/**
 * TitaniumKit PhotoGalleryOptionsType
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/Media/PhotoGalleryOptionsType.hpp"
#include "Titanium/UI/View.hpp"
#include "Titanium/detail/TiImpl.hpp"

namespace Titanium
{
	namespace Media
	{
		using namespace HAL;

		PhotoGalleryOptionsType js_to_PhotoGalleryOptionsType(const JSObject& object)
		{

			auto allowEditing = false;
			if (object.HasProperty("allowEditing")) {
				allowEditing = static_cast<bool>(object.GetProperty("allowEditing"));
			}
			auto animated = true;
			if (object.HasProperty("animated")) {
				animated = static_cast<bool>(object.GetProperty("animated"));
			}
			std::int32_t arrowDirection = 0;
			if (object.HasProperty("arrowDirection")) {
				arrowDirection = static_cast<int32_t>(object.GetProperty("arrowDirection"));
			}
			auto autohide = true;
			if (object.HasProperty("autohide")) {
				autohide = static_cast<bool>(object.GetProperty("autohide"));
			}
			std::vector<MediaType> mediaTypes;
			if (object.HasProperty("mediaTypes")) {
				const auto mediaTypes_property = object.GetProperty("mediaTypes");
				if (mediaTypes_property.IsObject()) {
					const auto js_mediaTypes = static_cast<JSObject>(mediaTypes_property);
					if (js_mediaTypes.IsArray()) {
						const auto js_array = static_cast<std::vector<JSValue>>(static_cast<JSArray>(js_mediaTypes));
						for (const auto v : js_array) {
							mediaTypes.push_back(static_cast<MediaType>(static_cast<std::uint32_t>(v)));
						}
					} else {
						TITANIUM_LOG_WARN("Media::PhotoGalleryOptionsType: Can't convert mediaTypes");
					}
				}
			}

			const auto js_popoverView = object.GetProperty("popoverView");
			ENSURE_MODULE_OBJECT(js_popoverView, popoverView, Titanium::UI::View);

			const auto success_property = object.GetProperty("success");
			const auto onsuccess = [success_property](const CameraMediaItemType& item) {
				if (success_property.IsObject()) {
					auto func = static_cast<JSObject>(success_property);
					if (func.IsFunction()) {
						const std::vector<JSValue> args = {
							CameraMediaItemType_to_js(func.get_context(), item)
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

			PhotoGalleryOptionsTypeCallbacks callbacks {
				object.GetProperty("cancel"),
				object.GetProperty("error"),
				object.GetProperty("success"),
				oncancel,
				onerror,
				onsuccess
			};

			PhotoGalleryOptionsType config {
				allowEditing,
				animated,
				arrowDirection,
				autohide,
				mediaTypes,
				popoverView,
				callbacks
			};
			
			return config;
		};

		JSObject PhotoGalleryOptionsType_to_js(const JSContext& js_context, const PhotoGalleryOptionsType& config)
		{
			auto object = js_context.CreateObject();
			object.SetProperty("allowEditing", js_context.CreateBoolean(config.allowEditing));
			object.SetProperty("animated", js_context.CreateBoolean(config.animated));
			object.SetProperty("arrowDirection", js_context.CreateNumber(config.arrowDirection));
			object.SetProperty("autohide", js_context.CreateBoolean(config.autohide));
			object.SetProperty("cancel",  config.callbacks.cancel);
			object.SetProperty("error", config.callbacks.error);

			std::vector<JSValue> js_mediaTypes;
			for (const auto v : config.mediaTypes) {
				js_mediaTypes.push_back(js_context.CreateNumber(static_cast<std::uint32_t>(v)));
			}
			object.SetProperty("mediaTypes", js_context.CreateArray(js_mediaTypes));

			if (config.popoverView != nullptr) {
				object.SetProperty("popoverView", config.popoverView->get_object());
			}

			object.SetProperty("success", config.callbacks.success);
			return object;
		}
	} // namespace Media
} // namespace Titanium
