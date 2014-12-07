/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#ifndef __TI_APP_PROPERTIES_PROXY_H__
#define __TI_APP_PROPERTIES_PROXY_H__

#include "TiCore/TiProxy.h"
#include "TiCore/TiUtils.h"

using namespace Windows::Storage;
using namespace Windows::Foundation;

namespace Ti { namespace App {
	class Properties : public Ti::Proxy, public virtual_enable_shared_from_this<Properties> {

	TI_CREATE_PROXY(Properties)

public:

	Ti::Value getValue();

private:

	ApplicationDataContainer^ local_settings_;

protected:

	static JSClassRef Parent() { return Ti::Proxy::ClassDef(); }
	Properties(const std::string&, const std::vector<Ti::Value>&);
	virtual ~Properties();

	// JavaScript's public API

	// Returns the value of a property as a boolean data type.
	Ti::Value getBool(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(Properties, getBool);

	// Returns the value of a property as a double (double-precision, floating point) data type.
	Ti::Value getDouble(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(Properties, getDouble);

	// Returns the value of a property as an integer data type.
	Ti::Value getInt(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(Properties, getInt);

	// Returns the value of a property as a string data type.
	Ti::Value getString(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(Properties, getString);

	// Indicates whether a property exists.
	Ti::Value hasProperty(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(Properties, hasProperty);

	// Returns an array of property names.
	Ti::Value listProperties(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(Properties, listProperties);

	// Removes a property if it exists, or does nothing otherwise.
	Ti::Value removeProperty(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(Properties, removeProperty);

	// Sets the value of a property as a boolean data type. The property will be created if it 
	// does not exist.
	Ti::Value setBool(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(Properties, setBool);

	// Sets the value of a property as a double (double-precision, floating point) data type. The 
	// property will be created if it does not exist.

	Ti::Value setDouble(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(Properties, setDouble);

	// Sets the value of a property as an integer data type. The property will be created if it 
	// does not exist.
	Ti::Value setInt(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(Properties, setInt);

	// Sets the value of a property as a string data type. The property will be created if it 
	// does not exist.
	Ti::Value setString(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(Properties, setString);
};
}}
#endif // defined(__TI_APP_PROPERTIES_PROXY_H__)