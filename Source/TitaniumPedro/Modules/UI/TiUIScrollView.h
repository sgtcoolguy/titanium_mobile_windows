/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#ifndef __TI_UI_SCROLLVIEW_PROXY_H__
#define __TI_UI_SCROLLVIEW_PROXY_H__

#include "TiCore/TiViewProxy.h"

namespace Ti {
	namespace UI {
		class ScrollView : public ViewProxy, public virtual_enable_shared_from_this < ScrollView > {

			TI_CREATE_PROXY(ScrollView)
			static JSClassRef Parent() { return Ti::ViewProxy::ClassDef(); }
		public:
			virtual std::string defaultHeight() const{ return Ti::Constants::SizeFILL; }
			virtual std::string defaultWidth() const { return Ti::Constants::SizeFILL; }
			// Events
			virtual Ti::Value eventAdded(const std::vector<Ti::Value>&);
			virtual Ti::Value eventRemoved(const std::vector<Ti::Value>&);

		protected:
			ScrollView(const std::string&, const std::vector<Ti::Value>&);
			virtual ~ScrollView();

			// JavaScript's public API

			// Sets the content view
			Ti::Value setContentView(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(ScrollView, setContentView);
			// Sets the value of the canCancelEvents property.
			Ti::Value setCanCancelEvents(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(ScrollView, setCanCancelEvents);
			// Sets the value of the contentOffset property.
			Ti::Value setContentOffset(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(ScrollView, setContentOffset);
			// Gets the value of the contentOffset property.
			Ti::Value getContentOffset(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(ScrollView, getContentOffset);
			/*
			 * http://stackoverflow.com/a/17280166/795295	
			 * // Sets the value of the disableBounce property.
			 * Ti::Value setDisableBounce(const std::vector<Ti::Value>& args);
			 * TI_CREATE_METHOD(ScrollView, setDisableBounce);
			 * // Gets the value of the disableBounce property.
			 * Ti::Value getDisableBounce(const std::vector<Ti::Value>& args);
			 * TI_CREATE_METHOD(ScrollView, getDisableBounce);
			 * // Sets the value of the horizontalBounce property.
			 * Ti::Value setHorizontalBounce(const std::vector<Ti::Value>& args);
			 * TI_CREATE_METHOD(ScrollView, setHorizontalBounce);
			 * // Gets the value of the horizontalBounce property.
			 * Ti::Value getHorizontalBounce(const std::vector<Ti::Value>& args);
			 * TI_CREATE_METHOD(ScrollView, getHorizontalBounce);
			 * // Sets the value of the verticalBounce property.
			 * Ti::Value setVerticalBounce(const std::vector<Ti::Value>& args);
			 * TI_CREATE_METHOD(ScrollView, setVerticalBounce);
			 * // Gets the value of the verticalBounce property.
			 * Ti::Value getVerticalBounce(const std::vector<Ti::Value>& args);
			 * TI_CREATE_METHOD(ScrollView, getVerticalBounce);
			 */
			// Sets the value of the maxZoomScale property.
			Ti::Value setMaxZoomScale(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(ScrollView, setMaxZoomScale);
			// Gets the value of the maxZoomScale property.
			Ti::Value getMaxZoomScale(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(ScrollView, getMaxZoomScale);
			// Sets the value of the minZoomScale property.
			Ti::Value setMinZoomScale(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(ScrollView, setMinZoomScale);
			// Gets the value of the minZoomScale property.
			Ti::Value getMinZoomScale(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(ScrollView, getMinZoomScale);
			// Gets the value of the scrollType property.
			Ti::Value setScrollingEnabled(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(ScrollView, setScrollingEnabled);
			// Gets the value of the scrollingEnabled property.
			Ti::Value getScrollingEnabled(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(ScrollView, getScrollingEnabled);
			// Sets the value of the showHorizontalScrollIndicator property.
			Ti::Value setShowHorizontalScrollIndicator(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(ScrollView, setShowHorizontalScrollIndicator);
			// Gets the value of the showHorizontalScrollIndicator property.
			Ti::Value getShowHorizontalScrollIndicator(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(ScrollView, getShowHorizontalScrollIndicator);
			// Sets the value of the showVerticalScrollIndicator property.
			Ti::Value setShowVerticalScrollIndicator(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(ScrollView, setShowVerticalScrollIndicator);
			// Gets the value of the showVerticalScrollIndicator property.
			Ti::Value getShowVerticalScrollIndicator(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(ScrollView, getShowVerticalScrollIndicator);
			// Sets the value of the zoomScale property.
			Ti::Value setZoomScale(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(ScrollView, setZoomScale);
			// Gets the value of the zoomScale property.
			Ti::Value getZoomScale(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(ScrollView, getZoomScale);
			// Moves the specified coordinate of the scrollable region into the viewable area.
			Ti::Value scrollTo(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(ScrollView, scrollTo);
			// Moves the end of the scrollable region into the viewable area.
			Ti::Value scrollToBottom(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(ScrollView, scrollToBottom);
		private:
			Windows::UI::Xaml::Controls::ScrollViewer^ scroll_viewer_;
			// private members go here
		};
	}
}
#endif // defined(__TI_UI_SCROLLVIEW_PROXY_H__)