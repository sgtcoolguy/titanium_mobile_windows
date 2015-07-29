/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/Media/Sound.hpp"
#include "Titanium/detail/TiLogger.hpp"
#include "TitaniumWindows/Utility.hpp"

using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Media;

namespace TitaniumWindows
{
	namespace Media {
		Sound::Sound(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Media::Sound(js_context) {
			TITANIUM_LOG_DEBUG("TitaniumWindows::Media::Sound::ctor Initialize");
		}

		Sound::~Sound() 
		{
			TITANIUM_LOG_DEBUG("TitaniumWindows::Media::Sound::dtor");
		}

		void Sound::JSExportInitialize() 
		{
			JSExport<Sound>::SetClassVersion(1);
			JSExport<Sound>::SetParent(JSExport<Titanium::Media::Sound>::Class());
		}

		void Sound::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) 
		{
			Titanium::Media::Sound::postCallAsConstructor(js_context, arguments);
			player__ = ref new Windows::UI::Xaml::Controls::MediaElement();
			player__->AudioCategory = AudioCategory::SoundEffects;
			player__->AreTransportControlsEnabled = true;
			player__->Visibility = Windows::UI::Xaml::Visibility::Collapsed; // Hide UI
			player__->AutoPlay = false;
			player__->IsLooping = false;
			player__->CurrentStateChanged += ref new RoutedEventHandler([this](Platform::Object^ sender, RoutedEventArgs^ e) {
				looping__ = isLooping();
				playing__ = isPlaying();
				paused__ = isPaused();
				volume__ = player__->Volume;
				duration__ = static_cast<std::uint32_t>(player__->NaturalDuration.TimeSpan.Duration / 10000); // convert 100 nanosecond to milliseconds

				const auto ctx = get_context();
				auto event_arg = ctx.CreateObject();

				switch (player__->CurrentState) {
				case MediaElementState::Buffering:
					event_arg.SetProperty("state", state_buffering__);
					break;
				case MediaElementState::Paused:
					event_arg.SetProperty("state", state_paused__);
					break;
				case MediaElementState::Playing:
					event_arg.SetProperty("state", state_playing__);
					break;
				case MediaElementState::Stopped:
					event_arg.SetProperty("state", state_stopped__);
					break;
				case MediaElementState::Opening:
					break;
				case MediaElementState::Closed:
					break;
				}

				fireEvent("change", event_arg);
			});

			// Add "hidden" MediaElement UI onto current Window, because it doesn't work when it is not on the UI.
			// This is little bit tricky because this proxy is not kind of View and then you can't use Titanium's layout engine. 
			const auto rootFrame = dynamic_cast<Windows::UI::Xaml::Controls::Frame^>(Windows::UI::Xaml::Window::Current->Content);
			const auto registerUI = ref new Windows::UI::Core::DispatchedHandler([this, rootFrame]() {
				if (rootFrame->Content) {
					const auto page = dynamic_cast<Windows::UI::Xaml::Controls::Page^>(rootFrame->Content);
					if (page && page->Content) {
						const auto content = static_cast<Panel^>(page->Content);
						if (content) {
							content->Children->Append(player__);
						}
					}
				}
			});
			if (rootFrame->Content == nullptr) {
				// If there's no Window (Window.open() is not called) yet, wait for the first Window opened
				navigated_event__ = rootFrame->Navigated += ref new Navigation::NavigatedEventHandler([this, rootFrame, registerUI](Platform::Object^ sender, Navigation::NavigationEventArgs^ e) {
					rootFrame->Navigated -= navigated_event__; // unregister current event, you just need to do this only once
					Window::Current->Dispatcher->RunAsync(Windows::UI::Core::CoreDispatcherPriority::Normal, registerUI);
				});
			} else {
				// If there's a Window already, just attach to it
				Window::Current->Dispatcher->RunAsync(Windows::UI::Core::CoreDispatcherPriority::Normal, registerUI);
			}
		}

		void Sound::set_volume(const double& volume) TITANIUM_NOEXCEPT
		{
			Titanium::Media::Sound::set_volume(volume);
			player__->Volume = volume;
		}

		void Sound::set_paused(const bool& paused) TITANIUM_NOEXCEPT
		{
			Titanium::Media::Sound::set_paused(paused);
			if (paused) {
				pause();
			} else {
				play();
			}
		}

		std::chrono::milliseconds Sound::get_time() const TITANIUM_NOEXCEPT
		{
			return std::chrono::milliseconds(static_cast<std::chrono::milliseconds::rep>(player__->Position.Duration / 10000));
		}

		void Sound::set_url(const std::string& param) TITANIUM_NOEXCEPT
		{
			std::string url = param;
			if (param.find("://") == std::string::npos) {
				url = "ms-appx:///" + param;
			}
			Titanium::Media::Sound::set_url(url);
			player__->Source = ref new Windows::Foundation::Uri(TitaniumWindows::Utility::ConvertString(url));
		}

		void Sound::set_looping(const bool& looping) TITANIUM_NOEXCEPT
		{
			Titanium::Media::Sound::set_looping(looping);
			player__->IsLooping = looping;
		}

		bool Sound::isLooping() TITANIUM_NOEXCEPT
		{
			return player__->IsLooping;
		}

		bool Sound::isPaused() TITANIUM_NOEXCEPT
		{
			return player__->CurrentState == MediaElementState::Paused;
		}

		bool Sound::isPlaying() TITANIUM_NOEXCEPT
		{
			return player__->CurrentState == MediaElementState::Playing;
		}

		void Sound::pause() TITANIUM_NOEXCEPT
		{
			player__->Pause();
		}

		void Sound::play() TITANIUM_NOEXCEPT
		{
			player__->Play();
		}

		void Sound::reset() TITANIUM_NOEXCEPT
		{
			stop();
		}

		void Sound::stop() TITANIUM_NOEXCEPT
		{
			player__->Stop();
		}

		void Sound::enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
		{
			Titanium::Media::Sound::enableEvent(event_name);

			if (event_name == "complete") {
				complete_event__ = player__->MediaEnded += ref new RoutedEventHandler([this](Platform::Object^ sender, RoutedEventArgs^ e) {
					const auto ctx = get_context();
					auto event_arg = ctx.CreateObject();
					event_arg.SetProperty("success", ctx.CreateBoolean(true));
					event_arg.SetProperty("code", ctx.CreateNumber(0));
					fireEvent("complete", event_arg);
				});
			} else if (event_name == "error") {
				failed_event__ = player__->MediaFailed += ref new ExceptionRoutedEventHandler([this](Platform::Object^ sender, ExceptionRoutedEventArgs^ e) {
					const auto ctx = get_context();
					auto event_arg = ctx.CreateObject();
					event_arg.SetProperty("message", ctx.CreateString(TitaniumWindows::Utility::ConvertString(e->ErrorMessage)));
					event_arg.SetProperty("success", ctx.CreateBoolean(false));
					event_arg.SetProperty("code", ctx.CreateNumber(-1));
					fireEvent("error", event_arg);
				});
			}
		}

		void Sound::disableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
		{
			Titanium::Media::Sound::disableEvent(event_name);
			if (event_name == "complete") {
				player__->MediaEnded -= complete_event__;
			} else if (event_name == "error") {
				player__->MediaFailed -= failed_event__;
			}
		}
	}
}
