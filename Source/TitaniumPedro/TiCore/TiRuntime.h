/** -*- mode: c++ -*-
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MOBILE_WINDOWS_TICORE_TIRUNTIME_H_
#define _TITANIUM_MOBILE_WINDOWS_TICORE_TIRUNTIME_H_

#include <JavaScriptCore/JavaScript.h>
#include <string>

// For debug!!
extern "C" JS_EXPORT void JSSynchronousGarbageCollectForDebugging(JSContextRef);

namespace Ti {

class Value;
class Runtime {

 public:

	// Return the one and only instance of the Runtime class.
	static Runtime& instance() {
		static Runtime instance;
		return instance;
	}

	// Returns the global JS context
	::JSGlobalContextRef globalContext() const {
		return globalContext_;
	}

	// Returns the global JS object
	::JSObjectRef globalObject() const {
		return globalObject_;
	}

	// Adds a property to the global object
	void addPropertyToGlobalObject(const std::string& propertyName, const Ti::Value& value) const;

	// For dev and debug, forces GC
	void forceGarbageCollection() {
		// This is for dev and debug only!!
		JSSynchronousGarbageCollectForDebugging(globalContext_);
	}

 private:

	// Enforce the Singleton pattern.
	Runtime() {
	}

	Runtime(const Runtime&) = delete;
	Runtime& operator=(const Runtime&) = delete;

	::JSGlobalContextRef globalContext_ { JSGlobalContextCreate(nullptr) };
	::JSObjectRef				 globalObject_	{ JSContextGetGlobalObject(globalContext_) };
};

}	// namespace Ti {

#endif // _TITANIUM_MOBILE_WINDOWS_TICORE_TIRUNTIME_H_
