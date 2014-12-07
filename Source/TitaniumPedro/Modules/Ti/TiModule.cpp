#include "Modules/Ti/TiModule.h"
#include <mutex>
#include <vector>
#include <Windows.h>
#include "TiCore/TiViewProxy.h"
#include "TiCore/TimerProxy.h"
#include "TiCore/TiRuntimeFunctions.h"

/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

// TODO:
// Move all this to the TiCore project
// This file sets the main Titanium components.

// Log function for console.log, Ti.API.info, etc..
static JSValueRef Log(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception) {
	std::string val = Ti::Value(arguments, argumentCount).toString();
	std::string logstr = val + "\n";
	std::wstring wresult = std::wstring(logstr.begin(), logstr.end());
	OutputDebugString(wresult.c_str());

	return JSValueMakeUndefined(ctx);
}

// WARNING!
// THIS IF FOR DEBUG PURPOSES ONLY!
JSValueRef GC(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception) {
	Ti::Runtime::instance().forceGarbageCollection();
	return Ti::Value::Undefined().JSValueRef();
}

// #ifndef DEBUG_TIMODULE
// #define DEBUG_TIMODULE
// #endif


Ti::Value TiModule::Initialize(const std::string& ns, Ti::Value& obj) {
	Ti::Value result;
	static std::once_flag of;
	std::call_once(of, [&result, &ns, &obj] {
			JSContextRef globalContext = Ti::Runtime::instance().globalContext();
			// Create a temporary object for store our private classes and functions
			Ti::Value tempObject;
			// But create a handle to the global object by creating a simple property
			tempObject.setProperty("global", obj);
			
			// Ok, inject our stuff that we don't want to expose publicly
			tempObject.setProperty("Timer", TimerProxy::CreateConstructor());
			tempObject.setProperty("BaseProxy", BaseProxy::CreateConstructor());
			tempObject.setProperty("TiProxy", Ti::Proxy::CreateConstructor());
			tempObject.setProperty("TiViewProxy", Ti::ViewProxy::CreateConstructor());
			
			Ti::Value logObject(JSObjectMakeFunctionWithCallback(globalContext, nullptr, Log));
			tempObject.setProperty("log", logObject);
			
			Ti::Value gcFunc(JSObjectMakeFunctionWithCallback(globalContext, nullptr, GC));
			tempObject.setProperty("gc", gcFunc);
			
			Ti::Value requireFunc(JSObjectMakeFunctionWithCallback(globalContext, nullptr, Ti::JSModuleRequire));
			tempObject.setProperty("require", requireFunc);
			
			Ti::Value internalRequireFunc(JSObjectMakeFunctionWithCallback(Ti::Runtime::instance().globalContext(), nullptr, Ti::JSInternalModuleRequire));
			tempObject.setProperty("internal_require", internalRequireFunc);

			// Now we evalutate this code in the tempObject. The tempObject looks like this:
			// tempObject = {
			//		 global: [object Global],
			//		 Timer: [constructor TimerProxy],
			//		 BaseProxy: [constructor BaseProxy],
			//		 TiProxy: [constructor TiProxy],
			//		 log: [function Log]
			// };
			// But we return a new object containing other stuff
			// var Ti = {
			//			API: [object API]
			// }
			// And the global object has also been injected with stuff
			// console = [object log]
			// setTimeout = [function setTimeout]
			// clearTimeout = [function clearTimeout]
			// setInterval = [function setInterval]
			// clearInterval = [function clearInterval]
			
			result = Ti::evaluateScriptFileInObject("TitaniumPedro/ti.js", tempObject);
			obj.setProperty(ns, result);
			// This line is for debug, place a breakpoint and see what the result is
			// It should be [object object]
			// TODO: remove this line
			//std::string strResult = result.toString();
		});
	
	return result;
}
