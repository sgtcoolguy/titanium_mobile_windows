/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

// #ifndef DEBUG_BASEPROXY
// #define DEBUG_BASEPROXY
// #endif

#include "TiCore/BaseProxy.h"
#include <algorithm>

std::atomic<long> BaseProxy::ctor_counter_ { 0 };
std::atomic<long> BaseProxy::dtor_counter_ { 0 };

BaseProxy::ProxyStatistics_t   BaseProxy::proxy_statistics_;
ProxyCacheManager_shared_ptr_t BaseProxy::proxy_cache_manager_ { ProxyCacheManager::Instance() };

BaseProxy_shared_ptr_t BaseProxy::toProxy(const Ti::Value& value) const {
	static const std::string log_prefix { "MDL: BaseProxy::toProxy:" };

#ifdef DEBUG_BASEPROXY
	std::clog << log_prefix << " [DEBUG] " << get_proxy_identifier() << std::endl; 
#endif

	JSGlobalContextRef global_context = Ti::Runtime::instance().globalContext();
	JSValueRef js_value = value.JSValueRef();

	// precondition
	assert(JSValueIsObject(global_context, js_value));

	JSValueRef exception = nullptr;
	JSObjectRef jsObject = JSValueToObject(global_context, js_value, &exception);

	// precondition
	assert(exception == nullptr);

	const auto key = reinterpret_cast<ProxyMap_t::key_type>(JSObjectGetPrivate(jsObject));
	const auto proxy_ptr = proxy_cache_manager_ -> find(key);

#ifdef DEBUG_BASEPROXY
	std::clog << log_prefix
	          << " [DEBUG] found proxy "
	          << proxy_ptr -> get_proxy_identifier()
	          << " in cache (use_count = "
	          << proxy_ptr.use_count()
	          << "), finalized = "
	          << std::boolalpha
	          << proxy_ptr -> get_finalized()
	          << std::endl;
#endif

	// precondition
	assert(proxy_ptr -> get_finalized() == false);

	return proxy_ptr;
}

Ti::Value BaseProxy::callFunction(const std::string& propertyName, const std::vector<Ti::Value>& arguments) const {
	static const std::string log_prefix { "MDL: BaseProxy::callFunction:" };

#ifdef DEBUG_BASEPROXY
	std::clog << log_prefix << " [DEBUG] " << get_proxy_identifier() << " calling function " << propertyName << " with " << arguments.size() << " arguments." << std::endl;
#endif
	
	const auto js_object = get_js_object();
	JSGlobalContextRef global_context = Ti::Runtime::instance().globalContext();
	
	// Find the JavaScript function with the given name assuming it is
	// a property of this proxy.
	auto propertyNameStr = JSStringCreateWithUTF8CString(propertyName.c_str());
	JSValueRef exception = nullptr;
	JSValueRef property  = JSObjectGetProperty(global_context, js_object, propertyNameStr, &exception);
	JSStringRelease(propertyNameStr);
	if (exception) {
		return Ti::Value(exception);
	}
	// precondition
	assert(exception == nullptr);
	
	// Check if the property can be called as a function.
	if (!JSValueIsObject(global_context, property)) {
		std::clog << log_prefix << " [WARN] " << get_proxy_identifier() << " property " << propertyName << " can not be called as a function." << std::endl;
		Ti::Value::Undefined();
	}
	
	// Convert the property to an object that can be called.
	JSObjectRef object = JSValueToObject(global_context, property, &exception);
	
	// precondition
	if (exception) {
		const std::string exception_string = Ti::Value(exception).toString();
		std::clog << log_prefix << " [ERROR] " << get_proxy_identifier() << " converting property " << propertyName << " to JSObjectRef caught exception:  " << exception_string << std::endl;
		return Ti::Value(exception);
	}
	assert(exception == nullptr);
	
	std::vector<JSValueRef> argument_array;
	std::transform(arguments.begin(), arguments.end(), std::back_inserter(argument_array), [](const Ti::Value& value) { return value.JSValueRef();});
	
	JSValueRef result = JSObjectCallAsFunction(global_context, object, js_object, argument_array.size(), &argument_array[0], &exception);
	if (exception) {
		const std::string exception_string = Ti::Value(exception).toString();
		std::clog << log_prefix << " [ERROR] " << get_proxy_identifier() << " calling function " << propertyName << " caught exception:  " << exception_string << std::endl;
		return Ti::Value(exception);
	}
	assert(exception == nullptr);
	
	return Ti::Value(result);
}

void BaseProxy::Finalizer(JSObjectRef js_object) {
	static const std::string log_prefix { "MDL: BaseProxy::Finalizer:" };
	// std::clog << log_prefix << std::endl;
	const auto key = reinterpret_cast<ProxyMap_t::key_type>(JSObjectGetPrivate(js_object));

#ifdef DEBUG_BASEPROXY
	std::clog << log_prefix << " [DEBUG] key = " << key << std::endl;
#endif
	// assert(key != 0);
	if (key == 0) {
		// std::clog << log_prefix << " [DEBUG] key = " << key << " was 0." << std::endl;
		return;
	}
	const auto start = std::chrono::high_resolution_clock::now();
	const auto proxy_ptr  = proxy_cache_manager_ -> remove(key);
	proxy_ptr -> set_finalized();
	const auto end = std::chrono::high_resolution_clock::now();
	const auto diff = end - start;
	auto &stats = get_proxy_statistics()[proxy_ptr -> get_proxy_name()];
	stats.add_duration(diff);
	JSObjectSetPrivate(js_object, nullptr);
}


////////////////////////////////////////////////////////////////////////
//
// Proxy macro infrastructure goes below here.
//
////////////////////////////////////////////////////////////////////////

JSStaticFunction const BaseProxy::ClassMethods[] = {
	{"testMethod", _testMethod, kJSPropertyAttributeNone},
	{"ProxyIdentifier", _ProxyIdentifier, kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete},
	{0,0,0}
};
