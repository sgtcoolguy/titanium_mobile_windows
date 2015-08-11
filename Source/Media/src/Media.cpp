/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/Media.hpp"
#include "Titanium/Filesystem/File.hpp"
#include "Titanium/Media/Item.hpp"
#include "Titanium/Media/CameraOptionsType.hpp"
#include "Titanium/Media/PhotoGalleryOptionsType.hpp"
#include "TitaniumWindows/Utility.hpp"
#include "Titanium/detail/TiImpl.hpp"
#include "TitaniumWindows/AppModule.hpp"
#include <ppltasks.h>

#define GET_TITANIUM_APP(VARNAME) \
	const auto ctx = get_context(); \
  JSValue Titanium_property = ctx.get_global_object().GetProperty("Titanium"); \
  TITANIUM_ASSERT(Titanium_property.IsObject()); \
  JSObject Titanium = static_cast<JSObject>(Titanium_property); \
  JSValue App_property = Titanium.GetProperty("App"); \
  TITANIUM_ASSERT(App_property.IsObject()); \
  std::shared_ptr<TitaniumWindows::AppModule> VARNAME = static_cast<JSObject>(App_property).GetPrivate<TitaniumWindows::AppModule>();

namespace TitaniumWindows
{
	using namespace Windows::Foundation;
	using namespace Windows::Storage;
	using namespace Windows::Storage::Pickers;
	using namespace Windows::Media;
	using namespace Windows::Media::Capture;
	using namespace Windows::Media::MediaProperties;
	using namespace Windows::Devices::Enumeration;
	using namespace Windows::UI::Xaml;
	using namespace Windows::UI::Xaml::Controls;
	using namespace Platform::Collections;
	using namespace concurrency;

	JSFunction MediaModule::createFileOpenFromPickerFunction(const JSContext& js_context) const TITANIUM_NOEXCEPT
	{
		return js_context.CreateFunction(R"JS(
			Ti.App.removeEventListener('windows.fileOpenFromPicker', this);
			Ti.API._postOpenPhotoGallery(e.files);
		)JS", { "e" });
	}

