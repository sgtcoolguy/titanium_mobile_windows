/**
* Titanium.UI.Label for Windows
*
* Copyright (c) 2014-2015 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/

#include "TitaniumWindows/UI/Label.hpp"
#include "TitaniumWindows/UI/WindowsViewLayoutPolicy.hpp"
#include "TitaniumWindows/Utility.hpp"

#define DEFAULT_FONT_SIZE 20

namespace TitaniumWindows
{
	namespace UI
	{
		// FIXME What file formats does windows support for fonts? We need to limit here! Most of what I read says only TTF, but I see some mentions of OpenType
		static const std::string ti_label_js = R"TI_LABEL_JS(
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

		Label::Label(const JSContext& js_context) TITANIUM_NOEXCEPT
			  : Titanium::UI::Label(js_context)
		{
		}

		void Label::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{
			Titanium::UI::Label::postCallAsConstructor(js_context, arguments);
			
			label__ = ref new Windows::UI::Xaml::Controls::TextBlock();
			Titanium::UI::Label::setLayoutPolicy<WindowsViewLayoutPolicy>();

			label__->TextWrapping = Windows::UI::Xaml::TextWrapping::Wrap;
			label__->TextTrimming = Windows::UI::Xaml::TextTrimming::Clip;
			label__->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Center;
			label__->FontSize = DEFAULT_FONT_SIZE;

			getViewLayoutPolicy<WindowsViewLayoutPolicy>()->setComponent(label__);

		}

		void Label::JSExportInitialize()
		{
			JSExport<Label>::SetClassVersion(1);
			JSExport<Label>::SetParent(JSExport<Titanium::UI::Label>::Class());
		}

		void Label::set_color(const std::string& colorName) TITANIUM_NOEXCEPT
		{
			Titanium::UI::Label::set_color(colorName);
			const auto color_obj = WindowsViewLayoutPolicy::ColorForName(colorName);
			label__->Foreground = ref new Windows::UI::Xaml::Media::SolidColorBrush(color_obj);
		}

		void Label::set_text(const std::string& text) TITANIUM_NOEXCEPT
		{
			Titanium::UI::Label::set_text(text);
			label__->Text = ref new Platform::String(std::wstring(text.begin(), text.end()).c_str());
		}

		void Label::set_textAlign(const Titanium::UI::TEXT_ALIGNMENT& textAlign) TITANIUM_NOEXCEPT
		{
			Titanium::UI::Label::set_textAlign(textAlign);
			if (textAlign == Titanium::UI::TEXT_ALIGNMENT::CENTER) {
				label__->TextAlignment = Windows::UI::Xaml::TextAlignment::Center;
			} else if (textAlign == Titanium::UI::TEXT_ALIGNMENT::LEFT) {
				label__->TextAlignment = Windows::UI::Xaml::TextAlignment::Left;
			} else if (textAlign == Titanium::UI::TEXT_ALIGNMENT::RIGHT) {
				label__->TextAlignment = Windows::UI::Xaml::TextAlignment::Right;
			}
			// TODO Windows supports JUSTIFY!
		}

		void Label::set_verticalAlign(const Titanium::UI::TEXT_VERTICAL_ALIGNMENT& verticalAlign) TITANIUM_NOEXCEPT
		{
			Titanium::UI::Label::set_verticalAlign(verticalAlign);
			if (verticalAlign == Titanium::UI::TEXT_VERTICAL_ALIGNMENT::BOTTOM) {
				label__->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Bottom;
			} else if (verticalAlign == Titanium::UI::TEXT_VERTICAL_ALIGNMENT::CENTER) {
				label__->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Center;
			} else if (verticalAlign == Titanium::UI::TEXT_VERTICAL_ALIGNMENT::TOP) {
				label__->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Top;
			}
			// TODO Windows supports stretch!
		}

		void Label::set_wordWrap(const bool& wordWrap) TITANIUM_NOEXCEPT
		{
			Titanium::UI::Label::set_wordWrap(wordWrap);
			label__->TextWrapping = wordWrap ? Windows::UI::Xaml::TextWrapping::Wrap : Windows::UI::Xaml::TextWrapping::NoWrap;
		}

		void Label::set_fontFamily(const std::string& family) TITANIUM_NOEXCEPT
		{
			Titanium::UI::Label::set_fontFamily(family);
			// TODO This lookup map should be global, not per-instance of a Label!
			// Did we already look up this font?
			auto path = family;
			if (custom_fonts__.find(family) == custom_fonts__.end()) {
				// Look up to see if this is a custom font!
				auto export_object = get_context().CreateObject();
				get_context().JSEvaluateScript(ti_label_js, export_object);
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
				custom_fonts__[family] = path;
			}
			label__->FontFamily = ref new Windows::UI::Xaml::Media::FontFamily (TitaniumWindows::Utility::ConvertString(path));
		}

		void Label::set_fontSize(const JSValue& size) TITANIUM_NOEXCEPT
		{
			if (size.IsNumber()) {
				label__->FontSize = static_cast<double>(size);
			} else {
				label__->FontSize = std::stod(static_cast<std::string>(size));
			}
		}

		void Label::set_fontStyle(const std::string& style) TITANIUM_NOEXCEPT
		{
			if (style == "italic") {
				label__->FontStyle = Windows::UI::Text::FontStyle::Italic;
			} else if (style == "normal") {
				label__->FontStyle = Windows::UI::Text::FontStyle::Normal;
			}
			// TODO Windows supports Oblique: http://msdn.microsoft.com/en-us/library/windows/apps/windows.ui.text.fontstyle.aspx
		}

		void Label::set_fontWeight(const std::string& weight) TITANIUM_NOEXCEPT
		{
			if (weight == "bold") {
				label__->FontWeight = Windows::UI::Text::FontWeights::Bold;
			} else if (weight == "normal") {
				label__->FontWeight = Windows::UI::Text::FontWeights::Normal;
			} else if (weight == "semibold") {
				label__->FontWeight = Windows::UI::Text::FontWeights::SemiBold;
			}
			// TODO Windows supports a large number of other weights: http://msdn.microsoft.com/en-us/library/windows/apps/windows.ui.text.fontweights
		}

		void Label::set_textStyle(const Titanium::UI::TEXT_STYLE& textStyle) TITANIUM_NOEXCEPT
		{
			Titanium::UI::Label::set_textStyle(textStyle);
		}

		void Label::enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_DEBUG("Label::enableEvent: (event name '", event_name, "'");

			const JSContext ctx = this->get_context();

			using namespace Windows::UI::Xaml::Input;
			using namespace Windows::UI::Xaml;

			auto component = getViewLayoutPolicy<WindowsViewLayoutPolicy>()->getComponent();

			if (event_name == "click") {
				click_event_ = component->Tapped += ref new TappedEventHandler([this, ctx](Platform::Object^ sender, TappedRoutedEventArgs^ e) {
					auto component = safe_cast<FrameworkElement^>(sender);
					auto position = e->GetPosition(component);

					JSObject  eventArgs = ctx.CreateObject();
					eventArgs.SetProperty("x", ctx.CreateNumber(position.X));
					eventArgs.SetProperty("y", ctx.CreateNumber(position.Y));

					this->fireEvent("click", eventArgs);
				});
			}
		}

	} // namespace UI
} // namespace TitaniumWindows
