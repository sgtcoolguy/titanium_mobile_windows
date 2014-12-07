/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#include "TiCore/TiRuntime.h"
#include "TiCore/TiValue.h"

namespace Ti {

// Adds a property to the global object
void Runtime::addPropertyToGlobalObject(const std::string& propertyName, const Ti::Value& value) const {
	const auto propertyStr = JSStringCreateWithUTF8CString(propertyName.c_str());
	JSObjectSetProperty(globalContext_, (::JSObjectRef)globalObject_, propertyStr, value.JSValueRef(), kJSPropertyAttributeNone, nullptr);
	JSStringRelease(propertyStr);
}

} // namespace Ti {
