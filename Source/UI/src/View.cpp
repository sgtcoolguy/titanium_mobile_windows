/**
 * Titanium.UI.View for Windows
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/UI/View.hpp"
#include "TitaniumWindows/UI/WindowsViewLayoutDelegate.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		using namespace Windows::UI::Xaml::Input;
		using namespace Windows::UI::Xaml;

		View::View(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::UI::View(js_context)
		{
			TITANIUM_LOG_DEBUG("TitaniumWindows::UI::View::ctor ", this);
		}

		View::~View() 
		{
			TITANIUM_LOG_DEBUG("TitaniumWindows::UI::View::dtor ", this);
		}

		void View::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{
			Titanium::UI::View::postCallAsConstructor(js_context, arguments);	
			
			canvas__ = ref new Windows::UI::Xaml::Controls::Canvas();

			Titanium::UI::View::setLayoutDelegate<WindowsViewLayoutDelegate>();

			layoutDelegate__->set_defaultHeight(Titanium::UI::LAYOUT::FILL);
			layoutDelegate__->set_defaultWidth(Titanium::UI::LAYOUT::FILL);
			layoutDelegate__->set_autoLayoutForHeight(Titanium::UI::LAYOUT::FILL);
			layoutDelegate__->set_autoLayoutForWidth(Titanium::UI::LAYOUT::FILL);

			getViewLayoutDelegate<WindowsViewLayoutDelegate>()->setComponent(canvas__);
		}

		void View::JSExportInitialize()
		{
			JSExport<View>::SetClassVersion(1);
			JSExport<View>::SetParent(JSExport<Titanium::UI::View>::Class());
		}

		Windows::UI::Xaml::FrameworkElement^ View::getComponent() TITANIUM_NOEXCEPT
		{
			return getViewLayoutDelegate<WindowsViewLayoutDelegate>()->getComponent();
		}

		void View::firePositionEvent(const std::string& event_name, FrameworkElement^ component, Windows::Foundation::Point position)
		{
			const auto ctx = get_context();

			JSObject  eventArgs = ctx.CreateObject();
			eventArgs.SetProperty("x", ctx.CreateNumber(position.X));
			eventArgs.SetProperty("y", ctx.CreateNumber(position.Y));

			this->fireEvent(event_name, eventArgs);		
		}

		void View::enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
		{
			Titanium::UI::View::enableEvent(event_name);

			const JSContext ctx = this->get_context();
			const auto component = getComponent();

			if (event_name == "touchmove") {
				component->ManipulationMode = ManipulationModes::All;
				touchmove_event__ = component->ManipulationDelta += ref new ManipulationDeltaEventHandler([ctx, this](Platform::Object^ sender, ManipulationDeltaRoutedEventArgs^ e) {
					JSObject  delta = ctx.CreateObject();
					delta.SetProperty("x", ctx.CreateNumber(e->Delta.Translation.X));
					delta.SetProperty("y", ctx.CreateNumber(e->Delta.Translation.Y));

					JSObject  eventArgs = ctx.CreateObject();
					eventArgs.SetProperty("x", ctx.CreateNumber(e->Position.X));
					eventArgs.SetProperty("y", ctx.CreateNumber(e->Position.Y));
					eventArgs.SetProperty("delta", delta);

					this->fireEvent("touchmove", eventArgs);
				});
			} else if (event_name == "touchstart") {
				component->ManipulationMode = ManipulationModes::All;
				component->ManipulationStarted += ref new ManipulationStartedEventHandler([ctx, this](Platform::Object^ sender, ManipulationStartedRoutedEventArgs^ e) {
					const auto component = safe_cast<FrameworkElement^>(sender);
					firePositionEvent("touchstart", component, e->Position);
				});
			} else if (event_name == "touchend") {
				component->ManipulationMode = ManipulationModes::All;
				component->ManipulationCompleted += ref new ManipulationCompletedEventHandler([ctx, this](Platform::Object^ sender, ManipulationCompletedRoutedEventArgs^ e) {
					const auto component = safe_cast<FrameworkElement^>(sender);
					firePositionEvent("touchend", component, e->Position);
				});
			} else if (event_name == "click") {
				click_event__ = component->Tapped += ref new TappedEventHandler([this, ctx](Platform::Object^ sender, TappedRoutedEventArgs^ e) {
					const auto component = safe_cast<FrameworkElement^>(sender);
					firePositionEvent("click", component, e->GetPosition(component));
				});
			} else if (event_name == "doubleclick") {
				doubleclick_event__ = component->DoubleTapped += ref new DoubleTappedEventHandler([this, ctx](Platform::Object^ sender, DoubleTappedRoutedEventArgs^ e) {
					const auto component = safe_cast<FrameworkElement^>(sender);
					firePositionEvent("doubleclick", component, e->GetPosition(component));
				});
			} else if (event_name == "singletap") {
				singletap_event__ = component->Tapped += ref new TappedEventHandler([this, ctx](Platform::Object^ sender, TappedRoutedEventArgs^ e) {
					const auto component = safe_cast<FrameworkElement^>(sender);
					firePositionEvent("singletap", component, e->GetPosition(component));
				});
			} else if (event_name == "doubletap") {
				doubletap_event__ = component->DoubleTapped += ref new DoubleTappedEventHandler([this, ctx](Platform::Object^ sender, DoubleTappedRoutedEventArgs^ e) {
					const auto component = safe_cast<FrameworkElement^>(sender);
					firePositionEvent("doubletap", component, e->GetPosition(component));
				});
			} else if (event_name == "longpress") {
				longpress_event__ = component->Holding += ref new HoldingEventHandler([this, ctx](Platform::Object^ sender, HoldingRoutedEventArgs^ e) {
					const auto component = safe_cast<FrameworkElement^>(sender);
					firePositionEvent("longpress", component, e->GetPosition(component));
				});
			} else if (event_name == "focus") {
				focus_event__ = component->GotFocus += ref new RoutedEventHandler([this, ctx](Platform::Object^ sender, RoutedEventArgs^ e) {
					this->fireEvent("focus");
				});
				return;
			}
		}

		void View::disableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
		{
			Titanium::UI::View::disableEvent(event_name);
			const auto component = getComponent();
			if (event_name == "touchmove") {
				component->ManipulationDelta -= touchmove_event__;
			} else if (event_name == "touchstart") {
				component->ManipulationStarted -= touchstart_event__;
			} else if (event_name == "touchend") {
				component->ManipulationCompleted -= touchend_event__;
			} else if (event_name == "click") {
				component->Tapped -= click_event__;
			} else if (event_name == "doubleclick") {
				component->DoubleTapped -= doubleclick_event__;
			} else if (event_name == "singletap") {
				component->Tapped -= singletap_event__;
			} else if (event_name == "doubletap") {
				component->DoubleTapped -= doubletap_event__;
			} else if (event_name == "longpress") {
				component->Holding -= longpress_event__;
			} else if (event_name == "focus") {
				component->GotFocus -= focus_event__;
			}
		}
	} // namespace UI
} // namespace TitaniumWindows
