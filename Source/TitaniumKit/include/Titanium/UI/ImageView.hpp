/**
 * TitaniumKit
 *
 * Copyright (c) 2014-2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_UI_IMAGEVIEW_HPP_
#define _TITANIUM_UI_IMAGEVIEW_HPP_

#include "Titanium/Blob.hpp"
#include "Titanium/UI/View.hpp"

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		/*!
		  @class

		  @discussion This is the Titanium UI ImageView.

		  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.UI.ImageView
		*/
		class TITANIUMKIT_EXPORT ImageView : public View, public JSExport<ImageView>
		{
		public:

			/*!
			  @method

			  @abstract start() : void

			  @discussion Starts the image animation. On Android and Mobile Web, also resets index to the first image.

			  This method only works if multiple images are specified.

			  @result void
			*/
			virtual void start() TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract stop() : void

			  @discussion Stops a running animation. On iOS and Mobile Web, also resets index to the first image.

			  This method only works if multiple images are specified.

			  @result void
			*/
			virtual void stop() TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract pause() : void

			  @discussion Pauses a running animation. Use resume method to continue.

			  This method only works if multiple images are specified.

			  @result void
			*/
			virtual void pause() TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract resume() : void

			  @discussion Resumes an animation from a pause state.

			  This method only works if multiple images are specified.

			  @result void
			*/
			virtual void resume() TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract toBlob() : Titanium.Blob

			  @discussion Returns the image as a Blob object.

			  @result Titanium.Blob
			*/
			virtual std::shared_ptr<Titanium::Blob> toBlob() TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract animating : Boolean

			  @discussion Indicates whether animation is running.

			  Default: false on creation, true on load (Android), false (iPhone, iPad, Mobile Web, Tizen)
			*/
			virtual bool get_animating() const TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract autorotate : Boolean

			  @discussion Indicates whether the image should be rotated based on exif orientation data. By default, this is false on android and true on iOS. The auto rotate behavior is not supported on Mobile Web and Tizen.

			  Default: false on android, true on iOS.
			*/
			virtual bool get_autorotate() const TITANIUM_NOEXCEPT;
			virtual void set_autorotate(const bool& autorotate) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract decodeRetries : Number

			  @discussion Number of times to retry decoding the bitmap at a URL.

			  Default: 5
			*/
			virtual uint32_t get_decodeRetries() const TITANIUM_NOEXCEPT final;
			virtual void set_decodeRetries(const uint32_t& decodeRetries) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract defaultImage : String

			  @discussion Local path to the default image to display while loading a remote image.
			*/
			virtual std::string get_defaultImage() const TITANIUM_NOEXCEPT final;
			virtual void set_defaultImage(const std::string& defaultImage) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract duration : Number

			  @discussion Amount of time in milliseconds to animate one cycle.

			  Starting with release 2.1.1, the minimum duration is 30 ms and the default duration is 200 ms.

			  On Android, prior to release 2.1.1, if any images are assigned to the images property when the animation is started, duration will be set to the number of images multiplied by 33 ms. If no images are assigned, duration will be set to 100 ms.

			  On iOS, Tizen and Mobile Web, prior to release 2.1.1, the default is 30 ms.

			  On Android, if the value of duration is changed, stop and start need to be called for the new value to take effect.

			  Default: 200 ms in Release 2.1.1 and later. Platform-specific default in earlier releases.
			*/
			virtual std::chrono::milliseconds get_duration() const TITANIUM_NOEXCEPT final;
			virtual void set_duration(const std::chrono::milliseconds& duration) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract enableZoomControls : Boolean

			  @discussion Show zoom controls when the user touches the image view.

			  Default: false
			*/
			virtual bool get_enableZoomControls() const TITANIUM_NOEXCEPT final;
			virtual void set_enableZoomControls(const bool& enableZoomControls) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract hires : Boolean

			  @discussion Set to true to prevent scaling of 2x-resolution remote images for Retina displays.

			  Causes images to display at 50%, where one pixel of the graphic maps to one physical pixel on-screen. This functionality is automatically determined for local images via their filenames, and thus this property is only applicable to remote images.

			  Default: false
			*/
			virtual bool get_hires() const TITANIUM_NOEXCEPT final;
			virtual void set_hires(const bool& hires) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract image : String/Titanium.Blob/Titanium.Filesystem.File

			  @discussion Image to display.

			  Image to display, defined using a local filesystem path, a File object, a remote URL, or a Blob object containing image data. Blob and File objects are not supported on Mobile Web.
			*/
			virtual std::string get_image() const TITANIUM_NOEXCEPT final;
			virtual void set_image(const std::string& image) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract image : String[]/Titanium.Blob[]/Titanium.Filesystem.File[]

			  @discussion Array of images to animate, defined using local filesystem paths, File objects, remote URLs (Android only), or Blob objects containing image data. Blob and File objects are not supported on Mobile Web.
			*/
			virtual std::vector<std::string> get_images() const TITANIUM_NOEXCEPT final;
			virtual void set_images(const std::vector<std::string>& images) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract paused : Boolean

			  @discussion Indicates whether the animation is paused.

			  Default: false
			*/
			virtual bool get_paused() const TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract preventDefaultImage : Boolean

			  @discussion Prevent the default image from being displayed while loading a remote image. This property is ignored when the defaultImage property is set.

			  Default: false
			*/
			virtual bool get_preventDefaultImage() const TITANIUM_NOEXCEPT final;
			virtual void set_preventDefaultImage(const bool& preventDefaultImage) TITANIUM_NOEXCEPT;


			/*!
			  @method

			  @abstract repeatCount : Number

			  @discussion umber of times to repeat the image animation.

			  Default: 0 (infinite)
			*/
			virtual uint32_t get_repeatCount() const TITANIUM_NOEXCEPT final;
			virtual void set_repeatCount(const uint32_t& repeatCount) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract reverse : Boolean

			  @discussion Run the animation in reverse.

			  Default: false
			*/
			virtual bool get_reverse() const TITANIUM_NOEXCEPT final;
			virtual void set_reverse(const bool& reverse) TITANIUM_NOEXCEPT;

			ImageView(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~ImageView() = default;
			ImageView(const ImageView&) = default;
			ImageView& operator=(const ImageView&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			ImageView(ImageView&&) = default;
			ImageView& operator=(ImageView&&) = default;
#endif

			static void JSExportInitialize();
			// methods
			TITANIUM_FUNCTION_DEF(start);
			TITANIUM_FUNCTION_DEF(stop);
			TITANIUM_FUNCTION_DEF(pause);
			TITANIUM_FUNCTION_DEF(resume);
			TITANIUM_FUNCTION_DEF(toBlob);

			// properties
			TITANIUM_PROPERTY_READONLY_DEF(animating);
			TITANIUM_FUNCTION_DEF(getAnimating);

			TITANIUM_PROPERTY_DEF(autorotate);
			TITANIUM_FUNCTION_DEF(getAutorotate);

			TITANIUM_PROPERTY_DEF(decodeRetries);
			TITANIUM_FUNCTION_DEF(getDecodeRetries);
			TITANIUM_FUNCTION_DEF(setDecodeRetries);

			TITANIUM_PROPERTY_DEF(defaultImage);
			TITANIUM_FUNCTION_DEF(getDefaultImage);
			TITANIUM_FUNCTION_DEF(setDefaultImage);

			TITANIUM_PROPERTY_DEF(duration);
			TITANIUM_FUNCTION_DEF(getDuration);
			TITANIUM_FUNCTION_DEF(setDuration);

			TITANIUM_PROPERTY_DEF(enableZoomControls);
			TITANIUM_FUNCTION_DEF(getEnableZoomControls);
			TITANIUM_FUNCTION_DEF(setEnableZoomControls);

			TITANIUM_PROPERTY_DEF(hires);
			TITANIUM_FUNCTION_DEF(getHires);
			TITANIUM_FUNCTION_DEF(setHires);

			TITANIUM_PROPERTY_DEF(image);
			TITANIUM_FUNCTION_DEF(getImage);
			TITANIUM_FUNCTION_DEF(setImage);

			TITANIUM_PROPERTY_DEF(images);
			TITANIUM_FUNCTION_DEF(getImages);
			TITANIUM_FUNCTION_DEF(setImages);

			TITANIUM_PROPERTY_READONLY_DEF(paused);
			TITANIUM_FUNCTION_DEF(getPaused);

			TITANIUM_PROPERTY_DEF(preventDefaultImage);
			TITANIUM_FUNCTION_DEF(getPreventDefaultImage);
			TITANIUM_FUNCTION_DEF(setPreventDefaultImage);

			TITANIUM_PROPERTY_DEF(repeatCount);
			TITANIUM_FUNCTION_DEF(getRepeatCount);
			TITANIUM_FUNCTION_DEF(setRepeatCount);

			TITANIUM_PROPERTY_DEF(reverse);
			TITANIUM_FUNCTION_DEF(getReverse);
			TITANIUM_FUNCTION_DEF(setReverse);

		private:
#pragma warning(push)
#pragma warning(disable : 4251)
			bool autorotate__;
			uint32_t decodeRetries__;
			std::string defaultImage__;
			std::chrono::milliseconds duration__;
			bool enableZoomControls__;
			bool hires__;
			std::string image__;
			std::vector<std::string> images__;
			bool preventDefaultImage__;
			uint32_t repeatCount__;
			bool reverse__;
#pragma warning(pop)
		};
	} // namespace UI
}  // namespace Titanium

#endif  // _TITANIUM_UI_IMAGEVIEW_HPP_
