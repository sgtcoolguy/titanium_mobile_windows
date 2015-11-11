/**
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/TiModule.hpp"
#include "Titanium/detail/TiImpl.hpp"
#include "Titanium/Buffer.hpp"
#include <unordered_map>
#include <sstream>

namespace Titanium
{
	TiModule::TiModule(const JSContext& js_context) TITANIUM_NOEXCEPT
	    : Module(js_context, "Titanium"),
	      userAgent__(js_context.CreateString())
	{
		TITANIUM_LOG_DEBUG("TiModule:: ctor ", this);
	}

	void TiModule::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) 
	{
		HAL_LOG_DEBUG("TiModule:: postCallAsConstructor ", this);
	}

	void TiModule::JSExportInitialize()
	{
		JSExport<TiModule>::SetClassVersion(1);
		JSExport<TiModule>::SetParent(JSExport<Module>::Class());
		TITANIUM_ADD_PROPERTY_READONLY(TiModule, version);
		TITANIUM_ADD_PROPERTY_READONLY(TiModule, buildDate);
		TITANIUM_ADD_PROPERTY_READONLY(TiModule, buildHash);
		TITANIUM_ADD_PROPERTY(TiModule, userAgent);
		TITANIUM_ADD_FUNCTION(TiModule, getVersion);
		TITANIUM_ADD_FUNCTION(TiModule, getBuildDate);
		TITANIUM_ADD_FUNCTION(TiModule, getBuildHash);
		TITANIUM_ADD_FUNCTION(TiModule, getUserAgent);
		TITANIUM_ADD_FUNCTION(TiModule, setUserAgent);
		TITANIUM_ADD_FUNCTION(TiModule, createBuffer);
	}

	JSObject TiModule::GetStaticObject(const JSContext& js_context) TITANIUM_NOEXCEPT
	{
		JSValue Titanium_property = js_context.get_global_object().GetProperty("Titanium");
		TITANIUM_ASSERT(Titanium_property.IsObject());  // precondition
		return static_cast<JSObject>(Titanium_property);
	}

	std::string TiModule::version() const TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("TiModule::version: Unimplemented");
		return "";
	}

	TITANIUM_PROPERTY_GETTER(TiModule, version)
	{
		return get_context().CreateString(version());
	}

	TITANIUM_FUNCTION(TiModule, getVersion)
	{
		const auto js_context = this_object.get_context();
		const auto object_ptr = GetStaticObject(js_context).GetPrivate<TiModule>();
		return object_ptr->js_get_version();
	}

	std::string TiModule::buildDate() const TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("TiModule::buildDate: Unimplemented");
		return "";
	}

	TITANIUM_PROPERTY_GETTER(TiModule, buildDate)
	{
		return get_context().CreateString(buildDate());
	}

	TITANIUM_FUNCTION(TiModule, getBuildDate)
	{
		const auto js_context = this_object.get_context();
		const auto object_ptr = GetStaticObject(js_context).GetPrivate<TiModule>();
		return object_ptr->js_get_buildDate();
	}

	std::string TiModule::buildHash() const TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("TiModule::buildHash: Unimplemented");
		return "";
	}

	TITANIUM_PROPERTY_GETTER(TiModule, buildHash)
	{
		return get_context().CreateString(buildHash());
	}

	TITANIUM_FUNCTION(TiModule, getBuildHash)
	{
		const auto js_context = this_object.get_context();
		const auto object_ptr = GetStaticObject(js_context).GetPrivate<TiModule>();
		return object_ptr->js_get_buildHash();
	}

	TITANIUM_PROPERTY_GETTER(TiModule, userAgent)
	{
		return get_context().CreateString(userAgent__);
	}

	TITANIUM_FUNCTION(TiModule, getUserAgent)
	{
		const auto js_context = this_object.get_context();
		const auto object_ptr = GetStaticObject(js_context).GetPrivate<TiModule>();
		return object_ptr->js_get_userAgent();
	}

	TITANIUM_FUNCTION(TiModule, setUserAgent)
	{
		const auto js_context = this_object.get_context();
		const auto object_ptr = GetStaticObject(js_context).GetPrivate<TiModule>();
		
		object_ptr->js_set_userAgent(arguments.at(0));

		return get_context().CreateUndefined();
	}

	void TiModule::setUserAgent(const std::string& userAgent) TITANIUM_NOEXCEPT
	{
		userAgent__ = userAgent;
	}

	TITANIUM_PROPERTY_SETTER(TiModule, userAgent)
	{
		setUserAgent(static_cast<std::string>(argument));
		return true;
	}

	TITANIUM_FUNCTION(TiModule, createBuffer)
	{
		ENSURE_OPTIONAL_OBJECT_AT_INDEX(parameters, 0);

		JSValue Titanium_property = this_object.get_context().get_global_object().GetProperty("Titanium");
		TITANIUM_ASSERT(Titanium_property.IsObject());
		JSObject Titanium = static_cast<JSObject>(Titanium_property);
		JSValue Buffer_property = Titanium.GetProperty("Buffer");
		TITANIUM_ASSERT(Buffer_property.IsObject());
		JSObject Buffer = static_cast<JSObject>(Buffer_property);
		auto Buffer_obj = Buffer.CallAsConstructor(parameters);
		Titanium::Module::applyProperties(parameters, Buffer_obj);

		return Buffer_obj;
	}

}  // namespace Titanium
