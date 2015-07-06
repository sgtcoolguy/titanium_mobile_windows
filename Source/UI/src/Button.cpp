/**
* Titanium.UI.Button for Windows
*
* Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/

#include "TitaniumWindows/UI/Button.hpp"
#include "TitaniumWindows/Utility.hpp"
#include "TitaniumWindows/UI/WindowsViewLayoutDelegate.hpp"
#include "Titanium/detail/TiImpl.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		// FIXME Combine with TitaniumWindows::UI::Label!
		static const std::string ti_button_js = R"TI_BUTTON_JS(
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
	)TI_BUTTON_JS";

		Button::Button(const JSContext& js_context) TITANIUM_NOEXCEPT
		    : Titanium::UI::Button(js_context)
		{
			TITANIUM_LOG_DEBUG("Button::ctor");
		}

		void Button::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{
			Titanium::UI::Button::postCallAsConstructor(js_context, arguments);	
			button__ = ref new Windows::UI::Xaml::Controls::Button();
			// TODO Create a StackPanel to hold image and TextBox in Content property...
			Titanium::UI::Button::setLayoutDelegate<WindowsViewLayoutDelegate>();

			button__->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Center;
			button__->FontSize = DefaultFontSize;

			// TIMOB-19143: reset MinWidth to fix size issues
			button__->MinWidth = 0;

			getViewLayoutDelegate<WindowsViewLayoutDelegate>()->setComponent(button__);
		}

		void Button::JSExportInitialize()
		{
			JSExport<Button>::SetClassVersion(1);
			JSExport<Button>::SetParent(JSExport<Titanium::UI::Button>::Class());
		}

		void Button::set_color(const std::string& colorName) TITANIUM_NOEXCEPT
		{
			Titanium::UI::Button::set_color(colorName);
			const auto color_obj = WindowsViewLayoutDelegate::ColorForName(colorName);
			button__->Foreground = ref new Windows::UI::Xaml::Media::SolidColorBrush(color_obj);
		}

		void Button::set_image(const std::string& image) TITANIUM_NOEXCEPT
		{
			Titanium::UI::Button::set_image(image);

			// TODO Implement! We can use Content property to generate a composite holding both text and image!
			TITANIUM_LOG_WARN("Button.image is not implemented yet");
		}

		void Button::set_font(const Titanium::UI::Font& font) TITANIUM_NOEXCEPT
		{
			Titanium::UI::Button::set_font(font);
			// TODO This lookup map should be global, not per-instance of a Label!
			// Did we already look up this font?
			auto family = font.fontFamily;
			if (family.length() > 0) {
				auto path = family;
				if (custom_fonts__.find(family) == custom_fonts__.end()) {
					// Look up to see if this is a custom font!
					auto export_object = get_context().CreateObject();
					get_context().JSEvaluateScript(ti_button_js, export_object);
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
				button__->FontFamily = ref new Windows::UI::Xaml::Media::FontFamily(Utility::ConvertUTF8String(path));
			}
			if (font.fontSize.length() > 0) {
				button__->FontSize = std::stod(font.fontSize);
			}

			if (font.fontStyle == Titanium::UI::FONT_STYLE::ITALIC) {
				button__->FontStyle = Windows::UI::Text::FontStyle::Italic;
			} else if (font.fontStyle == Titanium::UI::FONT_STYLE::NORMAL) {
				button__->FontStyle = Windows::UI::Text::FontStyle::Normal;
			}
			// TODO Windows supports Oblique: http://msdn.microsoft.com/en-us/library/windows/apps/windows.ui.text.fontstyle.aspx

			if (font.fontWeight == Titanium::UI::FONT_WEIGHT::BOLD) {
				button__->FontWeight = Windows::UI::Text::FontWeights::Bold;
			} else if (font.fontWeight == Titanium::UI::FONT_WEIGHT::NORMAL) {
				button__->FontWeight = Windows::UI::Text::FontWeights::Normal;
			} else if (font.fontWeight == Titanium::UI::FONT_WEIGHT::SEMIBOLD) {
				button__->FontWeight = Windows::UI::Text::FontWeights::SemiBold;
			}
			// TODO Windows supports a large number of other weights: http://msdn.microsoft.com/en-us/library/windows/apps/windows.ui.text.fontweights
		}

		void Button::set_textAlign(const Titanium::UI::TEXT_ALIGNMENT& textAlign) TITANIUM_NOEXCEPT
		{
			Titanium::UI::Button::set_textAlign(textAlign);

			TITANIUM_LOG_WARN("Button.textAlign is not implemented yet");
			//if (textAlign == Titanium::UI::TEXT_ALIGNMENT::CENTER) {
			//	button__->TextAlignment = Windows::UI::Xaml::TextAlignment::Center;
			//} else if (textAlign == Titanium::UI::TEXT_ALIGNMENT::LEFT) {
			//	button__->TextAlignment = Windows::UI::Xaml::TextAlignment::Left;
			//} else if (textAlign == Titanium::UI::TEXT_ALIGNMENT::RIGHT) {
			//	button__->TextAlignment = Windows::UI::Xaml::TextAlignment::Right;
			//}
			// TODO Windows supports JUSTIFY!
		}

		void Button::set_title(const std::string& title) TITANIUM_NOEXCEPT
		{
			Titanium::UI::Button::set_title(title);
			button__->Content = TitaniumWindows::Utility::ConvertUTF8String(title);
		}

		void Button::set_verticalAlign(const Titanium::UI::TEXT_VERTICAL_ALIGNMENT& verticalAlign) TITANIUM_NOEXCEPT
		{
			Titanium::UI::Button::set_verticalAlign(verticalAlign);
			if (verticalAlign == Titanium::UI::TEXT_VERTICAL_ALIGNMENT::BOTTOM) {
				button__ ->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Bottom;
			} else if (verticalAlign == Titanium::UI::TEXT_VERTICAL_ALIGNMENT::CENTER) {
				button__->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Center;
			} else if (verticalAlign == Titanium::UI::TEXT_VERTICAL_ALIGNMENT::TOP) {
				button__->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Top;
			}
			// TODO Windows supports stretch!
		}

		void Button::enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
		{
			Titanium::UI::Button::enableEvent(event_name);

			const JSContext ctx = this->get_context();

			using namespace Windows::UI::Xaml::Input;
			using namespace Windows::UI::Xaml;

			auto component = getViewLayoutDelegate<WindowsViewLayoutDelegate>()->getComponent();

			if (event_name == "click") {
				if (click_event_count_ == 0) {
					click_event_ = component->Tapped += ref new TappedEventHandler([this, ctx](Platform::Object^ sender, TappedRoutedEventArgs^ e) {
						auto component = safe_cast<FrameworkElement^>(sender);
						auto position = e->GetPosition(component);

						JSObject  eventArgs = ctx.CreateObject();
						eventArgs.SetProperty("x", ctx.CreateNumber(position.X));
						eventArgs.SetProperty("y", ctx.CreateNumber(position.Y));

						this->fireEvent("click", eventArgs);
					});
				}

				++click_event_count_;

				return;
			}
		}
	} // namespace UI
} // namespace TitaniumWindows
