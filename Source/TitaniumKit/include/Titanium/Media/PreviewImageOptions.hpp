/**
 * TitaniumKit PreviewImageOptions
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MEDIA_PREVIEWIMAGEOPTIONS_HPP_
#define _TITANIUM_MEDIA_PREVIEWIMAGEOPTIONS_HPP_

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
		  See http://docs.appcelerator.com/titanium/latest/#!/api/PreviewImageOptions
		*/
		struct PreviewImageOptions
		{
			JSValue error;
			JSValue success;
		};
		
		PreviewImageOptions js_to_PreviewImageOptions(const JSObject& object);
		JSObject PreviewImageOptions_to_js(const JSContext& js_context, const PreviewImageOptions& config);
		
	} // namespace Media
} // namespace Titanium
#endif // _TITANIUM_MEDIA_PREVIEWIMAGEOPTIONS_HPP_
