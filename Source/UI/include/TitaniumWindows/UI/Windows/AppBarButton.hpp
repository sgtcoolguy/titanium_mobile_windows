/**
* Windows.AppBarButton
*
* Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/
#ifndef _TITANIUMWINDOWS_WINDOWS_COMMANDBARBUTTON_HPP_
#define _TITANIUMWINDOWS_WINDOWS_COMMANDBARBUTTON_HPP_

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

			  @discussion This is the Titanium.UI.Windows.AppBarButton implementation
			*/
			class TITANIUMWINDOWS_UI_EXPORT AppBarButton final : public Titanium::Module, public JSExport<AppBarButton>
			{

			public:
				AppBarButton(const JSContext&) TITANIUM_NOEXCEPT;

				virtual ~AppBarButton()                = default;
				AppBarButton(const AppBarButton&)            = default;
				AppBarButton& operator=(const AppBarButton&) = default;
	#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
				AppBarButton(AppBarButton&&)                 = default;
				AppBarButton& operator=(AppBarButton&&)      = default;
	#endif

				TITANIUM_PROPERTY_DEF(icon);
				TITANIUM_PROPERTY_DEF(touchEnabled);

				static void JSExportInitialize();

				virtual void postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) override;
				virtual void enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT override final;
				virtual void disableEvent(const std::string& event_name) TITANIUM_NOEXCEPT override final;

				Windows::UI::Xaml::Controls::AppBarButton^ getComponent() const TITANIUM_NOEXCEPT
				{
					return button__;
				}

			private:
				Windows::UI::Xaml::Controls::AppBarButton^ button__;
				Windows::Foundation::EventRegistrationToken click_event__;
				JSValue icon__;
			};
		} // namespace WindowsXaml
	}  // namespace UI
}  // namespace TitaniumWindows
#endif // _TITANIUMWINDOWS_WINDOWS_COMMANDBARBUTTON_HPP_