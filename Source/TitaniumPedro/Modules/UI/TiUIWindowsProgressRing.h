/** -*- mode: c++ -*-
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUIWINDOWSPROGRESSRING_H_
#define _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUIWINDOWSPROGRESSRING_H_

#include "TiCore/TiViewProxy.h"

// This is the Ti.UI.Windows.ProgressRing
namespace Ti { 	namespace UI {

  class ProgressRing : public Ti::ViewProxy, public virtual_enable_shared_from_this<ProgressRing> {

protected:

  ProgressRing(const std::string& name, const std::vector<Ti::Value>& arguments) : Ti::ViewProxy(name, arguments) {
		progress_ring_ = ref new Windows::UI::Xaml::Controls::ProgressRing();
    setComponent(progress_ring_);
	}

	~ProgressRing() {
		progress_ring_ = nullptr;
	}

 private:

	Windows::UI::Xaml::Controls::ProgressRing^ progress_ring_{ nullptr };

	////////////////////////////////////////////////////////////////////////
	//
	// Proxy macro infrastructure goes below here.
	//
	////////////////////////////////////////////////////////////////////////

  TI_CREATE_PROXY(ProgressRing);

	static JSClassRef Parent() {
		return Ti::ViewProxy::ClassDef();
	}

  // Gets the value of the isActive property.
  TI_CREATE_METHOD(ProgressRing, getIsActive);
  Ti::Value getIsActive(const std::vector<Ti::Value>& arguments) {
    return Ti::Value(progress_ring_->IsActive);
  }

  // Sets the value of the isActive property.
  TI_CREATE_METHOD(ProgressRing, setIsActive);
  Ti::Value setIsActive(const std::vector<Ti::Value>& arguments) {
    progress_ring_->IsActive = arguments.at(0).toBool();
    return Ti::Value::Undefined();
  }

  // methods
	virtual Ti::Value hide(const std::vector<Ti::Value>& arguments) override {
		progress_ring_->IsActive = false;
		return Ti::ViewProxy::hide(arguments);
	}

	virtual Ti::Value show(const std::vector<Ti::Value>& arguments) override {
		progress_ring_->IsActive = true;
		return Ti::ViewProxy::show(arguments);
	}
};

}} // namespace Ti { namespace UI {

#endif // _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUIWINDOWSPROGRESSRING_H_
