/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/Media.hpp"
#include "Titanium/Filesystem/File.hpp"
#include "Titanium/Media/Item.hpp"
#include "Titanium/Media/CameraOptionsType.hpp"
#include "TitaniumWindows/Utility.hpp"
#include "Titanium/detail/TiImpl.hpp"
#include <ppltasks.h>

namespace TitaniumWindows
{
	using namespace Windows::Foundation;
	using namespace Windows::Storage;
	using namespace Windows::Media;
	using namespace Windows::Media::Capture;
	using namespace Windows::Media::MediaProperties;

	void MediaModule::beep() TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::beep: Unimplemented");
	}

	void MediaModule::hideCamera() TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::hideCamera: Unimplemented");
	}

	void MediaModule::hideMusicLibrary() TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::hideMusicLibrary: Unimplemented");
	}

	bool MediaModule::isMediaTypeSupported(const std::string& source, const std::string& type) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::isMediaTypeSupported: Unimplemented");
		return false;
	}

	void MediaModule::openMusicLibrary(const Titanium::Media::MusicLibraryOptionsType& options) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::openMusicLibrary: Unimplemented");
	}

	void MediaModule::openPhotoGallery(const Titanium::Media::PhotoGalleryOptionsType& options) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::openPhotoGallery: Unimplemented");
	}

	void MediaModule::previewImage(const std::unordered_map<std::string, Titanium::Media::PreviewImageOptions>& options) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::previewImage: Unimplemented");
	}

	void MediaModule::saveToPhotoGallery(const std::shared_ptr<Titanium::Filesystem::File>& media, JSValue callbacks) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::saveToPhotoGallery: Unimplemented");
	}

	void MediaModule::setOverrideAudioRoute(const Titanium::Media::AudioSessionOverrideRoute& route) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::setOverrideAudioRoute: Unimplemented");
	}

	void MediaModule::showCamera(const Titanium::Media::CameraOptionsType& options) TITANIUM_NOEXCEPT
	{
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP

#else
		auto cameraCaptureUI = ref new CameraCaptureUI();

		// TODO: Provide a option to specify aspect ratio
		cameraCaptureUI->PhotoSettings->CroppedAspectRatio = Size(16, 9);

		concurrency::task<StorageFile^>(cameraCaptureUI->CaptureFileAsync(CameraCaptureUIMode::Photo)).then([options, this](StorageFile^ file) {
			if (nullptr != file) {
				Titanium::Media::CameraMediaItemType item;
				item.mediaType = Titanium::Media::MediaType::Photo;

				// Construct Blob from Ti.Fiilesystem.File object
				if (file != nullptr) {
					const auto ctx = get_context();
					const auto getFile_property = ctx.JSEvaluateScript("Ti.Filesystem.getFile");
					TITANIUM_ASSERT(getFile_property.IsObject());
					auto getFile = static_cast<JSObject>(getFile_property);
					const std::vector<JSValue> args = { ctx.CreateString(TitaniumWindows::Utility::ConvertString(file->Path)) };
					const auto file = getFile(args, getFile);
					if (file.IsObject()) {
						item.media = static_cast<JSObject>(file).GetPrivate<Titanium::Filesystem::File>()->read();
					} else {
						item.error = "Failed to create media object from file";
					}
				} else {
					item.error = "Failed to take picture";
				}
				options.callbacks.onsuccess(item);
			} else {
				Titanium::ErrorResponse error;
				error.error = "Failed to take picture";
				error.success = false;
				options.callbacks.oncancel(error);
			}
		});
#endif
	}

	std::vector<std::shared_ptr<Titanium::Media::Item>> MediaModule::queryMusicLibrary(const Titanium::Media::MediaQueryType& query) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::queryMusicLibrary: Unimplemented");
		return std::vector<std::shared_ptr<Titanium::Media::Item>>();
	}

	void MediaModule::fireMediaVolumeEvent(const SoundLevel& level) {
		// There's only three level on Windows: Muted, Low and Full.
		// TODO: Find reasonable number for volume. Right now it's mapped to Muted=0, Low=0.5 and Full=1.
		auto obj = get_context().CreateObject();
		switch (level) {
		case SoundLevel::Muted:
			obj.SetProperty("volume", get_context().CreateNumber(0));
			break;
		case SoundLevel::Low:
			obj.SetProperty("volume", get_context().CreateNumber(0.5));
			break;
		case SoundLevel::Full:
			obj.SetProperty("volume", get_context().CreateNumber(1));
			break;
		default:
			TITANIUM_LOG_WARN("MediaModule: Unknown volume");
			obj.SetProperty("volume", get_context().CreateNumber(0));
			break;
		}
		fireEvent("volume", obj);
	}

	void MediaModule::startMicrophoneMonitor() TITANIUM_NOEXCEPT
	{
		SystemMediaTransportControls^ systemMediaControls = SystemMediaTransportControls::GetForCurrentView();
		audioCaptureMonitoring_token__ = systemMediaControls->PropertyChanged += ref new TypedEventHandler<SystemMediaTransportControls^, SystemMediaTransportControlsPropertyChangedEventArgs^>([this](SystemMediaTransportControls^ sender, SystemMediaTransportControlsPropertyChangedEventArgs^ e) {
			switch (e->Property) {
			case SystemMediaTransportControlsProperty::SoundLevel:
				fireMediaVolumeEvent(sender->SoundLevel);
				break;
			default:
				break;
			}
		});
	}

	void MediaModule::stopMicrophoneMonitor() TITANIUM_NOEXCEPT
	{
		SystemMediaTransportControls^ systemMediaControls = SystemMediaTransportControls::GetForCurrentView();
		systemMediaControls->PropertyChanged -= audioCaptureMonitoring_token__;
	}

	void MediaModule::takePicture() TITANIUM_NOEXCEPT
	{
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
		TITANIUM_LOG_WARN("MediaModule::takePicture: Unimplemented");
#else
		TITANIUM_LOG_WARN("MediaModule::takePicture: Not available for Windows Store app");
#endif
	}

	void MediaModule::startVideoCapture() TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::startVideoCapture: Unimplemented");
	}

	void MediaModule::stopVideoCapture() TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::stopVideoCapture: Unimplemented");
	}

	void MediaModule::switchCamera(const Titanium::Media::CameraOption& camera) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::switchCamera: Unimplemented");
	}

	void MediaModule::takeScreenshotDone() 
	{
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
		if (screenCaptureStarted__) {
			delete(screenMediaCapture__.Get());
			screenCaptureStarted__ = false;
		}
#endif
	}

	// Create new storage and start capturing!
	void MediaModule::takeScreenshotToFile()
	{
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
		concurrency::task<StorageFile^>(KnownFolders::VideosLibrary->CreateFileAsync("TiMediaScreenCapture.jpg", CreationCollisionOption::GenerateUniqueName)).then([this](concurrency::task<StorageFile^> fileTask) {
			try {
				auto screenMediaCaptureStorageFile = fileTask.get();

				// TODO: Provide an API to customize capture settings
				ImageEncodingProperties^ imageEncodingProperties = ImageEncodingProperties::CreateJpeg();
				concurrency::create_task(screenMediaCapture__->CapturePhotoToStorageFileAsync(imageEncodingProperties, screenMediaCaptureStorageFile)).then([this](concurrency::task<void> recordTask) {
					try {
						recordTask.get();
					} catch (Platform::Exception^ e) {
						// TODO: need to throw JavaScript exception or raise failure callback?
						TITANIUM_LOG_WARN("MediaModule: Failure on start capturing screen: ", TitaniumWindows::Utility::ConvertString(e->Message));
					}
					takeScreenshotDone();
				});
				// TODO: need to fire "started recording" callback because it's done by async?
			} catch (Platform::Exception^ e) {
				// TODO: need to throw JavaScript exception or raise failure callback?
				TITANIUM_LOG_WARN("MediaModule: Failure on start capturing screen: ", TitaniumWindows::Utility::ConvertString(e->Message));
				takeScreenshotDone();
			}
		});
#else
		TITANIUM_LOG_WARN("MediaModule::takeScreenshotToFile: Unimplemented");
#endif
	}

	void MediaModule::takeScreenshot(JSValue callback) TITANIUM_NOEXCEPT
	{
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
		// https://msdn.microsoft.com/en-us/library/windows/apps/xaml/dn642093.aspx
		auto screenCapture = ScreenCapture::GetForCurrentView();
		auto mediaCapture = ref new MediaCapture();

		screenMediaCapture__ = mediaCapture;
		screenCaptureStarted__ = true;

		// TODO: Provide an API for customizing capture settings
		auto settings = ref new MediaCaptureInitializationSettings();
		settings->VideoSource = screenCapture->VideoSource;
		settings->StreamingCaptureMode = StreamingCaptureMode::Video;

		concurrency::create_task(mediaCapture->InitializeAsync()).then([this](concurrency::task<void> initTask) {
			try {
				initTask.get();
				auto mediaCapture = screenMediaCapture__.Get();

				// TODO: need to throw JavaScript exception or raise failure callback?
				mediaCapture->RecordLimitationExceeded += ref new RecordLimitationExceededEventHandler([this](MediaCapture^ sender) {
					TITANIUM_LOG_WARN("MediaModule: Stopping screen capture on exceeding max record duration");
					takeScreenshotDone();
				});
				mediaCapture->Failed += ref new MediaCaptureFailedEventHandler([this](MediaCapture^ sender, MediaCaptureFailedEventArgs^ e) {
					TITANIUM_LOG_WARN("MediaModule: Failed to capture screen: ", TitaniumWindows::Utility::ConvertString(e->Message));
					takeScreenshotDone();
				});

				takeScreenshotToFile();
			} catch (Platform::Exception ^ e) {
				// TODO: need to throw JavaScript exception or raise failure callback?
				TITANIUM_LOG_WARN("MediaModule: Failed to initialize capture device: ", TitaniumWindows::Utility::ConvertString(e->Message));
				takeScreenshotDone();
			}
		});

#else
		TITANIUM_LOG_WARN("MediaModule::takeScreenshot: Unimplemented");
#endif
	}

	void MediaModule::vibrate(std::vector<std::chrono::milliseconds> pattern) TITANIUM_NOEXCEPT
	{
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
		using namespace Windows::Phone::Devices::Notification;
		const auto device = VibrationDevice::GetDefault();
		Windows::Foundation::TimeSpan duration;
		for (const auto msec : pattern) {
			duration.Duration = msec.count() * 10000;
			device->Vibrate(duration); // does this a blocking function so we can push durations like this?
		}
#else
		TITANIUM_LOG_WARN("MediaModule::vibrate: Unimplemented");
#endif
	}

	MediaModule::MediaModule(const JSContext& js_context) TITANIUM_NOEXCEPT
		: Titanium::MediaModule(js_context)
	{
		TITANIUM_LOG_DEBUG("TitaniumWindows::MediaModule::ctor Initialize");
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP

#endif
	}

	MediaModule::~MediaModule()
	{
		TITANIUM_LOG_DEBUG("TitaniumWindows::MediaModule::dtor");
	}

	void MediaModule::JSExportInitialize()
	{
		JSExport<MediaModule>::SetClassVersion(1);
		JSExport<MediaModule>::SetParent(JSExport<Titanium::MediaModule>::Class());
	}

	void MediaModule::enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
	{
		Titanium::Module::enableEvent(event_name);
	}

	void MediaModule::disableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
	{
		Titanium::Module::disableEvent(event_name);
	}
}
