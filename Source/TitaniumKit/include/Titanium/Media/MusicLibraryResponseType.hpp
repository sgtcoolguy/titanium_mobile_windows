/**
 * TitaniumKit MusicLibraryResponseType
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MEDIA_MUSICLIBRARYRESPONSETYPE_HPP_
#define _TITANIUM_MEDIA_MUSICLIBRARYRESPONSETYPE_HPP_

#include "Titanium/detail/TiBase.hpp"
#include "Titanium/Media/Constants.hpp"
#include <vector>
#include <unordered_set>

namespace Titanium
{
	namespace Media
	{
		using namespace HAL;

		class Item;
		
		/*!
		  @struct
		  @discussion Simple object passed to the openMusicLibrary success callback function.
		  This is an abstract type. Any object meeting this description can be used where this type is used.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/MusicLibraryResponseType
		*/
		struct MusicLibraryResponseType
		{
			std::vector<std::shared_ptr<Item>> items;
			std::vector<std::shared_ptr<Item>> representative;
			std::unordered_set<MusicMediaType> types;
		};
		
		MusicLibraryResponseType js_to_MusicLibraryResponseType(const JSObject& object);
		JSObject MusicLibraryResponseType_to_js(const JSContext& js_context, const MusicLibraryResponseType& config);
		
	} // namespace Media
} // namespace Titanium
#endif // _TITANIUM_MEDIA_MUSICLIBRARYRESPONSETYPE_HPP_
