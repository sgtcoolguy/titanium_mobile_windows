/**
 * Windows Native Wrapper for Windows.UI.Xaml.Controls.Frame
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.Media.Animation.NavigationTransitionInfo.hpp"
#include "Windows.UI.Xaml.DependencyProperty.hpp"
#include "Windows.Foundation.Collections.IVector`1&lt;class Windows.UI.Xaml.Navigation.PageStackEntry&gt;.hpp"
#include "Windows.UI.Xaml.Controls.Frame.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{
				namespace Controls
				{

		Frame::Frame(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::Controls::ContentControl(js_context)
		{
		}

		void Frame::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::Controls::Frame^ Frame::unwrapWindows_UI_Xaml_Controls_Frame() const
		{
			return dynamic_cast<::Windows::UI::Xaml::Controls::Frame^>(wrapped__);
		}

		::Windows::UI::Xaml::Controls::Frame^ Frame::unwrap() const
		{
			return unwrapWindows_UI_Xaml_Controls_Frame();
		}

		void Frame::wrap(::Windows::UI::Xaml::Controls::Frame^ object)
		{
			wrapped__ = object;
		}

		void Frame::JSExportInitialize()
		{
			JSExport<Frame>::SetClassVersion(1);
			JSExport<Frame>::SetParent(JSExport<Windows::UI::Xaml::Controls::ContentControl>::Class());

			TITANIUM_ADD_PROPERTY(Frame, SourcePageType);
			TITANIUM_ADD_PROPERTY(Frame, CacheSize);
			TITANIUM_ADD_PROPERTY_READONLY(Frame, BackStackDepth);
			TITANIUM_ADD_PROPERTY_READONLY(Frame, CanGoBack);
			TITANIUM_ADD_PROPERTY_READONLY(Frame, CanGoForward);
			TITANIUM_ADD_PROPERTY_READONLY(Frame, CurrentSourcePageType);
			TITANIUM_ADD_PROPERTY_READONLY(Frame, BackStack);
			TITANIUM_ADD_PROPERTY_READONLY(Frame, ForwardStack);
			TITANIUM_ADD_PROPERTY_READONLY(Frame, BackStackProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Frame, ForwardStackProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Frame, BackStackDepthProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Frame, CacheSizeProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Frame, CanGoBackProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Frame, CanGoForwardProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Frame, CurrentSourcePageTypeProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Frame, SourcePageTypeProperty);
			TITANIUM_ADD_FUNCTION(Frame, GoBack);
			TITANIUM_ADD_FUNCTION(Frame, GoForward);
			TITANIUM_ADD_FUNCTION(Frame, Navigate);
			TITANIUM_ADD_FUNCTION(Frame, GetNavigationState);
			TITANIUM_ADD_FUNCTION(Frame, SetNavigationState);
			TITANIUM_ADD_FUNCTION(Frame, Navigate);
			TITANIUM_ADD_FUNCTION(Frame, Navigate);
		}

		TITANIUM_PROPERTY_SETTER(Frame, SourcePageType)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(argument);
			auto value = ::Windows::UI::Xaml::Interop::TypeName(NaN0);
			// Assign fields explicitly since we cheated on constructor args
			auto Name = object_value.GetProperty("Name");
			value.Name = static_cast<int32_t>(Name);
			auto Kind = object_value.GetProperty("Kind");
			value.Kind = static_cast<int32_t>(Kind);


			unwrap()->SourcePageType = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Frame, SourcePageType)
		{
			auto value = unwrap()->SourcePageType;
			auto context = get_context();
			auto result = context.CreateObject();
			result.SetProperty("Name", context.CreateNumber(static_cast<int32_t>(value.Name)));
			result.SetProperty("Kind", context.CreateNumber(static_cast<int32_t>(value.Kind)));

			return result;
		}

		TITANIUM_PROPERTY_SETTER(Frame, CacheSize)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<int32_t>(argument);


			unwrap()->CacheSize = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Frame, CacheSize)
		{
			auto value = unwrap()->CacheSize;
			auto context = get_context();
 			auto result = context.CreateNumber(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Frame, BackStackDepth)
		{
			auto value = unwrap()->BackStackDepth;
			auto context = get_context();
 			auto result = context.CreateNumber(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Frame, CanGoBack)
		{
			auto value = unwrap()->CanGoBack;
			auto context = get_context();
 			auto result = context.CreateBoolean(value); 

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Frame, CanGoForward)
		{
			auto value = unwrap()->CanGoForward;
			auto context = get_context();
 			auto result = context.CreateBoolean(value); 

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Frame, CurrentSourcePageType)
		{
			auto value = unwrap()->CurrentSourcePageType;
			auto context = get_context();
			auto result = context.CreateObject();
			result.SetProperty("Name", context.CreateNumber(static_cast<int32_t>(value.Name)));
			result.SetProperty("Kind", context.CreateNumber(static_cast<int32_t>(value.Kind)));

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Frame, BackStack)
		{
			auto value = unwrap()->BackStack;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::Foundation::Collections::IVector`1<class Windows::UI::Xaml::Navigation::PageStackEntry>>::Class());
			auto result_wrapper = result.GetPrivate<Windows::Foundation::Collections::IVector`1<class Windows::UI::Xaml::Navigation::PageStackEntry>>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Frame, ForwardStack)
		{
			auto value = unwrap()->ForwardStack;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::Foundation::Collections::IVector`1<class Windows::UI::Xaml::Navigation::PageStackEntry>>::Class());
			auto result_wrapper = result.GetPrivate<Windows::Foundation::Collections::IVector`1<class Windows::UI::Xaml::Navigation::PageStackEntry>>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Frame, BackStackProperty)
		{
			auto value = unwrap()->BackStackProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Frame, ForwardStackProperty)
		{
			auto value = unwrap()->ForwardStackProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Frame, BackStackDepthProperty)
		{
			auto value = unwrap()->BackStackDepthProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Frame, CacheSizeProperty)
		{
			auto value = unwrap()->CacheSizeProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Frame, CanGoBackProperty)
		{
			auto value = unwrap()->CanGoBackProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Frame, CanGoForwardProperty)
		{
			auto value = unwrap()->CanGoForwardProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Frame, CurrentSourcePageTypeProperty)
		{
			auto value = unwrap()->CurrentSourcePageTypeProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Frame, SourcePageTypeProperty)
		{
			auto value = unwrap()->SourcePageTypeProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_FUNCTION(Frame, GoBack)
		{
			unwrap()->GoBack();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Frame, GoForward)
		{
			unwrap()->GoForward();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Frame, Navigate)
		{
			auto _0 = arguments.at(0);
			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_sourcePageType = static_cast<JSObject>(_0);
			auto sourcePageType = ::Windows::UI::Xaml::Interop::TypeName(NaN0);
			// Assign fields explicitly since we cheated on constructor args
			auto Name = object_sourcePageType.GetProperty("Name");
			sourcePageType.Name = static_cast<int32_t>(Name);
			auto Kind = object_sourcePageType.GetProperty("Kind");
			sourcePageType.Kind = static_cast<int32_t>(Kind);


			auto _1 = arguments.at(1);
 			TITANIUM_ASSERT_AND_THROW(_1.IsObject(), "Expected Object");
			auto object_parameter = static_cast<JSObject>(_1);
			auto wrapper_parameter = object_parameter.GetPrivate<Titanium::Module>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto parameter = wrapper_parameter->unwrapTitanium_Module();


			auto context = get_context();
			auto method_result = unwrap()->Navigate(sourcePageType, parameter);

 			auto result = context.CreateBoolean(method_result); 

			return result;
		}

		TITANIUM_FUNCTION(Frame, GetNavigationState)
		{
			auto context = get_context();
			auto method_result = unwrap()->GetNavigationState();

 			auto result = context.CreateString(TitaniumWindows::Utility::ConvertUTF8String(method_result));

			return result;
		}

		TITANIUM_FUNCTION(Frame, SetNavigationState)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsString(), "Expected String");
			auto navigationState = TitaniumWindows::Utility::ConvertUTF8String(static_cast<std::string>(_0));


			unwrap()->SetNavigationState(navigationState);
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Frame, Navigate)
		{
			auto _0 = arguments.at(0);
			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_sourcePageType = static_cast<JSObject>(_0);
			auto sourcePageType = ::Windows::UI::Xaml::Interop::TypeName(NaN0);
			// Assign fields explicitly since we cheated on constructor args
			auto Name = object_sourcePageType.GetProperty("Name");
			sourcePageType.Name = static_cast<int32_t>(Name);
			auto Kind = object_sourcePageType.GetProperty("Kind");
			sourcePageType.Kind = static_cast<int32_t>(Kind);


			auto _1 = arguments.at(1);
 			TITANIUM_ASSERT_AND_THROW(_1.IsObject(), "Expected Object");
			auto object_parameter = static_cast<JSObject>(_1);
			auto wrapper_parameter = object_parameter.GetPrivate<Titanium::Module>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto parameter = wrapper_parameter->unwrapTitanium_Module();


			auto _2 = arguments.at(2);
 			TITANIUM_ASSERT_AND_THROW(_2.IsObject(), "Expected Object");
			auto object_infoOverride = static_cast<JSObject>(_2);
			auto wrapper_infoOverride = object_infoOverride.GetPrivate<Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto infoOverride = wrapper_infoOverride->unwrapWindows_UI_Xaml_Media_Animation_NavigationTransitionInfo();


			auto context = get_context();
			auto method_result = unwrap()->Navigate(sourcePageType, parameter, infoOverride);

 			auto result = context.CreateBoolean(method_result); 

			return result;
		}

		TITANIUM_FUNCTION(Frame, Navigate)
		{
			auto _0 = arguments.at(0);
			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_sourcePageType = static_cast<JSObject>(_0);
			auto sourcePageType = ::Windows::UI::Xaml::Interop::TypeName(NaN0);
			// Assign fields explicitly since we cheated on constructor args
			auto Name = object_sourcePageType.GetProperty("Name");
			sourcePageType.Name = static_cast<int32_t>(Name);
			auto Kind = object_sourcePageType.GetProperty("Kind");
			sourcePageType.Kind = static_cast<int32_t>(Kind);


			auto context = get_context();
			auto method_result = unwrap()->Navigate(sourcePageType);

 			auto result = context.CreateBoolean(method_result); 

			return result;
		}

				} // namespace Controls
			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
