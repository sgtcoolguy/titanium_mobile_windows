/**
 * {#SubClass#}
 * Author: {#Author#}
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/{#Module#}/{#SubClass#}.hpp"

namespace Titanium { namespace {#Module#} {
	
	{#SubClass#}::{#SubClass#}(const JSContext& js_context) TITANIUM_NOEXCEPT : Module(js_context) {
	}
	
	{#SubClass#}::{#SubClass#}(const {#SubClass#}& rhs, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT : Module(rhs, arguments) {
	}
	
{#KIT_PROPERTIES#}
{#KIT_METHODS#}
{#KIT_PROPERTY_VALIDATORS#}
{#KIT_VALIDATORS#}
	
	void {#SubClass#}::JSExportInitialize() {
		JSExport<{#SubClass#}>::SetClassVersion(1);
		JSExport<{#SubClass#}>::SetParent(JSExport<Module>::Class());
		
{#ADD_PROPERTIES#}
{#ADD_FUNCTIONS#}
	}
	
}} // namespace Titanium, namespace {#SubClass#}
