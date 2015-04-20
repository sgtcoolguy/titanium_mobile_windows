/**
 * Windows Native Wrapper for Windows.UI.Xaml.FrameworkElement
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.Data.BindingExpression.hpp"
#include "Windows.UI.Xaml.DependencyProperty.hpp"
#include "Windows.UI.Xaml.TriggerCollection.hpp"
#include "Windows.UI.Xaml.DependencyObject.hpp"
#include "Windows.Foundation.Uri.hpp"
#include "Windows.UI.Xaml.ResourceDictionary.hpp"
#include "Windows.UI.Xaml.Style.hpp"
#include "Windows.UI.Xaml.FrameworkElement.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{

		FrameworkElement::FrameworkElement(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::UIElement(js_context)
		{
		}

		void FrameworkElement::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
			wrapped__ = ref new ::Windows::UI::Xaml::FrameworkElement();
		}

		::Windows::UI::Xaml::FrameworkElement^ FrameworkElement::unwrapWindows_UI_Xaml_FrameworkElement() const
		{
			return dynamic_cast<::Windows::UI::Xaml::FrameworkElement^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		::Windows::UI::Xaml::FrameworkElement^ FrameworkElement::unwrap() const
		{
			return unwrapWindows_UI_Xaml_FrameworkElement();
		}

		void FrameworkElement::wrap(::Windows::UI::Xaml::FrameworkElement^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void FrameworkElement::JSExportInitialize()
		{
			JSExport<FrameworkElement>::SetClassVersion(1);
			JSExport<FrameworkElement>::SetParent(JSExport<Windows::UI::Xaml::UIElement>::Class());

			TITANIUM_ADD_PROPERTY(FrameworkElement, Language);
			TITANIUM_ADD_PROPERTY(FrameworkElement, HorizontalAlignment);
			TITANIUM_ADD_PROPERTY(FrameworkElement, Height);
			TITANIUM_ADD_PROPERTY(FrameworkElement, MaxWidth);
			TITANIUM_ADD_PROPERTY(FrameworkElement, FlowDirection);
			TITANIUM_ADD_PROPERTY(FrameworkElement, DataContext);
			TITANIUM_ADD_PROPERTY(FrameworkElement, MaxHeight);
			TITANIUM_ADD_PROPERTY(FrameworkElement, Name);
			TITANIUM_ADD_PROPERTY(FrameworkElement, Width);
			TITANIUM_ADD_PROPERTY(FrameworkElement, VerticalAlignment);
			TITANIUM_ADD_PROPERTY(FrameworkElement, Tag);
			TITANIUM_ADD_PROPERTY(FrameworkElement, Style);
			TITANIUM_ADD_PROPERTY(FrameworkElement, Resources);
			TITANIUM_ADD_PROPERTY(FrameworkElement, Margin);
			TITANIUM_ADD_PROPERTY(FrameworkElement, MinWidth);
			TITANIUM_ADD_PROPERTY(FrameworkElement, MinHeight);
			TITANIUM_ADD_PROPERTY_READONLY(FrameworkElement, ActualHeight);
			TITANIUM_ADD_PROPERTY_READONLY(FrameworkElement, ActualWidth);
			TITANIUM_ADD_PROPERTY_READONLY(FrameworkElement, BaseUri);
			TITANIUM_ADD_PROPERTY_READONLY(FrameworkElement, Parent);
			TITANIUM_ADD_PROPERTY_READONLY(FrameworkElement, Triggers);
			TITANIUM_ADD_PROPERTY(FrameworkElement, RequestedTheme);
			TITANIUM_ADD_PROPERTY_READONLY(FrameworkElement, RequestedThemeProperty);
			TITANIUM_ADD_PROPERTY_READONLY(FrameworkElement, ActualHeightProperty);
			TITANIUM_ADD_PROPERTY_READONLY(FrameworkElement, ActualWidthProperty);
			TITANIUM_ADD_PROPERTY_READONLY(FrameworkElement, DataContextProperty);
			TITANIUM_ADD_PROPERTY_READONLY(FrameworkElement, FlowDirectionProperty);
			TITANIUM_ADD_PROPERTY_READONLY(FrameworkElement, HeightProperty);
			TITANIUM_ADD_PROPERTY_READONLY(FrameworkElement, HorizontalAlignmentProperty);
			TITANIUM_ADD_PROPERTY_READONLY(FrameworkElement, LanguageProperty);
			TITANIUM_ADD_PROPERTY_READONLY(FrameworkElement, MarginProperty);
			TITANIUM_ADD_PROPERTY_READONLY(FrameworkElement, MaxHeightProperty);
			TITANIUM_ADD_PROPERTY_READONLY(FrameworkElement, MaxWidthProperty);
			TITANIUM_ADD_PROPERTY_READONLY(FrameworkElement, MinHeightProperty);
			TITANIUM_ADD_PROPERTY_READONLY(FrameworkElement, MinWidthProperty);
			TITANIUM_ADD_PROPERTY_READONLY(FrameworkElement, NameProperty);
			TITANIUM_ADD_PROPERTY_READONLY(FrameworkElement, StyleProperty);
			TITANIUM_ADD_PROPERTY_READONLY(FrameworkElement, TagProperty);
			TITANIUM_ADD_PROPERTY_READONLY(FrameworkElement, VerticalAlignmentProperty);
			TITANIUM_ADD_PROPERTY_READONLY(FrameworkElement, WidthProperty);
			TITANIUM_ADD_FUNCTION(FrameworkElement, FindName);
			TITANIUM_ADD_FUNCTION(FrameworkElement, SetBinding);
			TITANIUM_ADD_FUNCTION(FrameworkElement, GetBindingExpression);
			TITANIUM_ADD_FUNCTION(FrameworkElement, MeasureOverride);
			TITANIUM_ADD_FUNCTION(FrameworkElement, ArrangeOverride);
			TITANIUM_ADD_FUNCTION(FrameworkElement, OnApplyTemplate);
			TITANIUM_ADD_FUNCTION(FrameworkElement, GoToElementStateCore);
		}

		TITANIUM_PROPERTY_SETTER(FrameworkElement, Language)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsString(), "Expected String");
			auto value = static_cast<std::string>(argument);
			unwrap()->Language = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, Language)
		{
			auto value = unwrap()->Language;
			auto context = get_context();
 			return context.CreateString(value);
		}

		TITANIUM_PROPERTY_SETTER(FrameworkElement, HorizontalAlignment)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<::Windows::UI::Xaml::HorizontalAlignment>(static_cast<int32_t>(argument)); // TODO Look up enum in metadata to know what type it's value is? 
			unwrap()->HorizontalAlignment = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, HorizontalAlignment)
		{
			auto value = unwrap()->HorizontalAlignment;
			auto context = get_context();
			return context.CreateNumber(static_cast<int32_t>(static_cast<int>(value))); // FIXME What if the enum isn't an int based one?!
		}

		TITANIUM_PROPERTY_SETTER(FrameworkElement, Height)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<double>(argument);
			unwrap()->Height = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, Height)
		{
			auto value = unwrap()->Height;
			auto context = get_context();
			return context.CreateNumber(static_cast<double>(value));
		}

		TITANIUM_PROPERTY_SETTER(FrameworkElement, MaxWidth)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<double>(argument);
			unwrap()->MaxWidth = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, MaxWidth)
		{
			auto value = unwrap()->MaxWidth;
			auto context = get_context();
			return context.CreateNumber(static_cast<double>(value));
		}

		TITANIUM_PROPERTY_SETTER(FrameworkElement, FlowDirection)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<::Windows::UI::Xaml::FlowDirection>(static_cast<int32_t>(argument)); // TODO Look up enum in metadata to know what type it's value is? 
			unwrap()->FlowDirection = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, FlowDirection)
		{
			auto value = unwrap()->FlowDirection;
			auto context = get_context();
			return context.CreateNumber(static_cast<int32_t>(static_cast<int>(value))); // FIXME What if the enum isn't an int based one?!
		}

		TITANIUM_PROPERTY_SETTER(FrameworkElement, DataContext)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<Titanium::Module>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrapTitanium_Module();
			unwrap()->DataContext = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, DataContext)
		{
			auto value = unwrap()->DataContext;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<object>::Class());
			auto native_wrapper = object.GetPrivate<object>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_SETTER(FrameworkElement, MaxHeight)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<double>(argument);
			unwrap()->MaxHeight = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, MaxHeight)
		{
			auto value = unwrap()->MaxHeight;
			auto context = get_context();
			return context.CreateNumber(static_cast<double>(value));
		}

		TITANIUM_PROPERTY_SETTER(FrameworkElement, Name)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsString(), "Expected String");
			auto value = static_cast<std::string>(argument);
			unwrap()->Name = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, Name)
		{
			auto value = unwrap()->Name;
			auto context = get_context();
 			return context.CreateString(value);
		}

		TITANIUM_PROPERTY_SETTER(FrameworkElement, Width)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<double>(argument);
			unwrap()->Width = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, Width)
		{
			auto value = unwrap()->Width;
			auto context = get_context();
			return context.CreateNumber(static_cast<double>(value));
		}

		TITANIUM_PROPERTY_SETTER(FrameworkElement, VerticalAlignment)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<::Windows::UI::Xaml::VerticalAlignment>(static_cast<int32_t>(argument)); // TODO Look up enum in metadata to know what type it's value is? 
			unwrap()->VerticalAlignment = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, VerticalAlignment)
		{
			auto value = unwrap()->VerticalAlignment;
			auto context = get_context();
			return context.CreateNumber(static_cast<int32_t>(static_cast<int>(value))); // FIXME What if the enum isn't an int based one?!
		}

		TITANIUM_PROPERTY_SETTER(FrameworkElement, Tag)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<Titanium::Module>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrapTitanium_Module();
			unwrap()->Tag = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, Tag)
		{
			auto value = unwrap()->Tag;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<object>::Class());
			auto native_wrapper = object.GetPrivate<object>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_SETTER(FrameworkElement, Style)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<Windows::UI::Xaml::Style>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrapWindows_UI_Xaml_Style();
			unwrap()->Style = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, Style)
		{
			auto value = unwrap()->Style;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::Style>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::Style>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_SETTER(FrameworkElement, Resources)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<Windows::UI::Xaml::ResourceDictionary>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrapWindows_UI_Xaml_ResourceDictionary();
			unwrap()->Resources = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, Resources)
		{
			auto value = unwrap()->Resources;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::ResourceDictionary>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::ResourceDictionary>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_SETTER(FrameworkElement, Margin)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto value = ref new Windows::UI::Xaml::Thickness(0, 0, 0, 0);
			unwrap()->Margin = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, Margin)
		{
			auto value = unwrap()->Margin;
			auto context = get_context();
			auto result = context.CreateObject();
			result.SetProperty("Left", context.CreateNumber(static_cast<int32_t>(value.Left)));
			result.SetProperty("Top", context.CreateNumber(static_cast<int32_t>(value.Top)));
			result.SetProperty("Right", context.CreateNumber(static_cast<int32_t>(value.Right)));
			result.SetProperty("Bottom", context.CreateNumber(static_cast<int32_t>(value.Bottom)));
			return result; 
		}

		TITANIUM_PROPERTY_SETTER(FrameworkElement, MinWidth)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<double>(argument);
			unwrap()->MinWidth = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, MinWidth)
		{
			auto value = unwrap()->MinWidth;
			auto context = get_context();
			return context.CreateNumber(static_cast<double>(value));
		}

		TITANIUM_PROPERTY_SETTER(FrameworkElement, MinHeight)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<double>(argument);
			unwrap()->MinHeight = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, MinHeight)
		{
			auto value = unwrap()->MinHeight;
			auto context = get_context();
			return context.CreateNumber(static_cast<double>(value));
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, ActualHeight)
		{
			auto value = unwrap()->ActualHeight;
			auto context = get_context();
			return context.CreateNumber(static_cast<double>(value));
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, ActualWidth)
		{
			auto value = unwrap()->ActualWidth;
			auto context = get_context();
			return context.CreateNumber(static_cast<double>(value));
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, BaseUri)
		{
			auto value = unwrap()->BaseUri;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::Foundation::Uri>::Class());
			auto native_wrapper = object.GetPrivate<Windows::Foundation::Uri>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, Parent)
		{
			auto value = unwrap()->Parent;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyObject>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyObject>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, Triggers)
		{
			auto value = unwrap()->Triggers;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::TriggerCollection>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::TriggerCollection>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_SETTER(FrameworkElement, RequestedTheme)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<::Windows::UI::Xaml::ElementTheme>(static_cast<int32_t>(argument)); // TODO Look up enum in metadata to know what type it's value is? 
			unwrap()->RequestedTheme = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, RequestedTheme)
		{
			auto value = unwrap()->RequestedTheme;
			auto context = get_context();
			return context.CreateNumber(static_cast<int32_t>(static_cast<int>(value))); // FIXME What if the enum isn't an int based one?!
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, RequestedThemeProperty)
		{
			auto value = unwrap()->RequestedThemeProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, ActualHeightProperty)
		{
			auto value = unwrap()->ActualHeightProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, ActualWidthProperty)
		{
			auto value = unwrap()->ActualWidthProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, DataContextProperty)
		{
			auto value = unwrap()->DataContextProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, FlowDirectionProperty)
		{
			auto value = unwrap()->FlowDirectionProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, HeightProperty)
		{
			auto value = unwrap()->HeightProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, HorizontalAlignmentProperty)
		{
			auto value = unwrap()->HorizontalAlignmentProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, LanguageProperty)
		{
			auto value = unwrap()->LanguageProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, MarginProperty)
		{
			auto value = unwrap()->MarginProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, MaxHeightProperty)
		{
			auto value = unwrap()->MaxHeightProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, MaxWidthProperty)
		{
			auto value = unwrap()->MaxWidthProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, MinHeightProperty)
		{
			auto value = unwrap()->MinHeightProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, MinWidthProperty)
		{
			auto value = unwrap()->MinWidthProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, NameProperty)
		{
			auto value = unwrap()->NameProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, StyleProperty)
		{
			auto value = unwrap()->StyleProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, TagProperty)
		{
			auto value = unwrap()->TagProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, VerticalAlignmentProperty)
		{
			auto value = unwrap()->VerticalAlignmentProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(FrameworkElement, WidthProperty)
		{
			auto value = unwrap()->WidthProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_FUNCTION(FrameworkElement, FindName)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = unwrap()->FindName();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(FrameworkElement, SetBinding)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			unwrap()->SetBinding();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(FrameworkElement, GetBindingExpression)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = unwrap()->GetBindingExpression();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(FrameworkElement, MeasureOverride)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = unwrap()->MeasureOverride();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(FrameworkElement, ArrangeOverride)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = unwrap()->ArrangeOverride();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(FrameworkElement, OnApplyTemplate)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			unwrap()->OnApplyTemplate();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(FrameworkElement, GoToElementStateCore)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = unwrap()->GoToElementStateCore();
			return get_context().CreateBoolean(result); 
		}

			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
