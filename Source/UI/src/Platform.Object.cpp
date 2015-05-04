/**
 * Windows Native Wrapper for Platform.Object
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Platform.Object.hpp"

namespace Titanium
{
	namespace Platform
	{

		Object::Object(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Module(js_context)
		{
		}

		void Object::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Platform::Object^ Object::unwrapPlatform_Object() const
		{
			return dynamic_cast<::Platform::Object^>(wrapped__);
		}

		::Platform::Object^ Object::unwrap() const
		{
			return unwrapPlatform_Object();
		}

		void Object::wrap(::Platform::Object^ object)
		{
			wrapped__ = object;
		}

		void Object::JSExportInitialize()
		{
			JSExport<Object>::SetClassVersion(1);
			JSExport<Object>::SetParent(JSExport<Module>::Class());

		}

	} // namespace Platform
} // namespace Titanium
