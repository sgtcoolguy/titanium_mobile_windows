/**
 * Windows Native Wrapper for Windows.Foundation.WwwFormUrlDecoder
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.Foundation.IWwwFormUrlDecoderEntry[].hpp"
#include "Windows.Foundation.IWwwFormUrlDecoderEntry.hpp"
#include "Windows.Foundation.Collections.IIterator`1&lt;class Windows.Foundation.IWwwFormUrlDecoderEntry&gt;.hpp"
#include "Windows.Foundation.WwwFormUrlDecoder.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace Foundation
		{

		WwwFormUrlDecoder::WwwFormUrlDecoder(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Module(js_context)
		{
		}

		void WwwFormUrlDecoder::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::Foundation::WwwFormUrlDecoder^ WwwFormUrlDecoder::unwrapWindows_Foundation_WwwFormUrlDecoder() const
		{
			return dynamic_cast<::Windows::Foundation::WwwFormUrlDecoder^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		::Windows::Foundation::WwwFormUrlDecoder^ WwwFormUrlDecoder::unwrap() const
		{
			return unwrapWindows_Foundation_WwwFormUrlDecoder();
		}

		void WwwFormUrlDecoder::wrap(::Windows::Foundation::WwwFormUrlDecoder^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void WwwFormUrlDecoder::JSExportInitialize()
		{
			JSExport<WwwFormUrlDecoder>::SetClassVersion(1);
			JSExport<WwwFormUrlDecoder>::SetParent(JSExport<Titanium::Module>::Class());

			TITANIUM_ADD_PROPERTY_READONLY(WwwFormUrlDecoder, Size);
			TITANIUM_ADD_FUNCTION(WwwFormUrlDecoder, GetFirstValueByName);
			TITANIUM_ADD_FUNCTION(WwwFormUrlDecoder, First);
			TITANIUM_ADD_FUNCTION(WwwFormUrlDecoder, GetAt);
			TITANIUM_ADD_FUNCTION(WwwFormUrlDecoder, IndexOf);
			TITANIUM_ADD_FUNCTION(WwwFormUrlDecoder, GetMany);
		}

		TITANIUM_PROPERTY_GETTER(WwwFormUrlDecoder, Size)
		{
			auto value = unwrap()->Size;
			auto context = get_context();
 			auto result = context.CreateNumber(value);

			return result;
		}

		TITANIUM_FUNCTION(WwwFormUrlDecoder, GetFirstValueByName)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsString(), "Expected String");
			auto name = TitaniumWindows::Utility::ConvertUTF8String(static_cast<std::string>(_0));


			auto context = get_context();
			auto method_result = unwrap()->GetFirstValueByName(name);

 			auto result = context.CreateString(TitaniumWindows::Utility::ConvertUTF8String(method_result));


			return result; 
		}

		TITANIUM_FUNCTION(WwwFormUrlDecoder, First)
		{
			auto context = get_context();
			auto method_result = unwrap()->First();

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::Foundation::Collections::IIterator`1&lt;class Windows::Foundation::IWwwFormUrlDecoderEntry&gt;>::Class());
			auto result_wrapper = result.GetPrivate<Windows::Foundation::Collections::IIterator`1&lt;class Windows::Foundation::IWwwFormUrlDecoderEntry&gt;>();
			result_wrapper->wrap(method_result);


			return result; 
		}

		TITANIUM_FUNCTION(WwwFormUrlDecoder, GetAt)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsNumber(), "Expected Number");
			auto index = static_cast<uint32_t>(_0);


			auto context = get_context();
			auto method_result = unwrap()->GetAt(index);

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::Foundation::IWwwFormUrlDecoderEntry>::Class());
			auto result_wrapper = result.GetPrivate<Windows::Foundation::IWwwFormUrlDecoderEntry>();
			result_wrapper->wrap(method_result);


			return result; 
		}

		TITANIUM_FUNCTION(WwwFormUrlDecoder, IndexOf)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(_0);
			auto wrapper_value = object_value.GetPrivate<Windows::Foundation::IWwwFormUrlDecoderEntry>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_Foundation_IWwwFormUrlDecoderEntry();


			auto _1 = arguments.at(1);
 			TITANIUM_ASSERT_AND_THROW(_1.IsObject(), "Expected Object");
			auto object_index = static_cast<JSObject>(_1);
			auto wrapper_index = object_index.GetPrivate<uint32&amp;>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto index = wrapper_index->unwrapuint32&amp;();


			auto context = get_context();
			auto method_result = unwrap()->IndexOf(value, index);

 			auto result = context.CreateBoolean(method_result); 


			return result; 
		}

		TITANIUM_FUNCTION(WwwFormUrlDecoder, GetMany)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsNumber(), "Expected Number");
			auto startIndex = static_cast<uint32_t>(_0);


			auto _1 = arguments.at(1);
 			TITANIUM_ASSERT_AND_THROW(_1.IsObject(), "Expected Object");
			auto object_items = static_cast<JSObject>(_1);
			auto wrapper_items = object_items.GetPrivate<Windows::Foundation::IWwwFormUrlDecoderEntry[]>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto items = wrapper_items->unwrapWindows_Foundation_IWwwFormUrlDecoderEntry[]();


			auto context = get_context();
			auto method_result = unwrap()->GetMany(startIndex, items);

 			auto result = context.CreateNumber(method_result);


			return result; 
		}

		} // namespace Foundation
	} // namespace Windows
} // namespace Titanium
