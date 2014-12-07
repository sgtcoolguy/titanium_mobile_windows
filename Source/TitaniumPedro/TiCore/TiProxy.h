/** -*- mode: c++ -*-
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MOBILE_WINDOWS_TICORE_TIPROXY_H_
#define _TITANIUM_MOBILE_WINDOWS_TICORE_TIPROXY_H_

#include <iostream>
#include "TiCore/BaseProxy.h"

// This is the main Proxy, every Proxy will inherit from this
namespace Ti {

class Proxy : public BaseProxy, public virtual_enable_shared_from_this<Proxy> {

 public:

	// Call this to fire an event to the JS
	// fireEvent("click", Ti::Value());
	void fireEvent(const std::string&, const Ti::Value&) const;

	// Call this to fire a callback, for example
	// JS:
	// myPrpxy.onLoad = function(e) {};
	// C++
	// fireCallback("onLoad", Ti::Value());
	void fireCallback(const std::string&, const Ti::Value&) const;

 protected:

	explicit Proxy(const std::string& name, const std::vector<Ti::Value>& arguments) : BaseProxy(name, arguments) {
	}

	////////////////////////////////////////////////////////////////////////
	//
	// Proxy macro infrastructure goes below here.
	//
	////////////////////////////////////////////////////////////////////////
	virtual ~Proxy(){
		// Uncomment to see the proxies being deleted
		// std::clog << "Deleting proxy " << get_proxy_name() << std::endl;
	}
	TI_CREATE_PROXY(Proxy);

	static JSClassRef Parent() {
		return BaseProxy::ClassDef();
	}

	// Called when an event has been added to the object
	TI_CREATE_METHOD(Proxy, eventAdded);
	virtual Ti::Value eventAdded(const std::vector<Ti::Value>& arguments) {
		static const std::string log_prefix { "MDL: Ti::Proxy::eventAdded:" };
		// std::clog << log_prefix << " [DEBUG] " << get_proxy_identifier() << " called with " << arguments.size() << " arguments." << std::endl;
		
		// preconditions
		assert(arguments.size() == 2);
		assert(arguments.at(0).isString());
		assert(arguments.at(1).isObject());
		
		const auto eventName = arguments.at(0).toString();
		const auto callback  = arguments.at(1).JSValueRef();
		
		// std::clog << log_prefix << " [DEBUG] " << get_proxy_identifier() << " eventName = " << eventName << "." << std::endl;
		JSValueProtect(Ti::Runtime::instance().globalContext(), callback);
		
		return Ti::Value::Undefined();
	}

	// Called when an event has been removed from the object
	TI_CREATE_METHOD(Proxy, eventRemoved);
	virtual Ti::Value eventRemoved(const std::vector<Ti::Value>& arguments) {
		static const std::string log_prefix { "MDL: Ti::Proxy::eventRemoved:" };
		// std::clog << log_prefix << " [DEBUG] " << get_proxy_identifier() << " called with " << arguments.size() << " arguments." << std::endl;
		
		// preconditions
		assert(arguments.size() == 2);
		assert(arguments.at(0).isString());
		assert(arguments.at(1).isObject());
		
		const auto eventName = arguments.at(0).toString();
		const auto callback  = arguments.at(1).JSValueRef();
		
		// std::clog << log_prefix << " [DEBUG] " << get_proxy_identifier() << " eventName = " << eventName << "." << std::endl;
		JSValueUnprotect(Ti::Runtime::instance().globalContext(), callback);
		
		return Ti::Value::Undefined();
	}
};

}  // namespace Ti {

#endif // _TITANIUM_MOBILE_WINDOWS_TICORE_TIPROXY_H_
