/**
 * Windows Native Wrapper for Windows.UI.Core.CoreDispatcher
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Core.IdleDispatchedHandler.hpp"
#include "Windows.UI.Core.DispatchedHandler.hpp"
#include "Windows.Foundation.IAsyncAction.hpp"
#include "Windows.UI.Core.CoreDispatcher.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Core
			{

		CoreDispatcher::CoreDispatcher(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Module(js_context)
		{
		}

		void CoreDispatcher::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
			wrapped__ = ref new ::Windows::UI::Core::CoreDispatcher();
		}

		::Windows::UI::Core::CoreDispatcher^ CoreDispatcher::unwrapWindows_UI_Core_CoreDispatcher() const
		{
			return dynamic_cast<::Windows::UI::Core::CoreDispatcher^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		::Windows::UI::Core::CoreDispatcher^ CoreDispatcher::unwrap() const
		{
			return unwrapWindows_UI_Core_CoreDispatcher();
		}

		void CoreDispatcher::wrap(::Windows::UI::Core::CoreDispatcher^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void CoreDispatcher::JSExportInitialize()
		{
			JSExport<CoreDispatcher>::SetClassVersion(1);
			JSExport<CoreDispatcher>::SetParent(JSExport<Titanium::Module>::Class());

			TITANIUM_ADD_PROPERTY(CoreDispatcher, CurrentPriority);
			TITANIUM_ADD_PROPERTY_READONLY(CoreDispatcher, HasThreadAccess);
			TITANIUM_ADD_FUNCTION(CoreDispatcher, ProcessEvents);
			TITANIUM_ADD_FUNCTION(CoreDispatcher, RunAsync);
			TITANIUM_ADD_FUNCTION(CoreDispatcher, RunIdleAsync);
			TITANIUM_ADD_FUNCTION(CoreDispatcher, ShouldYield);
			TITANIUM_ADD_FUNCTION(CoreDispatcher, ShouldYield);
			TITANIUM_ADD_FUNCTION(CoreDispatcher, StopProcessEvents);
		}

		TITANIUM_PROPERTY_SETTER(CoreDispatcher, CurrentPriority)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<::Windows::UI::Core::CoreDispatcherPriority>(static_cast<int32_t>(argument)); // TODO Look up enum in metadata to know what type it's value is? 
			unwrap()->CurrentPriority = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(CoreDispatcher, CurrentPriority)
		{
			auto value = unwrap()->CurrentPriority;
			auto context = get_context();
			return context.CreateNumber(static_cast<int32_t>(static_cast<int>(value))); // FIXME What if the enum isn't an int based one?!
		}

		TITANIUM_PROPERTY_GETTER(CoreDispatcher, HasThreadAccess)
		{
			auto value = unwrap()->HasThreadAccess;
			auto context = get_context();
 			return context.CreateBoolean(value); 
		}

		TITANIUM_FUNCTION(CoreDispatcher, ProcessEvents)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			unwrap()->ProcessEvents();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(CoreDispatcher, RunAsync)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = unwrap()->RunAsync();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(CoreDispatcher, RunIdleAsync)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = unwrap()->RunIdleAsync();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(CoreDispatcher, ShouldYield)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = unwrap()->ShouldYield();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(CoreDispatcher, ShouldYield)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = unwrap()->ShouldYield();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(CoreDispatcher, StopProcessEvents)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			unwrap()->StopProcessEvents();
			return get_context().CreateUndefined(); 
		}

			} // namespace Core
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
