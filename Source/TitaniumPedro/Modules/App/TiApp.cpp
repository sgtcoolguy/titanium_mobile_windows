/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#include "TiApp.h"
#include <Windows.h>

#include "TiCore/TiRuntimeFunctions.h"
#include "Modules/UI/TiUIWebView.h"

namespace Ti { namespace App {

	std::string AppModule::arguments_;

	// These are JavaScript methods they will call class methods
	const JSStaticFunction AppModule::ClassMethods[] = {
		{"getAnalytics", _getAnalytics, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
		{"getAccessibilityEnabled" ,_getAccessibilityEnabled ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"setDisableNetworkActivityIndicator" ,_setDisableNetworkActivityIndicator ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getDisableNetworkActivityIndicator" ,_getDisableNetworkActivityIndicator ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"setForceSplashAsSnapshot" ,_setForceSplashAsSnapshot ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getForceSplashAsSnapshot" ,_getForceSplashAsSnapshot ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"setIdleTimerDisabled" ,_setIdleTimerDisabled ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getIdleTimerDisabled" ,_getIdleTimerDisabled ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getKeyboardVisible" ,_getKeyboardVisible ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"setProximityDetection" ,_setProximityDetection ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getProximityDetection" ,_getProximityDetection ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getProximityState" ,_getProximityState ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getSessionId" ,_getSessionId ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getArguments", _getArguments, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
		{"fireSystemEvent" ,_fireSystemEvent ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"_fireEventHook" ,__fireEventHook ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{0,0,0}
	};

	Ti::Value AppModule::Initialize(const std::string& ns, Ti::Value& obj) {
		Ti::Value appModule;

		appModule.setProperty("global", Ti::Value(Ti::Runtime::instance().globalObject()));
		appModule.setProperty("TiApp", App::AppModule::CreateConstructor());
		appModule.setProperty("TiAppProperties", App::Properties::CreateConstructor());

		Ti::Value result = Ti::evaluateScriptFileInObject("TitaniumPedro/ti.app.js", appModule);
		std::string r = result.toString();

		obj.setProperty(ns, result);

		return result;
	}
	
	AppModule::~AppModule(){
	}
	AppModule::AppModule(const std::string& name, const std::vector<Ti::Value>& args) : Ti::Proxy(name, args){
	}

	void AppModule::SetArguments(std::string args) {
		arguments_ = args;
	}

	// Public API

	// Gets the value of the analytics property.
	Ti::Value AppModule::getAnalytics(const std::vector<Ti::Value>& args)
	{
		return Ti::Value(analytics_);
	}

	// Gets the value of the accessibilityEnabled property.
	Ti::Value AppModule::getAccessibilityEnabled(const std::vector<Ti::Value>& args)
	{
		return Ti::Value(accessibility_enabled_);
	}

	// Sets the value of the disableNetworkActivityIndicator property.
	Ti::Value AppModule::setDisableNetworkActivityIndicator(const std::vector<Ti::Value>& args)
	{
		if (args.size() >= 1) {
			disable_network_activity_indicator_ = args.at(0).toBool();
		}
		return Ti::Value::Undefined();
	}

	// Gets the value of the disableNetworkActivityIndicator property.
	Ti::Value AppModule::getDisableNetworkActivityIndicator(const std::vector<Ti::Value>& args)
	{
		return Ti::Value(disable_network_activity_indicator_);
	}

	// Sets the value of the forceSplashAsSnapshot property.
	Ti::Value AppModule::setForceSplashAsSnapshot(const std::vector<Ti::Value>& args)
	{
		if (args.size() >= 1) {
			force_splash_as_snapshot_ = args.at(0).toBool();
		}
		return Ti::Value::Undefined();
	}

	// Gets the value of the forceSplashAsSnapshot property.
	Ti::Value AppModule::getForceSplashAsSnapshot(const std::vector<Ti::Value>& args)
	{
		return Ti::Value(force_splash_as_snapshot_);
	}

	// Sets the value of the idleTimerDisabled property.
	Ti::Value AppModule::setIdleTimerDisabled(const std::vector<Ti::Value>& args)
	{
		if (args.size() >= 1) {
			idle_timer_disabled_ = args.at(0).toBool();

		}
		return Ti::Value::Undefined();
	}

	// Gets the value of the idleTimerDisabled property.
	Ti::Value AppModule::getIdleTimerDisabled(const std::vector<Ti::Value>& args)
	{
		return Ti::Value(idle_timer_disabled_);
	}

	// Gets the value of the keyboardVisible property.
	Ti::Value AppModule::getKeyboardVisible(const std::vector<Ti::Value>& args)
	{
		return Ti::Value(keyboard_visiable_);
	}

	// Sets the value of the proximityDetection property.
	Ti::Value AppModule::setProximityDetection(const std::vector<Ti::Value>& args)
	{
		if (args.size() >= 1) {
			proximity_detection_ = args.at(0).toBool();
		}
		return Ti::Value::Undefined();
	}

	// Gets the value of the proximityDetection property.
	Ti::Value AppModule::getProximityDetection(const std::vector<Ti::Value>& args)
	{
		return Ti::Value(proximity_detection_);
	}

	// Gets the value of the proximityState property.
	Ti::Value AppModule::getProximityState(const std::vector<Ti::Value>& args)
	{
		return Ti::Value(proximity_state_);
	}

	// Gets the value of the sessionId property.
	Ti::Value AppModule::getSessionId(const std::vector<Ti::Value>& args)
	{
		return Ti::Value(session_id_);
	}

	// Gets the value of the arguments property.
	Ti::Value AppModule::getArguments(const std::vector<Ti::Value>& args)
	{
		return Ti::Value(arguments_);
	}

	// Fire a system-level event such as Ti.App.EVENT_ACCESSIBILITY_ANNOUNCEMENT.
	Ti::Value AppModule::fireSystemEvent(const std::vector<Ti::Value>& args)
	{
		//TODO : Windows has no accessibility manager
		return Ti::Value::Undefined();
	}

	// Event hook for fireEvent, to delegate all Ti.App events onto WebView.
	Ti::Value AppModule::_fireEventHook(const std::vector<Ti::Value>& args) {
		assert(args.size() == 2);

		const auto name = args.at(0);
		const auto obj = args.at(1);

		const auto webviews = UI::TiUIWebView::getWebViewProxies();
		for (const auto& container : webviews) {
			const auto webview = container.second.lock();
			if (webview) {
				webview->executeListener(name, obj);
			}
		}

		return Ti::Value::Undefined();
	}
}}