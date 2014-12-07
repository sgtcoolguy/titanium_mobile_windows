/** -*- mode: c++ -*-
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MOBILE_WINDOWS_TEST_TIVALUE_TIVALUE_TIVALUE_EXAMPLEPROXY_H_
#define _TITANIUM_MOBILE_WINDOWS_TEST_TIVALUE_TIVALUE_TIVALUE_EXAMPLEPROXY_H_

#include "TiCore/TiProxy.h"

namespace Ti {

class ExampleProxy : public Proxy, public virtual_enable_shared_from_this<ExampleProxy> {

 public:

	bool get_post_construct_called() const {
		return post_construct_called_;
	}

 protected:

	ExampleProxy(const std::string& name, const std::vector<Ti::Value>& arguments) : Ti::Proxy(name, arguments) {
	}

	virtual void postConstruct() {
		// static const std::string log_prefix { "MDL: ExampleProxy::postConstruct:" };
		// std::clog << log_prefix << " [DEBUG] for " << get_proxy_identifier() << "." << std::endl;
		post_construct_called_ = true;
	}

 private:

	bool post_construct_called_ { false };

	TI_CREATE_PROXY(ExampleProxy);

	static JSClassRef Parent() {
	  return Proxy::ClassDef();
	}

	// JavaScriptCore calls an auto-generated _saySomething static
	// function Which then calls this function
	TI_CREATE_METHOD(ExampleProxy, saySomething);
	Ti::Value saySomething(const std::vector<Ti::Value>& arguments) {
		std::cout << arguments.at(0).toString() << std::endl;
		return Ti::Value(true);
	}

	TI_CREATE_METHOD(ExampleProxy, createNew);
	Ti::Value createNew(const std::vector<Ti::Value>& arguments) {
		auto proxy_ptr = ExampleProxy::create("ExampleProxy", arguments);
		// do something useful to the new proxy
		//return Ti::Value(proxy_ptr);
		return Ti::Value();
	}
};

}  // namespace Ti {

#endif // _TITANIUM_MOBILE_WINDOWS_TEST_TIVALUE_TIVALUE_TIVALUE_EXAMPLEPROXY_H_
