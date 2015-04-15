
/**
 * Windows Native Wrapper for Windows.UI.Xaml.Controls.ToggleSwitch
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_WINDOWS_UI_XAML_CONTROLS_TOGGLESWITCH_HPP_
#define _TITANIUM_WINDOWS_UI_XAML_CONTROLS_TOGGLESWITCH_HPP_

#include "Titanium/Module.hpp"

namespace Windows
{
	namespace UI
	{
		namespace Xaml
		{
			namespace Controls
			{

		using namespace HAL;

		class TITANIUMKIT_EXPORT ToggleSwitch : public Module, public JSExport<ToggleSwitch>
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

			TITANIUM_FUNCTION_DEF(OnToggled);
			TITANIUM_FUNCTION_DEF(OnOnContentChanged);
			TITANIUM_FUNCTION_DEF(OnOffContentChanged);
			TITANIUM_FUNCTION_DEF(OnHeaderChanged);

			ToggleSwitch(const JSContext&, const std::vector<JSValue>& arguments = {}) TITANIUM_NOEXCEPT;

			virtual ~ToggleSwitch() = default;
			ToggleSwitch(const ToggleSwitch&) = default;
			ToggleSwitch& operator=(const ToggleSwitch&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			ToggleSwitch(ToggleSwitch&&)                 = default;
			ToggleSwitch& operator=(ToggleSwitch&&)      = default;
#endif

			static void JSExportInitialize();

			Windows::UI::Xaml::Controls::ToggleSwitch^ unwrap();
			void wrap(Windows::UI::Xaml::Controls::ToggleSwitch^ object);

		private:
			Windows::UI::Xaml::Controls::ToggleSwitch^ wrapped__;
		};

			} // namespace Controls
		} // namespace Xaml
	} // namespace UI
} // namespace Windows
#endif // _TITANIUM_WINDOWS_UI_XAML_CONTROLS_TOGGLESWITCH_HPP_
