
/**
 * Windows Native Wrapper for Windows.UI.Xaml.Window
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_WINDOWS_UI_XAML_WINDOW_HPP_
#define _TITANIUM_WINDOWS_UI_XAML_WINDOW_HPP_

#include "Titanium/Module.hpp"

namespace Windows
{
	namespace UI
	{
		namespace Xaml
		{

		using namespace HAL;

		class TITANIUMKIT_EXPORT Window : public Module, public JSExport<Window>
		{

		public:
			TITANIUM_PROPERTY_DEF(Content);
				TITANIUM_PROPERTY_READONLY_DEF(Bounds);
			TITANIUM_PROPERTY_READONLY_DEF(CoreWindow);
			TITANIUM_PROPERTY_READONLY_DEF(Dispatcher);
			TITANIUM_PROPERTY_READONLY_DEF(Visible);
			TITANIUM_PROPERTY_READONLY_DEF(Current);

			TITANIUM_FUNCTION_DEF(Activate);
			TITANIUM_FUNCTION_DEF(Close);

			Window(const JSContext&, const std::vector<JSValue>& arguments = {}) TITANIUM_NOEXCEPT;

			virtual ~Window() = default;
			Window(const Window&) = default;
			Window& operator=(const Window&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			Window(Window&&)                 = default;
			Window& operator=(Window&&)      = default;
#endif

			static void JSExportInitialize();

			Windows::UI::Xaml::Window^ unwrap();
			void wrap(Windows::UI::Xaml::Window^ object);

		private:
			Windows::UI::Xaml::Window^ wrapped__;
		};

		} // namespace Xaml
	} // namespace UI
} // namespace Windows
#endif // _TITANIUM_WINDOWS_UI_XAML_WINDOW_HPP_
