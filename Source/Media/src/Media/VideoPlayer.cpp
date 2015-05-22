/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/Media/VideoPlayer.hpp"

namespace TitaniumWindows
{
	namespace Media
	{
		VideoPlayer::VideoPlayer(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Media::VideoPlayer(js_context)
		{
			TITANIUM_LOG_DEBUG("TitaniumWindows::Media::VideoPlayer::ctor Initialize");
		}

		VideoPlayer::~VideoPlayer()
		{
			TITANIUM_LOG_DEBUG("TitaniumWindows::Media::VideoPlayer::dtor");
		}

		void VideoPlayer::JSExportInitialize()
		{
			JSExport<VideoPlayer>::SetClassVersion(1);
			JSExport<VideoPlayer>::SetParent(JSExport<Titanium::Media::VideoPlayer>::Class());
		}

		void VideoPlayer::enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
		{
			Titanium::Media::VideoPlayer::enableEvent(event_name);
		}

		void VideoPlayer::disableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
		{
			Titanium::Media::VideoPlayer::disableEvent(event_name);
		}
	}
}
