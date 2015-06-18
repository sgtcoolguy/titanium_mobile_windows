/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/Locale.hpp"
#include "Titanium/detail/TiBase.hpp"
#include "TitaniumWindows/Utility.hpp"

namespace TitaniumWindows
{
	Locale::Locale(const JSContext& js_context) TITANIUM_NOEXCEPT
		: Titanium::Locale(js_context)
	{
		TITANIUM_LOG_DEBUG("TitaniumWindows::Locale::ctor");
	}

	Locale::~Locale()
	{
		TITANIUM_LOG_DEBUG("TitaniumWindows::Locale::dtor");
	}

	void Locale::JSExportInitialize()
	{
		JSExport<Locale>::SetClassVersion(1);
		JSExport<Locale>::SetParent(JSExport<Titanium::Locale>::Class());
	}

}  // namespace TitaniumWindows
