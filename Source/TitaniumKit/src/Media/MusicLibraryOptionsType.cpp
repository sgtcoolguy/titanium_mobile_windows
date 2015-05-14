/**
 * TitaniumKit MusicLibraryOptionsType
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/Media/MusicLibraryOptionsType.hpp"

namespace Titanium
{
	namespace Media
	{
		using namespace HAL;

		MusicLibraryOptionsType js_to_MusicLibraryOptionsType(const JSObject& object)
		{
			MusicLibraryOptionsType config {
				object.GetProperty("cancel"),
				object.GetProperty("error"),
				object.GetProperty("success"),
			};
			
			return config;
		};

		JSObject MusicLibraryOptionsType_to_js(const JSContext& js_context, const MusicLibraryOptionsType& config)
		{
			auto object = js_context.CreateObject();
			object.SetProperty("cancel",  config.cancel);
			object.SetProperty("error",   config.error);
			object.SetProperty("success", config.success);
			return object;
		}
	} // namespace Media
} // namespace Titanium
