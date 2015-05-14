/**
 * TitaniumKit PhotoGalleryOptionsType
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_NETWORK_PHOTOGALLERYOPTIONSTYPE_HPP_
#define _TITANIUM_NETWORK_PHOTOGALLERYOPTIONSTYPE_HPP_

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
		  See http://docs.appcelerator.com/titanium/latest/#!/api/PhotoGalleryOptionsType
		*/
		struct PhotoGalleryOptionsType
		{
			JSValue cancel;
			JSValue error;
			JSValue success;
		};
		
		PhotoGalleryOptionsType js_to_PhotoGalleryOptionsType(const JSObject& object);
		JSObject PhotoGalleryOptionsType_to_js(const JSContext& js_context, const PhotoGalleryOptionsType& config);
		
	} // namespace Media
} // namespace Titanium
#endif // _TITANIUM_NETWORK_PHOTOGALLERYOPTIONSTYPE_HPP_
