/**
 * Titanium.UI.ScrollableView for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_SCROLLABLEVIEW_HPP_
#define _TITANIUMWINDOWS_SCROLLABLEVIEW_HPP_

#include "TitaniumWindows/UI/detail/UIBase.hpp"
#include "Titanium/UI/ScrollableView.hpp"

namespace TitaniumWindows
{
	namespace UI
	{

		using namespace HAL;

		/*!
		  @class

		  @discussion This is the Titanium.UI.ScrollableView implementation for Windows.
		*/
		class TITANIUMWINDOWS_UI_EXPORT ScrollableView final : public Titanium::UI::ScrollableView, public JSExport<ScrollableView>
		{

		public:
			ScrollableView(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~ScrollableView()                        = default;
			ScrollableView(const ScrollableView&)            = default;
			ScrollableView& operator=(const ScrollableView&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			ScrollableView(ScrollableView&&)                 = default;
			ScrollableView& operator=(ScrollableView&&)      = default;
#endif

			static void JSExportInitialize();

		private:

		};
	}  // namespace UI
}  // namespace TitaniumWindows
#endif // _TITANIUMWINDOWS_SCROLLABLEVIEW_HPP_