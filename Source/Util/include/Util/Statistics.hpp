/**
 * Util
 * Author: Matthew D. Langston
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */
#ifndef _TITANIUM_MOBILE_UTIL_STATISTICS_HPP_
#define _TITANIUM_MOBILE_UTIL_STATISTICS_HPP_

#include <vector>
#include <chrono>

namespace Appcelerator { namespace Util {

using duration_t        = std::chrono::nanoseconds;
using duration_list_t   = std::vector<duration_t>;
using result_duration_t = std::chrono::duration<double, std::nano>;

class Statistics {
  
 public:
  
  void              add_duration(const duration_t& duration);
  size_t            count()              const;
  result_duration_t mean()               const;
  result_duration_t standard_deviation() const;
  
 private:
  
  void calculate() const;
  size_t            count_              { 0 };
  result_duration_t mean_               { 0.0 };
  result_duration_t standard_deviation_ { 0.0 };
  duration_list_t   duration_list_;
};

}} // namespace Appcelerator::Util

#endif // _TITANIUM_MOBILE_UTIL_STATISTICS_HPP_
