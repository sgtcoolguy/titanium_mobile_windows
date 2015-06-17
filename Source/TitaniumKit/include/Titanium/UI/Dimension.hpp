/**
 * TitaniumKit Dimension
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_DIMENSION_HPP_
#define _TITANIUM_DIMENSION_HPP_

#include "Titanium/detail/TiBase.hpp"

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		/*!
		  @struct
		  @discussion An abstract datatype for specifying a dimension.
		  This is an abstract type. Any object meeting this description can be used where this type is used.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/Dimension
		  */
		struct Dimension {
			int32_t x { 0 };
			int32_t y { 0 };
			uint32_t width { 0 };
			uint32_t height { 0 };
		};

		TITANIUMKIT_EXPORT Dimension js_to_Dimension(const JSObject& object);
		TITANIUMKIT_EXPORT JSObject Dimension_to_js(const JSContext& js_context, const Dimension& dimension);
	} // namespace UI
} // namespace Titanium
#endif // _TITANIUM_DIMENSION_HPP_
