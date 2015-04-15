
/**
 * Windows Native Wrapper for Windows.UI.Xaml.Controls.Canvas
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_WINDOWS_UI_XAML_CONTROLS_CANVAS_HPP_
#define _TITANIUM_WINDOWS_UI_XAML_CONTROLS_CANVAS_HPP_

#include "Titanium/Module.hpp"

namespace Windows
{
	namespace UI
	{
		namespace Xaml
		{
			namespace Controls
			{

		using namespace HAL;

		class TITANIUMKIT_EXPORT Canvas : public Module, public JSExport<Canvas>
		{

		public:
			TITANIUM_PROPERTY_READONLY_DEF(LeftProperty);
			TITANIUM_PROPERTY_READONLY_DEF(TopProperty);
			TITANIUM_PROPERTY_READONLY_DEF(ZIndexProperty);

			TITANIUM_FUNCTION_DEF(GetLeft);
			TITANIUM_FUNCTION_DEF(SetLeft);
			TITANIUM_FUNCTION_DEF(GetTop);
			TITANIUM_FUNCTION_DEF(SetTop);
			TITANIUM_FUNCTION_DEF(GetZIndex);
			TITANIUM_FUNCTION_DEF(SetZIndex);

			Canvas(const JSContext&, const std::vector<JSValue>& arguments = {}) TITANIUM_NOEXCEPT;

			virtual ~Canvas() = default;
			Canvas(const Canvas&) = default;
			Canvas& operator=(const Canvas&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			Canvas(Canvas&&)                 = default;
			Canvas& operator=(Canvas&&)      = default;
#endif

			static void JSExportInitialize();

			Windows::UI::Xaml::Controls::Canvas^ unwrap();
			void wrap(Windows::UI::Xaml::Controls::Canvas^ object);

		private:
			Windows::UI::Xaml::Controls::Canvas^ wrapped__;
		};

			} // namespace Controls
		} // namespace Xaml
	} // namespace UI
} // namespace Windows
#endif // _TITANIUM_WINDOWS_UI_XAML_CONTROLS_CANVAS_HPP_
