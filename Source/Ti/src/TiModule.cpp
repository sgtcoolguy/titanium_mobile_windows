/**
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/TiModule.hpp"
#include "Titanium/detail/TiBase.hpp"
#include <iostream>
#include <objbase.h>

namespace TitaniumWindows
{
	TiModule::TiModule(const JSContext& js_context) TITANIUM_NOEXCEPT
	    : Titanium::TiModule(js_context)
	{
		TITANIUM_LOG_DEBUG("TitaniumWindows::TiModule::ctor");
		setUserAgent("__TITANIUM_USER_AGENT__");
	}

	TiModule::~TiModule()
	{
		TITANIUM_LOG_DEBUG("TitaniumWindows::TiModule::dtor");
	}

	void TiModule::JSExportInitialize()
	{
		JSExport<TiModule>::SetClassVersion(1);
		JSExport<TiModule>::SetParent(JSExport<Titanium::TiModule>::Class());
	}

	std::string TiModule::version() const TITANIUM_NOEXCEPT
	{
		return "__TITANIUM_VERSION__";
	}

	std::string TiModule::buildDate() const TITANIUM_NOEXCEPT
	{
		return "6/22/2015 15:18";
	}

	std::string TiModule::buildHash() const TITANIUM_NOEXCEPT
	{
		return "aac7571";
	}

}  // namespace TitaniumWindows
