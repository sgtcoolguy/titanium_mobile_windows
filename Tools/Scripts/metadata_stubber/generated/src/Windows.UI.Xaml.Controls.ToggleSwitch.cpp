/**
 * Windows Native Wrapper for Windows.UI.Xaml.Controls.ToggleSwitch
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.Controls.ToggleSwitch.hpp"
 // TODO Include the headers for all the native types we use in here! We'll have to go through type of every method arg, return type, type of every property

namespace Windows
{
	namespace UI
	{
		namespace Xaml
		{
			namespace Controls
			{

		ToggleSwitch::ToggleSwitch(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::Controls::Control(js_context, arguments)
		{
		}

		void ToggleSwitch::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
			wrapped__ = ref new Windows::UI::Xaml::Controls::ToggleSwitch();
		}

		Windows::UI::Xaml::Controls::ToggleSwitch^ ToggleSwitch::unwrapWindows_UI_Xaml_Controls_ToggleSwitch()
		{
			return dynamic_cast<Windows::UI::Xaml::Controls::ToggleSwitch^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		void ToggleSwitch::wrap(Windows::UI::Xaml::Controls::ToggleSwitch^ object)
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
			TITANIUM_ADD_FUNCTION(ToggleSwitch, OnToggled);
			TITANIUM_ADD_FUNCTION(ToggleSwitch, OnOnContentChanged);
			TITANIUM_ADD_FUNCTION(ToggleSwitch, OnOffContentChanged);
			TITANIUM_ADD_FUNCTION(ToggleSwitch, OnHeaderChanged);
		}

		TITANIUM_PROPERTY_SETTER(ToggleSwitch, OnContentTemplate)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<Windows::UI::Xaml::DataTemplate>();
			// FIXME What if the type we want here is some parent class of the actual wrapper class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrapWindows_UI_Xaml_DataTemplate();
			wrapped__->OnContentTemplate = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ToggleSwitch, OnContentTemplate)
		{
			auto value = wrapped__->OnContentTemplate;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DataTemplate>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DataTemplate>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_SETTER(ToggleSwitch, OnContent)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<object>();
			// FIXME What if the type we want here is some parent class of the actual wrapper class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrapobject();
			wrapped__->OnContent = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ToggleSwitch, OnContent)
		{
			auto value = wrapped__->OnContent;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<object>::Class());
			auto native_wrapper = object.GetPrivate<object>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_SETTER(ToggleSwitch, OffContentTemplate)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<Windows::UI::Xaml::DataTemplate>();
			// FIXME What if the type we want here is some parent class of the actual wrapper class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrapWindows_UI_Xaml_DataTemplate();
			wrapped__->OffContentTemplate = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ToggleSwitch, OffContentTemplate)
		{
			auto value = wrapped__->OffContentTemplate;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DataTemplate>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DataTemplate>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_SETTER(ToggleSwitch, OffContent)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<object>();
			// FIXME What if the type we want here is some parent class of the actual wrapper class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrapobject();
			wrapped__->OffContent = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ToggleSwitch, OffContent)
		{
			auto value = wrapped__->OffContent;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<object>::Class());
			auto native_wrapper = object.GetPrivate<object>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_SETTER(ToggleSwitch, IsOn)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsBoolean(), "Expected boolean");
			auto value = static_cast<bool>(argument);
			wrapped__->IsOn = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ToggleSwitch, IsOn)
		{
			auto value = wrapped__->IsOn;
			auto context = get_context();
 			return context.CreateBoolean(value); 
		}

		TITANIUM_PROPERTY_SETTER(ToggleSwitch, HeaderTemplate)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<Windows::UI::Xaml::DataTemplate>();
			// FIXME What if the type we want here is some parent class of the actual wrapper class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrapWindows_UI_Xaml_DataTemplate();
			wrapped__->HeaderTemplate = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ToggleSwitch, HeaderTemplate)
		{
			auto value = wrapped__->HeaderTemplate;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DataTemplate>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DataTemplate>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_SETTER(ToggleSwitch, Header)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<object>();
			// FIXME What if the type we want here is some parent class of the actual wrapper class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrapobject();
			wrapped__->Header = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ToggleSwitch, Header)
		{
			auto value = wrapped__->Header;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<object>::Class());
			auto native_wrapper = object.GetPrivate<object>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(ToggleSwitch, TemplateSettings)
		{
			auto value = wrapped__->TemplateSettings;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::Controls::Primitives::ToggleSwitchTemplateSettings>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::Controls::Primitives::ToggleSwitchTemplateSettings>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(ToggleSwitch, HeaderProperty)
		{
			auto value = wrapped__->HeaderProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(ToggleSwitch, HeaderTemplateProperty)
		{
			auto value = wrapped__->HeaderTemplateProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(ToggleSwitch, IsOnProperty)
		{
			auto value = wrapped__->IsOnProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(ToggleSwitch, OffContentProperty)
		{
			auto value = wrapped__->OffContentProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(ToggleSwitch, OffContentTemplateProperty)
		{
			auto value = wrapped__->OffContentTemplateProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(ToggleSwitch, OnContentProperty)
		{
			auto value = wrapped__->OnContentProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(ToggleSwitch, OnContentTemplateProperty)
		{
			auto value = wrapped__->OnContentTemplateProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_FUNCTION(ToggleSwitch, OnToggled)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->OnToggled();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(ToggleSwitch, OnOnContentChanged)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->OnOnContentChanged();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(ToggleSwitch, OnOffContentChanged)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->OnOffContentChanged();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(ToggleSwitch, OnHeaderChanged)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->OnHeaderChanged();
			return get_context().CreateUndefined(); 
		}

			} // namespace Controls
		} // namespace Xaml
	} // namespace UI
} // namespace Windows
