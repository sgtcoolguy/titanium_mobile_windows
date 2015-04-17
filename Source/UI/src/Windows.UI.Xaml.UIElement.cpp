/**
 * Windows Native Wrapper for Windows.UI.Xaml.UIElement
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.UIElement.hpp"
 // TODO Include the headers for all the native types we use in here! We'll have to go through type of every method arg, return type, type of every property

namespace Windows
{
	namespace UI
	{
		namespace Xaml
		{

		UIElement::UIElement(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::DependencyObject(js_context, arguments)
		{
		}

		void UIElement::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
			wrapped__ = ref new Windows::UI::Xaml::UIElement();
		}

		Windows::UI::Xaml::UIElement^ UIElement::unwrapWindows_UI_Xaml_UIElement()
		{
			return dynamic_cast<Windows::UI::Xaml::UIElement^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		void UIElement::wrap(Windows::UI::Xaml::UIElement^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void UIElement::JSExportInitialize()
		{
			JSExport<UIElement>::SetClassVersion(1);
			JSExport<UIElement>::SetParent(JSExport<Windows::UI::Xaml::DependencyObject>::Class());

			TITANIUM_ADD_PROPERTY(UIElement, CompositeMode);
			TITANIUM_ADD_PROPERTY(UIElement, IsTapEnabled);
			TITANIUM_ADD_PROPERTY(UIElement, IsRightTapEnabled);
			TITANIUM_ADD_PROPERTY(UIElement, IsHoldingEnabled);
			TITANIUM_ADD_PROPERTY(UIElement, IsHitTestVisible);
			TITANIUM_ADD_PROPERTY(UIElement, IsDoubleTapEnabled);
			TITANIUM_ADD_PROPERTY(UIElement, ManipulationMode);
			TITANIUM_ADD_PROPERTY(UIElement, Clip);
			TITANIUM_ADD_PROPERTY(UIElement, CacheMode);
			TITANIUM_ADD_PROPERTY(UIElement, AllowDrop);
			TITANIUM_ADD_PROPERTY(UIElement, Visibility);
			TITANIUM_ADD_PROPERTY(UIElement, UseLayoutRounding);
			TITANIUM_ADD_PROPERTY(UIElement, Transitions);
			TITANIUM_ADD_PROPERTY(UIElement, RenderTransformOrigin);
			TITANIUM_ADD_PROPERTY(UIElement, RenderTransform);
			TITANIUM_ADD_PROPERTY(UIElement, Projection);
			TITANIUM_ADD_PROPERTY(UIElement, Opacity);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, PointerCaptures);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, RenderSize);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, DesiredSize);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, CompositeModeProperty);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, AllowDropProperty);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, CacheModeProperty);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, ClipProperty);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, DoubleTappedEvent);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, DragEnterEvent);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, DragLeaveEvent);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, DragOverEvent);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, DropEvent);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, HoldingEvent);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, IsDoubleTapEnabledProperty);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, IsHitTestVisibleProperty);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, IsHoldingEnabledProperty);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, IsRightTapEnabledProperty);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, IsTapEnabledProperty);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, KeyDownEvent);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, KeyUpEvent);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, ManipulationCompletedEvent);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, ManipulationDeltaEvent);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, ManipulationInertiaStartingEvent);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, ManipulationModeProperty);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, ManipulationStartedEvent);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, ManipulationStartingEvent);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, OpacityProperty);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, PointerCanceledEvent);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, PointerCaptureLostEvent);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, PointerCapturesProperty);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, PointerEnteredEvent);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, PointerExitedEvent);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, PointerMovedEvent);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, PointerPressedEvent);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, PointerReleasedEvent);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, PointerWheelChangedEvent);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, ProjectionProperty);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, RenderTransformOriginProperty);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, RenderTransformProperty);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, RightTappedEvent);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, TappedEvent);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, TransitionsProperty);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, UseLayoutRoundingProperty);
			TITANIUM_ADD_PROPERTY_READONLY(UIElement, VisibilityProperty);
			TITANIUM_ADD_FUNCTION(UIElement, Measure);
			TITANIUM_ADD_FUNCTION(UIElement, Arrange);
			TITANIUM_ADD_FUNCTION(UIElement, CapturePointer);
			TITANIUM_ADD_FUNCTION(UIElement, ReleasePointerCapture);
			TITANIUM_ADD_FUNCTION(UIElement, ReleasePointerCaptures);
			TITANIUM_ADD_FUNCTION(UIElement, AddHandler);
			TITANIUM_ADD_FUNCTION(UIElement, RemoveHandler);
			TITANIUM_ADD_FUNCTION(UIElement, TransformToVisual);
			TITANIUM_ADD_FUNCTION(UIElement, InvalidateMeasure);
			TITANIUM_ADD_FUNCTION(UIElement, InvalidateArrange);
			TITANIUM_ADD_FUNCTION(UIElement, UpdateLayout);
			TITANIUM_ADD_FUNCTION(UIElement, CancelDirectManipulations);
			TITANIUM_ADD_FUNCTION(UIElement, OnCreateAutomationPeer);
			TITANIUM_ADD_FUNCTION(UIElement, OnDisconnectVisualChildren);
			TITANIUM_ADD_FUNCTION(UIElement, FindSubElementsForTouchTargeting);
		}

		TITANIUM_PROPERTY_SETTER(UIElement, CompositeMode)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<int32_t>(argument); // TODO Look up enum in metadata to know what type it's value is? 
			wrapped__->CompositeMode = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, CompositeMode)
		{
			auto value = wrapped__->CompositeMode;
			auto context = get_context();
			return context.CreateNumber(value);
		}

		TITANIUM_PROPERTY_SETTER(UIElement, IsTapEnabled)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsBoolean(), "Expected boolean");
			auto value = static_cast<bool>(argument);
			wrapped__->IsTapEnabled = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, IsTapEnabled)
		{
			auto value = wrapped__->IsTapEnabled;
			auto context = get_context();
 			return context.CreateBoolean(value); 
		}

		TITANIUM_PROPERTY_SETTER(UIElement, IsRightTapEnabled)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsBoolean(), "Expected boolean");
			auto value = static_cast<bool>(argument);
			wrapped__->IsRightTapEnabled = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, IsRightTapEnabled)
		{
			auto value = wrapped__->IsRightTapEnabled;
			auto context = get_context();
 			return context.CreateBoolean(value); 
		}

		TITANIUM_PROPERTY_SETTER(UIElement, IsHoldingEnabled)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsBoolean(), "Expected boolean");
			auto value = static_cast<bool>(argument);
			wrapped__->IsHoldingEnabled = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, IsHoldingEnabled)
		{
			auto value = wrapped__->IsHoldingEnabled;
			auto context = get_context();
 			return context.CreateBoolean(value); 
		}

		TITANIUM_PROPERTY_SETTER(UIElement, IsHitTestVisible)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsBoolean(), "Expected boolean");
			auto value = static_cast<bool>(argument);
			wrapped__->IsHitTestVisible = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, IsHitTestVisible)
		{
			auto value = wrapped__->IsHitTestVisible;
			auto context = get_context();
 			return context.CreateBoolean(value); 
		}

		TITANIUM_PROPERTY_SETTER(UIElement, IsDoubleTapEnabled)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsBoolean(), "Expected boolean");
			auto value = static_cast<bool>(argument);
			wrapped__->IsDoubleTapEnabled = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, IsDoubleTapEnabled)
		{
			auto value = wrapped__->IsDoubleTapEnabled;
			auto context = get_context();
 			return context.CreateBoolean(value); 
		}

		TITANIUM_PROPERTY_SETTER(UIElement, ManipulationMode)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<int32_t>(argument); // TODO Look up enum in metadata to know what type it's value is? 
			wrapped__->ManipulationMode = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, ManipulationMode)
		{
			auto value = wrapped__->ManipulationMode;
			auto context = get_context();
			return context.CreateNumber(value);
		}

		TITANIUM_PROPERTY_SETTER(UIElement, Clip)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<Windows::UI::Xaml::Media::RectangleGeometry>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrapWindows_UI_Xaml_Media_RectangleGeometry();
			wrapped__->Clip = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, Clip)
		{
			auto value = wrapped__->Clip;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::Media::RectangleGeometry>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::Media::RectangleGeometry>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_SETTER(UIElement, CacheMode)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<Windows::UI::Xaml::Media::CacheMode>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrapWindows_UI_Xaml_Media_CacheMode();
			wrapped__->CacheMode = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, CacheMode)
		{
			auto value = wrapped__->CacheMode;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::Media::CacheMode>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::Media::CacheMode>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_SETTER(UIElement, AllowDrop)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsBoolean(), "Expected boolean");
			auto value = static_cast<bool>(argument);
			wrapped__->AllowDrop = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, AllowDrop)
		{
			auto value = wrapped__->AllowDrop;
			auto context = get_context();
 			return context.CreateBoolean(value); 
		}

		TITANIUM_PROPERTY_SETTER(UIElement, Visibility)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<int32_t>(argument); // TODO Look up enum in metadata to know what type it's value is? 
			wrapped__->Visibility = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, Visibility)
		{
			auto value = wrapped__->Visibility;
			auto context = get_context();
			return context.CreateNumber(value);
		}

		TITANIUM_PROPERTY_SETTER(UIElement, UseLayoutRounding)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsBoolean(), "Expected boolean");
			auto value = static_cast<bool>(argument);
			wrapped__->UseLayoutRounding = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, UseLayoutRounding)
		{
			auto value = wrapped__->UseLayoutRounding;
			auto context = get_context();
 			return context.CreateBoolean(value); 
		}

		TITANIUM_PROPERTY_SETTER(UIElement, Transitions)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<Windows::UI::Xaml::Media::Animation::TransitionCollection>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrapWindows_UI_Xaml_Media_Animation_TransitionCollection();
			wrapped__->Transitions = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, Transitions)
		{
			auto value = wrapped__->Transitions;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::Media::Animation::TransitionCollection>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::Media::Animation::TransitionCollection>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_SETTER(UIElement, RenderTransformOrigin)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto value = ref new Windows::Foundation::Point(0, 0);
			wrapped__->RenderTransformOrigin = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, RenderTransformOrigin)
		{
			auto value = wrapped__->RenderTransformOrigin;
			auto context = get_context();
			auto result = context.CreateObject();
			result.SetProperty("X", context.CreateNumber(static_cast<double>(value.X)));
			result.SetProperty("Y", context.CreateNumber(static_cast<double>(value.Y)));
			return result; 
		}

		TITANIUM_PROPERTY_SETTER(UIElement, RenderTransform)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<Windows::UI::Xaml::Media::Transform>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrapWindows_UI_Xaml_Media_Transform();
			wrapped__->RenderTransform = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, RenderTransform)
		{
			auto value = wrapped__->RenderTransform;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::Media::Transform>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::Media::Transform>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_SETTER(UIElement, Projection)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<Windows::UI::Xaml::Media::Projection>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrapWindows_UI_Xaml_Media_Projection();
			wrapped__->Projection = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, Projection)
		{
			auto value = wrapped__->Projection;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::Media::Projection>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::Media::Projection>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_SETTER(UIElement, Opacity)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<double>(argument);
			wrapped__->Opacity = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, Opacity)
		{
			auto value = wrapped__->Opacity;
			auto context = get_context();
			return context.CreateNumber(static_cast<double>(value));
		}

		TITANIUM_PROPERTY_GETTER(UIElement, PointerCaptures)
		{
			auto value = wrapped__->PointerCaptures;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::Foundation::Collections::IVectorView`1&lt;class Windows::UI::Xaml::Input::Pointer&gt;>::Class());
			auto native_wrapper = object.GetPrivate<Windows::Foundation::Collections::IVectorView`1&lt;class Windows::UI::Xaml::Input::Pointer&gt;>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, RenderSize)
		{
			auto value = wrapped__->RenderSize;
			auto context = get_context();
			auto result = context.CreateObject();
			result.SetProperty("Width", context.CreateNumber(static_cast<double>(value.Width)));
			result.SetProperty("Height", context.CreateNumber(static_cast<double>(value.Height)));
			return result; 
		}

		TITANIUM_PROPERTY_GETTER(UIElement, DesiredSize)
		{
			auto value = wrapped__->DesiredSize;
			auto context = get_context();
			auto result = context.CreateObject();
			result.SetProperty("Width", context.CreateNumber(static_cast<double>(value.Width)));
			result.SetProperty("Height", context.CreateNumber(static_cast<double>(value.Height)));
			return result; 
		}

		TITANIUM_PROPERTY_GETTER(UIElement, CompositeModeProperty)
		{
			auto value = wrapped__->CompositeModeProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, AllowDropProperty)
		{
			auto value = wrapped__->AllowDropProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, CacheModeProperty)
		{
			auto value = wrapped__->CacheModeProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, ClipProperty)
		{
			auto value = wrapped__->ClipProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, DoubleTappedEvent)
		{
			auto value = wrapped__->DoubleTappedEvent;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::RoutedEvent>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::RoutedEvent>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, DragEnterEvent)
		{
			auto value = wrapped__->DragEnterEvent;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::RoutedEvent>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::RoutedEvent>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, DragLeaveEvent)
		{
			auto value = wrapped__->DragLeaveEvent;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::RoutedEvent>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::RoutedEvent>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, DragOverEvent)
		{
			auto value = wrapped__->DragOverEvent;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::RoutedEvent>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::RoutedEvent>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, DropEvent)
		{
			auto value = wrapped__->DropEvent;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::RoutedEvent>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::RoutedEvent>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, HoldingEvent)
		{
			auto value = wrapped__->HoldingEvent;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::RoutedEvent>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::RoutedEvent>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, IsDoubleTapEnabledProperty)
		{
			auto value = wrapped__->IsDoubleTapEnabledProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, IsHitTestVisibleProperty)
		{
			auto value = wrapped__->IsHitTestVisibleProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, IsHoldingEnabledProperty)
		{
			auto value = wrapped__->IsHoldingEnabledProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, IsRightTapEnabledProperty)
		{
			auto value = wrapped__->IsRightTapEnabledProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, IsTapEnabledProperty)
		{
			auto value = wrapped__->IsTapEnabledProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, KeyDownEvent)
		{
			auto value = wrapped__->KeyDownEvent;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::RoutedEvent>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::RoutedEvent>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, KeyUpEvent)
		{
			auto value = wrapped__->KeyUpEvent;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::RoutedEvent>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::RoutedEvent>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, ManipulationCompletedEvent)
		{
			auto value = wrapped__->ManipulationCompletedEvent;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::RoutedEvent>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::RoutedEvent>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, ManipulationDeltaEvent)
		{
			auto value = wrapped__->ManipulationDeltaEvent;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::RoutedEvent>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::RoutedEvent>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, ManipulationInertiaStartingEvent)
		{
			auto value = wrapped__->ManipulationInertiaStartingEvent;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::RoutedEvent>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::RoutedEvent>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, ManipulationModeProperty)
		{
			auto value = wrapped__->ManipulationModeProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, ManipulationStartedEvent)
		{
			auto value = wrapped__->ManipulationStartedEvent;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::RoutedEvent>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::RoutedEvent>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, ManipulationStartingEvent)
		{
			auto value = wrapped__->ManipulationStartingEvent;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::RoutedEvent>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::RoutedEvent>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, OpacityProperty)
		{
			auto value = wrapped__->OpacityProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, PointerCanceledEvent)
		{
			auto value = wrapped__->PointerCanceledEvent;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::RoutedEvent>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::RoutedEvent>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, PointerCaptureLostEvent)
		{
			auto value = wrapped__->PointerCaptureLostEvent;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::RoutedEvent>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::RoutedEvent>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, PointerCapturesProperty)
		{
			auto value = wrapped__->PointerCapturesProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, PointerEnteredEvent)
		{
			auto value = wrapped__->PointerEnteredEvent;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::RoutedEvent>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::RoutedEvent>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, PointerExitedEvent)
		{
			auto value = wrapped__->PointerExitedEvent;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::RoutedEvent>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::RoutedEvent>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, PointerMovedEvent)
		{
			auto value = wrapped__->PointerMovedEvent;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::RoutedEvent>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::RoutedEvent>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, PointerPressedEvent)
		{
			auto value = wrapped__->PointerPressedEvent;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::RoutedEvent>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::RoutedEvent>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, PointerReleasedEvent)
		{
			auto value = wrapped__->PointerReleasedEvent;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::RoutedEvent>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::RoutedEvent>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, PointerWheelChangedEvent)
		{
			auto value = wrapped__->PointerWheelChangedEvent;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::RoutedEvent>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::RoutedEvent>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, ProjectionProperty)
		{
			auto value = wrapped__->ProjectionProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, RenderTransformOriginProperty)
		{
			auto value = wrapped__->RenderTransformOriginProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, RenderTransformProperty)
		{
			auto value = wrapped__->RenderTransformProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, RightTappedEvent)
		{
			auto value = wrapped__->RightTappedEvent;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::RoutedEvent>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::RoutedEvent>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, TappedEvent)
		{
			auto value = wrapped__->TappedEvent;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::RoutedEvent>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::RoutedEvent>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, TransitionsProperty)
		{
			auto value = wrapped__->TransitionsProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, UseLayoutRoundingProperty)
		{
			auto value = wrapped__->UseLayoutRoundingProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(UIElement, VisibilityProperty)
		{
			auto value = wrapped__->VisibilityProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_FUNCTION(UIElement, Measure)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->Measure();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(UIElement, Arrange)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->Arrange();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(UIElement, CapturePointer)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = wrapped__->CapturePointer();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(UIElement, ReleasePointerCapture)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->ReleasePointerCapture();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(UIElement, ReleasePointerCaptures)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->ReleasePointerCaptures();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(UIElement, AddHandler)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->AddHandler();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(UIElement, RemoveHandler)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->RemoveHandler();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(UIElement, TransformToVisual)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = wrapped__->TransformToVisual();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(UIElement, InvalidateMeasure)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->InvalidateMeasure();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(UIElement, InvalidateArrange)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->InvalidateArrange();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(UIElement, UpdateLayout)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->UpdateLayout();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(UIElement, CancelDirectManipulations)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = wrapped__->CancelDirectManipulations();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(UIElement, OnCreateAutomationPeer)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = wrapped__->OnCreateAutomationPeer();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(UIElement, OnDisconnectVisualChildren)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->OnDisconnectVisualChildren();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(UIElement, FindSubElementsForTouchTargeting)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = wrapped__->FindSubElementsForTouchTargeting();
			return get_context().CreateBoolean(result); 
		}

		} // namespace Xaml
	} // namespace UI
} // namespace Windows
