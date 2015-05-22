/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_MEDIA_SOUND_HPP_
#define _TITANIUMWINDOWS_MEDIA_SOUND_HPP_

#include "TitaniumWindows_Media_EXPORT.h"
#include "Titanium/Media/Sound.hpp"

namespace TitaniumWindows
{
	using namespace HAL;

	namespace Media
	{
		/*!
	      @class

	      @discussion This is the Titanium.Media.Sound implementation for Windows.
	    */
		class TITANIUMWINDOWS_MEDIA_EXPORT Sound final : public Titanium::Media::Sound, public JSExport<Sound>
		{
		public:
			Sound(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~Sound();
			Sound(const Sound&) = default;
			Sound& operator=(const Sound&) = default;
	#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			Sound(Sound&&) = default;
			Sound& operator=(Sound&&) = default;
	#endif

			static void JSExportInitialize();

			virtual void enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT override final;
			virtual void disableEvent(const std::string& event_name) TITANIUM_NOEXCEPT override final;

		protected:
		};

	} // namespace Media
} // namespace TitaniumWindows

#endif  // _TITANIUMWINDOWS_MEDIA_SOUND_HPP_
