/** -*- mode: c++ -*-
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MOBILE_WINDOWS_TICORE_TIVALUE_H_
#define _TITANIUM_MOBILE_WINDOWS_TICORE_TIVALUE_H_

#include <JavaScriptCore/JavaScript.h>
#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <atomic>
#include "TiCore/TiRuntime.h"

/**
 * TiValue
 *
 * Design constraints:
 *
 * Objects of this class can only live on the stack. Never the heap. This is enforced in the class' design.
 * This class should never be subclassed.
 *
 *
 * Description:
 *		Wrapper class for creating JSValues and and calling methods on them.
 *		Instances of this class must be created on the stack.
 *		Some examples:
 *			To create a Undefined JS value simply:
 *				Ti::Value undefined();
 *			To create a Number JS value, pass the number to the constructor
 *				Ti::Value number(12.23);
 *		You can also create JS objects or array by passing a std::map or std::vector
 *			To create an Object value with a map:
 *				std::map<std::string, Ti::Value> myObject;
 *				myObject["number"] = Ti::Value(12.34);
 *				myObject["string"] = Ti::Value("hello world);
 *				Ti::Value jsObject(myObject);
 *			Similarly, create a Array value
 *				std::vector<Ti::Value> myArray;
 *				myArray.push_back(Ti::Value(12.34));
 *				myArray.push_back(Ti::Value("hello world");
 *				Ti::Value jsArray(myArray);
 */
namespace Ti {

class Proxy;
class Value final	{

 public:

	// Create an empty object.
	Value() {
		//std::clog << "TiValue: ctor called ()" << std::endl;
		postConstruct(JSObjectMake(globalContext_, nullptr, nullptr));
	}

	~Value() {
		//std::clog << "TiValue: dtor called" << std::endl;
		++dtor_counter_;
	}

	// Copy constructor.
	Value(const Value& rhs) {
		//std::clog << "TiValue: copy ctor called" << std::endl;
		postConstruct(rhs.value_);
	}

	// Create a copy of another Ti::Value by assignment.
	Value& operator=( const Value& rhs ) {
		//std::clog << "TiValue: operator= called" << std::endl;

		if ( this == &rhs ) {
			return *this;
		}


		value_ = rhs.value_;



		return *this;
	}

	// Creates a Ti::Value with a predefined JSValueRef
	explicit Value(JSValueRef value) {
		//std::clog << "TiValue: ctor called (JSValueRef)" << std::endl;
		postConstruct(value);
	}

	// Creates a Ti::Value from a c string, the internal value will be
	// a String
	explicit Value(const char* string) {
		//std::clog << "TiValue: ctor called (const char*)" << std::endl;
		auto jsString = JSStringCreateWithUTF8CString(string);
		postConstruct(JSValueMakeString(globalContext_, jsString));
		JSStringRelease(jsString);
	}

	explicit Value(const std::string& string) {
		//std::clog << "TiValue: ctor called (std::string)" << std::endl;
		auto jsString = JSStringCreateWithUTF8CString(string.c_str());
		postConstruct(JSValueMakeString(globalContext_, jsString));
		JSStringRelease(jsString);
	}
	// Creates a Ti::Value from a std::vector, the internal value will be an Array
	explicit Value(const std::vector<Value>& list);

	// Creates a Ti::Value from a std::map, this internal value will be an Object
	explicit Value(const std::map<std::string, Value>& map);

	// Creates a Ti::Value from a number, it must be a double. The internal value will be a Number
	explicit Value(double number) {
		//std::clog << "TiValue: ctor called (double)" << std::endl;
		postConstruct(JSValueMakeNumber(globalContext_, number));
	}

	// Creates a Ti::Value from a bool, the internal value will be a Boolean
	explicit Value(bool flag) {
		//std::clog << "TiValue: ctor called (bool)" << std::endl;
		postConstruct(JSValueMakeBoolean(globalContext_, flag));
	}

	// Create a Ti::Value from the given C array of JSValueRef, and
	// return the corresponding JavaScript array. This is always used
	// for Proxy callback function arguments.
	explicit Value(const JSValueRef arguments[], size_t argumentCount) {
		if(argumentCount == 0) {
			// According to JSObjectRef.h:
			// @param arguments A JSValue array of data to populate the Array with. Pass NULL if argumentCount is 0.
			postConstruct(JSObjectMakeArray(globalContext_, 0, nullptr, nullptr));
		} else {
			postConstruct(JSObjectMakeArray(globalContext_, argumentCount, arguments, nullptr));
		}
	}

	// Create a Ti::Value of each of these types
	static Value Undefined() {
		return Value(JSValueMakeUndefined(Ti::Runtime::instance().globalContext()));
	}

	static Value Null() {
		return Value(JSValueMakeNull(Ti::Runtime::instance().globalContext()));
	}

	// ======= Utility methods for objects =======
	// Gets the property `propertyName` from the internal JSObjectRef. A Ti::Value containing
	// this property will be returned. If the internal value is not an object, the Ti::Value's value
	// will be Undefined
	Value getProperty(const std::string& propertyName) const {
		assert(isObject());
		auto propertyNameStr = JSStringCreateWithUTF8CString(propertyName.c_str());
		auto value = JSObjectGetProperty(globalContext_, (::JSObjectRef)value_, propertyNameStr, nullptr);
		JSStringRelease(propertyNameStr);
		return Value(value);
	}

