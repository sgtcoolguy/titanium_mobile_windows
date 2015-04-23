/**
 * Windows Native Wrapper for Windows.UI.Xaml.Documents.TextElement
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.DependencyProperty.hpp"
#include "Windows.UI.Xaml.Documents.TextPointer.hpp"
#include "Windows.UI.Xaml.Media.FontFamily.hpp"
#include "Windows.UI.Xaml.Media.Brush.hpp"
#include "Windows.UI.Xaml.Documents.TextElement.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{
				namespace Documents
				{

		TextElement::TextElement(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::DependencyObject(js_context)
		{
		}

		void TextElement::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::Documents::TextElement^ TextElement::unwrapWindows_UI_Xaml_Documents_TextElement() const
		{
			return dynamic_cast<::Windows::UI::Xaml::Documents::TextElement^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		::Windows::UI::Xaml::Documents::TextElement^ TextElement::unwrap() const
		{
			return unwrapWindows_UI_Xaml_Documents_TextElement();
		}

		void TextElement::wrap(::Windows::UI::Xaml::Documents::TextElement^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void TextElement::JSExportInitialize()
		{
			JSExport<TextElement>::SetClassVersion(1);
			JSExport<TextElement>::SetParent(JSExport<Windows::UI::Xaml::DependencyObject>::Class());

			TITANIUM_ADD_PROPERTY(TextElement, Language);
			TITANIUM_ADD_PROPERTY(TextElement, Foreground);
			TITANIUM_ADD_PROPERTY(TextElement, FontWeight);
			TITANIUM_ADD_PROPERTY(TextElement, FontStyle);
			TITANIUM_ADD_PROPERTY(TextElement, FontStretch);
			TITANIUM_ADD_PROPERTY(TextElement, FontSize);
			TITANIUM_ADD_PROPERTY(TextElement, FontFamily);
			TITANIUM_ADD_PROPERTY(TextElement, CharacterSpacing);
			TITANIUM_ADD_PROPERTY_READONLY(TextElement, ContentEnd);
			TITANIUM_ADD_PROPERTY_READONLY(TextElement, ContentStart);
			TITANIUM_ADD_PROPERTY_READONLY(TextElement, ElementEnd);
			TITANIUM_ADD_PROPERTY_READONLY(TextElement, ElementStart);
			TITANIUM_ADD_PROPERTY_READONLY(TextElement, Name);
			TITANIUM_ADD_PROPERTY_READONLY(TextElement, CharacterSpacingProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextElement, FontFamilyProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextElement, FontSizeProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextElement, FontStretchProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextElement, FontStyleProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextElement, FontWeightProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextElement, ForegroundProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextElement, LanguageProperty);
			TITANIUM_ADD_FUNCTION(TextElement, FindName);
		}

		TITANIUM_PROPERTY_SETTER(TextElement, Language)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsString(), "Expected String");
			auto value = TitaniumWindows::Utility::ConvertUTF8String(static_cast<std::string>(argument));


			unwrap()->Language = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextElement, Language)
		{
			auto value = unwrap()->Language;
			auto context = get_context();
 			auto result = context.CreateString(TitaniumWindows::Utility::ConvertUTF8String(value));

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextElement, Foreground)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(argument);
			auto wrapper_value = object_value.GetPrivate<Windows::UI::Xaml::Media::Brush>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_Media_Brush();


			unwrap()->Foreground = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextElement, Foreground)
		{
			auto value = unwrap()->Foreground;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::Media::Brush>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::Media::Brush>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextElement, FontWeight)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(argument);
			auto value = ::Windows::UI::Text::FontWeight(0);
			// Assign fields explicitly since we cheated on constructor args
			auto Weight = object_value.GetProperty("Weight");
			value.Weight = static_cast<int32_t>(Weight);


			unwrap()->FontWeight = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextElement, FontWeight)
		{
			auto value = unwrap()->FontWeight;
			auto context = get_context();
			auto result = context.CreateObject();
			result.SetProperty("Weight", context.CreateNumber(static_cast<int32_t>(value.Weight)));

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextElement, FontStyle)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<::Windows::UI::Text::FontStyle>(static_cast<int32_t>(argument)); // TODO Look up enum in metadata to know what type it's value is? 


			unwrap()->FontStyle = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextElement, FontStyle)
		{
			auto value = unwrap()->FontStyle;
			auto context = get_context();
			auto result = context.CreateNumber(static_cast<int32_t>(static_cast<int>(value))); // FIXME What if the enum isn't an int based one?!

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextElement, FontStretch)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<::Windows::UI::Text::FontStretch>(static_cast<int32_t>(argument)); // TODO Look up enum in metadata to know what type it's value is? 


			unwrap()->FontStretch = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextElement, FontStretch)
		{
			auto value = unwrap()->FontStretch;
			auto context = get_context();
			auto result = context.CreateNumber(static_cast<int32_t>(static_cast<int>(value))); // FIXME What if the enum isn't an int based one?!

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextElement, FontSize)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<double>(argument);


			unwrap()->FontSize = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextElement, FontSize)
		{
			auto value = unwrap()->FontSize;
			auto context = get_context();
			auto result = context.CreateNumber(static_cast<double>(value));

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextElement, FontFamily)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(argument);
			auto wrapper_value = object_value.GetPrivate<Windows::UI::Xaml::Media::FontFamily>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_Media_FontFamily();


			unwrap()->FontFamily = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextElement, FontFamily)
		{
			auto value = unwrap()->FontFamily;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::Media::FontFamily>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::Media::FontFamily>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextElement, CharacterSpacing)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<int32_t>(argument);


			unwrap()->CharacterSpacing = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextElement, CharacterSpacing)
		{
			auto value = unwrap()->CharacterSpacing;
			auto context = get_context();
 			auto result = context.CreateNumber(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextElement, ContentEnd)
		{
			auto value = unwrap()->ContentEnd;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::Documents::TextPointer>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::Documents::TextPointer>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextElement, ContentStart)
		{
			auto value = unwrap()->ContentStart;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::Documents::TextPointer>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::Documents::TextPointer>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextElement, ElementEnd)
		{
			auto value = unwrap()->ElementEnd;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::Documents::TextPointer>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::Documents::TextPointer>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextElement, ElementStart)
		{
			auto value = unwrap()->ElementStart;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::Documents::TextPointer>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::Documents::TextPointer>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextElement, Name)
		{
			auto value = unwrap()->Name;
			auto context = get_context();
 			auto result = context.CreateString(TitaniumWindows::Utility::ConvertUTF8String(value));

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextElement, CharacterSpacingProperty)
		{
			auto value = unwrap()->CharacterSpacingProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextElement, FontFamilyProperty)
		{
			auto value = unwrap()->FontFamilyProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextElement, FontSizeProperty)
		{
			auto value = unwrap()->FontSizeProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextElement, FontStretchProperty)
		{
			auto value = unwrap()->FontStretchProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextElement, FontStyleProperty)
		{
			auto value = unwrap()->FontStyleProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextElement, FontWeightProperty)
		{
			auto value = unwrap()->FontWeightProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextElement, ForegroundProperty)
		{
			auto value = unwrap()->ForegroundProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextElement, LanguageProperty)
		{
			auto value = unwrap()->LanguageProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_FUNCTION(TextElement, FindName)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsString(), "Expected String");
			auto name = TitaniumWindows::Utility::ConvertUTF8String(static_cast<std::string>(_0));


			auto context = get_context();
			auto method_result = unwrap()->FindName(name);

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<object>::Class());
			auto result_wrapper = result.GetPrivate<object>();
			result_wrapper->wrap(method_result);


			return result; 
		}

				} // namespace Documents
			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
