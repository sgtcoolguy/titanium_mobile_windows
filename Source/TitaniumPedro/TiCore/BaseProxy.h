/** -*- mode: c++ -*-
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */


#ifndef _TITANIUM_MOBILE_WINDOWS_TICORE_BASEPROXY_H_
#define _TITANIUM_MOBILE_WINDOWS_TICORE_BASEPROXY_H_

#include <iostream>
//#include <unordered_map>
#include <chrono>
#include <mutex>
#include <memory>
#include <utility>
#include <cstdint>
#include <JavaScriptCore/JavaScript.h>
#include "Util/Statistics.hpp"
#include "TiCore/ProxyCacheManager.hpp"
#include "TiCore/TiRuntime.h"
#include "TiCore/TiValue.h"
#include "Util/virtual_enable_shared_from_this_base.hpp"
#include "Util/JSObjectRefRAII.hpp"

using Appcelerator::Util::virtual_enable_shared_from_this;
using Appcelerator::Util::JSObjectRefRAII;

class BaseProxy;
using ProxyMap_t = std::unordered_map < std::intptr_t, std::shared_ptr<BaseProxy> > ;

#define TITANIUM_MOBILE_WINDOWS_STR_HELPER(x) #x
#define TITANIUM_MOBILE_WINDOWS_STR(x) TITANIUM_MOBILE_WINDOWS_STR_HELPER(x)

#ifndef TI_CREATE_METHOD
#define TI_CREATE_METHOD(PROXY_NAME, METHOD_NAME)	\
 protected: \
	static JSValueRef _##METHOD_NAME(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef argumentArray[], JSValueRef* exception) { \
		static const std::string proxyIdentifier { TITANIUM_MOBILE_WINDOWS_STR(PROXY_NAME) "_" TITANIUM_MOBILE_WINDOWS_STR(METHOD_NAME) }; \
		/* std::clog << "MDL: " << proxyIdentifier << std::endl; */  \
		/* std::clog << "MDL: " << proxyIdentifier << ": argumentCount = " << argumentCount << std::endl; */ \
		auto proxy_ptr = reinterpret_cast<PROXY_NAME*>(JSObjectGetPrivate(thisObject)); \
		assert(proxy_ptr); \
		auto start = std::chrono::high_resolution_clock::now(); \
		auto arguments = Ti::Value(argumentArray, argumentCount).toVector(); \
		auto result = proxy_ptr -> METHOD_NAME(arguments).JSValueRef(); \
		auto end = std::chrono::high_resolution_clock::now(); \
		auto diff = end - start; \
		auto &stats = get_proxy_statistics()[proxyIdentifier]; \
		stats.add_duration(diff); \
		return result; \
	};
#endif

#ifndef TI_CREATE_PROXY
#define TI_CREATE_PROXY(PROXY_NAME) \
 public: \
	using virtual_enable_shared_from_this<PROXY_NAME>::shared_from_this; \
	using PROXY_NAME##_shared_ptr_t = std::shared_ptr<PROXY_NAME>; \
	using PROXY_NAME##_weak_ptr_t   = std::weak_ptr<PROXY_NAME>; \
\
	template <typename... Ts> \
	static std::shared_ptr<PROXY_NAME> create(Ts&&... params) { \
		static const std::string proxy_identifier { TITANIUM_MOBILE_WINDOWS_STR(PROXY_NAME) "_ctor_from_create" }; \
		const auto start = std::chrono::high_resolution_clock::now(); \
		auto proxy_ptr = std::shared_ptr<PROXY_NAME>(new PROXY_NAME(std::forward<Ts>(params)...), deleter{}); \
		auto key = proxy_cache_manager_ -> add(std::static_pointer_cast<BaseProxy>(proxy_ptr)); \
		const auto end = std::chrono::high_resolution_clock::now(); \
		const auto diff = end - start; \
		auto &stats = get_proxy_statistics()[proxy_identifier]; \
		stats.add_duration(diff); \
		auto context = Ti::Runtime::instance().globalContext(); \
		auto object = JSObjectMake(context, PROXY_NAME::ClassDef(), reinterpret_cast<void*>(key)); \
		auto ti_private = JSObjectMake(context, nullptr, nullptr); \
		auto ti_private_string = JSStringCreateWithUTF8CString("__ti_private__"); \
		JSObjectSetProperty(context, object, ti_private_string, ti_private, kJSPropertyAttributeDontEnum | kJSPropertyAttributeDontDelete, nullptr); \
		JSStringRelease(ti_private_string); \
		proxy_ptr -> set_js_object(object); \
		proxy_ptr -> postConstruct(); \
		return proxy_ptr; \
	} \
