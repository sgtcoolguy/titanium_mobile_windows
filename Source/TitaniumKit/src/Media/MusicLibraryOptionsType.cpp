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
			auto allowMultipleSelections = false;
			if (object.HasProperty("allowMultipleSelections")) {
				allowMultipleSelections = static_cast<bool>(object.GetProperty("allowMultipleSelections"));
			}
			auto animated = true;
			if (object.HasProperty("animated")) {
				animated = static_cast<bool>(object.GetProperty("animated"));
			}
			auto autohide = true;
			if (object.HasProperty("autohide")) {
				autohide = static_cast<bool>(object.GetProperty("autohide"));
			}
			std::vector<MusicMediaType> mediaTypes;
			if (object.HasProperty("mediaTypes")) {
				const auto mediaTypes_property = object.GetProperty("mediaTypes");
				if (mediaTypes_property.IsObject()) {
					const auto js_mediaTypes = static_cast<JSObject>(mediaTypes_property);
					if (js_mediaTypes.IsArray()) {
						const auto js_array = static_cast<std::vector<JSValue>>(static_cast<JSArray>(js_mediaTypes));
						for (const auto v : js_array) {
							mediaTypes.push_back(static_cast<MusicMediaType>(static_cast<std::uint32_t>(v)));
						}
					} else {
						TITANIUM_LOG_WARN("Media::MusicLibraryOptionsType: Can't convert mediaTypes");
					}
				} else if (mediaTypes_property.IsNumber()) {
					const auto mediaTypes_map = Constants::to_MusicMediaType(static_cast<std::uint32_t>(mediaTypes_property));
					for (const auto v : mediaTypes_map) {
						mediaTypes.push_back(v);
					}
				}
			}

			const auto success_property = object.GetProperty("success");
			const auto onsuccess = [success_property](const MusicLibraryResponseType& item) {
				if (success_property.IsObject()) {
					auto func = static_cast<JSObject>(success_property);
					if (func.IsFunction()) {
						const std::vector<JSValue> args = {
							MusicLibraryResponseType_to_js(func.get_context(), item)
						};
						func(args, func);
					}
				}
			};
			const auto cancel_property = object.GetProperty("cancel");
			const auto oncancel = [cancel_property](const ErrorResponse& e) {
				if (cancel_property.IsObject()) {
					auto func = static_cast<JSObject>(cancel_property);
					if (func.IsFunction()) {
						const std::vector<JSValue> args = {
							ErrorResponse_to_js(func.get_context(), e)
						};
						func(args, func);
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

			MusicLibraryOptionsType config {
				allowMultipleSelections,
				animated,
				autohide,
				mediaTypes,
				oncancel,
				onerror,
				onsuccess,
				object.GetProperty("cancel"),
				object.GetProperty("error"),
				object.GetProperty("success"),
			};
			
			return config;
		};

		JSObject MusicLibraryOptionsType_to_js(const JSContext& js_context, const MusicLibraryOptionsType& config)
		{
			auto object = js_context.CreateObject();
			object.SetProperty("allowMultipleSelections", js_context.CreateBoolean(config.allowMultipleSelections));
			object.SetProperty("animated", js_context.CreateBoolean(config.animated));
			object.SetProperty("autohide", js_context.CreateBoolean(config.autohide));
			object.SetProperty("cancel",  config.cancel);
			object.SetProperty("error",   config.error);

			std::vector<JSValue> js_mediaTypes;
			for (const auto v : config.mediaTypes) {
				js_mediaTypes.push_back(js_context.CreateNumber(static_cast<std::uint32_t>(v)));
			}
			object.SetProperty("mediaTypes", js_context.CreateArray(js_mediaTypes));
			object.SetProperty("success", config.success);
			return object;
		}
	} // namespace Media
} // namespace Titanium
