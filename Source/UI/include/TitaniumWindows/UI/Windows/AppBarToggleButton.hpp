/**
* Windows.AppBarToggleButton
*
* Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/
#ifndef _TITANIUMWINDOWS_WINDOWS_COMMANDBARTOGGLEBUTTON_HPP_
#define _TITANIUMWINDOWS_WINDOWS_COMMANDBARTOGGLEBUTTON_HPP_

#include "TitaniumWindows_UI_EXPORT.h"
#include "Titanium/Module.hpp"

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

			  @discussion This is the Titanium.UI.Windows.AppBarToggleButton implementation
			*/
			class TITANIUMWINDOWS_UI_EXPORT AppBarToggleButton final : public Titanium::Module, public JSExport<AppBarToggleButton>
			{

			public:
				AppBarToggleButton(const JSContext&) TITANIUM_NOEXCEPT;

				virtual ~AppBarToggleButton()                = default;
				AppBarToggleButton(const AppBarToggleButton&)            = default;
				AppBarToggleButton& operator=(const AppBarToggleButton&) = default;
	#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
				AppBarToggleButton(AppBarToggleButton&&)                 = default;
				AppBarToggleButton& operator=(AppBarToggleButton&&)      = default;
	#endif
				TITANIUM_PROPERTY_DEF(icon);
				TITANIUM_PROPERTY_DEF(touchEnabled);
				TITANIUM_PROPERTY_DEF(checked);

				static void JSExportInitialize();

				virtual void postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) override;
				virtual void enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT override final;
				virtual void disableEvent(const std::string& event_name) TITANIUM_NOEXCEPT override final;

				Windows::UI::Xaml::Controls::AppBarToggleButton^ getComponent() const TITANIUM_NOEXCEPT
				{
					return button__;
				}

			private:
				Windows::UI::Xaml::Controls::AppBarToggleButton^ button__;
				Windows::Foundation::EventRegistrationToken click_event__;
				JSValue icon__;

			};
		} // namespace WindowsXaml
	}  // namespace UI
}  // namespace TitaniumWindows
#endif // _TITANIUMWINDOWS_WINDOWS_COMMANDBARTOGGLEBUTTON_HPP_