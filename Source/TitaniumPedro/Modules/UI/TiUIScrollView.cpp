/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#include "TiUIScrollView.h"
#include <Windows.h>

namespace Ti {
	namespace UI {
		// These are JavaScript methods they will call class methods
		const JSStaticFunction ScrollView::ClassMethods[] = {
				{ "setContentView", _setContentView, 0 },
				{ "setCanCancelEvents", _setCanCancelEvents, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setContentOffset", _setContentOffset, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getContentOffset", _getContentOffset, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				/*
				 * http://stackoverflow.com/a/17280166/795295
				 * { "setDisableBounce", _setDisableBounce, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				 * { "getDisableBounce", _getDisableBounce, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				 * { "setHorizontalBounce", _setHorizontalBounce, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				 * { "getHorizontalBounce", _getHorizontalBounce, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				 * { "setVerticalBounce", _setVerticalBounce, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				 * { "getVerticalBounce", _getVerticalBounce, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				 */
				{ "setMaxZoomScale", _setMaxZoomScale, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getMaxZoomScale", _getMaxZoomScale, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setMinZoomScale", _setMinZoomScale, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getMinZoomScale", _getMinZoomScale, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setScrollingEnabled", _setScrollingEnabled, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getScrollingEnabled", _getScrollingEnabled, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setShowHorizontalScrollIndicator", _setShowHorizontalScrollIndicator, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getShowHorizontalScrollIndicator", _getShowHorizontalScrollIndicator, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setShowVerticalScrollIndicator", _setShowVerticalScrollIndicator, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getShowVerticalScrollIndicator", _getShowVerticalScrollIndicator, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setZoomScale", _setZoomScale, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getZoomScale", _getZoomScale, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "scrollTo", _scrollTo, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "scrollToBottom", _scrollToBottom, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ 0, 0, 0 }
		};

		ScrollView::~ScrollView()
		{

		}
		ScrollView::ScrollView(const std::string& name, const std::vector<Ti::Value>& args) : Ti::ViewProxy(name, args)
		{
			using namespace Windows::UI::Xaml::Controls;
			scroll_viewer_ = ref new ScrollViewer();
			scroll_viewer_->HorizontalScrollBarVisibility = ScrollBarVisibility::Auto;
			scroll_viewer_->VerticalScrollBarVisibility = ScrollBarVisibility::Auto;
			scroll_viewer_->HorizontalScrollMode = ScrollMode::Enabled;
			scroll_viewer_->VerticalScrollMode = ScrollMode::Enabled;
			setComponent(scroll_viewer_);
		}

		Ti::Value ScrollView::eventAdded(const std::vector<Ti::Value>& args)
		{
			return Ti::ViewProxy::eventAdded(args);
		}
		Ti::Value ScrollView::eventRemoved(const std::vector<Ti::Value>& args)
		{
			return Ti::ViewProxy::eventRemoved(args);
		}

		// Public API

		// Sets the value of the canCancelEvents property.
		Ti::Value ScrollView::setContentView(const std::vector<Ti::Value>& args)
		{
			assert(scroll_viewer_->Content == nullptr);
			auto contentView = std::dynamic_pointer_cast<ViewProxy>(toProxy(args[0]));
			scroll_viewer_->Content = contentView->getComponent();
			Ti::Layout::nodeAddChild(layout_node_, contentView->layout_node_);
			auto root = Ti::Layout::nodeRequestLayout(layout_node_);
			if (root) {
				Ti::Layout::nodeLayout(root);
			}

			return Ti::Value::Undefined();
		}
		// Sets the value of the canCancelEvents property.
		Ti::Value ScrollView::setCanCancelEvents(const std::vector<Ti::Value>& args)
		{
			if (args[0].toBool()) {
				scroll_viewer_->CancelDirectManipulations();
			}
			return Ti::Value::Undefined();
		}
		// Sets the value of the contentOffset property.
		Ti::Value ScrollView::setContentOffset(const std::vector<Ti::Value>& args)
		{
			if (!args[0].isObject()) {
				OutputDebugString(L"[WARN] ScrollView.setContentOffset() takes an object\n");
				return Ti::Value::Undefined();
			}
			return scrollTo(args);
		}
		// Gets the value of the contentOffset property.
		Ti::Value ScrollView::getContentOffset(const std::vector<Ti::Value>& args)
		{
			const auto x = scroll_viewer_->HorizontalOffset;
			const auto y = scroll_viewer_->VerticalOffset;
			Ti::Value val;
			val.setProperty("x", Ti::Value(x));
			val.setProperty("y", Ti::Value(y));
			return val;
		}
		/*
		 * http://stackoverflow.com/a/17280166/795295		
		 * // Sets the value of the disableBounce property.
		 * Ti::Value ScrollView::setDisableBounce(const std::vector<Ti::Value>& args)
		 * {
		 * 	OutputDebugString(L"[WARN] ScrollView.setDisableBounce() not implemented yet. Returning Undefined\n");
		 * 	return Ti::Value::Undefined();
		 * }
		 * // Gets the value of the disableBounce property.
		 * Ti::Value ScrollView::getDisableBounce(const std::vector<Ti::Value>& args)
		 * {
		 * 	OutputDebugString(L"[WARN] ScrollView.getDisableBounce() not implemented yet. Returning Undefined\n");
		 * 	return Ti::Value::Undefined();
		 * }
		 * // Sets the value of the horizontalBounce property.
		 * Ti::Value ScrollView::setHorizontalBounce(const std::vector<Ti::Value>& args)
		 * {
		 * 	OutputDebugString(L"[WARN] ScrollView.setHorizontalBounce() not implemented yet. Returning Undefined\n");
		 * 	return Ti::Value::Undefined();
		 * }
		 * // Gets the value of the horizontalBounce property.
		 * Ti::Value ScrollView::getHorizontalBounce(const std::vector<Ti::Value>& args)
		 * {
		 * 	OutputDebugString(L"[WARN] ScrollView.getHorizontalBounce() not implemented yet. Returning Undefined\n");
		 * 	return Ti::Value::Undefined();
		 * }
		 *  // Sets the value of the verticalBounce property.
		 * Ti::Value ScrollView::setVerticalBounce(const std::vector<Ti::Value>& args)
		 * {
		 *  OutputDebugString(L"[WARN] ScrollView.setVerticalBounce() not implemented yet. Returning Undefined\n");
		 *  return Ti::Value::Undefined();
		 *  }
		 *  // Gets the value of the verticalBounce property.
		 *  Ti::Value ScrollView::getVerticalBounce(const std::vector<Ti::Value>& args)
		 *  {
		 *  OutputDebugString(L"[WARN] ScrollView.getVerticalBounce() not implemented yet. Returning Undefined\n");
		 *  return Ti::Value::Undefined();
		 *  }
		 */

		// Sets the value of the maxZoomScale property.
		Ti::Value ScrollView::setMaxZoomScale(const std::vector<Ti::Value>& args)
		{
			scroll_viewer_->MaxZoomFactor = static_cast<float>(args[0].toDouble());
			return Ti::Value::Undefined();
		}
		// Gets the value of the maxZoomScale property.
		Ti::Value ScrollView::getMaxZoomScale(const std::vector<Ti::Value>& args)
		{
			return Ti::Value(static_cast<double>(scroll_viewer_->MaxZoomFactor));
		}
		// Sets the value of the minZoomScale property.
		Ti::Value ScrollView::setMinZoomScale(const std::vector<Ti::Value>& args)
		{
			scroll_viewer_->MinZoomFactor = static_cast<float>(args[0].toDouble());
			return Ti::Value::Undefined();
		}
		// Gets the value of the minZoomScale property.
		Ti::Value ScrollView::getMinZoomScale(const std::vector<Ti::Value>& args)
		{
			return Ti::Value(static_cast<double>(scroll_viewer_->MinZoomFactor));
		}
		// Sets the value of the scrollingEnabled property.
		Ti::Value ScrollView::setScrollingEnabled(const std::vector<Ti::Value>& args)
		{
			if (args[0].toBool()) {
				scroll_viewer_->HorizontalScrollMode = Windows::UI::Xaml::Controls::ScrollMode::Auto;
			}
			else {
				scroll_viewer_->HorizontalScrollMode = Windows::UI::Xaml::Controls::ScrollMode::Disabled;
			}
			return Ti::Value::Undefined();
		}
		// Gets the value of the scrollingEnabled property.
		Ti::Value ScrollView::getScrollingEnabled(const std::vector<Ti::Value>& args)
		{
			return Ti::Value(scroll_viewer_->HorizontalScrollMode != Windows::UI::Xaml::Controls::ScrollMode::Disabled);
		}
		// Sets the value of the showHorizontalScrollIndicator property.
		Ti::Value ScrollView::setShowHorizontalScrollIndicator(const std::vector<Ti::Value>& args)
		{
			using namespace Windows::UI::Xaml::Controls;
			if (args[0].toBool()) {
				scroll_viewer_->HorizontalScrollBarVisibility = ScrollBarVisibility::Auto;
			}
			else {
				scroll_viewer_->HorizontalScrollBarVisibility = ScrollBarVisibility::Hidden;
			}
			return Ti::Value::Undefined();
		}
		// Gets the value of the showHorizontalScrollIndicator property.
		Ti::Value ScrollView::getShowHorizontalScrollIndicator(const std::vector<Ti::Value>& args)
		{
			using namespace Windows::UI::Xaml::Controls;
			return Ti::Value(scroll_viewer_->HorizontalScrollBarVisibility != ScrollBarVisibility::Hidden);
		}
		// Sets the value of the showVerticalScrollIndicator property.
		Ti::Value ScrollView::setShowVerticalScrollIndicator(const std::vector<Ti::Value>& args)
		{
			using namespace Windows::UI::Xaml::Controls;
			if (args[0].toBool()) {
				scroll_viewer_->VerticalScrollBarVisibility = ScrollBarVisibility::Auto;
			}
			else {
				scroll_viewer_->VerticalScrollBarVisibility = ScrollBarVisibility::Hidden;
			}
			return Ti::Value::Undefined();
		}
		// Gets the value of the showVerticalScrollIndicator property.
		Ti::Value ScrollView::getShowVerticalScrollIndicator(const std::vector<Ti::Value>& args)
		{
			using namespace Windows::UI::Xaml::Controls;
			return Ti::Value(scroll_viewer_->VerticalScrollBarVisibility != ScrollBarVisibility::Hidden);
		}
		// Sets the value of the zoomScale property.
		Ti::Value ScrollView::setZoomScale(const std::vector<Ti::Value>& args)
		{
			scroll_viewer_->ChangeView(nullptr, nullptr, ref new Platform::Box<float>(static_cast<float>(args[0].toDouble())));
			return Ti::Value::Undefined();
		}
		// Gets the value of the zoomScale property.
		Ti::Value ScrollView::getZoomScale(const std::vector<Ti::Value>& args)
		{
			return Ti::Value(static_cast<double>(scroll_viewer_->ZoomFactor));
		}
		// Moves the specified coordinate of the scrollable region into the viewable area.
		Ti::Value ScrollView::scrollTo(const std::vector<Ti::Value>& args)
		{
			if (args[0].isObject()) {
				const auto x = args[0].getProperty("x");
				const auto y = args[0].getProperty("y");
				const auto animated = args[0].getProperty("animated").toBool();
				scroll_viewer_->ChangeView(
					x.isNumber() ? ref new Platform::Box<double>(x.toDouble()) : nullptr,
					y.isNumber() ? ref new Platform::Box<double>(y.toDouble()) : nullptr,
					nullptr,
					!animated);
			}
			else {
				OutputDebugString(L"[WARN] ScrollView.scrollTo() must be an object\n");
			}
			return Ti::Value::Undefined();
		}
		// Moves the end of the scrollable region into the viewable area.
		Ti::Value ScrollView::scrollToBottom(const std::vector<Ti::Value>& args)
		{
			scroll_viewer_->ChangeView(nullptr, ref new Platform::Box<double>(scroll_viewer_->ScrollableHeight), nullptr);
			return Ti::Value::Undefined();
		}
	}
}