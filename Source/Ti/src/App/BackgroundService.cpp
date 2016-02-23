/**
* Ti.App.Windows.BackgroundService
*
* Copyright (c) 2016 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/
#include "TitaniumWindows/App/BackgroundService.hpp"
#include "TitaniumWindows/App/BackgroundServiceTask.hpp"
#include "Titanium/GeolocationModule.hpp"
#include "Titanium/detail/TiImpl.hpp"
#include "TitaniumWindows/Utility.hpp"
#include <boost/algorithm/string/predicate.hpp>

using namespace Windows::Foundation;
using namespace Windows::Devices::Geolocation;
using namespace Windows::ApplicationModel::Background;
using namespace Windows::Storage;

namespace TitaniumWindows_Ti
{
	void BackgroundServiceTask::Run(IBackgroundTaskInstance^ taskInstance)
	{
		const auto deferral = Platform::Agile<BackgroundTaskDeferral>(taskInstance->GetDeferral());
		const auto location_enabled = TitaniumWindows::App::WindowsXaml::BackgroundService::Get_LocationServiceEnabled();
		if (location_enabled) {

			const auto geolocator_ = ref new Geolocator();
			geolocator_->MovementThreshold = 1;
			geolocator_->ReportInterval = 0;
			geolocator_->DesiredAccuracy = PositionAccuracy::High;

			TitaniumWindows::App::WindowsXaml::BackgroundService::ResetLastGeoposition();

			concurrency::create_task(geolocator_->GetGeopositionAsync()).then([deferral](concurrency::task<Geoposition^> task){
				try {
					TitaniumWindows::App::WindowsXaml::BackgroundService::UpdateLastGeoposition(task.get());
				} catch (Platform::COMException^ e) {
					TitaniumWindows::App::WindowsXaml::BackgroundService::ResetLastGeoposition();
					TITANIUM_LOG_WARN(TitaniumWindows::Utility::ConvertString(e->Message));
				}
				deferral->Complete();
			});
		} else {
			// Complete the task immediately just to tell subscriber "Complete" event
			deferral->Complete();
		}
	}
}

namespace TitaniumWindows
{
	namespace App
	{
		namespace WindowsXaml 
		{
			Platform::String^ BackgroundService::TASK_ENTRYPOINT_NAME { "TitaniumWindows_Ti.BackgroundServiceTask" };
			Platform::String^ BackgroundService::LAST_GEOLOCATION_KEY { "TitaniumWindows_Ti.BackgroundServiceTask.LastGeolocation" };
			Platform::String^ BackgroundService::GEOLOCATION_ENABLED_KEY{ "TitaniumWindows_Ti.BackgroundServiceTask.GeolocationEnabled" };
			std::atomic<std::uint32_t> BackgroundService::task_id_generator__;

			BackgroundService::BackgroundService(const JSContext& js_context) TITANIUM_NOEXCEPT
				: Titanium::Module(js_context, "Titanium.App.Windows.BackgroundService")
			{
				TITANIUM_LOG_DEBUG("BackgroundService::ctor Initialize");
			}

			BackgroundService::~BackgroundService() 
			{
				TITANIUM_LOG_DEBUG("BackgroundService::dtor");
				UnregisterTasks();
			}

			void BackgroundService::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) 
			{
				Titanium::Module::postCallAsConstructor(js_context, arguments);
				TITANIUM_LOG_DEBUG("BackgroundService::postCallAsConstructor");
			}

			void BackgroundService::JSExportInitialize() 
			{
				JSExport<BackgroundService>::SetClassVersion(1);
				JSExport<BackgroundService>::SetParent(JSExport<Titanium::Module>::Class());

				TITANIUM_ADD_FUNCTION(BackgroundService, registerTimerTask);
				TITANIUM_ADD_FUNCTION(BackgroundService, unregisterAllTasks);
				TITANIUM_ADD_PROPERTY(BackgroundService, locationServiceEnabled);
			}

			std::shared_ptr<BackgroundServiceTask> BackgroundService::registerTimerTask(JSObject& callback, const std::uint32_t& freshnessTime, const bool& oneShot, IBackgroundCondition^ condition)
			{
				return registerTask(callback, ref new TimeTrigger(freshnessTime, oneShot), condition);
			}

			std::shared_ptr<BackgroundServiceTask> BackgroundService::registerTask(JSObject& callback, IBackgroundTrigger^ trigger, IBackgroundCondition^ condition)
			{
#if defined(IS_WINDOWS_PHONE)
				BackgroundExecutionManager::RequestAccessAsync();
#endif
				const auto taskId   = task_id_generator__++;
				const auto taskName = Windows::ApplicationModel::Package::Current->Id->Name + "." + taskId;

				// Make sure to unregister all task which has same name
				// This could happen when last process doesn't unregister tasks properly.
				UnregisterTask(taskId);

				const auto builder = ref new BackgroundTaskBuilder();
				builder->Name = taskName;
				builder->TaskEntryPoint = TASK_ENTRYPOINT_NAME;
				builder->SetTrigger(trigger);

				if (condition != nullptr)
				{
					builder->AddCondition(condition);
					builder->CancelOnConditionLoss = true;
				}

				auto task = get_context().CreateObject(JSExport<BackgroundServiceTask>::Class()).CallAsConstructor().GetPrivate<BackgroundServiceTask>();
				task->construct(taskId, builder->Register(), callback);

				return task;
			}

			IBackgroundTaskRegistration^ BackgroundService::GetTask(const std::uint32_t& id) 
			{
				const auto taskName = Windows::ApplicationModel::Package::Current->Id->Name + "." + id;
				const auto iter = BackgroundTaskRegistration::AllTasks->First();
				auto hasCurrent = iter->HasCurrent;
				while (hasCurrent)
				{
					const auto cur = iter->Current->Value;
					if (cur->Name == taskName)
					{
						return cur;
					}
					hasCurrent = iter->MoveNext();
				}

				return nullptr;
			}

			void BackgroundService::UnregisterTask(const std::uint32_t& id)
			{
				const auto taskName = Windows::ApplicationModel::Package::Current->Id->Name + "." + id;
				const auto iter = BackgroundTaskRegistration::AllTasks->First();
				auto hasCurrent = iter->HasCurrent;
				while (hasCurrent)
				{
					const auto cur = iter->Current->Value;
					if (cur->Name == taskName)
					{
						cur->Unregister(true);
					}
					hasCurrent = iter->MoveNext();
				}
			}

			void BackgroundService::UnregisterTasks() 
			{
				const auto taskName = TitaniumWindows::Utility::ConvertString(Windows::ApplicationModel::Package::Current->Id->Name);
				const auto iter = BackgroundTaskRegistration::AllTasks->First();
				auto hasCurrent = iter->HasCurrent;
				while (hasCurrent)
				{
					const auto cur = iter->Current->Value;
					if (boost::starts_with(TitaniumWindows::Utility::ConvertString(cur->Name), taskName))
					{
						cur->Unregister(true);
					}
					hasCurrent = iter->MoveNext();
				}
			}

			bool BackgroundService::Get_LocationServiceEnabled() TITANIUM_NOEXCEPT
			{
				//
				// We need to share configuration with BackgroundTask using LocalSettings
				//
				return ApplicationData::Current->LocalSettings->Values->HasKey(GEOLOCATION_ENABLED_KEY);
			}

			void BackgroundService::Set_LocationServiceEnabled(const bool& enabled) TITANIUM_NOEXCEPT
			{
				ResetLastGeoposition();

				if (enabled) {
					ApplicationData::Current->LocalSettings->Values->Insert(GEOLOCATION_ENABLED_KEY, dynamic_cast<PropertyValue^>(PropertyValue::CreateBoolean(true)));
				} else {
					ApplicationData::Current->LocalSettings->Values->Remove(GEOLOCATION_ENABLED_KEY);
				}
			}

			void BackgroundService::UpdateLastGeoposition(Geoposition^ pos) TITANIUM_NOEXCEPT
			{
				ResetLastGeoposition();

				const auto accuracy  = pos->Coordinate->Accuracy;
				const auto latitude  = pos->Coordinate->Point->Position.Latitude;
				const auto longitude = pos->Coordinate->Point->Position.Longitude;
				const auto altitude  = pos->Coordinate->Point->Position.Altitude;
				const auto altitudeAccuracy = pos->Coordinate->AltitudeAccuracy;
				const auto heading = pos->Coordinate->Heading;
				const auto speed = pos->Coordinate->Speed;

				/*
				* accuracy, altitude, altitudeAccuracy, heading, longitude, latitude, speed, floor, timestamp
				*/
				auto values = ref new Platform::Array<double>(9);
				values->Data[0] = accuracy;
				values->Data[1] = altitude;
				values->Data[2] = altitudeAccuracy ? altitudeAccuracy->Value : 0;
				values->Data[3] = heading ? heading->Value : 0;
				values->Data[4] = longitude;
				values->Data[5] = latitude;
				values->Data[6] = speed ? speed->Value : 0;
				values->Data[7] = 0; /* floor: unused */
				auto now = ref new Windows::Globalization::Calendar();
				now->SetToNow();
				values->Data[8] = static_cast<double>(TitaniumWindows::Utility::GetMSecSinceEpoch(now->GetDateTime()).count());

				ApplicationData::Current->LocalSettings->Values->Insert(LAST_GEOLOCATION_KEY, dynamic_cast<PropertyValue^>(PropertyValue::CreateDoubleArray(values)));
			}

			void BackgroundService::ResetLastGeoposition() TITANIUM_NOEXCEPT
			{
				ApplicationData::Current->LocalSettings->Values->Remove(LAST_GEOLOCATION_KEY);
			}

			Titanium::LocationCoordinates BackgroundService::GetLastGeoposition() TITANIUM_NOEXCEPT
			{
				Titanium::LocationCoordinates pos;
				if (!Get_LocationServiceEnabled() || !ApplicationData::Current->LocalSettings->Values->HasKey(LAST_GEOLOCATION_KEY)) {
					pos.available = false;
					return pos;
				}

				auto values = ref new Platform::Array<double>(9);
				safe_cast<IPropertyValue^>(ApplicationData::Current->LocalSettings->Values->Lookup(LAST_GEOLOCATION_KEY))->GetDoubleArray(&values);

				/*
				 * accuracy, altitude, altitudeAccuracy, heading, longitude, latitude, speed, floor, timestamp
				 */
				pos.accuracy  = values->Data[0];
				pos.altitude  = values->Data[1];
				pos.altitudeAccuracy = values->Data[2];
				pos.heading   = values->Data[3];
				pos.longitude = values->Data[4];
				pos.latitude  = values->Data[5];
				pos.speed = values->Data[6];

				Titanium::LocationCoordinatesFloor floor;
				floor.level = static_cast<std::int32_t>(values->Data[7]);
				pos.floor = floor;

				pos.timestamp = std::chrono::milliseconds(static_cast<std::chrono::milliseconds::rep>(values->Data[8]));

				return pos;
			}

			TITANIUM_FUNCTION(BackgroundService, registerTimerTask)
			{
				ENSURE_OBJECT_AT_INDEX(callback, 0);
				ENSURE_OPTIONAL_UINT_AT_INDEX(freshnessTime, 1, 15);
				ENSURE_OPTIONAL_BOOL_AT_INDEX(oneShot, 2, false);
				const auto task = registerTimerTask(callback, freshnessTime, oneShot);
				if (task) {
					return task->get_object();
				}
				return get_context().CreateNull();
			}

			TITANIUM_FUNCTION(BackgroundService, unregisterAllTasks) 
			{
				UnregisterTasks();
				return get_context().CreateUndefined();
			}

			TITANIUM_PROPERTY_GETTER(BackgroundService, locationServiceEnabled)
			{
				return get_context().CreateBoolean(Get_LocationServiceEnabled());
			}

			TITANIUM_PROPERTY_SETTER(BackgroundService, locationServiceEnabled)
			{
				Set_LocationServiceEnabled(static_cast<bool>(argument));
				return true;
			}
		} // namespace WindowsXaml
	}  // namespace App
}  // namespace TitaniumWindows
