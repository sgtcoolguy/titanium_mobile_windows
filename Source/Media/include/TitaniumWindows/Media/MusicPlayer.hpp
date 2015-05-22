/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_MEDIA_MUSICPLAYER_HPP_
#define _TITANIUMWINDOWS_MEDIA_MUSICPLAYER_HPP_

#include "TitaniumWindows_Media_EXPORT.h"
#include "Titanium/Media/MusicPlayer.hpp"

namespace TitaniumWindows
{
	using namespace HAL;

	namespace Media
	{
		/*!
	      @class

	      @discussion This is the Titanium.Media.MusicPlayer implementation for Windows.
	    */
		class TITANIUMWINDOWS_MEDIA_EXPORT MusicPlayer final : public Titanium::Media::MusicPlayer, public JSExport<MusicPlayer>
		{
		public:
			MusicPlayer(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~MusicPlayer();
			MusicPlayer(const MusicPlayer&) = default;
			MusicPlayer& operator=(const MusicPlayer&) = default;
	#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			MusicPlayer(MusicPlayer&&) = default;
			MusicPlayer& operator=(MusicPlayer&&) = default;
	#endif

			static void JSExportInitialize();

			virtual void enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT override final;
			virtual void disableEvent(const std::string& event_name) TITANIUM_NOEXCEPT override final;

		protected:
		};

	} // namespace Media
} // namespace TitaniumWindows

#endif  // _TITANIUMWINDOWS_MEDIA_MUSICPLAYER_HPP_
