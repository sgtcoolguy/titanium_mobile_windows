/**
 * Titanium.{#SubClass#} for Windows
 * Author: Gary Mathews
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/{#SubClass#}.hpp"
#include "Titanium/detail/TiBase.hpp"

namespace TitaniumWindows { namespace {#Module#} {

	{#SubClass#}::{#SubClass#}(const JSContext& js_context) TITANIUM_NOEXCEPT : Titanium::{#Module#}::{#SubClass#}(js_context) {
		TITANIUM_LOG_DEBUG("{#SubClass#}::ctor Initialize");
	}

	{#SubClass#}::{#SubClass#}(const {#SubClass#}& rhs, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT : Titanium::{#Module#}::{#SubClass#}(rhs, arguments) {
		TITANIUM_LOG_DEBUG("{#SubClass#}::ctor CallAsConstructor");
	}
	
{#MODULE_PROPERTIES#}
{#MODULE_METHODS#}
	void {#SubClass#}::JSExportInitialize() {
		JSExport<{#SubClass#}>::SetClassVersion(1);
		JSExport<{#SubClass#}>::SetParent(JSExport<Titanium::{#Module#}::{#SubClass#}>::Class());
	}

}} // namespace Titanium, namespace {#SubClass#}