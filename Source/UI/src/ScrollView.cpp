/**
* Titanium.UI.ScrollView for Windows
*
* Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/

#include "TitaniumWindows/UI/ScrollView.hpp"
#include "TitaniumWindows/UI/View.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		void ScrollView::setupViewer()
		{
			using namespace Windows::UI::Xaml::Controls;
			scroll_viewer__->HorizontalScrollBarVisibility = ScrollBarVisibility::Auto;
			scroll_viewer__->VerticalScrollBarVisibility = ScrollBarVisibility::Auto;
			scroll_viewer__->HorizontalScrollMode = ScrollMode::Enabled;
			scroll_viewer__->VerticalScrollMode = ScrollMode::Enabled;

			contentView__.SetProperty("top", get_context().CreateNumber(0));
			contentView__.SetProperty("left", get_context().CreateNumber(0));
			contentView__.SetProperty("width", get_context().CreateString("Ti.UI.FILL"));
			contentView__.SetProperty("height", get_context().CreateString("Ti.UI.FILL"));

			auto content = contentView__.GetPrivate<TitaniumWindows::UI::View>();
			scroll_viewer__->Content = content->getComponent();

			View::add(contentView__, get_context().CreateObject());
		}

		ScrollView::ScrollView(const JSContext& js_context) TITANIUM_NOEXCEPT
		    : Titanium::UI::ScrollView(js_context),
		      scroll_viewer__(ref new Windows::UI::Xaml::Controls::ScrollViewer()),
		      contentView__(js_context.CreateObject(JSExport<TitaniumWindows::UI::View>::Class()).CallAsConstructor())
		{
			TITANIUM_LOG_DEBUG("ScrollView::ctor Initialize");
		}

		ScrollView::ScrollView(const ScrollView& rhs, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
		    : Titanium::UI::ScrollView(rhs, arguments),
		      scroll_viewer__(ref new Windows::UI::Xaml::Controls::ScrollViewer()),
		      contentView__(get_context().CreateObject(JSExport<TitaniumWindows::UI::View>::Class()).CallAsConstructor())
		{
			TITANIUM_LOG_DEBUG("ScrollView::ctor CallAsConstructor");
			setupViewer();
			setComponent(scroll_viewer__);
		}

		void ScrollView::JSExportInitialize()
		{
			JSExport<ScrollView>::SetClassVersion(1);
			JSExport<ScrollView>::SetParent(JSExport<Titanium::UI::ScrollView>::Class());
		}

		void ScrollView::add(const JSObject& view, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			auto content = std::dynamic_pointer_cast<TitaniumWindows::UI::View>(contentView__.GetPrivate<Titanium::UI::View>());
			content->add(view, this_object);
		}

		void ScrollView::set_backgroundColor(const std::string& backgroundColorName) TITANIUM_NOEXCEPT
		{
			Titanium::UI::View::set_backgroundColor(backgroundColorName);
			const auto backgroundColor = ColorForName(backgroundColorName);
			scroll_viewer__->Background = ref new Windows::UI::Xaml::Media::SolidColorBrush(backgroundColor);
		}

		void ScrollView::scrollTo(double x, double y)
		{
			scroll_viewer__->ChangeView(
			    ref new Platform::Box<double>(x),
			    ref new Platform::Box<double>(y),
			    nullptr,
			    false);
		}

		void ScrollView::scrollToBottom()
		{
			scroll_viewer__->ChangeView(nullptr, ref new Platform::Box<double>(scroll_viewer__->ScrollableHeight), nullptr);
		}

		std::string ScrollView::get_contentWidth() const
		{
			auto content = std::dynamic_pointer_cast<TitaniumWindows::UI::View>(contentView__.GetPrivate<Titanium::UI::View>());
			return content->get_width();
		}

		std::string ScrollView::get_contentHeight() const
		{
			auto content = std::dynamic_pointer_cast<TitaniumWindows::UI::View>(contentView__.GetPrivate<Titanium::UI::View>());
			return content->get_height();
		}

		bool ScrollView::set_contentWidth(const double& width)
		{
			auto content = std::dynamic_pointer_cast<TitaniumWindows::UI::View>(contentView__.GetPrivate<Titanium::UI::View>());
			bool result = false;
			content->getComponent()->Width = width;
			result = true;
			return result;
		}

		bool ScrollView::set_contentHeight(const double& height)
		{
			auto content = std::dynamic_pointer_cast<TitaniumWindows::UI::View>(contentView__.GetPrivate<Titanium::UI::View>());
			bool result = false;
			content->getComponent()->Height = height;
			result = true;
			return result;
		}

		bool ScrollView::get_scrollingEnabled() const TITANIUM_NOEXCEPT
		{
			return scroll_viewer__->HorizontalScrollMode != Windows::UI::Xaml::Controls::ScrollMode::Disabled;
		}

		bool ScrollView::set_scrollingEnabled(bool enabled) TITANIUM_NOEXCEPT
		{
			if (enabled) {
				scroll_viewer__->HorizontalScrollMode = Windows::UI::Xaml::Controls::ScrollMode::Auto;
			} else {
				scroll_viewer__->HorizontalScrollMode = Windows::UI::Xaml::Controls::ScrollMode::Disabled;
			}
			return true;
		}

		bool ScrollView::get_showHorizontalScrollIndicator() const TITANIUM_NOEXCEPT
		{
			return scroll_viewer__->HorizontalScrollBarVisibility != Windows::UI::Xaml::Controls::ScrollBarVisibility::Hidden;
		}

		bool ScrollView::set_showHorizontalScrollIndicator(bool enabled) TITANIUM_NOEXCEPT
		{
			if (enabled) {
				scroll_viewer__->HorizontalScrollBarVisibility = Windows::UI::Xaml::Controls::ScrollBarVisibility::Auto;
			} else {
				scroll_viewer__->HorizontalScrollBarVisibility = Windows::UI::Xaml::Controls::ScrollBarVisibility::Hidden;
			}
			return true;
		}

		bool ScrollView::get_showVerticalScrollIndicator() const TITANIUM_NOEXCEPT
		{
			return scroll_viewer__->VerticalScrollBarVisibility != Windows::UI::Xaml::Controls::ScrollBarVisibility::Hidden;
		}

		bool ScrollView::set_showVerticalScrollIndicator(bool enabled) TITANIUM_NOEXCEPT
		{
			if (enabled) {
				scroll_viewer__->VerticalScrollBarVisibility = Windows::UI::Xaml::Controls::ScrollBarVisibility::Auto;
			} else {
				scroll_viewer__->VerticalScrollBarVisibility = Windows::UI::Xaml::Controls::ScrollBarVisibility::Hidden;
			}
			return true;
		}
	} // namespace UI
} // namespace TitaniumWindows
