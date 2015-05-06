/**
 * Titanium.UI.ScrollableView for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/UI/ScrollableView.hpp"
#include "Titanium/detail/TiBase.hpp"

namespace TitaniumWindows
{
	namespace UI
	{

		ScrollableView::ScrollableView(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::UI::ScrollableView(js_context)
		{
			TITANIUM_LOG_DEBUG("ScrollableView::ctor Initialize");
		}

		void ScrollableView::JSExportInitialize() 
		{
			JSExport<ScrollableView>::SetClassVersion(1);
			JSExport<ScrollableView>::SetParent(JSExport<Titanium::UI::ScrollableView>::Class());
		}

	}  // namespace UI
}  // namespace TitaniumWindows