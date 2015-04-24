/**
* Windows.AppBarSeparator
*
* Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/
#ifndef _TITANIUMWINDOWS_WINDOWS_COMMANDBARSEPARATOR_HPP_
#define _TITANIUMWINDOWS_WINDOWS_COMMANDBARSEPARATOR_HPP_

#include "TitaniumWindows/UI/detail/UIBase.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		// Use WindowsXaml namespace instead of "Windows" because it screws entire namespace in UI...
		namespace WindowsXaml
		{
			using namespace HAL;

			/*!
			  @class

			  @discussion This is the Titanium.UI.Windows.AppBarSeparator implementation
			*/
			class TITANIUMWINDOWS_UI_EXPORT AppBarSeparator final : public Titanium::Module, public JSExport<AppBarSeparator>
			{

			public:
				AppBarSeparator(const JSContext&) TITANIUM_NOEXCEPT;

				virtual ~AppBarSeparator()                = default;
				AppBarSeparator(const AppBarSeparator&)            = default;
				AppBarSeparator& operator=(const AppBarSeparator&) = default;
	#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
				AppBarSeparator(AppBarSeparator&&)                 = default;
				AppBarSeparator& operator=(AppBarSeparator&&)      = default;
	#endif

				static void JSExportInitialize();

				virtual void postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) override;

				Windows::UI::Xaml::Controls::AppBarSeparator^ getComponent() const TITANIUM_NOEXCEPT
				{
					return separator__;
				}

			private:
				Windows::UI::Xaml::Controls::AppBarSeparator^ separator__;

			};
		} // namespace WindowsXaml
	}  // namespace UI
}  // namespace TitaniumWindows
#endif // _TITANIUMWINDOWS_WINDOWS_COMMANDBARSEPARATOR_HPP_