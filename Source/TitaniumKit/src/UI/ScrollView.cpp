/**
 * TitaniumKit
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/ScrollView.hpp"

namespace Titanium { namespace UI {
  
  ScrollView::ScrollView(const JSContext& js_context) TITANIUM_NOEXCEPT
    : View(js_context) {
  }
  
  ScrollView::ScrollView(const ScrollView& rhs, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
  : View(rhs, arguments) {
  }
  
  void ScrollView::JSExportInitialize() {
    JSExport<ScrollView>::SetClassVersion(1);
    JSExport<ScrollView>::SetParent(JSExport<View>::Class());
    JSExport<ScrollView>::AddFunctionProperty("scrollTo", std::mem_fn(&ScrollView::scrollToArgumentValidator));
    JSExport<ScrollView>::AddFunctionProperty("scrollToBottom", std::mem_fn(&ScrollView::scrollToBottomArgumentValidator));
    JSExport<ScrollView>::AddValueProperty("contentWidth", std::mem_fn(&ScrollView::getContentWidth), std::mem_fn(&ScrollView::setContentWidth));
    JSExport<ScrollView>::AddValueProperty("contentHeight", std::mem_fn(&ScrollView::getContentHeight), std::mem_fn(&ScrollView::setContentHeight));
    JSExport<ScrollView>::AddFunctionProperty("setContentWidth", std::mem_fn(&ScrollView::setContentWidthArgumentValidator));
    JSExport<ScrollView>::AddFunctionProperty("setContentHeight", std::mem_fn(&ScrollView::setContentHeightArgumentValidator));
    JSExport<ScrollView>::AddFunctionProperty("getContentWidth", std::mem_fn(&ScrollView::getContentWidthArgumentValidator));
    JSExport<ScrollView>::AddFunctionProperty("getContentHeight", std::mem_fn(&ScrollView::getContentHeightArgumentValidator));
  }
  
  void ScrollView::add(const JSObject& view, JSObject& this_object) TITANIUM_NOEXCEPT {
    TITANIUM_LOG_WARN("ScrollView::add: Unimplemented");
    View::add(view, this_object);
  }

  void ScrollView::scrollTo(double x, double y) TITANIUM_NOEXCEPT {
    TITANIUM_LOG_WARN("ScrollView::scrollTo: Unimplemented");
  }

  void ScrollView::scrollToBottom() TITANIUM_NOEXCEPT {
    TITANIUM_LOG_WARN("ScrollView::scrollToBottom: Unimplemented");
  }

  JSValue ScrollView::getContentWidth() const {
    TITANIUM_LOG_WARN("ScrollView::getContentWidth: Unimplemented");
    return get_context().CreateUndefined();
  }
  JSValue ScrollView::getContentHeight() const {
    TITANIUM_LOG_WARN("ScrollView::getContentHeight: Unimplemented");
    return get_context().CreateUndefined();
  }
  bool ScrollView::setContentWidth(const JSValue& width) {
    TITANIUM_LOG_WARN("ScrollView::setContentWidth: Unimplemented");
    return false;
  }
  bool ScrollView::setContentHeight(const JSValue& height) {
    TITANIUM_LOG_WARN("ScrollView::setContentHeight: Unimplemented");
    return false;
  }

  JSValue ScrollView::scrollToArgumentValidator(const std::vector<JSValue>& arguments, JSObject&) TITANIUM_NOEXCEPT {
    if (arguments.size() < 2) {
      return get_context().CreateUndefined();
    }
    const auto _0 = arguments.at(0);
    const auto _1 = arguments.at(1);
    TITANIUM_ASSERT(_0.IsNumber());
    TITANIUM_ASSERT(_1.IsNumber());
    scrollTo(static_cast<double>(_0), static_cast<double>(_1));
    return get_context().CreateUndefined();
  }

  JSValue ScrollView::scrollToBottomArgumentValidator(const std::vector<JSValue>& arguments, JSObject&) TITANIUM_NOEXCEPT {
    scrollToBottom();
    return get_context().CreateUndefined();
  }

  JSValue ScrollView::setContentWidthArgumentValidator(const std::vector<JSValue>& arguments, JSObject&) TITANIUM_NOEXCEPT {
    if (arguments.size() == 0) {
      return get_context().CreateUndefined();
    }
    const auto _0 = arguments.at(0);
    setContentWidth(_0);
    return get_context().CreateUndefined();
  }
  JSValue ScrollView::getContentWidthArgumentValidator(const std::vector<JSValue>& arguments, JSObject&) TITANIUM_NOEXCEPT {
    return getContentWidth();
  }

  JSValue ScrollView::setContentHeightArgumentValidator(const std::vector<JSValue>& arguments, JSObject&) TITANIUM_NOEXCEPT {
    if (arguments.size() == 0) {
      return get_context().CreateUndefined();
    }
    const auto _0 = arguments.at(0);
    setContentHeight(_0);
    return get_context().CreateUndefined();
  }
  JSValue ScrollView::getContentHeightArgumentValidator(const std::vector<JSValue>& arguments, JSObject&) TITANIUM_NOEXCEPT {
    return getContentHeight();
  }
}} // namespace Titanium { namespace UI {
