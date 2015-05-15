/**
 * TitaniumKit MediaQueryType
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MEDIA_MEDIAQUERYTYPE_HPP_
#define _TITANIUM_MEDIA_MEDIAQUERYTYPE_HPP_

#include "Titanium/detail/TiBase.hpp"
#include "Titanium/Media/Constants.hpp"
#include "Titanium/Media/MediaQueryInfoType.hpp"

namespace Titanium
{
	namespace Media
	{
		using namespace HAL;

		/*!
		  @struct
		  @discussion An Object describing the current audio route.
		  This is an abstract type. Any object meeting this description can be used where this type is used.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/MediaQueryType
		*/
		struct MediaQueryType
		{
			MediaQueryInfoType albumArtist;
			MediaQueryInfoType albumTitle;
			MediaQueryInfoType artist;
			MediaQueryInfoType composer;
			MediaQueryInfoType genre;
			MusicMediaGroup    grouping;
			MediaQueryInfoType isCompilation;
			MediaQueryInfoType mediaType;
			MediaQueryInfoType title;
		};
		
		MediaQueryType js_to_MediaQueryType(const JSObject& object);
		JSObject MediaQueryType_to_js(const JSContext& js_context, const MediaQueryType& config);
		
	} // namespace Media
} // namespace Titanium
#endif // _TITANIUM_MEDIA_MEDIAQUERYTYPE_HPP_
