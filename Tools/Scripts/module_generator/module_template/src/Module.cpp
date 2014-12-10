/**
 * Titanium.{#Name#} for Windows
 * Author: {#Author#}
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/{#Name#}.hpp"
#include "Titanium/detail/TiBase.hpp"

namespace TitaniumWindows {

	{#Name#}::{#Name#}(const JSContext& js_context) TITANIUM_NOEXCEPT : Titanium::{#Name#}(js_context)
	{
		TITANIUM_LOG_DEBUG("{#Name#}::ctor Initialize");
	}

	{#Name#}::{#Name#}(const {#Name#}& rhs, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT : Titanium::{#Name#}(rhs, arguments)
	{
		TITANIUM_LOG_DEBUG("{#Name#}::ctor CallAsConstructor");
	}

{#MODULE_PROPERTIES#}
{#MODULE_METHODS#}

	void {#Name#}::JSExportInitialize() {
		JSExport<{#Name#}>::SetClassVersion(1);
		JSExport<{#Name#}>::SetParent(JSExport<Titanium::{#Name#}>::Class());
	}

}  // namespace TitaniumWindows
