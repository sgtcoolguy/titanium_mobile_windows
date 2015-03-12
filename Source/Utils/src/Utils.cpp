/**
 * Titanium.Utils for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/Utils.hpp"
#include "Titanium/detail/TiBase.hpp"

namespace TitaniumWindows
{

		UtilsModule::UtilsModule(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::UtilsModule(js_context)
		{
			TITANIUM_LOG_DEBUG("Utils::ctor Initialize");
		}

		void UtilsModule::JSExportInitialize() {
			JSExport<UtilsModule>::SetClassVersion(1);
			JSExport<UtilsModule>::SetParent(JSExport<Titanium::UtilsModule>::Class());
		}

		JSValue UtilsModule::base64decode(JSValue obj) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Utils.base64decode is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue UtilsModule::base64encode(JSValue obj) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Utils.base64encode is not implemented yet");
			return get_context().CreateUndefined();
		}

		std::string UtilsModule::md5HexDigest(JSValue obj) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Utils.md5HexDigest is not implemented yet");
			return "";
		}

		std::string UtilsModule::sha1(JSValue obj) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Utils.sha1 is not implemented yet");
			return "";
		}

		std::string UtilsModule::sha256(JSValue obj) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Utils.sha256 is not implemented yet");
			return "";
		}

}  // namespace TitaniumWindows