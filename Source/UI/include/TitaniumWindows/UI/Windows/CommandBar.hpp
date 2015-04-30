/**
* Windows.CommandBar
*
* Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/
#ifndef _TITANIUMWINDOWS_WINDOWS_COMMANDBAR_HPP_
#define _TITANIUMWINDOWS_WINDOWS_COMMANDBAR_HPP_

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

			  @discussion This is the Titanium.UI.Windows.CommandBar implementation
			*/
			class TITANIUMWINDOWS_UI_EXPORT CommandBar final : public Titanium::Module, public JSExport<CommandBar>
			{

			public:
				CommandBar(const JSContext&) TITANIUM_NOEXCEPT;

				virtual ~CommandBar()                    = default;
				CommandBar(const CommandBar&)            = default;
				CommandBar& operator=(const CommandBar&) = default;
	#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
				CommandBar(CommandBar&&)                 = default;
				CommandBar& operator=(CommandBar&&)      = default;
	#endif

				TITANIUM_PROPERTY_DEF(items);

				static void JSExportInitialize();

				virtual void postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) override;

				Windows::UI::Xaml::Controls::CommandBar^ getComponent() const TITANIUM_NOEXCEPT
				{
					return commandBar__;
				}

			private:
#pragma warning(push)
#pragma warning(disable : 4251)
				Windows::UI::Xaml::Controls::CommandBar^ commandBar__;
				JSValue items__;
#pragma warning(pop)
			};
		} // namespace WindowsXaml
	}  // namespace UI
}  // namespace TitaniumWindows
#endif // _TITANIUMWINDOWS_WINDOWS_COMMANDBAR_HPP_