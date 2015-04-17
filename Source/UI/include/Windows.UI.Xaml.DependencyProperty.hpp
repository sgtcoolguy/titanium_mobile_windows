/**
 * Windows Native Wrapper for Windows.UI.Xaml.DependencyProperty
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _WINDOWS_UI_XAML_DEPENDENCYPROPERTY_HPP_
#define _WINDOWS_UI_XAML_DEPENDENCYPROPERTY_HPP_

#include "Titanium/Module.hpp"

namespace Windows
{
	namespace UI
	{
		namespace Xaml
		{


		using namespace HAL;

		class TITANIUMKIT_EXPORT DependencyProperty : public Titanium::Module, public JSExport<DependencyProperty>
		{

		public:
			TITANIUM_PROPERTY_READONLY_DEF(UnsetValue);

			TITANIUM_FUNCTION_DEF(GetMetadata);
			TITANIUM_FUNCTION_DEF(Register);
			TITANIUM_FUNCTION_DEF(RegisterAttached);

			DependencyProperty(const JSContext&, const std::vector<JSValue>& arguments = {}) TITANIUM_NOEXCEPT;

			virtual ~DependencyProperty() = default;
			DependencyProperty(const DependencyProperty&) = default;
			DependencyProperty& operator=(const DependencyProperty&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			DependencyProperty(DependencyProperty&&)                 = default;
			DependencyProperty& operator=(DependencyProperty&&)      = default;
#endif

			static void JSExportInitialize();

			Windows::UI::Xaml::DependencyProperty^ unwrapWindows_UI_Xaml_DependencyProperty();
			void wrap(Windows::UI::Xaml::DependencyProperty^ object);

		protected:
			Windows::UI::Xaml::DependencyProperty^ wrapped__;
		};

		} // namespace Xaml
	} // namespace UI
} // namespace Windows
#endif // _WINDOWS_UI_XAML_DEPENDENCYPROPERTY_HPP_
