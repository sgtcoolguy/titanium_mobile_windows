/**
 * Windows Native Wrapper for Windows.UI.Xaml.Media.Animation.TransitionCollection
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.Media.Animation.TransitionCollection.hpp"
 // TODO Include the headers for all the native types we use in here! We'll have to go through type of every method arg, return type, type of every property

namespace Windows
{
	namespace UI
	{
		namespace Xaml
		{
			namespace Media
			{
				namespace Animation
				{

		TransitionCollection::TransitionCollection(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
			: Titanium::Module(js_context, arguments)
		{
		}

		void TransitionCollection::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
			wrapped__ = ref new Windows::UI::Xaml::Media::Animation::TransitionCollection();
		}

		Windows::UI::Xaml::Media::Animation::TransitionCollection^ TransitionCollection::unwrapWindows_UI_Xaml_Media_Animation_TransitionCollection()
		{
			return dynamic_cast<Windows::UI::Xaml::Media::Animation::TransitionCollection^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		void TransitionCollection::wrap(Windows::UI::Xaml::Media::Animation::TransitionCollection^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void TransitionCollection::JSExportInitialize()
		{
			JSExport<TransitionCollection>::SetClassVersion(1);
			JSExport<TransitionCollection>::SetParent(JSExport<Titanium::Module>::Class());

			TITANIUM_ADD_PROPERTY_READONLY(TransitionCollection, Size);
			TITANIUM_ADD_FUNCTION(TransitionCollection, GetAt);
			TITANIUM_ADD_FUNCTION(TransitionCollection, GetView);
			TITANIUM_ADD_FUNCTION(TransitionCollection, IndexOf);
			TITANIUM_ADD_FUNCTION(TransitionCollection, SetAt);
			TITANIUM_ADD_FUNCTION(TransitionCollection, InsertAt);
			TITANIUM_ADD_FUNCTION(TransitionCollection, RemoveAt);
			TITANIUM_ADD_FUNCTION(TransitionCollection, Append);
			TITANIUM_ADD_FUNCTION(TransitionCollection, RemoveAtEnd);
			TITANIUM_ADD_FUNCTION(TransitionCollection, Clear);
			TITANIUM_ADD_FUNCTION(TransitionCollection, GetMany);
			TITANIUM_ADD_FUNCTION(TransitionCollection, ReplaceAll);
			TITANIUM_ADD_FUNCTION(TransitionCollection, First);
		}

		TITANIUM_PROPERTY_GETTER(TransitionCollection, Size)
		{
			auto value = wrapped__->Size;
			auto context = get_context();
 			return context.CreateNumber(value);
		}

		TITANIUM_FUNCTION(TransitionCollection, GetAt)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = wrapped__->GetAt();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(TransitionCollection, GetView)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = wrapped__->GetView();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(TransitionCollection, IndexOf)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = wrapped__->IndexOf();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(TransitionCollection, SetAt)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->SetAt();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TransitionCollection, InsertAt)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->InsertAt();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TransitionCollection, RemoveAt)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->RemoveAt();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TransitionCollection, Append)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->Append();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TransitionCollection, RemoveAtEnd)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->RemoveAtEnd();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TransitionCollection, Clear)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->Clear();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TransitionCollection, GetMany)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = wrapped__->GetMany();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(TransitionCollection, ReplaceAll)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->ReplaceAll();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TransitionCollection, First)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = wrapped__->First();
			return get_context().CreateBoolean(result); 
		}

				} // namespace Animation
			} // namespace Media
		} // namespace Xaml
	} // namespace UI
} // namespace Windows
