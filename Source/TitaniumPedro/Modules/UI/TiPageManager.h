/** -*- mode: c++ -*-
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIPAGEMANAGER_H_
#define _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIPAGEMANAGER_H_

#include <vector>
#include <memory>

namespace Ti { namespace UI	{

class Window;

class PageManager;
using PageManager_weak_ptr_t	 = std::weak_ptr<PageManager>;
using PageManager_shared_ptr_t = std::shared_ptr<PageManager>;

class PageManager final : public std::enable_shared_from_this<PageManager> {

public:

	static PageManager_shared_ptr_t Instance();

	// returns true of the window opened, otherwise false
	static bool Open(Window* proxy) {
		return Instance() -> presentWindowProxy(proxy);
	}

	// returns true if the window closes, otherwise false
	static bool Close(Window* proxy) {
		return Instance() -> dismissWindowProxy(proxy);
	}

 private:

	// Private to enforce singleton pattern.
	PageManager() {
	};

	// Private to enforce singleton pattern.
	~PageManager() {
	};

	// This struct only exists so that a custom deleter can be passed to
	// std::shared_ptr<PageManager> while keeping the PageManager
	// destructor private.
	struct deleter {
		void operator()(PageManager* ptr) {
			delete ptr;
		}
	};

	void registerCallbacks();

	// openes a Ti.UI.Window, animated on phone
	bool presentWindowProxy(Ti::UI::Window* proxy);

	// closes a Ti.UI.Window, animated if last window in stack
	bool dismissWindowProxy(Ti::UI::Window* proxy);

	// Return tru if handles, false othewise
	bool onBackButton();

	// Called when navigation has started
	void onNavigating() {
		// Change the `can_navigate_` to false
		can_navigate_ = false;
	}

	void onNavigated();

	// Private member variables follow.
	
	enum class NavigationState {
		None		= 0,
		Opening = 1,
		Closing = 2
	};

	// Current naviagtion state
	NavigationState navigation_state_ { NavigationState::None };

	// Wheather a new navigation is allowed to happend or not
	bool can_navigate_ { true };

	// Stack of Proxy's
	std::vector<Ti::UI::Window*> window_proxy_stack_;

};

}} // namespace Ti { namespace UI	{

#endif // _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIPAGEMANAGER_H_
