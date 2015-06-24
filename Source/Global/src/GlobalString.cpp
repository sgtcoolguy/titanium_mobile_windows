/**
 * Global.String for Windows
 *
 * Copyright (c) 2014-2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/GlobalString.hpp"
#include "Titanium/detail/TiLogger.hpp"

namespace TitaniumWindows
{

	GlobalString::GlobalString(const JSContext& js_context) TITANIUM_NOEXCEPT
	    : Titanium::GlobalString(js_context)
	{
		TITANIUM_LOG_DEBUG("GlobalString::ctor");
	}

	void GlobalString::JSExportInitialize()
	{
		JSExport<GlobalString>::SetClassVersion(1);
		JSExport<GlobalString>::SetParent(JSExport<Titanium::GlobalString>::Class());
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

}  // namespace TitaniumWindows
