/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/Media/AudioRecorder.hpp"
#include "TitaniumWindows/Utility.hpp"
#include "Titanium/detail/TiImpl.hpp"
#include <ppltasks.h>
#include <concrt.h>

namespace TitaniumWindows
{
	namespace Media
	{
		using namespace Windows::Media;
		using namespace Windows::Media::Capture;
		using namespace Windows::Media::MediaProperties;
		using namespace Windows::Storage;

		void AudioRecorder::start() TITANIUM_NOEXCEPT
		{
			// Need to initialize audio capture device first of all.
			auto mediaCapture = ref new MediaCapture();
			mediaCapture__ = mediaCapture;

			// Clear last saved recording
			recordStorageFile__ = nullptr;

			// TODO: Provide an API for customizing capture settings
			auto settings = ref new MediaCaptureInitializationSettings();
			settings->StreamingCaptureMode =StreamingCaptureMode::Audio;
			settings->MediaCategory = MediaCategory::Other;
			settings->AudioProcessing = AudioProcessing::Default;

			bool mic_init { false };
			concurrency::event initialize_event;
			concurrency::create_task(mediaCapture->InitializeAsync()).then([&mic_init, &initialize_event, this](concurrency::task<void> initTask) {
				try {
					initTask.get();
					auto mediaCapture = mediaCapture__.Get();

					// TODO: need to throw JavaScript exception or raise failure callback?
					mediaCapture->RecordLimitationExceeded += ref new RecordLimitationExceededEventHandler([this](MediaCapture^ sender) {
						TITANIUM_LOG_WARN("AudioRecorder: Stopping Record on exceeding max record duration");
						stop();
					});
					mediaCapture->Failed += ref new MediaCaptureFailedEventHandler([this](MediaCapture^ sender, MediaCaptureFailedEventArgs^ e) {
						TITANIUM_LOG_WARN("AudioRecorder: Failed to capture audio: ", TitaniumWindows::Utility::ConvertString(e->Message));
						stop();
					});
					mic_init = true;
				} catch (Platform::Exception ^ e) {
					// TODO: need to throw JavaScript exception or raise failure callback?
					TITANIUM_LOG_WARN("AudioRecorder: Failed to initialize audio capture device: ", TitaniumWindows::Utility::ConvertString(e->Message));
				}
				initialize_event.set();
			});
			initialize_event.wait();
			if (mic_init) {
				return;
			}

			// Create new storage and start recording!
			concurrency::task<StorageFile^>(KnownFolders::VideosLibrary->CreateFileAsync("TiMediaAudioRecorderFile", CreationCollisionOption::GenerateUniqueName)).then([this](concurrency::task<StorageFile^> fileTask) {
				try {
					this->recordStorageFile__ = fileTask.get();

					// TODO: Provide an API to customize capture settings
					MediaEncodingProfile^ recordProfile = MediaEncodingProfile::CreateM4a(AudioEncodingQuality::Auto);
					concurrency::create_task(mediaCapture__->StartRecordToStorageFileAsync(recordProfile, this->recordStorageFile__)).then([this](concurrency::task<void> recordTask) {
						try {
							recordTask.get();
							recording__ = true;
						} catch (Platform::Exception^ e) {
							// TODO: need to throw JavaScript exception or raise failure callback?
							TITANIUM_LOG_WARN("AudioRecorder: Failure on start recording: ", TitaniumWindows::Utility::ConvertString(e->Message));
						}
					});
					// TODO: need to fire "started recording" callback because it's done by async?
				} catch (Platform::Exception^ e) {
					// TODO: need to throw JavaScript exception or raise failure callback?
					TITANIUM_LOG_WARN("AudioRecorder: Failure on start recording: ", TitaniumWindows::Utility::ConvertString(e->Message));
				}
			});

		}

		std::shared_ptr<Titanium::Filesystem::File> AudioRecorder::stop() TITANIUM_NOEXCEPT
		{
			if (recording__) {
				concurrency::create_task(mediaCapture__->StopRecordAsync()).then([this](concurrency::task<void> recordTask) {
					try {
						recordTask.get();
						recording__ = false;
						delete(mediaCapture__.Get());
					} catch (Platform::Exception ^e) {
						TITANIUM_LOG_WARN("AudioRecorder: Failure on stopping recording: ", TitaniumWindows::Utility::ConvertString(e->Message));
					}
				});
			} else {
				try {
					if (mediaCapture__.Get()) {
						delete(mediaCapture__.Get());
					}
				} catch (Platform::Exception ^e) {
					TITANIUM_LOG_WARN("AudioRecorder: Failure on stopping audio capture device: ", TitaniumWindows::Utility::ConvertString(e->Message));
				}
			}

			// Return Ti.Fiilesystem.File object
			if (recordStorageFile__ != nullptr) {
				const auto ctx = get_context();
				const auto getFile_property = ctx.JSEvaluateScript("Ti.Filesystem.getFile");
				TITANIUM_ASSERT(getFile_property.IsObject());
				auto getFile = static_cast<JSObject>(getFile_property);
				const std::vector<JSValue> args = { ctx.CreateString(TitaniumWindows::Utility::ConvertString(recordStorageFile__->Path)) };
				const auto file = getFile(args, getFile);
				if (file.IsObject()) {
					return static_cast<JSObject>(file).GetPrivate<Titanium::Filesystem::File>();
				}
			}
			return nullptr;
		}

		AudioRecorder::AudioRecorder(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Media::AudioRecorder(js_context)
		{
			TITANIUM_LOG_DEBUG("TitaniumWindows::Media::AudioRecorder::ctor Initialize");
		}

		AudioRecorder::~AudioRecorder()
		{
			TITANIUM_LOG_DEBUG("TitaniumWindows::Media::AudioRecorder::dtor");
		}

		void AudioRecorder::JSExportInitialize()
		{
			JSExport<AudioRecorder>::SetClassVersion(1);
			JSExport<AudioRecorder>::SetParent(JSExport<Titanium::Media::AudioRecorder>::Class());
		}
	}
}
