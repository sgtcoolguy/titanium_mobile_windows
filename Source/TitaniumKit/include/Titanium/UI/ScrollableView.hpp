/**
 * TitaniumKit Titanium.UI.ScrollableView
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_UI_SCROLLABLEVIEW_HPP_
#define _TITANIUM_UI_SCROLLABLEVIEW_HPP_

#include "Titanium/Module.hpp"
#include "Titanium/UI/Dimension.hpp"
#include "Titanium/UI/View.hpp"

namespace Titanium
{
	namespace UI
	{

		using namespace HAL;

		/*!
		  @class
		  @discussion This is the Titanium ScrollableView Module.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.UI.ScrollableView
		*/
		class TITANIUMKIT_EXPORT ScrollableView : public View, public JSExport<ScrollableView>
		{

		public:

			/*!
			  @property
			  @abstract cacheSize
			  @discussion Number of pages to cache (pre-render).
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::uint32_t, cacheSize);

			/*!
			  @property
			  @abstract currentPage
			  @discussion Index of the active page.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::uint32_t, currentPage);

			/*!
			  @property
			  @abstract disableBounce
			  @discussion Determines whether page bouncing effect is disabled.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, disableBounce);

			/*!
			  @property
			  @abstract overScrollMode
			  @discussion Determines the behavior when the user overscolls the view.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(JSValue, overScrollMode);

			/*!
			  @property
			  @abstract pagingControlColor
			  @discussion Color of the paging control, as a color name or hex triplet.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, pagingControlColor);

			/*!
			  @property
			  @abstract pagingControlHeight
			  @discussion Height of the paging control, in pixels.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::uint32_t, pagingControlHeight);

			/*!
			  @property
			  @abstract showPagingControl
			  @discussion Determines whether the paging control is visible.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, showPagingControl);

			/*!
			  @property
			  @abstract pagingControlTimeout
			  @discussion Number of milliseconds to wait before hiding the paging control.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::uint32_t, pagingControlTimeout);

			/*!
			  @property
			  @abstract pagingControlAlpha
			  @discussion Alpha value of the paging control.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(double, pagingControlAlpha);

			/*!
			  @property
			  @abstract pagingControlOnTop
			  @discussion Determines whether the paging control is displayed at the top or bottom of the view.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, pagingControlOnTop);

			/*!
			  @property
			  @abstract overlayEnabled
			  @discussion Determines whether the paging control is added as an overlay to the view.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, overlayEnabled);

			/*!
			  @property
			  @abstract scrollingEnabled
			  @discussion Determines whether scrolling is enabled for the view.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, scrollingEnabled);

			/*!
			  @property
			  @abstract views
			  @discussion Sets the pages within this Scrollable View.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::vector<std::shared_ptr<View>>, views);

			/*!
			  @property
			  @abstract clipViews
			  @discussion Determines whether the previous and next pages are clipped, so that they are not visible adjacent to the current page.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, clipViews);

			/*!
			  @property
			  @abstract hitRect
			  @discussion Sets the region where this view responds to gestures.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(Dimension, hitRect);

			/*!
			  @method
			  @abstract addView
			  @discussion Adds a new page to this Scrollable View.
			*/
			virtual void addView(const std::shared_ptr<View>& view) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract moveNext
			  @discussion Sets the current page to the next consecutive page in <Titanium.UI.ScrollableView.views>.
			*/
			virtual void moveNext() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract movePrevious
			  @discussion Sets the current page to the previous consecutive page in <Titanium.UI.ScrollableView.views>.
			*/
			virtual void movePrevious() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract removeView
			  @discussion Removes an existing page from this Scrollable View.
			*/
			virtual void removeView(const std::shared_ptr<View>& view) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract scrollToView
			  @discussion Scrolls to the specified page in <Titanium.UI.ScrollableView.views>.
			*/
			virtual void scrollToView(const std::shared_ptr<View>& view) TITANIUM_NOEXCEPT;

			ScrollableView(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~ScrollableView() = default;
			ScrollableView(const ScrollableView&) = default;
			ScrollableView& operator=(const ScrollableView&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			ScrollableView(ScrollableView&&)                 = default;
			ScrollableView& operator=(ScrollableView&&)      = default;
#endif

			static void JSExportInitialize();

			TITANIUM_PROPERTY_DEF(cacheSize);
			TITANIUM_PROPERTY_DEF(currentPage);
			TITANIUM_PROPERTY_DEF(disableBounce);
			TITANIUM_PROPERTY_DEF(overScrollMode);
			TITANIUM_PROPERTY_DEF(pagingControlColor);
			TITANIUM_PROPERTY_DEF(pagingControlHeight);
			TITANIUM_PROPERTY_DEF(showPagingControl);
			TITANIUM_PROPERTY_DEF(pagingControlTimeout);
			TITANIUM_PROPERTY_DEF(pagingControlAlpha);
			TITANIUM_PROPERTY_DEF(pagingControlOnTop);
			TITANIUM_PROPERTY_DEF(overlayEnabled);
			TITANIUM_PROPERTY_DEF(scrollingEnabled);
			TITANIUM_PROPERTY_DEF(views);
			TITANIUM_PROPERTY_DEF(clipViews);
			TITANIUM_PROPERTY_DEF(hitRect);

			TITANIUM_FUNCTION_DEF(addView);
			TITANIUM_FUNCTION_DEF(moveNext);
			TITANIUM_FUNCTION_DEF(movePrevious);
			TITANIUM_FUNCTION_DEF(removeView);
			TITANIUM_FUNCTION_DEF(scrollToView);
			TITANIUM_FUNCTION_DEF(getCacheSize);
			TITANIUM_FUNCTION_DEF(setCacheSize);
			TITANIUM_FUNCTION_DEF(getCurrentPage);
			TITANIUM_FUNCTION_DEF(setCurrentPage);
			TITANIUM_FUNCTION_DEF(getDisableBounce);
			TITANIUM_FUNCTION_DEF(setDisableBounce);
			TITANIUM_FUNCTION_DEF(getOverScrollMode);
			TITANIUM_FUNCTION_DEF(setOverScrollMode);
			TITANIUM_FUNCTION_DEF(getPagingControlColor);
			TITANIUM_FUNCTION_DEF(setPagingControlColor);
			TITANIUM_FUNCTION_DEF(getPagingControlHeight);
			TITANIUM_FUNCTION_DEF(setPagingControlHeight);
			TITANIUM_FUNCTION_DEF(getShowPagingControl);
			TITANIUM_FUNCTION_DEF(setShowPagingControl);
			TITANIUM_FUNCTION_DEF(getPagingControlTimeout);
			TITANIUM_FUNCTION_DEF(setPagingControlTimeout);
			TITANIUM_FUNCTION_DEF(getPagingControlAlpha);
			TITANIUM_FUNCTION_DEF(setPagingControlAlpha);
			TITANIUM_FUNCTION_DEF(getPagingControlOnTop);
			TITANIUM_FUNCTION_DEF(setPagingControlOnTop);
			TITANIUM_FUNCTION_DEF(getOverlayEnabled);
			TITANIUM_FUNCTION_DEF(setOverlayEnabled);
			TITANIUM_FUNCTION_DEF(getScrollingEnabled);
			TITANIUM_FUNCTION_DEF(setScrollingEnabled);
			TITANIUM_FUNCTION_DEF(getViews);
			TITANIUM_FUNCTION_DEF(setViews);
			TITANIUM_FUNCTION_DEF(getClipViews);
			TITANIUM_FUNCTION_DEF(setClipViews);
			TITANIUM_FUNCTION_DEF(getHitRect);
			TITANIUM_FUNCTION_DEF(setHitRect);

		protected:
#pragma warning(push)
#pragma warning(disable : 4251)
			std::uint32_t cacheSize__;
			std::uint32_t currentPage__;
			bool disableBounce__;
			JSValue overScrollMode__;
			std::string pagingControlColor__;
			std::uint32_t pagingControlHeight__;
			bool showPagingControl__;
			std::uint32_t pagingControlTimeout__;
			double pagingControlAlpha__;
			bool pagingControlOnTop__;
			bool overlayEnabled__;
			bool scrollingEnabled__;
			std::vector<std::shared_ptr<View>> views__;
			bool clipViews__;
			Dimension hitRect__;
#pragma warning(pop)
		};

	} // namespace UI
} // namespace Titanium
#endif // _TITANIUM_UI_SCROLLABLEVIEW_HPP_