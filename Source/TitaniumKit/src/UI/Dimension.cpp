/**
 * TitaniumKit Dimension
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/Dimension.hpp"

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		Dimension js_to_Dimension(const JSObject& object)
		{
			Dimension dimension;
			if (object.HasProperty("x")) {
				dimension.x = static_cast<double>(object.GetProperty("x"));
			}
			if (object.HasProperty("y")) {
				dimension.y = static_cast<double>(object.GetProperty("y"));
			}
			if (object.HasProperty("width")) {
				dimension.width = static_cast<double>(object.GetProperty("width"));
			}
			if (object.HasProperty("height")) {
				dimension.height = static_cast<double>(object.GetProperty("height"));
			}
			return dimension;
		};

		JSObject Dimension_to_js(const JSContext& js_context, const Dimension& dimension)
		{
			auto object = js_context.CreateObject();
			object.SetProperty("x",  js_context.CreateNumber(static_cast<double>(dimension.x)));
			object.SetProperty("y",  js_context.CreateNumber(static_cast<double>(dimension.y)));
			object.SetProperty("width",   js_context.CreateNumber(static_cast<double>(dimension.width)));
			object.SetProperty("height",  js_context.CreateNumber(static_cast<double>(dimension.height)));
			return object;
		}
	} // namespace UI
} // namespace Titanium
