/**
 * TitaniumKit Titanium.UI.ScrollableView
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/ScrollableView.hpp"

namespace Titanium
{
	namespace UI
	{


		ScrollableView::ScrollableView(const JSContext& js_context) TITANIUM_NOEXCEPT
			: View(js_context),
			cacheSize__(0),
			currentPage__(0),
			disableBounce__(false),
			pagingControlColor__("Black"),
			pagingControlHeight__(20),
			showPagingControl__(false),
			pagingControlTimeout__(3000),
			pagingControlAlpha__(1),
			pagingControlOnTop__(false),
			overlayEnabled__(false),
			scrollingEnabled__(false),
			overScrollMode__(js_context.CreateNull()),
			clipViews__(true)
		{
		}

		TITANIUM_PROPERTY_READWRITE(ScrollableView, std::uint32_t, cacheSize)
		TITANIUM_PROPERTY_READWRITE(ScrollableView, std::uint32_t, currentPage)
		TITANIUM_PROPERTY_READWRITE(ScrollableView, bool, disableBounce)
		TITANIUM_PROPERTY_READWRITE(ScrollableView, JSValue, overScrollMode)
		TITANIUM_PROPERTY_READWRITE(ScrollableView, std::string, pagingControlColor)
		TITANIUM_PROPERTY_READWRITE(ScrollableView, std::uint32_t, pagingControlHeight)
		TITANIUM_PROPERTY_READWRITE(ScrollableView, bool, showPagingControl)
		TITANIUM_PROPERTY_READWRITE(ScrollableView, std::uint32_t, pagingControlTimeout)
		TITANIUM_PROPERTY_READWRITE(ScrollableView, double, pagingControlAlpha)
		TITANIUM_PROPERTY_READWRITE(ScrollableView, bool, pagingControlOnTop)
		TITANIUM_PROPERTY_READWRITE(ScrollableView, bool, overlayEnabled)
		TITANIUM_PROPERTY_READWRITE(ScrollableView, bool, scrollingEnabled)
		TITANIUM_PROPERTY_READWRITE(ScrollableView, std::vector<std::shared_ptr<View>>, views)
		TITANIUM_PROPERTY_READWRITE(ScrollableView, bool, clipViews)
		TITANIUM_PROPERTY_READWRITE(ScrollableView, Dimension, hitRect)

		void ScrollableView::addView(const std::shared_ptr<View>& view) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_DEBUG("ScrollableView::addView");
		}

		void ScrollableView::moveNext() TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_DEBUG("ScrollableView::moveNext");
		}

		void ScrollableView::movePrevious() TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_DEBUG("ScrollableView::movePrevious");
		}

		void ScrollableView::removeView(const std::shared_ptr<View>& view) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_DEBUG("ScrollableView::removeView");
		}

		void ScrollableView::scrollToView(const std::shared_ptr<View>& view) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_DEBUG("ScrollableView::scrollToView");
		}

		void ScrollableView::JSExportInitialize() 
		{
			JSExport<ScrollableView>::SetClassVersion(1);
			JSExport<ScrollableView>::SetParent(JSExport<View>::Class());

			TITANIUM_ADD_PROPERTY(ScrollableView, cacheSize);
			TITANIUM_ADD_PROPERTY(ScrollableView, currentPage);
			TITANIUM_ADD_PROPERTY(ScrollableView, disableBounce);
			TITANIUM_ADD_PROPERTY(ScrollableView, overScrollMode);
			TITANIUM_ADD_PROPERTY(ScrollableView, pagingControlColor);
			TITANIUM_ADD_PROPERTY(ScrollableView, pagingControlHeight);
			TITANIUM_ADD_PROPERTY(ScrollableView, showPagingControl);
			TITANIUM_ADD_PROPERTY(ScrollableView, pagingControlTimeout);
			TITANIUM_ADD_PROPERTY(ScrollableView, pagingControlAlpha);
			TITANIUM_ADD_PROPERTY(ScrollableView, pagingControlOnTop);
			TITANIUM_ADD_PROPERTY(ScrollableView, overlayEnabled);
			TITANIUM_ADD_PROPERTY(ScrollableView, scrollingEnabled);
			TITANIUM_ADD_PROPERTY(ScrollableView, views);
			TITANIUM_ADD_PROPERTY(ScrollableView, clipViews);
			TITANIUM_ADD_PROPERTY(ScrollableView, hitRect);

			TITANIUM_ADD_FUNCTION(ScrollableView, addView);
			TITANIUM_ADD_FUNCTION(ScrollableView, moveNext);
			TITANIUM_ADD_FUNCTION(ScrollableView, movePrevious);
			TITANIUM_ADD_FUNCTION(ScrollableView, removeView);
			TITANIUM_ADD_FUNCTION(ScrollableView, scrollToView);
			TITANIUM_ADD_FUNCTION(ScrollableView, getCacheSize);
			TITANIUM_ADD_FUNCTION(ScrollableView, setCacheSize);
			TITANIUM_ADD_FUNCTION(ScrollableView, getCurrentPage);
			TITANIUM_ADD_FUNCTION(ScrollableView, setCurrentPage);
			TITANIUM_ADD_FUNCTION(ScrollableView, getDisableBounce);
			TITANIUM_ADD_FUNCTION(ScrollableView, setDisableBounce);
			TITANIUM_ADD_FUNCTION(ScrollableView, getOverScrollMode);
			TITANIUM_ADD_FUNCTION(ScrollableView, setOverScrollMode);
			TITANIUM_ADD_FUNCTION(ScrollableView, getPagingControlColor);
			TITANIUM_ADD_FUNCTION(ScrollableView, setPagingControlColor);
			TITANIUM_ADD_FUNCTION(ScrollableView, getPagingControlHeight);
			TITANIUM_ADD_FUNCTION(ScrollableView, setPagingControlHeight);
			TITANIUM_ADD_FUNCTION(ScrollableView, getShowPagingControl);
			TITANIUM_ADD_FUNCTION(ScrollableView, setShowPagingControl);
			TITANIUM_ADD_FUNCTION(ScrollableView, getPagingControlTimeout);
			TITANIUM_ADD_FUNCTION(ScrollableView, setPagingControlTimeout);
			TITANIUM_ADD_FUNCTION(ScrollableView, getPagingControlAlpha);
			TITANIUM_ADD_FUNCTION(ScrollableView, setPagingControlAlpha);
			TITANIUM_ADD_FUNCTION(ScrollableView, getPagingControlOnTop);
			TITANIUM_ADD_FUNCTION(ScrollableView, setPagingControlOnTop);
			TITANIUM_ADD_FUNCTION(ScrollableView, getOverlayEnabled);
			TITANIUM_ADD_FUNCTION(ScrollableView, setOverlayEnabled);
			TITANIUM_ADD_FUNCTION(ScrollableView, getScrollingEnabled);
			TITANIUM_ADD_FUNCTION(ScrollableView, setScrollingEnabled);
			TITANIUM_ADD_FUNCTION(ScrollableView, getViews);
			TITANIUM_ADD_FUNCTION(ScrollableView, setViews);
			TITANIUM_ADD_FUNCTION(ScrollableView, getClipViews);
			TITANIUM_ADD_FUNCTION(ScrollableView, setClipViews);
			TITANIUM_ADD_FUNCTION(ScrollableView, getHitRect);
			TITANIUM_ADD_FUNCTION(ScrollableView, setHitRect);
		}

		TITANIUM_PROPERTY_GETTER(ScrollableView, cacheSize)
		{
			return get_context().CreateNumber(get_cacheSize());
		}

		TITANIUM_PROPERTY_SETTER(ScrollableView, cacheSize)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_cacheSize(static_cast<std::uint32_t>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ScrollableView, currentPage)
		{
			return get_context().CreateNumber(get_currentPage());
		}

		TITANIUM_PROPERTY_SETTER(ScrollableView, currentPage)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_currentPage(static_cast<std::uint32_t>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ScrollableView, disableBounce)
		{
			return get_context().CreateBoolean(get_disableBounce());
		}

		TITANIUM_PROPERTY_SETTER(ScrollableView, disableBounce)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_disableBounce(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ScrollableView, overScrollMode)
		{
			return get_overScrollMode();
		}

		TITANIUM_PROPERTY_SETTER(ScrollableView, overScrollMode)
		{
			set_overScrollMode(argument);
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ScrollableView, pagingControlColor)
		{
			return get_context().CreateString(get_pagingControlColor());
		}

		TITANIUM_PROPERTY_SETTER(ScrollableView, pagingControlColor)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_pagingControlColor(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ScrollableView, pagingControlHeight)
		{
			return get_context().CreateNumber(get_pagingControlHeight());
		}

		TITANIUM_PROPERTY_SETTER(ScrollableView, pagingControlHeight)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_pagingControlHeight(static_cast<std::uint32_t>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ScrollableView, showPagingControl)
		{
			return get_context().CreateBoolean(get_showPagingControl());
		}

		TITANIUM_PROPERTY_SETTER(ScrollableView, showPagingControl)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_showPagingControl(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ScrollableView, pagingControlTimeout)
		{
			return get_context().CreateNumber(get_pagingControlTimeout());
		}

		TITANIUM_PROPERTY_SETTER(ScrollableView, pagingControlTimeout)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_pagingControlTimeout(static_cast<std::uint32_t>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ScrollableView, pagingControlAlpha)
		{
			return get_context().CreateNumber(get_pagingControlAlpha());
		}

		TITANIUM_PROPERTY_SETTER(ScrollableView, pagingControlAlpha)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_pagingControlAlpha(static_cast<double>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ScrollableView, pagingControlOnTop)
		{
			return get_context().CreateBoolean(get_pagingControlOnTop());
		}

		TITANIUM_PROPERTY_SETTER(ScrollableView, pagingControlOnTop)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_pagingControlOnTop(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ScrollableView, overlayEnabled)
		{
			return get_context().CreateBoolean(get_overlayEnabled());
		}

		TITANIUM_PROPERTY_SETTER(ScrollableView, overlayEnabled)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_overlayEnabled(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ScrollableView, scrollingEnabled)
		{
			return get_context().CreateBoolean(get_scrollingEnabled());
		}

		TITANIUM_PROPERTY_SETTER(ScrollableView, scrollingEnabled)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_scrollingEnabled(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ScrollableView, views)
		{
			std::vector<JSValue> js_views;
			for (auto view : get_views()) {
				js_views.push_back(view->get_object());
			}
			return get_context().CreateArray(js_views);
		}

		TITANIUM_PROPERTY_SETTER(ScrollableView, views)
		{
			TITANIUM_ASSERT(argument.IsObject());
			auto js_arg = static_cast<JSObject>(argument);
			TITANIUM_ASSERT(js_arg.IsArray());

			auto views_obj = static_cast<JSArray>(js_arg);
			auto js_views = static_cast<std::vector<JSValue>>(views_obj);
			std::vector<std::shared_ptr<View>> views;
			for (auto view : js_views) {
				views.push_back(static_cast<JSObject>(view).GetPrivate<View>());
			}
			set_views(views);

			return true;
		}

		TITANIUM_PROPERTY_GETTER(ScrollableView, clipViews)
		{
			return get_context().CreateBoolean(get_clipViews());
		}

		TITANIUM_PROPERTY_SETTER(ScrollableView, clipViews)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_clipViews(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ScrollableView, hitRect)
		{
			return Dimension_to_js(get_context(), get_hitRect());
		}

		TITANIUM_PROPERTY_SETTER(ScrollableView, hitRect)
		{
			TITANIUM_ASSERT(argument.IsObject());
			set_hitRect(js_to_Dimension(static_cast<JSObject>(argument)));
			return true;
		}

		TITANIUM_FUNCTION(ScrollableView, addView)
		{
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}

			ENSURE_OBJECT_AT_INDEX(view, 0);
			addView(view.GetPrivate<View>());
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ScrollableView, moveNext)
		{
			moveNext();
			return get_context().CreateUndefined();
		}
		TITANIUM_FUNCTION(ScrollableView, movePrevious)
		{
			movePrevious();
			return get_context().CreateUndefined();
		}
		TITANIUM_FUNCTION(ScrollableView, removeView)
		{
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}

			ENSURE_OBJECT_AT_INDEX(view, 0);
			removeView(view.GetPrivate<View>());
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ScrollableView, scrollToView)
		{
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}

			ENSURE_OBJECT_AT_INDEX(view, 0);
			scrollToView(view.GetPrivate<View>());
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION_AS_GETTER(ScrollableView, getCacheSize, cacheSize)
		TITANIUM_FUNCTION_AS_SETTER(ScrollableView, setCacheSize, cacheSize)
		TITANIUM_FUNCTION_AS_GETTER(ScrollableView, getCurrentPage, currentPage)
		TITANIUM_FUNCTION_AS_SETTER(ScrollableView, setCurrentPage, currentPage)
		TITANIUM_FUNCTION_AS_GETTER(ScrollableView, getDisableBounce, disableBounce)
		TITANIUM_FUNCTION_AS_SETTER(ScrollableView, setDisableBounce, disableBounce)
		TITANIUM_FUNCTION_AS_GETTER(ScrollableView, getOverScrollMode, overScrollMode)
		TITANIUM_FUNCTION_AS_SETTER(ScrollableView, setOverScrollMode, overScrollMode)
		TITANIUM_FUNCTION_AS_GETTER(ScrollableView, getPagingControlColor, pagingControlColor)
		TITANIUM_FUNCTION_AS_SETTER(ScrollableView, setPagingControlColor, pagingControlColor)
		TITANIUM_FUNCTION_AS_GETTER(ScrollableView, getPagingControlHeight, pagingControlHeight)
		TITANIUM_FUNCTION_AS_SETTER(ScrollableView, setPagingControlHeight, pagingControlHeight)
		TITANIUM_FUNCTION_AS_GETTER(ScrollableView, getShowPagingControl, showPagingControl)
		TITANIUM_FUNCTION_AS_SETTER(ScrollableView, setShowPagingControl, showPagingControl)
		TITANIUM_FUNCTION_AS_GETTER(ScrollableView, getPagingControlTimeout, pagingControlTimeout)
		TITANIUM_FUNCTION_AS_SETTER(ScrollableView, setPagingControlTimeout, pagingControlTimeout)
		TITANIUM_FUNCTION_AS_GETTER(ScrollableView, getPagingControlAlpha, pagingControlAlpha)
		TITANIUM_FUNCTION_AS_SETTER(ScrollableView, setPagingControlAlpha, pagingControlAlpha)
		TITANIUM_FUNCTION_AS_GETTER(ScrollableView, getPagingControlOnTop, pagingControlOnTop)
		TITANIUM_FUNCTION_AS_SETTER(ScrollableView, setPagingControlOnTop, pagingControlOnTop)
		TITANIUM_FUNCTION_AS_GETTER(ScrollableView, getOverlayEnabled, overlayEnabled)
		TITANIUM_FUNCTION_AS_SETTER(ScrollableView, setOverlayEnabled, overlayEnabled)
		TITANIUM_FUNCTION_AS_GETTER(ScrollableView, getScrollingEnabled, scrollingEnabled)
		TITANIUM_FUNCTION_AS_SETTER(ScrollableView, setScrollingEnabled, scrollingEnabled)
		TITANIUM_FUNCTION_AS_GETTER(ScrollableView, getViews, views)
		TITANIUM_FUNCTION_AS_SETTER(ScrollableView, setViews, views)
		TITANIUM_FUNCTION_AS_GETTER(ScrollableView, getClipViews, clipViews)
		TITANIUM_FUNCTION_AS_SETTER(ScrollableView, setClipViews, clipViews)
		TITANIUM_FUNCTION_AS_GETTER(ScrollableView, getHitRect, hitRect)
		TITANIUM_FUNCTION_AS_SETTER(ScrollableView, setHitRect, hitRect)

	} // namespace UI
} // namespace Titanium