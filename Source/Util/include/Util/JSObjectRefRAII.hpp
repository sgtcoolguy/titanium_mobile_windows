/**
 * Util
 * Author: Matthew D. Langston
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */
#ifndef _TITANIUM_MOBILE_WINDOWS_UTIL_JSOBJECTREFRAII_HPP_
#define _TITANIUM_MOBILE_WINDOWS_UTIL_JSOBJECTREFRAII_HPP_

#include <JavaScriptCore/JavaScript.h>

namespace Appcelerator { namespace Util {

class JSObjectRefRAII final {
  
public:
  
  // Create an empty object.
  JSObjectRefRAII(JSObjectRef js_object, JSGlobalContextRef context);
  
  ~JSObjectRefRAII();
  
  JSObjectRefRAII(const JSObjectRefRAII& rhs);
  JSObjectRefRAII& operator=(const JSObjectRefRAII& rhs);
  
  operator JSObjectRef() const;
  
private:
  
  // Prevent heap based objects.
  static void * operator new(size_t);      // #1: To prevent allocation of scalar objects
  static void * operator new [] (size_t);  // #2: To prevent allocation of array of objects
  
  JSObjectRef        js_object_;
  JSGlobalContextRef context_;
};

}} // namespace Appcelerator { namespace Util {

#endif // _TITANIUM_MOBILE_WINDOWS_UTIL_JSOBJECTREFRAII_HPP_
