/**
 * Windows Native Wrapper for Windows.UI.Xaml.Controls.Control
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.Controls.Control.hpp"
 // TODO Include the headers for all the native types we use in here! We'll have to go through type of every method arg, return type, type of every property

namespace Windows
{
	namespace UI
	{
		namespace Xaml
		{
			namespace Controls
			{

		Control::Control(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::FrameworkElement(js_context, arguments)
		{
		}

		void Control::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
			wrapped__ = ref new Windows::UI::Xaml::Controls::Control();
		}

		Windows::UI::Xaml::Controls::Control^ Control::unwrapWindows_UI_Xaml_Controls_Control()
		{
			return dynamic_cast<Windows::UI::Xaml::Controls::Control^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		void Control::wrap(Windows::UI::Xaml::Controls::Control^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void Control::JSExportInitialize()
		{
			JSExport<Control>::SetClassVersion(1);
			JSExport<Control>::SetParent(JSExport<Windows::UI::Xaml::FrameworkElement>::Class());

			TITANIUM_ADD_PROPERTY(Control, FontStyle);
			TITANIUM_ADD_PROPERTY(Control, FontStretch);
			TITANIUM_ADD_PROPERTY(Control, FontSize);
			TITANIUM_ADD_PROPERTY(Control, FontFamily);
			TITANIUM_ADD_PROPERTY(Control, FontWeight);
			TITANIUM_ADD_PROPERTY(Control, CharacterSpacing);
			TITANIUM_ADD_PROPERTY(Control, BorderThickness);
			TITANIUM_ADD_PROPERTY(Control, BorderBrush);
			TITANIUM_ADD_PROPERTY(Control, Background);
			TITANIUM_ADD_PROPERTY(Control, VerticalContentAlignment);
			TITANIUM_ADD_PROPERTY(Control, Template);
			TITANIUM_ADD_PROPERTY(Control, TabNavigation);
			TITANIUM_ADD_PROPERTY(Control, TabIndex);
			TITANIUM_ADD_PROPERTY(Control, Padding);
			TITANIUM_ADD_PROPERTY(Control, IsTabStop);
			TITANIUM_ADD_PROPERTY(Control, IsEnabled);
			TITANIUM_ADD_PROPERTY(Control, HorizontalContentAlignment);
			TITANIUM_ADD_PROPERTY(Control, Foreground);
			TITANIUM_ADD_PROPERTY_READONLY(Control, FocusState);
			TITANIUM_ADD_PROPERTY(Control, DefaultStyleKey);
			TITANIUM_ADD_PROPERTY_READONLY(Control, BackgroundProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, BorderBrushProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, BorderThicknessProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, CharacterSpacingProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, DefaultStyleKeyProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, FocusStateProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, FontFamilyProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, FontSizeProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, FontStretchProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, FontStyleProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, FontWeightProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, ForegroundProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, HorizontalContentAlignmentProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, IsEnabledProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, IsTabStopProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, PaddingProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, TabIndexProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, TabNavigationProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, TemplateProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, VerticalContentAlignmentProperty);
			TITANIUM_ADD_FUNCTION(Control, ApplyTemplate);
			TITANIUM_ADD_FUNCTION(Control, Focus);
			TITANIUM_ADD_FUNCTION(Control, OnPointerEntered);
			TITANIUM_ADD_FUNCTION(Control, OnPointerPressed);
			TITANIUM_ADD_FUNCTION(Control, OnPointerMoved);
			TITANIUM_ADD_FUNCTION(Control, OnPointerReleased);
			TITANIUM_ADD_FUNCTION(Control, OnPointerExited);
			TITANIUM_ADD_FUNCTION(Control, OnPointerCaptureLost);
			TITANIUM_ADD_FUNCTION(Control, OnPointerCanceled);
			TITANIUM_ADD_FUNCTION(Control, OnPointerWheelChanged);
			TITANIUM_ADD_FUNCTION(Control, OnTapped);
			TITANIUM_ADD_FUNCTION(Control, OnDoubleTapped);
			TITANIUM_ADD_FUNCTION(Control, OnHolding);
			TITANIUM_ADD_FUNCTION(Control, OnRightTapped);
			TITANIUM_ADD_FUNCTION(Control, OnManipulationStarting);
			TITANIUM_ADD_FUNCTION(Control, OnManipulationInertiaStarting);
			TITANIUM_ADD_FUNCTION(Control, OnManipulationStarted);
			TITANIUM_ADD_FUNCTION(Control, OnManipulationDelta);
			TITANIUM_ADD_FUNCTION(Control, OnManipulationCompleted);
			TITANIUM_ADD_FUNCTION(Control, OnKeyUp);
			TITANIUM_ADD_FUNCTION(Control, OnKeyDown);
			TITANIUM_ADD_FUNCTION(Control, OnGotFocus);
			TITANIUM_ADD_FUNCTION(Control, OnLostFocus);
			TITANIUM_ADD_FUNCTION(Control, OnDragEnter);
			TITANIUM_ADD_FUNCTION(Control, OnDragLeave);
			TITANIUM_ADD_FUNCTION(Control, OnDragOver);
			TITANIUM_ADD_FUNCTION(Control, OnDrop);
			TITANIUM_ADD_FUNCTION(Control, GetTemplateChild);
		}

		TITANIUM_PROPERTY_SETTER(Control, FontStyle)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<int32_t>(argument); // TODO Look up enum in metadata to know what type it's value is? 
			wrapped__->FontStyle = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, FontStyle)
		{
			auto value = wrapped__->FontStyle;
			auto context = get_context();
			return context.CreateNumber(value);
		}

		TITANIUM_PROPERTY_SETTER(Control, FontStretch)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<int32_t>(argument); // TODO Look up enum in metadata to know what type it's value is? 
			wrapped__->FontStretch = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, FontStretch)
		{
			auto value = wrapped__->FontStretch;
			auto context = get_context();
			return context.CreateNumber(value);
		}

		TITANIUM_PROPERTY_SETTER(Control, FontSize)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<double>(argument);
			wrapped__->FontSize = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, FontSize)
		{
			auto value = wrapped__->FontSize;
			auto context = get_context();
			return context.CreateNumber(static_cast<double>(value));
		}

		TITANIUM_PROPERTY_SETTER(Control, FontFamily)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<Windows::UI::Xaml::Media::FontFamily>();
			// FIXME What if the type we want here is some parent class of the actual wrapper class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrapWindows_UI_Xaml_Media_FontFamily();
			wrapped__->FontFamily = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, FontFamily)
		{
			auto value = wrapped__->FontFamily;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::Media::FontFamily>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::Media::FontFamily>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_SETTER(Control, FontWeight)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto value = ref new Windows::UI::Text::FontWeight(); // FIXME We need to look at the fields to know how many, and order of args to pass in!
			wrapped__->FontWeight = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, FontWeight)
		{
			auto value = wrapped__->FontWeight;
			auto context = get_context();
			auto result = context.CreateObject();
			result.SetProperty("Weight", context.CreateNumber(static_cast<int32_t>(value.Weight)));
			return result; 
		}

		TITANIUM_PROPERTY_SETTER(Control, CharacterSpacing)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<int32_t>(argument);
			wrapped__->CharacterSpacing = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, CharacterSpacing)
		{
			auto value = wrapped__->CharacterSpacing;
			auto context = get_context();
 			return context.CreateNumber(value);
		}

		TITANIUM_PROPERTY_SETTER(Control, BorderThickness)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto value = ref new Windows::UI::Xaml::Thickness(); // FIXME We need to look at the fields to know how many, and order of args to pass in!
			wrapped__->BorderThickness = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, BorderThickness)
		{
			auto value = wrapped__->BorderThickness;
			auto context = get_context();
			auto result = context.CreateObject();
			result.SetProperty("Left", context.CreateNumber(static_cast<int32_t>(value.Left)));
			result.SetProperty("Top", context.CreateNumber(static_cast<int32_t>(value.Top)));
			result.SetProperty("Right", context.CreateNumber(static_cast<int32_t>(value.Right)));
			result.SetProperty("Bottom", context.CreateNumber(static_cast<int32_t>(value.Bottom)));
			return result; 
		}

		TITANIUM_PROPERTY_SETTER(Control, BorderBrush)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<Windows::UI::Xaml::Media::Brush>();
			// FIXME What if the type we want here is some parent class of the actual wrapper class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrapWindows_UI_Xaml_Media_Brush();
			wrapped__->BorderBrush = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, BorderBrush)
		{
			auto value = wrapped__->BorderBrush;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::Media::Brush>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::Media::Brush>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_SETTER(Control, Background)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<Windows::UI::Xaml::Media::Brush>();
			// FIXME What if the type we want here is some parent class of the actual wrapper class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrapWindows_UI_Xaml_Media_Brush();
			wrapped__->Background = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, Background)
		{
			auto value = wrapped__->Background;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::Media::Brush>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::Media::Brush>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_SETTER(Control, VerticalContentAlignment)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<int32_t>(argument); // TODO Look up enum in metadata to know what type it's value is? 
			wrapped__->VerticalContentAlignment = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, VerticalContentAlignment)
		{
			auto value = wrapped__->VerticalContentAlignment;
			auto context = get_context();
			return context.CreateNumber(value);
		}

		TITANIUM_PROPERTY_SETTER(Control, Template)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<Windows::UI::Xaml::Controls::ControlTemplate>();
			// FIXME What if the type we want here is some parent class of the actual wrapper class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrapWindows_UI_Xaml_Controls_ControlTemplate();
			wrapped__->Template = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, Template)
		{
			auto value = wrapped__->Template;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::Controls::ControlTemplate>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::Controls::ControlTemplate>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_SETTER(Control, TabNavigation)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<int32_t>(argument); // TODO Look up enum in metadata to know what type it's value is? 
			wrapped__->TabNavigation = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, TabNavigation)
		{
			auto value = wrapped__->TabNavigation;
			auto context = get_context();
			return context.CreateNumber(value);
		}

		TITANIUM_PROPERTY_SETTER(Control, TabIndex)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<int32_t>(argument);
			wrapped__->TabIndex = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, TabIndex)
		{
			auto value = wrapped__->TabIndex;
			auto context = get_context();
 			return context.CreateNumber(value);
		}

		TITANIUM_PROPERTY_SETTER(Control, Padding)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto value = ref new Windows::UI::Xaml::Thickness(); // FIXME We need to look at the fields to know how many, and order of args to pass in!
			wrapped__->Padding = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, Padding)
		{
			auto value = wrapped__->Padding;
			auto context = get_context();
			auto result = context.CreateObject();
			result.SetProperty("Left", context.CreateNumber(static_cast<int32_t>(value.Left)));
			result.SetProperty("Top", context.CreateNumber(static_cast<int32_t>(value.Top)));
			result.SetProperty("Right", context.CreateNumber(static_cast<int32_t>(value.Right)));
			result.SetProperty("Bottom", context.CreateNumber(static_cast<int32_t>(value.Bottom)));
			return result; 
		}

		TITANIUM_PROPERTY_SETTER(Control, IsTabStop)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsBoolean(), "Expected boolean");
			auto value = static_cast<bool>(argument);
			wrapped__->IsTabStop = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, IsTabStop)
		{
			auto value = wrapped__->IsTabStop;
			auto context = get_context();
 			return context.CreateBoolean(value); 
		}

		TITANIUM_PROPERTY_SETTER(Control, IsEnabled)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsBoolean(), "Expected boolean");
			auto value = static_cast<bool>(argument);
			wrapped__->IsEnabled = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, IsEnabled)
		{
			auto value = wrapped__->IsEnabled;
			auto context = get_context();
 			return context.CreateBoolean(value); 
		}

		TITANIUM_PROPERTY_SETTER(Control, HorizontalContentAlignment)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<int32_t>(argument); // TODO Look up enum in metadata to know what type it's value is? 
			wrapped__->HorizontalContentAlignment = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, HorizontalContentAlignment)
		{
			auto value = wrapped__->HorizontalContentAlignment;
			auto context = get_context();
			return context.CreateNumber(value);
		}

		TITANIUM_PROPERTY_SETTER(Control, Foreground)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<Windows::UI::Xaml::Media::Brush>();
			// FIXME What if the type we want here is some parent class of the actual wrapper class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrapWindows_UI_Xaml_Media_Brush();
			wrapped__->Foreground = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, Foreground)
		{
			auto value = wrapped__->Foreground;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::Media::Brush>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::Media::Brush>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Control, FocusState)
		{
			auto value = wrapped__->FocusState;
			auto context = get_context();
			return context.CreateNumber(value);
		}

		TITANIUM_PROPERTY_SETTER(Control, DefaultStyleKey)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<object>();
			// FIXME What if the type we want here is some parent class of the actual wrapper class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrapobject();
			wrapped__->DefaultStyleKey = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, DefaultStyleKey)
		{
			auto value = wrapped__->DefaultStyleKey;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<object>::Class());
			auto native_wrapper = object.GetPrivate<object>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Control, BackgroundProperty)
		{
			auto value = wrapped__->BackgroundProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Control, BorderBrushProperty)
		{
			auto value = wrapped__->BorderBrushProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Control, BorderThicknessProperty)
		{
			auto value = wrapped__->BorderThicknessProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Control, CharacterSpacingProperty)
		{
			auto value = wrapped__->CharacterSpacingProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Control, DefaultStyleKeyProperty)
		{
			auto value = wrapped__->DefaultStyleKeyProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Control, FocusStateProperty)
		{
			auto value = wrapped__->FocusStateProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Control, FontFamilyProperty)
		{
			auto value = wrapped__->FontFamilyProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Control, FontSizeProperty)
		{
			auto value = wrapped__->FontSizeProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Control, FontStretchProperty)
		{
			auto value = wrapped__->FontStretchProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Control, FontStyleProperty)
		{
			auto value = wrapped__->FontStyleProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Control, FontWeightProperty)
		{
			auto value = wrapped__->FontWeightProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Control, ForegroundProperty)
		{
			auto value = wrapped__->ForegroundProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Control, HorizontalContentAlignmentProperty)
		{
			auto value = wrapped__->HorizontalContentAlignmentProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Control, IsEnabledProperty)
		{
			auto value = wrapped__->IsEnabledProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Control, IsTabStopProperty)
		{
			auto value = wrapped__->IsTabStopProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Control, PaddingProperty)
		{
			auto value = wrapped__->PaddingProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Control, TabIndexProperty)
		{
			auto value = wrapped__->TabIndexProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Control, TabNavigationProperty)
		{
			auto value = wrapped__->TabNavigationProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Control, TemplateProperty)
		{
			auto value = wrapped__->TemplateProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Control, VerticalContentAlignmentProperty)
		{
			auto value = wrapped__->VerticalContentAlignmentProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_FUNCTION(Control, ApplyTemplate)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = wrapped__->ApplyTemplate();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(Control, Focus)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = wrapped__->Focus();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(Control, OnPointerEntered)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->OnPointerEntered();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Control, OnPointerPressed)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->OnPointerPressed();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Control, OnPointerMoved)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->OnPointerMoved();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Control, OnPointerReleased)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->OnPointerReleased();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Control, OnPointerExited)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->OnPointerExited();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Control, OnPointerCaptureLost)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->OnPointerCaptureLost();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Control, OnPointerCanceled)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->OnPointerCanceled();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Control, OnPointerWheelChanged)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->OnPointerWheelChanged();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Control, OnTapped)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->OnTapped();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Control, OnDoubleTapped)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->OnDoubleTapped();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Control, OnHolding)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->OnHolding();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Control, OnRightTapped)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->OnRightTapped();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Control, OnManipulationStarting)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->OnManipulationStarting();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Control, OnManipulationInertiaStarting)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->OnManipulationInertiaStarting();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Control, OnManipulationStarted)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->OnManipulationStarted();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Control, OnManipulationDelta)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->OnManipulationDelta();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Control, OnManipulationCompleted)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->OnManipulationCompleted();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Control, OnKeyUp)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->OnKeyUp();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Control, OnKeyDown)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->OnKeyDown();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Control, OnGotFocus)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->OnGotFocus();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Control, OnLostFocus)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->OnLostFocus();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Control, OnDragEnter)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->OnDragEnter();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Control, OnDragLeave)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->OnDragLeave();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Control, OnDragOver)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->OnDragOver();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Control, OnDrop)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->OnDrop();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Control, GetTemplateChild)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = wrapped__->GetTemplateChild();
			return get_context().CreateBoolean(result); 
		}

			} // namespace Controls
		} // namespace Xaml
	} // namespace UI
} // namespace Windows
