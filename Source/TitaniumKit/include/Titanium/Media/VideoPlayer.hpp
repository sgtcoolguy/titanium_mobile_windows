/**
 * TitaniumKit Titanium.Media.VideoPlayer
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MEDIA_VIDEOPLAYER_HPP_
#define _TITANIUM_MEDIA_VIDEOPLAYER_HPP_

#include "Titanium/UI/View.hpp"
#include "Titanium/UI/Dimension.hpp"
#include "Titanium/Media/Constants.hpp"
#include <chrono>
#include <unordered_set>

namespace Titanium
{
	class Blob;

	namespace Media
	{
		using namespace HAL;

		/*!
		  @class
		  @discussion This is the Titanium VideoPlayer Module.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.Media.VideoPlayer
		*/
		class TITANIUMKIT_EXPORT VideoPlayer : public Titanium::UI::View, public JSExport<VideoPlayer>
		{

		public:

			/*!
			  @property
			  @abstract allowsAirPlay
			  @discussion Whether or not the current movie can be played on a remote device.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, allowsAirPlay);

			/*!
			  @property
			  @abstract autoplay
			  @discussion Indicates if a movie should automatically start playback.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, autoplay);

			/*!
			  @property
			  @abstract contentURL
			  @discussion URL of the media to play.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, contentURL);

			/*!
			  @property
			  @abstract currentPlaybackTime
			  @discussion Current playback time of the current movie in milliseconds.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::chrono::milliseconds, currentPlaybackTime);

			/*!
			  @property
			  @abstract duration
			  @discussion The duration of the current movie in milliseconds, or 0.0 if not known.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::chrono::milliseconds, duration);

			/*!
			  @property
			  @abstract endPlaybackTime
			  @discussion The end time of movie playback, in milliseconds.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::chrono::milliseconds, endPlaybackTime);

			/*!
			  @property
			  @abstract fullscreen
			  @discussion Determines if the movie is presented in the entire screen (obscuring all other application content). 
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, fullscreen);

			/*!
			  @property
			  @abstract initialPlaybackTime
			  @discussion The start time of movie playback, in milliseconds.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::chrono::milliseconds, initialPlaybackTime);

			/*!
			  @property
			  @abstract loadState
			  @discussion Returns the network load state of the movie player.
			*/
			TITANIUM_PROPERTY_IMPL_READONLY_DEF(VideoLoadState, loadState);

			/*!
			  @property
			  @abstract media
			  @discussion Media object to play, as either a `File`,  a `Blob`, or a URL.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::shared_ptr<Titanium::Blob>, media);

			/*!
			  @property
			  @abstract mediaControlStyle
			  @discussion The style of the playback controls.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(VideoControlStyle, mediaControlStyle);

			/*!
			  @property
			  @abstract mediaTypes
			  @discussion The types of media in the movie, or <Titanium.Media.VIDEO_MEDIA_TYPE_NONE> if not known.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::unordered_set<VideoMediaType>, mediaTypes);

			/*!
			  @property
			  @abstract movieControlMode
			  @discussion Style of the media playback controls.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(VideoControlStyle, movieControlMode);

			/*!
			  @property
			  @abstract naturalSize
			  @discussion Returns the natural size of the movie.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(Titanium::UI::Dimension, naturalSize);

			/*!
			  @property
			  @abstract playableDuration
			  @discussion Currently playable duration of the movie, in milliseconds, for progressively downloaded network content, or 0.0 if not known.
			*/
			TITANIUM_PROPERTY_IMPL_READONLY_DEF(std::chrono::milliseconds, playableDuration);

			/*!
			  @property
			  @abstract playbackState
			  @discussion Current playback state of the video player.
			*/
			TITANIUM_PROPERTY_IMPL_READONLY_DEF(VideoPlaybackState, playbackState);

			/*!
			  @property
			  @abstract playing
			  @discussion Boolean to indicate if the player has started playing.
			*/
			TITANIUM_PROPERTY_IMPL_READONLY_DEF(bool, playing);

			/*!
			  @property
			  @abstract repeatMode
			  @discussion Determines how the movie player repeats when reaching the end of playback.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(VideoRepeatMode, repeatMode);

			/*!
			  @property
			  @abstract scalingMode
			  @discussion Determines how the content scales to fit the view.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(VideoScaling, scalingMode);

			/*!
			  @property
			  @abstract sourceType
			  @discussion The playback type of the movie.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(VideoSourceType, sourceType);

			/*!
			  @property
			  @abstract url
			  @discussion URL of the media to play.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::vector<std::string>, urls);

			/*!
			  @property
			  @abstract useApplicationAudioSession
			  @discussion Indicates if the movie player should inherit the application's audio sessioninstead of creating a new session.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, useApplicationAudioSession);

			/*!
			  @property
			  @abstract volume
			  @discussion Volume of the audio portion of the video. 
			*/
			TITANIUM_PROPERTY_IMPL_DEF(double, volume);

			/*!
			  @method
			  @abstract cancelAllThumbnailImageRequests
			  @discussion Cancels all pending asynchronous thumbnail requests.
			*/
			virtual void cancelAllThumbnailImageRequests() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract pause
			  @discussion Pauses playing the video.
			*/
			virtual void pause() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract play
			  @discussion Starts playing the video.
			*/
			virtual void play() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract release
			  @discussion Releases the internal video resources immediately.
			*/
			virtual void release() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract requestThumbnailImagesAtTimes
			  @discussion Asynchronously request thumbnail images for one or more points in time in the video.
			*/
			virtual void requestThumbnailImagesAtTimes(std::vector<std::chrono::seconds> times, const VideoTimeOption& option, JSValue callback) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract setBackgroundView
			  @discussion Sets the background view for customization which is always displayed behind movie content.
			*/
			virtual void setBackgroundView(std::shared_ptr<Titanium::UI::View> view) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract stop
			  @discussion Stops playing the video.
			*/
			virtual void stop() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract thumbnailImageAtTime
			  @discussion Returns a thumbnail image for the video at the specified time.
			*/
			virtual std::shared_ptr<Titanium::Blob> thumbnailImageAtTime(const std::chrono::seconds& time, const VideoTimeOption& option) TITANIUM_NOEXCEPT;

			VideoPlayer(const JSContext&) TITANIUM_NOEXCEPT;
			virtual ~VideoPlayer()                     = default;
			VideoPlayer(const VideoPlayer&)            = default;
			VideoPlayer& operator=(const VideoPlayer&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			VideoPlayer(VideoPlayer&&)                 = default;
			VideoPlayer& operator=(VideoPlayer&&)      = default;
#endif

			static void JSExportInitialize();

			TITANIUM_PROPERTY_DEF(allowsAirPlay);
			TITANIUM_PROPERTY_DEF(autoplay);
			TITANIUM_PROPERTY_DEF(contentURL);
			TITANIUM_PROPERTY_DEF(currentPlaybackTime);
			TITANIUM_PROPERTY_DEF(duration);
			TITANIUM_PROPERTY_DEF(endPlaybackTime);
			TITANIUM_PROPERTY_DEF(fullscreen);
			TITANIUM_PROPERTY_DEF(initialPlaybackTime);
			TITANIUM_PROPERTY_READONLY_DEF(loadState);
			TITANIUM_PROPERTY_DEF(media);
			TITANIUM_PROPERTY_DEF(mediaControlStyle);
			TITANIUM_PROPERTY_DEF(mediaTypes);
			TITANIUM_PROPERTY_DEF(movieControlMode);
			TITANIUM_PROPERTY_DEF(naturalSize);
			TITANIUM_PROPERTY_READONLY_DEF(playableDuration);
			TITANIUM_PROPERTY_READONLY_DEF(playbackState);
			TITANIUM_PROPERTY_READONLY_DEF(playing);
			TITANIUM_PROPERTY_DEF(repeatMode);
			TITANIUM_PROPERTY_DEF(scalingMode);
			TITANIUM_PROPERTY_DEF(sourceType);
			TITANIUM_PROPERTY_DEF(url);
			TITANIUM_PROPERTY_DEF(useApplicationAudioSession);
			TITANIUM_PROPERTY_DEF(volume);

			TITANIUM_FUNCTION_DEF(cancelAllThumbnailImageRequests);
			TITANIUM_FUNCTION_DEF(pause);
			TITANIUM_FUNCTION_DEF(play);
			TITANIUM_FUNCTION_DEF(release);
			TITANIUM_FUNCTION_DEF(requestThumbnailImagesAtTimes);
			TITANIUM_FUNCTION_DEF(setBackgroundView);
			TITANIUM_FUNCTION_DEF(stop);
			TITANIUM_FUNCTION_DEF(thumbnailImageAtTime);
			TITANIUM_FUNCTION_DEF(getAllowsAirPlay);
			TITANIUM_FUNCTION_DEF(setAllowsAirPlay);
			TITANIUM_FUNCTION_DEF(getAutoplay);
			TITANIUM_FUNCTION_DEF(setAutoplay);
			TITANIUM_FUNCTION_DEF(getContentURL);
			TITANIUM_FUNCTION_DEF(setContentURL);
			TITANIUM_FUNCTION_DEF(getCurrentPlaybackTime);
			TITANIUM_FUNCTION_DEF(setCurrentPlaybackTime);
			TITANIUM_FUNCTION_DEF(getDuration);
			TITANIUM_FUNCTION_DEF(setDuration);
			TITANIUM_FUNCTION_DEF(getEndPlaybackTime);
			TITANIUM_FUNCTION_DEF(setEndPlaybackTime);
			TITANIUM_FUNCTION_DEF(getFullscreen);
			TITANIUM_FUNCTION_DEF(setFullscreen);
			TITANIUM_FUNCTION_DEF(getInitialPlaybackTime);
			TITANIUM_FUNCTION_DEF(setInitialPlaybackTime);
			TITANIUM_FUNCTION_DEF(getLoadState);
			TITANIUM_FUNCTION_DEF(setMedia);
			TITANIUM_FUNCTION_DEF(getMediaControlStyle);
			TITANIUM_FUNCTION_DEF(setMediaControlStyle);
			TITANIUM_FUNCTION_DEF(getMediaTypes);
			TITANIUM_FUNCTION_DEF(setMediaTypes);
			TITANIUM_FUNCTION_DEF(getMovieControlMode);
			TITANIUM_FUNCTION_DEF(setMovieControlMode);
			TITANIUM_FUNCTION_DEF(getNaturalSize);
			TITANIUM_FUNCTION_DEF(setNaturalSize);
			TITANIUM_FUNCTION_DEF(getPlayableDuration);
			TITANIUM_FUNCTION_DEF(getPlaybackState);
			TITANIUM_FUNCTION_DEF(getPlaying);
			TITANIUM_FUNCTION_DEF(getRepeatMode);
			TITANIUM_FUNCTION_DEF(setRepeatMode);
			TITANIUM_FUNCTION_DEF(getScalingMode);
			TITANIUM_FUNCTION_DEF(setScalingMode);
			TITANIUM_FUNCTION_DEF(getSourceType);
			TITANIUM_FUNCTION_DEF(setSourceType);
			TITANIUM_FUNCTION_DEF(getUrl);
			TITANIUM_FUNCTION_DEF(setUrl);
			TITANIUM_FUNCTION_DEF(getUseApplicationAudioSession);
			TITANIUM_FUNCTION_DEF(setUseApplicationAudioSession);
			TITANIUM_FUNCTION_DEF(getVolume);
			TITANIUM_FUNCTION_DEF(setVolume);

		protected:
#pragma warning(push)
#pragma warning(disable : 4251)
			bool allowsAirPlay__;
			bool autoplay__;
			std::string contentURL__;
			std::chrono::milliseconds currentPlaybackTime__;
			std::chrono::milliseconds duration__;
			std::chrono::milliseconds endPlaybackTime__;
			bool fullscreen__;
			std::chrono::milliseconds initialPlaybackTime__;
			VideoLoadState loadState__;
			std::shared_ptr<Titanium::Blob> media__;
			VideoControlStyle mediaControlStyle__;
			std::unordered_set<VideoMediaType> mediaTypes__;
			VideoControlStyle movieControlMode__;
			Titanium::UI::Dimension naturalSize__;
			std::chrono::milliseconds playableDuration__;
			VideoPlaybackState playbackState__;
			bool playing__;
			VideoRepeatMode repeatMode__;
			VideoScaling scalingMode__;
			VideoSourceType sourceType__;
			std::vector<std::string> urls__;
			bool useApplicationAudioSession__;
			double volume__;
#pragma warning(pop)
		};

	} // namespace Media
} // namespace Titanium
#endif // _TITANIUM_MEDIA_VIDEOPLAYER_HPP_