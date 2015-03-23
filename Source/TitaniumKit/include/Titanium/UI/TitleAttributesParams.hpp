/**
 * TitaniumKit TitleAttributesParams
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_UI_TITLEATTRIBUTESPARAMS_HPP_
#define _TITANIUM_UI_TITLEATTRIBUTESPARAMS_HPP_

#include "Titanium/detail/TiBase.hpp"
#include "Titanium/UI/Font.hpp"
#include "Titanium/UI/ShadowDict.hpp"

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		/*!
		  @struct
		  @discussion An abstract datatype for specifying a text TitleAttributesParams.
		  This is an abstract type. Any object meeting this description can be used where this type is used.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/TitleAttributesParams
		*/
		struct TitleAttributesParams
		{
			std::string  color;
			Font         font;
			ShadowDict   shadow;
		};
		
		TitleAttributesParams js_to_TitleAttributesParams(const JSObject& object);
		JSObject TitleAttributesParams_to_js(const JSContext& js_context, const TitleAttributesParams& params);
		
	} // namespace UI
} // namespace Titanium
#endif // _TITANIUM_UI_TITLEATTRIBUTESPARAMS_HPP_
