/**
 * TitaniumKit RouteDescription
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MEDIA_ROUTEDESCRIPTION_HPP_
#define _TITANIUM_MEDIA_ROUTEDESCRIPTION_HPP_

#include "Titanium/detail/TiBase.hpp"
#include "Titanium/Media/Constants.hpp"

namespace Titanium
{
	namespace Media
	{
		using namespace HAL;

		/*!
		  @struct
		  @discussion An Object describing the current audio route.
		  This is an abstract type. Any object meeting this description can be used where this type is used.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/RouteDescription
		*/
		struct RouteDescription
		{
			std::vector<AudioSessionPort> inputs;
			std::vector<AudioSessionPort> outputs;
		};
		
		TITANIUMKIT_EXPORT RouteDescription js_to_RouteDescription(const JSObject& object);
		TITANIUMKIT_EXPORT JSObject RouteDescription_to_js(const JSContext& js_context, const RouteDescription& config);
		
	} // namespace Media
} // namespace Titanium
#endif // _TITANIUM_MEDIA_ROUTEDESCRIPTION_HPP_
