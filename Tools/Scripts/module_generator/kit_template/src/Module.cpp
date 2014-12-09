/**
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/{#Name#}.hpp"
#include <unordered_map>
#include <sstream>

namespace Titanium {

	{#Name#}::{#Name#}(const JSContext& js_context) TITANIUM_NOEXCEPT : Module(js_context) {
	}

	{#Name#}::{#Name#}(const {#Name#}& rhs, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT : Module(rhs, arguments) {
	}

{#KIT_PROPERTIES#}
{#KIT_METHODS#}
{#KIT_PROPERTY_VALIDATORS#}
{#KIT_VALIDATORS#}

	void {#Name#}::JSExportInitialize() {
		JSExport<{#Name#}>::SetClassVersion(1);
		JSExport<{#Name#}>::SetParent(JSExport<Module>::Class());

{#ADD_PROPERTIES#}
{#ADD_FUNCTIONS#}
		
		JSExport<{#Name#}>::AddValueProperty("osname", std::mem_fn(&{#Name#}::get_osname_ArgumentValidator));
		JSExport<{#Name#}>::AddFunctionProperty("openURL", std::mem_fn(&{#Name#}::openURLValidator));
	}

} // namespace Titanium
