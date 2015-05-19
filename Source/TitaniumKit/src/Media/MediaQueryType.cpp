/**
 * TitaniumKit MediaQueryType
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/Media/MediaQueryType.hpp"

namespace Titanium
{
	namespace Media
	{
		using namespace HAL;

		MediaQueryType js_to_MediaQueryType(const JSObject& object)
		{
			MediaQueryType config {
				js_to_MediaQueryInfoType(object.GetProperty("albumArtist")),
				js_to_MediaQueryInfoType(object.GetProperty("albumTitle")),
				js_to_MediaQueryInfoType(object.GetProperty("artist")),
				js_to_MediaQueryInfoType(object.GetProperty("composer")),
				js_to_MediaQueryInfoType(object.GetProperty("genre")),
				static_cast<MusicMediaGroup>(static_cast<std::uint32_t>(object.GetProperty("grouping"))),
				js_to_MediaQueryInfoType(object.GetProperty("isCompilation")),
				js_to_MediaQueryInfoType(object.GetProperty("mediaType")),
				js_to_MediaQueryInfoType(object.GetProperty("title"))
			};
			
			return config;
		};

		JSObject MediaQueryType_to_js(const JSContext& js_context, const MediaQueryType& config)
		{
			auto object = js_context.CreateObject();
			object.SetProperty("albumArtist", MediaQueryInfoType_to_js(js_context, config.albumArtist));
			object.SetProperty("albumTitle", MediaQueryInfoType_to_js(js_context, config.albumTitle));
			object.SetProperty("artist", MediaQueryInfoType_to_js(js_context, config.artist));
			object.SetProperty("composer", MediaQueryInfoType_to_js(js_context, config.composer));
			object.SetProperty("genre", MediaQueryInfoType_to_js(js_context, config.genre));
			object.SetProperty("isCompilation", MediaQueryInfoType_to_js(js_context, config.isCompilation));
			object.SetProperty("mediaType", MediaQueryInfoType_to_js(js_context, config.mediaType));
			object.SetProperty("title", MediaQueryInfoType_to_js(js_context, config.title));
			object.SetProperty("grouping", js_context.CreateNumber(static_cast<std::uint32_t>(config.grouping)));
			return object;
		}
	} // namespace Media
} // namespace Titanium
