/**
 * Windows Native Wrapper for Windows.Foundation.Collections.IPropertySet
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.Foundation.Collections.IPropertySet.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace Foundation
		{
			namespace Collections
			{

		IPropertySet::IPropertySet(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Module(js_context)
		{
		}

		void IPropertySet::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::Foundation::Collections::IPropertySet^ IPropertySet::unwrapWindows_Foundation_Collections_IPropertySet() const
		{
			return dynamic_cast<::Windows::Foundation::Collections::IPropertySet^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		::Windows::Foundation::Collections::IPropertySet^ IPropertySet::unwrap() const
		{
			return unwrapWindows_Foundation_Collections_IPropertySet();
		}

		void IPropertySet::wrap(::Windows::Foundation::Collections::IPropertySet^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void IPropertySet::JSExportInitialize()
		{
			JSExport<IPropertySet>::SetClassVersion(1);
			JSExport<IPropertySet>::SetParent(JSExport<Titanium::Module>::Class());

		}

			} // namespace Collections
		} // namespace Foundation
	} // namespace Windows
} // namespace Titanium
