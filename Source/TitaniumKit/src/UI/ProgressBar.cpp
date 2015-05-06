/**
 * TitaniumKit Titanium.UI.ProgressBar
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/ProgressBar.hpp"

namespace Titanium
{
	namespace UI
	{


		ProgressBar::ProgressBar(const JSContext& js_context) TITANIUM_NOEXCEPT
			: View(js_context),
			color__(""),
			max__(0),
			message__(""),
			min__(0),
			value__(0)
		{
		}

		TITANIUM_PROPERTY_READWRITE(ProgressBar, std::string, color)
		TITANIUM_PROPERTY_READWRITE(ProgressBar, Font, font)
		TITANIUM_PROPERTY_READWRITE(ProgressBar, double, max)
		TITANIUM_PROPERTY_READWRITE(ProgressBar, std::string, message)
		TITANIUM_PROPERTY_READWRITE(ProgressBar, double, min)
		TITANIUM_PROPERTY_READWRITE(ProgressBar, double, value)

		void ProgressBar::remove(const std::shared_ptr<View>& view) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_DEBUG("ProgressBar::add");
		}

		void ProgressBar::add(const std::shared_ptr<View>& view) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_DEBUG("ProgressBar::remove");
		}

		void ProgressBar::JSExportInitialize() 
		{
			JSExport<ProgressBar>::SetClassVersion(1);
			JSExport<ProgressBar>::SetParent(JSExport<View>::Class());

			TITANIUM_ADD_PROPERTY(ProgressBar, color);
			TITANIUM_ADD_PROPERTY(ProgressBar, font);
			TITANIUM_ADD_PROPERTY(ProgressBar, max);
			TITANIUM_ADD_PROPERTY(ProgressBar, message);
			TITANIUM_ADD_PROPERTY(ProgressBar, min);
			TITANIUM_ADD_PROPERTY(ProgressBar, style);
			TITANIUM_ADD_PROPERTY(ProgressBar, value);

			TITANIUM_ADD_FUNCTION(ProgressBar, remove);
			TITANIUM_ADD_FUNCTION(ProgressBar, add);
			TITANIUM_ADD_FUNCTION(ProgressBar, getColor);
			TITANIUM_ADD_FUNCTION(ProgressBar, setColor);
			TITANIUM_ADD_FUNCTION(ProgressBar, getFont);
			TITANIUM_ADD_FUNCTION(ProgressBar, setFont);
			TITANIUM_ADD_FUNCTION(ProgressBar, getMax);
			TITANIUM_ADD_FUNCTION(ProgressBar, setMax);
			TITANIUM_ADD_FUNCTION(ProgressBar, getMessage);
			TITANIUM_ADD_FUNCTION(ProgressBar, setMessage);
			TITANIUM_ADD_FUNCTION(ProgressBar, getMin);
			TITANIUM_ADD_FUNCTION(ProgressBar, setMin);
			TITANIUM_ADD_FUNCTION(ProgressBar, getStyle);
			TITANIUM_ADD_FUNCTION(ProgressBar, setStyle);
			TITANIUM_ADD_FUNCTION(ProgressBar, getValue);
			TITANIUM_ADD_FUNCTION(ProgressBar, setValue);
		}

		TITANIUM_PROPERTY_GETTER(ProgressBar, color)
		{
			return get_context().CreateString(get_color());
		}

		TITANIUM_PROPERTY_SETTER(ProgressBar, color)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_color(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ProgressBar, font)
		{
			return Font_to_js(get_context(), get_font());
		}

		TITANIUM_PROPERTY_SETTER(ProgressBar, font)
		{
			TITANIUM_ASSERT(argument.IsObject());
			set_font(js_to_Font(static_cast<JSObject>(argument)));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ProgressBar, max)
		{
			return get_context().CreateNumber(get_max());
		}

		TITANIUM_PROPERTY_SETTER(ProgressBar, max)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_max(static_cast<double>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ProgressBar, message)
		{
			return get_context().CreateString(get_message());
		}

		TITANIUM_PROPERTY_SETTER(ProgressBar, message)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_message(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ProgressBar, min)
		{
			return get_context().CreateNumber(get_min());
		}

		TITANIUM_PROPERTY_SETTER(ProgressBar, min)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_min(static_cast<double>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ProgressBar, style)
		{
			TITANIUM_LOG_WARN("ProgressBar::style: getter unimplemented");
			return get_context().CreateUndefined();
		}

		TITANIUM_PROPERTY_SETTER(ProgressBar, style)
		{
			TITANIUM_LOG_WARN("ProgressBar::style: setter unimplemented");
			return false;
		}

		TITANIUM_PROPERTY_GETTER(ProgressBar, value)
		{
			return get_context().CreateNumber(get_value());
		}

		TITANIUM_PROPERTY_SETTER(ProgressBar, value)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_value(static_cast<double>(argument));
			return true;
		}

		TITANIUM_FUNCTION(ProgressBar, remove)
		{
			ENSURE_OBJECT_AT_INDEX(view, 0);
			remove(view.GetPrivate<View>());
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ProgressBar, add)
		{
			ENSURE_OBJECT_AT_INDEX(view, 0);
			add(view.GetPrivate<View>());
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION_AS_GETTER(ProgressBar, getColor, color)
		TITANIUM_FUNCTION_AS_SETTER(ProgressBar, setColor, color)
		TITANIUM_FUNCTION_AS_GETTER(ProgressBar, getFont, font)
		TITANIUM_FUNCTION_AS_SETTER(ProgressBar, setFont, font)
		TITANIUM_FUNCTION_AS_GETTER(ProgressBar, getMax, max)
		TITANIUM_FUNCTION_AS_SETTER(ProgressBar, setMax, max)
		TITANIUM_FUNCTION_AS_GETTER(ProgressBar, getMessage, message)
		TITANIUM_FUNCTION_AS_SETTER(ProgressBar, setMessage, message)
		TITANIUM_FUNCTION_AS_GETTER(ProgressBar, getMin, min)
		TITANIUM_FUNCTION_AS_SETTER(ProgressBar, setMin, min)
		TITANIUM_FUNCTION_AS_GETTER(ProgressBar, getStyle, style)
		TITANIUM_FUNCTION_AS_SETTER(ProgressBar, setStyle, style)
		TITANIUM_FUNCTION_AS_GETTER(ProgressBar, getValue, value)
		TITANIUM_FUNCTION_AS_SETTER(ProgressBar, setValue, value)

	} // namespace UI
} // namespace Titanium