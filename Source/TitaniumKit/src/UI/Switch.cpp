/**
 * TitaniumKit Titanium.UI.Switch
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/Switch.hpp"

namespace Titanium
{
	namespace UI
	{
		Switch::Switch(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
			: View(js_context),
			value__(false)
		{
		}

		bool Switch::get_value() const TITANIUM_NOEXCEPT
		{
			return value__;
		}

		void Switch::set_value(const bool& value) TITANIUM_NOEXCEPT
		{
			value__ = value;
		}

		void Switch::JSExportInitialize() {
			JSExport<Switch>::SetClassVersion(1);
			JSExport<Switch>::SetParent(JSExport<Module>::Class());

			TITANIUM_ADD_PROPERTY(Switch, value);
			TITANIUM_ADD_FUNCTION(Switch, getValue);
			TITANIUM_ADD_FUNCTION(Switch, setValue);
		}

		TITANIUM_PROPERTY_GETTER(Switch, value)
		{
			return get_context().CreateBoolean(get_value());
		}

		TITANIUM_PROPERTY_SETTER(Switch, value)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_value(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_FUNCTION(Switch, getValue)
		{
			return js_get_value();
		}

		TITANIUM_FUNCTION(Switch, setValue)
		{
			TITANIUM_ASSERT(arguments.size() >= 1);
			js_set_value(arguments.at(0));
			return get_context().CreateUndefined();
		}
	} // namespace UI
} // namespace Titanium