/**
 * Titanium.{#Module#} for Windows
 * Author: {#Author#}
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/{#Module#}.hpp"
#include "Titanium/detail/TiBase.hpp"

namespace TitaniumWindows {

	{#ModuleName#}::{#ModuleName#}(const JSContext& js_context) TITANIUM_NOEXCEPT : Titanium::{#ModuleName#}(js_context) {
		TITANIUM_LOG_DEBUG("{#Module#}::ctor Initialize");
	}

	{#ModuleName#}::{#ModuleName#}(const {#ModuleName#}& rhs, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT : Titanium::{#ModuleName#}(rhs, arguments) {
		TITANIUM_LOG_DEBUG("{#Module#}::ctor CallAsConstructor");
	}

{#MODULE_PROPERTIES#}
{#MODULE_METHODS#}

	void {#ModuleName#}::JSExportInitialize() {
		JSExport<{#ModuleName#}>::SetClassVersion(1);
		JSExport<{#ModuleName#}>::SetParent(JSExport<Titanium::{#ModuleName#}>::Class());
	}

}  // namespace TitaniumWindows
