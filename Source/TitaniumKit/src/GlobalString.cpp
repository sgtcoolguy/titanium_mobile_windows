/**
 * TitaniumKit
 *
 * Copyright (c) 2014-2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/GlobalString.hpp"
#include "Titanium/Global/sprintf_js.hpp"

namespace Titanium
{
	GlobalString::GlobalString(const JSContext& js_context) TITANIUM_NOEXCEPT
		: JSExportObject(js_context)
	{
		TITANIUM_LOG_DEBUG("GlobalString:: ctor ", this);
	}

	void GlobalString::postInitialize(JSObject& this_object) 
	{
		HAL_LOG_DEBUG("GlobalString:: postInitialize ", this);

		const auto ctx = this_object.get_context();

		// Create cross-platform String.format
		auto stringObject = static_cast<JSObject>(ctx.get_global_object().GetProperty("String"));
		auto formatObject = ctx.CreateObject();
		ctx.JSEvaluateScript(sprintf_js, formatObject);
		stringObject.SetProperty("format", ctx.JSEvaluateScript("sprintf;", formatObject));
	}

	GlobalString::~GlobalString() TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_DEBUG("GlobalString:: dtor ", this);
	}

	std::string GlobalString::formatCurrency(double value) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_ERROR("GlobalString::formatCurrency: Unimplemented");
		return std::to_string(value);
	}

	std::string GlobalString::formatDate(JSObject date, std::string format) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_ERROR("GlobalString::formatDate: Unimplemented");
		return static_cast<std::string>(static_cast<JSValue>(date));
	}

	std::string GlobalString::formatDecimal(double value, std::string locale, std::string pattern) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_ERROR("GlobalString::formatDecimal: Unimplemented");
		return std::to_string(value);
	}

	std::string GlobalString::formatTime(JSObject date, std::string format) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_ERROR("GlobalString::formatTime: Unimplemented");
		return static_cast<std::string>(static_cast<JSValue>(date));
	}

	void GlobalString::JSExportInitialize()
	{
		TITANIUM_LOG_DEBUG("GlobalString::JSExportInitialize");
		JSExport<GlobalString>::SetClassVersion(1);
		JSExport<GlobalString>::SetParent(JSExport<JSExportObject>::Class());
		
		TITANIUM_ADD_FUNCTION(GlobalString, formatCurrency);
		TITANIUM_ADD_FUNCTION(GlobalString, formatDate);
		TITANIUM_ADD_FUNCTION(GlobalString, formatDecimal);
		TITANIUM_ADD_FUNCTION(GlobalString, formatTime);
	}

	TITANIUM_FUNCTION(GlobalString, formatCurrency) 
	{
		ENSURE_DOUBLE_AT_INDEX(value, 0);

		return this_object.get_context().CreateString(formatCurrency(value));
	}

	TITANIUM_FUNCTION(GlobalString, formatDate) 
	{
		ENSURE_OBJECT_AT_INDEX(date, 0);
		ENSURE_OPTIONAL_STRING_AT_INDEX(format, 1, "");

		return this_object.get_context().CreateString(formatDate(date, format));
	}

	TITANIUM_FUNCTION(GlobalString, formatDecimal) 
	{
		ENSURE_DOUBLE_AT_INDEX(value, 0);
		ENSURE_OPTIONAL_STRING_AT_INDEX(locale, 1, "");
		ENSURE_OPTIONAL_STRING_AT_INDEX(pattern, 2, "");

		return this_object.get_context().CreateString(formatDecimal(value, locale, pattern));
	}

	TITANIUM_FUNCTION(GlobalString, formatTime) 
	{
		ENSURE_OBJECT_AT_INDEX(date, 0);
		ENSURE_OPTIONAL_STRING_AT_INDEX(format, 1, "");

		return this_object.get_context().CreateString(formatTime(date, format));
	}

}  // namespace Titanium
