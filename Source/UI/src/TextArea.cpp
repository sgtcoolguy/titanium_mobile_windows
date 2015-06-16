/**
 * Titanium.UI.TextArea for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/UI/TextArea.hpp"
#include "TitaniumWindows/UI/WindowsViewLayoutDelegate.hpp"
#include "TitaniumWindows/Utility.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		// FIXME What file formats does windows support for fonts? We need to limit here! Most of what I read says only TTF, but I see some mentions of OpenType
		static const std::string ti_textarea_js = R"TI_LABEL_JS(
	this.exports = {};
	this.exports.getFontFilePath = function(fontFamily) {
		var iconsFolder = Ti.Filesystem.getFile(Ti.Filesystem.applicationDirectory, 'fonts');
		var files = iconsFolder.getDirectoryListing();
		for (var i = 0; i < files.length; i++) {
			var name = files[i];
			if (name.toLowerCase() == fontFamily.toLowerCase() || name.toLowerCase().indexOf(fontFamily.toLowerCase() + '.') == 0) {
				return name;
			}
		}
		return null;
	};
	)TI_LABEL_JS";

		TextArea::TextArea(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::UI::TextArea(js_context)
		{
		}

		void TextArea::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{
			Titanium::UI::TextArea::postCallAsConstructor(js_context, arguments);	
			
			text_box__ = ref new Windows::UI::Xaml::Controls::TextBox();
			text_box__->AcceptsReturn = true;

			Titanium::UI::TextArea::setLayoutDelegate<WindowsViewLayoutDelegate>();
			getViewLayoutDelegate<WindowsViewLayoutDelegate>()->setComponent(text_box__);
		}

		void TextArea::JSExportInitialize() {
			JSExport<TextArea>::SetClassVersion(1);
			JSExport<TextArea>::SetParent(JSExport<Titanium::UI::TextArea>::Class());
		}

		void TextArea::set_autocorrect(const bool& autocorrect) TITANIUM_NOEXCEPT
		{
			Titanium::UI::TextArea::set_autocorrect(autocorrect);
			text_box__->IsSpellCheckEnabled = autocorrect;
		}

		void TextArea::set_color(const std::string& color) TITANIUM_NOEXCEPT
		{
			Titanium::UI::TextArea::set_color(color);
			const auto color_obj = WindowsViewLayoutDelegate::ColorForName(color);
			text_box__->Foreground = ref new Windows::UI::Xaml::Media::SolidColorBrush(color_obj);
		}

		void TextArea::set_editable(const bool& editable) TITANIUM_NOEXCEPT
		{
			Titanium::UI::TextArea::set_editable(editable);
			text_box__->IsReadOnly = !editable;
		}

		void TextArea::set_font(const Titanium::UI::Font& font) TITANIUM_NOEXCEPT
		{
			Titanium::UI::TextArea::set_font(font);
			// TODO This lookup map should be global, not per-instance of a TextArea!
			// Did we already look up this font?
			auto family = font.fontFamily;
			if (family.length() > 0) {
				auto path = family;
				if (custom_fonts__.find(family) == custom_fonts__.end()) {
					// Look up to see if this is a custom font!
					auto export_object = get_context().CreateObject();
					get_context().JSEvaluateScript(ti_textarea_js, export_object);
					TITANIUM_ASSERT(export_object.HasProperty("exports"));
					auto exports = export_object.GetProperty("exports");
					TITANIUM_ASSERT(exports.IsObject());
					auto exports_object = static_cast<JSObject>(exports);
					auto eval_result = exports_object.GetProperty("getFontFilePath");
					TITANIUM_ASSERT(eval_result.IsObject());
					auto func = static_cast<JSObject>(eval_result);
					TITANIUM_ASSERT(func.IsFunction());
					auto result = func(family, get_context().get_global_object());
					if (result.IsNull()) { // we have no custom font by this name, assume it's a built-in font
						path = family;
					} else {
						TITANIUM_ASSERT(result.IsString()); // custom font file
						const auto file_name = static_cast<std::string>(result);
						path = "/fonts/" + file_name + "#" + family;
					}
				}
				
				custom_fonts__.emplace(family, path);
				text_box__->FontFamily = ref new Windows::UI::Xaml::Media::FontFamily(Utility::ConvertUTF8String(path));
			}
			if (font.fontSize.length() > 0) {
				text_box__->FontSize = std::stod(font.fontSize);
			}

			if (font.fontStyle == Titanium::UI::FONT_STYLE::ITALIC) {
				text_box__->FontStyle = Windows::UI::Text::FontStyle::Italic;
			} else if (font.fontStyle == Titanium::UI::FONT_STYLE::NORMAL) {
				text_box__->FontStyle = Windows::UI::Text::FontStyle::Normal;
			}
			// TODO Windows supports Oblique: http://msdn.microsoft.com/en-us/library/windows/apps/windows.ui.text.fontstyle.aspx

			if (font.fontWeight == Titanium::UI::FONT_WEIGHT::BOLD) {
				text_box__->FontWeight = Windows::UI::Text::FontWeights::Bold;
			} else if (font.fontWeight == Titanium::UI::FONT_WEIGHT::NORMAL) {
				text_box__->FontWeight = Windows::UI::Text::FontWeights::Normal;
			} else if (font.fontWeight == Titanium::UI::FONT_WEIGHT::SEMIBOLD) {
				text_box__->FontWeight = Windows::UI::Text::FontWeights::SemiBold;
			}
			// TODO Windows supports a large number of other weights: http://msdn.microsoft.com/en-us/library/windows/apps/windows.ui.text.fontweights
		}

		void TextArea::set_hintText(const std::string& hintText) TITANIUM_NOEXCEPT
		{
			Titanium::UI::TextArea::set_hintText(hintText);
			text_box__->PlaceholderText = TitaniumWindows::Utility::ConvertUTF8String(hintText);
		}

		void TextArea::set_keyboardType(const Titanium::UI::KEYBOARD& keyboardType) TITANIUM_NOEXCEPT
		{
			Titanium::UI::TextArea::set_keyboardType(keyboardType);
			auto scope_name = ref new Windows::UI::Xaml::Input::InputScopeName();
			if (keyboardType == Titanium::UI::KEYBOARD::ASCII) {
				scope_name->NameValue = Windows::UI::Xaml::Input::InputScopeNameValue::Default;
			}
			else if (keyboardType == Titanium::UI::KEYBOARD::DECIMAL_PAD) {
				scope_name->NameValue = Windows::UI::Xaml::Input::InputScopeNameValue::Number;
			}
			else if (keyboardType == Titanium::UI::KEYBOARD::DEFAULT) {
				scope_name->NameValue = Windows::UI::Xaml::Input::InputScopeNameValue::Default;
			}
			else if (keyboardType == Titanium::UI::KEYBOARD::EMAIL) {
				scope_name->NameValue = Windows::UI::Xaml::Input::InputScopeNameValue::EmailSmtpAddress;
			}
			else if (keyboardType == Titanium::UI::KEYBOARD::NAMEPHONE_PAD) {
				scope_name->NameValue = Windows::UI::Xaml::Input::InputScopeNameValue::NameOrPhoneNumber;
			}
			else if (keyboardType == Titanium::UI::KEYBOARD::NUMBERS_PUNCTUATION) {
				scope_name->NameValue = Windows::UI::Xaml::Input::InputScopeNameValue::CurrencyAmountAndSymbol;
			}
			else if (keyboardType == Titanium::UI::KEYBOARD::NUMBER_PAD) {
				scope_name->NameValue = Windows::UI::Xaml::Input::InputScopeNameValue::Number;
			}
			else if (keyboardType == Titanium::UI::KEYBOARD::PHONE_PAD) {
				scope_name->NameValue = Windows::UI::Xaml::Input::InputScopeNameValue::TelephoneNumber;
			}
			else if (keyboardType == Titanium::UI::KEYBOARD::URL) {
				scope_name->NameValue = Windows::UI::Xaml::Input::InputScopeNameValue::Url;
			}
			else {
				return;
			}
			auto scope = text_box__->InputScope;
			if (!scope) {
				scope = ref new Windows::UI::Xaml::Input::InputScope();
				text_box__->InputScope = scope;
			}
			scope->Names->Clear();
			scope->Names->Append(scope_name);
		}


		void TextArea::set_maxLength(const int32_t& maxLength) TITANIUM_NOEXCEPT
		{
			Titanium::UI::TextArea::set_maxLength(maxLength);
			text_box__->MaxLength = maxLength;
		}

		JSValue TextArea::get_selection() const TITANIUM_NOEXCEPT
		{
			// FIXME Introduce a struct up in TitaniumKit for this!
			auto context = get_context();
			auto object = context.CreateObject();
			object.SetProperty("length", context.CreateNumber(text_box__->SelectionLength));
			object.SetProperty("location", context.CreateNumber(text_box__->SelectionStart));
			return object;
		}

		void TextArea::set_textAlign(const Titanium::UI::TEXT_ALIGNMENT& textAlign) TITANIUM_NOEXCEPT
		{
			Titanium::UI::TextArea::set_textAlign(textAlign);
			if (textAlign == Titanium::UI::TEXT_ALIGNMENT::CENTER) {
				text_box__->TextAlignment = Windows::UI::Xaml::TextAlignment::Center;
			} else if (textAlign == Titanium::UI::TEXT_ALIGNMENT::LEFT) {
				text_box__->TextAlignment = Windows::UI::Xaml::TextAlignment::Left;
			} else if (textAlign == Titanium::UI::TEXT_ALIGNMENT::RIGHT) {
				text_box__->TextAlignment = Windows::UI::Xaml::TextAlignment::Right;
			}
			// TODO Windows supports JUSTIFY!
		}

		std::string TextArea::get_value() const TITANIUM_NOEXCEPT
		{
			return TitaniumWindows::Utility::ConvertUTF8String(text_box__->Text);
		}

		void TextArea::set_value(const std::string& value) TITANIUM_NOEXCEPT
		{
			Titanium::UI::TextArea::set_value(value);
			text_box__->Text = TitaniumWindows::Utility::ConvertUTF8String(value);
		}

		void TextArea::set_verticalAlign(const Titanium::UI::TEXT_VERTICAL_ALIGNMENT& verticalAlign) TITANIUM_NOEXCEPT
		{
			Titanium::UI::TextArea::set_verticalAlign(verticalAlign);
			if (verticalAlign == Titanium::UI::TEXT_VERTICAL_ALIGNMENT::BOTTOM) {
				text_box__->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Bottom;
			} else if (verticalAlign == Titanium::UI::TEXT_VERTICAL_ALIGNMENT::CENTER) {
				text_box__->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Center;
			} else if (verticalAlign == Titanium::UI::TEXT_VERTICAL_ALIGNMENT::TOP) {
				text_box__->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Top;
			}
			// TODO Windows supports stretch!
		}

		void TextArea::blur() TITANIUM_NOEXCEPT
		{
			// TODO Windows doesn't allow forcibly losing focus, need to set focus on another control to achieve it! Can we set focus on the window or parent or something?
		}

		void TextArea::focus() TITANIUM_NOEXCEPT
		{
			text_box__->Focus(Windows::UI::Xaml::FocusState::Programmatic);
		}

	}  // namespace UI
}  // namespace TitaniumWindows