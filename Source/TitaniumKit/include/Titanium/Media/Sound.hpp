/**
 * TitaniumKit Titanium.Media.Sound
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MEDIA_SOUND_HPP_
#define _TITANIUM_MEDIA_SOUND_HPP_

#include "Titanium/Module.hpp"
#include <chrono>

namespace Titanium
{
	namespace Media
	{
		using namespace HAL;

		/*!
		  @class
		  @discussion This is the Titanium Sound Module.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.Media.Sound
		*/
		class TITANIUMKIT_EXPORT Sound : public Module, public JSExport<Sound>
		{

		public:

			/*!
			  @property
			  @abstract allowBackground
			  @discussion Determines whether the audio should continue playing even when its activity is paused.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, allowBackground);

			/*!
			  @property
			  @abstract duration
			  @discussion Duration of the audio resource.
			*/
			TITANIUM_PROPERTY_IMPL_READONLY_DEF(std::uint32_t, duration);

			/*!
			  @property
			  @abstract looping
			  @discussion Determines whether the audio should loop upon completion.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, looping);

			/*!
			  @property
			  @abstract paused
			  @discussion Indicates if the audio is paused.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, paused);

			/*!
			  @property
			  @abstract playing
			  @discussion Indicates if the audio is playing.
			*/
			TITANIUM_PROPERTY_IMPL_READONLY_DEF(bool, playing);

			/*!
			  @property
			  @abstract time
			  @discussion Current playback position of the audio.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::chrono::milliseconds, time);

			/*!
			  @property
			  @abstract url
			  @discussion URL identifying the audio resource.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, url);

			/*!
			  @property
			  @abstract volume
			  @discussion Volume of the audio from 0.0 (muted) to 1.0 (loudest).
			*/
			TITANIUM_PROPERTY_IMPL_DEF(double, volume);

			/*!
			  @method
			  @abstract isLooping
			  @discussion Returns the value of the [looping](Titanium.Media.Sound.looping) property.
			*/
			virtual bool isLooping() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract isPaused
			  @discussion Returns the value of the [paused](Titanium.Media.Sound.paused) property.
			*/
			virtual bool isPaused() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract isPlaying
			  @discussion Returns the value of the [playing](Titanium.Media.Sound.playing) property.
			*/
			virtual bool isPlaying() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract pause
			  @discussion Pauses the audio.
			*/
			virtual void pause() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract play
			  @discussion Starting playing the sound, or resume playing a paused sound.
			*/
			virtual void play() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract release
			  @discussion Releases all internal resources.
			*/
			virtual void release() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract reset
			  @discussion Resets the audio playback position to the beginning.
			*/
			virtual void reset() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract setLooping
			  @discussion Sets the value of the [looping](Titanium.Media.Sound.looping) property.
			*/
			virtual void setLooping(const bool& looping) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract setPaused
			  @discussion Sets the value of the [paused](Titanium.Media.Sound.paused) property.
			*/
			virtual void setPaused(const bool& paused) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract stop
			  @discussion Stops playing the audio and resets the playback position to the beginning of the clip.
			*/
			virtual void stop() TITANIUM_NOEXCEPT;

			Sound(const JSContext&) TITANIUM_NOEXCEPT;
			virtual ~Sound()               = default;
			Sound(const Sound&)            = default;
			Sound& operator=(const Sound&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			Sound(Sound&&)                 = default;
			Sound& operator=(Sound&&)      = default;
#endif

			static void JSExportInitialize();

			TITANIUM_PROPERTY_READONLY_DEF(STATE_BUFFERING);
			TITANIUM_PROPERTY_READONLY_DEF(STATE_INITIALIZED);
			TITANIUM_PROPERTY_READONLY_DEF(STATE_PAUSED);
			TITANIUM_PROPERTY_READONLY_DEF(STATE_PLAYING);
			TITANIUM_PROPERTY_READONLY_DEF(STATE_STARTING);
			TITANIUM_PROPERTY_READONLY_DEF(STATE_STOPPED);
			TITANIUM_PROPERTY_READONLY_DEF(STATE_STOPPING);
			TITANIUM_PROPERTY_READONLY_DEF(STATE_WAITING_FOR_DATA);
			TITANIUM_PROPERTY_READONLY_DEF(STATE_WAITING_FOR_QUEUE);
			TITANIUM_PROPERTY_DEF(allowBackground);
			TITANIUM_PROPERTY_READONLY_DEF(duration);
			TITANIUM_PROPERTY_DEF(looping);
			TITANIUM_PROPERTY_DEF(paused);
			TITANIUM_PROPERTY_READONLY_DEF(playing);
			TITANIUM_PROPERTY_DEF(time);
			TITANIUM_PROPERTY_DEF(url);
			TITANIUM_PROPERTY_DEF(volume);

			TITANIUM_FUNCTION_DEF(isLooping);
			TITANIUM_FUNCTION_DEF(isPaused);
			TITANIUM_FUNCTION_DEF(isPlaying);
			TITANIUM_FUNCTION_DEF(pause);
			TITANIUM_FUNCTION_DEF(play);
			TITANIUM_FUNCTION_DEF(release);
			TITANIUM_FUNCTION_DEF(reset);
			TITANIUM_FUNCTION_DEF(setLooping);
			TITANIUM_FUNCTION_DEF(setPaused);
			TITANIUM_FUNCTION_DEF(stop);
			TITANIUM_FUNCTION_DEF(getDuration);
			TITANIUM_FUNCTION_DEF(getTime);
			TITANIUM_FUNCTION_DEF(setTime);
			TITANIUM_FUNCTION_DEF(getUrl);
			TITANIUM_FUNCTION_DEF(setUrl);
			TITANIUM_FUNCTION_DEF(getVolume);
			TITANIUM_FUNCTION_DEF(setVolume);

		protected:
#pragma warning(push)
#pragma warning(disable : 4251)
			JSValue state_buffering__;
			JSValue state_initialized__;
			JSValue state_paused__;
			JSValue state_playing__;
			JSValue state_starting__;
			JSValue state_stopped__;
			JSValue state_stopping__;
			JSValue state_waiting_for_data__;
			JSValue state_waiting_for_queue__;
			bool allowBackground__;
			std::uint32_t duration__;
			bool looping__;
			bool paused__;
			bool playing__;
			std::chrono::milliseconds time__;
			std::string url__;
			double volume__;
#pragma warning(pop)
		};

	} // namespace Media
} // namespace Titanium
#endif // _TITANIUM_MEDIA_SOUND_HPP_