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

			JSExport<Switch>::AddValueProperty("value", std::mem_fn(&Switch::js_get_value), std::mem_fn(&Switch::js_set_value));

			JSExport<Switch>::AddFunctionProperty("getValue", std::mem_fn(&Switch::js_getValue));
			JSExport<Switch>::AddFunctionProperty("setValue", std::mem_fn(&Switch::js_setValue));
		}

		JSValue Switch::js_get_value() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(get_value());
		}

		bool Switch::js_set_value(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_value(static_cast<bool>(argument));
			return true;
		}

		JSValue Switch::js_getValue(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_value();
		}

		JSValue Switch::js_setValue(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() >= 1);
			js_set_value(arguments.at(0));
			return get_context().CreateUndefined();
		}
	} // namespace UI
} // namespace Titanium