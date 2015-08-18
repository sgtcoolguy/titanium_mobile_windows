/**
 * TitaniumKit ViewInsertOrReplaceParams
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_UI_VIEWINSERTORREPLACEPARAMS_HPP_
#define _TITANIUM_UI_VIEWINSERTORREPLACEPARAMS_HPP_

#include "Titanium/detail/TiBase.hpp"

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		class View;

		/*!
		  @struct
		  @discussion An abstract datatype for View.insertAt and View.replaceAt
		*/
		struct ViewInsertOrReplaceParams
		{
			std::shared_ptr<View> view { nullptr };
			std::uint32_t position { 0 };
		};
		
		TITANIUMKIT_EXPORT ViewInsertOrReplaceParams js_to_ViewInsertOrReplaceParams(const JSObject& object);
		TITANIUMKIT_EXPORT JSObject ViewInsertOrReplaceParams_to_js(const JSContext& js_context, const ViewInsertOrReplaceParams& params);
		
	} // namespace UI
} // namespace Titanium
#endif // _TITANIUM_UI_VIEWINSERTORREPLACEPARAMS_HPP_
