/**
 * Windows Native Wrapper for Windows.UI.Xaml.Documents.TextPointer
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.FrameworkElement.hpp"
#include "Windows.UI.Xaml.DependencyObject.hpp"
#include "Windows.UI.Xaml.Documents.TextPointer.hpp"

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

		TextPointer::TextPointer(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Platform::Object(js_context)
		{
		}

		void TextPointer::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::Documents::TextPointer^ TextPointer::unwrapWindows_UI_Xaml_Documents_TextPointer() const
		{
			return dynamic_cast<::Windows::UI::Xaml::Documents::TextPointer^>(wrapped__);
		}

		::Windows::UI::Xaml::Documents::TextPointer^ TextPointer::unwrap() const
		{
			return unwrapWindows_UI_Xaml_Documents_TextPointer();
		}

		void TextPointer::wrap(::Windows::UI::Xaml::Documents::TextPointer^ object)
		{
			wrapped__ = object;
		}

		void TextPointer::JSExportInitialize()
		{
			JSExport<TextPointer>::SetClassVersion(1);
			JSExport<TextPointer>::SetParent(JSExport<Titanium::Platform::Object>::Class());

			TITANIUM_ADD_PROPERTY_READONLY(TextPointer, LogicalDirection);
			TITANIUM_ADD_PROPERTY_READONLY(TextPointer, Offset);
			TITANIUM_ADD_PROPERTY_READONLY(TextPointer, Parent);
			TITANIUM_ADD_PROPERTY_READONLY(TextPointer, VisualParent);
			TITANIUM_ADD_FUNCTION(TextPointer, GetCharacterRect);
			TITANIUM_ADD_FUNCTION(TextPointer, GetPositionAtOffset);
		}

		TITANIUM_PROPERTY_GETTER(TextPointer, LogicalDirection)
		{
			auto value = unwrap()->LogicalDirection;
			auto context = get_context();
			auto result = context.CreateNumber(static_cast<int32_t>(static_cast<int>(value))); // FIXME What if the enum isn't an int based one?!

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextPointer, Offset)
		{
			auto value = unwrap()->Offset;
			auto context = get_context();
 			auto result = context.CreateNumber(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextPointer, Parent)
		{
			auto value = unwrap()->Parent;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyObject>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyObject>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextPointer, VisualParent)
		{
			auto value = unwrap()->VisualParent;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::FrameworkElement>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::FrameworkElement>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_FUNCTION(TextPointer, GetCharacterRect)
		{
			auto _0 = arguments.at(0);
			TITANIUM_ASSERT_AND_THROW(_0.IsNumber(), "Expected Number");
			auto direction = static_cast<::Windows::UI::Xaml::Documents::LogicalDirection>(static_cast<int32_t>(_0)); // TODO Look up enum in metadata to know what type it's value is? 


			auto context = get_context();
			auto method_result = unwrap()->GetCharacterRect(direction);

			auto result = context.CreateObject();
			result.SetProperty("X", context.CreateNumber(static_cast<double>(method_result.X)));
			result.SetProperty("Y", context.CreateNumber(static_cast<double>(method_result.Y)));
			result.SetProperty("Width", context.CreateNumber(static_cast<double>(method_result.Width)));
			result.SetProperty("Height", context.CreateNumber(static_cast<double>(method_result.Height)));

			return result;
		}

		TITANIUM_FUNCTION(TextPointer, GetPositionAtOffset)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsNumber(), "Expected Number");
			auto offset = static_cast<int32_t>(_0);


			auto _1 = arguments.at(1);
			TITANIUM_ASSERT_AND_THROW(_1.IsNumber(), "Expected Number");
			auto direction = static_cast<::Windows::UI::Xaml::Documents::LogicalDirection>(static_cast<int32_t>(_1)); // TODO Look up enum in metadata to know what type it's value is? 


			auto context = get_context();
			auto method_result = unwrap()->GetPositionAtOffset(offset, direction);

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::Documents::TextPointer>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::Documents::TextPointer>();
			result_wrapper->wrap(method_result);

			return result;
		}

				} // namespace Documents
			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
