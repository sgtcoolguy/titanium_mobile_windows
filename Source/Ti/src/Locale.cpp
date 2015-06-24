/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/Locale.hpp"
#include "Titanium/detail/TiLogger.hpp"
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

	std::string Locale::getString(const std::string& key, const std::string& hint) TITANIUM_NOEXCEPT
	{
		try {
			const auto loader = Windows::ApplicationModel::Resources::ResourceLoader::GetForCurrentView();
			const auto value = loader->GetString(TitaniumWindows::Utility::ConvertUTF8String(key));
			if (value) {
				return TitaniumWindows::Utility::ConvertUTF8String(value);
			}
		} catch (...) {
			TITANIUM_LOG_ERROR("Error during Locale::getString");
		}
		return hint.empty() ? key : hint;
	}

	void Locale::JSExportInitialize()
	{
		JSExport<Locale>::SetClassVersion(1);
		JSExport<Locale>::SetParent(JSExport<Titanium::Locale>::Class());
	}

}  // namespace TitaniumWindows
