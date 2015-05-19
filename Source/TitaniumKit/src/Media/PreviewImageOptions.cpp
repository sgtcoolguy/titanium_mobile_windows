/**
 * TitaniumKit PreviewImageOptions
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/Media/PreviewImageOptions.hpp"
#include "Titanium/Blob.hpp"

namespace Titanium
{
	namespace Media
	{
		using namespace HAL;

		PreviewImageOptions js_to_PreviewImageOptions(const JSObject& object)
		{
			const auto js_image = object.GetProperty("image");
			ENSURE_MODULE_OBJECT(js_image, image, Titanium::Blob);

			const auto success_property = object.GetProperty("success");
			const auto onsuccess = [success_property]() {
				if (success_property.IsObject()) {
					auto func = static_cast<JSObject>(success_property);
					if (func.IsFunction()) {
						func(func);
					}
				}
			};
			const auto error_property = object.GetProperty("error");
			const auto onerror = [error_property](const ErrorResponse& e) {
				if (error_property.IsObject()) {
					auto func = static_cast<JSObject>(error_property);
					if (func.IsFunction()) {
						const std::vector<JSValue> args = {
							ErrorResponse_to_js(func.get_context(), e)
						};
						func(args, func);
					}
				}
			};

			PreviewImageOptions config {
				image,
				onerror,
				onsuccess,
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
