/**
 * TitaniumKit Font
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_UI_FONT_HPP_
#define _TITANIUM_UI_FONT_HPP_

#include "Titanium/detail/TiBase.hpp"
#include "Titanium/UI/Constants.hpp"

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		/*!
		  @struct
		  @discussion An abstract datatype for specifying a text font.
		  This is an abstract type. Any object meeting this description can be used where this type is used.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/Font
		*/
		struct Font
		{
			std::string fontFamily;
			std::string fontSize;
			FONT_STYLE  fontStyle;
			FONT_WEIGHT fontWeight;
			TEXT_STYLE  textStyle;
		};
		
		Font js_to_Font(const JSObject& object);
		JSObject Font_to_js(const JSContext& js_context, Font font);
		
	} // namespace UI
} // namespace Titanium
#endif // _TITANIUM_UI_FONT_HPP_
