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
			JSExport<Label>::AddValueProperty("color", std::mem_fn(&Label::js_get_color), std::mem_fn(&Label::js_set_color));
			JSExport<Label>::AddValueProperty("ellipsize", std::mem_fn(&Label::js_get_ellipsize), std::mem_fn(&Label::js_set_ellipsize));
			JSExport<Label>::AddValueProperty("font", std::mem_fn(&Label::js_get_font), std::mem_fn(&Label::js_set_font));
			JSExport<Label>::AddValueProperty("text", std::mem_fn(&Label::js_get_text), std::mem_fn(&Label::js_set_text));
			JSExport<Label>::AddValueProperty("textAlign", std::mem_fn(&Label::js_get_textAlign), std::mem_fn(&Label::js_set_textAlign));
			JSExport<Label>::AddValueProperty("verticalAlign", std::mem_fn(&Label::js_get_verticalAlign), std::mem_fn(&Label::js_set_verticalAlign));
			JSExport<Label>::AddValueProperty("wordWrap", std::mem_fn(&Label::js_get_wordWrap), std::mem_fn(&Label::js_set_wordWrap));

			JSExport<Label>::AddFunctionProperty("getColor", std::mem_fn(&Label::js_getColor));
			JSExport<Label>::AddFunctionProperty("setColor", std::mem_fn(&Label::js_setColor));
			JSExport<Label>::AddFunctionProperty("getEllipsize", std::mem_fn(&Label::js_getEllipsize));
			JSExport<Label>::AddFunctionProperty("setEllipsize", std::mem_fn(&Label::js_setEllipsize));
			JSExport<Label>::AddFunctionProperty("getFont", std::mem_fn(&Label::js_getFont));
			JSExport<Label>::AddFunctionProperty("setFont", std::mem_fn(&Label::js_setFont));
			JSExport<Label>::AddFunctionProperty("getText", std::mem_fn(&Label::js_getText));
			JSExport<Label>::AddFunctionProperty("setText", std::mem_fn(&Label::js_setText));
			JSExport<Label>::AddFunctionProperty("getTextAlign", std::mem_fn(&Label::js_getTextAlign));
			JSExport<Label>::AddFunctionProperty("setTextAlign", std::mem_fn(&Label::js_setTextAlign));
			JSExport<Label>::AddFunctionProperty("getVerticalAlign", std::mem_fn(&Label::js_getVerticalAlign));
			JSExport<Label>::AddFunctionProperty("setVerticalAlign", std::mem_fn(&Label::js_setVerticalAlign));
			JSExport<Label>::AddFunctionProperty("getWordWrap", std::mem_fn(&Label::js_getWordWrap));
			JSExport<Label>::AddFunctionProperty("setWordWrap", std::mem_fn(&Label::js_setWordWrap));
		}

		JSValue Label::js_get_color() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(get_color());
		}

		bool Label::js_set_color(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsString());
			set_color(static_cast<std::string>(argument));
			return true;
		}

		JSValue Label::js_get_ellipsize() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(get_ellipsize());
		}

		bool Label::js_set_ellipsize(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_ellipsize(static_cast<bool>(argument));
			return true;
		}

		JSValue Label::js_get_font() const TITANIUM_NOEXCEPT
		{
			JSObject font = get_context().CreateObject();
			font.SetProperty("fontFamily", get_context().CreateString(font__.fontFamily));
			font.SetProperty("fontSize", get_context().CreateString(font__.fontSize));
			font.SetProperty("fontStyle", get_context().CreateString(Constants::to_string(font__.fontStyle)));
			font.SetProperty("fontFamily", get_context().CreateString(Constants::to_string(font__.fontWeight)));
			font.SetProperty("textStyle", get_context().CreateString(Constants::to_string(font__.textStyle)));
			return static_cast<JSValue>(font);
		}

		bool Label::js_set_font(const JSValue& js_font) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(js_font.IsObject());
			JSObject font = static_cast<JSObject>(js_font);

			// Number/String
			if (font.HasProperty("fontSize")) {
				const auto font_size = font.GetProperty("fontSize");
				TITANIUM_ASSERT(font_size.IsString() || font_size.IsNumber());
				font__.fontSize = static_cast<std::string>(font_size);
			}

			// bold or normal
			if (font.HasProperty("fontWeight")) {
				const auto font_weight = font.GetProperty("fontWeight");
				TITANIUM_ASSERT(font_weight.IsString());
				font__.fontWeight = Constants::to_FONT_WEIGHT(std::underlying_type_t<FONT_WEIGHT>(font_weight));
			}

			// italic or normal
			if (font.HasProperty("fontStyle")) {
				const auto font_style = font.GetProperty("fontStyle");
				TITANIUM_ASSERT(font_style.IsString());
				font__.fontStyle = Constants::to_FONT_STYLE(std::underlying_type_t<FONT_STYLE>(font_style));
			}

			// String
			if (font.HasProperty("fontFamily")) {
				const auto font_family = font.GetProperty("fontFamily");
				TITANIUM_ASSERT(font_family.IsString());
				font__.fontFamily = static_cast<std::string>(font_family);
			}

			// String Titanium::UI::TEXT_STYLE constants
			if (font.HasProperty("textStyle")) {
				const auto font_text_style = font.GetProperty("textStyle");
				TITANIUM_ASSERT(font_text_style.IsString());
				font__.textStyle = Constants::to_TEXT_STYLE(std::underlying_type_t<TEXT_STYLE>(font_text_style));
			}

			return true;
		}

		JSValue Label::js_get_text() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(text__);
		}

		bool Label::js_set_text(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsString());
			set_text(static_cast<std::string>(argument));
			return true;
		}

		JSValue Label::js_get_textAlign() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(static_cast<std::underlying_type<TEXT_ALIGNMENT>::type>(get_textAlign()));
		}

		bool Label::js_set_textAlign(const JSValue& argument) TITANIUM_NOEXCEPT
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

		JSValue Label::js_get_verticalAlign() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(static_cast<std::underlying_type<TEXT_VERTICAL_ALIGNMENT>::type>(get_verticalAlign()));
		}

		bool Label::js_set_verticalAlign(const JSValue& argument) TITANIUM_NOEXCEPT
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

		JSValue Label::js_get_wordWrap() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(wordWrap__);
		}

		bool Label::js_set_wordWrap(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_wordWrap(static_cast<bool>(argument));
			return true;
		}

		JSValue Label::js_getColor(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_color();
		}

		JSValue Label::js_setColor(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_color(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

	JSValue Label::js_getEllipsize(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_ellipsize();
		}

		JSValue Label::js_setEllipsize(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_ellipsize(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue Label::js_getFont(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_font();
		}

		JSValue Label::js_setFont(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_font(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue Label::js_getText(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_text();
		}

		JSValue Label::js_setText(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_text(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue Label::js_getTextAlign(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_textAlign();
		}

		JSValue Label::js_setTextAlign(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_textAlign(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue Label::js_getVerticalAlign(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_verticalAlign();
		}

		JSValue Label::js_setVerticalAlign(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_verticalAlign(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue Label::js_getWordWrap(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_wordWrap();
		}

		JSValue Label::js_setWordWrap(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_wordWrap(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}
	} // namespace UI
}  // namespace Titanium
