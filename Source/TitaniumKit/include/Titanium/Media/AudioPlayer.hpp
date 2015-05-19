/**
 * TitaniumKit Titanium.Media.AudioPlayer
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MEDIA_AUDIOPLAYER_HPP_
#define _TITANIUM_MEDIA_AUDIOPLAYER_HPP_

#include "Titanium/Module.hpp"
#include "Titanium/Media/Constants.hpp"
#include <chrono>

namespace Titanium
{
	namespace Media
	{
		using namespace HAL;

		/*!
		  @class
		  @discussion This is the Titanium AudioPlayer Module.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.Media.AudioPlayer
		*/
		class TITANIUMKIT_EXPORT AudioPlayer : public Module, public JSExport<AudioPlayer>
		{

		public:

			/*!
			  @property
			  @abstract allowBackground
			  @discussion Boolean to indicate if audio should continue playing even if the associatedAndroid [Activity](Titanium.Android.Activity) is paused.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, allowBackground);

			/*!
			  @property
			  @abstract autoplay
			  @discussion Indicates if an audio should automatically start playback.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, autoplay);

			/*!
			  @property
			  @abstract bitRate
			  @discussion Bit rate of the current playback stream.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::uint32_t, bitRate);

			/*!
			  @property
			  @abstract duration
			  @discussion Estimated duration in milliseconds of the file being played.
			*/
			TITANIUM_PROPERTY_IMPL_READONLY_DEF(std::chrono::milliseconds, duration);

			/*!
			  @property
			  @abstract idle
			  @discussion Boolean indicating if the player is idle.
			*/
			TITANIUM_PROPERTY_IMPL_READONLY_DEF(bool, idle);

			/*!
			  @property
			  @abstract paused
			  @discussion Boolean indicating if audio playback is paused.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, paused);

			/*!
			  @property
			  @abstract playing
			  @discussion Boolean indicating if audio is currently playing.
			*/
			TITANIUM_PROPERTY_IMPL_READONLY_DEF(bool, playing);

			/*!
			  @property
			  @abstract progress
			  @discussion Current playback progress, in milliseconds.
			*/
			TITANIUM_PROPERTY_IMPL_READONLY_DEF(std::chrono::milliseconds, progress);

			/*!
			  @property
			  @abstract state
			  @discussion Current state of playback, specified using one of the `STATE` constants defined on this object.
			*/
			TITANIUM_PROPERTY_IMPL_READONLY_DEF(AudioState, state);

			/*!
			  @property
			  @abstract url
			  @discussion URL for the audio stream.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, url);

			/*!
			  @property
			  @abstract volume
			  @discussion Volume of the audio, from 0.0 (muted) to 1.0 (loudest).
			*/
			TITANIUM_PROPERTY_IMPL_DEF(double, volume);

			/*!
			  @property
			  @abstract waiting
			  @discussion Boolean indicating if the playback is waiting for audio data from the network.
			*/
			TITANIUM_PROPERTY_IMPL_READONLY_DEF(bool, waiting);

			/*!
			  @property
			  @abstract bufferSize
			  @discussion Size of the buffer used for streaming, in bytes.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::uint32_t, bufferSize);

			/*!
			  @property
			  @abstract time
			  @discussion Current playback position of the audio.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::chrono::milliseconds, time);

			/*!
			  @method
			  @abstract isPaused
			  @discussion Returns the value of the [paused](Titanium.Media.AudioPlayer.paused) property.
			*/
			virtual bool isPaused() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract isPlaying
			  @discussion Returns the value of the [playing](Titanium.Media.AudioPlayer.playing) property.
			*/
			virtual bool isPlaying() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract pause
			  @discussion Pauses audio playback.
			*/
			virtual void pause() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract play
			  @discussion Starts or resumes audio playback.
			*/
			virtual void play() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract release
			  @discussion Stops buffering audio data and releases audio resources.
			*/
			virtual void release() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract start
			  @discussion Starts or resumes audio playback.
			*/
			virtual void start() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract stateDescription
			  @discussion Converts a [state](Titanium.Media.AudioPlayer.state) value into a text descriptionsuitable for display.
			*/
			virtual std::string stateDescription(const AudioState& state) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract stop
			  @discussion Stops audio playback.
			*/
			virtual void stop() TITANIUM_NOEXCEPT;

			AudioPlayer(const JSContext&) TITANIUM_NOEXCEPT;
			virtual ~AudioPlayer()                     = default;
			AudioPlayer(const AudioPlayer&)            = default;
			AudioPlayer& operator=(const AudioPlayer&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			AudioPlayer(AudioPlayer&&)                 = default;
			AudioPlayer& operator=(AudioPlayer&&)      = default;
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
			TITANIUM_PROPERTY_DEF(autoplay);
			TITANIUM_PROPERTY_DEF(bitRate);
			TITANIUM_PROPERTY_READONLY_DEF(duration);
			TITANIUM_PROPERTY_READONLY_DEF(idle);
			TITANIUM_PROPERTY_DEF(paused);
			TITANIUM_PROPERTY_READONLY_DEF(playing);
			TITANIUM_PROPERTY_READONLY_DEF(progress);
			TITANIUM_PROPERTY_READONLY_DEF(state);
			TITANIUM_PROPERTY_DEF(url);
			TITANIUM_PROPERTY_DEF(volume);
			TITANIUM_PROPERTY_READONLY_DEF(waiting);
			TITANIUM_PROPERTY_DEF(bufferSize);
			TITANIUM_PROPERTY_DEF(time);

			TITANIUM_FUNCTION_DEF(isPaused);
			TITANIUM_FUNCTION_DEF(isPlaying);
			TITANIUM_FUNCTION_DEF(pause);
			TITANIUM_FUNCTION_DEF(play);
			TITANIUM_FUNCTION_DEF(release);
			TITANIUM_FUNCTION_DEF(start);
			TITANIUM_FUNCTION_DEF(stateDescription);
			TITANIUM_FUNCTION_DEF(stop);
			TITANIUM_FUNCTION_DEF(getAllowBackground);
			TITANIUM_FUNCTION_DEF(setAllowBackground);
			TITANIUM_FUNCTION_DEF(getAutoplay);
			TITANIUM_FUNCTION_DEF(setAutoplay);
			TITANIUM_FUNCTION_DEF(getBitRate);
			TITANIUM_FUNCTION_DEF(setBitRate);
			TITANIUM_FUNCTION_DEF(getDuration);
			TITANIUM_FUNCTION_DEF(getIdle);
			TITANIUM_FUNCTION_DEF(getPaused);
			TITANIUM_FUNCTION_DEF(setPaused);
			TITANIUM_FUNCTION_DEF(getPlaying);
			TITANIUM_FUNCTION_DEF(getProgress);
			TITANIUM_FUNCTION_DEF(getState);
			TITANIUM_FUNCTION_DEF(getUrl);
			TITANIUM_FUNCTION_DEF(setUrl);
			TITANIUM_FUNCTION_DEF(getVolume);
			TITANIUM_FUNCTION_DEF(setVolume);
			TITANIUM_FUNCTION_DEF(getWaiting);
			TITANIUM_FUNCTION_DEF(getBufferSize);
			TITANIUM_FUNCTION_DEF(setBufferSize);
			TITANIUM_FUNCTION_DEF(getTime);
			TITANIUM_FUNCTION_DEF(setTime);

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
			bool autoplay__;
			std::uint32_t bitRate__;
			std::chrono::milliseconds duration__;
			bool idle__;
			bool paused__;
			bool playing__;
			std::chrono::milliseconds progress__;
			AudioState state__;
			std::string url__;
			double volume__;
			bool waiting__;
			std::uint32_t bufferSize__;
			std::chrono::milliseconds time__;
#pragma warning(pop)
		};

	} // namespace Media
} // namespace Titanium
#endif // _TITANIUM_MEDIA_AUDIOPLAYER_HPP_