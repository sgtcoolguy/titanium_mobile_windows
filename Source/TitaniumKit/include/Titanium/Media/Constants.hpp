/**
 * TitaniumKit Titanium.Media constants
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MEDIA_CONSTANTS_HPP_
#define _TITANIUM_MEDIA_CONSTANTS_HPP_

namespace Titanium
{
	using namespace HAL;

	namespace Media
	{
		
		enum class AudioFileFormat
		{
			ThreeGP2,
			ThreeGPP,
			Aiff,
			Amr,
			Caf,
			Mp3,
			Mp4,
			Mp4a,
			Wave
		};
		
		enum class AudioFormat
		{
			Aac,
			Alaw,
			AppleLossless,
			Ilbc,
			Ima4,
			LinearPCM,
			Ulaw
		};

		enum class AudioSessionCategory 
		{
			Ambient,
			Playback,
			PlayAndRecord,
			Record,
			SoloAmbient
		};
		
		enum class AudioSessionOverrideRoute
		{
			None,
			Speaker
		};
		
		enum class AudioSessionPort
		{
			Airplay,
			BluetoothA2DP,
			BluetoothHFP,
			BluetoothLE,
			BuiltinMic,
			BuiltinReceiver,
			BuiltinSpeaker,
			CarAudio,
			Hdmi,
			HeadPhones,
			HeadSetMic,
			LineIn,
			LineOut,
			USBAudio
		};
		
		enum class CameraOption
		{
			Authorized,
			Denied,
			NotDetermined,
			Restricted,
			Front,
			Rear,
			FlashAuto,
			FlashOff,
			FlashOn
		};

		enum class State
		{
			DeviceBusy,
			NoCamera,
			NoVideo
		};

		enum class MediaType 
		{
			Photo,
			Video
		};
		
		enum class MusicMediaGroup
		{
			Album,
			AlbumArtist,
			Artist,
			Composer,
			Genre,
			Playlist,
			PodcastTitle,
			Title
		};

		enum class MusicMediaType
		{
			All,
			AnyAudio,
			AudioBook,
			Music,
			Podcast
		};
		
		enum class MusicPlayerRepeat
		{
			All,
			Default,
			None,
			One
		};
		
		enum class MusicPlayerShuffle
		{
			Albums,
			Default,
			None,
			Songs
		};
		
		enum class MusicPlayerState
		{
			Interrupted,
			Paused,
			Playing,
			SeekBackward,
			SeekForward,
			Stopped
		};
		
		enum class Quality
		{
			High,
			Low,
			Medium
		};
		
		enum class Error
		{
			Unknown
		};
		
		enum class VideoControl
		{
			Default,
			Embedded,
			Fullscreen,
			Hidden,
			None
		};
		
		enum class VideoFinishReason
		{
			PlaybackEnded,
			PlaybackError,
			UserExited
		};
		
		enum class VideoLoadState
		{
			Playable,
			PlaythroughOK,
			Stalled,
			Unknown
		};
		
		enum class VideoMediaType
		{
			Audio,
			None,
			Video
		};
		
		enum class VideoPlaybackState
		{
			Interrupted,
			Paused,
			Playing,
			SeekingBackward,
			SeekingForward,
			Stopped
		};
		
		enum class VideoRepeatMode
		{
			None,
			One
		};
		
		enum class VideoScaling
		{
			AspectFill,
			AspectFit,
			ModeFill,
			None
		};
		
		enum class VideoSourceType
		{
			File,
			Streaming,
			Unknown
		};
		
		enum class VideoTimeOption
		{
			ClosestSync,
			Exact,
			NearestKeyframe,
			NextSync,
			PreviousSync
		};

	} // namespace Media
} // namespace Titanium

#endif // _TITANIUM_MEDIA_CONSTANTS_HPP_