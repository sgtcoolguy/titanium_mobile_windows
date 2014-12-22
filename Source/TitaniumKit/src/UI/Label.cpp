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
    , color__(js_context.CreateString())
    , text__(js_context.CreateString())
    , textAlign__(TEXT_ALIGNMENT::LEFT)
    , verticalAlign__(TEXT_VERTICAL_ALIGNMENT::CENTER)
    , wordWrap__(js_context.CreateBoolean(true)) {
  }
  
  Label::Label(const Label& rhs, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
  : View(rhs, arguments)
    , color__(rhs.color__)
    , text__(rhs.text__)
    , textAlign__(rhs.textAlign__)
    , verticalAlign__(rhs.verticalAlign__)
    , wordWrap__(rhs.wordWrap__) {
  }
  
  JSValue Label::get_text() const TITANIUM_NOEXCEPT {
    return text__;
  }
  
  void Label::set_text(const JSValue& text) TITANIUM_NOEXCEPT {
    text__ = text;
  }

  TEXT_ALIGNMENT Label::get_textAlign() const  TITANIUM_NOEXCEPT {
    return textAlign__;
  }
  
  void Label::set_textAlign(const TEXT_ALIGNMENT& textAlign) TITANIUM_NOEXCEPT {
    textAlign__ = textAlign;
  }

  TEXT_VERTICAL_ALIGNMENT Label::get_verticalAlign() const  TITANIUM_NOEXCEPT {
    return verticalAlign__;
  }

  void Label::set_verticalAlign(const TEXT_VERTICAL_ALIGNMENT& verticalAlign) TITANIUM_NOEXCEPT {
    verticalAlign__ = verticalAlign;
  }

  JSValue Label::get_wordWrap() const  TITANIUM_NOEXCEPT {
    return wordWrap__;
  }

  void Label::set_wordWrap(const JSValue& wordWrap) TITANIUM_NOEXCEPT {
    wordWrap__ = wordWrap;
  }

  JSValue Label::get_color() const  TITANIUM_NOEXCEPT {
    return color__;
  }

  void Label::set_color(const JSValue& color) TITANIUM_NOEXCEPT {
    color__ = color;
  }
  
  // TODO: The following functions can automatically be generated from
  // the YAML API docs.
  
  void Label::JSExportInitialize() {
    JSExport<Label>::SetClassVersion(1);
    JSExport<Label>::SetParent(JSExport<View>::Class());
    JSExport<Label>::AddValueProperty("color", std::mem_fn(&Label::getColorArgumentValidator), std::mem_fn(&Label::setColorArgumentValidator));
    JSExport<Label>::AddValueProperty("text", std::mem_fn(&Label::getTextArgumentValidator), std::mem_fn(&Label::setTextArgumentValidator));
    JSExport<Label>::AddValueProperty("textAlign", std::mem_fn(&Label::getTextAlignArgumentValidator), std::mem_fn(&Label::setTextAlignArgumentValidator));
    JSExport<Label>::AddValueProperty("verticalAlign", std::mem_fn(&Label::getVerticalAlignArgumentValidator), std::mem_fn(&Label::setVerticalAlignArgumentValidator));
    JSExport<Label>::AddValueProperty("wordWrap", std::mem_fn(&Label::getWordWrapArgumentValidator), std::mem_fn(&Label::setWordWrapArgumentValidator));
  }

  JSValue Label::getColorArgumentValidator() const TITANIUM_NOEXCEPT {
    return get_color();
  }

  bool Label::setColorArgumentValidator(const JSValue& argument) TITANIUM_NOEXCEPT {
    TITANIUM_ASSERT(argument.IsString());
    color__ = get_context().CreateString(static_cast<std::string>(argument));
    set_color(color__);
    return true;
  }

  JSValue Label::getTextArgumentValidator() const TITANIUM_NOEXCEPT {
    return get_text();
  }

  bool Label::setTextArgumentValidator(const JSValue& argument) TITANIUM_NOEXCEPT {
    TITANIUM_ASSERT(argument.IsString());
    text__ = get_context().CreateString(static_cast<std::string>(argument));
    set_text(text__);
    return true;
  }

  JSValue Label::getTextAlignArgumentValidator() const TITANIUM_NOEXCEPT {
    return get_context().CreateNumber(static_cast<std::underlying_type<TEXT_ALIGNMENT>::type>(get_textAlign()));
  }
  
  bool Label::setTextAlignArgumentValidator(const JSValue& argument) TITANIUM_NOEXCEPT {
    bool result = false;
    if (argument.IsNumber()) {
      textAlign__ = Constants::to_TEXT_ALIGNMENT(static_cast<std::underlying_type<TEXT_ALIGNMENT>::type>(argument));
      set_textAlign(textAlign__);
      result = true;
    } else if (argument.IsString()) {
      textAlign__ = Constants::to_TEXT_ALIGNMENT(static_cast<std::string>(argument));
      set_textAlign(textAlign__);
      result = true;
    }
    
    return result;
  }

  JSValue Label::getVerticalAlignArgumentValidator() const TITANIUM_NOEXCEPT {
    return get_context().CreateNumber(static_cast<std::underlying_type<TEXT_VERTICAL_ALIGNMENT>::type>(get_verticalAlign()));
  }

  bool Label::setVerticalAlignArgumentValidator(const JSValue& argument) TITANIUM_NOEXCEPT {
    bool result = false;
    if (argument.IsNumber()) {
      verticalAlign__ = Constants::to_TEXT_VERTICAL_ALIGNMENT(static_cast<std::underlying_type<TEXT_VERTICAL_ALIGNMENT>::type>(argument));
      set_verticalAlign(verticalAlign__);
      result = true;
    }
    else if (argument.IsString()) {
      verticalAlign__ = Constants::to_TEXT_VERTICAL_ALIGNMENT(static_cast<std::string>(argument));
      set_verticalAlign(verticalAlign__);
      result = true;
    }

    return result;
  }

  JSValue Label::getWordWrapArgumentValidator() const TITANIUM_NOEXCEPT {
    return get_wordWrap();
  }

  bool Label::setWordWrapArgumentValidator(const JSValue& argument) TITANIUM_NOEXCEPT {
    TITANIUM_ASSERT(argument.IsBoolean());
    wordWrap__ = get_context().CreateBoolean(static_cast<bool>(argument));
    set_wordWrap(wordWrap__);
    return true;
  }
  
}} // namespace Titanium { namespace UI {
