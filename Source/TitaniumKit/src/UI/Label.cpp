/**
 * TitaniumKit
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/Label.hpp"

namespace Titanium { namespace UI {
	
	Label::Label(const JSContext& js_context) TITANIUM_NOEXCEPT
    : View(js_context)
    , text__(js_context.CreateString()) {
  }
  
	Label::Label(const Label& rhs, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
  : View(rhs, arguments)
    , text__(rhs.text__) {
  }
  
	JSValue Label::get_text() const TITANIUM_NOEXCEPT{
    return text__;
  }
  
  void Label::set_text(const JSValue& text) TITANIUM_NOEXCEPT{
    text__ = text;
  }
	  
  // TODO: The following functions can automatically be generated from
  // the YAML API docs.
  
  void Label::JSExportInitialize() {
    JSExport<Label>::SetClassVersion(1);
    JSExport<Label>::SetParent(JSExport<View>::Class());
    JSExport<Label>::AddValueProperty("text", std::mem_fn(&Label::get_text), std::mem_fn(&Label::setTextArgumentValidator));
  }
  
  bool Label::setTextArgumentValidator(const JSValue& argument) TITANIUM_NOEXCEPT {
    TITANIUM_LOG_WARN("Button::setTitleArgumentValidator: Unimplemented");

    // Base classes must implement this method. This is the minimum
    // functionality that you should perform:
    //
    // TITANIUM_ASSERT(argument.IsString());
    // set_text(argument);
    // return true;

    return false;
  }
  
}} // namespace Titanium { namespace UI {
