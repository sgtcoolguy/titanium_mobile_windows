/** -*- mode: c++ -*-
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#ifndef _TITANIUM_MOBILE_WINDOWS_MODULES_GESTURE_H_
#define _TITANIUM_MOBILE_WINDOWS_MODULES_GESTURE_H_

#include "TiCore/TiProxy.h"
#include "Modules/UI/UIModule.h"
#include "ShakeGestureHelper.h"

namespace Ti { namespace Gesture {
	class GestureModule : public Ti::Proxy, public virtual_enable_shared_from_this<GestureModule> {

	public:
		static Ti::Value Initialize(const std::string& ns, Ti::Value& obj);
		virtual Ti::Value eventAdded(const std::vector<Ti::Value>&args) override;
		virtual Ti::Value eventRemoved(const std::vector<Ti::Value>&args) override;

	protected:
		GestureModule(const std::string& name, const std::vector<Ti::Value>& arguments);
		virtual ~GestureModule();
		virtual void postConstruct() override;

	private:
		Windows::Foundation::DateTime previous_acceleromter_time_;
		Windows::Devices::Sensors::Accelerometer^ accelerometer_;

		int orientation_ = UI::UIModule::UNKNOWN;

		// milliseconds to wait until next shake event (taken from Titanium Android)
		const unsigned int postShakePeriod = 500;

		Windows::Foundation::EventRegistrationToken shake_event_;
		Windows::Foundation::EventRegistrationToken orientationchange_event_;

		unsigned int shake_listener_count_ { 0 };
		unsigned int orientationchange_listener_count_ { 0 };

		ShakeGestureHelper shakeGestureHelper;

		int updateOrientation();

		TI_CREATE_PROXY(GestureModule);

		static JSClassRef Parent();

		// Gets the value of the landscape property.
		TI_CREATE_METHOD(GestureModule, getLandscape);
		Ti::Value GestureModule::getLandscape(const std::vector<Ti::Value>& arguments);

		// Gets the value of the orientation property.
		TI_CREATE_METHOD(GestureModule, getOrientation);
		Ti::Value GestureModule::getOrientation(const std::vector<Ti::Value>& arguments);

		// Gets the value of the portrait property.
		TI_CREATE_METHOD(GestureModule, getPortrait);
		Ti::Value GestureModule::getPortrait(const std::vector<Ti::Value>& arguments);

		// Returns whether current window is considered face down by the device.
		TI_CREATE_METHOD(GestureModule, isFaceDown);
		Ti::Value GestureModule::isFaceDown(const std::vector<Ti::Value>& arguments);

		// Returns whether current window is considered face up by the device.
		TI_CREATE_METHOD(GestureModule, isFaceUp);
		Ti::Value GestureModule::isFaceUp(const std::vector<Ti::Value>& arguments);

		// Returns whether current window is considered landscape by the device.
		TI_CREATE_METHOD(GestureModule, isLandscape);
		Ti::Value GestureModule::isLandscape(const std::vector<Ti::Value>& arguments);

		// Returns whether current window is considered portrait by the device.
		TI_CREATE_METHOD(GestureModule, isPortrait);
		Ti::Value GestureModule::isPortrait(const std::vector<Ti::Value>& arguments);
	};
}} // namespace Ti { namespace Gesture {

#endif // _TITANIUM_MOBILE_WINDOWS_MODULES_GESTURE_H_
