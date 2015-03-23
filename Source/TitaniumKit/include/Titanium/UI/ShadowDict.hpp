/**
 * TitaniumKit ShadowDict
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_UI_SHADOWDICT_HPP_
#define _TITANIUM_UI_SHADOWDICT_HPP_

#include "Titanium/detail/TiBase.hpp"
#include "Titanium/UI/Dimension.hpp"
#include <vector>

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		/*!
		  @struct
		  @discussion An abstract datatype for specifying a text ShadowDict.
		  This is an abstract type. Any object meeting this description can be used where this type is used.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/ShadowDict
		*/
		struct ShadowDict
		{
			double blurRadius {0};
			std::string color;
			Dimension offset;
		};
		
		ShadowDict js_to_ShadowDict(const JSObject& object);
		JSObject ShadowDict_to_js(const JSContext& js_context, const ShadowDict& shadowDict);
		
	} // namespace UI
} // namespace Titanium
#endif // _TITANIUM_UI_SHADOWDICT_HPP_
