/**
 * TitaniumKit CameraMediaItemType
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/Media/CameraMediaItemType.hpp"
#include "Titanium/Blob.hpp"
#include "Titanium/detail/TiImpl.hpp"

namespace Titanium
{
	namespace Media
	{
		using namespace HAL;

		CameraMediaItemType js_to_CameraMediaItemType(const JSObject& object)
		{
			CameraMediaItemType config;

			config.code = static_cast<std::int32_t>(object.GetProperty("code"));
			if (object.HasProperty("cropRect")) {
				config.cropRect = Titanium::UI::js_to_Dimension(static_cast<JSObject>(object.GetProperty("cropRect")));
			}
			if (object.HasProperty("error")) {
				config.error = static_cast<std::string>(object.GetProperty("error"));
			}
			const auto js_media = object.GetProperty("media");
			ENSURE_MODULE_OBJECT(js_media, media, Titanium::Blob);
			config.media = media;
			config.mediaType = static_cast<MediaType>(static_cast<std::uint32_t>(object.GetProperty("mediaType")));
			config.success = static_cast<bool>(object.GetProperty("success"));
			return config;
		};

		JSObject CameraMediaItemType_to_js(const JSContext& js_context, const CameraMediaItemType& config)
		{
			auto object = js_context.CreateObject();
			object.SetProperty("code", js_context.CreateNumber(config.code));
			object.SetProperty("cropRect", Titanium::UI::Dimension_to_js(js_context, config.cropRect));
			object.SetProperty("error", js_context.CreateString(config.error));
			if (config.media != nullptr) {
				object.SetProperty("media", config.media->get_object());
			}
			object.SetProperty("mediaType", js_context.CreateNumber(static_cast<std::uint32_t>(config.mediaType)));
			object.SetProperty("success", js_context.CreateBoolean(config.success));
			return object;
		}
	} // namespace Media
} // namespace Titanium
