/**
 * Util
 * Author: Matthew D. Langston
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */
#include "Util/Statistics.hpp"

#include <numeric>
#include <utility>
#include <algorithm>
#include <cmath>

namespace Appcelerator { namespace Util {
  
void Statistics::add_duration(const duration_t& duration) {
  duration_list_.push_back(duration);
}

size_t Statistics::count() const {
  calculate();
  return count_;
}

result_duration_t Statistics::mean() const {
  calculate();
  return mean_;
}

result_duration_t Statistics::standard_deviation() const {
  calculate();
  return standard_deviation_;
}

void Statistics::calculate() const {
  if (count_ == duration_list_.size()) {
    return;
  }
  
  using tick_list_t = std::vector<double>;
  tick_list_t tick_list(duration_list_.size());
  std::transform(duration_list_.begin(), duration_list_.end(), tick_list.begin(), [](duration_list_t::value_type duration) { return duration.count(); });
  
  const auto sum  = std::accumulate(tick_list.begin(), tick_list.end(), 0.0);
  const auto mean = sum / tick_list.size();
  
  tick_list_t diff(tick_list.size());
  std::transform(tick_list.begin(), tick_list.end(), diff.begin(), [&mean](tick_list_t::value_type duration) {return duration - mean; });
  const auto sum_of_squares     = std::inner_product(diff.begin(), diff.end(), diff.begin(), 0.0);
  const auto standard_deviation = std::sqrt(sum_of_squares / tick_list.size());
  
  //static const double ms_per_ns { 1000000.0 };
  const_cast<Statistics*>(this) -> count_              = tick_list.size();
  const_cast<Statistics*>(this) -> mean_               = result_duration_t(mean);
  const_cast<Statistics*>(this) -> standard_deviation_ = result_duration_t(standard_deviation);
}

}} // namespace Appcelerator { namespace Util {
