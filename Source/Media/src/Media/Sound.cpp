/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/Media/Sound.hpp"
#include "Titanium/detail/TiLogger.hpp"

namespace TitaniumWindows
{
	namespace Media
	{
		Sound::Sound(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Media::Sound(js_context)
		{
			TITANIUM_LOG_DEBUG("TitaniumWindows::Media::Sound::ctor Initialize");
		}

		Sound::~Sound()
		{
			TITANIUM_LOG_DEBUG("TitaniumWindows::Media::Sound::dtor");
		}

		void Sound::JSExportInitialize()
		{
			JSExport<Sound>::SetClassVersion(1);
			JSExport<Sound>::SetParent(JSExport<Titanium::Media::Sound>::Class());
		}

		void Sound::enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
		{
			Titanium::Media::Sound::enableEvent(event_name);
		}

		void Sound::disableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
		{
			Titanium::Media::Sound::disableEvent(event_name);
		}
	}
}
