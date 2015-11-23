/**
 * TitaniumKit Point
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */
#include "Titanium/UI/Point.hpp"
#include <boost/algorithm/string/predicate.hpp>

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		Point js_to_Point(const JSObject& object)
		{
			Point point;
			if (object.HasProperty("x")) {
				const auto xobj = object.GetProperty("x");
				if (xobj.IsString()) {
					const auto xstr = static_cast<std::string>(xobj);
					if (boost::ends_with(xstr, "%")) {
						// Point accepts '%'. 
						point.x_percent = xstr;
					} else {
						// not a percent? Force double anyway
						point.x = static_cast<double>(xobj);
					}
				} else {
					point.x = static_cast<double>(xobj);
				}
			}
			if (object.HasProperty("y")) {
				const auto yobj = object.GetProperty("y");
				if (yobj.IsString()) {
					const auto ystr = static_cast<std::string>(yobj);
					if (boost::ends_with(ystr, "%")) {
						// Point accepts '%'
						point.y_percent = ystr;
					} else {
						// not a percent? Force double anyway
						point.y = static_cast<double>(yobj);
					}
				} else {
					point.y = static_cast<double>(yobj);
				}
			}
			return point;
		};

		JSObject Point_to_js(const JSContext& js_context, const Point& point)
		{
			auto object = js_context.CreateObject();
			object.SetProperty("x", js_context.CreateNumber(point.x));
			object.SetProperty("y", js_context.CreateNumber(point.y));
			return object;
		};
	} // namespace UI
} // namespace Titanium
