/**
 * Windows Native Wrapper for Windows.UI.Core.CoreDispatcher
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Core.CoreDispatcher.hpp"
 // TODO Include the headers for all the native types we use in here! We'll have to go through type of every method arg, return type, type of every property

namespace Windows
{
	namespace UI
	{
		namespace Core
		{

		CoreDispatcher::CoreDispatcher(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
			: Titanium::Module(js_context, arguments)
		{
		}

		void CoreDispatcher::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
			wrapped__ = ref new Windows::UI::Core::CoreDispatcher();
		}

		Windows::UI::Core::CoreDispatcher^ CoreDispatcher::unwrapWindows_UI_Core_CoreDispatcher()
		{
			return dynamic_cast<Windows::UI::Core::CoreDispatcher^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		void CoreDispatcher::wrap(Windows::UI::Core::CoreDispatcher^ object)
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
			auto value = static_cast<int32_t>(argument); // TODO Look up enum in metadata to know what type it's value is? 
			wrapped__->CurrentPriority = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(CoreDispatcher, CurrentPriority)
		{
			auto value = wrapped__->CurrentPriority;
			auto context = get_context();
			return context.CreateNumber(value);
		}

		TITANIUM_PROPERTY_GETTER(CoreDispatcher, HasThreadAccess)
		{
			auto value = wrapped__->HasThreadAccess;
			auto context = get_context();
 			return context.CreateBoolean(value); 
		}

		TITANIUM_FUNCTION(CoreDispatcher, ProcessEvents)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->ProcessEvents();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(CoreDispatcher, RunAsync)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = wrapped__->RunAsync();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(CoreDispatcher, RunIdleAsync)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = wrapped__->RunIdleAsync();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(CoreDispatcher, ShouldYield)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = wrapped__->ShouldYield();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(CoreDispatcher, ShouldYield)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = wrapped__->ShouldYield();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(CoreDispatcher, StopProcessEvents)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->StopProcessEvents();
			return get_context().CreateUndefined(); 
		}

		} // namespace Core
	} // namespace UI
} // namespace Windows
