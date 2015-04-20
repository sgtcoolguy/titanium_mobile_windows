/**
 * Windows Native Wrapper for Windows.UI.Xaml.Controls.ToggleSwitch
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.DependencyProperty.hpp"
#include "Windows.UI.Xaml.Controls.Primitives.ToggleSwitchTemplateSettings.hpp"
#include "Windows.UI.Xaml.DataTemplate.hpp"
#include "Windows.UI.Xaml.Controls.ToggleSwitch.hpp"

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

		ToggleSwitch::ToggleSwitch(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::Controls::Control(js_context)
		{
		}

		void ToggleSwitch::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
			wrapped__ = ref new ::Windows::UI::Xaml::Controls::ToggleSwitch();
		}

		::Windows::UI::Xaml::Controls::ToggleSwitch^ ToggleSwitch::unwrapWindows_UI_Xaml_Controls_ToggleSwitch() const
		{
			return dynamic_cast<::Windows::UI::Xaml::Controls::ToggleSwitch^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		::Windows::UI::Xaml::Controls::ToggleSwitch^ ToggleSwitch::unwrap() const
		{
			return unwrapWindows_UI_Xaml_Controls_ToggleSwitch();
		}

		void ToggleSwitch::wrap(::Windows::UI::Xaml::Controls::ToggleSwitch^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void ToggleSwitch::JSExportInitialize()
		{
			JSExport<ToggleSwitch>::SetClassVersion(1);
			JSExport<ToggleSwitch>::SetParent(JSExport<Windows::UI::Xaml::Controls::Control>::Class());

			TITANIUM_ADD_PROPERTY(ToggleSwitch, OnContentTemplate);
			TITANIUM_ADD_PROPERTY(ToggleSwitch, OnContent);
			TITANIUM_ADD_PROPERTY(ToggleSwitch, OffContentTemplate);
			TITANIUM_ADD_PROPERTY(ToggleSwitch, OffContent);
			TITANIUM_ADD_PROPERTY(ToggleSwitch, IsOn);
			TITANIUM_ADD_PROPERTY(ToggleSwitch, HeaderTemplate);
			TITANIUM_ADD_PROPERTY(ToggleSwitch, Header);
			TITANIUM_ADD_PROPERTY_READONLY(ToggleSwitch, TemplateSettings);
			TITANIUM_ADD_PROPERTY_READONLY(ToggleSwitch, HeaderProperty);
			TITANIUM_ADD_PROPERTY_READONLY(ToggleSwitch, HeaderTemplateProperty);
			TITANIUM_ADD_PROPERTY_READONLY(ToggleSwitch, IsOnProperty);
			TITANIUM_ADD_PROPERTY_READONLY(ToggleSwitch, OffContentProperty);
			TITANIUM_ADD_PROPERTY_READONLY(ToggleSwitch, OffContentTemplateProperty);
			TITANIUM_ADD_PROPERTY_READONLY(ToggleSwitch, OnContentProperty);
			TITANIUM_ADD_PROPERTY_READONLY(ToggleSwitch, OnContentTemplateProperty);
		}

		TITANIUM_PROPERTY_SETTER(ToggleSwitch, OnContentTemplate)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(argument);
			auto wrapper_value = object_value.GetPrivate<Windows::UI::Xaml::DataTemplate>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_DataTemplate();


			unwrap()->OnContentTemplate = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ToggleSwitch, OnContentTemplate)
		{
			auto value = unwrap()->OnContentTemplate;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DataTemplate>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DataTemplate>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_SETTER(ToggleSwitch, OnContent)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(argument);
			auto wrapper_value = object_value.GetPrivate<Titanium::Module>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapTitanium_Module();


			unwrap()->OnContent = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ToggleSwitch, OnContent)
		{
			auto value = unwrap()->OnContent;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<object>::Class());
			auto result_wrapper = result.GetPrivate<object>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_SETTER(ToggleSwitch, OffContentTemplate)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(argument);
			auto wrapper_value = object_value.GetPrivate<Windows::UI::Xaml::DataTemplate>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_DataTemplate();


			unwrap()->OffContentTemplate = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ToggleSwitch, OffContentTemplate)
		{
			auto value = unwrap()->OffContentTemplate;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DataTemplate>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DataTemplate>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_SETTER(ToggleSwitch, OffContent)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(argument);
			auto wrapper_value = object_value.GetPrivate<Titanium::Module>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapTitanium_Module();


			unwrap()->OffContent = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ToggleSwitch, OffContent)
		{
			auto value = unwrap()->OffContent;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<object>::Class());
			auto result_wrapper = result.GetPrivate<object>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_SETTER(ToggleSwitch, IsOn)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsBoolean(), "Expected boolean");
			auto value = static_cast<bool>(argument);


			unwrap()->IsOn = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ToggleSwitch, IsOn)
		{
			auto value = unwrap()->IsOn;
			auto context = get_context();
 			auto result = context.CreateBoolean(value); 

			return result;
		}

		TITANIUM_PROPERTY_SETTER(ToggleSwitch, HeaderTemplate)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(argument);
			auto wrapper_value = object_value.GetPrivate<Windows::UI::Xaml::DataTemplate>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_DataTemplate();


			unwrap()->HeaderTemplate = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ToggleSwitch, HeaderTemplate)
		{
			auto value = unwrap()->HeaderTemplate;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DataTemplate>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DataTemplate>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_SETTER(ToggleSwitch, Header)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(argument);
			auto wrapper_value = object_value.GetPrivate<Titanium::Module>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapTitanium_Module();


			unwrap()->Header = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ToggleSwitch, Header)
		{
			auto value = unwrap()->Header;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<object>::Class());
			auto result_wrapper = result.GetPrivate<object>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(ToggleSwitch, TemplateSettings)
		{
			auto value = unwrap()->TemplateSettings;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::Controls::Primitives::ToggleSwitchTemplateSettings>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::Controls::Primitives::ToggleSwitchTemplateSettings>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(ToggleSwitch, HeaderProperty)
		{
			auto value = unwrap()->HeaderProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(ToggleSwitch, HeaderTemplateProperty)
		{
			auto value = unwrap()->HeaderTemplateProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(ToggleSwitch, IsOnProperty)
		{
			auto value = unwrap()->IsOnProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(ToggleSwitch, OffContentProperty)
		{
			auto value = unwrap()->OffContentProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(ToggleSwitch, OffContentTemplateProperty)
		{
			auto value = unwrap()->OffContentTemplateProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(ToggleSwitch, OnContentProperty)
		{
			auto value = unwrap()->OnContentProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(ToggleSwitch, OnContentTemplateProperty)
		{
			auto value = unwrap()->OnContentTemplateProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

				} // namespace Controls
			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
