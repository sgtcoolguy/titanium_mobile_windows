/**
* Ti.App.Windows.BackgroundServiceTask
*
* Copyright (c) 2016 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/
#include "TitaniumWindows/App/BackgroundServiceTask.hpp"
#include "TitaniumWindows/App/BackgroundService.hpp"
#include "Titanium/GeolocationModule.hpp"
#include "Titanium/detail/TiImpl.hpp"
#include <ppltasks.h>

namespace TitaniumWindows
{
	namespace App
	{
		namespace WindowsXaml 
		{
			BackgroundServiceTask::BackgroundServiceTask(const JSContext& js_context) TITANIUM_NOEXCEPT
				: Titanium::Module(js_context, "Titanium.App.Windows.BackgroundServiceTask")
				, callback__(js_context.CreateObject())
			{
				TITANIUM_LOG_DEBUG("BackgroundServiceTask::ctor Initialize");
			}

			BackgroundServiceTask::~BackgroundServiceTask() 
			{
				TITANIUM_LOG_DEBUG("BackgroundServiceTask::dtor");

				// Make sure we remove all listeners
				const auto task = BackgroundService::GetTask(taskId__);
				if (task) {
					task->Completed -= completed_event__;
				}
			}

			void BackgroundServiceTask::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) 
			{
				Titanium::Module::postCallAsConstructor(js_context, arguments);
				TITANIUM_LOG_DEBUG("BackgroundServiceTask::postCallAsConstructor");
			}

			void BackgroundServiceTask::JSExportInitialize() 
			{
				JSExport<BackgroundServiceTask>::SetClassVersion(1);
				JSExport<BackgroundServiceTask>::SetParent(JSExport<Titanium::Module>::Class());
				TITANIUM_ADD_FUNCTION(BackgroundServiceTask, unregister);
			}

			TITANIUM_PROPERTY_READ(BackgroundServiceTask, std::uint32_t, taskId);

			void BackgroundServiceTask::taskCompleted(const bool& canceled) 
			{
				TITANIUM_ASSERT(callback__.IsFunction());

				const auto ctx = get_context();

				auto e = ctx.CreateObject();
				e.SetProperty("source", get_object());
				e.SetProperty("canceled", ctx.CreateBoolean(canceled));

				auto pos = TitaniumWindows::App::WindowsXaml::BackgroundService::GetLastGeoposition();
				if (pos.available) {
					e.SetProperty("location", LocationCoordinates_to_js(ctx, pos));
				}

				const std::vector<JSValue> callback_args{ e };
				callback__(callback_args, get_object());
			}

			void BackgroundServiceTask::construct(const std::uint32_t& id, BackgroundTaskRegistration^ registration, JSObject& callback)
			{
				taskId__   = id;
				callback__ = callback;
				completed_event__ = registration->Completed += ref new BackgroundTaskCompletedEventHandler([this](BackgroundTaskRegistration^ task, BackgroundTaskCompletedEventArgs^ args) {
					taskCompleted();
				});
			}

			void BackgroundServiceTask::unregister()
			{
				const auto task = BackgroundService::GetTask(taskId__);
				if (task) {
					task->Unregister(true);
					taskCompleted(true);
				}
			}

			TITANIUM_FUNCTION(BackgroundServiceTask, unregister)
			{
				unregister();
				return get_context().CreateUndefined();
			}
		} // namespace WindowsXaml
	}  // namespace App
}  // namespace TitaniumWindows
