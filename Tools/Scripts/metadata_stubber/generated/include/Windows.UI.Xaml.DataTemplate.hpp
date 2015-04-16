/**
 * Windows Native Wrapper for Windows.UI.Xaml.DataTemplate
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _WINDOWS_UI_XAML_DATATEMPLATE_HPP_
#define _WINDOWS_UI_XAML_DATATEMPLATE_HPP_

#include "Windows.UI.Xaml.FrameworkTemplate.hpp"

namespace Windows
{
	namespace UI
	{
		namespace Xaml
		{


		using namespace HAL;

		class TITANIUMKIT_EXPORT DataTemplate : public Windows::UI::Xaml::FrameworkTemplate, public JSExport<DataTemplate>
		{

		public:

			TITANIUM_FUNCTION_DEF(LoadContent);

			DataTemplate(const JSContext&, const std::vector<JSValue>& arguments = {}) TITANIUM_NOEXCEPT;

			virtual ~DataTemplate() = default;
			DataTemplate(const DataTemplate&) = default;
			DataTemplate& operator=(const DataTemplate&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			DataTemplate(DataTemplate&&)                 = default;
			DataTemplate& operator=(DataTemplate&&)      = default;
#endif

			static void JSExportInitialize();

			Windows::UI::Xaml::DataTemplate^ unwrapWindows_UI_Xaml_DataTemplate();
			void wrap(Windows::UI::Xaml::DataTemplate^ object);
		};

		} // namespace Xaml
	} // namespace UI
} // namespace Windows
#endif // _WINDOWS_UI_XAML_DATATEMPLATE_HPP_
