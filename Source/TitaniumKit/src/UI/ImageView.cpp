/**
 * TitaniumKit
 *
 * Copyright (c) 2014-2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/ImageView.hpp"

#define IMAGEVIEW_MIN_INTERVAL 30

namespace Titanium
{
	namespace UI
	{
		ImageView::ImageView(const JSContext& js_context) TITANIUM_NOEXCEPT
		    : View(js_context),
			  autorotate__(false),
			  decodeRetries__(5),
			  defaultImage__(""),
			  enableZoomControls__(false),
		      duration__(200),
		      image__(""),
		      images__(),
		      preventDefaultImage__(false)
		{
		}

		void ImageView::start() TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_DEBUG("ImageView::start unimplemented");
		}

		void ImageView::stop() TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_DEBUG("ImageView::stop unimplemented");
		}

		void ImageView::pause() TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_DEBUG("ImageView::pause unimplemented");
		}

		void ImageView::resume() TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_DEBUG("ImageView::resume unimplemented");
		}

		std::shared_ptr<Titanium::Blob> ImageView::toBlob() TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_DEBUG("ImageView::toBlob unimplemented");
			return nullptr;
		}

		bool ImageView::get_animating() const TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_DEBUG("ImageView::get_animating unimplemented");
			return false;
		}

		bool ImageView::get_autorotate() const TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_DEBUG("ImageView::get_autorotate unimplemented");
			return false;
		}

		void ImageView::set_autorotate(const bool& autorotate) TITANIUM_NOEXCEPT
		{
			autorotate__ = autorotate;
		}

		uint32_t ImageView::get_decodeRetries() const TITANIUM_NOEXCEPT
		{
			return decodeRetries__;
		}

		void ImageView::set_decodeRetries(const uint32_t& decodeRetries) TITANIUM_NOEXCEPT
		{
			decodeRetries__ = decodeRetries;
		}

		std::string ImageView::get_defaultImage() const TITANIUM_NOEXCEPT
		{
			return defaultImage__;
		}

		void ImageView::set_defaultImage(const std::string& defaultImage) TITANIUM_NOEXCEPT
		{
			defaultImage__ = defaultImage;
		}

		std::chrono::milliseconds ImageView::get_duration() const TITANIUM_NOEXCEPT
		{
			return duration__;
		}

		void ImageView::set_duration(const std::chrono::milliseconds& duration) TITANIUM_NOEXCEPT
		{
			// enforce minimum
			if (duration.count() < IMAGEVIEW_MIN_INTERVAL) {
				duration__ = std::chrono::milliseconds(static_cast<std::chrono::milliseconds::rep>(IMAGEVIEW_MIN_INTERVAL));
			} else {
				duration__ = duration;
			}
		}

		bool ImageView::get_enableZoomControls() const TITANIUM_NOEXCEPT
		{
			return enableZoomControls__;
		}

		void ImageView::set_enableZoomControls(const bool& enableZoomControls) TITANIUM_NOEXCEPT
		{
			enableZoomControls__ = enableZoomControls;
		}

		bool ImageView::get_hires() const TITANIUM_NOEXCEPT
		{
			return hires__;
		}

		void ImageView::set_hires(const bool& hires) TITANIUM_NOEXCEPT
		{
			hires__ = hires;
		}

		std::string ImageView::get_image() const TITANIUM_NOEXCEPT
		{
			return image__;
		}

		void ImageView::set_image(const std::string& image) TITANIUM_NOEXCEPT
		{
			image__ = image;
		}

		std::vector<std::string> ImageView::get_images() const TITANIUM_NOEXCEPT
		{
			return images__;
		}

		void ImageView::set_images(const std::vector<std::string>& images) TITANIUM_NOEXCEPT
		{
			images__ = images;
		}

		bool ImageView::get_paused() const TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_DEBUG("ImageView::get_paused unimplemented");
			return false;
		}

		bool ImageView::get_preventDefaultImage() const TITANIUM_NOEXCEPT
		{
			return preventDefaultImage__;
		}

		void ImageView::set_preventDefaultImage(const bool& preventDefaultImage) TITANIUM_NOEXCEPT
		{
			preventDefaultImage__ = preventDefaultImage;
		}

		uint32_t ImageView::get_repeatCount() const TITANIUM_NOEXCEPT
		{
			return repeatCount__;
		}

		void ImageView::set_repeatCount(const uint32_t& repeatCount) TITANIUM_NOEXCEPT
		{
			repeatCount__ = repeatCount;
		}

		bool ImageView::get_reverse() const TITANIUM_NOEXCEPT
		{
			return reverse__;
		}

		void ImageView::set_reverse(const bool& reverse) TITANIUM_NOEXCEPT
		{
			reverse__ = reverse;
		}

		void ImageView::JSExportInitialize()
		{
			JSExport<ImageView>::SetClassVersion(1);
			JSExport<ImageView>::SetParent(JSExport<View>::Class());
			// methods
			JSExport<ImageView>::AddFunctionProperty("pause", std::mem_fn(&ImageView::js_pause));
			JSExport<ImageView>::AddFunctionProperty("resume", std::mem_fn(&ImageView::js_resume ));
			JSExport<ImageView>::AddFunctionProperty("start", std::mem_fn(&ImageView::js_start));
			JSExport<ImageView>::AddFunctionProperty("stop", std::mem_fn(&ImageView::js_stop));
			JSExport<ImageView>::AddFunctionProperty("toBlob", std::mem_fn(&ImageView::js_toBlob));
			// properties
			JSExport<ImageView>::AddValueProperty("animating", std::mem_fn(&ImageView::js_get_animating));
			JSExport<ImageView>::AddValueProperty("autorotate", std::mem_fn(&ImageView::js_get_autorotate), std::mem_fn(&ImageView::js_set_autorotate));
			JSExport<ImageView>::AddValueProperty("decodeRetries", std::mem_fn(&ImageView::js_get_decodeRetries), std::mem_fn(&ImageView::js_set_decodeRetries));
			JSExport<ImageView>::AddValueProperty("defaultImage", std::mem_fn(&ImageView::js_get_defaultImage), std::mem_fn(&ImageView::js_set_defaultImage));
			JSExport<ImageView>::AddValueProperty("duration", std::mem_fn(&ImageView::js_get_duration), std::mem_fn(&ImageView::js_set_duration));
			JSExport<ImageView>::AddValueProperty("enableZoomControls", std::mem_fn(&ImageView::js_get_enableZoomControls), std::mem_fn(&ImageView::js_set_enableZoomControls));
			JSExport<ImageView>::AddValueProperty("hires", std::mem_fn(&ImageView::js_get_hires), std::mem_fn(&ImageView::js_set_hires));
			JSExport<ImageView>::AddValueProperty("image", std::mem_fn(&ImageView::js_get_image), std::mem_fn(&ImageView::js_set_image));
			JSExport<ImageView>::AddValueProperty("images", std::mem_fn(&ImageView::js_get_images), std::mem_fn(&ImageView::js_set_images));
			JSExport<ImageView>::AddValueProperty("paused", std::mem_fn(&ImageView::js_get_paused));
			JSExport<ImageView>::AddValueProperty("preventDefaultImage", std::mem_fn(&ImageView::js_get_preventDefaultImage), std::mem_fn(&ImageView::js_set_preventDefaultImage));
			JSExport<ImageView>::AddValueProperty("repeatCount", std::mem_fn(&ImageView::js_get_repeatCount), std::mem_fn(&ImageView::js_set_repeatCount));
			JSExport<ImageView>::AddValueProperty("reverse", std::mem_fn(&ImageView::js_get_reverse), std::mem_fn(&ImageView::js_set_reverse));
			// accessor/setter methods
			JSExport<ImageView>::AddFunctionProperty("getAnimating", std::mem_fn(&ImageView::js_getAnimating));
			JSExport<ImageView>::AddFunctionProperty("getAutorotate", std::mem_fn(&ImageView::js_getAutorotate));
			JSExport<ImageView>::AddFunctionProperty("getDecodeRetries", std::mem_fn(&ImageView::js_getDecodeRetries));
			JSExport<ImageView>::AddFunctionProperty("setDecodeRetries", std::mem_fn(&ImageView::js_setDecodeRetries));
			JSExport<ImageView>::AddFunctionProperty("getDefaultImage", std::mem_fn(&ImageView::js_getDefaultImage));
			JSExport<ImageView>::AddFunctionProperty("setDefaultImage", std::mem_fn(&ImageView::js_setDefaultImage));
			JSExport<ImageView>::AddFunctionProperty("getDuration", std::mem_fn(&ImageView::js_getDuration));
			JSExport<ImageView>::AddFunctionProperty("setDuration", std::mem_fn(&ImageView::js_setDuration));
			JSExport<ImageView>::AddFunctionProperty("getEnableZoomControls", std::mem_fn(&ImageView::js_getEnableZoomControls));
			JSExport<ImageView>::AddFunctionProperty("setEnableZoomControls", std::mem_fn(&ImageView::js_setEnableZoomControls));
			JSExport<ImageView>::AddFunctionProperty("getHires", std::mem_fn(&ImageView::js_getHires));
			JSExport<ImageView>::AddFunctionProperty("setHires", std::mem_fn(&ImageView::js_setHires));
			JSExport<ImageView>::AddFunctionProperty("getImage", std::mem_fn(&ImageView::js_getImage));
			JSExport<ImageView>::AddFunctionProperty("setImage", std::mem_fn(&ImageView::js_setImage));
			JSExport<ImageView>::AddFunctionProperty("getImages", std::mem_fn(&ImageView::js_getImages));
			JSExport<ImageView>::AddFunctionProperty("setImages", std::mem_fn(&ImageView::js_setImages));
			JSExport<ImageView>::AddFunctionProperty("getPaused", std::mem_fn(&ImageView::js_getPaused));
			JSExport<ImageView>::AddFunctionProperty("getPreventDefaultImage", std::mem_fn(&ImageView::js_getPreventDefaultImage));
			JSExport<ImageView>::AddFunctionProperty("setPreventDefaultImage", std::mem_fn(&ImageView::js_setPreventDefaultImage));
			JSExport<ImageView>::AddFunctionProperty("getRepeatCount", std::mem_fn(&ImageView::js_getRepeatCount));
			JSExport<ImageView>::AddFunctionProperty("setRepeatCount", std::mem_fn(&ImageView::js_setRepeatCount));
			JSExport<ImageView>::AddFunctionProperty("getReverse", std::mem_fn(&ImageView::js_getReverse));
			JSExport<ImageView>::AddFunctionProperty("setReverse", std::mem_fn(&ImageView::js_setReverse));
		}

		JSValue ImageView::js_pause(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.empty());
			pause();
			return get_context().CreateUndefined();
		}

		JSValue ImageView::js_resume(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.empty());
			resume();
			return get_context().CreateUndefined();
		}

		JSValue ImageView::js_start(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.empty());
			start();
			return get_context().CreateUndefined();
		}

		JSValue ImageView::js_stop(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.empty());
			stop();
			return get_context().CreateUndefined();
		}

		JSValue ImageView::js_toBlob(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.empty());
			auto blob = toBlob();
			if (blob == nullptr) {
				return get_context().CreateNull();
			}
			return blob->get_object();
		}

		JSValue ImageView::js_get_animating() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(get_animating());
		}

		JSValue ImageView::js_get_autorotate() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(get_autorotate());
		}

		bool ImageView::js_set_autorotate(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_autorotate(static_cast<bool>(argument));
			return true;
		}

		JSValue ImageView::js_get_decodeRetries() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(get_decodeRetries());
		}

		bool ImageView::js_set_decodeRetries(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_decodeRetries(static_cast<uint32_t>(argument));
			return true;
		}

		JSValue ImageView::js_get_defaultImage() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(get_defaultImage());
		}

		bool ImageView::js_set_defaultImage(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsString());
			std::string path = static_cast<std::string>(argument);
			set_defaultImage(static_cast<std::string>(argument));
			return true;
		}

		JSValue ImageView::js_get_duration() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(static_cast<double>(duration__.count()));
		}

		bool ImageView::js_set_duration(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsNumber());
			const auto duration = std::chrono::milliseconds(static_cast<std::chrono::milliseconds::rep>(static_cast<std::uint32_t>(argument)));
			set_duration(duration);
			return true;
		}

		JSValue ImageView::js_get_enableZoomControls() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(get_enableZoomControls());
		}

		bool ImageView::js_set_enableZoomControls(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_enableZoomControls(static_cast<bool>(argument));
			return true;
		}

		JSValue ImageView::js_get_hires() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(get_hires());
		}

		bool ImageView::js_set_hires(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_hires(static_cast<bool>(argument));
			return true;
		}

		JSValue ImageView::js_get_image() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(get_image());
		}

		bool ImageView::js_set_image(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsString());
			set_image(static_cast<std::string>(argument));
			return true;
		}

		JSValue ImageView::js_get_images() const TITANIUM_NOEXCEPT
		{
			std::vector<JSValue> images;
			for (auto image : get_images()) {
				images.push_back(get_context().CreateString(image));
			}
			return get_context().CreateArray(images);
		}

		bool ImageView::js_set_images(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsObject());
			auto object = static_cast<JSObject>(argument);
			TITANIUM_ASSERT(object.IsArray());
			
			std::vector<std::string> images;
			const auto item_count = object.GetPropertyNames().GetCount();
			for (uint32_t i = 0; i < item_count; ++i) {
				JSValue item = object.GetProperty(i);
				TITANIUM_ASSERT(item.IsString());
				images.push_back(static_cast<std::string>(item));
			}
			set_images(images);
			return true;
		}

		JSValue ImageView::js_get_paused() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(get_paused());
		}

		JSValue ImageView::js_get_preventDefaultImage() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(get_preventDefaultImage());
		}

		bool ImageView::js_set_preventDefaultImage(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_preventDefaultImage(static_cast<bool>(argument));
			return true;
		}

		JSValue ImageView::js_get_repeatCount() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(get_repeatCount());
		}

		bool ImageView::js_set_repeatCount(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_repeatCount(static_cast<uint32_t>(argument));
			return true;
		}

		JSValue ImageView::js_get_reverse() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(get_reverse());
		}

		bool ImageView::js_set_reverse(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_reverse(static_cast<bool>(argument));
			return true;
		}

		JSValue ImageView::js_getAnimating(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_animating();
		}

		JSValue ImageView::js_getAutorotate(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_autorotate();
		}

		JSValue ImageView::js_getDecodeRetries(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_decodeRetries();
		}

		JSValue ImageView::js_setDecodeRetries(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_decodeRetries(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue ImageView::js_getDefaultImage(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_defaultImage();
		}

		JSValue ImageView::js_setDefaultImage(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_defaultImage(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue ImageView::js_getDuration(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_duration();
		}

		JSValue ImageView::js_setDuration(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_duration(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue ImageView::js_getEnableZoomControls(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_enableZoomControls();
		}

		JSValue ImageView::js_setEnableZoomControls(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_enableZoomControls(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue ImageView::js_getHires(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_hires();
		}

		JSValue ImageView::js_setHires(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_hires(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue ImageView::js_getImage(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_image();
		}

		JSValue ImageView::js_setImage(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_image(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue ImageView::js_getImages(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_images();
		}

		JSValue ImageView::js_setImages(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_images(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue ImageView::js_getPaused(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_paused();
		}

		JSValue ImageView::js_getPreventDefaultImage(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_preventDefaultImage();
		}

		JSValue ImageView::js_setPreventDefaultImage(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_preventDefaultImage(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue ImageView::js_getRepeatCount(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_repeatCount();
		}

		JSValue ImageView::js_setRepeatCount(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_repeatCount(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue ImageView::js_getReverse(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_reverse();
		}

		JSValue ImageView::js_setReverse(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_reverse(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}
	} // namespace UI
}  // namespace Titanium
