/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_MEDIA_AUDIORECORDER_HPP_
#define _TITANIUMWINDOWS_MEDIA_AUDIORECORDER_HPP_

#include "TitaniumWindows_Media_EXPORT.h"
#include "Titanium/Media/AudioRecorder.hpp"
#include <agile.h>

namespace TitaniumWindows
{
	using namespace HAL;

	namespace Media
	{
		/*!
		  @class AudioRecorder
		  @ingroup Titanium.Media.AudioRecorder

		  @discussion This is the Titanium.Media.AudioRecorder implementation for Windows.
		*/
		class TITANIUMWINDOWS_MEDIA_EXPORT AudioRecorder final : public Titanium::Media::AudioRecorder, public JSExport<AudioRecorder>
		{
		public:
			TITANIUM_PROPERTY_UNIMPLEMENTED(compression);

			AudioRecorder(const JSContext&) TITANIUM_NOEXCEPT;
			virtual ~AudioRecorder();
			AudioRecorder(const AudioRecorder&) = default;
			AudioRecorder& operator=(const AudioRecorder&) = default;
	#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			AudioRecorder(AudioRecorder&&) = default;
			AudioRecorder& operator=(AudioRecorder&&) = default;
	#endif

			static void JSExportInitialize();

			/*!
			  @property
			  @abstract format
			  @discussion Audio format to be used for the recording.
			*/
			virtual void set_format(const Titanium::Media::AudioFileFormat& format) TITANIUM_NOEXCEPT override;

			/*!
			  @method
			  @abstract start
			  @discussion Starts an audio recording.
			*/
			virtual void start() TITANIUM_NOEXCEPT override;

			/*!
			  @method
			  @abstract stop
			  @discussion Stops the current audio recording and returns the recorded audio file.
			*/
			virtual std::shared_ptr<Titanium::Filesystem::File> stop() TITANIUM_NOEXCEPT override;

			/*!
			  @method
			  @abstract pause
			  @discussion Pauses the current audio recording.
			*/
			virtual void pause() TITANIUM_NOEXCEPT override;

			/*!
			  @method
			  @abstract resume
			  @discussion Resumes a paused recording.
			*/
			virtual void resume() TITANIUM_NOEXCEPT override;

		protected:
#pragma warning(push)
#pragma warning(disable : 4251)
			::Platform::Agile<Windows::Media::Capture::MediaCapture> mediaCapture__;
			Windows::Media::MediaProperties::MediaEncodingProfile^ encodingProfile__;
			Windows::Storage::StorageFile^ recordFile__;
#pragma warning(pop)
		};

	} // namespace Media
} // namespace TitaniumWindows

#endif  // _TITANIUMWINDOWS_MEDIA_AUDIORECORDER_HPP_
