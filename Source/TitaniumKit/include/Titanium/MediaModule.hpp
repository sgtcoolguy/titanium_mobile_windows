/**
 * TitaniumKit Titanium.Media
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MEDIA_HPP_
#define _TITANIUM_MEDIA_HPP_

#include "Titanium/Module.hpp"
#include "Titanium/Media/Constants.hpp"
#include "Titanium/Media/Item.hpp"
#include "Titanium/Media/CameraOptionsType.hpp"
#include "Titanium/Media/MediaQueryType.hpp"
#include "Titanium/Media/MusicLibraryOptionsType.hpp"
#include "Titanium/Media/PhotoGalleryOptionsType.hpp"
#include "Titanium/Media/PreviewImageOptions.hpp"
#include "Titanium/Media/RouteDescription.hpp"
#include <unordered_map>
#include <chrono>

namespace Titanium
{
	using namespace HAL;

	/*!
	  @class
	  @discussion This is the Titanium Media Module.
	  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.MediaModule
	*/
	class TITANIUMKIT_EXPORT MediaModule : public Module, public JSExport<MediaModule>
	{

	public:

		/*!
		  @property
		  @abstract audioPlaying
		  @discussion Returns `true` if the device is playing audio.
		*/
		TITANIUM_PROPERTY_IMPL_READONLY_DEF(bool, audioPlaying);

		/*!
		  @property
		  @abstract audioSessionCategory
		  @discussion A constant for the audio session category to be used.
		*/
		TITANIUM_PROPERTY_IMPL_DEF(Media::AudioSessionCategory, audioSessionCategory);

		/*!
		  @property
		  @abstract availableCameras
		  @discussion Array indicating which cameras are available, `CAMERA_FRONT`, `CAMERA_REAR` or both.
		*/
		TITANIUM_PROPERTY_IMPL_READONLY_DEF(std::vector<Media::CameraOption>, availableCameras);

		/*!
		  @property
		  @abstract availableCameraMediaTypes
		  @discussion Array of media type constants supported for the camera.
		*/
		TITANIUM_PROPERTY_IMPL_DEF(std::vector<Media::MediaType>, availableCameraMediaTypes);

		/*!
		  @property
		  @abstract availablePhotoGalleryMediaTypes
		  @discussion Array of media type constants supported for saving to the device's camera roll or saved images album.
		*/
		TITANIUM_PROPERTY_IMPL_DEF(std::vector<Media::MediaType>, availablePhotoGalleryMediaTypes);

		/*!
		  @property
		  @abstract availablePhotoMediaTypes
		  @discussion Array of media type constants supported for the photo library.
		*/
		TITANIUM_PROPERTY_IMPL_DEF(std::vector<Media::MediaType>, availablePhotoMediaTypes);

		/*!
		  @property
		  @abstract averageMicrophonePower
		  @discussion Current average microphone level in dB or -1 if microphone monitoring is disabled.
		*/
		TITANIUM_PROPERTY_IMPL_DEF(double, averageMicrophonePower);

		/*!
		  @property
		  @abstract cameraFlashMode
		  @discussion Determines how the flash is fired when using the device's camera.
		*/
		TITANIUM_PROPERTY_IMPL_DEF(Media::CameraOption, cameraFlashMode);

		/*!
		  @property
		  @abstract canRecord
		  @discussion `true` if the device has a recording input device available.
		*/
		TITANIUM_PROPERTY_IMPL_READONLY_DEF(bool, canRecord);

		/*!
		  @property
		  @abstract currentRoute
		  @discussion Returns a description of the current route, consisting of zero or more input ports and zero or more output ports.
		*/
		TITANIUM_PROPERTY_IMPL_READONLY_DEF(Media::RouteDescription, currentRoute);

		/*!
		  @property
		  @abstract isCameraSupported
		  @discussion `true` if the device has camera support.
		*/
		TITANIUM_PROPERTY_IMPL_READONLY_DEF(bool, isCameraSupported);

		/*!
		  @property
		  @abstract peakMicrophonePower
		  @discussion Current microphone level peak power in dB or -1 if microphone monitoring is disabled.
		*/
		TITANIUM_PROPERTY_IMPL_READONLY_DEF(double, peakMicrophonePower);

		/*!
		  @property
		  @abstract volume
		  @discussion Current volume of the playback device.
		*/
		TITANIUM_PROPERTY_IMPL_READONLY_DEF(double, volume);

		/*!
		  @method
		  @abstract beep
		  @discussion Plays a device beep notification.
		*/
		virtual void beep() TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract hideCamera
		  @discussion Hides the device camera UI.
		*/
		virtual void hideCamera() TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract hideMusicLibrary
		  @discussion Hides the music library.
		*/
		virtual void hideMusicLibrary() TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract isMediaTypeSupported
		  @discussion Returns `true` if the source supports the specified media type.
		*/
		virtual bool isMediaTypeSupported(const std::string& source, const std::string& type) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract openMusicLibrary
		  @discussion Shows the music library and allows the user to select one or more tracks.
		*/
		virtual void openMusicLibrary(const Media::MusicLibraryOptionsType& options) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract openPhotoGallery
		  @discussion Opens the photo gallery image picker.
		*/
		virtual void openPhotoGallery(const Media::PhotoGalleryOptionsType& options) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract previewImage
		  @discussion Displays the given image.
		*/
		virtual void previewImage(const std::unordered_map<std::string, Media::PreviewImageOptions>& options) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract saveToPhotoGallery
		  @discussion Saves media to the device's photo gallery / camera roll.
		*/
		virtual void saveToPhotoGallery(const std::shared_ptr<Titanium::Filesystem::File>& media, JSValue callbacks) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract setOverrideAudioRoute
		  @discussion Overrides the default audio route when using the <Titanium.Media.AUDIO_SESSION_MODE_PLAY_AND_RECORD> session mode.
		*/
		virtual void setOverrideAudioRoute(const Media::AudioSessionOverrideRoute& route) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract showCamera
		  @discussion Shows the camera.
		*/
		virtual void showCamera(const Media::CameraOptionsType& options) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract queryMusicLibrary
		  @discussion Searches the music library for items matching the specified search predicates.
		*/
		virtual std::vector<std::shared_ptr<Media::Item>> queryMusicLibrary(const Media::MediaQueryType& query) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract startMicrophoneMonitor
		  @discussion Starts monitoring the microphone sound level.
		*/
		virtual void startMicrophoneMonitor() TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract stopMicrophoneMonitor
		  @discussion Stops monitoring the microphone sound level.
		*/
		virtual void stopMicrophoneMonitor() TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract takePicture
		  @discussion Uses the device camera to capture a photo.
		*/
		virtual void takePicture() TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract startVideoCapture
		  @discussion Starts video capture using the camera specified.
		*/
		virtual void startVideoCapture() TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract stopVideoCapture
		  @discussion Stops video capture using the camera specified.
		*/
		virtual void stopVideoCapture() TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract switchCamera
		  @discussion Switches between front and rear-facing cameras.
		*/
		virtual void switchCamera(const Media::CameraOption& camera) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract takeScreenshot
		  @discussion Takes a screen shot of the visible UI on the device.
		*/
		virtual void takeScreenshot(JSValue callback) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract vibrate
		  @discussion Makes the device vibrate.
		*/
		virtual void vibrate(std::vector<std::chrono::milliseconds> pattern) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract requestAuthorization
		  @discussion Request the user's permission for audio recording.
		*/
		virtual void requestAuthorization(JSValue callback) TITANIUM_NOEXCEPT;

		MediaModule(const JSContext&) TITANIUM_NOEXCEPT;
		virtual ~MediaModule()                     = default;
		MediaModule(const MediaModule&)            = default;
		MediaModule& operator=(const MediaModule&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
		MediaModule(MediaModule&&)                 = default;
		MediaModule& operator=(MediaModule&&)      = default;
#endif

		static void JSExportInitialize();

		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_FILEFORMAT_3GP2);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_FILEFORMAT_3GPP);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_FILEFORMAT_AIFF);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_FILEFORMAT_AMR);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_FILEFORMAT_CAF);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_FILEFORMAT_MP3);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_FILEFORMAT_MP4);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_FILEFORMAT_MP4A);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_FILEFORMAT_WAVE);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_FORMAT_AAC);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_FORMAT_ALAW);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_FORMAT_APPLE_LOSSLESS);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_FORMAT_ILBC);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_FORMAT_IMA4);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_FORMAT_LINEAR_PCM);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_FORMAT_ULAW);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_SESSION_CATEGORY_AMBIENT);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_SESSION_CATEGORY_PLAYBACK);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_SESSION_CATEGORY_PLAY_AND_RECORD);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_SESSION_CATEGORY_RECORD);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_SESSION_CATEGORY_SOLO_AMBIENT);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_SESSION_OVERRIDE_ROUTE_NONE);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_SESSION_OVERRIDE_ROUTE_SPEAKER);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_SESSION_PORT_LINEIN);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_SESSION_PORT_BUILTINMIC);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_SESSION_PORT_HEADSETMIC);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_SESSION_PORT_LINEOUT);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_SESSION_PORT_HEADPHONES);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_SESSION_PORT_BLUETOOTHA2DP);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_SESSION_PORT_BUILTINRECEIVER);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_SESSION_PORT_BUILTINSPEAKER);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_SESSION_PORT_HDMI);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_SESSION_PORT_AIRPLAY);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_SESSION_PORT_BLUETOOTHHFP);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_SESSION_PORT_USBAUDIO);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_SESSION_PORT_BLUETOOTHLE);
		TITANIUM_PROPERTY_READONLY_DEF(AUDIO_SESSION_PORT_CARAUDIO);
		TITANIUM_PROPERTY_READONLY_DEF(CAMERA_FLASH_AUTO);
		TITANIUM_PROPERTY_READONLY_DEF(CAMERA_FLASH_OFF);
		TITANIUM_PROPERTY_READONLY_DEF(CAMERA_FLASH_ON);
		TITANIUM_PROPERTY_READONLY_DEF(CAMERA_FRONT);
		TITANIUM_PROPERTY_READONLY_DEF(CAMERA_REAR);
		TITANIUM_PROPERTY_READONLY_DEF(DEVICE_BUSY);
		TITANIUM_PROPERTY_READONLY_DEF(MEDIA_TYPE_PHOTO);
		TITANIUM_PROPERTY_READONLY_DEF(MEDIA_TYPE_VIDEO);
		TITANIUM_PROPERTY_READONLY_DEF(MUSIC_MEDIA_TYPE_ALL);
		TITANIUM_PROPERTY_READONLY_DEF(MUSIC_MEDIA_TYPE_ANY_AUDIO);
		TITANIUM_PROPERTY_READONLY_DEF(MUSIC_MEDIA_TYPE_AUDIOBOOK);
		TITANIUM_PROPERTY_READONLY_DEF(MUSIC_MEDIA_TYPE_MUSIC);
		TITANIUM_PROPERTY_READONLY_DEF(MUSIC_MEDIA_TYPE_PODCAST);
		TITANIUM_PROPERTY_READONLY_DEF(MUSIC_MEDIA_GROUP_TITLE);
		TITANIUM_PROPERTY_READONLY_DEF(MUSIC_MEDIA_GROUP_ALBUM);
		TITANIUM_PROPERTY_READONLY_DEF(MUSIC_MEDIA_GROUP_ARTIST);
		TITANIUM_PROPERTY_READONLY_DEF(MUSIC_MEDIA_GROUP_ALBUM_ARTIST);
		TITANIUM_PROPERTY_READONLY_DEF(MUSIC_MEDIA_GROUP_COMPOSER);
		TITANIUM_PROPERTY_READONLY_DEF(MUSIC_MEDIA_GROUP_GENRE);
		TITANIUM_PROPERTY_READONLY_DEF(MUSIC_MEDIA_GROUP_PLAYLIST);
		TITANIUM_PROPERTY_READONLY_DEF(MUSIC_MEDIA_GROUP_PODCAST_TITLE);
		TITANIUM_PROPERTY_READONLY_DEF(MUSIC_PLAYER_REPEAT_ALL);
		TITANIUM_PROPERTY_READONLY_DEF(MUSIC_PLAYER_REPEAT_DEFAULT);
		TITANIUM_PROPERTY_READONLY_DEF(MUSIC_PLAYER_REPEAT_NONE);
		TITANIUM_PROPERTY_READONLY_DEF(MUSIC_PLAYER_REPEAT_ONE);
		TITANIUM_PROPERTY_READONLY_DEF(MUSIC_PLAYER_SHUFFLE_ALBUMS);
		TITANIUM_PROPERTY_READONLY_DEF(MUSIC_PLAYER_SHUFFLE_DEFAULT);
		TITANIUM_PROPERTY_READONLY_DEF(MUSIC_PLAYER_SHUFFLE_NONE);
		TITANIUM_PROPERTY_READONLY_DEF(MUSIC_PLAYER_SHUFFLE_SONGS);
		TITANIUM_PROPERTY_READONLY_DEF(MUSIC_PLAYER_STATE_INTERRUPTED);
		TITANIUM_PROPERTY_READONLY_DEF(MUSIC_PLAYER_STATE_PAUSED);
		TITANIUM_PROPERTY_READONLY_DEF(MUSIC_PLAYER_STATE_PLAYING);
		TITANIUM_PROPERTY_READONLY_DEF(MUSIC_PLAYER_STATE_SEEK_BACKWARD);
		TITANIUM_PROPERTY_READONLY_DEF(MUSIC_PLAYER_STATE_SEEK_FORWARD);
		TITANIUM_PROPERTY_READONLY_DEF(MUSIC_PLAYER_STATE_STOPPED);
		TITANIUM_PROPERTY_READONLY_DEF(NO_CAMERA);
		TITANIUM_PROPERTY_READONLY_DEF(NO_VIDEO);
		TITANIUM_PROPERTY_READONLY_DEF(QUALITY_HIGH);
		TITANIUM_PROPERTY_READONLY_DEF(QUALITY_LOW);
		TITANIUM_PROPERTY_READONLY_DEF(QUALITY_MEDIUM);
		TITANIUM_PROPERTY_READONLY_DEF(UNKNOWN_ERROR);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_CONTROL_DEFAULT);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_CONTROL_EMBEDDED);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_CONTROL_FULLSCREEN);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_CONTROL_HIDDEN);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_CONTROL_NONE);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_FINISH_REASON_PLAYBACK_ENDED);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_FINISH_REASON_PLAYBACK_ERROR);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_FINISH_REASON_USER_EXITED);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_LOAD_STATE_PLAYABLE);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_LOAD_STATE_PLAYTHROUGH_OK);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_LOAD_STATE_STALLED);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_LOAD_STATE_UNKNOWN);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_MEDIA_TYPE_AUDIO);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_MEDIA_TYPE_NONE);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_MEDIA_TYPE_VIDEO);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_PLAYBACK_STATE_INTERRUPTED);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_PLAYBACK_STATE_PAUSED);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_PLAYBACK_STATE_PLAYING);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_PLAYBACK_STATE_SEEKING_BACKWARD);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_PLAYBACK_STATE_SEEKING_FORWARD);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_PLAYBACK_STATE_STOPPED);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_REPEAT_MODE_NONE);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_REPEAT_MODE_ONE);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_SCALING_ASPECT_FILL);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_SCALING_ASPECT_FIT);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_SCALING_MODE_FILL);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_SCALING_NONE);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_SOURCE_TYPE_FILE);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_SOURCE_TYPE_STREAMING);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_SOURCE_TYPE_UNKNOWN);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_TIME_OPTION_EXACT);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_TIME_OPTION_NEAREST_KEYFRAME);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_TIME_OPTION_CLOSEST_SYNC);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_TIME_OPTION_NEXT_SYNC);
		TITANIUM_PROPERTY_READONLY_DEF(VIDEO_TIME_OPTION_PREVIOUS_SYNC);
		TITANIUM_PROPERTY_READONLY_DEF(appMusicPlayer);
		TITANIUM_PROPERTY_READONLY_DEF(audioPlaying);
		TITANIUM_PROPERTY_DEF(audioSessionCategory);
		TITANIUM_PROPERTY_READONLY_DEF(availableCameras);
		TITANIUM_PROPERTY_DEF(availableCameraMediaTypes);
		TITANIUM_PROPERTY_DEF(availablePhotoGalleryMediaTypes);
		TITANIUM_PROPERTY_DEF(availablePhotoMediaTypes);
		TITANIUM_PROPERTY_DEF(averageMicrophonePower);
		TITANIUM_PROPERTY_DEF(cameraFlashMode);
		TITANIUM_PROPERTY_READONLY_DEF(canRecord);
		TITANIUM_PROPERTY_READONLY_DEF(currentRoute);
		TITANIUM_PROPERTY_READONLY_DEF(isCameraSupported);
		TITANIUM_PROPERTY_READONLY_DEF(peakMicrophonePower);
		TITANIUM_PROPERTY_READONLY_DEF(systemMusicPlayer);
		TITANIUM_PROPERTY_READONLY_DEF(volume);

		TITANIUM_FUNCTION_DEF(beep);
		TITANIUM_FUNCTION_DEF(hideCamera);
		TITANIUM_FUNCTION_DEF(hideMusicLibrary);
		TITANIUM_FUNCTION_DEF(isMediaTypeSupported);
		TITANIUM_FUNCTION_DEF(openMusicLibrary);
		TITANIUM_FUNCTION_DEF(openPhotoGallery);
		TITANIUM_FUNCTION_DEF(previewImage);
		TITANIUM_FUNCTION_DEF(saveToPhotoGallery);
		TITANIUM_FUNCTION_DEF(setOverrideAudioRoute);
		TITANIUM_FUNCTION_DEF(showCamera);
		TITANIUM_FUNCTION_DEF(queryMusicLibrary);
		TITANIUM_FUNCTION_DEF(startMicrophoneMonitor);
		TITANIUM_FUNCTION_DEF(stopMicrophoneMonitor);
		TITANIUM_FUNCTION_DEF(takePicture);
		TITANIUM_FUNCTION_DEF(startVideoCapture);
		TITANIUM_FUNCTION_DEF(stopVideoCapture);
		TITANIUM_FUNCTION_DEF(switchCamera);
		TITANIUM_FUNCTION_DEF(takeScreenshot);
		TITANIUM_FUNCTION_DEF(vibrate);
		TITANIUM_FUNCTION_DEF(requestAuthorization);
		TITANIUM_FUNCTION_DEF(createAudioPlayer);
		TITANIUM_FUNCTION_DEF(createAudioRecorder);
		TITANIUM_FUNCTION_DEF(getAppMusicPlayer);
		TITANIUM_FUNCTION_DEF(getAudioPlaying);
		TITANIUM_FUNCTION_DEF(getAudioSessionCategory);
		TITANIUM_FUNCTION_DEF(setAudioSessionCategory);
		TITANIUM_FUNCTION_DEF(getAvailableCameras);
		TITANIUM_FUNCTION_DEF(getAvailableCameraMediaTypes);
		TITANIUM_FUNCTION_DEF(setAvailableCameraMediaTypes);
		TITANIUM_FUNCTION_DEF(getAvailablePhotoGalleryMediaTypes);
		TITANIUM_FUNCTION_DEF(setAvailablePhotoGalleryMediaTypes);
		TITANIUM_FUNCTION_DEF(getAvailablePhotoMediaTypes);
		TITANIUM_FUNCTION_DEF(setAvailablePhotoMediaTypes);
		TITANIUM_FUNCTION_DEF(getAverageMicrophonePower);
		TITANIUM_FUNCTION_DEF(setAverageMicrophonePower);
		TITANIUM_FUNCTION_DEF(getCameraFlashMode);
		TITANIUM_FUNCTION_DEF(setCameraFlashMode);
		TITANIUM_FUNCTION_DEF(getCanRecord);
		TITANIUM_FUNCTION_DEF(getCurrentRoute);
		TITANIUM_FUNCTION_DEF(getIsCameraSupported);
		TITANIUM_FUNCTION_DEF(getPeakMicrophonePower);
		TITANIUM_FUNCTION_DEF(getSystemMusicPlayer);
		TITANIUM_FUNCTION_DEF(getVolume);

	protected:
