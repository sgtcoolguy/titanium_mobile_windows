/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#include "TiAppProperties.h"
#include <Windows.h>

#include "TiCore/TiConstants.h"

namespace Ti { namespace App {

	// These are JavaScript methods they will call class methods
	const JSStaticFunction Properties::ClassMethods[] = {
		{"getBool" ,_getBool ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getDouble" ,_getDouble ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getInt" ,_getInt ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getString" ,_getString ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"hasProperty" ,_hasProperty ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"listProperties" ,_listProperties ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"removeProperty" ,_removeProperty ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"setBool" ,_setBool ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"setDouble" ,_setDouble ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"setInt" ,_setInt ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"setString" ,_setString ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{0,0,0}
	};
	
	Properties::~Properties(){
	}
	Properties::Properties(const std::string& name, const std::vector<Ti::Value>& args) : Ti::Proxy(name, args){
		local_settings_ = ApplicationData::Current->LocalSettings;
	}

	Ti::Value Properties::getValue() {
		return Ti::Value(this->get_js_object());
	}

	// Public API
	// Returns the value of a property as a boolean data type.
	Ti::Value Properties::getBool(const std::vector<Ti::Value>& args)
	{
		if (args.size() >= 1) {
			auto values = local_settings_->Values;
			auto value = safe_cast<IPropertyValue^>(values->Lookup(Ti::Utils::GetPlatformString(args.at(0).toString())))->GetBoolean();
			return Ti::Value(value);
		}
		return Ti::Value::Undefined();
	}
	// Returns the value of a property as a double (double-precision, floating point) data type.
	Ti::Value Properties::getDouble(const std::vector<Ti::Value>& args)
	{
		if (args.size() >= 1) {
			auto values = local_settings_->Values;
			auto value = safe_cast<IPropertyValue^>(values->Lookup(Ti::Utils::GetPlatformString(args.at(0).toString())))->GetDouble();
			return Ti::Value(value);
		}
		return Ti::Value::Undefined();
	}

	// Returns the value of a property as an integer data type.
	Ti::Value Properties::getInt(const std::vector<Ti::Value>& args)
	{
		if (args.size() >= 1) {
			auto values = local_settings_->Values;
			auto value = safe_cast<IPropertyValue^>(values->Lookup(Ti::Utils::GetPlatformString(args.at(0).toString())))->GetInt32();
			return Ti::Value(static_cast<double>(value));
		}
		return Ti::Value::Undefined();
	}

	// Returns the value of a property as a string data type.
	Ti::Value Properties::getString(const std::vector<Ti::Value>& args)
	{
		if (args.size() >= 1) {
			auto values = local_settings_->Values;
			auto value = safe_cast<Platform::String^>(values->Lookup(Ti::Utils::GetPlatformString(args.at(0).toString())));
			return Ti::Value(Ti::Utils::GetPlatformString(value));
		}
		return Ti::Value::Undefined();
	}
	// Indicates whether a property exists.
	Ti::Value Properties::hasProperty(const std::vector<Ti::Value>& args)
	{
		if (args.size() >= 1) {
			auto values = local_settings_->Values;
			return Ti::Value(values->HasKey(Ti::Utils::GetPlatformString(args.at(0).toString())));
		}
		return Ti::Value::Undefined();
	}
	// Returns an array of property names.
	Ti::Value Properties::listProperties(const std::vector<Ti::Value>& args)
	{
		auto values = local_settings_->Values;
		std::vector<Ti::Value> properties;
		for (auto i = values->First(); i->HasCurrent; i->MoveNext()) {
			properties.push_back(Ti::Value(Ti::Utils::GetPlatformString(i->Current->Key)));
		}
		return Ti::Value(properties);
	}
	// Removes a property if it exists, or does nothing otherwise.
	Ti::Value Properties::removeProperty(const std::vector<Ti::Value>& args)
	{
		if (args.size() >= 1) {
			auto values = local_settings_->Values;
			values->Remove(Ti::Utils::GetPlatformString(args.at(0).toString()));
		}
		return Ti::Value::Undefined();
	}
	// Sets the value of a property as a boolean data type. The property will be created if it 
	// does not exist.
	Ti::Value Properties::setBool(const std::vector<Ti::Value>& args)
	{
		if (args.size() >= 1) {
			auto values = local_settings_->Values;
			values->Insert(Ti::Utils::GetPlatformString(args.at(0).toString()), dynamic_cast<PropertyValue^>(PropertyValue::CreateBoolean(args.at(1).toBool())));
			fireEvent(Ti::Constants::EventChange, Ti::Value::Undefined());
		}
		return Ti::Value::Undefined();
	}
	// Sets the value of a property as a double (double-precision, floating point) data type. The 
	// property will be created if it does not exist.
	Ti::Value Properties::setDouble(const std::vector<Ti::Value>& args)
	{
		if (args.size() >= 1) {
			auto values = local_settings_->Values;
			values->Insert(Ti::Utils::GetPlatformString(args.at(0).toString()), dynamic_cast<PropertyValue^>(PropertyValue::CreateDouble(args.at(1).toDouble())));
			fireEvent(Ti::Constants::EventChange, Ti::Value::Undefined());
		}
		return Ti::Value::Undefined();
	}
	// Sets the value of a property as an integer data type. The property will be created if it 
	// does not exist.
	Ti::Value Properties::setInt(const std::vector<Ti::Value>& args)
	{
		if (args.size() >= 1) {
			auto values = local_settings_->Values;
			values->Insert(Ti::Utils::GetPlatformString(args.at(0).toString()), dynamic_cast<PropertyValue^>(PropertyValue::CreateInt32(args.at(1).toDouble())));
			fireEvent(Ti::Constants::EventChange, Ti::Value::Undefined());
		}
		return Ti::Value::Undefined();
	}

	// Sets the value of a property as a string data type. The property will be created if it 
	// does not exist.
	Ti::Value Properties::setString(const std::vector<Ti::Value>& args)
	{
		if (args.size() >= 1) {
			auto values = local_settings_->Values;
			values->Insert(Ti::Utils::GetPlatformString(args.at(0).toString()), dynamic_cast<PropertyValue^>(PropertyValue::CreateString(Ti::Utils::GetPlatformString(args.at(1).toString()))));
			fireEvent(Ti::Constants::EventChange, Ti::Value::Undefined());
		}
		return Ti::Value::Undefined();
	}
}}