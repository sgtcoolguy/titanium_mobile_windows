/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_MEDIAMODULE_HPP_
#define _TITANIUMWINDOWS_MEDIAMODULE_HPP_

#include "TitaniumWindows_Media_EXPORT.h"
#include "Titanium/MediaModule.hpp"
#include <agile.h>
#include <collection.h>

namespace TitaniumWindows
{
	using namespace HAL;

	/*!
	  @class

	  @discussion This is the Titanium.Media implementation for Windows.
	*/
	class TITANIUMWINDOWS_MEDIA_EXPORT MediaModule final : public Titanium::MediaModule, public JSExport<MediaModule>
	{
	public:

		/*!
		  @method
		  @abstract beep
		  @discussion Plays a device beep notification.
		*/
		virtual void beep() TITANIUM_NOEXCEPT override;

		/*!
		  @method
		  @abstract hideCamera
		  @discussion Hides the device camera UI.
		*/
		virtual void hideCamera() TITANIUM_NOEXCEPT override;

		/*!
		  @method
		  @abstract hideMusicLibrary
		  @discussion Hides the music library.
		*/
		virtual void hideMusicLibrary() TITANIUM_NOEXCEPT override;

		/*!
		  @method
		  @abstract isMediaTypeSupported
		  @discussion Returns `true` if the source supports the specified media type.
		*/
		virtual bool isMediaTypeSupported(const std::string& source, const Titanium::Media::MediaType& type) TITANIUM_NOEXCEPT override;

		/*!
		  @method
		  @abstract openMusicLibrary
		  @discussion Shows the music library and allows the user to select one or more tracks.
		*/
		virtual void openMusicLibrary(const Titanium::Media::MusicLibraryOptionsType& options) TITANIUM_NOEXCEPT override;

		/*!
		  @method
		  @abstract openPhotoGallery
		  @discussion Opens the photo gallery image picker.
		*/
		virtual void openPhotoGallery(const Titanium::Media::PhotoGalleryOptionsType& options) TITANIUM_NOEXCEPT override;

		/*!
		  @method
		  @abstract previewImage
		  @discussion Displays the given image.
		*/
		virtual void previewImage(const std::unordered_map<std::string, Titanium::Media::PreviewImageOptions>& options) TITANIUM_NOEXCEPT override;

		/*!
		  @method
		  @abstract saveToPhotoGallery
		  @discussion Saves media to the device's photo gallery / camera roll.
		*/
		virtual void saveToPhotoGallery(const std::shared_ptr<Titanium::Filesystem::File>& media, JSValue callbacks) TITANIUM_NOEXCEPT override;

		/*!
		  @method
		  @abstract setOverrideAudioRoute
		  @discussion Overrides the default audio route when using the <Titanium.Media.AUDIO_SESSION_MODE_PLAY_AND_RECORD> session mode.
		*/
		virtual void setOverrideAudioRoute(const Titanium::Media::AudioSessionOverrideRoute& route) TITANIUM_NOEXCEPT override;

		/*!
		  @method
		  @abstract showCamera
		  @discussion Shows the camera.
		*/
		virtual void showCamera(const Titanium::Media::CameraOptionsType& options) TITANIUM_NOEXCEPT override;

		/*!
		  @method
		  @abstract queryMusicLibrary
		  @discussion Searches the music library for items matching the specified search predicates.
		*/
		virtual std::vector<std::shared_ptr<Titanium::Media::Item>> queryMusicLibrary(const Titanium::Media::MediaQueryType& query) TITANIUM_NOEXCEPT override;

		/*!
		  @method
		  @abstract startMicrophoneMonitor
		  @discussion Starts monitoring the microphone sound level.
		*/
		virtual void startMicrophoneMonitor() TITANIUM_NOEXCEPT override;

		/*!
		  @method
		  @abstract stopMicrophoneMonitor
		  @discussion Stops monitoring the microphone sound level.
		*/
		virtual void stopMicrophoneMonitor() TITANIUM_NOEXCEPT override;

		/*!
		  @method
		  @abstract takePicture
		  @discussion Uses the device camera to capture a photo.
		*/
		virtual void takePicture() TITANIUM_NOEXCEPT override;

		/*!
		  @method
		  @abstract startVideoCapture
		  @discussion Starts video capture using the camera specified.
		*/
		virtual void startVideoCapture() TITANIUM_NOEXCEPT override;

		/*!
		  @method
		  @abstract stopVideoCapture
		  @discussion Stops video capture using the camera specified.
		*/
		virtual void stopVideoCapture() TITANIUM_NOEXCEPT override;

		/*!
		  @method
		  @abstract switchCamera
		  @discussion Switches between front and rear-facing cameras.
		*/
		virtual void switchCamera(const Titanium::Media::CameraOption& camera) TITANIUM_NOEXCEPT override;

		/*!
		  @method
		  @abstract takeScreenshot
		  @discussion Takes a screen shot of the visible UI on the device.
		*/
		virtual void takeScreenshot(JSValue callback) TITANIUM_NOEXCEPT override;

		/*!
		  @method
		  @abstract vibrate
		  @discussion Makes the device vibrate.
		*/
		virtual void vibrate(std::vector<std::chrono::milliseconds> pattern) TITANIUM_NOEXCEPT override;

		MediaModule(const JSContext&) TITANIUM_NOEXCEPT;

		virtual ~MediaModule();
		MediaModule(const MediaModule&) = default;
		MediaModule& operator=(const MediaModule&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
		MediaModule(MediaModule&&) = default;
		MediaModule& operator=(MediaModule&&) = default;
#endif

		static void JSExportInitialize();

		virtual void enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT override final;
		virtual void disableEvent(const std::string& event_name) TITANIUM_NOEXCEPT override final;

		void fireMediaVolumeEvent(const Windows::Media::SoundLevel& level);

	protected:

		JSFunction createFileOpenFromPickerFunction(const JSContext& js_context) const TITANIUM_NOEXCEPT;
		void takeScreenshotDone(JSObject callback, const std::string& file = "", const bool& hasError = true);
		void clearScreenshotResources();
		void takeScreenshotToFile(JSObject callback);

#pragma warning(push)
#pragma warning(disable : 4251)
		Windows::Foundation::EventRegistrationToken audioMonitoring_token__;
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
		bool screenCaptureStarted__ { false };
		bool cameraPreviewStarted__ { false };
		bool waitingToBeRestoredFromPicker { false };
		JSObject fileOpenFromPickerCallback__;
		::Platform::Agile<Windows::Media::Capture::MediaCapture> mediaCapture__;
		::Platform::Collections::Vector<Windows::UI::Xaml::DispatcherTimer^>^ vibrate_timers__;
		Windows::UI::Xaml::Controls::CaptureElement^ captureElement__;
		Windows::Foundation::EventRegistrationToken camera_navigated_event__;
#else

#endif

#pragma warning(pop)
	};

}  

#endif  // _TITANIUMWINDOWS_MEDIAMODULE_HPP_
