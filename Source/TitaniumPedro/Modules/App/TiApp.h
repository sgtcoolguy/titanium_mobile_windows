/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#ifndef __TI_APP_PROXY_H__
#define __TI_APP_PROXY_H__

#include "TiCore/TiProxy.h"
#include "TiAppProperties.h"

using namespace Platform;

namespace Ti { namespace App {
	class AppModule : public Ti::Proxy, public virtual_enable_shared_from_this < AppModule > {

		TI_CREATE_PROXY(AppModule)

	public:

		static Ti::Value Initialize(const std::string& ns, Ti::Value& obj);
		static void SetArguments(std::string args);

private:

	static std::string arguments_;

	bool analytics_ { false };
	bool accessibility_enabled_ { false };
	bool disable_network_activity_indicator_ { false };
	bool force_splash_as_snapshot_ { false };
	bool idle_timer_disabled_ { false };
	bool keyboard_visiable_ { false };
	bool proximity_detection_ { false };
	bool proximity_state_ { false };
	std::string session_id_;

protected:

	static JSClassRef Parent() { return Ti::Proxy::ClassDef(); }
	AppModule(const std::string&, const std::vector<Ti::Value>&);
	virtual ~AppModule();

	// JavaScript's public API

	// Gets the value of the analytics property.
	Ti::Value getAnalytics(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(AppModule, getAnalytics);

	// Gets the value of the accessibilityEnabled property.
	Ti::Value getAccessibilityEnabled(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(AppModule, getAccessibilityEnabled);

	// Sets the value of the disableNetworkActivityIndicator property.
	Ti::Value setDisableNetworkActivityIndicator(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(AppModule, setDisableNetworkActivityIndicator);

	// Gets the value of the disableNetworkActivityIndicator property.
	Ti::Value getDisableNetworkActivityIndicator(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(AppModule, getDisableNetworkActivityIndicator);

	// Sets the value of the forceSplashAsSnapshot property.
	Ti::Value setForceSplashAsSnapshot(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(AppModule, setForceSplashAsSnapshot);

	// Gets the value of the forceSplashAsSnapshot property.
	Ti::Value getForceSplashAsSnapshot(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(AppModule, getForceSplashAsSnapshot);

	// Sets the value of the idleTimerDisabled property.
	Ti::Value setIdleTimerDisabled(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(AppModule, setIdleTimerDisabled);

	// Gets the value of the idleTimerDisabled property.
	Ti::Value getIdleTimerDisabled(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(AppModule, getIdleTimerDisabled);

	// Gets the value of the keyboardVisible property.
	Ti::Value getKeyboardVisible(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(AppModule, getKeyboardVisible);

	// Sets the value of the proximityDetection property.
	Ti::Value setProximityDetection(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(AppModule, setProximityDetection);

	// Gets the value of the proximityDetection property.
	Ti::Value getProximityDetection(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(AppModule, getProximityDetection);

	// Gets the value of the proximityState property.
	Ti::Value getProximityState(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(AppModule, getProximityState);

	// Gets the value of the sessionId property.
	Ti::Value getSessionId(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(AppModule, getSessionId);

	Ti::Value getArguments(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(AppModule, getArguments);

	// Fire a system-level event such as Ti.App.EVENT_ACCESSIBILITY_ANNOUNCEMENT.
	Ti::Value fireSystemEvent(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(AppModule, fireSystemEvent);

	// Event hook for fireEvent, to delegate all Ti.App events onto WebView.
	Ti::Value _fireEventHook(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(AppModule, _fireEventHook);
};
}}
#endif // defined(__TI_APP_PROXY_H__)