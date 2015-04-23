/**
 * Windows Native Wrapper for Windows.UI.Xaml.Controls.ControlTemplate
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.Controls.ControlTemplate.hpp"

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

		ControlTemplate::ControlTemplate(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::FrameworkTemplate(js_context)
		{
		}

		void ControlTemplate::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::Controls::ControlTemplate^ ControlTemplate::unwrapWindows_UI_Xaml_Controls_ControlTemplate() const
		{
			return dynamic_cast<::Windows::UI::Xaml::Controls::ControlTemplate^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		::Windows::UI::Xaml::Controls::ControlTemplate^ ControlTemplate::unwrap() const
		{
			return unwrapWindows_UI_Xaml_Controls_ControlTemplate();
		}

		void ControlTemplate::wrap(::Windows::UI::Xaml::Controls::ControlTemplate^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void ControlTemplate::JSExportInitialize()
		{
			JSExport<ControlTemplate>::SetClassVersion(1);
			JSExport<ControlTemplate>::SetParent(JSExport<Windows::UI::Xaml::FrameworkTemplate>::Class());

			TITANIUM_ADD_PROPERTY(ControlTemplate, TargetType);
		}

		TITANIUM_PROPERTY_SETTER(ControlTemplate, TargetType)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(argument);
			auto value = ::Windows::UI::Xaml::Interop::TypeName(NaN0);
			// Assign fields explicitly since we cheated on constructor args
			auto Name = object_value.GetProperty("Name");
			value.Name = static_cast<int32_t>(Name);
			auto Kind = object_value.GetProperty("Kind");
			value.Kind = static_cast<int32_t>(Kind);


			unwrap()->TargetType = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ControlTemplate, TargetType)
		{
			auto value = unwrap()->TargetType;
			auto context = get_context();
			auto result = context.CreateObject();
			result.SetProperty("Name", context.CreateNumber(static_cast<int32_t>(value.Name)));
			result.SetProperty("Kind", context.CreateNumber(static_cast<int32_t>(value.Kind)));

			return result;
		}

				} // namespace Controls
			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
