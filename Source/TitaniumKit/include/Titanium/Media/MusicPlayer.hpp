/**
 * TitaniumKit Titanium.Media.MusicPlayer
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MEDIA_MUSICPLAYER_HPP_
#define _TITANIUM_MEDIA_MUSICPLAYER_HPP_

#include "Titanium/Module.hpp"
#include "Titanium/Media/Constants.hpp"
#include "Titanium/Media/Item.hpp"
#include <chrono>

namespace Titanium
{
	namespace Media
	{
		using namespace HAL;

		/*!
		  @class
		  @discussion This is the Titanium MusicPlayer Module.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.Media.MusicPlayer
		*/
		class TITANIUMKIT_EXPORT MusicPlayer : public Module, public JSExport<MusicPlayer>
		{

		public:

			/*!
			  @property
			  @abstract currentPlaybackTime
			  @discussion Current point in song playback, in seconds.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::chrono::seconds, currentPlaybackTime);

			/*!
			  @property
			  @abstract nowPlaying
			  @discussion An `Item` object representing the currently playing media item.
			*/
			TITANIUM_PROPERTY_IMPL_READONLY_DEF(std::shared_ptr<Item>, nowPlaying);

			/*!
			  @property
			  @abstract playbackState
			  @discussion Playback state.
			*/
			TITANIUM_PROPERTY_IMPL_READONLY_DEF(MusicPlayerState, playbackState);

			/*!
			  @property
			  @abstract repeatMode
			  @discussion Repeat setting.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(MusicPlayerRepeat, repeatMode);

			/*!
			  @property
			  @abstract shuffleMode
			  @discussion Shuffle setting.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(MusicPlayerShuffle, shuffleMode);

			/*!
			  @property
			  @abstract volume
			  @discussion Volume level for the music player from 0.0 (muted) to 1.0 (loudest).
			*/
			TITANIUM_PROPERTY_IMPL_DEF(double, volume);

			/*!
			  @method
			  @abstract pause
			  @discussion Pauses playback of the current media item.
			*/
			virtual void pause() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract play
			  @discussion Begins playback of the current media item.
			*/
			virtual void play() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract seekBackward
			  @discussion Begins seeking backward in the currently playing media.
			*/
			virtual void seekBackward() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract seekForward
			  @discussion Begins seeking forward in the currently playing media item.
			*/
			virtual void seekForward() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract setQueue
			  @discussion Sets the media queue.
			*/
			virtual void setQueue(std::vector<std::shared_ptr<Item>> queues) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract skipToBeginning
			  @discussion Skips to the beginning of the currently playing media item.
			*/
			virtual void skipToBeginning() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract skipToNext
			  @discussion Skips to the next media item in the queue.
			*/
			virtual void skipToNext() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract skipToPrevious
			  @discussion Skips to the previous media item in the queue.
			*/
			virtual void skipToPrevious() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract stop
			  @discussion Stops playback of the current media queue.
			*/
			virtual void stop() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract stopSeeking
			  @discussion Ends a seek operation and returns to the previous playback state.See also: [seekForward](Titanium.Media.MusicPlayer.seekForward) and[seekBackward](Titanium.Media.MusicPlayer.seekBackward).
			*/
			virtual void stopSeeking() TITANIUM_NOEXCEPT;

			MusicPlayer(const JSContext&) TITANIUM_NOEXCEPT;
			virtual ~MusicPlayer()                     = default;
			MusicPlayer(const MusicPlayer&)            = default;
			MusicPlayer& operator=(const MusicPlayer&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			MusicPlayer(MusicPlayer&&)                 = default;
			MusicPlayer& operator=(MusicPlayer&&)      = default;
#endif

			static void JSExportInitialize();

			TITANIUM_PROPERTY_DEF(currentPlaybackTime);
			TITANIUM_PROPERTY_READONLY_DEF(nowPlaying);
			TITANIUM_PROPERTY_READONLY_DEF(playbackState);
			TITANIUM_PROPERTY_DEF(repeatMode);
			TITANIUM_PROPERTY_DEF(shuffleMode);
			TITANIUM_PROPERTY_DEF(volume);

			TITANIUM_FUNCTION_DEF(pause);
			TITANIUM_FUNCTION_DEF(play);
			TITANIUM_FUNCTION_DEF(seekBackward);
			TITANIUM_FUNCTION_DEF(seekForward);
			TITANIUM_FUNCTION_DEF(setQueue);
			TITANIUM_FUNCTION_DEF(skipToBeginning);
			TITANIUM_FUNCTION_DEF(skipToNext);
			TITANIUM_FUNCTION_DEF(skipToPrevious);
			TITANIUM_FUNCTION_DEF(stop);
			TITANIUM_FUNCTION_DEF(stopSeeking);
			TITANIUM_FUNCTION_DEF(getCurrentPlaybackTime);
			TITANIUM_FUNCTION_DEF(setCurrentPlaybackTime);
			TITANIUM_FUNCTION_DEF(getNowPlaying);
			TITANIUM_FUNCTION_DEF(getPlaybackState);
			TITANIUM_FUNCTION_DEF(getRepeatMode);
			TITANIUM_FUNCTION_DEF(setRepeatMode);
			TITANIUM_FUNCTION_DEF(getShuffleMode);
			TITANIUM_FUNCTION_DEF(setShuffleMode);
			TITANIUM_FUNCTION_DEF(getVolume);
			TITANIUM_FUNCTION_DEF(setVolume);

		protected:
#pragma warning(push)
#pragma warning(disable : 4251)
			std::chrono::seconds currentPlaybackTime__;
			std::shared_ptr<Item> nowPlaying__;
			MusicPlayerState playbackState__;
			MusicPlayerRepeat repeatMode__;
			MusicPlayerShuffle shuffleMode__;
			double volume__;
#pragma warning(pop)
		};

	} // namespace Media
} // namespace Titanium
#endif // _TITANIUM_MEDIA_MUSICPLAYER_HPP_