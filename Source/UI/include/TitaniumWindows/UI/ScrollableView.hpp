/**
 * Titanium.UI.ScrollableView for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_SCROLLABLEVIEW_HPP_
#define _TITANIUMWINDOWS_SCROLLABLEVIEW_HPP_

#include "TitaniumWindows/UI/detail/UIBase.hpp"
#include "Titanium/UI/ScrollableView.hpp"
#include "TitaniumWindows/UI/WindowsViewLayoutDelegate.hpp"

namespace TitaniumWindows
{
	namespace UI
	{

		using namespace HAL;

		class TITANIUMWINDOWS_UI_EXPORT ScrollableViewLayoutDelegate : public WindowsViewLayoutDelegate {
		public:
			ScrollableViewLayoutDelegate(const std::shared_ptr<WindowsViewLayoutDelegate>&) TITANIUM_NOEXCEPT;
			virtual ~ScrollableViewLayoutDelegate() = default;

			void requestLayout(const bool& fire_event) override;

			void setScrollablePageCount(const std::uint32_t& count) {
				pageCount__ = count;
			}

		protected:
#pragma warning(push)
#pragma warning(disable : 4251)
			std::shared_ptr<WindowsViewLayoutDelegate> contentView__;
			std::uint32_t pageCount__ { 1 };
#pragma warning(pop)
		};

		/*!
		  @class

		  @discussion This is the Titanium.UI.ScrollableView implementation for Windows.
		*/
		class TITANIUMWINDOWS_UI_EXPORT ScrollableView final : public Titanium::UI::ScrollableView, public JSExport<ScrollableView>
		{

		public:
			ScrollableView(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~ScrollableView()                        = default;
			ScrollableView(const ScrollableView&)            = default;
			ScrollableView& operator=(const ScrollableView&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			ScrollableView(ScrollableView&&)                 = default;
			ScrollableView& operator=(ScrollableView&&)      = default;
#endif

			static void JSExportInitialize();
			virtual void postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) override;

			virtual void addView(const std::shared_ptr<View>& view) TITANIUM_NOEXCEPT override;

		private:
			Windows::UI::Xaml::Controls::ScrollViewer^ scroll_viewer__;
			JSObject contentView__;

		};
	}  // namespace UI
}  // namespace TitaniumWindows
#endif // _TITANIUMWINDOWS_SCROLLABLEVIEW_HPP_