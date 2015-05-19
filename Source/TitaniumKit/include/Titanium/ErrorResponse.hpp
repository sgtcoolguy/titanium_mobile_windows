/**
 * TitaniumKit ErrorResponse
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_UI_ERRORRESPONSE_HPP_
#define _TITANIUM_UI_ERRORRESPONSE_HPP_

#include "Titanium/detail/TiBase.hpp"

namespace Titanium
{
	using namespace HAL;

	/*!
	  @struct
	  @discussion An abstract datatype for specifying a text ErrorResponse.
	  This is an abstract type. Any object meeting this description can be used where this type is used.
	  See http://docs.appcelerator.com/titanium/latest/#!/api/ErrorResponse
	*/
	struct ErrorResponse
	{
		std::int32_t code { 0 };
		std::string error;
		bool success { true };
	};
	
	ErrorResponse js_to_ErrorResponse(const JSObject& object);
	JSObject ErrorResponse_to_js(const JSContext& js_context, const ErrorResponse& ErrorResponse);
	
} // namespace Titanium
#endif // _TITANIUM_UI_ERRORRESPONSE_HPP_
