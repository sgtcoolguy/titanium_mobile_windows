/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#include "Modules/Gesture/TiGesture.h"
#include "TiCore/TiRuntimeFunctions.h"

namespace Ti { namespace Gesture {

	GestureModule::GestureModule(const std::string& name, const std::vector<Ti::Value>& arguments) : Ti::Proxy(name, arguments) {

	}

	GestureModule::~GestureModule() {
		const auto display = Windows::Graphics::Display::DisplayInformation::GetForCurrentView();
		display->OrientationChanged -= orientationchange_event_;
	}

	void GestureModule::postConstruct() {
		Proxy::postConstruct();

		using namespace std::placeholders;
		using namespace Windows::Graphics::Display;

		const auto display = DisplayInformation::GetForCurrentView();

		// Setup OrientationChanged event
		const auto orientationchangeCallback = std::bind([](
			const GestureModule_weak_ptr_t& weakThis,
			DisplayInformation ^sender, ::Platform::Object ^args) {
			const auto strong_ptr = weakThis.lock();
			if (strong_ptr) {
				Ti::Value obj;
				obj.setProperty("orientation", Ti::Value(static_cast<double>(strong_ptr->updateOrientation())));
				strong_ptr->fireEvent(Ti::Constants::EventOrientationChange, obj);
			}
		}, std::move(get_weak_ptr_for_proxy()), _1, _2);

		orientationchange_event_ = display->OrientationChanged += ref new Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation^, ::Platform::Object^>(orientationchangeCallback);
	}

	static std::string gCode =
		"(function(self){"
		""
		"Object.defineProperties(self.TiGesture.prototype, {"
		"	'landscape': {get:function(){return this.getLandscape();}, enumerable:true},"
		"	'orientation': {get:function(){return this.getOrientation();}, enumerable:true},"
		"	'portrait': {get:function(){return this.getPortrait();}, enumerable:true},"
		"});"
		""
		" var exports = new self.TiGesture();"
		""
		" return exports;"
		"})(this);"
		;

	Ti::Value GestureModule::Initialize(const std::string& ns, Ti::Value& obj) {
		Ti::Value result;
		static std::once_flag of;
		std::call_once(of, [&result, &ns, &obj] {
			Ti::Value pfModule;
			pfModule.setProperty("global", Ti::Value(Ti::Runtime::instance().globalObject()));
			pfModule.setProperty("TiGesture", GestureModule::CreateConstructor());
			result = Ti::evaluateScriptInObject(gCode, pfModule);
			obj.setProperty(ns, result);
		});
		return result;
	}

	Ti::Value GestureModule::eventAdded(const std::vector<Ti::Value>&args) {
		const auto arg = args.at(0).toString();
		if (arg == Ti::Constants::EventOrientationChange) {
			++orientationchange_listener_count_;
		} else if (arg == Ti::Constants::EventShake) {
			if (shake_listener_count_ == 0) {
				accelerometer_ = Windows::Devices::Sensors::Accelerometer::GetDefault();
				if (accelerometer_ == nullptr) {
					std::clog << "[ERROR] Ti.Gesture: No accelerometer found" << std::endl;
					return Ti::Value::Undefined();
				}
				// Select a report interval that is both suitable for the purposes of the app and supported by the sensor.
				const auto minReportInterval = accelerometer_->MinimumReportInterval;
				accelerometer_->ReportInterval = minReportInterval > 16 ? minReportInterval : 16;

				// Capture Window::Current here because getting it outside of UI thread seems always return nullptr
				const auto current = Windows::UI::Xaml::Window::Current;

				using namespace std::placeholders;
				const auto shakeCallback = std::bind([current](const GestureModule_weak_ptr_t& weakThis, Windows::Devices::Sensors::Accelerometer^ sender, Windows::Devices::Sensors::AccelerometerReadingChangedEventArgs^ e) {
					const auto strong_ptr = weakThis.lock();
					if (strong_ptr) {
						const auto dispatchedCallback = std::bind([](const GestureModule_weak_ptr_t& weakThis) {
							const auto strong_ptr = weakThis.lock();
							if (strong_ptr) {
								const auto reading = strong_ptr->accelerometer_->GetCurrentReading();
								const unsigned int timestamp = (reading->Timestamp.UniversalTime - strong_ptr->previous_acceleromter_time_.UniversalTime) / 10000.0;
								if (strong_ptr->shakeGestureHelper.isShaken(reading) && timestamp > strong_ptr->postShakePeriod) {
									Ti::Value obj;
									strong_ptr->previous_acceleromter_time_ = reading->Timestamp;
									obj.setProperty("timestamp", Ti::Value(static_cast<double>(timestamp)));
									obj.setProperty("x", Ti::Value(reading->AccelerationX));
									obj.setProperty("y", Ti::Value(reading->AccelerationY));
									obj.setProperty("z", Ti::Value(reading->AccelerationZ));

									strong_ptr->fireEvent(Ti::Constants::EventShake, obj);
								}
							}
						}, /* std::move(strong_ptr->get_weak_ptr_for_proxy()) causes crash */ weakThis);
						if (current) {
							current->Dispatcher->RunAsync(
								Windows::UI::Core::CoreDispatcherPriority::Normal, 
								ref new Windows::UI::Core::DispatchedHandler(dispatchedCallback));
						}
					}
				}, std::move(get_weak_ptr_for_proxy()), _1, _2);
				shake_event_ = accelerometer_->ReadingChanged += ref new Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Accelerometer^, Windows::Devices::Sensors::AccelerometerReadingChangedEventArgs^>(shakeCallback);
			}
			++shake_listener_count_;
		}
		return Ti::Proxy::eventAdded(args);
	}

