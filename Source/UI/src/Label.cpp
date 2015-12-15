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
#include <unordered_map>
#include <tuple>

namespace TitaniumWindows
{
	namespace UI
	{
		using namespace Windows::UI::Xaml;
		using namespace Windows::UI::Xaml::Documents;
		using namespace Windows::UI::Text;

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
			//
			// store some attributes by index so we can search them faster
			//
			// ranges[index] = [length, hasUnderline, hasLink, url]
			//
			std::unordered_map<std::uint32_t, std::tuple<std::uint32_t, bool, bool, std::string>> ranges;
 			std::unordered_map<std::uint32_t, std::vector<Titanium::UI::Attribute>> styles;
			// scan all attributes to construct range collection
			for (const auto attribute : attributes) {

				const auto index = attribute.from;

				if (ranges.find(index) == ranges.end()) {
					ranges[index] = std::make_tuple(attribute.length, false, false, "");
				}


				if (styles.find(index) == styles.end()) {
					std::vector<Titanium::UI::Attribute> attrs;
					styles.emplace(index, attrs);
				}

				auto data = ranges.at(index);
				if (attribute.type == Titanium::UI::ATTRIBUTE_TYPE::UNDERLINES_STYLE) {
					std::get<1>(data) = true;
				} else if (attribute.type == Titanium::UI::ATTRIBUTE_TYPE::LINK) {
					std::get<2>(data) = true;
					std::get<3>(data) = static_cast<std::string>(attribute.value);
				}
				ranges.at(index) = data;

				styles.at(attribute.from).push_back(attribute);
			}

			std::uint32_t nostyle_start = 0;
			for (std::uint32_t pos = 0; pos < text_length; pos++) {
				if (ranges.find(pos) != ranges.end()) {
					const auto rangeInfo = ranges.at(pos);
					const auto length = std::get<0>(rangeInfo);
					const auto hasUnderline = std::get<1>(rangeInfo);
					const auto hasLink = std::get<2>(rangeInfo);

					// text with no attribute
					const auto nostyle_pos = pos - nostyle_start;
					if (nostyle_pos > 0) {
						auto run = ref new Run();
						run->Text = ref new Platform::String(text.substr(nostyle_start, nostyle_pos).data());
						root->Inlines->Append(run);
					}

					// extract attributes
					auto run  = ref new Run();
					// text with attribute
					run->Text = ref new Platform::String(text.substr(pos, length).data());

					Span^ span;
					if (hasUnderline) {        /* UNDERLINES_STYLE */
						span = ref new Underline();
					} else if (hasLink) { /* LINK */
						auto hyperlink = ref new Hyperlink();
						hyperlink->NavigateUri = ref new Windows::Foundation::Uri(TitaniumWindows::Utility::ConvertString(std::get<3>(rangeInfo)));
						span = hyperlink;
					} else {
						span = ref new Span();
					}

					if (styles.find(pos) != styles.end()) {
						for (const auto attribute : styles.at(pos)) {
							const auto attribute_styles = Titanium::UI::Constants::to_ATTRIBUTE_STYLE(static_cast<std::underlying_type<Titanium::UI::ATTRIBUTE_STYLE>::type>(attribute.value));
							switch (attribute.type) {
							case Titanium::UI::ATTRIBUTE_TYPE::FOREGROUND_COLOR: 
								span->Foreground = ref new Windows::UI::Xaml::Media::SolidColorBrush(
									WindowsViewLayoutDelegate::ColorForName(static_cast<std::string>(attribute.value)));
								break;
							case Titanium::UI::ATTRIBUTE_TYPE::FONT: 
							{
								const auto font = Titanium::UI::js_to_Font(static_cast<JSObject>(attribute.value));
								TitaniumWindows::UI::ViewHelper::SetFont<Windows::UI::Xaml::Documents::Span^>(get_context(), span, font);
								break;
							}
							case Titanium::UI::ATTRIBUTE_TYPE::EXPANSION:
							{
								const auto value = static_cast<double>(attribute.value);
								if (value <= -0.5) {
									run->FontStretch = FontStretch::UltraCondensed;
								} else if (value <= -0.375) {
									run->FontStretch = FontStretch::ExtraCondensed;
								} else if (value <= -0.25) {
									run->FontStretch = FontStretch::Condensed;
								} else if (value <= -0.125) {
									run->FontStretch = FontStretch::SemiCondensed;
								} else if (value <= 0) {
									run->FontStretch = FontStretch::Normal;
								} else if (value <= 0.125) {
									run->FontStretch = FontStretch::SemiExpanded;
								} else if (value <= 0.25) {
									run->FontStretch = FontStretch::Expanded;
								} else if (value <= 0.50) {
									run->FontStretch = FontStretch::ExtraExpanded;
								} else if (value <= 1.0) {
									run->FontStretch = FontStretch::UltraExpanded;
								}
								break;
							}
							case Titanium::UI::ATTRIBUTE_TYPE::WRITING_DIRECTION:
								if (attribute_styles.find(Titanium::UI::ATTRIBUTE_STYLE::WRITING_DIRECTION_LEFT_TO_RIGHT) != attribute_styles.end()) {
									run->FlowDirection = FlowDirection::LeftToRight;
								} else if (attribute_styles.find(Titanium::UI::ATTRIBUTE_STYLE::WRITING_DIRECTION_RIGHT_TO_LEFT) != attribute_styles.end()) {
									run->FlowDirection = FlowDirection::RightToLeft;
								}
								break;
							case Titanium::UI::ATTRIBUTE_TYPE::KERN:
								run->CharacterSpacing = static_cast<std::int32_t>(attribute.value);
								Typography::SetKerning(label__, true);
								break;
							case Titanium::UI::ATTRIBUTE_TYPE::LIGATURE:
							{
								// range is ignored here, because Ligature affects entire text on TextBlock
								const auto value = static_cast<std::uint32_t>(attribute.value);
								Typography::SetStandardLigatures(label__, (value == 1 ? true : false));
								break;
							}
							}
						}
					}

					span->Inlines->Append(run);
					root->Inlines->Append(span);
					pos += length;
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
