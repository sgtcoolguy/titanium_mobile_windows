/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_MEDIA_SOUND_HPP_
#define _TITANIUMWINDOWS_MEDIA_SOUND_HPP_

#include "TitaniumWindows_Media_EXPORT.h"
#include "Titanium/Media/Sound.hpp"

namespace TitaniumWindows
{
	using namespace HAL;

	namespace Media
	{
		/*!
	      @class

	      @discussion This is the Titanium.Media.Sound implementation for Windows.
	    */
		class TITANIUMWINDOWS_MEDIA_EXPORT Sound final : public Titanium::Media::Sound, public JSExport<Sound>
		{
		public:

			virtual void set_paused(const bool& paused) TITANIUM_NOEXCEPT override;
			virtual void set_looping(const bool& looping) TITANIUM_NOEXCEPT override;
			virtual void set_url(const std::string& url) TITANIUM_NOEXCEPT override;
			virtual void set_volume(const double& volume) TITANIUM_NOEXCEPT override;
			virtual std::chrono::milliseconds get_time() const TITANIUM_NOEXCEPT override;

			virtual bool isLooping() TITANIUM_NOEXCEPT override;
			virtual bool isPaused() TITANIUM_NOEXCEPT override;
			virtual bool isPlaying() TITANIUM_NOEXCEPT override;
			virtual void pause() TITANIUM_NOEXCEPT override;
			virtual void play() TITANIUM_NOEXCEPT override;
			virtual void reset() TITANIUM_NOEXCEPT override;
			virtual void stop() TITANIUM_NOEXCEPT override;

			Sound(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~Sound();
			Sound(const Sound&) = default;
			Sound& operator=(const Sound&) = default;
	#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			Sound(Sound&&) = default;
			Sound& operator=(Sound&&) = default;
	#endif

			static void JSExportInitialize();

			virtual void postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) override;

			virtual void enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT override final;
			virtual void disableEvent(const std::string& event_name) TITANIUM_NOEXCEPT override final;

		protected:
			Windows::UI::Xaml::Controls::MediaElement ^ player__;
			Windows::Foundation::EventRegistrationToken complete_event__;
			Windows::Foundation::EventRegistrationToken failed_event__;
			Windows::Foundation::EventRegistrationToken navigated_event__;
		};

	} // namespace Media
} // namespace TitaniumWindows

#endif  // _TITANIUMWINDOWS_MEDIA_SOUND_HPP_
