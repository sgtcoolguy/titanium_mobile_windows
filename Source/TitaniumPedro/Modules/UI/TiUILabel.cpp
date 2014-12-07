/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#include "Modules/UI/TiUILabel.h"
#include <Windows.h>
#include "TiCore/TiWebColor.h"
#include "TiCore/TiUtils.h"

namespace Ti {
	namespace UI {

		const JSStaticFunction Label::ClassMethods[] = {
				{ "setEllipsize", _setEllipsize, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getEllipsize", _getEllipsize, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setFont", _setFont, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setHighlightedColor", _setHighlightedColor, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setText", _setText, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getText", _getText, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setTextAlign", _setTextAlign, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getTextAlign", _getTextAlign, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setVerticalAlign", _setVerticalAlign, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getVerticalAlign", _getVerticalAlign, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setWordWrap", _setWordWrap, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getWordWrap", _getWordWrap, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ 0, 0, 0 }
		};

		Label::Label(const std::string& name, const std::vector<Ti::Value>& arguments) : Ti::ViewProxy(name, arguments) {
			text_block_ = ref new Windows::UI::Xaml::Controls::TextBlock();
			text_block_->TextWrapping = Windows::UI::Xaml::TextWrapping::Wrap;
			text_block_->TextTrimming = Windows::UI::Xaml::TextTrimming::Clip;
			text_block_->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Center;

			setComponent(text_block_);
		}

		// TODO: Move this to a utils class to be used in other proxies, like
		// TextArea or TextField Sets the value of the font property.
		Ti::Value Label::setFont(const std::vector<Ti::Value>& arguments) {
			const auto& arg1 = arguments.at(0);
			if (!arg1.isObject()) {
				OutputDebugString(L"[WARN] Label.setFont() must be an object. Returning Undefined");
				return Ti::Value::Undefined();
			}

			const auto font = arg1.getProperty("fontFamily");
			if (font.isString()){
				const auto str = font.toString();
        const auto pStr = Ti::Utils::GetPlatformString(str);
				text_block_->FontFamily = ref new Windows::UI::Xaml::Media::FontFamily(pStr);
			}
			const auto size = arg1.getProperty("fontSize");
			if (size.isString() || size.isNumber()) {
        text_block_->FontSize = size.toDouble();
			}

			const auto weight = arg1.getProperty("fontWeight");
			if (weight.isString()) {
				const auto str = weight.toString();
				if (str == "bold") {
					text_block_->FontWeight = Windows::UI::Text::FontWeights::Bold;
				}
				else if (str == "black") {
					text_block_->FontWeight = Windows::UI::Text::FontWeights::Black;
				}
				else if (str == "light") {
					text_block_->FontWeight = Windows::UI::Text::FontWeights::Light;
				}
				else if (str == "extraBlack") {
					text_block_->FontWeight = Windows::UI::Text::FontWeights::ExtraBlack;
				}
				else if (str == "extraBold") {
					text_block_->FontWeight = Windows::UI::Text::FontWeights::ExtraBold;
				}
				else if (str == "extraLight") {
					text_block_->FontWeight = Windows::UI::Text::FontWeights::ExtraLight;
				}
			}
			return Ti::Value::Undefined();
		}



		// Gets the value of the ellipsize property.
		Ti::Value Label::getEllipsize(const std::vector<Ti::Value>& arguments)
		{
			return Ti::Value(text_block_->TextTrimming == Windows::UI::Xaml::TextTrimming::WordEllipsis);
		}

		// Sets the value of the ellipsize property.
		Ti::Value Label::setEllipsize(const std::vector<Ti::Value>& arguments)
		{
			using Windows::UI::Xaml::TextTrimming;
			text_block_->TextTrimming = arguments.at(0).toBool() ? TextTrimming::WordEllipsis : TextTrimming::None;
			return Ti::Value::Undefined();
		}

		// Gets the value of the font property.
		// Sets the value of the highlightedColor property.
		Ti::Value Label::setHighlightedColor(const std::vector<Ti::Value>& arguments)
		{
			highlighted_color_ = arguments.at(0).toString();
			text_block_->SelectionHighlightColor = ref new Windows::UI::Xaml::Media::SolidColorBrush(Ti::WebColor::Color(highlighted_color_));
			return Ti::Value::Undefined();
		}

		// Gets the value of the text property.
		Ti::Value Label::getText(const std::vector<Ti::Value>& arguments)
		{
			const auto text = text_block_->Text;
			return Ti::Value(std::string(text->Begin(), text->End()));
		}

		// Sets the value of the text property.
		Ti::Value Label::setText(const std::vector<Ti::Value>& arguments)
		{
			const auto str = arguments.at(0).toString();
			text_block_->Text = ref new Platform::String(std::wstring(str.begin(), str.end()).c_str());
			return Ti::Value::Undefined();
		}

		// Gets the value of the textAlign property.
		Ti::Value Label::getTextAlign(const std::vector<Ti::Value>& arguments)
		{
			switch (text_block_->TextAlignment) {
			case Windows::UI::Xaml::TextAlignment::Center:
				return Ti::Value("center");
			case Windows::UI::Xaml::TextAlignment::Justify:
				return Ti::Value("justify");
			case Windows::UI::Xaml::TextAlignment::Left:
				return Ti::Value("left");
			case Windows::UI::Xaml::TextAlignment::Right:
				return Ti::Value("right");
			default:
				return Ti::Value::Undefined();
			}
		}

		// Sets the value of the textAlign property.
		Ti::Value Label::setTextAlign(const std::vector<Ti::Value>& arguments)
		{
			auto textAlign = arguments.at(0).toString();
			// let's make it all lowercase, fool proof

			std::transform(textAlign.begin(), textAlign.end(), textAlign.begin(), ::tolower);
			if (textAlign == "center") {
				text_block_->TextAlignment = Windows::UI::Xaml::TextAlignment::Center;
			}
			else if (textAlign == "justify") {
				text_block_->TextAlignment = Windows::UI::Xaml::TextAlignment::Justify;
			}
			else if (textAlign == "left"){
				text_block_->TextAlignment = Windows::UI::Xaml::TextAlignment::Left;
			}
			else if (textAlign == "right"){
				text_block_->TextAlignment = Windows::UI::Xaml::TextAlignment::Right;
			}

			return Ti::Value::Undefined();
		}

		// Gets the value of the verticalAlign property.
		Ti::Value Label::getVerticalAlign(const std::vector<Ti::Value>& arguments)
		{
			switch (text_block_->VerticalAlignment) {
			case Windows::UI::Xaml::VerticalAlignment::Bottom:
				return Ti::Value("bottom");
			case Windows::UI::Xaml::VerticalAlignment::Center:
				return Ti::Value("center");
			case Windows::UI::Xaml::VerticalAlignment::Stretch:
				return Ti::Value("stretch");
			case Windows::UI::Xaml::VerticalAlignment::Top:
				return Ti::Value("top");
			default:
				return Ti::Value::Undefined();
			}
		}

		Ti::Value Label::setVerticalAlign(const std::vector<Ti::Value>& arguments)
		{
			auto vertAlign = arguments.at(0).toString();
			// let's make it all lowercase, fool proof
			std::transform(vertAlign.begin(), vertAlign.end(), vertAlign.begin(), ::tolower);
			if (vertAlign == "bottom"){
				text_block_->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Bottom;
			}
			else if (vertAlign == "center"){
				text_block_->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Center;
			}
			else if (vertAlign == "stretch"){
				text_block_->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Stretch;
			}
			else if (vertAlign == "top"){
				text_block_->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Top;
			}

			return Ti::Value::Undefined();
		}

		// Gets the value of the wordWrap property.
		Ti::Value Label::getWordWrap(const std::vector<Ti::Value>& arguments)
		{
			return Ti::Value(text_block_->TextWrapping == Windows::UI::Xaml::TextWrapping::Wrap);
		}

		// Sets the value of the wordWrap property.
		Ti::Value Label::setWordWrap(const std::vector<Ti::Value>& arguments)
		{
			using Windows::UI::Xaml::TextWrapping;
			text_block_->TextWrapping = arguments.at(0).toBool() ? TextWrapping::Wrap : TextWrapping::NoWrap;
			return Ti::Value::Undefined();
		}


	}
} // namespace Ti { namespace UI {
