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
				dimension.x = static_cast<int32_t>(object.GetProperty("x"));
			}
			if (object.HasProperty("y")) {
				dimension.y = static_cast<int32_t>(object.GetProperty("y"));
			}
			if (object.HasProperty("width")) {
				dimension.width = static_cast<uint32_t>(object.GetProperty("width"));
			}
			if (object.HasProperty("height")) {
				dimension.height = static_cast<uint32_t>(object.GetProperty("height"));
			}
			return dimension;
		};

		JSObject Dimension_to_js(const JSContext& context, Dimension dimension)
		{
			auto object = context.CreateObject();
			object.SetProperty("x", context.CreateNumber(dimension.x));
			object.SetProperty("y", context.CreateNumber(dimension.y));
			object.SetProperty("width", context.CreateNumber(dimension.width));
			object.SetProperty("height", context.CreateNumber(dimension.height));
			return object;
		};
	} // namespace UI
} // namespace Titanium
