/**
 * Windows Native Wrapper for Windows.UI.Xaml.Controls.DataTemplateSelector
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _WINDOWS_UI_XAML_CONTROLS_DATATEMPLATESELECTOR_HPP_
#define _WINDOWS_UI_XAML_CONTROLS_DATATEMPLATESELECTOR_HPP_

#include "TitaniumWindows/UI/detail/UIBase.hpp"
#include "TitaniumWindows/Utility.hpp"
#include "Titanium/Module.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{
				namespace Controls
				{


		using namespace HAL;

		class TITANIUMWINDOWS_UI_EXPORT DataTemplateSelector : public Titanium::Module, public JSExport<DataTemplateSelector>
		{

		public:

			TITANIUM_FUNCTION_DEF(SelectTemplate);

			DataTemplateSelector(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~DataTemplateSelector() = default;
			DataTemplateSelector(const DataTemplateSelector&) = default;
			DataTemplateSelector& operator=(const DataTemplateSelector&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			DataTemplateSelector(DataTemplateSelector&&)                 = default;
			DataTemplateSelector& operator=(DataTemplateSelector&&)      = default;
#endif

			static void JSExportInitialize();

			virtual void postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) override;

			::Windows::UI::Xaml::Controls::DataTemplateSelector^ unwrapWindows_UI_Xaml_Controls_DataTemplateSelector() const;
			void wrap(::Windows::UI::Xaml::Controls::DataTemplateSelector^ object);

		protected:
			::Windows::UI::Xaml::Controls::DataTemplateSelector^ wrapped__;

		private:
			::Windows::UI::Xaml::Controls::DataTemplateSelector^ unwrap() const;

		};

				} // namespace Controls
			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
#endif // _WINDOWS_UI_XAML_CONTROLS_DATATEMPLATESELECTOR_HPP_
