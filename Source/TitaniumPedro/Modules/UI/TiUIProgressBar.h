/** -*- mode: c++ -*-
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#ifndef _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUIPROGRESSBAR_H_
#define _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUIPROGRESSBAR_H_

#include "TiCore/TiViewProxy.h"
#include "TiCore/TiWebColor.h"

namespace Ti { namespace UI {

class ProgressBar : public Ti::ViewProxy, public virtual_enable_shared_from_this<ProgressBar> {

 public:

	// The TIViewProxy defaults for height and width are correct.

 protected:

	ProgressBar(const std::string& name, const std::vector<Ti::Value>& arguments) : Ti::ViewProxy(name, arguments) {
		progress_bar_ = ref new Windows::UI::Xaml::Controls::ProgressBar();
		setComponent(progress_bar_);
	}

	virtual ~ProgressBar() {
		progress_bar_ = nullptr;
	}
 private:

	Windows::UI::Xaml::Controls::ProgressBar^ progress_bar_{ nullptr };
	bool is_indeterminate_;

	////////////////////////////////////////////////////////////////////////
	//
	// Proxy macro infrastructure goes below here.
	//
	////////////////////////////////////////////////////////////////////////

	TI_CREATE_PROXY(ProgressBar);

	static JSClassRef Parent() {
		return Ti::ViewProxy::ClassDef();
	}

	// Gets the value of the isIndeterminate property.
	TI_CREATE_METHOD(ProgressBar, getIsIndeterminate);
	Ti::Value getIsIndeterminate(const std::vector<Ti::Value>& arguments) {
		return Ti::Value(is_indeterminate_);
	}

	// Sets the value of the isIndeterminate property.
	TI_CREATE_METHOD(ProgressBar, setIsIndeterminate);
	Ti::Value setIsIndeterminate(const std::vector<Ti::Value>& arguments) {
		is_indeterminate_ = arguments.at(0).toBool();
		progress_bar_->IsIndeterminate = is_indeterminate_;
		return Ti::Value::Undefined();
	}

	// Gets the value of the max property.
	TI_CREATE_METHOD(ProgressBar, getMax);
	Ti::Value getMax(const std::vector<Ti::Value>& arguments) {
		return Ti::Value(progress_bar_->Maximum);
	}

	// Sets the value of the max property.
	TI_CREATE_METHOD(ProgressBar, setMax);
	Ti::Value setMax(const std::vector<Ti::Value>& arguments) {
		progress_bar_->Maximum = arguments.at(0).toDouble();
		return Ti::Value::Undefined();
	}

	// Gets the value of the min property.
	TI_CREATE_METHOD(ProgressBar, getMin);
	Ti::Value getMin(const std::vector<Ti::Value>& arguments) {
		return Ti::Value(progress_bar_->Minimum);
	}

	// Sets the value of the min property.
	TI_CREATE_METHOD(ProgressBar, setMin);
	Ti::Value setMin(const std::vector<Ti::Value>& arguments) {
		progress_bar_->Minimum = arguments.at(0).toDouble();
		return Ti::Value::Undefined();
	}

	// Gets the value of the showError property.
	TI_CREATE_METHOD(ProgressBar, getShowError);
	Ti::Value getShowError(const std::vector<Ti::Value>& arguments) {
	return Ti::Value(progress_bar_->ShowError);
	}

	// Sets the value of the showError property.
	TI_CREATE_METHOD(ProgressBar, setShowError);
	Ti::Value setShowError(const std::vector<Ti::Value>& arguments) {
		progress_bar_->ShowError = arguments.at(0).toDouble();
		return Ti::Value::Undefined();
	}

	// Gets the value of the showPaused property.
	TI_CREATE_METHOD(ProgressBar, getShowPaused);
	Ti::Value getShowPaused(const std::vector<Ti::Value>& arguments) {
		return Ti::Value(progress_bar_->ShowPaused);
	}

	// Sets the value of the showPaused property.
	TI_CREATE_METHOD(ProgressBar, setShowPaused);
	Ti::Value setShowPaused(const std::vector<Ti::Value>& arguments) {
		progress_bar_->ShowPaused = arguments.at(0).toDouble();
		return Ti::Value::Undefined();
	}

	// Gets the value of the value property.
	TI_CREATE_METHOD(ProgressBar, getValue);
	Ti::Value getValue(const std::vector<Ti::Value>& arguments) {
		return Ti::Value(progress_bar_->Value);
	}

	// Sets the value of the value property.
	TI_CREATE_METHOD(ProgressBar, setValue);
	Ti::Value setValue(const std::vector<Ti::Value>& arguments) {
		progress_bar_->Value = arguments.at(0).toDouble();
		return Ti::Value::Undefined();
	}

	// methods
	virtual Ti::Value hide(const std::vector<Ti::Value>& arguments) override {
		progress_bar_->IsIndeterminate = false; // for perf reasons, always set to indterminate when hidden
		return Ti::ViewProxy::hide(arguments);
	}

	virtual Ti::Value show(const std::vector<Ti::Value>& arguments) override {
		progress_bar_->IsIndeterminate = is_indeterminate_;
		return Ti::ViewProxy::show(arguments);
	}
};

}} // namespace Ti { namespace UI {

#endif // #define _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUIPROGRESSBAR_H_
