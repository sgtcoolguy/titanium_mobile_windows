/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#include "TiCore/TiProxy.h"
#include "TiCore/TiValue.h"

namespace Ti {

// Fires a callback on this object
void Proxy::fireCallback(const std::string& name, const Ti::Value& val) const {
	static const std::string log_prefix { "MDL: Ti::Proxy::fireCallback:" };
	// std::clog << log_prefix << " [DEBUG] " << get_proxy_identifier() << " called with name = " << name << "." << std::endl;
	
	std::vector<Ti::Value> arguments { val };
	callFunction(name, arguments);
}

void Proxy::fireEvent(const std::string& name, const Ti::Value& val) const {
	static const std::string log_prefix { "MDL: Ti::Proxy::fireEvent:" };
	// std::clog << log_prefix << " [DEBUG] " << get_proxy_identifier() << " called with name = " << name << "." << std::endl;

	std::vector<Ti::Value> arguments { Ti::Value(name), val };
	callFunction("fireEvent", arguments);
}


////////////////////////////////////////////////////////////////////////
//
// Proxy macro infrastructure goes below here.
//
////////////////////////////////////////////////////////////////////////

JSStaticFunction const Proxy::ClassMethods[] = {
	{ "eventRemoved", _eventRemoved, kJSPropertyAttributeDontDelete },
	{ "eventAdded", _eventAdded, kJSPropertyAttributeDontDelete },
	{0,0,0}
};

} // namespace Ti
