/**
 * Windows Native Wrapper for Windows.UI.Xaml.Controls.TextBlock
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.DependencyProperty.hpp"
#include "Windows.UI.Xaml.Media.SolidColorBrush.hpp"
#include "Windows.UI.Xaml.Documents.InlineCollection.hpp"
#include "Windows.UI.Xaml.Documents.TextPointer.hpp"
#include "Windows.UI.Xaml.Media.FontFamily.hpp"
#include "Windows.UI.Xaml.Media.Brush.hpp"
#include "Windows.UI.Xaml.Controls.TextBlock.hpp"

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

		TextBlock::TextBlock(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::FrameworkElement(js_context)
		{
		}

		void TextBlock::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::Controls::TextBlock^ TextBlock::unwrapWindows_UI_Xaml_Controls_TextBlock() const
		{
			return dynamic_cast<::Windows::UI::Xaml::Controls::TextBlock^>(wrapped__);
		}

		::Windows::UI::Xaml::Controls::TextBlock^ TextBlock::unwrap() const
		{
			return unwrapWindows_UI_Xaml_Controls_TextBlock();
		}

		void TextBlock::wrap(::Windows::UI::Xaml::Controls::TextBlock^ object)
		{
			wrapped__ = object;
		}

		void TextBlock::JSExportInitialize()
		{
			JSExport<TextBlock>::SetClassVersion(1);
			JSExport<TextBlock>::SetParent(JSExport<Windows::UI::Xaml::FrameworkElement>::Class());

			TITANIUM_ADD_PROPERTY(TextBlock, TextWrapping);
			TITANIUM_ADD_PROPERTY(TextBlock, TextTrimming);
			TITANIUM_ADD_PROPERTY(TextBlock, TextAlignment);
			TITANIUM_ADD_PROPERTY(TextBlock, Text);
			TITANIUM_ADD_PROPERTY(TextBlock, Padding);
			TITANIUM_ADD_PROPERTY(TextBlock, LineStackingStrategy);
			TITANIUM_ADD_PROPERTY(TextBlock, Foreground);
			TITANIUM_ADD_PROPERTY(TextBlock, FontWeight);
			TITANIUM_ADD_PROPERTY(TextBlock, FontStyle);
			TITANIUM_ADD_PROPERTY(TextBlock, FontStretch);
			TITANIUM_ADD_PROPERTY(TextBlock, FontSize);
			TITANIUM_ADD_PROPERTY(TextBlock, FontFamily);
			TITANIUM_ADD_PROPERTY(TextBlock, LineHeight);
			TITANIUM_ADD_PROPERTY(TextBlock, IsTextSelectionEnabled);
			TITANIUM_ADD_PROPERTY(TextBlock, CharacterSpacing);
			TITANIUM_ADD_PROPERTY_READONLY(TextBlock, SelectedText);
			TITANIUM_ADD_PROPERTY_READONLY(TextBlock, SelectionEnd);
			TITANIUM_ADD_PROPERTY_READONLY(TextBlock, SelectionStart);
			TITANIUM_ADD_PROPERTY_READONLY(TextBlock, ContentEnd);
			TITANIUM_ADD_PROPERTY_READONLY(TextBlock, ContentStart);
			TITANIUM_ADD_PROPERTY_READONLY(TextBlock, BaselineOffset);
			TITANIUM_ADD_PROPERTY_READONLY(TextBlock, Inlines);
			TITANIUM_ADD_PROPERTY(TextBlock, OpticalMarginAlignment);
			TITANIUM_ADD_PROPERTY(TextBlock, TextReadingOrder);
			TITANIUM_ADD_PROPERTY(TextBlock, TextLineBounds);
			TITANIUM_ADD_PROPERTY(TextBlock, SelectionHighlightColor);
			TITANIUM_ADD_PROPERTY(TextBlock, MaxLines);
			TITANIUM_ADD_PROPERTY(TextBlock, IsColorFontEnabled);
			TITANIUM_ADD_PROPERTY_READONLY(TextBlock, SelectionHighlightColorProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBlock, IsColorFontEnabledProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBlock, MaxLinesProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBlock, OpticalMarginAlignmentProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBlock, TextLineBoundsProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBlock, TextReadingOrderProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBlock, CharacterSpacingProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBlock, FontFamilyProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBlock, FontSizeProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBlock, FontStretchProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBlock, FontStyleProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBlock, FontWeightProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBlock, ForegroundProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBlock, IsTextSelectionEnabledProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBlock, LineHeightProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBlock, LineStackingStrategyProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBlock, PaddingProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBlock, SelectedTextProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBlock, TextAlignmentProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBlock, TextProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBlock, TextTrimmingProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBlock, TextWrappingProperty);
			TITANIUM_ADD_FUNCTION(TextBlock, SelectAll);
			TITANIUM_ADD_FUNCTION(TextBlock, Select);
			TITANIUM_ADD_FUNCTION(TextBlock, Focus);
		}

		TITANIUM_PROPERTY_SETTER(TextBlock, TextWrapping)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<::Windows::UI::Xaml::TextWrapping>(static_cast<int32_t>(argument)); // TODO Look up enum in metadata to know what type it's value is? 


			unwrap()->TextWrapping = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, TextWrapping)
		{
			auto value = unwrap()->TextWrapping;
			auto context = get_context();
			auto result = context.CreateNumber(static_cast<int32_t>(static_cast<int>(value))); // FIXME What if the enum isn't an int based one?!

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBlock, TextTrimming)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<::Windows::UI::Xaml::TextTrimming>(static_cast<int32_t>(argument)); // TODO Look up enum in metadata to know what type it's value is? 


			unwrap()->TextTrimming = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, TextTrimming)
		{
			auto value = unwrap()->TextTrimming;
			auto context = get_context();
			auto result = context.CreateNumber(static_cast<int32_t>(static_cast<int>(value))); // FIXME What if the enum isn't an int based one?!

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBlock, TextAlignment)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<::Windows::UI::Xaml::TextAlignment>(static_cast<int32_t>(argument)); // TODO Look up enum in metadata to know what type it's value is? 


			unwrap()->TextAlignment = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, TextAlignment)
		{
			auto value = unwrap()->TextAlignment;
			auto context = get_context();
			auto result = context.CreateNumber(static_cast<int32_t>(static_cast<int>(value))); // FIXME What if the enum isn't an int based one?!

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBlock, Text)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsString(), "Expected String");
			auto value = TitaniumWindows::Utility::ConvertUTF8String(static_cast<std::string>(argument));


			unwrap()->Text = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, Text)
		{
			auto value = unwrap()->Text;
			auto context = get_context();
 			auto result = context.CreateString(TitaniumWindows::Utility::ConvertUTF8String(value));

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBlock, Padding)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(argument);
			auto value = ::Windows::UI::Xaml::Thickness(0, 0, 0, 0);
			// Assign fields explicitly since we cheated on constructor args
			auto Left = object_value.GetProperty("Left");
			value.Left = static_cast<int32_t>(Left);
			auto Top = object_value.GetProperty("Top");
			value.Top = static_cast<int32_t>(Top);
			auto Right = object_value.GetProperty("Right");
			value.Right = static_cast<int32_t>(Right);
			auto Bottom = object_value.GetProperty("Bottom");
			value.Bottom = static_cast<int32_t>(Bottom);


			unwrap()->Padding = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, Padding)
		{
			auto value = unwrap()->Padding;
			auto context = get_context();
			auto result = context.CreateObject();
			result.SetProperty("Left", context.CreateNumber(static_cast<int32_t>(value.Left)));
			result.SetProperty("Top", context.CreateNumber(static_cast<int32_t>(value.Top)));
			result.SetProperty("Right", context.CreateNumber(static_cast<int32_t>(value.Right)));
			result.SetProperty("Bottom", context.CreateNumber(static_cast<int32_t>(value.Bottom)));

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBlock, LineStackingStrategy)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<::Windows::UI::Xaml::LineStackingStrategy>(static_cast<int32_t>(argument)); // TODO Look up enum in metadata to know what type it's value is? 


			unwrap()->LineStackingStrategy = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, LineStackingStrategy)
		{
			auto value = unwrap()->LineStackingStrategy;
			auto context = get_context();
			auto result = context.CreateNumber(static_cast<int32_t>(static_cast<int>(value))); // FIXME What if the enum isn't an int based one?!

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBlock, Foreground)
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

		TITANIUM_PROPERTY_GETTER(TextBlock, Foreground)
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

		TITANIUM_PROPERTY_SETTER(TextBlock, FontWeight)
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

		TITANIUM_PROPERTY_GETTER(TextBlock, FontWeight)
		{
			auto value = unwrap()->FontWeight;
			auto context = get_context();
			auto result = context.CreateObject();
			result.SetProperty("Weight", context.CreateNumber(static_cast<int32_t>(value.Weight)));

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBlock, FontStyle)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<::Windows::UI::Text::FontStyle>(static_cast<int32_t>(argument)); // TODO Look up enum in metadata to know what type it's value is? 


			unwrap()->FontStyle = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, FontStyle)
		{
			auto value = unwrap()->FontStyle;
			auto context = get_context();
			auto result = context.CreateNumber(static_cast<int32_t>(static_cast<int>(value))); // FIXME What if the enum isn't an int based one?!

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBlock, FontStretch)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<::Windows::UI::Text::FontStretch>(static_cast<int32_t>(argument)); // TODO Look up enum in metadata to know what type it's value is? 


			unwrap()->FontStretch = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, FontStretch)
		{
			auto value = unwrap()->FontStretch;
			auto context = get_context();
			auto result = context.CreateNumber(static_cast<int32_t>(static_cast<int>(value))); // FIXME What if the enum isn't an int based one?!

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBlock, FontSize)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<double>(argument);


			unwrap()->FontSize = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, FontSize)
		{
			auto value = unwrap()->FontSize;
			auto context = get_context();
			auto result = context.CreateNumber(static_cast<double>(value));

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBlock, FontFamily)
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

		TITANIUM_PROPERTY_GETTER(TextBlock, FontFamily)
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

		TITANIUM_PROPERTY_SETTER(TextBlock, LineHeight)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<double>(argument);


			unwrap()->LineHeight = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, LineHeight)
		{
			auto value = unwrap()->LineHeight;
			auto context = get_context();
			auto result = context.CreateNumber(static_cast<double>(value));

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBlock, IsTextSelectionEnabled)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsBoolean(), "Expected boolean");
			auto value = static_cast<bool>(argument);


			unwrap()->IsTextSelectionEnabled = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, IsTextSelectionEnabled)
		{
			auto value = unwrap()->IsTextSelectionEnabled;
			auto context = get_context();
 			auto result = context.CreateBoolean(value); 

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBlock, CharacterSpacing)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<int32_t>(argument);


			unwrap()->CharacterSpacing = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, CharacterSpacing)
		{
			auto value = unwrap()->CharacterSpacing;
			auto context = get_context();
 			auto result = context.CreateNumber(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, SelectedText)
		{
			auto value = unwrap()->SelectedText;
			auto context = get_context();
 			auto result = context.CreateString(TitaniumWindows::Utility::ConvertUTF8String(value));

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, SelectionEnd)
		{
			auto value = unwrap()->SelectionEnd;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::Documents::TextPointer>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::Documents::TextPointer>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, SelectionStart)
		{
			auto value = unwrap()->SelectionStart;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::Documents::TextPointer>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::Documents::TextPointer>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, ContentEnd)
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

		TITANIUM_PROPERTY_GETTER(TextBlock, ContentStart)
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

		TITANIUM_PROPERTY_GETTER(TextBlock, BaselineOffset)
		{
			auto value = unwrap()->BaselineOffset;
			auto context = get_context();
			auto result = context.CreateNumber(static_cast<double>(value));

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, Inlines)
		{
			auto value = unwrap()->Inlines;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::Documents::InlineCollection>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::Documents::InlineCollection>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBlock, OpticalMarginAlignment)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<::Windows::UI::Xaml::OpticalMarginAlignment>(static_cast<int32_t>(argument)); // TODO Look up enum in metadata to know what type it's value is? 


			unwrap()->OpticalMarginAlignment = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, OpticalMarginAlignment)
		{
			auto value = unwrap()->OpticalMarginAlignment;
			auto context = get_context();
			auto result = context.CreateNumber(static_cast<int32_t>(static_cast<int>(value))); // FIXME What if the enum isn't an int based one?!

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBlock, TextReadingOrder)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<::Windows::UI::Xaml::TextReadingOrder>(static_cast<int32_t>(argument)); // TODO Look up enum in metadata to know what type it's value is? 


			unwrap()->TextReadingOrder = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, TextReadingOrder)
		{
			auto value = unwrap()->TextReadingOrder;
			auto context = get_context();
			auto result = context.CreateNumber(static_cast<int32_t>(static_cast<int>(value))); // FIXME What if the enum isn't an int based one?!

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBlock, TextLineBounds)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<::Windows::UI::Xaml::TextLineBounds>(static_cast<int32_t>(argument)); // TODO Look up enum in metadata to know what type it's value is? 


			unwrap()->TextLineBounds = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, TextLineBounds)
		{
			auto value = unwrap()->TextLineBounds;
			auto context = get_context();
			auto result = context.CreateNumber(static_cast<int32_t>(static_cast<int>(value))); // FIXME What if the enum isn't an int based one?!

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBlock, SelectionHighlightColor)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(argument);
			auto wrapper_value = object_value.GetPrivate<Windows::UI::Xaml::Media::SolidColorBrush>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_Media_SolidColorBrush();


			unwrap()->SelectionHighlightColor = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, SelectionHighlightColor)
		{
			auto value = unwrap()->SelectionHighlightColor;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::Media::SolidColorBrush>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::Media::SolidColorBrush>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBlock, MaxLines)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<int32_t>(argument);


			unwrap()->MaxLines = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, MaxLines)
		{
			auto value = unwrap()->MaxLines;
			auto context = get_context();
 			auto result = context.CreateNumber(value);

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBlock, IsColorFontEnabled)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsBoolean(), "Expected boolean");
			auto value = static_cast<bool>(argument);


			unwrap()->IsColorFontEnabled = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, IsColorFontEnabled)
		{
			auto value = unwrap()->IsColorFontEnabled;
			auto context = get_context();
 			auto result = context.CreateBoolean(value); 

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, SelectionHighlightColorProperty)
		{
			auto value = unwrap()->SelectionHighlightColorProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, IsColorFontEnabledProperty)
		{
			auto value = unwrap()->IsColorFontEnabledProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, MaxLinesProperty)
		{
			auto value = unwrap()->MaxLinesProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, OpticalMarginAlignmentProperty)
		{
			auto value = unwrap()->OpticalMarginAlignmentProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, TextLineBoundsProperty)
		{
			auto value = unwrap()->TextLineBoundsProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, TextReadingOrderProperty)
		{
			auto value = unwrap()->TextReadingOrderProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, CharacterSpacingProperty)
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

		TITANIUM_PROPERTY_GETTER(TextBlock, FontFamilyProperty)
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

		TITANIUM_PROPERTY_GETTER(TextBlock, FontSizeProperty)
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

		TITANIUM_PROPERTY_GETTER(TextBlock, FontStretchProperty)
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

		TITANIUM_PROPERTY_GETTER(TextBlock, FontStyleProperty)
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

		TITANIUM_PROPERTY_GETTER(TextBlock, FontWeightProperty)
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

		TITANIUM_PROPERTY_GETTER(TextBlock, ForegroundProperty)
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

		TITANIUM_PROPERTY_GETTER(TextBlock, IsTextSelectionEnabledProperty)
		{
			auto value = unwrap()->IsTextSelectionEnabledProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, LineHeightProperty)
		{
			auto value = unwrap()->LineHeightProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, LineStackingStrategyProperty)
		{
			auto value = unwrap()->LineStackingStrategyProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, PaddingProperty)
		{
			auto value = unwrap()->PaddingProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, SelectedTextProperty)
		{
			auto value = unwrap()->SelectedTextProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, TextAlignmentProperty)
		{
			auto value = unwrap()->TextAlignmentProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, TextProperty)
		{
			auto value = unwrap()->TextProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, TextTrimmingProperty)
		{
			auto value = unwrap()->TextTrimmingProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBlock, TextWrappingProperty)
		{
			auto value = unwrap()->TextWrappingProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_FUNCTION(TextBlock, SelectAll)
		{
			unwrap()->SelectAll();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TextBlock, Select)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_start = static_cast<JSObject>(_0);
			auto wrapper_start = object_start.GetPrivate<Windows::UI::Xaml::Documents::TextPointer>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto start = wrapper_start->unwrapWindows_UI_Xaml_Documents_TextPointer();


			auto _1 = arguments.at(1);
 			TITANIUM_ASSERT_AND_THROW(_1.IsObject(), "Expected Object");
			auto object_end = static_cast<JSObject>(_1);
			auto wrapper_end = object_end.GetPrivate<Windows::UI::Xaml::Documents::TextPointer>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto end = wrapper_end->unwrapWindows_UI_Xaml_Documents_TextPointer();


			unwrap()->Select(start, end);
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TextBlock, Focus)
		{
			auto _0 = arguments.at(0);
			TITANIUM_ASSERT_AND_THROW(_0.IsNumber(), "Expected Number");
			auto value = static_cast<::Windows::UI::Xaml::FocusState>(static_cast<int32_t>(_0)); // TODO Look up enum in metadata to know what type it's value is? 


			auto context = get_context();
			auto method_result = unwrap()->Focus(value);

 			auto result = context.CreateBoolean(method_result); 

			return result;
		}

				} // namespace Controls
			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
