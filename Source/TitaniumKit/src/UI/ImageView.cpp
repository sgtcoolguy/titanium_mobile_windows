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
			TITANIUM_ADD_FUNCTION(ImageView, pause);
			TITANIUM_ADD_FUNCTION(ImageView, resume);
			TITANIUM_ADD_FUNCTION(ImageView, start);
			TITANIUM_ADD_FUNCTION(ImageView, stop);
			TITANIUM_ADD_FUNCTION(ImageView, toBlob);
			// properties
			TITANIUM_ADD_PROPERTY_READONLY(ImageView, animating);
			TITANIUM_ADD_PROPERTY(ImageView, autorotate);
			TITANIUM_ADD_PROPERTY(ImageView, decodeRetries);
			TITANIUM_ADD_PROPERTY(ImageView, defaultImage);
			TITANIUM_ADD_PROPERTY(ImageView, duration);
			TITANIUM_ADD_PROPERTY(ImageView, enableZoomControls);
			TITANIUM_ADD_PROPERTY(ImageView, hires);
			TITANIUM_ADD_PROPERTY(ImageView, image);
			TITANIUM_ADD_PROPERTY(ImageView, images);
			TITANIUM_ADD_PROPERTY_READONLY(ImageView, paused);
			TITANIUM_ADD_PROPERTY(ImageView, preventDefaultImage);
			TITANIUM_ADD_PROPERTY(ImageView, repeatCount);
			TITANIUM_ADD_PROPERTY(ImageView, reverse);
			// accessor/setter methods
			TITANIUM_ADD_FUNCTION(ImageView, getAnimating);
			TITANIUM_ADD_FUNCTION(ImageView, getAutorotate);
			TITANIUM_ADD_FUNCTION(ImageView, getDecodeRetries);
			TITANIUM_ADD_FUNCTION(ImageView, setDecodeRetries);
			TITANIUM_ADD_FUNCTION(ImageView, getDefaultImage);
			TITANIUM_ADD_FUNCTION(ImageView, setDefaultImage);
			TITANIUM_ADD_FUNCTION(ImageView, getDuration);
			TITANIUM_ADD_FUNCTION(ImageView, setDuration);
			TITANIUM_ADD_FUNCTION(ImageView, getEnableZoomControls);
			TITANIUM_ADD_FUNCTION(ImageView, setEnableZoomControls);
			TITANIUM_ADD_FUNCTION(ImageView, getHires);
			TITANIUM_ADD_FUNCTION(ImageView, setHires);
			TITANIUM_ADD_FUNCTION(ImageView, getImage);
			TITANIUM_ADD_FUNCTION(ImageView, setImage);
			TITANIUM_ADD_FUNCTION(ImageView, getImages);
			TITANIUM_ADD_FUNCTION(ImageView, setImages);
			TITANIUM_ADD_FUNCTION(ImageView, getPaused);
			TITANIUM_ADD_FUNCTION(ImageView, getPreventDefaultImage);
			TITANIUM_ADD_FUNCTION(ImageView, setPreventDefaultImage);
			TITANIUM_ADD_FUNCTION(ImageView, getRepeatCount);
			TITANIUM_ADD_FUNCTION(ImageView, setRepeatCount);
			TITANIUM_ADD_FUNCTION(ImageView, getReverse);
			TITANIUM_ADD_FUNCTION(ImageView, setReverse);
		}

		TITANIUM_FUNCTION(ImageView, pause)
		{
			TITANIUM_ASSERT(arguments.empty());
			pause();
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ImageView, resume)
		{
			TITANIUM_ASSERT(arguments.empty());
			resume();
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ImageView, start)
		{
			TITANIUM_ASSERT(arguments.empty());
			start();
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ImageView, stop)
		{
			TITANIUM_ASSERT(arguments.empty());
			stop();
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ImageView, toBlob)
		{
			TITANIUM_ASSERT(arguments.empty());
			auto blob = toBlob();
			if (blob == nullptr) {
				return get_context().CreateNull();
			}
			return blob->get_object();
		}

		TITANIUM_PROPERTY_GETTER(ImageView, animating)
		{
			return get_context().CreateBoolean(get_animating());
		}

		TITANIUM_PROPERTY_GETTER(ImageView, autorotate)
		{
			return get_context().CreateBoolean(get_autorotate());
		}

		TITANIUM_PROPERTY_SETTER(ImageView, autorotate)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_autorotate(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ImageView, decodeRetries)
		{
			return get_context().CreateNumber(get_decodeRetries());
		}

		TITANIUM_PROPERTY_SETTER(ImageView, decodeRetries)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_decodeRetries(static_cast<uint32_t>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ImageView, defaultImage)
		{
			return get_context().CreateString(get_defaultImage());
		}

		TITANIUM_PROPERTY_SETTER(ImageView, defaultImage)
		{
			TITANIUM_ASSERT(argument.IsString());
			std::string path = static_cast<std::string>(argument);
			set_defaultImage(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ImageView, duration)
		{
			return get_context().CreateNumber(static_cast<double>(duration__.count()));
		}

		TITANIUM_PROPERTY_SETTER(ImageView, duration)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			const auto duration = std::chrono::milliseconds(static_cast<std::chrono::milliseconds::rep>(static_cast<std::uint32_t>(argument)));
			set_duration(duration);
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ImageView, enableZoomControls)
		{
			return get_context().CreateBoolean(get_enableZoomControls());
		}

		TITANIUM_PROPERTY_SETTER(ImageView, enableZoomControls)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_enableZoomControls(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ImageView, hires)
		{
			return get_context().CreateBoolean(get_hires());
		}

		TITANIUM_PROPERTY_SETTER(ImageView, hires)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_hires(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ImageView, image)
		{
			return get_context().CreateString(get_image());
		}

		TITANIUM_PROPERTY_SETTER(ImageView, image)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_image(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ImageView, images)
		{
			std::vector<JSValue> images;
			for (auto image : get_images()) {
				images.push_back(get_context().CreateString(image));
			}
			return get_context().CreateArray(images);
		}

		TITANIUM_PROPERTY_SETTER(ImageView, images)
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

		TITANIUM_PROPERTY_GETTER(ImageView, paused)
		{
			return get_context().CreateBoolean(get_paused());
		}

		TITANIUM_PROPERTY_GETTER(ImageView, preventDefaultImage)
		{
			return get_context().CreateBoolean(get_preventDefaultImage());
		}

		TITANIUM_PROPERTY_SETTER(ImageView, preventDefaultImage)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_preventDefaultImage(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ImageView, repeatCount)
		{
			return get_context().CreateNumber(get_repeatCount());
		}

		TITANIUM_PROPERTY_SETTER(ImageView, repeatCount)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_repeatCount(static_cast<uint32_t>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ImageView, reverse)
		{
			return get_context().CreateBoolean(get_reverse());
		}

		TITANIUM_PROPERTY_SETTER(ImageView, reverse)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_reverse(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_FUNCTION(ImageView, getAnimating)
		{
			return js_get_animating();
		}

		TITANIUM_FUNCTION(ImageView, getAutorotate)
		{
			return js_get_autorotate();
		}

		TITANIUM_FUNCTION(ImageView, getDecodeRetries)
		{
			return js_get_decodeRetries();
		}

		TITANIUM_FUNCTION(ImageView, setDecodeRetries)
		{
			if (arguments.size() >= 1) {
				js_set_decodeRetries(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ImageView, getDefaultImage)
		{
			return js_get_defaultImage();
		}

		TITANIUM_FUNCTION(ImageView, setDefaultImage)
		{
			if (arguments.size() >= 1) {
				js_set_defaultImage(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ImageView, getDuration)
		{
			return js_get_duration();
		}

		TITANIUM_FUNCTION(ImageView, setDuration)
		{
			if (arguments.size() >= 1) {
				js_set_duration(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ImageView, getEnableZoomControls)
		{
			return js_get_enableZoomControls();
		}

		TITANIUM_FUNCTION(ImageView, setEnableZoomControls)
		{
			if (arguments.size() >= 1) {
				js_set_enableZoomControls(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ImageView, getHires)
		{
			return js_get_hires();
		}

		TITANIUM_FUNCTION(ImageView, setHires)
		{
			if (arguments.size() >= 1) {
				js_set_hires(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ImageView, getImage)
		{
			return js_get_image();
		}

		TITANIUM_FUNCTION(ImageView, setImage)
		{
			if (arguments.size() >= 1) {
				js_set_image(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ImageView, getImages)
		{
			return js_get_images();
		}

		TITANIUM_FUNCTION(ImageView, setImages)
		{
			if (arguments.size() >= 1) {
				js_set_images(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ImageView, getPaused)
		{
			return js_get_paused();
		}

		TITANIUM_FUNCTION(ImageView, getPreventDefaultImage)
		{
			return js_get_preventDefaultImage();
		}

		TITANIUM_FUNCTION(ImageView, setPreventDefaultImage)
		{
			if (arguments.size() >= 1) {
				js_set_preventDefaultImage(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ImageView, getRepeatCount)
		{
			return js_get_repeatCount();
		}

		TITANIUM_FUNCTION(ImageView, setRepeatCount)
		{
			if (arguments.size() >= 1) {
				js_set_repeatCount(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ImageView, getReverse)
		{
			return js_get_reverse();
		}

		TITANIUM_FUNCTION(ImageView, setReverse)
		{
			if (arguments.size() >= 1) {
				js_set_reverse(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}
	} // namespace UI
}  // namespace Titanium
