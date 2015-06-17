/**
 * TitaniumKit MediaQueryInfoType
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MEDIA_MEDIAQUERYINFOTYPE_HPP_
#define _TITANIUM_MEDIA_MEDIAQUERYINFOTYPE_HPP_

#include "Titanium/detail/TiBase.hpp"

namespace Titanium
{
	namespace Media
	{
		using namespace HAL;

		/*!
		  @struct
		  @discussion A full query descriptor for a filtering predicate.
		  This is an abstract type. Any object meeting this description can be used where this type is used.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/MediaQueryInfoType
		*/
		struct MediaQueryInfoType
		{
			bool exact;
			JSValue value;
		};
		
		TITANIUMKIT_EXPORT MediaQueryInfoType js_to_MediaQueryInfoType(const JSValue& info);
		TITANIUMKIT_EXPORT JSObject MediaQueryInfoType_to_js(const JSContext& js_context, const MediaQueryInfoType& config);
		
	} // namespace Media
} // namespace Titanium
#endif // _TITANIUM_MEDIA_MEDIAQUERYINFOTYPE_HPP_
