/** -*- mode: c++ -*-
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#ifndef _TITANIUM_MOBILE_WINDOWS_TICORE_TIRUNTIMEFUNCTIONS_H_
#define _TITANIUM_MOBILE_WINDOWS_TICORE_TIRUNTIMEFUNCTIONS_H_

#include <JavaScriptCore/JavaScript.h>
#include <string>
#include "TiCore/TiValue.h"

// For debug!!
extern "C" JS_EXPORT void JSSynchronousGarbageCollectForDebugging(JSContextRef);

namespace Ti {

	// Evals a string into the global object and returns the value from
	// eval.
	Value evaluateScript(const std::string& script);

	// Evals a string into the object that was passed in and returns the
	// value from eval.
	Value evaluateScriptInObject(const std::string& script, const Ti::Value& object);

	Value evaluateScriptFileInObject(const std::string& path, const Ti::Value& object);

	// Titanium version of "require" Currently works only with JS files.
	Value requireJS(const std::string& file);
	Value internalRequireJS(const std::string& file);

	JSValueRef JSModuleRequire(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception);
	JSValueRef JSInternalModuleRequire(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception);

}	// namespace Ti {

#endif // _TITANIUM_MOBILE_WINDOWS_TICORE_TIRUNTIMEFUNCTIONS_H_