\
	static JSClassRef ClassDef() { \
		static JSClassRef classDef = nullptr; \
		static std::once_flag of; \
		std::call_once(of, [] { \
			JSClassDefinition def = kJSClassDefinitionEmpty; \
			def.className = #PROXY_NAME; \
			def.staticFunctions = PROXY_NAME::ClassMethods; \
			def.callAsConstructor = PROXY_NAME::ConstructorCallback; \
			def.parentClass = PROXY_NAME::Parent(); \
			def.finalize = Finalizer; \
			classDef = JSClassCreate(&def); \
			}); \
		return classDef; \
	} \
\
	static Ti::Value CreateConstructor() { \
		return Ti::Value(JSObjectMakeConstructor(Ti::Runtime::instance().globalContext(), PROXY_NAME::ClassDef(), PROXY_NAME::ConstructorCallback)); \
	} \
\
 private: \
 \
	std::shared_ptr<PROXY_NAME> get_shared_ptr_for_proxy() const { \
		return std::dynamic_pointer_cast<PROXY_NAME>(get_shared_ptr_for_base_proxy()); \
	} \
\
	std::weak_ptr<PROXY_NAME> get_weak_ptr_for_proxy() const { \
		return std::dynamic_pointer_cast<PROXY_NAME>(get_shared_ptr_for_proxy()); \
	} \
\
	static const JSStaticFunction ClassMethods[]; \