	Ti::Value GestureModule::eventRemoved(const std::vector<Ti::Value>&args) {
		const auto arg = args.at(0).toString();
		if (arg == Ti::Constants::EventOrientationChange) {
			--orientationchange_listener_count_;
		} else if (arg == Ti::Constants::EventShake) {
			--shake_listener_count_;
			if (shake_listener_count_ == 0) {
				accelerometer_->ReadingChanged -= shake_event_;
			}
		}
		return Ti::Proxy::eventRemoved(args);
	}

	int GestureModule::updateOrientation() {
		using namespace Windows::Graphics::Display;
		const auto display = DisplayInformation::GetForCurrentView();
		const auto orientation = display->CurrentOrientation;
		if (orientation == DisplayOrientations::Landscape) {
			orientation_ = UI::UIModule::LANDSCAPE_LEFT;
		}
		else if (orientation == DisplayOrientations::LandscapeFlipped) {
			orientation_ = UI::UIModule::LANDSCAPE_RIGHT;
		}
		else if (orientation == DisplayOrientations::Portrait) {
			orientation_ = UI::UIModule::PORTRAIT;
		}
		else if (orientation == DisplayOrientations::PortraitFlipped) {
			orientation_ = UI::UIModule::UPSIDE_PORTRAIT;
		}
		else {
			orientation_ = UI::UIModule::UNKNOWN;
		}
		return orientation_;
	}

	const JSStaticFunction GestureModule::ClassMethods[] = {
			{ "getLandscape", _getLandscape, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
			{ "getOrientation", _getOrientation, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
			{ "getPortrait", _getPortrait, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
			{ "isFaceDown", _isFaceDown, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
			{ "isFaceUp", _isFaceUp, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
			{ "isLandscape", _isLandscape, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
			{ "isPortrait", _isPortrait, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
			{ 0, 0, 0 }
	};

	JSClassRef GestureModule::Parent() {
		return Ti::Proxy::ClassDef();
	}

	// Gets the value of the landscape property.
	Ti::Value GestureModule::getLandscape(const std::vector<Ti::Value>& arguments) {
		updateOrientation();
		return Ti::Value((orientation_ == UI::UIModule::LANDSCAPE_LEFT || orientation_ == UI::UIModule::LANDSCAPE_RIGHT));
	}
	// Gets the value of the orientation property.
	Ti::Value GestureModule::getOrientation(const std::vector<Ti::Value>& arguments) {
		return Ti::Value(static_cast<double>(updateOrientation()));
	}
	// Gets the value of the portrait property.
	Ti::Value GestureModule::getPortrait(const std::vector<Ti::Value>& arguments) {
		updateOrientation();
		return Ti::Value((orientation_ == UI::UIModule::PORTRAIT || orientation_ == UI::UIModule::UPSIDE_PORTRAIT));
	}
	// Returns whether current window is considered face down by the device.
	Ti::Value GestureModule::isFaceDown(const std::vector<Ti::Value>& arguments) {
		return Ti::Value(false);
	}
	// Returns whether current window is considered face up by the device.
	Ti::Value GestureModule::isFaceUp(const std::vector<Ti::Value>& arguments) {
		return Ti::Value(false);
	}
	// Returns whether current window is considered landscape by the device.
	Ti::Value GestureModule::isLandscape(const std::vector<Ti::Value>& arguments) {
		updateOrientation();
		return Ti::Value((orientation_ == UI::UIModule::LANDSCAPE_LEFT || orientation_ == UI::UIModule::LANDSCAPE_RIGHT));
	}
	// Returns whether current window is considered portrait by the device.
	Ti::Value GestureModule::isPortrait(const std::vector<Ti::Value>& arguments) {
		updateOrientation();
		return Ti::Value((orientation_ == UI::UIModule::PORTRAIT || orientation_ == UI::UIModule::UPSIDE_PORTRAIT));
	}

}} // namespace Ti { namespace Gesture {
