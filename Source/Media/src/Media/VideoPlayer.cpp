/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/Media/VideoPlayer.hpp"
#include "Titanium/detail/TiLogger.hpp"
#include "TitaniumWindows/Utility.hpp"
#include "TitaniumWindows/UI/WindowsViewLayoutDelegate.hpp"

using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Media;

namespace TitaniumWindows
{
	namespace Media
	{
		VideoPlayer::VideoPlayer(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Media::VideoPlayer(js_context)
		{
			TITANIUM_LOG_DEBUG("TitaniumWindows::Media::VideoPlayer::ctor Initialize");
		}

		VideoPlayer::~VideoPlayer()
		{
			TITANIUM_LOG_DEBUG("TitaniumWindows::Media::VideoPlayer::dtor");
		}

		void VideoPlayer::JSExportInitialize()
		{
			JSExport<VideoPlayer>::SetClassVersion(1);
			JSExport<VideoPlayer>::SetParent(JSExport<Titanium::Media::VideoPlayer>::Class());
		}

		void VideoPlayer::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) 
		{
			Titanium::Media::VideoPlayer::postCallAsConstructor(js_context, arguments);
			player__ = ref new Windows::UI::Xaml::Controls::MediaElement();
			player__->AreTransportControlsEnabled = true;
			player__->Visibility = Windows::UI::Xaml::Visibility::Visible;
			player__->AutoPlay = false;
			player__->IsLooping = true;
			player__->CurrentStateChanged += ref new RoutedEventHandler([this](Platform::Object^ sender, RoutedEventArgs^ e) {
				fireEvent("change");
			});

			Titanium::Media::VideoPlayer::setLayoutDelegate<TitaniumWindows::UI::WindowsViewLayoutDelegate>();	
			layoutDelegate__->set_defaultHeight(Titanium::UI::LAYOUT::FILL);
			layoutDelegate__->set_defaultWidth(Titanium::UI::LAYOUT::FILL);
			layoutDelegate__->set_autoLayoutForHeight(Titanium::UI::LAYOUT::FILL);
			layoutDelegate__->set_autoLayoutForWidth(Titanium::UI::LAYOUT::FILL);
			getViewLayoutDelegate<TitaniumWindows::UI::WindowsViewLayoutDelegate>()->setComponent(player__);
		}

		void VideoPlayer::pause() TITANIUM_NOEXCEPT
		{
			player__->Pause();
		}

		void VideoPlayer::play() TITANIUM_NOEXCEPT
		{
			player__->Play();
		}

		void VideoPlayer::stop() TITANIUM_NOEXCEPT
		{
			player__->Stop();
		}

		void VideoPlayer::set_urls(const std::vector<std::string>& urls) TITANIUM_NOEXCEPT
		{
			Titanium::Media::VideoPlayer::set_urls(urls);

			if (urls.size() == 0) {
				return;
			}

			// MediaElement can take only one url. Let's take the first one.
			std::string url = urls.at(0);
			if (url.find("://") == std::string::npos) {
				url = "ms-appx:///" + url;
			}
			player__->Source = ref new Windows::Foundation::Uri(TitaniumWindows::Utility::ConvertString(url));
		}

		void VideoPlayer::set_volume(const double& volume) TITANIUM_NOEXCEPT
		{
			Titanium::Media::VideoPlayer::set_volume(volume);
			player__->Volume = volume;
		}

		void VideoPlayer::set_autoplay(const bool& autoplay) TITANIUM_NOEXCEPT
		{
			Titanium::Media::VideoPlayer::set_autoplay(autoplay);
			player__->AutoPlay = autoplay;
		}

		std::chrono::milliseconds VideoPlayer::get_duration() const TITANIUM_NOEXCEPT
		{
			// convert 100 nanosecond to milliseconds
			return std::chrono::milliseconds(static_cast<std::chrono::milliseconds::rep>(player__->NaturalDuration.TimeSpan.Duration / 10000));
		}

		Titanium::Media::VideoPlaybackState VideoPlayer::get_playbackState() const TITANIUM_NOEXCEPT
		{
			switch (player__->CurrentState) 
			{
			case MediaElementState::Paused:
				return Titanium::Media::VideoPlaybackState::Paused;
			case MediaElementState::Playing:
				return Titanium::Media::VideoPlaybackState::Playing;
			case MediaElementState::Stopped:
				return Titanium::Media::VideoPlaybackState::Stopped;
			}
			// TODO: Do we need "Unknown" state?
			return Titanium::Media::VideoPlaybackState::Stopped;
		}

		void VideoPlayer::enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
		{
			Titanium::Media::VideoPlayer::enableEvent(event_name);
			if (event_name == "complete") {
				complete_event__ = player__->MediaEnded += ref new RoutedEventHandler([this](Platform::Object^ sender, RoutedEventArgs^ e) {
					const auto ctx = get_context();
					auto event_arg = ctx.CreateObject();
					event_arg.SetProperty("success", ctx.CreateBoolean(true));
					event_arg.SetProperty("code", ctx.CreateNumber(0));
					fireEvent("complete", event_arg);
				});
			}
			else if (event_name == "error") {
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

		void VideoPlayer::disableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
		{
			Titanium::Media::VideoPlayer::disableEvent(event_name);
			if (event_name == "complete") {
				player__->MediaEnded -= complete_event__;
			}
			else if (event_name == "error") {
				player__->MediaFailed -= failed_event__;
			}
		}
	}
}
