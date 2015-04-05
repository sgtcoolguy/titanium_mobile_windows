/**
 * TitaniumKit
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/Label.hpp"

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

		std::string Label::get_text() const TITANIUM_NOEXCEPT
		{
			return text__;
		}

		void Label::set_text(const std::string& text) TITANIUM_NOEXCEPT
		{
			text__ = text;
		}

		TEXT_ALIGNMENT Label::get_textAlign() const TITANIUM_NOEXCEPT
		{
			return textAlign__;
		}

		void Label::set_textAlign(const TEXT_ALIGNMENT& textAlign) TITANIUM_NOEXCEPT
		{
			textAlign__ = textAlign;
		}

		TEXT_VERTICAL_ALIGNMENT Label::get_verticalAlign() const TITANIUM_NOEXCEPT
		{
			return verticalAlign__;
		}

		void Label::set_verticalAlign(const TEXT_VERTICAL_ALIGNMENT& verticalAlign) TITANIUM_NOEXCEPT
		{
			verticalAlign__ = verticalAlign;
		}

		bool Label::get_wordWrap() const TITANIUM_NOEXCEPT
		{
			return wordWrap__;
		}

		void Label::set_wordWrap(const bool& wordWrap) TITANIUM_NOEXCEPT
		{
			wordWrap__ = wordWrap;
		}

		std::string Label::get_color() const TITANIUM_NOEXCEPT
		{
			return color__;
		}

		void Label::set_color(const std::string& color) TITANIUM_NOEXCEPT
		{
			color__ = color;
		}

		bool Label::get_ellipsize() const TITANIUM_NOEXCEPT
		{
			return ellipsize__;
		}

		void Label::set_ellipsize(const bool& ellipsize) TITANIUM_NOEXCEPT
		{
			ellipsize__ = ellipsize;
		}

		Font Label::get_font() const TITANIUM_NOEXCEPT
		{
			return font__;
		}

		void Label::set_font(const Font font) TITANIUM_NOEXCEPT
		{
			font__ = font;
		}

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

		TITANIUM_FUNCTION(Label, getColor)
		{
			return js_get_color();
		}

		TITANIUM_FUNCTION(Label, setColor)
		{
			if (arguments.size() >= 1) {
				js_set_color(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

	TITANIUM_FUNCTION(Label, getEllipsize)
		{
			return js_get_ellipsize();
		}

		TITANIUM_FUNCTION(Label, setEllipsize)
		{
			if (arguments.size() >= 1) {
				js_set_ellipsize(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Label, getFont)
		{
			return js_get_font();
		}

		TITANIUM_FUNCTION(Label, setFont)
		{
			if (arguments.size() >= 1) {
				js_set_font(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Label, getText)
		{
			return js_get_text();
		}

		TITANIUM_FUNCTION(Label, setText)
		{
			if (arguments.size() >= 1) {
				js_set_text(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Label, getTextAlign)
		{
			return js_get_textAlign();
		}

		TITANIUM_FUNCTION(Label, setTextAlign)
		{
			if (arguments.size() >= 1) {
				js_set_textAlign(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Label, getVerticalAlign)
		{
			return js_get_verticalAlign();
		}

		TITANIUM_FUNCTION(Label, setVerticalAlign)
		{
			if (arguments.size() >= 1) {
				js_set_verticalAlign(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Label, getWordWrap)
		{
			return js_get_wordWrap();
		}

		TITANIUM_FUNCTION(Label, setWordWrap)
		{
			if (arguments.size() >= 1) {
				js_set_wordWrap(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}
	} // namespace UI
}  // namespace Titanium
