/**
 * TitaniumKit PreviewImageOptions
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/Media/PreviewImageOptions.hpp"

namespace Titanium
{
	namespace Media
	{
		using namespace HAL;

		PreviewImageOptions js_to_PreviewImageOptions(const JSObject& object)
		{
			PreviewImageOptions config {
				object.GetProperty("error"),
				object.GetProperty("success")
			};
			
			return config;
		};

		JSObject PreviewImageOptions_to_js(const JSContext& js_context, const PreviewImageOptions& config)
		{
			auto object = js_context.CreateObject();
			object.SetProperty("error", config.error);
			object.SetProperty("success", config.success);
			return object;
		}
	} // namespace Media
} // namespace Titanium
