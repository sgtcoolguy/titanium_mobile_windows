/**
 * TitaniumKit Titanium.Media
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/MediaModule.hpp"

namespace Titanium
{

	MediaModule::MediaModule(const JSContext& js_context) TITANIUM_NOEXCEPT
		: Module(js_context)
		, audio_fileformat_3gp2__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioFileFormat::ThreeGP2)))
		, audio_fileformat_3gpp__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioFileFormat::ThreeGPP)))
		, audio_fileformat_aiff__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioFileFormat::Aiff)))
		, audio_fileformat_amr__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioFileFormat::Amr)))
		, audio_fileformat_caf__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioFileFormat::Caf)))
		, audio_fileformat_mp3__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioFileFormat::Mp3)))
		, audio_fileformat_mp4__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioFileFormat::Mp4)))
		, audio_fileformat_mp4a__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioFileFormat::Mp4a)))
		, audio_fileformat_wave__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioFileFormat::Wave)))
		, audio_format_aac__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioFormat::Aac)))
		, audio_format_alaw__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioFormat::Alaw)))
		, audio_format_apple_lossless__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioFormat::AppleLossless)))
		, audio_format_ilbc__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioFormat::Ilbc)))
		, audio_format_ima4__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioFormat::Ima4)))
		, audio_format_linear_pcm__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioFormat::LinearPCM)))
		, audio_format_ulaw__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioFormat::Ulaw)))
		, audio_session_category_ambient__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioSessionCategory::Ambient)))
		, audio_session_category_playback__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioSessionCategory::Playback)))
		, audio_session_category_play_and_record__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioSessionCategory::PlayAndRecord)))
		, audio_session_category_record__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioSessionCategory::Record)))
		, audio_session_category_solo_ambient__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioSessionCategory::SoloAmbient)))
		, audio_session_override_route_none__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioSessionOverrideRoute::None)))
		, audio_session_override_route_speaker__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioSessionOverrideRoute::Speaker)))
		, audio_session_port_linein__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioSessionPort::LineIn)))
		, audio_session_port_builtinmic__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioSessionPort::BuiltinMic)))
		, audio_session_port_headsetmic__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioSessionPort::HeadSetMic)))
		, audio_session_port_lineout__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioSessionPort::LineOut)))
		, audio_session_port_headphones__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioSessionPort::HeadPhones)))
		, audio_session_port_bluetootha2dp__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioSessionPort::BluetoothA2DP)))
		, audio_session_port_builtinreceiver__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioSessionPort::BuiltinReceiver)))
		, audio_session_port_builtinspeaker__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioSessionPort::BuiltinSpeaker)))
		, audio_session_port_hdmi__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioSessionPort::Hdmi)))
		, audio_session_port_airplay__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioSessionPort::Airplay)))
		, audio_session_port_bluetoothhfp__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioSessionPort::BluetoothHFP)))
		, audio_session_port_usbaudio__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioSessionPort::USBAudio)))
		, audio_session_port_bluetoothle__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioSessionPort::BluetoothLE)))
		, audio_session_port_caraudio__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::AudioSessionPort::CarAudio)))
		, camera_flash_auto__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::CameraOption::FlashAuto)))
		, camera_flash_off__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::CameraOption::FlashOff)))
		, camera_flash_on__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::CameraOption::FlashOn)))
		, camera_front__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::CameraOption::Front)))
		, camera_rear__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::CameraOption::Rear)))
		, device_busy__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::State::DeviceBusy)))
		, media_type_photo__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::MediaType::Photo)))
		, media_type_video__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::MediaType::Video)))
		, music_media_type_all__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::MusicMediaType::All)))
		, music_media_type_any_audio__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::MusicMediaType::AnyAudio)))
		, music_media_type_audiobook__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::MusicMediaType::AudioBook)))
		, music_media_type_music__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::MusicMediaType::Music)))
		, music_media_type_podcast__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::MusicMediaType::Podcast)))
		, music_media_group_title__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::MusicMediaGroup::Title)))
		, music_media_group_album__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::MusicMediaGroup::Album)))
		, music_media_group_artist__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::MusicMediaGroup::Artist)))
		, music_media_group_album_artist__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::MusicMediaGroup::AlbumArtist)))
		, music_media_group_composer__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::MusicMediaGroup::Composer)))
		, music_media_group_genre__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::MusicMediaGroup::Genre)))
		, music_media_group_playlist__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::MusicMediaGroup::Playlist)))
		, music_media_group_podcast_title__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::MusicMediaGroup::PodcastTitle)))
		, music_player_repeat_all__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::MusicPlayerRepeat::All)))
		, music_player_repeat_default__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::MusicPlayerRepeat::Default)))
		, music_player_repeat_none__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::MusicPlayerRepeat::None)))
		, music_player_repeat_one__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::MusicPlayerRepeat::One)))
		, music_player_shuffle_albums__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::MusicPlayerShuffle::Albums)))
		, music_player_shuffle_default__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::MusicPlayerShuffle::Default)))
		, music_player_shuffle_none__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::MusicPlayerShuffle::None)))
		, music_player_shuffle_songs__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::MusicPlayerShuffle::Songs)))
		, music_player_state_interrupted__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::MusicPlayerState::Interrupted)))
		, music_player_state_paused__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::MusicPlayerState::Paused)))
		, music_player_state_playing__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::MusicPlayerState::Playing)))
		, music_player_state_seek_backward__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::MusicPlayerState::SeekBackward)))
		, music_player_state_seek_forward__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::MusicPlayerState::SeekForward)))
		, music_player_state_stopped__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::MusicPlayerState::Stopped)))
		, no_camera__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::State::NoCamera)))
		, no_video__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::State::NoVideo)))
		, quality_high__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::Quality::High)))
		, quality_low__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::Quality::Low)))
		, quality_medium__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::Quality::Medium)))
		, unknown_error__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::Error::Unknown)))
		, video_control_default__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoControlStyle::Default)))
		, video_control_embedded__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoControlStyle::Embedded)))
		, video_control_fullscreen__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoControlStyle::Fullscreen)))
		, video_control_hidden__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoControlStyle::Hidden)))
		, video_control_none__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoControlStyle::None)))
		, video_finish_reason_playback_ended__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoFinishReason::PlaybackEnded)))
		, video_finish_reason_playback_error__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoFinishReason::PlaybackError)))
		, video_finish_reason_user_exited__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoFinishReason::UserExited)))
		, video_load_state_playable__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoLoadState::Playable)))
		, video_load_state_playthrough_ok__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoLoadState::PlaythroughOK)))
		, video_load_state_stalled__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoLoadState::Stalled)))
		, video_load_state_unknown__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoLoadState::Unknown)))
		, video_media_type_audio__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoMediaType::Audio)))
		, video_media_type_none__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoMediaType::None)))
		, video_media_type_video__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoMediaType::Video)))
		, video_playback_state_interrupted__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoPlaybackState::Interrupted)))
		, video_playback_state_paused__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoPlaybackState::Paused)))
		, video_playback_state_playing__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoPlaybackState::Playing)))
		, video_playback_state_seeking_backward__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoPlaybackState::SeekingBackward)))
		, video_playback_state_seeking_forward__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoPlaybackState::SeekingForward)))
		, video_playback_state_stopped__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoPlaybackState::Stopped)))
		, video_repeat_mode_none__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoRepeatMode::None)))
		, video_repeat_mode_one__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoRepeatMode::One)))
		, video_scaling_aspect_fill__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoScaling::AspectFill)))
		, video_scaling_aspect_fit__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoScaling::AspectFit)))
		, video_scaling_mode_fill__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoScaling::ModeFill)))
		, video_scaling_none__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoScaling::None)))
		, video_source_type_file__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoSourceType::File)))
		, video_source_type_streaming__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoSourceType::Streaming)))
		, video_source_type_unknown__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoSourceType::Unknown)))
		, video_time_option_exact__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoTimeOption::Exact)))
		, video_time_option_nearest_keyframe__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoTimeOption::NearestKeyframe)))
		, video_time_option_closest_sync__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoTimeOption::ClosestSync)))
		, video_time_option_next_sync__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoTimeOption::NextSync)))
		, video_time_option_previous_sync__(js_context.CreateNumber(static_cast<std::uint32_t>(Media::VideoTimeOption::PreviousSync)))
		, appMusicPlayer__(get_context().CreateNull())
		, audioPlaying__(false)
		, audioSessionCategory__(Media::AudioSessionCategory::Playback)
		, averageMicrophonePower__(0)
		, cameraFlashMode__(Media::CameraOption::FlashAuto)
		, canRecord__(false)
		, isCameraSupported__(false)
		, peakMicrophonePower__(0)
		, systemMusicPlayer__(get_context().CreateNull())
		, volume__(0)
	{
	}
	
	TITANIUM_PROPERTY_READ(MediaModule, bool, audioPlaying)
	TITANIUM_PROPERTY_READWRITE(MediaModule, Media::AudioSessionCategory, audioSessionCategory)
	TITANIUM_PROPERTY_READ(MediaModule, std::vector<Media::CameraOption>, availableCameras)
	TITANIUM_PROPERTY_READWRITE(MediaModule, std::vector<Media::MediaType>, availableCameraMediaTypes)
	TITANIUM_PROPERTY_READWRITE(MediaModule, std::vector<Media::MediaType>, availablePhotoGalleryMediaTypes)
	TITANIUM_PROPERTY_READWRITE(MediaModule, std::vector<Media::MediaType>, availablePhotoMediaTypes)
	TITANIUM_PROPERTY_READWRITE(MediaModule, double, averageMicrophonePower)
	TITANIUM_PROPERTY_READ(MediaModule, double, peakMicrophonePower)
	TITANIUM_PROPERTY_READWRITE(MediaModule, Media::CameraOption, cameraFlashMode)
	TITANIUM_PROPERTY_READ(MediaModule, bool, canRecord)
	TITANIUM_PROPERTY_READ(MediaModule, Media::RouteDescription, currentRoute)
	TITANIUM_PROPERTY_READ(MediaModule, bool, isCameraSupported)
	TITANIUM_PROPERTY_READ(MediaModule, double, volume)

	void MediaModule::beep() TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::beep: Unimplemented");
	}

	void MediaModule::hideCamera() TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::hideCamera: Unimplemented");
	}

	void MediaModule::hideMusicLibrary() TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::hideMusicLibrary: Unimplemented");
	}

	bool MediaModule::isMediaTypeSupported(const std::string& source, const std::string& type) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::isMediaTypeSupported: Unimplemented");
		return false;
	}

	void MediaModule::openMusicLibrary(const Media::MusicLibraryOptionsType& options) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::openMusicLibrary: Unimplemented");
	}

	void MediaModule::openPhotoGallery(const Media::PhotoGalleryOptionsType& options) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::openPhotoGallery: Unimplemented");
	}

	void MediaModule::previewImage(const std::unordered_map<std::string, Media::PreviewImageOptions>& options) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::previewImage: Unimplemented");
	}

	void MediaModule::saveToPhotoGallery(const std::shared_ptr<Titanium::Filesystem::File>& media, JSValue callbacks) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::saveToPhotoGallery: Unimplemented");
	}

	void MediaModule::setOverrideAudioRoute(const Media::AudioSessionOverrideRoute& route) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::setOverrideAudioRoute: Unimplemented");
	}

	void MediaModule::showCamera(const Media::CameraOptionsType& options) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::showCamera: Unimplemented");
	}

	std::vector<std::shared_ptr<Media::Item>> MediaModule::queryMusicLibrary(const Media::MediaQueryType& query) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::queryMusicLibrary: Unimplemented");
		return std::vector<std::shared_ptr<Media::Item>>();
	}

	void MediaModule::startMicrophoneMonitor() TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::startMicrophoneMonitor: Unimplemented");
	}

	void MediaModule::stopMicrophoneMonitor() TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::stopMicrophoneMonitor: Unimplemented");
	}

	void MediaModule::takePicture() TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::takePicture: Unimplemented");
	}

	void MediaModule::startVideoCapture() TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::startVideoCapture: Unimplemented");
	}

	void MediaModule::stopVideoCapture() TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::stopVideoCapture: Unimplemented");
	}

	void MediaModule::switchCamera(const Media::CameraOption& camera) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::switchCamera: Unimplemented");
	}

	void MediaModule::takeScreenshot(JSValue callback) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::takeScreenshot: Unimplemented");
	}

	void MediaModule::vibrate(std::vector<std::chrono::milliseconds> pattern) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::vibrate: Unimplemented");
	}

	void MediaModule::requestAuthorization(JSValue callback) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("MediaModule::requestAuthorization: Unimplemented");
	}

	void MediaModule::JSExportInitialize() 
	{
		JSExport<MediaModule>::SetClassVersion(1);
		JSExport<MediaModule>::SetParent(JSExport<Module>::Class());

		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_FILEFORMAT_3GP2);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_FILEFORMAT_3GPP);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_FILEFORMAT_AIFF);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_FILEFORMAT_AMR);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_FILEFORMAT_CAF);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_FILEFORMAT_MP3);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_FILEFORMAT_MP4);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_FILEFORMAT_MP4A);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_FILEFORMAT_WAVE);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_FORMAT_AAC);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_FORMAT_ALAW);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_FORMAT_APPLE_LOSSLESS);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_FORMAT_ILBC);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_FORMAT_IMA4);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_FORMAT_LINEAR_PCM);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_FORMAT_ULAW);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_SESSION_CATEGORY_AMBIENT);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_SESSION_CATEGORY_PLAYBACK);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_SESSION_CATEGORY_PLAY_AND_RECORD);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_SESSION_CATEGORY_RECORD);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_SESSION_CATEGORY_SOLO_AMBIENT);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_SESSION_OVERRIDE_ROUTE_NONE);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_SESSION_OVERRIDE_ROUTE_SPEAKER);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_SESSION_PORT_LINEIN);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_SESSION_PORT_BUILTINMIC);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_SESSION_PORT_HEADSETMIC);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_SESSION_PORT_LINEOUT);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_SESSION_PORT_HEADPHONES);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_SESSION_PORT_BLUETOOTHA2DP);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_SESSION_PORT_BUILTINRECEIVER);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_SESSION_PORT_BUILTINSPEAKER);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_SESSION_PORT_HDMI);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_SESSION_PORT_AIRPLAY);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_SESSION_PORT_BLUETOOTHHFP);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_SESSION_PORT_USBAUDIO);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_SESSION_PORT_BLUETOOTHLE);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, AUDIO_SESSION_PORT_CARAUDIO);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, CAMERA_FLASH_AUTO);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, CAMERA_FLASH_OFF);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, CAMERA_FLASH_ON);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, CAMERA_FRONT);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, CAMERA_REAR);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, DEVICE_BUSY);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, MEDIA_TYPE_PHOTO);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, MEDIA_TYPE_VIDEO);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, MUSIC_MEDIA_TYPE_ALL);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, MUSIC_MEDIA_TYPE_ANY_AUDIO);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, MUSIC_MEDIA_TYPE_AUDIOBOOK);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, MUSIC_MEDIA_TYPE_MUSIC);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, MUSIC_MEDIA_TYPE_PODCAST);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, MUSIC_MEDIA_GROUP_TITLE);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, MUSIC_MEDIA_GROUP_ALBUM);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, MUSIC_MEDIA_GROUP_ARTIST);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, MUSIC_MEDIA_GROUP_ALBUM_ARTIST);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, MUSIC_MEDIA_GROUP_COMPOSER);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, MUSIC_MEDIA_GROUP_GENRE);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, MUSIC_MEDIA_GROUP_PLAYLIST);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, MUSIC_MEDIA_GROUP_PODCAST_TITLE);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, MUSIC_PLAYER_REPEAT_ALL);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, MUSIC_PLAYER_REPEAT_DEFAULT);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, MUSIC_PLAYER_REPEAT_NONE);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, MUSIC_PLAYER_REPEAT_ONE);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, MUSIC_PLAYER_SHUFFLE_ALBUMS);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, MUSIC_PLAYER_SHUFFLE_DEFAULT);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, MUSIC_PLAYER_SHUFFLE_NONE);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, MUSIC_PLAYER_SHUFFLE_SONGS);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, MUSIC_PLAYER_STATE_INTERRUPTED);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, MUSIC_PLAYER_STATE_PAUSED);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, MUSIC_PLAYER_STATE_PLAYING);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, MUSIC_PLAYER_STATE_SEEK_BACKWARD);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, MUSIC_PLAYER_STATE_SEEK_FORWARD);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, MUSIC_PLAYER_STATE_STOPPED);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, NO_CAMERA);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, NO_VIDEO);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, QUALITY_HIGH);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, QUALITY_LOW);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, QUALITY_MEDIUM);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, UNKNOWN_ERROR);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_CONTROL_DEFAULT);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_CONTROL_EMBEDDED);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_CONTROL_FULLSCREEN);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_CONTROL_HIDDEN);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_CONTROL_NONE);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_FINISH_REASON_PLAYBACK_ENDED);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_FINISH_REASON_PLAYBACK_ERROR);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_FINISH_REASON_USER_EXITED);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_LOAD_STATE_PLAYABLE);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_LOAD_STATE_PLAYTHROUGH_OK);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_LOAD_STATE_STALLED);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_LOAD_STATE_UNKNOWN);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_MEDIA_TYPE_AUDIO);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_MEDIA_TYPE_NONE);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_MEDIA_TYPE_VIDEO);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_PLAYBACK_STATE_INTERRUPTED);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_PLAYBACK_STATE_PAUSED);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_PLAYBACK_STATE_PLAYING);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_PLAYBACK_STATE_SEEKING_BACKWARD);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_PLAYBACK_STATE_SEEKING_FORWARD);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_PLAYBACK_STATE_STOPPED);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_REPEAT_MODE_NONE);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_REPEAT_MODE_ONE);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_SCALING_ASPECT_FILL);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_SCALING_ASPECT_FIT);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_SCALING_MODE_FILL);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_SCALING_NONE);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_SOURCE_TYPE_FILE);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_SOURCE_TYPE_STREAMING);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_SOURCE_TYPE_UNKNOWN);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_TIME_OPTION_EXACT);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_TIME_OPTION_NEAREST_KEYFRAME);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_TIME_OPTION_CLOSEST_SYNC);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_TIME_OPTION_NEXT_SYNC);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, VIDEO_TIME_OPTION_PREVIOUS_SYNC);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, appMusicPlayer);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, audioPlaying);
		TITANIUM_ADD_PROPERTY(MediaModule, audioSessionCategory);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, availableCameras);
		TITANIUM_ADD_PROPERTY(MediaModule, availableCameraMediaTypes);
		TITANIUM_ADD_PROPERTY(MediaModule, availablePhotoGalleryMediaTypes);
		TITANIUM_ADD_PROPERTY(MediaModule, availablePhotoMediaTypes);
		TITANIUM_ADD_PROPERTY(MediaModule, averageMicrophonePower);
		TITANIUM_ADD_PROPERTY(MediaModule, cameraFlashMode);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, canRecord);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, currentRoute);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, isCameraSupported);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, peakMicrophonePower);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, systemMusicPlayer);
		TITANIUM_ADD_PROPERTY_READONLY(MediaModule, volume);

		TITANIUM_ADD_FUNCTION(MediaModule, beep);
		TITANIUM_ADD_FUNCTION(MediaModule, hideCamera);
		TITANIUM_ADD_FUNCTION(MediaModule, hideMusicLibrary);
		TITANIUM_ADD_FUNCTION(MediaModule, isMediaTypeSupported);
		TITANIUM_ADD_FUNCTION(MediaModule, openMusicLibrary);
		TITANIUM_ADD_FUNCTION(MediaModule, openPhotoGallery);
		TITANIUM_ADD_FUNCTION(MediaModule, previewImage);
		TITANIUM_ADD_FUNCTION(MediaModule, saveToPhotoGallery);
		TITANIUM_ADD_FUNCTION(MediaModule, setOverrideAudioRoute);
		TITANIUM_ADD_FUNCTION(MediaModule, showCamera);
		TITANIUM_ADD_FUNCTION(MediaModule, queryMusicLibrary);
		TITANIUM_ADD_FUNCTION(MediaModule, startMicrophoneMonitor);
		TITANIUM_ADD_FUNCTION(MediaModule, stopMicrophoneMonitor);
		TITANIUM_ADD_FUNCTION(MediaModule, takePicture);
		TITANIUM_ADD_FUNCTION(MediaModule, startVideoCapture);
		TITANIUM_ADD_FUNCTION(MediaModule, stopVideoCapture);
		TITANIUM_ADD_FUNCTION(MediaModule, switchCamera);
		TITANIUM_ADD_FUNCTION(MediaModule, takeScreenshot);
		TITANIUM_ADD_FUNCTION(MediaModule, vibrate);
		TITANIUM_ADD_FUNCTION(MediaModule, requestAuthorization);
		TITANIUM_ADD_FUNCTION(MediaModule, createAudioPlayer);
		TITANIUM_ADD_FUNCTION(MediaModule, createAudioRecorder);
		TITANIUM_ADD_FUNCTION(MediaModule, getAppMusicPlayer);
		TITANIUM_ADD_FUNCTION(MediaModule, getAudioPlaying);
		TITANIUM_ADD_FUNCTION(MediaModule, getAudioSessionCategory);
		TITANIUM_ADD_FUNCTION(MediaModule, setAudioSessionCategory);
		TITANIUM_ADD_FUNCTION(MediaModule, getAvailableCameras);
		TITANIUM_ADD_FUNCTION(MediaModule, getAvailableCameraMediaTypes);
		TITANIUM_ADD_FUNCTION(MediaModule, setAvailableCameraMediaTypes);
		TITANIUM_ADD_FUNCTION(MediaModule, getAvailablePhotoGalleryMediaTypes);
		TITANIUM_ADD_FUNCTION(MediaModule, setAvailablePhotoGalleryMediaTypes);
		TITANIUM_ADD_FUNCTION(MediaModule, getAvailablePhotoMediaTypes);
		TITANIUM_ADD_FUNCTION(MediaModule, setAvailablePhotoMediaTypes);
		TITANIUM_ADD_FUNCTION(MediaModule, getAverageMicrophonePower);
		TITANIUM_ADD_FUNCTION(MediaModule, setAverageMicrophonePower);
		TITANIUM_ADD_FUNCTION(MediaModule, getCameraFlashMode);
		TITANIUM_ADD_FUNCTION(MediaModule, setCameraFlashMode);
		TITANIUM_ADD_FUNCTION(MediaModule, getCanRecord);
		TITANIUM_ADD_FUNCTION(MediaModule, getCurrentRoute);
		TITANIUM_ADD_FUNCTION(MediaModule, getIsCameraSupported);
		TITANIUM_ADD_FUNCTION(MediaModule, getPeakMicrophonePower);
		TITANIUM_ADD_FUNCTION(MediaModule, getSystemMusicPlayer);
		TITANIUM_ADD_FUNCTION(MediaModule, getVolume);
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_FILEFORMAT_3GP2)
	{
		return audio_fileformat_3gp2__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_FILEFORMAT_3GPP)
	{
		return audio_fileformat_3gpp__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_FILEFORMAT_AIFF)
	{
		return audio_fileformat_aiff__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_FILEFORMAT_AMR)
	{
		return audio_fileformat_amr__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_FILEFORMAT_CAF)
	{
		return audio_fileformat_caf__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_FILEFORMAT_MP3)
	{
		return audio_fileformat_mp3__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_FILEFORMAT_MP4)
	{
		return audio_fileformat_mp4__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_FILEFORMAT_MP4A)
	{
		return audio_fileformat_mp4a__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_FILEFORMAT_WAVE)
	{
		return audio_fileformat_wave__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_FORMAT_AAC)
	{
		return audio_format_aac__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_FORMAT_ALAW)
	{
		return audio_format_alaw__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_FORMAT_APPLE_LOSSLESS)
	{
		return audio_format_apple_lossless__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_FORMAT_ILBC)
	{
		return audio_format_ilbc__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_FORMAT_IMA4)
	{
		return audio_format_ima4__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_FORMAT_LINEAR_PCM)
	{
		return audio_format_linear_pcm__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_FORMAT_ULAW)
	{
		return audio_format_ulaw__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_SESSION_CATEGORY_AMBIENT)
	{
		return audio_session_category_ambient__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_SESSION_CATEGORY_PLAYBACK)
	{
		return audio_session_category_playback__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_SESSION_CATEGORY_PLAY_AND_RECORD)
	{
		return audio_session_category_play_and_record__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_SESSION_CATEGORY_RECORD)
	{
		return audio_session_category_record__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_SESSION_CATEGORY_SOLO_AMBIENT)
	{
		return audio_session_category_solo_ambient__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_SESSION_OVERRIDE_ROUTE_NONE)
	{
		return audio_session_override_route_none__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_SESSION_OVERRIDE_ROUTE_SPEAKER)
	{
		return audio_session_override_route_speaker__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_SESSION_PORT_LINEIN)
	{
		return audio_session_port_linein__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_SESSION_PORT_BUILTINMIC)
	{
		return audio_session_port_builtinmic__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_SESSION_PORT_HEADSETMIC)
	{
		return audio_session_port_headsetmic__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_SESSION_PORT_LINEOUT)
	{
		return audio_session_port_lineout__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_SESSION_PORT_HEADPHONES)
	{
		return audio_session_port_headphones__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_SESSION_PORT_BLUETOOTHA2DP)
	{
		return audio_session_port_bluetootha2dp__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_SESSION_PORT_BUILTINRECEIVER)
	{
		return audio_session_port_builtinreceiver__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_SESSION_PORT_BUILTINSPEAKER)
	{
		return audio_session_port_builtinspeaker__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_SESSION_PORT_HDMI)
	{
		return audio_session_port_hdmi__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_SESSION_PORT_AIRPLAY)
	{
		return audio_session_port_airplay__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_SESSION_PORT_BLUETOOTHHFP)
	{
		return audio_session_port_bluetoothhfp__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_SESSION_PORT_USBAUDIO)
	{
		return audio_session_port_usbaudio__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_SESSION_PORT_BLUETOOTHLE)
	{
		return audio_session_port_bluetoothle__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, AUDIO_SESSION_PORT_CARAUDIO)
	{
		return audio_session_port_caraudio__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, CAMERA_FLASH_AUTO)
	{
		return camera_flash_auto__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, CAMERA_FLASH_OFF)
	{
		return camera_flash_off__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, CAMERA_FLASH_ON)
	{
		return camera_flash_on__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, CAMERA_FRONT)
	{
		return camera_front__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, CAMERA_REAR)
	{
		return camera_rear__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, DEVICE_BUSY)
	{
		return device_busy__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, MEDIA_TYPE_PHOTO)
	{
		return media_type_photo__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, MEDIA_TYPE_VIDEO)
	{
		return media_type_video__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, MUSIC_MEDIA_TYPE_ALL)
	{
		return music_media_type_all__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, MUSIC_MEDIA_TYPE_ANY_AUDIO)
	{
		return music_media_type_any_audio__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, MUSIC_MEDIA_TYPE_AUDIOBOOK)
	{
		return music_media_type_audiobook__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, MUSIC_MEDIA_TYPE_MUSIC)
	{
		return music_media_type_music__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, MUSIC_MEDIA_TYPE_PODCAST)
	{
		return music_media_type_podcast__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, MUSIC_MEDIA_GROUP_TITLE)
	{
		return music_media_group_title__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, MUSIC_MEDIA_GROUP_ALBUM)
	{
		return music_media_group_album__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, MUSIC_MEDIA_GROUP_ARTIST)
	{
		return music_media_group_artist__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, MUSIC_MEDIA_GROUP_ALBUM_ARTIST)
	{
		return music_media_group_album_artist__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, MUSIC_MEDIA_GROUP_COMPOSER)
	{
		return music_media_group_composer__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, MUSIC_MEDIA_GROUP_GENRE)
	{
		return music_media_group_genre__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, MUSIC_MEDIA_GROUP_PLAYLIST)
	{
		return music_media_group_playlist__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, MUSIC_MEDIA_GROUP_PODCAST_TITLE)
	{
		return music_media_group_podcast_title__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, MUSIC_PLAYER_REPEAT_ALL)
	{
		return music_player_repeat_all__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, MUSIC_PLAYER_REPEAT_DEFAULT)
	{
		return music_player_repeat_default__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, MUSIC_PLAYER_REPEAT_NONE)
	{
		return music_player_repeat_none__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, MUSIC_PLAYER_REPEAT_ONE)
	{
		return music_player_repeat_one__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, MUSIC_PLAYER_SHUFFLE_ALBUMS)
	{
		return music_player_shuffle_albums__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, MUSIC_PLAYER_SHUFFLE_DEFAULT)
	{
		return music_player_shuffle_default__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, MUSIC_PLAYER_SHUFFLE_NONE)
	{
		return music_player_shuffle_none__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, MUSIC_PLAYER_SHUFFLE_SONGS)
	{
		return music_player_shuffle_songs__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, MUSIC_PLAYER_STATE_INTERRUPTED)
	{
		return music_player_state_interrupted__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, MUSIC_PLAYER_STATE_PAUSED)
	{
		return music_player_state_paused__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, MUSIC_PLAYER_STATE_PLAYING)
	{
		return music_player_state_playing__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, MUSIC_PLAYER_STATE_SEEK_BACKWARD)
	{
		return music_player_state_seek_backward__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, MUSIC_PLAYER_STATE_SEEK_FORWARD)
	{
		return music_player_state_seek_forward__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, MUSIC_PLAYER_STATE_STOPPED)
	{
		return music_player_state_stopped__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, NO_CAMERA)
	{
		return no_camera__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, NO_VIDEO)
	{
		return no_video__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, QUALITY_HIGH)
	{
		return quality_high__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, QUALITY_LOW)
	{
		return quality_low__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, QUALITY_MEDIUM)
	{
		return quality_medium__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, UNKNOWN_ERROR)
	{
		return unknown_error__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_CONTROL_DEFAULT)
	{
		return video_control_default__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_CONTROL_EMBEDDED)
	{
		return video_control_embedded__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_CONTROL_FULLSCREEN)
	{
		return video_control_fullscreen__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_CONTROL_HIDDEN)
	{
		return video_control_hidden__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_CONTROL_NONE)
	{
		return video_control_none__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_FINISH_REASON_PLAYBACK_ENDED)
	{
		return video_finish_reason_playback_ended__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_FINISH_REASON_PLAYBACK_ERROR)
	{
		return video_finish_reason_playback_error__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_FINISH_REASON_USER_EXITED)
	{
		return video_finish_reason_user_exited__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_LOAD_STATE_PLAYABLE)
	{
		return video_load_state_playable__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_LOAD_STATE_PLAYTHROUGH_OK)
	{
		return video_load_state_playthrough_ok__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_LOAD_STATE_STALLED)
	{
		return video_load_state_stalled__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_LOAD_STATE_UNKNOWN)
	{
		return video_load_state_unknown__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_MEDIA_TYPE_AUDIO)
	{
		return video_media_type_audio__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_MEDIA_TYPE_NONE)
	{
		return video_media_type_none__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_MEDIA_TYPE_VIDEO)
	{
		return video_media_type_video__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_PLAYBACK_STATE_INTERRUPTED)
	{
		return video_playback_state_interrupted__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_PLAYBACK_STATE_PAUSED)
	{
		return video_playback_state_paused__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_PLAYBACK_STATE_PLAYING)
	{
		return video_playback_state_playing__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_PLAYBACK_STATE_SEEKING_BACKWARD)
	{
		return video_playback_state_seeking_backward__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_PLAYBACK_STATE_SEEKING_FORWARD)
	{
		return video_playback_state_seeking_forward__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_PLAYBACK_STATE_STOPPED)
	{
		return video_playback_state_stopped__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_REPEAT_MODE_NONE)
	{
		return video_repeat_mode_none__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_REPEAT_MODE_ONE)
	{
		return video_repeat_mode_one__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_SCALING_ASPECT_FILL)
	{
		return video_scaling_aspect_fill__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_SCALING_ASPECT_FIT)
	{
		return video_scaling_aspect_fit__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_SCALING_MODE_FILL)
	{
		return video_scaling_mode_fill__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_SCALING_NONE)
	{
		return video_scaling_none__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_SOURCE_TYPE_FILE)
	{
		return video_source_type_file__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_SOURCE_TYPE_STREAMING)
	{
		return video_source_type_streaming__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_SOURCE_TYPE_UNKNOWN)
	{
		return video_source_type_unknown__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_TIME_OPTION_EXACT)
	{
		return video_time_option_exact__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_TIME_OPTION_NEAREST_KEYFRAME)
	{
		return video_time_option_nearest_keyframe__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_TIME_OPTION_CLOSEST_SYNC)
	{
		return video_time_option_closest_sync__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_TIME_OPTION_NEXT_SYNC)
	{
		return video_time_option_next_sync__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, VIDEO_TIME_OPTION_PREVIOUS_SYNC)
	{
		return video_time_option_previous_sync__;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, appMusicPlayer)
	{
		return appMusicPlayer__;
	}

	TITANIUM_PROPERTY_GETTER_BOOL(MediaModule, audioPlaying)
	TITANIUM_PROPERTY_GETTER_ENUM(MediaModule, audioSessionCategory)
	TITANIUM_PROPERTY_SETTER_ENUM(MediaModule, audioSessionCategory, Media::AudioSessionCategory)

	TITANIUM_PROPERTY_GETTER(MediaModule, availableCameras)
	{
		const auto ctx = get_context();
		std::vector<JSValue> values;
		for (auto v : availableCameras__) {
			values.push_back(ctx.CreateNumber(static_cast<std::uint32_t>(v)));
		}
		return ctx.CreateArray(values);
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, availableCameraMediaTypes)
	{
		const auto ctx = get_context();
		std::vector<JSValue> values;
		for (auto v : availableCameraMediaTypes__) {
			values.push_back(ctx.CreateNumber(static_cast<std::uint32_t>(v)));
		}
		return ctx.CreateArray(values);
	}

	TITANIUM_PROPERTY_SETTER(MediaModule, availableCameraMediaTypes)
	{
		ENSURE_ARRAY(argument, js_array);

		std::vector<Media::MediaType> types;
		const auto js_types = static_cast<std::vector<JSValue>>(js_array);
		for (const auto v : js_types) {
			types.push_back(static_cast<Media::MediaType>(static_cast<std::uint32_t>(v)));
		}
		set_availableCameraMediaTypes(types);
		return true;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, availablePhotoGalleryMediaTypes)
	{
		const auto ctx = get_context();
		std::vector<JSValue> values;
		for (auto v : availablePhotoGalleryMediaTypes__) {
			values.push_back(ctx.CreateNumber(static_cast<std::uint32_t>(v)));
		}
		return ctx.CreateArray(values);
	}

	TITANIUM_PROPERTY_SETTER(MediaModule, availablePhotoGalleryMediaTypes)
	{
		ENSURE_ARRAY(argument, js_array);

		std::vector<Media::MediaType> types;
		const auto js_types = static_cast<std::vector<JSValue>>(js_array);
		for (const auto v : js_types) {
			types.push_back(static_cast<Media::MediaType>(static_cast<std::uint32_t>(v)));
		}
		set_availablePhotoGalleryMediaTypes(types);
		return true;
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, availablePhotoMediaTypes)
	{
		const auto ctx = get_context();
		std::vector<JSValue> values;
		for (auto v : availablePhotoMediaTypes__) {
			values.push_back(ctx.CreateNumber(static_cast<std::uint32_t>(v)));
		}
		return ctx.CreateArray(values);
	}

	TITANIUM_PROPERTY_SETTER(MediaModule, availablePhotoMediaTypes)
	{
		ENSURE_ARRAY(argument, js_array);

		std::vector<Media::MediaType> types;
		const auto js_types = static_cast<std::vector<JSValue>>(js_array);
		for (const auto v : js_types) {
			types.push_back(static_cast<Media::MediaType>(static_cast<std::uint32_t>(v)));
		}
		set_availablePhotoMediaTypes(types);
		return true;
	}

	TITANIUM_PROPERTY_GETTER_DOUBLE(MediaModule, averageMicrophonePower)
	TITANIUM_PROPERTY_SETTER_DOUBLE(MediaModule, averageMicrophonePower)
	TITANIUM_PROPERTY_GETTER_ENUM(MediaModule, cameraFlashMode)
	TITANIUM_PROPERTY_SETTER_ENUM(MediaModule, cameraFlashMode, Media::CameraOption)
	TITANIUM_PROPERTY_GETTER_BOOL(MediaModule, canRecord)
	TITANIUM_PROPERTY_GETTER_STRUCT(MediaModule, currentRoute, RouteDescription)
	TITANIUM_PROPERTY_GETTER_BOOL(MediaModule, isCameraSupported)
	TITANIUM_PROPERTY_GETTER_DOUBLE(MediaModule, volume)

	TITANIUM_PROPERTY_GETTER(MediaModule, systemMusicPlayer)
	{
		return systemMusicPlayer__;
	}

	TITANIUM_FUNCTION(MediaModule, beep)
	{
		beep();
		return get_context().CreateUndefined();
	}
	
	TITANIUM_FUNCTION(MediaModule, hideCamera)
	{
		hideCamera();
		return get_context().CreateUndefined();
	}
	
	TITANIUM_FUNCTION(MediaModule, hideMusicLibrary)
	{
		hideMusicLibrary();
		return get_context().CreateUndefined();
	}
	
	TITANIUM_FUNCTION(MediaModule, isMediaTypeSupported)
	{
		ENSURE_STRING_AT_INDEX(source, 0);
		ENSURE_STRING_AT_INDEX(type, 1);
		
		isMediaTypeSupported(source, type);
		return get_context().CreateUndefined();
	}

	TITANIUM_FUNCTION(MediaModule, openMusicLibrary)
	{
		ENSURE_OBJECT_AT_INDEX(options, 0);
		
		openMusicLibrary(Media::js_to_MusicLibraryOptionsType(options));
		return get_context().CreateUndefined();
	}

	TITANIUM_FUNCTION(MediaModule, openPhotoGallery)
	{
		ENSURE_OBJECT_AT_INDEX(options, 0);
		
		openPhotoGallery(Media::js_to_PhotoGalleryOptionsType(options));
		return get_context().CreateUndefined();
	}

	TITANIUM_PROPERTY_GETTER(MediaModule, peakMicrophonePower)
	{
		return get_context().CreateNumber(get_peakMicrophonePower());
	}

	TITANIUM_FUNCTION(MediaModule, previewImage)
	{
		ENSURE_OBJECT_AT_INDEX(js_options, 0);
		
		std::unordered_map<std::string, Media::PreviewImageOptions> options;
		
		for (const auto& name : static_cast<std::vector<JSString>>(js_options.GetPropertyNames())) {
			options.emplace(name, Media::js_to_PreviewImageOptions(static_cast<JSObject>(js_options.GetProperty(name))));
		}
		
		previewImage(options);
		return get_context().CreateUndefined();
	}

	TITANIUM_FUNCTION(MediaModule, saveToPhotoGallery)
	{
		ENSURE_OBJECT_AT_INDEX(media, 0);
		ENSURE_OBJECT_AT_INDEX(callbacks, 1);
		
		saveToPhotoGallery(media.GetPrivate<Titanium::Filesystem::File>(), callbacks);
		return get_context().CreateUndefined();
	}

	TITANIUM_FUNCTION(MediaModule, setOverrideAudioRoute)
	{
		ENSURE_UINT_AT_INDEX(route, 0);
		
		setOverrideAudioRoute(static_cast<Media::AudioSessionOverrideRoute>(route));
		return get_context().CreateUndefined();
	}

	TITANIUM_FUNCTION(MediaModule, showCamera)
	{
		ENSURE_OBJECT_AT_INDEX(options, 0);
		showCamera(Media::js_to_CameraOptionsType(options));
		return get_context().CreateUndefined();
	}

	TITANIUM_FUNCTION(MediaModule, queryMusicLibrary)
	{
		ENSURE_OBJECT_AT_INDEX(query, 0);
		
		std::vector<JSValue> js_results;
		const auto results = queryMusicLibrary(Media::js_to_MediaQueryType(query));
		for (const auto result : results) {
			js_results.push_back(result->get_object());
		}
		return get_context().CreateArray(js_results);
	}

	TITANIUM_FUNCTION(MediaModule, startMicrophoneMonitor)
	{
		startMicrophoneMonitor();
		return get_context().CreateUndefined();
	}
	
	TITANIUM_FUNCTION(MediaModule, stopMicrophoneMonitor)
	{
		stopMicrophoneMonitor();
		return get_context().CreateUndefined();
	}
	
	TITANIUM_FUNCTION(MediaModule, takePicture)
	{
		takePicture();
		return get_context().CreateUndefined();
	}
	
	TITANIUM_FUNCTION(MediaModule, startVideoCapture)
	{
		startVideoCapture();
		return get_context().CreateUndefined();
	}
	
	TITANIUM_FUNCTION(MediaModule, stopVideoCapture)
	{
		stopVideoCapture();
		return get_context().CreateUndefined();
	}
	
	TITANIUM_FUNCTION(MediaModule, switchCamera)
	{
		ENSURE_UINT_AT_INDEX(camera, 0);
		switchCamera(static_cast<Media::CameraOption>(camera));
		return get_context().CreateUndefined();
	}

	TITANIUM_FUNCTION(MediaModule, takeScreenshot)
	{
		ENSURE_OPTIONAL_OBJECT_AT_INDEX(callback, 0);
		takeScreenshot(callback);
		return get_context().CreateUndefined();
	}

	TITANIUM_FUNCTION(MediaModule, vibrate)
	{
		ENSURE_ARRAY_AT_INDEX(js_pattern, 0);
		const auto js_pattern_array = static_cast<std::vector<JSValue>>(js_pattern);
		std::vector<std::chrono::milliseconds> patterns;
		for (const auto v : js_pattern_array) {
			patterns.push_back(std::chrono::seconds(static_cast<std::chrono::seconds::rep>(static_cast<std::uint32_t>(v))));
		}
		vibrate(patterns);
		return get_context().CreateUndefined();
	}

	TITANIUM_FUNCTION(MediaModule, requestAuthorization)
	{
		ENSURE_OBJECT_AT_INDEX(callback, 0);
		requestAuthorization(callback);
		return get_context().CreateUndefined();
	}

	TITANIUM_FUNCTION(MediaModule, createAudioPlayer)
	{
		ENSURE_OPTIONAL_OBJECT_AT_INDEX(parameters, 0);
		
		JSValue Titanium_property = get_context().get_global_object().GetProperty("Titanium");
		TITANIUM_ASSERT(Titanium_property.IsObject());  // precondition
		JSObject Titanium = static_cast<JSObject>(Titanium_property);
		
		JSValue Audio_property = Titanium.GetProperty("Audio");
		TITANIUM_ASSERT(Audio_property.IsObject());  // precondition
		JSObject Audio = static_cast<JSObject>(Audio_property);
		
		JSValue Player_property = Audio.GetProperty("AudioPlayer");
		TITANIUM_ASSERT(Player_property.IsObject());  // precondition
		JSObject Player = static_cast<JSObject>(Player_property);
		
		auto player = Player.CallAsConstructor();
		applyProperties(parameters, player);
		return player;
	}

	TITANIUM_FUNCTION(MediaModule, createAudioRecorder)
	{
		ENSURE_OPTIONAL_OBJECT_AT_INDEX(parameters, 0);
		
		JSValue Titanium_property = get_context().get_global_object().GetProperty("Titanium");
		TITANIUM_ASSERT(Titanium_property.IsObject());  // precondition
		JSObject Titanium = static_cast<JSObject>(Titanium_property);
		
		JSValue Audio_property = Titanium.GetProperty("Audio");
		TITANIUM_ASSERT(Audio_property.IsObject());  // precondition
		JSObject Audio = static_cast<JSObject>(Audio_property);
		
		JSValue Recorder_property = Audio.GetProperty("AudioRecorder");
		TITANIUM_ASSERT(Recorder_property.IsObject());  // precondition
		JSObject Recorder = static_cast<JSObject>(Recorder_property);
		
		auto recorder = Recorder.CallAsConstructor();
		applyProperties(parameters, recorder);
		return recorder;
	}

	TITANIUM_FUNCTION_AS_GETTER(MediaModule, getAppMusicPlayer, appMusicPlayer)
	TITANIUM_FUNCTION_AS_GETTER(MediaModule, getAudioPlaying, audioPlaying)
	TITANIUM_FUNCTION_AS_GETTER(MediaModule, getAudioSessionCategory, audioSessionCategory)
	TITANIUM_FUNCTION_AS_SETTER(MediaModule, setAudioSessionCategory, audioSessionCategory)
	TITANIUM_FUNCTION_AS_GETTER(MediaModule, getAvailableCameras, availableCameras)
	TITANIUM_FUNCTION_AS_GETTER(MediaModule, getAvailableCameraMediaTypes, availableCameraMediaTypes)
	TITANIUM_FUNCTION_AS_SETTER(MediaModule, setAvailableCameraMediaTypes, availableCameraMediaTypes)
	TITANIUM_FUNCTION_AS_GETTER(MediaModule, getAvailablePhotoGalleryMediaTypes, availablePhotoGalleryMediaTypes)
	TITANIUM_FUNCTION_AS_SETTER(MediaModule, setAvailablePhotoGalleryMediaTypes, availablePhotoGalleryMediaTypes)
	TITANIUM_FUNCTION_AS_GETTER(MediaModule, getAvailablePhotoMediaTypes, availablePhotoMediaTypes)
	TITANIUM_FUNCTION_AS_SETTER(MediaModule, setAvailablePhotoMediaTypes, availablePhotoMediaTypes)
	TITANIUM_FUNCTION_AS_GETTER(MediaModule, getAverageMicrophonePower, averageMicrophonePower)
	TITANIUM_FUNCTION_AS_SETTER(MediaModule, setAverageMicrophonePower, averageMicrophonePower)
	TITANIUM_FUNCTION_AS_GETTER(MediaModule, getCameraFlashMode, cameraFlashMode)
	TITANIUM_FUNCTION_AS_SETTER(MediaModule, setCameraFlashMode, cameraFlashMode)
	TITANIUM_FUNCTION_AS_GETTER(MediaModule, getCanRecord, canRecord)
	TITANIUM_FUNCTION_AS_GETTER(MediaModule, getCurrentRoute, currentRoute)
	TITANIUM_FUNCTION_AS_GETTER(MediaModule, getIsCameraSupported, isCameraSupported)
	TITANIUM_FUNCTION_AS_GETTER(MediaModule, getPeakMicrophonePower, peakMicrophonePower)
	TITANIUM_FUNCTION_AS_GETTER(MediaModule, getSystemMusicPlayer, systemMusicPlayer)
	TITANIUM_FUNCTION_AS_GETTER(MediaModule, getVolume, volume)

} // namespace Titanium