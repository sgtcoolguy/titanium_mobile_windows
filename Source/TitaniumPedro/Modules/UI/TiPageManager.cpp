/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#include "Modules/UI/TiPageManager.h"
#include <memory>
#include <mutex>
#include <functional>
#include <type_traits>
#include <string>
#include <windows.h>
#include "Modules/UI/TiUIWindow.h"

using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::UI::Xaml::Controls;
#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
using namespace Windows::Phone::UI::Input;
#endif

namespace Ti { namespace UI {

// ============================ BEGIN PUBLIC API ============================

// Creates an instance of the manager, no more than one per app is needed
PageManager_shared_ptr_t PageManager::Instance() {
	static PageManager_shared_ptr_t instance;
	static std::once_flag of;
	std::call_once(of, [] {
			instance = PageManager_shared_ptr_t(new PageManager(), deleter{});
			instance -> registerCallbacks();
		});

	return instance;
}

// ============================= END PUBLIC API =============================

void PageManager::registerCallbacks() {
	/*
	 * Managing the Pages without the help of Xaml in WindwosStore or
	 * WindowPhone apps is tricky. On WindowsPhone there is a default
	 * animation for pushing and poping from the Frame navigation
	 * stack. In order to accomplish this successfully we need to know
	 * when a navigation transition is taking place, otherwise a race
	 * condition can happend and the application might crash.	 Another
	 * thing to know about the way Microsoft has designed this is that
	 * the actual Page object is recreated every time we navigate to
	 * that Page, either forward of backward; there is no way around
	 * this. The way to solve this problem is by manually keeping
	 * track of the Pages' contents, we use an std::vector for that
	 * and we store a pointer to the WindowProxy that has the content.
	 */

	// We need to listen for some navigation events to manage the
	// Pages When the navigation begins, the `can_navigate_` becomes
	// false, any attempt to transition to a different in this stage
	// page will fail When the navigation ends and the next page is
	// loaded, the `can_navigate_` becomes true and we can continue
	auto rootFrame = safe_cast<Frame^>(Windows::UI::Xaml::Window::Current->Content);

	// Bring in the placeholders _1, _2, etc. for std::bind.
	using namespace std::placeholders;

	// Occurs when a new navigation is requested.
	// Calls `onNavigating()` method
	auto weakThis1 = PageManager_weak_ptr_t(shared_from_this());
	auto callback1 = std::bind([](const PageManager_weak_ptr_t& weakThis, Platform::Object ^sender, NavigatingCancelEventArgs ^e) {
			auto strong_ptr = weakThis.lock();
			if (strong_ptr) {
				strong_ptr -> onNavigating();
			}
		},
		std::move(weakThis1), _1, _2);
	rootFrame->Navigating += ref new NavigatingCancelEventHandler(callback1);

	// Occurs when the content that is being navigated to has been found
	// and is available from the Content property, although it may not
	// have completed loading.	Calls `onNavigated()` method after the
	// coming page is loaded
	auto weakThis2 = PageManager_weak_ptr_t(shared_from_this());
	auto callback2 = std::bind([](const PageManager_weak_ptr_t& weakThis, Platform::Object ^sender, NavigationEventArgs ^e) {
			auto strong_ptr = weakThis.lock();
			if (strong_ptr) {
				// Make sure the page is loaded, ignore any page
				// transition when this is happening. This turns the
				// `can_navigate_` to true.
				auto weakThis3 = PageManager_weak_ptr_t(strong_ptr);
				auto callback3 = std::bind([](const PageManager_weak_ptr_t& weakThis, Platform::Object ^sender, Windows::UI::Xaml::RoutedEventArgs ^e) {
						auto strong_ptr = weakThis.lock();
						if (strong_ptr) {
							strong_ptr -> onNavigated();
						}
					},
					std::move(weakThis3), _1, _2);
				safe_cast<Page^>(e->Content) -> Loaded += ref new Windows::UI::Xaml::RoutedEventHandler(callback3);
			}
		},
		std::move(weakThis2), _1, _2);
	rootFrame->Navigated += ref new NavigatedEventHandler(callback2);

#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
	// For the WindowsPhone, hook up the back button Calls the
	// `onBackButton()` returns wheather the event should be handled or
	// not If the event is not handled, the application will go to the
	// suspended state.
	auto weakThis4 = PageManager_weak_ptr_t(shared_from_this());
	auto callback4 = std::bind([](const PageManager_weak_ptr_t& weakThis, Platform::Object ^sender, BackPressedEventArgs ^e) {
			auto strong_ptr = weakThis.lock();
			if (strong_ptr) {
				e->Handled = strong_ptr -> onBackButton();
			}
		},
		std::move(weakThis4), _1, _2);
	HardwareButtons::BackPressed += ref new Windows::Foundation::EventHandler<BackPressedEventArgs^>(callback4);
#endif
}

// Tries to open, or present, a Ti.UI.Window.	 Creates a page,
// navigates to it and sets the content of the proxy in it Returns
// true if success and false if failed
bool PageManager::presentWindowProxy(Ti::UI::Window* proxy) {
	// Don't try to preset a Ti.UI.Window if there's one transitioning
	// TODO: Create a queue
	if (can_navigate_ == false) {
		OutputDebugString(L"[ERROR] Cannot open window while transitioning is happening. Ingonring\n");
		return false;
	}
	// Change the `navigation_state_` so we know what's going on
	navigation_state_ = NavigationState::Opening;
	// Right away, fire the "open" event on the proxy
	proxy->fireEvent(Ti::Constants::EventOpen, Ti::Value());
	// Push this proxy into the proxy's stack
	window_proxy_stack_.push_back(proxy);

	// Start the navigation
	auto rootFrame = safe_cast<Frame^>(Windows::UI::Xaml::Window::Current->Content);
	// We're not using Xaml, so just create a standard Page
	rootFrame->Navigate(Page::typeid);
	// Once navigated to it get the Page instance and set the content of the Proxy to it
	auto page = safe_cast<Page^>(rootFrame->Content);
	page->Content = proxy->getComponent();
	return true;
}

// Closes, or dismisses, a Ti.UI.Window.
// Returns true if success and false if failed
bool PageManager::dismissWindowProxy(Ti::UI::Window* proxy) {
	auto rootFrame = safe_cast<Frame^>(Windows::UI::Xaml::Window::Current->Content);
	bool canNavigateBack = (proxy == window_proxy_stack_.back() && rootFrame->CanGoBack);
	// If we're going back, animated, first check if there's an animation
	// already going on, and stop it!
	if (canNavigateBack == true && can_navigate_ == false) {
		OutputDebugString(L"[ERROR] Cannot close window while transitioning is happening. Ingonring\n");
		return false;
	}
	// What? trying to close a window that is not there?
	// This should never ever happen.
	if (window_proxy_stack_.size() == 0) {
		OutputDebugString(L"[ERROR] Cannot close a window that is not in the stack. Ingonring\n");
		return false;
	}
	// We're ready to go back
	// Let's fire the event
	proxy->fireEvent(Ti::Constants::EventClose, Ti::Value());
	if (canNavigateBack) {
		// Update the `navigation_state_`
		navigation_state_ = NavigationState::Closing;
		// Go back one on the frame stack
		proxy->fireEvent(Ti::Constants::EventBlur, Ti::Value());
		rootFrame->GoBack();
		// Now that we're here, grab a hold of the Page
		auto page = safe_cast<Page^>(rootFrame->Content);
		// Remove one from the proxy stack, we already verified that this proxy is the last
		window_proxy_stack_.pop_back();
		// This should never be true, but just in case...
		if (window_proxy_stack_.size() > 0) {
			// Since we already poped one off the stack, get the new last one and set the content
			// on the page
			page->Content = window_proxy_stack_.back()->getComponent();
		}
		return true;
	}

	// This is in case a window, that's not the last on the stack, is
	// closed

	// Find the proxy in the proxy stack
	auto prox = std::find(window_proxy_stack_.begin(), window_proxy_stack_.end(), proxy);
	if (prox != window_proxy_stack_.end())
	{
		if (rootFrame->CanGoBack) {
			// Since all the pages in the frame back stack are the same
			// type (Page::typeid) Just remove the fisrt one
			rootFrame->BackStack->RemoveAt(0);
			return true;
		}
		navigation_state_ = NavigationState::None;
		// Remove it from the proxy stack
		window_proxy_stack_.erase(prox);
		// This is the first and only window, remove it
		rootFrame->Content = nullptr;
		Windows::UI::Xaml::Application::Current->Exit();
		return true;
	}
	// This should never happen, ever... Unless a window that was
	// never opened is being closed
	OutputDebugString(L"[ERROR] Cannot close window that is not in the stack. Ingonring\n");
	return false;
}

// Handles hardware back button for WindowsPhone
bool PageManager::onBackButton() {
	bool handlesEvent = false;
	// If there is only one Ti.UI.Window in the proxy stack, ignore
	// all this and return false, which means that we're not handling
	// the event ourselves, it suspends the app
	if (window_proxy_stack_.size() > 1) {
		// Get the last proxy in the stack, that's the only one we care, really
		auto proxy = window_proxy_stack_.back();
		// Should the app exit, or suspend, on close?
		if (proxy->existsOnClose()) {
			// Get a pointer to the root frame
			auto rootFrame = safe_cast<Frame^>(Windows::UI::Xaml::Window::Current->Content);
			// Get the first page, we need it for later
			auto firstPage = rootFrame->BackStack->GetAt(0);
			// Remove all the pages from the navigation stack
			rootFrame->BackStack->Clear();
			// Put the first page back
			rootFrame->BackStack->Append(firstPage);
			// Clear the proxy's stack
			window_proxy_stack_.clear();
			// Put the one proxy back at the begining of the stack
			window_proxy_stack_.push_back(proxy);
		} else {
			// Handle the event if exitOnClose is false
			handlesEvent = true;
		}

		if (proxy->hasBackButtonEvent()) {
			// Fire the event if it needs to
			proxy->fireEvent(Ti::Constants::EventBackButton, Ti::Value());
			return true;
		}
		// navigate to the previous page
		dismissWindowProxy(proxy);
		// return
		return handlesEvent;
	}
	return handlesEvent;
}

// Called when the new page is preseted and loaded
void PageManager::onNavigated() {
	// change the `can_navigate_` to true
	can_navigate_ = true;
	// Get the size of the proxy stack
	auto size = window_proxy_stack_.size();
	// If this transition is current an open transition:
	// fire "blur" on the last Ti.UI.Window
	// fire "focus" on the second to last Ti.UI.Window
	switch (navigation_state_) {

		case NavigationState::None:
			// Nothing to do.
			break;

		case NavigationState::Opening:
			window_proxy_stack_.back()->fireEvent(Ti::Constants::EventFocus, Ti::Value());
			if (size > 1) {
				window_proxy_stack_.at(size - 2)->fireEvent(Ti::Constants::EventBlur, Ti::Value());
			}
			break;

		case NavigationState::Closing:
			window_proxy_stack_.back()->fireEvent(Ti::Constants::EventFocus, Ti::Value());
			break;

		default:
			// If we get here it is a logic error.
			const auto unknown_navigation_state_value = static_cast<std::underlying_type<NavigationState>::type>(navigation_state_);
			throw std::logic_error("Unknown NavigationState " + std::to_string(unknown_navigation_state_value));
	}
}

}} // namespace Ti { namespace UI {
