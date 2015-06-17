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
#include "Titanium/ErrorResponse.hpp"

namespace Titanium
{
	class Blob;

	namespace Media
	{
		using namespace HAL;

		/*!
		  @struct
		  @discussion Options passed to Titanium.Media.previewImage.
		  This is an abstract type. Any object meeting this description can be used where this type is used.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/PreviewImageOptions
		*/
		struct PreviewImageOptions
		{
			std::shared_ptr<Titanium::Blob> image;
			std::function<void(const ErrorResponse&)> onerror;
			std::function<void()> onsuccess;
			// need to keep these references to prevent from GC
			JSValue error;
			JSValue success;
		};
		
		TITANIUMKIT_EXPORT PreviewImageOptions js_to_PreviewImageOptions(const JSObject& object);
		TITANIUMKIT_EXPORT JSObject PreviewImageOptions_to_js(const JSContext& js_context, const PreviewImageOptions& config);
		
	} // namespace Media
} // namespace Titanium
#endif // _TITANIUM_MEDIA_PREVIEWIMAGEOPTIONS_HPP_
