/**
 * Windows Native Wrapper for Windows.UI.Xaml.Controls.ToggleSwitch
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _WINDOWS_UI_XAML_CONTROLS_TOGGLESWITCH_HPP_
#define _WINDOWS_UI_XAML_CONTROLS_TOGGLESWITCH_HPP_

#include "TitaniumWindows/UI/detail/UIBase.hpp"
#include "Windows.UI.Xaml.Controls.Control.hpp"

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

		class TITANIUMWINDOWS_UI_EXPORT ToggleSwitch : public Titanium::Windows::UI::Xaml::Controls::Control, public JSExport<ToggleSwitch>
		{

		public:
			TITANIUM_PROPERTY_DEF(OnContentTemplate);
			TITANIUM_PROPERTY_DEF(OnContent);
			TITANIUM_PROPERTY_DEF(OffContentTemplate);
			TITANIUM_PROPERTY_DEF(OffContent);
			TITANIUM_PROPERTY_DEF(IsOn);
			TITANIUM_PROPERTY_DEF(HeaderTemplate);
			TITANIUM_PROPERTY_DEF(Header);
			TITANIUM_PROPERTY_READONLY_DEF(TemplateSettings);
			TITANIUM_PROPERTY_READONLY_DEF(HeaderProperty);
			TITANIUM_PROPERTY_READONLY_DEF(HeaderTemplateProperty);
			TITANIUM_PROPERTY_READONLY_DEF(IsOnProperty);
			TITANIUM_PROPERTY_READONLY_DEF(OffContentProperty);
			TITANIUM_PROPERTY_READONLY_DEF(OffContentTemplateProperty);
			TITANIUM_PROPERTY_READONLY_DEF(OnContentProperty);
			TITANIUM_PROPERTY_READONLY_DEF(OnContentTemplateProperty);


			ToggleSwitch(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~ToggleSwitch() = default;
			ToggleSwitch(const ToggleSwitch&) = default;
			ToggleSwitch& operator=(const ToggleSwitch&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			ToggleSwitch(ToggleSwitch&&)                 = default;
			ToggleSwitch& operator=(ToggleSwitch&&)      = default;
#endif

			static void JSExportInitialize();

			virtual void postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) override;

			::Windows::UI::Xaml::Controls::ToggleSwitch^ unwrapWindows_UI_Xaml_Controls_ToggleSwitch() const;
			void wrap(::Windows::UI::Xaml::Controls::ToggleSwitch^ object);

		private:
			::Windows::UI::Xaml::Controls::ToggleSwitch^ unwrap() const;

		};

				} // namespace Controls
			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
#endif // _WINDOWS_UI_XAML_CONTROLS_TOGGLESWITCH_HPP_
