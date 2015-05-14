/**
 * TitaniumKit MusicLibraryOptionsType
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_NETWORK_MUSICLIBRARYOPTIONSTYPE_HPP_
#define _TITANIUM_NETWORK_MUSICLIBRARYOPTIONSTYPE_HPP_

#include "Titanium/detail/TiBase.hpp"

namespace Titanium
{
	namespace Media
	{
		using namespace HAL;

		/*!
		  @struct
		  @discussion An Object describing the current audio route.
		  This is an abstract type. Any object meeting this description can be used where this type is used.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/MusicLibraryOptionsType
		*/
		struct MusicLibraryOptionsType
		{
			JSValue cancel;
			JSValue error;
			JSValue success;
		};
		
		MusicLibraryOptionsType js_to_MusicLibraryOptionsType(const JSObject& object);
		JSObject MusicLibraryOptionsType_to_js(const JSContext& js_context, const MusicLibraryOptionsType& config);
		
	} // namespace Media
} // namespace Titanium
#endif // _TITANIUM_NETWORK_MUSICLIBRARYOPTIONSTYPE_HPP_
