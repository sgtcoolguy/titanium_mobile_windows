/**
 * TitaniumKit RouteDescription
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/Media/RouteDescription.hpp"

namespace Titanium
{
	namespace Media
	{
		using namespace HAL;

		RouteDescription js_to_RouteDescription(const JSObject& object)
		{
			RouteDescription config {
				object.GetProperty("callback"),
			};
			
			return config;
		};

		JSObject RouteDescription_to_js(const JSContext& js_context, const RouteDescription& config)
		{
			auto object = js_context.CreateObject();
			object.SetProperty("callback", config.callback);
			return object;
		}
	} // namespace Media
} // namespace Titanium
