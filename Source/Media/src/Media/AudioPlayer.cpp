/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/Media/AudioPlayer.hpp"
#include "Titanium/detail/TiLogger.hpp"
#include "TitaniumWindows/Utility.hpp"

using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Media;

namespace TitaniumWindows
{
	namespace Media
	{
		AudioPlayer::AudioPlayer(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Media::AudioPlayer(js_context)
		{
			TITANIUM_LOG_DEBUG("TitaniumWindows::Media::AudioPlayer::ctor Initialize");
		}

		AudioPlayer::~AudioPlayer()
		{
			TITANIUM_LOG_DEBUG("TitaniumWindows::Media::AudioPlayer::dtor");
		}

		void AudioPlayer::JSExportInitialize()
		{
			JSExport<AudioPlayer>::SetClassVersion(1);
			JSExport<AudioPlayer>::SetParent(JSExport<Titanium::Media::AudioPlayer>::Class());
		}

		void AudioPlayer::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) 
		{
			Titanium::Media::AudioPlayer::postCallAsConstructor(js_context, arguments);

			player__ = ref new Windows::UI::Xaml::Controls::MediaElement();
			player__->AudioCategory = AudioCategory::BackgroundCapableMedia;
			player__->AreTransportControlsEnabled = true;
			player__->Visibility = Windows::UI::Xaml::Visibility::Collapsed; // Hide UI
			player__->AutoPlay = false;
			player__->IsLooping = false;
			player__->CurrentStateChanged += ref new RoutedEventHandler([this](Platform::Object^ sender, RoutedEventArgs^ e) {
				playing__ = isPlaying();
				paused__ = isPaused();
				volume__ = player__->Volume;
				waiting__ = (player__->CurrentState == MediaElementState::Buffering);
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
			navigated_event__ = rootFrame->Navigated += ref new Navigation::NavigatedEventHandler([this](Platform::Object^ sender, Navigation::NavigationEventArgs^ e) {
				Window::Current->Dispatcher->RunAsync(Windows::UI::Core::CoreDispatcherPriority::Normal, ref new Windows::UI::Core::DispatchedHandler([this, sender]() {
					const auto frame = static_cast<Windows::UI::Xaml::Controls::Frame^>(sender);
					frame->Navigated -= navigated_event__; // unregister current event, you just need to do this only once
					if (frame->Content) {
						const auto page = dynamic_cast<Windows::UI::Xaml::Controls::Page^>(frame->Content);
						if (page && page->Content) {
							const auto content = static_cast<Panel^>(page->Content);
							if (content) {
								content->Children->Append(player__);
							}
						}
					}
				}));
			});
		}

		Titanium::Media::AudioState AudioPlayer::get_state() const TITANIUM_NOEXCEPT
		{
			switch (player__->CurrentState) {
			case MediaElementState::Buffering:
				return Titanium::Media::AudioState::Buffering;
			case MediaElementState::Paused:
				return Titanium::Media::AudioState::Paused;
			case MediaElementState::Playing:
				return Titanium::Media::AudioState::Playing;
			case MediaElementState::Stopped:
				return Titanium::Media::AudioState::Stopped;
			case MediaElementState::Opening:
				break;
			case MediaElementState::Closed:
				break;
			}
			// TODO: Do we need "unknown" state?
			return Titanium::Media::AudioState::Stopped;
		}

		void AudioPlayer::set_volume(const double& volume) TITANIUM_NOEXCEPT
		{
			Titanium::Media::AudioPlayer::set_volume(volume);
			player__->Volume = volume;
		}

		void AudioPlayer::set_paused(const bool& paused) TITANIUM_NOEXCEPT
		{
			Titanium::Media::AudioPlayer::set_paused(paused);
			if (paused) {
				pause();
			} else {
				play();
			}
		}

		std::chrono::milliseconds AudioPlayer::get_time() const TITANIUM_NOEXCEPT
		{
			return std::chrono::milliseconds(static_cast<std::chrono::milliseconds::rep>(player__->Position.Duration / 10000));
		}

		void AudioPlayer::set_url(const std::string& param) TITANIUM_NOEXCEPT
		{
			std::string url = param;
			if (param.find("://") == std::string::npos) {
				url = "ms-appx:///" + param;
			}
			Titanium::Media::AudioPlayer::set_url(url);
			player__->Source = ref new Windows::Foundation::Uri(TitaniumWindows::Utility::ConvertString(url));
		}


		bool AudioPlayer::isPaused() TITANIUM_NOEXCEPT
		{
			return player__->CurrentState == MediaElementState::Paused;
		}

		bool AudioPlayer::isPlaying() TITANIUM_NOEXCEPT
		{
			return player__->CurrentState == MediaElementState::Playing;
		}

		void AudioPlayer::pause() TITANIUM_NOEXCEPT
		{
			player__->Pause();
		}

		void AudioPlayer::play() TITANIUM_NOEXCEPT
		{
			player__->Play();
		}

		void AudioPlayer::start() TITANIUM_NOEXCEPT
		{
			player__->Play();
		}

		void AudioPlayer::stop() TITANIUM_NOEXCEPT
		{
			player__->Stop();
		}

		void AudioPlayer::enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
		{
			Titanium::Media::AudioPlayer::enableEvent(event_name);
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

		void AudioPlayer::disableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
		{
			Titanium::Media::AudioPlayer::disableEvent(event_name);
			if (event_name == "complete") {
				player__->MediaEnded -= complete_event__;
			} else if (event_name == "error") {
				player__->MediaFailed -= failed_event__;
			}
		}
	}
}
