/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_MEDIA_ITEM_HPP_
#define _TITANIUMWINDOWS_MEDIA_ITEM_HPP_

#include "TitaniumWindows_Media_EXPORT.h"
#include "Titanium/Media/Item.hpp"

namespace TitaniumWindows
{
	using namespace HAL;

	namespace Media
	{
		/*!
	      @class Item
	      @ingroup Titanium.Media.Item

	      @discussion This is the Titanium.Media.Item implementation for Windows.
	    */
		class TITANIUMWINDOWS_MEDIA_EXPORT Item final : public Titanium::Media::Item, public JSExport<Item>
		{
		public:

			TITANIUM_PROPERTY_UNIMPLEMENTED(albumArtist);
			TITANIUM_PROPERTY_UNIMPLEMENTED(albumTitle);
			TITANIUM_PROPERTY_UNIMPLEMENTED(albumTrackCount);
			TITANIUM_PROPERTY_UNIMPLEMENTED(albumTrackNumber);
			TITANIUM_PROPERTY_UNIMPLEMENTED(artist);
			TITANIUM_PROPERTY_UNIMPLEMENTED(artwork);
			TITANIUM_PROPERTY_UNIMPLEMENTED(composer);
			TITANIUM_PROPERTY_UNIMPLEMENTED(discCount);
			TITANIUM_PROPERTY_UNIMPLEMENTED(discNumber);
			TITANIUM_PROPERTY_UNIMPLEMENTED(genre);
			TITANIUM_PROPERTY_UNIMPLEMENTED(isCompilation);
			TITANIUM_PROPERTY_UNIMPLEMENTED(lyrics);
			TITANIUM_PROPERTY_UNIMPLEMENTED(mediaType);
			TITANIUM_PROPERTY_UNIMPLEMENTED(playCount);
			TITANIUM_PROPERTY_UNIMPLEMENTED(playbackDuration);
			TITANIUM_PROPERTY_UNIMPLEMENTED(podcastTitle);
			TITANIUM_PROPERTY_UNIMPLEMENTED(rating);
			TITANIUM_PROPERTY_UNIMPLEMENTED(skipCount);
			TITANIUM_PROPERTY_UNIMPLEMENTED(title);

			Item(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~Item();
			Item(const Item&) = default;
			Item& operator=(const Item&) = default;
	#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			Item(Item&&) = default;
			Item& operator=(Item&&) = default;
	#endif

			static void JSExportInitialize();

			virtual void enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT override final;
			virtual void disableEvent(const std::string& event_name) TITANIUM_NOEXCEPT override final;

		protected:
		};

	} // namespace Media
} // namespace TitaniumWindows

#endif  // _TITANIUMWINDOWS_MEDIA_ITEM_HPP_