	// Sets a property on the internal JSObjectRef. It will fail if the internal value is not
	// a JSObjectRef
	void setProperty(const std::string& propertyName, const Value& value, JSPropertyAttributes attr = kJSPropertyAttributeNone) {
		assert(isObject());
		auto propertyNameStr = JSStringCreateWithUTF8CString(propertyName.c_str());
		JSObjectSetProperty(globalContext_, (::JSObjectRef)value_, propertyNameStr, value.JSValueRef(), attr, nullptr);
		JSStringRelease(propertyNameStr);
	}

	// Returns a std::map with all the Object properties
	const std::map<std::string, Value> toDictionary() const;

	bool isProxy() const {
		if (!isObject()) return false;
		return JSObjectGetPrivate(JSObjectRef()) != nullptr;
	}

	bool isFunction() const {
		return JSObjectIsFunction(globalContext_, JSObjectRef());
	}

	// ======= Utility methods for arrays =======
	// Returns true if the internal value is of type Array
	bool isArray() const {
		//
		// strict check for JS array type by Array.isArray(value)
		//
		if (isObject()) {
			const auto global = Ti::Value(Ti::Runtime::instance().globalObject());
			const auto array = global.getProperty("Array");
			if (!array.isObject()) {
				return false;
			}
			const auto isArray = array.getProperty("isArray");
			if (!isArray.isObject()) {
				return false;
			}
			auto exception = JSValueMakeNull(globalContext_);
			const auto result = Ti::Value(JSObjectCallAsFunction(globalContext_, isArray.JSObjectRef(), global.JSObjectRef(), 1, &value_, &exception));
			if (JSValueIsNull(globalContext_, exception) && result.isBoolean()) {
				return result.toBool();
			} else {
				return false;
			}
		}
		return false;
	}

	// Returns the length of the array in double format for consistency
	size_t getLength() const {
		// Same as above, but this time return the length number
		return static_cast<size_t>(getProperty("length").toDouble());
	}

	// Returns a Ti::Value at index `index` if the internal value is an array,
	// otherwise it will fail
	Value getValueAtIndex(int index) const {
		assert(isObject());
		return Value(JSObjectGetPropertyAtIndex(globalContext_, (::JSObjectRef)value_, index, nullptr));
	}

	// Returns an std::vector with all the values of the array
	std::vector<Value> toVector() const;

	//	======= Casting, converting JSValueRef to C/C++ types =======
	// Returns a number representation of the internal value
	double toDouble() const {
		::JSValueRef exception = 0;
		const double result = JSValueToNumber(globalContext_, value_, &exception);
		if (exception) {
			//[_context notifyException:exception];
			return std::numeric_limits<double>::quiet_NaN();
		}

		return result;
	}

	Ti::Value toJSONObject() const {
		auto str = JSValueToStringCopy(globalContext_, value_, nullptr);
		auto json = JSValueMakeFromJSONString(globalContext_, str);
		JSStringRelease(str);
		return Ti::Value(json);
	}

	// Returns a bool representation of the internal value
	bool toBool() const {
		return JSValueToBoolean(globalContext_, value_);
	}

	// Returns an std::string representation of the internal value
	std::string toString() const;

	// Returns an JSON std::string representation of the internal value
	std::string toJSONString() const;

	// Checking types
	// Returns true if the internal value is Undefined, otherwise it returns false
	bool isUndefined() const {
		return JSValueIsUndefined(globalContext_, value_);
	}

	// Returns true if the internal value is Null, otherwise it returns false
	bool isNull() const {
		return JSValueIsNull(globalContext_, value_);
	}

	// Returns true if the internal value is a Boolean, otherwise it returns false
	bool isBoolean() const {
		return JSValueIsBoolean(globalContext_, value_);
	}

	// Returns true if the internal value is a Number, otherwise it returns false
	bool isNumber() const {
		return JSValueIsNumber(globalContext_, value_);
	}

	// Returns true if the internal value is a String, otherwise it returns false
	bool isString() const {
		return JSValueIsString(globalContext_, value_);
	}

	// Returns true if the internal value is an Object, otherwise it returns false
	bool isObject() const {
		return JSValueIsObject(globalContext_, value_);
	}

	// Returns the interal value
	::JSValueRef JSValueRef() const {
		return value_;
	}

	// Returns the interal value as a JSObjectRef that's what it is, otherwise the behaviour
	// is undefined
	::JSObjectRef JSObjectRef() const {
		// Cast the value to a JSObjectRef
		// TODO: Handle exception
		return JSValueToObject(globalContext_, value_, nullptr);
	}

	static long get_ctor_counter() {
		return ctor_counter_;
	}

	static long get_dtor_counter() {
		return dtor_counter_;
	}

 protected:

	// Prevent heap based objects.
	static void * operator new(size_t);			 // #1: To prevent allocation of scalar objects
	static void * operator new [] (size_t);	 // #2: To prevent allocation of array of objects

 private:

	void postConstruct(::JSValueRef value) {
		value_ = value;
		++ctor_counter_;
		//std::clog << "TiValue:" << ctorCounter_ << " created, " << dtorCounter_ << " destroyed" << std::endl;
	}

	::JSGlobalContextRef globalContext_ {	Ti::Runtime::instance().globalContext() };
	::JSValueRef value_ { nullptr };

	static std::atomic<long> ctor_counter_;
	static std::atomic<long> dtor_counter_;
};

} // namespace Ti {

#endif // _TITANIUM_MOBILE_WINDOWS_TICORE_TIVALUE_H_
