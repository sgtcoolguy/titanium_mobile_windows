/**
 * Windows Native Wrapper for Windows.UI.Core.CoreCursor
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Core.CoreCursor.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Core
			{

		CoreCursor::CoreCursor(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Module(js_context)
		{
		}

		void CoreCursor::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Core::CoreCursor^ CoreCursor::unwrapWindows_UI_Core_CoreCursor() const
		{
			return dynamic_cast<::Windows::UI::Core::CoreCursor^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		::Windows::UI::Core::CoreCursor^ CoreCursor::unwrap() const
		{
			return unwrapWindows_UI_Core_CoreCursor();
		}

		void CoreCursor::wrap(::Windows::UI::Core::CoreCursor^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void CoreCursor::JSExportInitialize()
		{
			JSExport<CoreCursor>::SetClassVersion(1);
			JSExport<CoreCursor>::SetParent(JSExport<Titanium::Module>::Class());

			TITANIUM_ADD_PROPERTY_READONLY(CoreCursor, Id);
			TITANIUM_ADD_PROPERTY_READONLY(CoreCursor, Type);
		}

		TITANIUM_PROPERTY_GETTER(CoreCursor, Id)
		{
			auto value = unwrap()->Id;
			auto context = get_context();
 			auto result = context.CreateNumber(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(CoreCursor, Type)
		{
			auto value = unwrap()->Type;
			auto context = get_context();
			auto result = context.CreateNumber(static_cast<int32_t>(static_cast<int>(value))); // FIXME What if the enum isn't an int based one?!

			return result;
		}

			} // namespace Core
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