\
	static JSObjectRef ConstructorCallback (JSContextRef ctx, JSObjectRef constructor, size_t argumentCount, const JSValueRef argumentArray[], JSValueRef* exception) { \
		static const std::string proxyIdentifier { TITANIUM_MOBILE_WINDOWS_STR(PROXY_NAME) "_ctor_from_ConstructorCallback" }; \
		/* std::clog << "MDL: " << proxyIdentifier << std::endl; */  \
		/* std::clog << "MDL: " << proxyIdentifier << ": argumentCount = " << argumentCount << std::endl; */  \
		auto arguments = Ti::Value(argumentArray, argumentCount).toVector(); \
		auto proxy_ptr = PROXY_NAME::create(#PROXY_NAME, arguments); \
		return proxy_ptr -> get_js_object(); \
	} \
\
	struct deleter { \
		void operator()(PROXY_NAME* ptr) { \
			delete ptr; \
		} \
	};
#endif

class BaseProxy : public virtual_enable_shared_from_this<BaseProxy> {

 public:

	using ProxyStatistics_t = std::unordered_map<std::string, Appcelerator::Util::Statistics>;

	static long get_ctor_counter() {
		return ctor_counter_;
	}
	
	static long get_dtor_counter() {
		return dtor_counter_;
	}
	
	static ProxyStatistics_t& get_proxy_statistics() {
		return proxy_statistics_;
	}

protected:

	BaseProxy(const std::string& name, const std::vector<Ti::Value>& arguments) : proxy_name_(name){
		++ctor_counter_;
	}
	
	virtual ~BaseProxy() {
		++dtor_counter_;
	}
	
	virtual void postConstruct() {
		static const std::string log_prefix { "MDL: BaseProxy::postConstruct:" };
		// std::clog << log_prefix << " [DEBUG] for " << get_proxy_identifier() << "." << std::endl;
	}

	virtual std::shared_ptr<BaseProxy> get_shared_ptr_for_base_proxy() const {
		static const std::string log_prefix { "MDL: BaseProxy::get_shared_ptr_for_base_proxy:" };
		const auto key = get_proxy_map_key();
		const auto proxy_ptr = proxy_cache_manager_ -> find(key);
		proxy_cache_manager_ -> sweep();
		// proxy_cache_manager_ -> scan();
		return proxy_ptr;
	}
	
	std::string get_proxy_name() const {
		return proxy_name_;
	}
	
	virtual std::string get_proxy_identifier() const {
		BaseProxy* self = const_cast<BaseProxy*>(this);
		std::call_once(self -> proxy_identifier_once_flag_, [self] () {
				self -> proxy_identifier_ = self -> get_proxy_name() + "[" + std::to_string(reinterpret_cast<std::intptr_t>(self)) + "]";
			});
		
		return proxy_identifier_;
	}

	virtual ProxyMap_t::key_type get_proxy_map_key() const {
		BaseProxy* self = const_cast<BaseProxy*>(this);
		std::call_once(self -> proxy_map_key_once_flag_, [self] () {
				self -> proxy_map_key_ = reinterpret_cast<ProxyMap_t::key_type>(self);
			});
		
		return proxy_map_key_;
	}

	bool get_finalized() const {
		return finalized_;
	}

	JSObjectRefRAII get_js_object() const{
		static const std::string log_prefix { "MDL: BaseProxy::get_js_object:" };

#ifdef DEBUG_BASEPROXY
		std::clog << log_prefix << " [DEBUG] finalized_ = " << std::boolalpha << finalized_ << " for " << get_proxy_identifier() << "." << std::endl;
#endif

		// precondition
		assert(!finalized_);

		return JSObjectRefRAII(js_object_, Ti::Runtime::instance().globalContext());
	}
	
	void set_js_object(JSObjectRef obj) {
		// precondition: This setter can only be called once.
		assert(js_object_ == nullptr);
		js_object_ = obj;
	}

	virtual BaseProxy_shared_ptr_t toProxy(const Ti::Value& value) const;
	
	virtual Ti::Value callFunction(const std::string& functionName, const std::vector<Ti::Value>& arguments) const;
	
	static void Finalizer(JSObjectRef obj);

	static ProxyCacheManager_shared_ptr_t proxy_cache_manager_;

 private:

	friend ProxyCacheManager;
	
	BaseProxy(const BaseProxy& rhs) = delete;
	BaseProxy& operator=( const BaseProxy& rhs ) = delete;

	void set_finalized() {
		static const std::string log_prefix { "MDL: BaseProxy::set_finalized:" };
		assert(!finalized_);
		std::call_once(finalized_once_flag_, [this] () {
				this -> finalized_ = true;
			});

#ifdef DEBUG_BASEPROXY
		std::clog << log_prefix << " [DEBUG] finalized_ = " << std::boolalpha << finalized_ << " for " << get_proxy_identifier() << "." << std::endl;
#endif
	}
	
	JSObjectRef                  js_object_ { nullptr };
	std::string                  proxy_name_;
	std::string                  proxy_identifier_;
	std::once_flag               proxy_identifier_once_flag_;
	ProxyCacheManager_key_type_t proxy_map_key_;
	std::once_flag               proxy_map_key_once_flag_;
	bool                         finalized_ { false };
	bool                         protected_ { false };
	std::once_flag               finalized_once_flag_;

	static std::atomic<long> ctor_counter_;
	static std::atomic<long> dtor_counter_;
	static ProxyStatistics_t proxy_statistics_;


	////////////////////////////////////////////////////////////////////////
	//
	// Proxy macro infrastructure goes below here.
	//
	////////////////////////////////////////////////////////////////////////
	
	TI_CREATE_PROXY(BaseProxy);

	static JSClassRef Parent() {
		return nullptr;
	}

	TI_CREATE_METHOD(BaseProxy, testMethod);
	Ti::Value testMethod(const std::vector<Ti::Value>& arguments) {
		return Ti::Value(arguments.at(0).toString());
	}

	TI_CREATE_METHOD(BaseProxy, ProxyIdentifier);
	Ti::Value ProxyIdentifier(const std::vector<Ti::Value>& arguments) const {
		return Ti::Value(get_proxy_identifier());
	}
};

#endif // _TITANIUM_MOBILE_WINDOWS_TICORE_BASEPROXY_H_
