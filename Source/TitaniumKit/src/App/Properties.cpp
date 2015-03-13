/**
* TitaniumKit Titanium.App.Properties
*
* Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/

#include "Titanium/App/Properties.hpp"

namespace Titanium
{
	namespace App
	{
		JSFunction Properties::createStringifyFunction(const JSContext& js_context) const TITANIUM_NOEXCEPT
		{
			return get_context().CreateFunction("return JSON.stringify(value);", { "value" });
		}

		Properties::Properties(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Module(js_context),
			  stringify_function__(createStringifyFunction(js_context))
		{
			TITANIUM_LOG_DEBUG("Properties:: ctor ", this);
		}

		void Properties::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) {
			HAL_LOG_DEBUG("Properties:: postCallAsConstructor ", this);
		}

		bool Properties::getBool(const std::string& property, bool defaultValue) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Properties::getBool: Unimplemented");
			return false;
		}

		double Properties::getDouble(const std::string& property, double defaultValue) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Properties::getDouble: Unimplemented");
			return 0;
		}

		double Properties::getInt(const std::string& property, double defaultValue) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Properties::getInt: Unimplemented");
			return 0;
		}

		std::vector<JSValue> Properties::getList(const std::string& property, std::vector<JSValue> defaultValue) TITANIUM_NOEXCEPT
		{
			if (hasProperty(property)) {
				auto object = getObject(property, get_context().CreateObject());
				if (object.IsArray()) {
					return static_cast<JSArray>(object);
				}
			}
			return defaultValue;
		}

		JSObject Properties::getObject(const std::string& property, JSObject defaultValue) TITANIUM_NOEXCEPT
		{
			if (hasProperty(property)) {
				auto value = get_context().CreateValueFromJSON(getString(property, ""));
				if (value.IsObject()) {
					return static_cast<JSObject>(value);
				}
			}
			return defaultValue;
		}

		std::string Properties::getString(const std::string& property, const std::string& defaultValue) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Properties::getString: Unimplemented");
			return "";
		}

		bool Properties::hasProperty(const std::string& property) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Properties::hasProperty: Unimplemented");
			return false;
		}

		std::vector<std::string> Properties::listProperties() TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Properties::listProperties: Unimplemented");
			return std::vector <std::string>();
		}

		void Properties::removeProperty(const std::string& property) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Properties::removeProperty: Unimplemented");
		}

		void Properties::setBool(const std::string& property, bool value) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Properties::setBool: Unimplemented");
		}

		void Properties::setDouble(const std::string& property, double value) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Properties::setDouble: Unimplemented");
		}

		void Properties::setInt(const std::string& property, int value) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Properties::setInt: Unimplemented");
		}

		void Properties::setList(const std::string& property, std::vector<JSValue> value) TITANIUM_NOEXCEPT
		{
			std::vector<JSValue> arguments;
			arguments.push_back(get_context().CreateArray(value));
			setString(property, static_cast<std::string>(stringify_function__(arguments, get_context().get_global_object())));

			//fireEvent
		}

		void Properties::setObject(const std::string& property, JSObject value) TITANIUM_NOEXCEPT
		{
			setString(property, static_cast<std::string>(stringify_function__({ value }, get_context().get_global_object())));

			//fireEvent
		}

		void Properties::setString(const std::string& property, const std::string& value) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Properties::setString: Unimplemented");
		}


		void Properties::JSExportInitialize() {
			JSExport<Properties>::SetClassVersion(1);
			JSExport<Properties>::SetParent(JSExport<Module>::Class());

			JSExport<Properties>::AddFunctionProperty("getBool", std::mem_fn(&Properties::js_getBool));
			JSExport<Properties>::AddFunctionProperty("getDouble", std::mem_fn(&Properties::js_getDouble));
			JSExport<Properties>::AddFunctionProperty("getInt", std::mem_fn(&Properties::js_getInt));
			JSExport<Properties>::AddFunctionProperty("getList", std::mem_fn(&Properties::js_getList));
			JSExport<Properties>::AddFunctionProperty("getObject", std::mem_fn(&Properties::js_getObject));
			JSExport<Properties>::AddFunctionProperty("getString", std::mem_fn(&Properties::js_getString));
			JSExport<Properties>::AddFunctionProperty("hasProperty", std::mem_fn(&Properties::js_hasProperty));
			JSExport<Properties>::AddFunctionProperty("listProperties", std::mem_fn(&Properties::js_listProperties));
			JSExport<Properties>::AddFunctionProperty("removeProperty", std::mem_fn(&Properties::js_removeProperty));
			JSExport<Properties>::AddFunctionProperty("setBool", std::mem_fn(&Properties::js_setBool));
			JSExport<Properties>::AddFunctionProperty("setDouble", std::mem_fn(&Properties::js_setDouble));
			JSExport<Properties>::AddFunctionProperty("setInt", std::mem_fn(&Properties::js_setInt));
			JSExport<Properties>::AddFunctionProperty("setList", std::mem_fn(&Properties::js_setList));
			JSExport<Properties>::AddFunctionProperty("setObject", std::mem_fn(&Properties::js_setObject));
			JSExport<Properties>::AddFunctionProperty("setString", std::mem_fn(&Properties::js_setString));
		}

		JSValue Properties::js_getBool(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsString());
				const std::string property = static_cast<std::string>(_0);
				bool defaultValue = false;

				if (arguments.size() >= 2) {
					const auto _1 = arguments.at(1);
					TITANIUM_ASSERT(_1.IsBoolean());
					defaultValue = static_cast<bool>(_1);
				}
				return get_context().CreateBoolean(getBool(property, defaultValue));
			}
			return get_context().CreateUndefined();
		}

		JSValue Properties::js_getDouble(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsString());
				const std::string property = static_cast<std::string>(_0);
				double defaultValue = 0;

				if (arguments.size() >= 2) {
					const auto _1 = arguments.at(1);
					TITANIUM_ASSERT(_1.IsNumber());
					defaultValue = static_cast<double>(_1);
				}
				return get_context().CreateNumber(getDouble(property, defaultValue));
			}
			return get_context().CreateUndefined();
		}

		JSValue Properties::js_getInt(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsString());
				const std::string property = static_cast<std::string>(_0);
				double defaultValue = 0;
				if (arguments.size() >= 2) {
					const auto _1 = arguments.at(1);
					TITANIUM_ASSERT(_1.IsNumber());
					defaultValue = static_cast<double>(_1);
				}
				return get_context().CreateNumber(getInt(property, defaultValue));
			}
			return get_context().CreateUndefined();
		}

		JSValue Properties::js_getList(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsString());
				const std::string property = static_cast<std::string>(_0);
				std::vector<JSValue> defaultValue;
				if (arguments.size() >= 2) {
					const auto _1 = arguments.at(1);
					TITANIUM_ASSERT(_1.IsObject());
					auto object = static_cast<JSObject>(_1);
					TITANIUM_ASSERT(object.IsArray());
					defaultValue = static_cast<JSArray>(object);
				}
				std::vector<JSValue> list = getList(property, defaultValue);
				return get_context().CreateArray(list);
			}

			return get_context().CreateUndefined();
		}

		JSValue Properties::js_getObject(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsString());
				const std::string property = static_cast<std::string>(_0);
				JSObject defaultValue = get_context().CreateObject();
				if (arguments.size() >= 2) {
					const auto _1 = arguments.at(1);
					TITANIUM_ASSERT(_1.IsObject());
					defaultValue = static_cast<JSObject>(_1);
				}
				return getObject(property, defaultValue);
			}

			return get_context().CreateUndefined();
		}

		JSValue Properties::js_getString(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() > 0) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsString());
				const std::string property = static_cast<std::string>(_0);
				std::string defaultValue = "";
				if (arguments.size() > 1) {
					const auto _1 = arguments.at(1);
					TITANIUM_ASSERT(_1.IsString());
					defaultValue = static_cast<std::string>(_1);
				}
				return get_context().CreateString(getString(property, defaultValue));
			}

			return get_context().CreateUndefined();
		}

		JSValue Properties::js_hasProperty(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() < 1) {
				return get_context().CreateUndefined();
			}
			const auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsString());
			return get_context().CreateBoolean(hasProperty(static_cast<std::string>(_0)));
		}

		JSValue Properties::js_listProperties(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			const auto props = listProperties();
			std::vector<JSValue> converted;
			for (size_t i = 0; i < props.size(); i++) {
				converted.push_back(get_context().CreateString(props.at(i)));
			}
			return get_context().CreateArray(converted);
		}

		JSValue Properties::js_removeProperty(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() < 1) {
				return get_context().CreateUndefined();
			}
			const auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsString());
			removeProperty(static_cast<std::string>(_0));
			return get_context().CreateUndefined();
		}

		JSValue Properties::js_setBool(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 2) {
				const auto _0 = arguments.at(0);
				const auto _1 = arguments.at(1);

				TITANIUM_ASSERT(_0.IsString());
				TITANIUM_ASSERT(_1.IsBoolean());

				const std::string property = static_cast<std::string>(_0);
				const bool value = static_cast<bool>(_1);

				setBool(property, value);
			}

			return get_context().CreateUndefined();
		}

		JSValue Properties::js_setDouble(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 2) {
				const auto _0 = arguments.at(0);
				const auto _1 = arguments.at(1);

				TITANIUM_ASSERT(_0.IsString());
				TITANIUM_ASSERT(_1.IsNumber());

				const std::string property = static_cast<std::string>(_0);
				const double value = static_cast<double>(_1);

				setDouble(property, value);
			}

			return get_context().CreateUndefined();
		}

		JSValue Properties::js_setInt(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 2) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsString());
				const std::string property = static_cast<std::string>(_0);
				
				const auto _1 = arguments.at(1);
				TITANIUM_ASSERT(_1.IsNumber());
				const int value = static_cast<int32_t>(_1);

				setInt(property, value);
			}

			return get_context().CreateUndefined();
		}

		JSValue Properties::js_setList(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 2) {

				const auto _0 = arguments.at(0);
				const std::string property = static_cast<std::string>(_0);

				TITANIUM_ASSERT(_0.IsString());
				const auto _1 = arguments.at(1);
				TITANIUM_ASSERT(_1.IsObject());
				auto object = static_cast<JSObject>(_1);
				TITANIUM_ASSERT(object.IsArray());
				auto array = static_cast<JSArray>(object);

				setList(property, array);
			}

			return get_context().CreateUndefined();
		}

		JSValue Properties::js_setObject(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			 if (arguments.size() >= 2) {
				const auto _0 = arguments.at(0);
				const auto _1 = arguments.at(1);

				TITANIUM_ASSERT(_0.IsString());
				TITANIUM_ASSERT(_1.IsObject());

				const std::string property = static_cast<std::string>(_0);
				const auto value = static_cast<JSObject>(_1);

				setObject(property, value);
			}

			return get_context().CreateUndefined();
		}

		JSValue Properties::js_setString(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 2) {
				const auto _0 = arguments.at(0);
				const auto _1 = arguments.at(1);

				TITANIUM_ASSERT(_0.IsString());
				TITANIUM_ASSERT(_1.IsString());

				const std::string property = static_cast<std::string>(_0);
				const std::string value = static_cast<std::string>(_1);

				setString(property, value);
			}

			return get_context().CreateUndefined();
		}
	}
}