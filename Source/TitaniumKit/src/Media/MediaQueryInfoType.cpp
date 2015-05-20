/**
 * TitaniumKit MediaQueryInfoType
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/Media/MediaQueryInfoType.hpp"

namespace Titanium
{
	namespace Media
	{
		using namespace HAL;

		MediaQueryInfoType js_to_MediaQueryInfoType(const JSValue& js_info)
		{
			const auto ctx = js_info.get_context();
			
			if (js_info.IsObject()) {
				const auto js_info_obj = static_cast<JSObject>(js_info);
				const auto exact = static_cast<bool>(js_info_obj.GetProperty("exact"));
				const auto value = js_info_obj.GetProperty("value");
				return { exact, value };
			}
			return { true, js_info };
		};

		JSObject MediaQueryInfoType_to_js(const JSContext& js_context, const MediaQueryInfoType& config)
		{
			auto object = js_context.CreateObject();
			object.SetProperty("exact", js_context.CreateBoolean(config.exact));
			object.SetProperty("value", config.value);
			return object;
		}
	} // namespace Media
} // namespace Titanium
