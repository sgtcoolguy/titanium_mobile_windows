/**
 * Windows Native Wrapper for Windows.Foundation.IAsyncAction
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.Foundation.AsyncActionCompletedHandler.hpp"
#include "Windows.Foundation.IAsyncAction.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace Foundation
		{

		IAsyncAction::IAsyncAction(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Module(js_context)
		{
		}

		void IAsyncAction::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::Foundation::IAsyncAction^ IAsyncAction::unwrapWindows_Foundation_IAsyncAction() const
		{
			return dynamic_cast<::Windows::Foundation::IAsyncAction^>(wrapped__);
		}

		::Windows::Foundation::IAsyncAction^ IAsyncAction::unwrap() const
		{
			return unwrapWindows_Foundation_IAsyncAction();
		}

		void IAsyncAction::wrap(::Windows::Foundation::IAsyncAction^ object)
		{
			wrapped__ = object;
		}

		void IAsyncAction::JSExportInitialize()
		{
			JSExport<IAsyncAction>::SetClassVersion(1);
			JSExport<IAsyncAction>::SetParent(JSExport<Titanium::Module>::Class());

			TITANIUM_ADD_PROPERTY(IAsyncAction, Completed);
			TITANIUM_ADD_FUNCTION(IAsyncAction, GetResults);
		}

		TITANIUM_PROPERTY_SETTER(IAsyncAction, Completed)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(argument);
			auto wrapper_value = object_value.GetPrivate<Windows::Foundation::AsyncActionCompletedHandler>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_Foundation_AsyncActionCompletedHandler();


			unwrap()->Completed = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(IAsyncAction, Completed)
		{
			auto value = unwrap()->Completed;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::Foundation::AsyncActionCompletedHandler>::Class());
			auto result_wrapper = result.GetPrivate<Windows::Foundation::AsyncActionCompletedHandler>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_FUNCTION(IAsyncAction, GetResults)
		{
			unwrap()->GetResults();
			return get_context().CreateUndefined(); 
		}

		} // namespace Foundation
	} // namespace Windows
} // namespace Titanium
