/**
 * TitaniumKit ListViewAnimationProperties
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_UI_LISTVIEWANIMATIONPROPERTIES_HPP_
#define _TITANIUM_UI_LISTVIEWANIMATIONPROPERTIES_HPP_

#include "Titanium/detail/TiBase.hpp"

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		/*!
		  @struct
		  @discussion This is the ListViewAnimationProperties.
		  Extend this struct to implement platform-specific properties like animation style.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/ListViewAnimationProperties
		*/
		struct ListViewAnimationProperties
		{
			bool animated {true};
		};
		
		ListViewAnimationProperties js_to_ListViewAnimationProperties(const JSObject& object);
	} // namespace UI
} // namespace Titanium
#endif // _TITANIUM_UI_LISTVIEWANIMATIONPROPERTIES_HPP_
