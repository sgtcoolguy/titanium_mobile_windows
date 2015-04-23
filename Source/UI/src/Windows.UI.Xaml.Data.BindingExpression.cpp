/**
 * Windows Native Wrapper for Windows.UI.Xaml.Data.BindingExpression
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.Data.Binding.hpp"
#include "Windows.UI.Xaml.Data.BindingExpression.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{
				namespace Data
				{

		BindingExpression::BindingExpression(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::Data::BindingExpressionBase(js_context)
		{
		}

		void BindingExpression::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::Data::BindingExpression^ BindingExpression::unwrapWindows_UI_Xaml_Data_BindingExpression() const
		{
			return dynamic_cast<::Windows::UI::Xaml::Data::BindingExpression^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		::Windows::UI::Xaml::Data::BindingExpression^ BindingExpression::unwrap() const
		{
			return unwrapWindows_UI_Xaml_Data_BindingExpression();
		}

		void BindingExpression::wrap(::Windows::UI::Xaml::Data::BindingExpression^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void BindingExpression::JSExportInitialize()
		{
			JSExport<BindingExpression>::SetClassVersion(1);
			JSExport<BindingExpression>::SetParent(JSExport<Windows::UI::Xaml::Data::BindingExpressionBase>::Class());

			TITANIUM_ADD_PROPERTY_READONLY(BindingExpression, DataItem);
			TITANIUM_ADD_PROPERTY_READONLY(BindingExpression, ParentBinding);
			TITANIUM_ADD_FUNCTION(BindingExpression, UpdateSource);
		}

		TITANIUM_PROPERTY_GETTER(BindingExpression, DataItem)
		{
			auto value = unwrap()->DataItem;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<object>::Class());
			auto result_wrapper = result.GetPrivate<object>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(BindingExpression, ParentBinding)
		{
			auto value = unwrap()->ParentBinding;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::Data::Binding>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::Data::Binding>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_FUNCTION(BindingExpression, UpdateSource)
		{
			unwrap()->UpdateSource();
			return get_context().CreateUndefined(); 
		}

				} // namespace Data
			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
