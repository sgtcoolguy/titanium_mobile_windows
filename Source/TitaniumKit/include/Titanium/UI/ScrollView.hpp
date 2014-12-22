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

namespace Titanium { namespace UI {
  
  using namespace HAL;
  
  /*!
   @class
   
   @discussion This is the Titanium UI ScrollView.
   
   See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.UI.ScrollView
   */
  class TITANIUMKIT_EXPORT ScrollView : public View, public JSExport<ScrollView> {
    
  public:
    
    virtual void add(const JSObject& view, JSObject& this_object) TITANIUM_NOEXCEPT override;
    virtual void scrollTo(double x, double y) TITANIUM_NOEXCEPT;
    virtual void scrollToBottom() TITANIUM_NOEXCEPT;
    virtual JSValue getContentWidth() const TITANIUM_NOEXCEPT;
    virtual JSValue getContentHeight() const TITANIUM_NOEXCEPT;
    virtual bool setContentWidth(const JSValue& width) TITANIUM_NOEXCEPT;
    virtual bool setContentHeight(const JSValue& height) TITANIUM_NOEXCEPT;

    ScrollView(const JSContext& js_context)                          TITANIUM_NOEXCEPT;
    ScrollView(const ScrollView&, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT;
    
    virtual ~ScrollView()                   = default;
    ScrollView(const ScrollView&)               = default;
    ScrollView& operator=(const ScrollView&)    = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
    ScrollView(ScrollView&&)                    = default;
    ScrollView& operator=(ScrollView&&)         = default;
#endif
    
    static void JSExportInitialize();
    
    virtual JSValue setContentWidthArgumentValidator(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
    virtual JSValue getContentWidthArgumentValidator(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
    virtual JSValue setContentHeightArgumentValidator(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
    virtual JSValue getContentHeightArgumentValidator(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;

    virtual JSValue scrollToArgumentValidator(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
    virtual JSValue scrollToBottomArgumentValidator(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;

  private:
  };
}} // namespace Titanium { namespace UI {

#endif // _TITANIUM_UI_SCROLLVIEW_HPP_
