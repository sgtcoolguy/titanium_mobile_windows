/**
* Titanium.UI.Label for Windows
*
* Copyright (c) 2014-2015 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/

#include "TitaniumWindows/UI/Label.hpp"
#include "TitaniumWindows/UI/View.hpp"
#include "TitaniumWindows/Utility.hpp"
#include "TitaniumWindows/UI/Windows/ViewHelper.hpp"
#include "Titanium/detail/TiImpl.hpp"
#include "Titanium/UI/AttributedString.hpp"
#include "Titanium/UI/Font.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		using namespace Windows::UI::Xaml::Documents;

		WindowsLabelLayoutDelegate::WindowsLabelLayoutDelegate() TITANIUM_NOEXCEPT
			: WindowsViewLayoutDelegate()
		{
			TITANIUM_LOG_DEBUG("WindowsLabelLayoutDelegate::ctor ", this);
		}

		WindowsLabelLayoutDelegate::~WindowsLabelLayoutDelegate() 
		{
			TITANIUM_LOG_DEBUG("WindowsLabelLayoutDelegate::dtor ", this);
		}

		void WindowsLabelLayoutDelegate::setComponent(Windows::UI::Xaml::FrameworkElement^ label) 
		{
			WindowsViewLayoutDelegate::setComponent(label);

			// TIMOB-19048: max size is set to screen size by default
			defaultMaxWidth__  = label->MaxWidth;
			defaultMaxHeight__ = label->MaxHeight;
			const auto current = Windows::UI::Xaml::Window::Current;
			if (current) {
				label->MaxWidth  = current->Bounds.Width;
				label->MaxHeight = current->Bounds.Height;
			}
		}

		void WindowsLabelLayoutDelegate::set_width(const std::string& width) TITANIUM_NOEXCEPT
		{
			WindowsViewLayoutDelegate::set_width(width);

			// reset max width when width is set explicitly
			getComponent()->MaxWidth = defaultMaxWidth__;
		}

		void WindowsLabelLayoutDelegate::set_height(const std::string& height) TITANIUM_NOEXCEPT
		{
			WindowsViewLayoutDelegate::set_height(height);

			// reset max height when height is set explicitly
			getComponent()->MaxHeight = defaultMaxHeight__;
		}

		Label::Label(const JSContext& js_context) TITANIUM_NOEXCEPT
			  : Titanium::UI::Label(js_context)
		{
			TITANIUM_LOG_DEBUG("Label::ctor ", this);
		}

		Label::~Label() 
		{
			TITANIUM_LOG_DEBUG("Label::dtor ", this);
		}

		void Label::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{
			Titanium::UI::Label::postCallAsConstructor(js_context, arguments);
			
			label__ = ref new Windows::UI::Xaml::Controls::TextBlock();

			Titanium::UI::Label::setLayoutDelegate<WindowsLabelLayoutDelegate>();

			label__->TextWrapping = Windows::UI::Xaml::TextWrapping::Wrap;
			label__->TextTrimming = Windows::UI::Xaml::TextTrimming::None;
			label__->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Center;
			label__->FontSize = DefaultFontSize;

			getViewLayoutDelegate<WindowsLabelLayoutDelegate>()->setComponent(label__);
		}

		void Label::JSExportInitialize()
		{
			JSExport<Label>::SetClassVersion(1);
			JSExport<Label>::SetParent(JSExport<Titanium::UI::Label>::Class());
		}

		void Label::set_color(const std::string& colorName) TITANIUM_NOEXCEPT
		{
			Titanium::UI::Label::set_color(colorName);
			const auto color_obj = WindowsViewLayoutDelegate::ColorForName(colorName);
			label__->Foreground = ref new Windows::UI::Xaml::Media::SolidColorBrush(color_obj);
		}

		void Label::set_text(const std::string& text) TITANIUM_NOEXCEPT
		{
			Titanium::UI::Label::set_text(text);
			label__->Text = TitaniumWindows::Utility::ConvertUTF8String(text);
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

		void Label::set_font(const Titanium::UI::Font& font) TITANIUM_NOEXCEPT
		{
			Titanium::UI::Label::set_font(font);
			TitaniumWindows::UI::ViewHelper::SetFont<Windows::UI::Xaml::Controls::TextBlock^>(get_context(), label__, font);
		}

		void Label::set_attributedString(const std::shared_ptr<Titanium::UI::AttributedString>& attributedString) TITANIUM_NOEXCEPT
		{

			Titanium::UI::Label::set_attributedString(attributedString);

			//
			// simple implementation for attributed string due to mismatch with Windows Style API
			//   - only supports FOREGROUND_COLOR and FONT
			//   - attributes can't be nested
			// TODO: we might want to provide Windows-specific styling API leveraging Xaml Document API
			//
			const auto attributes = attributedString->get_attributes();
			const auto text = TitaniumWindows::Utility::ConvertToUTF8WString(attributedString->get_text());
			const auto text_length = text.length();

			auto root = ref new Span();
			std::unordered_map<std::uint32_t, std::uint32_t> ranges;
 			std::unordered_map<std::uint32_t, std::vector<Titanium::UI::Attribute>> styles;
			// scan all attributes to construct range collection
			for (const auto attribute : attributes) {
				const auto index = attribute.from;
				ranges.emplace(index, attribute.length);
				if (styles.find(index) == styles.end()) {
					std::vector<Titanium::UI::Attribute> attrs;
					styles.emplace(index, attrs);
				}
				styles.at(attribute.from).push_back(attribute);
			}

			std::uint32_t nostyle_start = 0;
			for (std::uint32_t pos = 0; pos < text_length; pos++) {
				if (ranges.find(pos) != ranges.end()) {

					// text with no attribute
					const auto nostyle_pos = pos - nostyle_start;
					if (nostyle_pos > 0) {
						auto run = ref new Run();
						run->Text = ref new Platform::String(text.substr(nostyle_start, nostyle_pos).data());
						root->Inlines->Append(run);
					}

					// extract attributes
					auto span = ref new Span();
					if (styles.find(pos) != styles.end()) {
						for (const auto attribute : styles.at(pos)) {
							switch (attribute.type) {
							case Titanium::UI::ATTRIBUTE_TYPE::FOREGROUND_COLOR: 
							{
								span->Foreground = ref new Windows::UI::Xaml::Media::SolidColorBrush(
									WindowsViewLayoutDelegate::ColorForName(static_cast<std::string>(attribute.value)));
								break;
							}
							case Titanium::UI::ATTRIBUTE_TYPE::FONT: 
							{
								const auto font = Titanium::UI::js_to_Font(static_cast<JSObject>(attribute.value));
								TitaniumWindows::UI::ViewHelper::SetFont<Windows::UI::Xaml::Documents::Span^>(get_context(), span, font);
								break;
							}
							}
						}
					}

					// text with attribute
					const auto len = ranges.at(pos);
					auto run = ref new Run();
					run->Text = ref new Platform::String(text.substr(pos, len).data());
					auto debug = ref new Platform::String(text.substr(pos, len).data());

					span->Inlines->Append(run);
					root->Inlines->Append(span);
					pos += len;
					nostyle_start = pos;
				}
			}

			// Append rest of the text with no attribute
			if (nostyle_start < text_length) {
				const auto len = text_length - nostyle_start;
				auto run = ref new Run();
				run->Text = ref new Platform::String(text.substr(nostyle_start, len).data());
				root->Inlines->Append(run);
			}

			label__->Inlines->Append(root);
		}

	} // namespace UI
} // namespace TitaniumWindows
