/**
 * TitaniumKit MusicLibraryOptionsType
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MEDIA_MUSICLIBRARYOPTIONSTYPE_HPP_
#define _TITANIUM_MEDIA_MUSICLIBRARYOPTIONSTYPE_HPP_

#include "Titanium/detail/TiBase.hpp"
#include "Titanium/ErrorResponse.hpp"
#include "Titanium/Media/Constants.hpp"
#include "Titanium/Media/MusicLibraryResponseType.hpp"

namespace Titanium
{
	namespace Media
	{
		using namespace HAL;

		struct MusicLibraryOptionsTypeCallbacks 
		{
			// need to keep these references to prevent from GC
			JSValue cancel;
			JSValue error;
			JSValue success;
			std::function<void(const ErrorResponse&)> oncancel;
			std::function<void(const ErrorResponse&)> onerror;
			std::function<void(const MusicLibraryResponseType&)> onsuccess;
		};

		/*!
		  @struct
		  @discussion Simple object for specifying options to openMusicLibrary.
		  This is an abstract type. Any object meeting this description can be used where this type is used.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/MusicLibraryOptionsType
		*/
		struct MusicLibraryOptionsType
		{
			bool allowMultipleSelections;
			bool animated;
			bool autohide;
			std::vector<MusicMediaType> mediaTypes;
			MusicLibraryOptionsTypeCallbacks callbacks;
		};
		
		TITANIUMKIT_EXPORT MusicLibraryOptionsType js_to_MusicLibraryOptionsType(const JSObject& object);
		TITANIUMKIT_EXPORT JSObject MusicLibraryOptionsType_to_js(const JSContext& js_context, const MusicLibraryOptionsType& config);
		TITANIUMKIT_EXPORT MusicLibraryOptionsType create_empty_MusicLibraryOptionsType(const JSContext& js_context);

	} // namespace Media
} // namespace Titanium
#endif // _TITANIUM_MEDIA_MUSICLIBRARYOPTIONSTYPE_HPP_
