
/**
 * Windows Native Wrapper for Windows.UI.Xaml.Controls.TextBox
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.Controls.TextBox.hpp"
 // TODO Include the headers for all the native types we use in here!

namespace Windows
{
	namespace UI
	{
		namespace Xaml
		{
			namespace Controls
			{

		TextBox::TextBox(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::Controls::Control(js_context, arguments)
		{
		}

		void TextBox::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
			// TODO If this is not a "leaf" class, should we instantiate the type? How woudl we even know if it's a leaf?
			wrapped__ = ref new Windows::UI::Xaml::Controls::TextBox();
		}

		Windows::UI::Xaml::Controls::TextBox^ TextBox::unwrap()
		{
			return wrapped__;
		}

		void TextBox::wrap(Windows::UI::Xaml::Controls::TextBox^ object)
		{
			wrapped__ = object; // TODO Do we need to do some sort of cast here? wrapped__ may be up in a parent class and defined as the parent type...
		}

		void TextBox::JSExportInitialize()
		{
			JSExport<TextBox>::SetClassVersion(1);
			JSExport<TextBox>::SetParent(JSExport<Windows::UI::Xaml::Controls::Control>::Class()); // FIXME Extend the parent class of the native type!

			TITANIUM_ADD_PROPERTY(TextBox, PreventKeyboardDisplayOnProgrammaticFocus);
			TITANIUM_ADD_PROPERTY(TextBox, PlaceholderText);
			TITANIUM_ADD_PROPERTY(TextBox, IsColorFontEnabled);
			TITANIUM_ADD_PROPERTY(TextBox, HeaderTemplate);
			TITANIUM_ADD_PROPERTY(TextBox, Header);
			TITANIUM_ADD_PROPERTY(TextBox, SelectionHighlightColor);
			TITANIUM_ADD_PROPERTY(TextBox, SelectionStart);
			TITANIUM_ADD_PROPERTY(TextBox, SelectionLength);
			TITANIUM_ADD_PROPERTY(TextBox, SelectedText);
			TITANIUM_ADD_PROPERTY(TextBox, MaxLength);
			TITANIUM_ADD_PROPERTY(TextBox, IsTextPredictionEnabled);
			TITANIUM_ADD_PROPERTY(TextBox, IsSpellCheckEnabled);
			TITANIUM_ADD_PROPERTY(TextBox, IsReadOnly);
			TITANIUM_ADD_PROPERTY(TextBox, InputScope);
			TITANIUM_ADD_PROPERTY(TextBox, AcceptsReturn);
			TITANIUM_ADD_PROPERTY(TextBox, Text);
			TITANIUM_ADD_PROPERTY(TextBox, TextWrapping);
			TITANIUM_ADD_PROPERTY(TextBox, TextAlignment);
			TITANIUM_ADD_PROPERTY_READONLY(TextBox, AcceptsReturnProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBox, InputScopeProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBox, IsReadOnlyProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBox, IsSpellCheckEnabledProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBox, IsTextPredictionEnabledProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBox, MaxLengthProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBox, TextAlignmentProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBox, TextProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBox, TextWrappingProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBox, HeaderProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBox, HeaderTemplateProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBox, IsColorFontEnabledProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBox, PlaceholderTextProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBox, PreventKeyboardDisplayOnProgrammaticFocusProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBox, SelectionHighlightColorProperty);
			TITANIUM_ADD_FUNCTION(TextBox, Select);
			TITANIUM_ADD_FUNCTION(TextBox, SelectAll);
			TITANIUM_ADD_FUNCTION(TextBox, GetRectFromCharacterIndex);
		}

		TITANIUM_PROPERTY_SETTER(TextBox, PreventKeyboardDisplayOnProgrammaticFocus)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsBoolean(), "Expected boolean");
			auto value = static_cast<bool>(argument);
			wrapped__->PreventKeyboardDisplayOnProgrammaticFocus = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, PreventKeyboardDisplayOnProgrammaticFocus)
		{
			auto value = wrapped__->PreventKeyboardDisplayOnProgrammaticFocus;
			auto context = get_context();
 			return context.CreateBoolean(value); 
		}

		TITANIUM_PROPERTY_SETTER(TextBox, PlaceholderText)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsString(), "Expected String");
			auto value = static_cast<std::string>(argument);
			wrapped__->PlaceholderText = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, PlaceholderText)
		{
			auto value = wrapped__->PlaceholderText;
			auto context = get_context();
 			return context.CreateString(value);
		}

		TITANIUM_PROPERTY_SETTER(TextBox, IsColorFontEnabled)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsBoolean(), "Expected boolean");
			auto value = static_cast<bool>(argument);
			wrapped__->IsColorFontEnabled = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, IsColorFontEnabled)
		{
			auto value = wrapped__->IsColorFontEnabled;
			auto context = get_context();
 			return context.CreateBoolean(value); 
		}

		TITANIUM_PROPERTY_SETTER(TextBox, HeaderTemplate)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<Windows::UI::Xaml::DataTemplate>();
			// FIXME What if the type we want here is some parent class of the actual wrapper class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrap();
			wrapped__->HeaderTemplate = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, HeaderTemplate)
		{
			auto value = wrapped__->HeaderTemplate;
			auto context = get_context();
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DataTemplate>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DataTemplate>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_SETTER(TextBox, Header)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<object>();
			// FIXME What if the type we want here is some parent class of the actual wrapper class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrap();
			wrapped__->Header = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, Header)
		{
			auto value = wrapped__->Header;
			auto context = get_context();
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
			auto object = context.CreateObject(JSExport<object>::Class());
			auto native_wrapper = object.GetPrivate<object>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_SETTER(TextBox, SelectionHighlightColor)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<Windows::UI::Xaml::Media::SolidColorBrush>();
			// FIXME What if the type we want here is some parent class of the actual wrapper class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrap();
			wrapped__->SelectionHighlightColor = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, SelectionHighlightColor)
		{
			auto value = wrapped__->SelectionHighlightColor;
			auto context = get_context();
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::Media::SolidColorBrush>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::Media::SolidColorBrush>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_SETTER(TextBox, SelectionStart)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<int32>(argument);
			wrapped__->SelectionStart = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, SelectionStart)
		{
			auto value = wrapped__->SelectionStart;
			auto context = get_context();
 			return context.CreateNumber(value);
		}

		TITANIUM_PROPERTY_SETTER(TextBox, SelectionLength)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<int32>(argument);
			wrapped__->SelectionLength = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, SelectionLength)
		{
			auto value = wrapped__->SelectionLength;
			auto context = get_context();
 			return context.CreateNumber(value);
		}

		TITANIUM_PROPERTY_SETTER(TextBox, SelectedText)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsString(), "Expected String");
			auto value = static_cast<std::string>(argument);
			wrapped__->SelectedText = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, SelectedText)
		{
			auto value = wrapped__->SelectedText;
			auto context = get_context();
 			return context.CreateString(value);
		}

		TITANIUM_PROPERTY_SETTER(TextBox, MaxLength)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<int32>(argument);
			wrapped__->MaxLength = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, MaxLength)
		{
			auto value = wrapped__->MaxLength;
			auto context = get_context();
 			return context.CreateNumber(value);
		}

		TITANIUM_PROPERTY_SETTER(TextBox, IsTextPredictionEnabled)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsBoolean(), "Expected boolean");
			auto value = static_cast<bool>(argument);
			wrapped__->IsTextPredictionEnabled = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, IsTextPredictionEnabled)
		{
			auto value = wrapped__->IsTextPredictionEnabled;
			auto context = get_context();
 			return context.CreateBoolean(value); 
		}

		TITANIUM_PROPERTY_SETTER(TextBox, IsSpellCheckEnabled)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsBoolean(), "Expected boolean");
			auto value = static_cast<bool>(argument);
			wrapped__->IsSpellCheckEnabled = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, IsSpellCheckEnabled)
		{
			auto value = wrapped__->IsSpellCheckEnabled;
			auto context = get_context();
 			return context.CreateBoolean(value); 
		}

		TITANIUM_PROPERTY_SETTER(TextBox, IsReadOnly)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsBoolean(), "Expected boolean");
			auto value = static_cast<bool>(argument);
			wrapped__->IsReadOnly = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, IsReadOnly)
		{
			auto value = wrapped__->IsReadOnly;
			auto context = get_context();
 			return context.CreateBoolean(value); 
		}

		TITANIUM_PROPERTY_SETTER(TextBox, InputScope)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<Windows::UI::Xaml::Input::InputScope>();
			// FIXME What if the type we want here is some parent class of the actual wrapper class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrap();
			wrapped__->InputScope = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, InputScope)
		{
			auto value = wrapped__->InputScope;
			auto context = get_context();
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::Input::InputScope>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::Input::InputScope>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_SETTER(TextBox, AcceptsReturn)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsBoolean(), "Expected boolean");
			auto value = static_cast<bool>(argument);
			wrapped__->AcceptsReturn = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, AcceptsReturn)
		{
			auto value = wrapped__->AcceptsReturn;
			auto context = get_context();
 			return context.CreateBoolean(value); 
		}

		TITANIUM_PROPERTY_SETTER(TextBox, Text)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsString(), "Expected String");
			auto value = static_cast<std::string>(argument);
			wrapped__->Text = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, Text)
		{
			auto value = wrapped__->Text;
			auto context = get_context();
 			return context.CreateString(value);
		}

		TITANIUM_PROPERTY_SETTER(TextBox, TextWrapping)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<int32>(argument); // TODO Look up enum in metadata to know what type it's value is? 
			wrapped__->TextWrapping = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, TextWrapping)
		{
			auto value = wrapped__->TextWrapping;
			auto context = get_context();
			return context.CreateNumber(value);
		}

		TITANIUM_PROPERTY_SETTER(TextBox, TextAlignment)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<int32>(argument); // TODO Look up enum in metadata to know what type it's value is? 
			wrapped__->TextAlignment = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, TextAlignment)
		{
			auto value = wrapped__->TextAlignment;
			auto context = get_context();
			return context.CreateNumber(value);
		}

		TITANIUM_PROPERTY_GETTER(TextBox, AcceptsReturnProperty)
		{
			auto value = wrapped__->AcceptsReturnProperty;
			auto context = get_context();
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, InputScopeProperty)
		{
			auto value = wrapped__->InputScopeProperty;
			auto context = get_context();
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, IsReadOnlyProperty)
		{
			auto value = wrapped__->IsReadOnlyProperty;
			auto context = get_context();
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, IsSpellCheckEnabledProperty)
		{
			auto value = wrapped__->IsSpellCheckEnabledProperty;
			auto context = get_context();
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, IsTextPredictionEnabledProperty)
		{
			auto value = wrapped__->IsTextPredictionEnabledProperty;
			auto context = get_context();
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, MaxLengthProperty)
		{
			auto value = wrapped__->MaxLengthProperty;
			auto context = get_context();
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, TextAlignmentProperty)
		{
			auto value = wrapped__->TextAlignmentProperty;
			auto context = get_context();
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, TextProperty)
		{
			auto value = wrapped__->TextProperty;
			auto context = get_context();
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, TextWrappingProperty)
		{
			auto value = wrapped__->TextWrappingProperty;
			auto context = get_context();
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, HeaderProperty)
		{
			auto value = wrapped__->HeaderProperty;
			auto context = get_context();
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, HeaderTemplateProperty)
		{
			auto value = wrapped__->HeaderTemplateProperty;
			auto context = get_context();
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, IsColorFontEnabledProperty)
		{
			auto value = wrapped__->IsColorFontEnabledProperty;
			auto context = get_context();
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, PlaceholderTextProperty)
		{
			auto value = wrapped__->PlaceholderTextProperty;
			auto context = get_context();
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, PreventKeyboardDisplayOnProgrammaticFocusProperty)
		{
			auto value = wrapped__->PreventKeyboardDisplayOnProgrammaticFocusProperty;
			auto context = get_context();
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, SelectionHighlightColorProperty)
		{
			auto value = wrapped__->SelectionHighlightColorProperty;
			auto context = get_context();
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_FUNCTION(TextBox, Select)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->Select();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TextBox, SelectAll)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->SelectAll();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TextBox, GetRectFromCharacterIndex)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = wrapped__->GetRectFromCharacterIndex();
			return get_context().CreateBoolean(result); 
		}

			} // namespace Controls
		} // namespace Xaml
	} // namespace UI
} // namespace Windows
