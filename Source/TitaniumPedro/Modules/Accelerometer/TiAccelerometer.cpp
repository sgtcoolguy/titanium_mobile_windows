/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#include "Modules/Accelerometer/TiAccelerometer.h"
#include "TiCore/TiRuntimeFunctions.h"
#include "TiCore/TiConstants.h"

namespace Ti { namespace Accelerometer {

	static std::string gCode =
		"(function(self){"
		"  var exports = new self.TiAccelerometer();"
		"  return exports;"
		"})(this);"
		;

	Ti::Value AccelerometerModule::Initialize(const std::string& ns, Ti::Value& obj) {
		Ti::Value result;
		static std::once_flag of;
		std::call_once(of, [&result, &ns, &obj] {
			Ti::Value pfModule;
			pfModule.setProperty("global", Ti::Value(Ti::Runtime::instance().globalObject()));
			pfModule.setProperty("TiAccelerometer", AccelerometerModule::CreateConstructor());
			result = Ti::evaluateScriptInObject(gCode, pfModule);
			obj.setProperty(ns, result);
		});

		return result;
	}

	Ti::Value AccelerometerModule::eventAdded(const std::vector<Ti::Value>&args) {
		const auto arg = args.at(0).toString();
		if (arg == Ti::Constants::EventUpdate) {
			if (update_listener_count_ == 0) {
				accelerometer_ = Windows::Devices::Sensors::Accelerometer::GetDefault();

				if (accelerometer_ == nullptr) {
					std::clog << "[ERROR] Ti.Accelerometer: No accelerometer found" << std::endl;
					return Ti::Value::Undefined();
				}

				// Select a report interval that is both suitable for the purposes of the app and supported by the sensor.
				const auto minReportInterval = accelerometer_->MinimumReportInterval;
				accelerometer_->ReportInterval = minReportInterval > 16 ? minReportInterval : 16;

				// Capture Window::Current here because getting it outside of UI thread seems always return nullptr
				const auto current = Windows::UI::Xaml::Window::Current;

				using namespace std::placeholders;
				const auto updateCallback = std::bind([current](const AccelerometerModule_weak_ptr_t& weakThis, Windows::Devices::Sensors::Accelerometer^ sender, Windows::Devices::Sensors::AccelerometerReadingChangedEventArgs^ e) {
					const auto strong_ptr = weakThis.lock();
					if (strong_ptr) {
						const auto dispatchedCallback = std::bind([](const AccelerometerModule_weak_ptr_t& weakThis) {
							const auto strong_ptr = weakThis.lock();
							if (strong_ptr) {
								Ti::Value obj;
								const auto reading = strong_ptr->accelerometer_->GetCurrentReading();
								int timestamp = 0;
								if (strong_ptr->previous_acceleromter_time_.UniversalTime != 0) {
									timestamp = (reading->Timestamp.UniversalTime - strong_ptr->previous_acceleromter_time_.UniversalTime) / 10000.0;
									// Suppress fireEvent so that it doesn't block UI thread (taken from Titanium Android)
									if (timestamp < 100) {
										return;
									}
								}
								strong_ptr->previous_acceleromter_time_ = reading->Timestamp;
								obj.setProperty("timestamp", Ti::Value(static_cast<double>(timestamp)));
								obj.setProperty("x", Ti::Value(reading->AccelerationX));
								obj.setProperty("y", Ti::Value(reading->AccelerationY));
								obj.setProperty("z", Ti::Value(reading->AccelerationZ));

								strong_ptr->fireEvent(Ti::Constants::EventUpdate, obj);
							}
						}, /* std::move(strong_ptr->get_weak_ptr_for_proxy()) causes crash */ weakThis);

						if (current) {
							current->Dispatcher->RunAsync(
								Windows::UI::Core::CoreDispatcherPriority::Normal,
								ref new Windows::UI::Core::DispatchedHandler(dispatchedCallback));
						}
					}
				}, std::move(get_weak_ptr_for_proxy()), _1, _2);

				update_event_ = accelerometer_->ReadingChanged += ref new Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Accelerometer^, Windows::Devices::Sensors::AccelerometerReadingChangedEventArgs^>(updateCallback);
			}
			++update_listener_count_;
		}
		return Ti::Proxy::eventAdded(args);
	}

	Ti::Value AccelerometerModule::eventRemoved(const std::vector<Ti::Value>&args) {
		const auto arg = args.at(0).toString();
		if (arg == Ti::Constants::EventUpdate) {
			--update_listener_count_;
			if (update_listener_count_ == 0) {
				accelerometer_->ReadingChanged -= update_event_;
			}
		}
		return Ti::Proxy::eventRemoved(args);
	}

	AccelerometerModule::AccelerometerModule(const std::string& name, const std::vector<Ti::Value>& arguments) : Ti::Proxy(name, arguments) {

	}

	void AccelerometerModule::postConstruct() {
		Proxy::postConstruct();
	}

	////////////////////////////////////////////////////////////////////////
	//
	// Proxy macro infrastructure goes below here.
	//
	////////////////////////////////////////////////////////////////////////

	JSClassRef AccelerometerModule::Parent() {
		return Ti::Proxy::ClassDef();
	}

	const JSStaticFunction AccelerometerModule::ClassMethods[] = {
		{ 0, 0, 0 }
	};

}} // namespace Ti { namespace Accelerometer {
