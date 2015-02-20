/**
 * TitaniumKit ListViewMarkerProps
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/ListViewMarkerProps.hpp"

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		ListViewMarkerProps js_to_ListViewMarkerProps(const JSObject& object)
		{
			ListViewMarkerProps props;
			if (object.HasProperty("itemIndex")) {
				props.itemIndex = static_cast<uint32_t>(object.GetProperty("itemIndex"));
			}
			if (object.HasProperty("sectionIndex")) {
				props.sectionIndex = static_cast<uint32_t>(object.GetProperty("sectionIndex"));
			}
			return props;
		};
	} // namespace UI
} // namespace Titanium
