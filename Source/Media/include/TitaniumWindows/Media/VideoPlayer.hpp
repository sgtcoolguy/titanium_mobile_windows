/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_MEDIA_AUDIOPLAYER_HPP_
#define _TITANIUMWINDOWS_MEDIA_AUDIOPLAYER_HPP_

#include "TitaniumWindows_Media_EXPORT.h"
#include "Titanium/Media/VideoPlayer.hpp"

namespace TitaniumWindows
{
	using namespace HAL;

	namespace Media
	{
		/*!
	      @class

	      @discussion This is the Titanium.Media.VideoPlayer implementation for Windows.
	    */
		class TITANIUMWINDOWS_MEDIA_EXPORT VideoPlayer final : public Titanium::Media::VideoPlayer, public JSExport<VideoPlayer>
		{
		public:
			VideoPlayer(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~VideoPlayer();
			VideoPlayer(const VideoPlayer&) = default;
			VideoPlayer& operator=(const VideoPlayer&) = default;
	#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			VideoPlayer(VideoPlayer&&) = default;
			VideoPlayer& operator=(VideoPlayer&&) = default;
	#endif

			static void JSExportInitialize();

			virtual void enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT override final;
			virtual void disableEvent(const std::string& event_name) TITANIUM_NOEXCEPT override final;

		protected:
		};

	} // namespace Media
} // namespace TitaniumWindows

#endif  // _TITANIUMWINDOWS_MEDIA_AUDIOPLAYER_HPP_
