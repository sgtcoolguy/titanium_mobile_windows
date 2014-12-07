/**
 * Util
 * Author: Matthew D. Langston
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */
#ifndef _TITANIUM_MOBILE_UTIL_VIRTUAL_ENABLE_SHARED_FROM_THIS_BASE_HPP_
#define _TITANIUM_MOBILE_UTIL_VIRTUAL_ENABLE_SHARED_FROM_THIS_BASE_HPP_

#include <memory>

namespace Appcelerator { namespace Util {
  
// This header file allows std::enable_shared_from_this to work when
// both base and derived classes both need to inherit from
// boost::enable_shared_from_this. Use it like this:
//
// struct A: virtual_enable_shared_from_this<A> {};
//
// struct B: virtual_enable_shared_from_this<B> {};
//
// struct C: A, B, virtual_enable_shared_from_this<C> {
//   using enable_shared_from_this<C>::shared_from_this;
// }

struct virtual_enable_shared_from_this_base : std::enable_shared_from_this<virtual_enable_shared_from_this_base> {
  virtual ~virtual_enable_shared_from_this_base() {
  }
};

template<typename T>
struct virtual_enable_shared_from_this : virtual virtual_enable_shared_from_this_base {
  std::shared_ptr<T> shared_from_this() {
    return std::dynamic_pointer_cast<T>(virtual_enable_shared_from_this_base::shared_from_this());
  }
};

}} // namespace Appcelerator::Util

#endif // _TITANIUM_MOBILE_UTIL_VIRTUAL_ENABLE_SHARED_FROM_THIS_BASE_HPP_