#pragma warning(push)
#pragma warning(disable : 4251)
		JSValue audio_fileformat_3gp2__;
		JSValue audio_fileformat_3gpp__;
		JSValue audio_fileformat_aiff__;
		JSValue audio_fileformat_amr__;
		JSValue audio_fileformat_caf__;
		JSValue audio_fileformat_mp3__;
		JSValue audio_fileformat_mp4__;
		JSValue audio_fileformat_mp4a__;
		JSValue audio_fileformat_wave__;
		JSValue audio_format_aac__;
		JSValue audio_format_alaw__;
		JSValue audio_format_apple_lossless__;
		JSValue audio_format_ilbc__;
		JSValue audio_format_ima4__;
		JSValue audio_format_linear_pcm__;
		JSValue audio_format_ulaw__;
		JSValue audio_session_category_ambient__;
		JSValue audio_session_category_playback__;
		JSValue audio_session_category_play_and_record__;
		JSValue audio_session_category_record__;
		JSValue audio_session_category_solo_ambient__;
		JSValue audio_session_override_route_none__;
		JSValue audio_session_override_route_speaker__;
		JSValue audio_session_port_linein__;
		JSValue audio_session_port_builtinmic__;
		JSValue audio_session_port_headsetmic__;
		JSValue audio_session_port_lineout__;
		JSValue audio_session_port_headphones__;
		JSValue audio_session_port_bluetootha2dp__;
		JSValue audio_session_port_builtinreceiver__;
		JSValue audio_session_port_builtinspeaker__;
		JSValue audio_session_port_hdmi__;
		JSValue audio_session_port_airplay__;
		JSValue audio_session_port_bluetoothhfp__;
		JSValue audio_session_port_usbaudio__;
		JSValue audio_session_port_bluetoothle__;
		JSValue audio_session_port_caraudio__;
		JSValue camera_flash_auto__;
		JSValue camera_flash_off__;
		JSValue camera_flash_on__;
		JSValue camera_front__;
		JSValue camera_rear__;
		JSValue device_busy__;
		JSValue media_type_photo__;
		JSValue media_type_video__;
		JSValue music_media_type_all__;
		JSValue music_media_type_any_audio__;
		JSValue music_media_type_audiobook__;
		JSValue music_media_type_music__;
		JSValue music_media_type_podcast__;
		JSValue music_media_group_title__;
		JSValue music_media_group_album__;
		JSValue music_media_group_artist__;
		JSValue music_media_group_album_artist__;
		JSValue music_media_group_composer__;
		JSValue music_media_group_genre__;
		JSValue music_media_group_playlist__;
		JSValue music_media_group_podcast_title__;
		JSValue music_player_repeat_all__;
		JSValue music_player_repeat_default__;
		JSValue music_player_repeat_none__;
		JSValue music_player_repeat_one__;
		JSValue music_player_shuffle_albums__;
		JSValue music_player_shuffle_default__;
		JSValue music_player_shuffle_none__;
		JSValue music_player_shuffle_songs__;
		JSValue music_player_state_interrupted__;
		JSValue music_player_state_paused__;
		JSValue music_player_state_playing__;
		JSValue music_player_state_seek_backward__;
		JSValue music_player_state_seek_forward__;
		JSValue music_player_state_stopped__;
		JSValue no_camera__;
		JSValue no_video__;
		JSValue quality_high__;
		JSValue quality_low__;
		JSValue quality_medium__;
		JSValue unknown_error__;
		JSValue video_control_default__;
		JSValue video_control_embedded__;
		JSValue video_control_fullscreen__;
		JSValue video_control_hidden__;
		JSValue video_control_none__;
		JSValue video_finish_reason_playback_ended__;
		JSValue video_finish_reason_playback_error__;
		JSValue video_finish_reason_user_exited__;
		JSValue video_load_state_playable__;
		JSValue video_load_state_playthrough_ok__;
		JSValue video_load_state_stalled__;
		JSValue video_load_state_unknown__;
		JSValue video_media_type_audio__;
		JSValue video_media_type_none__;
		JSValue video_media_type_video__;
		JSValue video_playback_state_interrupted__;
		JSValue video_playback_state_paused__;
		JSValue video_playback_state_playing__;
		JSValue video_playback_state_seeking_backward__;
		JSValue video_playback_state_seeking_forward__;
		JSValue video_playback_state_stopped__;
		JSValue video_repeat_mode_none__;
		JSValue video_repeat_mode_one__;
		JSValue video_scaling_aspect_fill__;
		JSValue video_scaling_aspect_fit__;
		JSValue video_scaling_mode_fill__;
		JSValue video_scaling_none__;
		JSValue video_source_type_file__;
		JSValue video_source_type_streaming__;
		JSValue video_source_type_unknown__;
		JSValue video_time_option_exact__;
		JSValue video_time_option_nearest_keyframe__;
		JSValue video_time_option_closest_sync__;
		JSValue video_time_option_next_sync__;
		JSValue video_time_option_previous_sync__;
		bool audioPlaying__;
		Media::AudioSessionCategory audioSessionCategory__;
		std::vector<Media::CameraOption> availableCameras__;
		std::vector<Media::MediaType> availableCameraMediaTypes__;
		std::vector<Media::MediaType> availablePhotoGalleryMediaTypes__;
		std::vector<Media::MediaType> availablePhotoMediaTypes__;
		double averageMicrophonePower__;
		Media::CameraOption cameraFlashMode__;
		bool canRecord__;
		Media::RouteDescription currentRoute__;
		bool isCameraSupported__;
		double peakMicrophonePower__;
		double volume__;
		JSValue appMusicPlayer__;
		JSValue systemMusicPlayer__;
#pragma warning(pop)
		};

} // namespace Titanium
#endif // _TITANIUM_MEDIA_HPP_