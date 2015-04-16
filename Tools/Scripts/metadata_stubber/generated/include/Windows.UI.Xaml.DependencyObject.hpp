/**
 * Windows Native Wrapper for Windows.UI.Xaml.DependencyObject
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _WINDOWS_UI_XAML_DEPENDENCYOBJECT_HPP_
#define _WINDOWS_UI_XAML_DEPENDENCYOBJECT_HPP_

#include "Titanium/Module.hpp"

namespace Windows
{
	namespace UI
	{
		namespace Xaml
		{


		using namespace HAL;

		class TITANIUMKIT_EXPORT DependencyObject : public Titanium::Module, public JSExport<DependencyObject>
		{

		public:
			TITANIUM_PROPERTY_READONLY_DEF(Dispatcher);

			TITANIUM_FUNCTION_DEF(GetValue);
			TITANIUM_FUNCTION_DEF(SetValue);
			TITANIUM_FUNCTION_DEF(ClearValue);
			TITANIUM_FUNCTION_DEF(ReadLocalValue);
			TITANIUM_FUNCTION_DEF(GetAnimationBaseValue);

			DependencyObject(const JSContext&, const std::vector<JSValue>& arguments = {}) TITANIUM_NOEXCEPT;

			virtual ~DependencyObject() = default;
			DependencyObject(const DependencyObject&) = default;
			DependencyObject& operator=(const DependencyObject&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			DependencyObject(DependencyObject&&)                 = default;
			DependencyObject& operator=(DependencyObject&&)      = default;
#endif

			static void JSExportInitialize();

			Windows::UI::Xaml::DependencyObject^ unwrapWindows_UI_Xaml_DependencyObject();
			void wrap(Windows::UI::Xaml::DependencyObject^ object);

		protected:
			Windows::UI::Xaml::DependencyObject^ wrapped__;
		};

		} // namespace Xaml
	} // namespace UI
} // namespace Windows
#endif // _WINDOWS_UI_XAML_DEPENDENCYOBJECT_HPP_