	void MediaModule::beep() TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::beep: Unimplemented");
	}

	void MediaModule::hideMusicLibrary() TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::hideMusicLibrary: Unimplemented");
	}

	void MediaModule::openMusicLibrary(const Titanium::Media::MusicLibraryOptionsType& options) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::openMusicLibrary: Unimplemented");
	}

	void MediaModule::openPhotoGallery(const Titanium::Media::PhotoGalleryOptionsType& options) TITANIUM_NOEXCEPT
	{
		auto picker = ref new FileOpenPicker();
		picker->ViewMode = PickerViewMode::Thumbnail;
		picker->SuggestedStartLocation = PickerLocationId::PicturesLibrary;
		picker->FileTypeFilter->Append(".jpg");
		picker->FileTypeFilter->Append(".jpeg");
		picker->FileTypeFilter->Append(".png");
		picker->FileTypeFilter->Append(".gif");

#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
		// Listen to "windows.fileOpenFromPicker" event
		GET_TITANIUM_APP(App);
		App->addEventListener("windows.fileOpenFromPicker", fileOpenFromPickerCallback__, fileOpenFromPickerCallback__);
		waitingToBeRestoredFromPicker = true;
		picker->PickSingleFileAndContinue();
#else
		task<StorageFile^>(picker->PickSingleFileAsync()).then([this, options](task<StorageFile^> task) {
			const auto file = task.get();
			if (file == nullptr) {
				Titanium::ErrorResponse error;
				error.code = -1;
				error.error = "File picker is cancelled";
				error.success = false;
				options.callbacks.oncancel(error);
				return;
			}
			const auto blob = TitaniumWindows::Utility::GetTiBlobForFile(get_context(), TitaniumWindows::Utility::ConvertString(file->Path));
			if (blob.IsObject()) {
				Titanium::Media::CameraMediaItemType item;
				item.code = 0;
				item.success = true;
				item.mediaType = Titanium::Media::MediaType::Photo;
				item.media = static_cast<JSObject>(blob).GetPrivate<Titanium::Blob>();
				options.callbacks.onsuccess(item);
			} else {
				Titanium::ErrorResponse error;
				error.code = -1;
				error.error = "Failed to load content from file";
				error.success = false;
				options.callbacks.onerror(error);
			}
		});
#endif
	}

	void MediaModule::previewImage(const std::unordered_map<std::string, Titanium::Media::PreviewImageOptions>& options) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::previewImage: Unimplemented");
	}

	std::vector<std::shared_ptr<Titanium::Media::Item>> MediaModule::queryMusicLibrary(const Titanium::Media::MediaQueryType& query) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::queryMusicLibrary: Unimplemented");
		return std::vector<std::shared_ptr<Titanium::Media::Item>>();
	}

	void MediaModule::setOverrideAudioRoute(const Titanium::Media::AudioSessionOverrideRoute& route) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::setOverrideAudioRoute: Unimplemented");
	}

	bool MediaModule::isMediaTypeSupported(const std::string& source, const Titanium::Media::MediaType& type) TITANIUM_NOEXCEPT
	{
		if (source == "camera") {
			bool videoSupported = false;
			concurrency::event event;
			task<DeviceInformationCollection^>(DeviceInformation::FindAllAsync(DeviceClass::VideoCapture)).then([&videoSupported, &event](task<DeviceInformationCollection^> task) {
				try {
					videoSupported = task.get()->Size > 0;
				} catch (Platform::COMException^ ex) {
					TITANIUM_LOG_DEBUG(TitaniumWindows::Utility::ConvertString(ex->Message));
				}
				event.set();
			}, concurrency::task_continuation_context::use_arbitrary());
			event.wait();

			// Looks like there's no difference between "video" and "camera" in DeviceInformation...
			// Assuming "VideoCapture" device supports both camera and video. 
			return videoSupported;
		} else if (source == "photo") {
			// Does Photo Library support both picture and video? There's no way to query that.
			return true;
		}
		return false;
	}


	void MediaModule::saveToPhotoGallery(const std::shared_ptr<Titanium::Filesystem::File>& media, JSValue callbacks) TITANIUM_NOEXCEPT
	{
		const auto ctx = get_context();

		auto onSuccess = ctx.CreateObject();
		auto onError = ctx.CreateObject();

		if (callbacks.IsObject()) {
			const auto callbacksObj = static_cast<JSObject>(callbacks);
			if (callbacksObj.HasProperty("success")) {
				const auto success = callbacksObj.GetProperty("success");
				if (success.IsObject()) {
					onSuccess = static_cast<JSObject>(success);
				}
			}
			if (callbacksObj.HasProperty("error")) {
				const auto error = callbacksObj.GetProperty("error");
				if (error.IsObject()) {
					onError = static_cast<JSObject>(error);
				}
			}
		}
		const auto to_path = Windows::Storage::KnownFolders::PicturesLibrary->Path;
		if (media->copy(TitaniumWindows::Utility::ConvertString(to_path))) {
			if (onSuccess.IsFunction()) {
				auto arg = ctx.CreateObject();
				arg.SetProperty("success", ctx.CreateBoolean(true));
				arg.SetProperty("code", ctx.CreateNumber(0));
				onSuccess({ arg }, get_object());
			}
		} else {
			if (onError.IsFunction()) {
				auto arg = ctx.CreateObject();
				arg.SetProperty("success", ctx.CreateBoolean(true));
				arg.SetProperty("code", ctx.CreateNumber(-1));
				arg.SetProperty("message", ctx.CreateString("Failed to save file to Pictures Library"));
				onError({ arg }, get_object());
			}
		}
	}

	void MediaModule::hideCamera() TITANIUM_NOEXCEPT
	{
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
		TITANIUM_ASSERT_AND_THROW(cameraPreviewStarted__, "Camera is not visiable. Use showCamera() to show camera.");
		concurrency::create_task(mediaCapture__->StopPreviewAsync()).then([this](concurrency::task<void> stopTask) {
			try {
				stopTask.get();
			} catch (Platform::Exception^ e) {
				TITANIUM_LOG_WARN("MediaModule: Failed to stop camera preview: ", TitaniumWindows::Utility::ConvertString(e->Message));
			}
			TitaniumWindows::Utility::RemoveViewFromCurrentWindow(captureElement__);
			captureElement__->Source = nullptr;
			cameraPreviewStarted__ = false;
			delete(mediaCapture__.Get());
		});
#endif
	}

	void MediaModule::showCamera(const Titanium::Media::CameraOptionsType& options) TITANIUM_NOEXCEPT
	{
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP

		if (cameraPreviewStarted__) {
			TITANIUM_LOG_WARN("Failed to showCamera(): Camera is already visible.");
			return;
		}

		TITANIUM_ASSERT_AND_THROW(!screenCaptureStarted__, "showCamera() can't be used during screen capture.");
		mediaCapture__ = ref new MediaCapture();
		concurrency::create_task(mediaCapture__->InitializeAsync()).then([this](concurrency::task<void> initTask) {
			try {
				initTask.get();
				auto mediaCapture = mediaCapture__.Get();
				captureElement__->Source = mediaCapture;
				this->cameraPreviewStarted__ = true;

				concurrency::create_task(mediaCapture->StartPreviewAsync()).then([this](concurrency::task<void> previewTask) {
					try {
						previewTask.get();
					} catch (Platform::Exception^ e) {
						TITANIUM_LOG_WARN("MediaModule: Failed to start camera preview: ", TitaniumWindows::Utility::ConvertString(e->Message));
					}
				});
			} catch (Platform::Exception^ e) {
				TITANIUM_LOG_WARN("MediaModule: Failed to initialize capture device: ", TitaniumWindows::Utility::ConvertString(e->Message));
			}
		});
		TitaniumWindows::Utility::SetViewForCurrentWindow(captureElement__, camera_navigated_event__);
#else
		auto cameraCaptureUI = ref new CameraCaptureUI();

		// TODO: Provide a option to specify aspect ratio
		cameraCaptureUI->PhotoSettings->CroppedAspectRatio = Size(16, 9);

		concurrency::task<StorageFile^>(cameraCaptureUI->CaptureFileAsync(CameraCaptureUIMode::Photo)).then([options, this](StorageFile^ file) {
			if (nullptr != file) {
				Titanium::Media::CameraMediaItemType item;
				item.mediaType = Titanium::Media::MediaType::Photo;
				if (file != nullptr) {
					const auto blob = TitaniumWindows::Utility::GetTiBlobForFile(get_context(), TitaniumWindows::Utility::ConvertString(file->Path));
					if (blob.IsObject()) {
						item.media = static_cast<JSObject>(blob).GetPrivate<Titanium::Blob>();
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

	void MediaModule::fireMediaVolumeEvent(const SoundLevel& level) 
	{
		// There's only three level on Windows: Muted, Low and Full.
		// TODO: Find reasonable number for volume. Right now it's mapped to Muted=0, Low=0.5 and Full=1.
		const auto ctx = get_context();
		auto obj = ctx.CreateObject();
		switch (level) {
		case SoundLevel::Muted:
			obj.SetProperty("volume", ctx.CreateNumber(0));
			break;
		case SoundLevel::Low:
			obj.SetProperty("volume", ctx.CreateNumber(0.5));
			break;
		case SoundLevel::Full:
			obj.SetProperty("volume", ctx.CreateNumber(1));
			break;
		default:
			TITANIUM_LOG_WARN("MediaModule: Unknown volume");
			obj.SetProperty("volume", ctx.CreateNumber(0));
			break;
		}
		fireEvent("volume", obj);
	}

	void MediaModule::startMicrophoneMonitor() TITANIUM_NOEXCEPT
	{
		SystemMediaTransportControls^ systemMediaControls = SystemMediaTransportControls::GetForCurrentView();
		audioMonitoring_token__ = systemMediaControls->PropertyChanged += ref new TypedEventHandler<SystemMediaTransportControls^, SystemMediaTransportControlsPropertyChangedEventArgs^>([this](SystemMediaTransportControls^ sender, SystemMediaTransportControlsPropertyChangedEventArgs^ e) {
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
		systemMediaControls->PropertyChanged -= audioMonitoring_token__;
	}

	void MediaModule::takePicture() TITANIUM_NOEXCEPT
	{
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
		// CreationCollisionOption::GenerateUniqueName generates unique name such as "TiMediaPhoto (2).jpg"
		concurrency::task<StorageFile^>(KnownFolders::VideosLibrary->CreateFileAsync("TiMediaPhoto.jpg", CreationCollisionOption::GenerateUniqueName)).then([this](concurrency::task<StorageFile^> fileTask) {
			try {
				auto file = fileTask.get();

				// TODO: Provide an API to customize capture settings
				ImageEncodingProperties^ properties = ImageEncodingProperties::CreateJpeg();
				concurrency::create_task(mediaCapture__->CapturePhotoToStorageFileAsync(properties, file)).then([this, file](concurrency::task<void> recordTask) {
					try {
						recordTask.get();
					} catch (Platform::Exception^ e) {
						const auto message = TitaniumWindows::Utility::ConvertString(e->Message);
						TITANIUM_LOG_WARN("MediaModule: Failure on start taking photo: ", message);
					}
				});
			} catch (Platform::Exception^ e) {
				const auto message = TitaniumWindows::Utility::ConvertString(e->Message);
				TITANIUM_LOG_WARN("MediaModule: Failure on start taking photo: ", message);
			}
	});
#else
		TITANIUM_LOG_WARN("MediaModule::takePicture: Not available for Windows Store app");
#endif
	}

	void MediaModule::startVideoCapture() TITANIUM_NOEXCEPT
	{
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
		concurrency::task<StorageFile^>(KnownFolders::VideosLibrary->CreateFileAsync("TiMediaVideo.mp4", CreationCollisionOption::GenerateUniqueName)).then([this](concurrency::task<StorageFile^> fileTask) {
			try {
				auto file = fileTask.get();

				// TODO: Provide an API to customize capture settings
				auto properties = MediaEncodingProfile::CreateMp4(VideoEncodingQuality::Auto);
				concurrency::create_task(mediaCapture__->StartRecordToStorageFileAsync(properties, file)).then([this, file](concurrency::task<void> recordTask) {
					try {
						recordTask.get();
					} catch (Platform::Exception^ e) {
						const auto message = TitaniumWindows::Utility::ConvertString(e->Message);
						TITANIUM_LOG_WARN("MediaModule: Failure on start taking video: ", message);
					}
				});
			} catch (Platform::Exception^ e) {
				const auto message = TitaniumWindows::Utility::ConvertString(e->Message);
				TITANIUM_LOG_WARN("MediaModule: Failure on start taking video: ", message);
			}
		});

#else
		TITANIUM_LOG_WARN("MediaModule::startVideoCapture: Not available for Windows Store app");
#endif
	}

	void MediaModule::stopVideoCapture() TITANIUM_NOEXCEPT
	{
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
		TITANIUM_ASSERT_AND_THROW(cameraPreviewStarted__, "Camera is not visiable. Use showCamera() to show camera.");
		concurrency::create_task(mediaCapture__->StopRecordAsync()).then([this](concurrency::task<void> stopTask) {
			try {
				stopTask.get();
			} catch (Platform::Exception^ e) {
				TITANIUM_LOG_WARN("MediaModule: Failed to stop camera preview: ", TitaniumWindows::Utility::ConvertString(e->Message));
			}
		});
#else
		TITANIUM_LOG_WARN("MediaModule::stopVideoCapture: Not available for Windows Store app");
#endif
	}

	void MediaModule::switchCamera(const Titanium::Media::CameraOption& camera) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::switchCamera: Unimplemented");
	}

	void MediaModule::takeScreenshotDone(JSObject callback, const std::string& file, const bool& hasError)
	{
		clearScreenshotResources();

		const auto ctx = get_context();
		auto eventArg = ctx.CreateObject();
		if (hasError) {
			eventArg.SetProperty("media", ctx.CreateNull());
		} else {
			// read file and get blob.
			eventArg.SetProperty("media", TitaniumWindows::Utility::GetTiBlobForFile(ctx, file));
		}
		callback({ eventArg }, get_object());
	}

	void MediaModule::clearScreenshotResources()
	{
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
		if (screenCaptureStarted__) {
			delete(mediaCapture__.Get());
			screenCaptureStarted__ = false;
		}
#endif
	}

	// Create new storage and start capturing!
	void MediaModule::takeScreenshotToFile(JSObject callback)
	{
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
		// CreationCollisionOption::GenerateUniqueName generates unique name such as "TiMediaScreenCapture (2).jpg"
		concurrency::task<StorageFile^>(KnownFolders::VideosLibrary->CreateFileAsync("TiMediaScreenCapture.jpg", CreationCollisionOption::GenerateUniqueName)).then([this, callback](concurrency::task<StorageFile^> fileTask) {
			try {
				auto file = fileTask.get();

				// TODO: Provide an API to customize capture settings
				ImageEncodingProperties^ properties = ImageEncodingProperties::CreateJpeg();
				concurrency::create_task(mediaCapture__->CapturePhotoToStorageFileAsync(properties, file)).then([this, file, callback](concurrency::task<void> recordTask) {
					try {
						recordTask.get();
						takeScreenshotDone(callback, TitaniumWindows::Utility::ConvertString(file->Path), false);
					} catch (Platform::Exception^ e) {
						const auto message = TitaniumWindows::Utility::ConvertString(e->Message);
						TITANIUM_LOG_WARN("MediaModule: Failure on start capturing screen: ", message);
						takeScreenshotDone(callback);
					}
				});
			} catch (Platform::Exception^ e) {
				const auto message = TitaniumWindows::Utility::ConvertString(e->Message);
				TITANIUM_LOG_WARN("MediaModule: Failure on start capturing screen: ", message);
				takeScreenshotDone(callback);
			}
		});
#else
		TITANIUM_LOG_WARN("MediaModule::takeScreenshotToFile: Unimplemented");
#endif
	}

	void MediaModule::takeScreenshot(JSValue callback_value) TITANIUM_NOEXCEPT
	{
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP

		TITANIUM_ASSERT_AND_THROW(!cameraPreviewStarted__, "takeScreenshot() can't be used during camera preview");

		// https://msdn.microsoft.com/en-us/library/windows/apps/xaml/dn642093.aspx
		auto screenCapture = ScreenCapture::GetForCurrentView();
		auto mediaCapture = ref new MediaCapture();

		mediaCapture__ = mediaCapture;
		screenCaptureStarted__ = true;

		// TODO: Provide an API for customizing capture settings
		auto settings = ref new MediaCaptureInitializationSettings();
		settings->VideoSource = screenCapture->VideoSource;
		settings->StreamingCaptureMode = StreamingCaptureMode::Video;

		JSObject callback = get_context().CreateObject();
		if (callback_value.IsObject()) {
			callback = static_cast<JSObject>(callback_value);
		}

		concurrency::create_task(mediaCapture__->InitializeAsync()).then([this, callback](concurrency::task<void> initTask) {
			try {
				initTask.get();
				auto mediaCapture = mediaCapture__.Get();

				mediaCapture->RecordLimitationExceeded += ref new RecordLimitationExceededEventHandler([this, callback](MediaCapture^ sender) {
					TITANIUM_LOG_WARN("MediaModule: Stopping screen capture on exceeding max record duration");
					takeScreenshotDone(callback);
				});
				mediaCapture->Failed += ref new MediaCaptureFailedEventHandler([this, callback](MediaCapture^ sender, MediaCaptureFailedEventArgs^ e) {
					const auto message = TitaniumWindows::Utility::ConvertString(e->Message);
					TITANIUM_LOG_WARN("MediaModule: Failed to capture screen: ", message);
					takeScreenshotDone(callback);
				});

				takeScreenshotToFile(callback);
			} catch (Platform::Exception ^ e) {
				const auto message = TitaniumWindows::Utility::ConvertString(e->Message);
				TITANIUM_LOG_WARN("MediaModule: Failed to initialize capture device: ", message);
				takeScreenshotDone(callback);
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

		vibrate_timers__->Clear();

		for (size_t i = 0; i < pattern.size(); i++) {
			const auto msec = pattern.at(i);
			std::chrono::duration<std::chrono::nanoseconds::rep, std::ratio_multiply<std::ratio<100>, std::nano>> timer_interval_ticks = pattern.at(i);

			Windows::Foundation::TimeSpan time_span;
			time_span.Duration = timer_interval_ticks.count();
			auto vibrate_timer = ref new DispatcherTimer();
			vibrate_timer->Interval = time_span;
			vibrate_timer->Stop();

			vibrate_timer->Tick += ref new Windows::Foundation::EventHandler<Platform::Object^>([this, i](Platform::Object^ sender, Platform::Object^ event) {
				// stop current timer
				vibrate_timers__->GetAt(i)->Stop();

				// return when it's a last timer
				const size_t next = i + 1;
				if (next == vibrate_timers__->Size) {
					vibrate_timers__->Clear();
					return;
				}
				// vibrate device only when even number index
				if (next % 2 != 0) {
					VibrationDevice::GetDefault()->Vibrate(vibrate_timers__->GetAt(next)->Interval);
				}
				// Start next timer
				vibrate_timers__->GetAt(next)->Start();
			});
			vibrate_timers__->Append(vibrate_timer);
		}

		if (pattern.size() > 0) {
			vibrate_timers__->GetAt(0)->Start();
		}

#else
		TITANIUM_LOG_WARN("MediaModule::vibrate: Not supported");
#endif
	}

	MediaModule::MediaModule(const JSContext& js_context) TITANIUM_NOEXCEPT
		: Titanium::MediaModule(js_context)
		, fileOpenFromPickerCallback__(createFileOpenFromPickerFunction(js_context))
	{
		TITANIUM_LOG_DEBUG("TitaniumWindows::MediaModule::ctor Initialize");
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
		vibrate_timers__ = ref new Vector<DispatcherTimer^>();
		captureElement__ = ref new CaptureElement();
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
