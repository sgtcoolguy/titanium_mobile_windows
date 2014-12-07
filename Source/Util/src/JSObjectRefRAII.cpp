/**
 * Util
 * Author: Matthew D. Langston
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */
#include "Util/JSObjectRefRAII.hpp"

namespace Appcelerator { namespace Util {
  
JSObjectRefRAII::JSObjectRefRAII(JSObjectRef js_object, JSGlobalContextRef context)
: js_object_(js_object)
, context_(context) {
  JSValueProtect(context_, js_object_);
}
    
JSObjectRefRAII::~JSObjectRefRAII() {
  JSValueUnprotect(context_, js_object_);
}

JSObjectRefRAII::JSObjectRefRAII(const JSObjectRefRAII& rhs) {
  JSValueUnprotect(context_, js_object_);
  js_object_ = rhs.js_object_;
  context_   = rhs.context_;
  JSValueProtect(context_, js_object_);
}

JSObjectRefRAII& JSObjectRefRAII::operator=(const JSObjectRefRAII& rhs) {
  if (this == &rhs) {
    return *this;
  }
  
  JSValueUnprotect(context_, js_object_);
  js_object_ = rhs.js_object_;
  context_   = rhs.context_;
  JSValueProtect(context_, js_object_);
  return *this;
}

JSObjectRefRAII::operator JSObjectRef() const {
  return js_object_;
}

}} // namespace Appcelerator { namespace Util {
