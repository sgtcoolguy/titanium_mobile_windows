/**
 * TitaniumKit
 *
 * Copyright (c) 2014-2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/Label.hpp"
#include "Titanium/detail/TiImpl.hpp"

namespace Titanium
{
	namespace UI
	{
		Label::Label(const JSContext& js_context) TITANIUM_NOEXCEPT
		    : View(js_context),
		      color__(js_context.CreateString()),
		      ellipsize__(false),
		      text__(js_context.CreateString()),
		      textAlign__(TEXT_ALIGNMENT::LEFT),
		      verticalAlign__(TEXT_VERTICAL_ALIGNMENT::CENTER),
		      wordWrap__(js_context.CreateBoolean(true))
		{
		}

		TITANIUM_PROPERTY_READWRITE(Label, std::string, text)

		TITANIUM_PROPERTY_READWRITE(Label, TEXT_ALIGNMENT, textAlign)

		TITANIUM_PROPERTY_READWRITE(Label, TEXT_VERTICAL_ALIGNMENT, verticalAlign)

		TITANIUM_PROPERTY_READWRITE(Label, bool, wordWrap)

		TITANIUM_PROPERTY_READWRITE(Label, std::string, color)

		TITANIUM_PROPERTY_READWRITE(Label, bool, ellipsize)

		TITANIUM_PROPERTY_READWRITE(Label, Font, font)

		void Label::JSExportInitialize()
		{
			JSExport<Label>::SetClassVersion(1);
			JSExport<Label>::SetParent(JSExport<View>::Class());
			TITANIUM_ADD_PROPERTY(Label, color);
			TITANIUM_ADD_PROPERTY(Label, ellipsize);
			TITANIUM_ADD_PROPERTY(Label, font);
			TITANIUM_ADD_PROPERTY(Label, text);
			TITANIUM_ADD_PROPERTY(Label, textAlign);
			TITANIUM_ADD_PROPERTY(Label, verticalAlign);
			TITANIUM_ADD_PROPERTY(Label, wordWrap);

			TITANIUM_ADD_FUNCTION(Label, getColor);
			TITANIUM_ADD_FUNCTION(Label, setColor);
			TITANIUM_ADD_FUNCTION(Label, getEllipsize);
			TITANIUM_ADD_FUNCTION(Label, setEllipsize);
			TITANIUM_ADD_FUNCTION(Label, getFont);
			TITANIUM_ADD_FUNCTION(Label, setFont);
			TITANIUM_ADD_FUNCTION(Label, getText);
			TITANIUM_ADD_FUNCTION(Label, setText);
			TITANIUM_ADD_FUNCTION(Label, getTextAlign);
			TITANIUM_ADD_FUNCTION(Label, setTextAlign);
			TITANIUM_ADD_FUNCTION(Label, getVerticalAlign);
			TITANIUM_ADD_FUNCTION(Label, setVerticalAlign);
			TITANIUM_ADD_FUNCTION(Label, getWordWrap);
			TITANIUM_ADD_FUNCTION(Label, setWordWrap);
		}

		TITANIUM_PROPERTY_GETTER(Label, color)
		{
			return get_context().CreateString(get_color());
		}

		TITANIUM_PROPERTY_SETTER(Label, color)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_color(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Label, ellipsize)
		{
			return get_context().CreateBoolean(get_ellipsize());
		}

		TITANIUM_PROPERTY_SETTER(Label, ellipsize)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_ellipsize(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Label, font)
		{
			JSObject font = Titanium::UI::Font_to_js(get_context(), get_font());
			return static_cast<JSValue>(font);
		}

		TITANIUM_PROPERTY_SETTER(Label, font)
		{
			TITANIUM_ASSERT(argument.IsObject());
			set_font(Titanium::UI::js_to_Font(static_cast<JSObject>(argument)));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Label, text)
		{
			return get_context().CreateString(text__);
		}

		TITANIUM_PROPERTY_SETTER(Label, text)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_text(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Label, textAlign)
		{
			return get_context().CreateNumber(static_cast<std::underlying_type<TEXT_ALIGNMENT>::type>(get_textAlign()));
		}

		TITANIUM_PROPERTY_SETTER(Label, textAlign)
		{
			bool result = false;
			if (argument.IsNumber()) {
				set_textAlign(Constants::to_TEXT_ALIGNMENT(static_cast<std::underlying_type<TEXT_ALIGNMENT>::type>(argument)));
				result = true;
			} else if (argument.IsString()) {
				set_textAlign(Constants::to_TEXT_ALIGNMENT(static_cast<std::string>(argument)));
				result = true;
			}

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Label, verticalAlign)
		{
			return get_context().CreateNumber(static_cast<std::underlying_type<TEXT_VERTICAL_ALIGNMENT>::type>(get_verticalAlign()));
		}

		TITANIUM_PROPERTY_SETTER(Label, verticalAlign)
		{
			bool result = false;
			if (argument.IsNumber()) {
				set_verticalAlign(Constants::to_TEXT_VERTICAL_ALIGNMENT(static_cast<std::underlying_type<TEXT_VERTICAL_ALIGNMENT>::type>(argument)));
				result = true;
			} else if (argument.IsString()) {
				set_verticalAlign(Constants::to_TEXT_VERTICAL_ALIGNMENT(static_cast<std::string>(argument)));
				result = true;
			}

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Label, wordWrap)
		{
			return get_context().CreateBoolean(wordWrap__);
		}

		TITANIUM_PROPERTY_SETTER(Label, wordWrap)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_wordWrap(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_FUNCTION_AS_GETTER(Label, getColor, color)
		TITANIUM_FUNCTION_AS_SETTER(Label, setColor, color)

		TITANIUM_FUNCTION_AS_GETTER(Label, getEllipsize, ellipsize)
		TITANIUM_FUNCTION_AS_SETTER(Label, setEllipsize, ellipsize)
		
		TITANIUM_FUNCTION_AS_GETTER(Label, getFont, font)
		TITANIUM_FUNCTION_AS_SETTER(Label, setFont, font)

		TITANIUM_FUNCTION_AS_GETTER(Label, getText, text)
		TITANIUM_FUNCTION_AS_SETTER(Label, setText, text)

		TITANIUM_FUNCTION_AS_GETTER(Label, getTextAlign, textAlign)
		TITANIUM_FUNCTION_AS_SETTER(Label, setTextAlign, textAlign)
		
		TITANIUM_FUNCTION_AS_GETTER(Label, getVerticalAlign, verticalAlign)
		TITANIUM_FUNCTION_AS_SETTER(Label, setVerticalAlign, verticalAlign)

		TITANIUM_FUNCTION_AS_GETTER(Label, getWordWrap, wordWrap)
		TITANIUM_FUNCTION_AS_SETTER(Label, setWordWrap, wordWrap)
	} // namespace UI
}  // namespace Titanium
