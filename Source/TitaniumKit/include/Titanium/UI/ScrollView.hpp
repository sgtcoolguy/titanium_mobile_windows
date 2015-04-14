/**
 * TitaniumKit
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_UI_SCROLLVIEW_HPP_
#define _TITANIUM_UI_SCROLLVIEW_HPP_

#include "Titanium/UI/View.hpp"

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		/*!
		  @class

		  @discussion This is the Titanium UI ScrollView.

		  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.UI.ScrollView
		*/
		class TITANIUMKIT_EXPORT ScrollView : public View, public JSExport<ScrollView>
		{
		public:
			virtual void scrollTo(double x, double y) TITANIUM_NOEXCEPT;
			virtual void scrollToBottom() TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract contentWidth : Number/String

			  @discussion Width of the scrollable region.

			  While auto and absolute dimensions are supported, relative values, such as those provided in percentages, are not. The minimum value for contentWidth is the width of the scroll view.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, contentWidth);
			virtual void set_contentWidth(const double& width) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract contentHeight : Number/String

			  @discussion Height of the scrollable region.

			  While auto and absolute dimensions are supported, relative values, such as those provided in percentages, are not. The minimum value for contentHeight is the height of the scroll view.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, contentHeight);
			virtual void set_contentHeight(const double& height) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract scrollingEnabled : Boolean

			  @discussion Determines whether scrolling is enabled for the view.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, scrollingEnabled);

			/*!
			  @method

			  @abstract showHorizontalScrollIndicator : Boolean

			  @discussion Determines whether the horizontal scroll indicator is visible.

			  Set to true to show the horizontal scroll indicator.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, showHorizontalScrollIndicator);

			/*!
			  @method

			  @abstract showVerticalScrollIndicator : Boolean

			  @discussion Determines whether the vertical scroll indicator is visible.

			  Set to true to show the vertical scroll indicator.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, showVerticalScrollIndicator);

			ScrollView(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~ScrollView() = default;
			ScrollView(const ScrollView&) = default;
			ScrollView& operator=(const ScrollView&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			ScrollView(ScrollView&&) = default;
			ScrollView& operator=(ScrollView&&) = default;
#endif

			static void JSExportInitialize();

			TITANIUM_PROPERTY_DEF(contentWidth);
			TITANIUM_FUNCTION_DEF(setContentWidth);
			TITANIUM_FUNCTION_DEF(getContentWidth);

			TITANIUM_PROPERTY_DEF(contentHeight);
			TITANIUM_FUNCTION_DEF(setContentHeight);
			TITANIUM_FUNCTION_DEF(getContentHeight);

			TITANIUM_FUNCTION_DEF(scrollTo);
			TITANIUM_FUNCTION_DEF(scrollToBottom);

			TITANIUM_PROPERTY_DEF(scrollingEnabled);
			TITANIUM_FUNCTION_DEF(setScrollingEnabled);
			TITANIUM_FUNCTION_DEF(getScrollingEnabled);

			TITANIUM_PROPERTY_DEF(showHorizontalScrollIndicator);
			TITANIUM_FUNCTION_DEF(setShowHorizontalScrollIndicator);
			TITANIUM_FUNCTION_DEF(getShowHorizontalScrollIndicator);

			TITANIUM_PROPERTY_DEF(showVerticalScrollIndicator);
			TITANIUM_FUNCTION_DEF(setShowVerticalScrollIndicator);
			TITANIUM_FUNCTION_DEF(getShowVerticalScrollIndicator);

		private:
		};
	} // namespace UI
}  // namespace Titanium

#endif  // _TITANIUM_UI_SCROLLVIEW_HPP_
