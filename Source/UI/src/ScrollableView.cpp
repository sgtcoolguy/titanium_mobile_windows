/**
 * Titanium.UI.ScrollableView for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/UI/ScrollableView.hpp"
#include "TitaniumWindows/UI/View.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		using namespace Windows::UI::Xaml::Controls;

		ScrollableViewLayoutDelegate::ScrollableViewLayoutDelegate(const std::shared_ptr<WindowsViewLayoutDelegate>& contentView) TITANIUM_NOEXCEPT
			: WindowsViewLayoutDelegate()
			, contentView__(contentView)
		{

		}

		void ScrollableViewLayoutDelegate::requestLayout(const bool& fire_event)
		{
			WindowsViewLayoutDelegate::requestLayout(fire_event);

			const auto contentWidth = getComponent()->Width * pageCount__;
			contentView__->getComponent()->Width = contentWidth;
		}

		void ScrollableView::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) {
			using namespace Windows::UI::Xaml::Controls;

			Titanium::UI::ScrollableView::postCallAsConstructor(js_context, arguments);

			scroll_viewer__ = ref new Windows::UI::Xaml::Controls::ScrollViewer();

			scroll_viewer__->HorizontalScrollBarVisibility = ScrollBarVisibility::Visible;
			scroll_viewer__->VerticalScrollBarVisibility = ScrollBarVisibility::Visible;
			scroll_viewer__->HorizontalScrollMode = ScrollMode::Enabled;
			scroll_viewer__->VerticalScrollMode = ScrollMode::Enabled;

			contentView__.SetProperty("layout", get_context().CreateString("horizontal"));
			contentView__.SetProperty("top", get_context().CreateNumber(0));
			contentView__.SetProperty("left", get_context().CreateNumber(0));
			contentView__.SetProperty("width", get_context().CreateString(Titanium::UI::Constants::to_string(Titanium::UI::LAYOUT::SIZE)));
			contentView__.SetProperty("height", get_context().CreateString(Titanium::UI::Constants::to_string(Titanium::UI::LAYOUT::SIZE)));

			auto content = contentView__.GetPrivate<TitaniumWindows::UI::View>();
			scroll_viewer__->Content = content->getComponent();
			auto contentLayoutDelegate = content->getViewLayoutDelegate<WindowsViewLayoutDelegate>();

			Titanium::UI::ScrollableView::setLayoutDelegate<ScrollableViewLayoutDelegate>(contentLayoutDelegate);

			layoutDelegate__->set_defaultHeight(Titanium::UI::LAYOUT::FILL);
			layoutDelegate__->set_defaultWidth(Titanium::UI::LAYOUT::FILL);

			auto layoutDelegate = getViewLayoutDelegate<WindowsViewLayoutDelegate>();
			layoutDelegate->setComponent(scroll_viewer__);

			auto nativeChildView = content->getComponent();
			if (nativeChildView != nullptr) {
				Titanium::LayoutEngine::nodeAddChild(layoutDelegate->getLayoutNode(), contentLayoutDelegate->getLayoutNode());
				if (layoutDelegate->isLoaded()) {
					layoutDelegate->requestLayout();
				}
			} else {
				TITANIUM_LOG_WARN("ScrollableView: nativeChildView = nullptr");
			}
		}

		void ScrollableView::addView(const std::shared_ptr<View>& view) TITANIUM_NOEXCEPT
		{
			Titanium::UI::ScrollableView::addView(view);

			getViewLayoutDelegate<ScrollableViewLayoutDelegate>()->setScrollablePageCount(views__.size());

			auto content = contentView__.GetPrivate<TitaniumWindows::UI::View>();
			auto layout  = content->getViewLayoutDelegate<WindowsViewLayoutDelegate>();

			layout->add(view);
		}

		ScrollableView::ScrollableView(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::UI::ScrollableView(js_context)
			, contentView__(get_context().CreateObject(JSExport<TitaniumWindows::UI::View>::Class()).CallAsConstructor())
		{
			TITANIUM_LOG_DEBUG("ScrollableView::ctor Initialize");
		}

		void ScrollableView::JSExportInitialize() 
		{
			JSExport<ScrollableView>::SetClassVersion(1);
			JSExport<ScrollableView>::SetParent(JSExport<Titanium::UI::ScrollableView>::Class());
		}

	}  // namespace UI
}  // namespace TitaniumWindows