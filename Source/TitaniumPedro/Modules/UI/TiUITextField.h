/** -*- mode: c++ -*-
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUITEXTFIELD_H_
#define _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUITEXTFIELD_H_

#include "TiCore/TiViewProxy.h"
#include <algorithm>
#include "TiCore/TiConstants.h"
#include "TiCore/TiUtils.h"

namespace Ti { namespace UI {

class TextField : public Ti::ViewProxy, public virtual_enable_shared_from_this<TextField> {

 public:

	// The TIViewProxy defaults for height and width are correct.

 protected:

	TextField(const std::string& name, const std::vector<Ti::Value>& arguments) : Ti::ViewProxy(name, arguments) {
		text_box_ = ref new Windows::UI::Xaml::Controls::TextBox();
		text_box_->AcceptsReturn = false;
		text_box_->IsSpellCheckEnabled = true;
		setComponent(text_box_);
	}

 private:

	Windows::UI::Xaml::Controls::TextBox^ text_box_ { nullptr };
  Windows::Foundation::EventRegistrationToken         blur_event_;
  Windows::Foundation::EventRegistrationToken         change_event_;
  Windows::Foundation::EventRegistrationToken         focus_event_;
  Windows::Foundation::EventRegistrationToken         return_event_;
	std::atomic<long>                                   blur_event_handler_count_;
	std::atomic<long>                                   change_event_handler_count_;
	std::atomic<long>                                   focus_event_handler_count_;
	std::atomic<long>                                   return_event_handler_count_;

	////////////////////////////////////////////////////////////////////////
	//
	// Proxy macro infrastructure goes below here.
	//
	////////////////////////////////////////////////////////////////////////

	TI_CREATE_PROXY(TextField);

	static JSClassRef Parent() {
		return Ti::ViewProxy::ClassDef();
	}

	// Gets the value of the autocapitalization property.
	TI_CREATE_METHOD(TextField, getAutocapitalization);
	Ti::Value getAutocapitalization(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] TextField.getAutocapitalization() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Sets the value of the autocapitalization property.
	TI_CREATE_METHOD(TextField, setAutocapitalization);
	Ti::Value setAutocapitalization(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] TextField.setAutocapitalization() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Gets the value of the autocorrect property.
	TI_CREATE_METHOD(TextField, getAutocorrect);
	Ti::Value getAutocorrect(const std::vector<Ti::Value>& arguments) {
		return Ti::Value(text_box_->IsSpellCheckEnabled);
	}

	// Sets the value of the autocapitalization property.
	TI_CREATE_METHOD(TextField, setAutocorrect);
	Ti::Value setAutocorrect(const std::vector<Ti::Value>& arguments) {
		text_box_->IsSpellCheckEnabled = arguments.at(0).toBool();
		return Ti::Value::Undefined();
	}

	// Gets the value of the borderStyle property.
	TI_CREATE_METHOD(TextField, getBorderStyle);
	Ti::Value getBorderStyle(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] TextField.getBorderStyle() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Sets the value of the borderStyle property.
	TI_CREATE_METHOD(TextField, setBorderStyle);
	Ti::Value setBorderStyle(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] TextField.setBorderStyle() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Gets the value of the clearOnEdit property.
	TI_CREATE_METHOD(TextField, getClearOnEdit);
	Ti::Value getClearOnEdit(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] TextField.getClearOnEdit() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Sets the value of the clearOnEdit property.
	TI_CREATE_METHOD(TextField, setClearOnEdit);
	Ti::Value setClearOnEdit(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] TextField.setClearOnEdit() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Gets the value of the editable property.
	TI_CREATE_METHOD(TextField, getEditable);
	Ti::Value getEditable(const std::vector<Ti::Value>& arguments) {
		return Ti::Value(!text_box_->IsReadOnly);
	}

	// Sets the value of the editable property.
	TI_CREATE_METHOD(TextField, setEditable);
	Ti::Value setEditable(const std::vector<Ti::Value>& arguments) {
		text_box_->IsReadOnly = !arguments.at(0).toBool();
		return Ti::Value::Undefined();
	}

	// Gets the value of the ellipsize property.
	TI_CREATE_METHOD(TextField, getEllipsize);
	Ti::Value getEllipsize(const std::vector<Ti::Value>& arguments) {
		return Ti::Value(false);
	}

	// Sets the value of the ellipsize property.
	TI_CREATE_METHOD(TextField, setEllipsize);
	Ti::Value setEllipsize(const std::vector<Ti::Value>& arguments) {
		// There is no trimming option for TextBox
		return Ti::Value::Undefined();
	}

	// Gets the value of the enableReturnKey property.
	TI_CREATE_METHOD(TextField, getEnableReturnKey);
	Ti::Value getEnableReturnKey(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] TextField.getEnableReturnKey() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Sets the value of the enableReturnKey property.
	TI_CREATE_METHOD(TextField, setEnableReturnKey);
	Ti::Value setEnableReturnKey(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] TextField.setEnableReturnKey() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Gets the value of the font property.
	TI_CREATE_METHOD(TextField, getFont);
	Ti::Value getFont(const std::vector<Ti::Value>& arguments) {
		return Ti::Value::Undefined();
	}

	// Sets the value of the font property.
	TI_CREATE_METHOD(TextField, setFont);
	Ti::Value setFont(const std::vector<Ti::Value>& arguments);

	// Gets the value of the hintText property.
	TI_CREATE_METHOD(TextField, getHintText);
	Ti::Value getHintText(const std::vector<Ti::Value>& arguments) {
		return Ti::Value(Ti::Utils::GetPlatformString(text_box_->PlaceholderText));
	}

	// Sets the value of the hintText property.
	TI_CREATE_METHOD(TextField, setHintText);
	Ti::Value setHintText(const std::vector<Ti::Value>& arguments) {
		text_box_->PlaceholderText = Ti::Utils::GetPlatformString(arguments.at(0).toString());
		return Ti::Value::Undefined();
	}

	// Gets the value of the keyboardType property.
	TI_CREATE_METHOD(TextField, getKeyboardType);
  Ti::Value getKeyboardType(const std::vector<Ti::Value>& arguments);

  // Sets the value of the keyboardType property.
	TI_CREATE_METHOD(TextField, setKeyboardType);
  Ti::Value setKeyboardType(const std::vector<Ti::Value>& arguments);

	// Gets the value of the maxLength property.
	TI_CREATE_METHOD(TextField, getMaxLength);
	Ti::Value getMaxLength(const std::vector<Ti::Value>& arguments) {
		return Ti::Value(static_cast<double>(text_box_->MaxLength));
	}

	// Sets the value of the maxLength property.
	TI_CREATE_METHOD(TextField, setMaxLength);
	Ti::Value setMaxLength(const std::vector<Ti::Value>& arguments) {
		text_box_->MaxLength = arguments.at(0).toDouble();
		return Ti::Value::Undefined();
	}

	// Gets the value of the passwordMask property.
	TI_CREATE_METHOD(TextField, getPasswordMask);
	Ti::Value getPasswordMask(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] TextField.getPasswordMask() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Sets the value of the passwordMask property.
	TI_CREATE_METHOD(TextField, setPasswordMask);
	Ti::Value setPasswordMask(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] TextField.setPasswordMask() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Gets the value of the returnKeyType property.
	TI_CREATE_METHOD(TextField, getReturnKeyType);
	Ti::Value getReturnKeyType(const std::vector<Ti::Value>& arguments) {
    // FIXME I don't believe Windows allows you to alter the "return" key. Keyboard input type may influence it slightly...
		OutputDebugString(L"[WARN] TextField.getReturnKeyType() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Sets the value of the returnKeyType property.
	TI_CREATE_METHOD(TextField, setReturnKeyType);
	Ti::Value setReturnKeyType(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] TextField.setReturnKeyType() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Gets the value of the selection property.
	TI_CREATE_METHOD(TextField, getSelection);
	Ti::Value getSelection(const std::vector<Ti::Value>& arguments) {
		// Need to return an object with properties: length and location, both numbers
		std::map<std::string, Ti::Value> myObject;
    myObject["location"] = Ti::Value(static_cast<double>(text_box_->SelectionStart));
    myObject["length"] = Ti::Value(static_cast<double>(text_box_->SelectionLength));
		return Ti::Value(myObject);
	}

	// Gets the value of the suppressReturn property.
	TI_CREATE_METHOD(TextField, getSuppressReturn);
	Ti::Value getSuppressReturn(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] TextField.getSuppressReturn() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Sets the value of the suppressReturn property.
	TI_CREATE_METHOD(TextField, setSuppressReturn);
	Ti::Value setSuppressReturn(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] TextField.setSuppressReturn() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Gets the value of the textAlign property.
	TI_CREATE_METHOD(TextField, getTextAlign);
  Ti::Value getTextAlign(const std::vector<Ti::Value>& arguments);

	// Sets the value of the textAlign property.
	TI_CREATE_METHOD(TextField, setTextAlign);
  Ti::Value setTextAlign(const std::vector<Ti::Value>& arguments);

	// Gets the value of the value property.
	TI_CREATE_METHOD(TextField, getValue);
	Ti::Value getValue(const std::vector<Ti::Value>& arguments) {
		return Ti::Value(Ti::Utils::GetPlatformString(text_box_->Text));
	}

	// Sets the value of the value property.
	TI_CREATE_METHOD(TextField, setValue);
	Ti::Value setValue(const std::vector<Ti::Value>& arguments) {
		text_box_->Text = Ti::Utils::GetPlatformString(arguments.at(0).toString());
		return Ti::Value::Undefined();
	}

	// Gets the value of the verticalAlign property.
	TI_CREATE_METHOD(TextField, getVerticalAlign);
  Ti::Value getVerticalAlign(const std::vector<Ti::Value>& arguments);

	TI_CREATE_METHOD(TextField, setVerticalAlign);
  Ti::Value setVerticalAlign(const std::vector<Ti::Value>& arguments);

	// JavaScript methods:
	TI_CREATE_METHOD(TextField, blur);
	Ti::Value blur(const std::vector<Ti::Value>& arguments) {
		// TODO Windows doesn't allow forcibly losing focus, need to set focus on another control to achieve it! Can we set focus on the window or parent or something?
		return Ti::Value::Undefined();
	}

	TI_CREATE_METHOD(TextField, focus);
	Ti::Value focus(const std::vector<Ti::Value>& arguments) {
		text_box_->Focus(Windows::UI::Xaml::FocusState::Programmatic);
		return Ti::Value::Undefined();
	}

	TI_CREATE_METHOD(TextField, hasText);
	Ti::Value hasText(const std::vector<Ti::Value>& arguments) {
    return Ti::Value(!text_box_->Text->IsEmpty());
	}
  
  virtual Ti::Value eventAdded(const std::vector<Ti::Value>& arguments) override;

  virtual Ti::Value eventRemoved(const std::vector<Ti::Value>& arguments) override;
};

}} // namespace Ti { namespace UI {

#endif // #define _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUITEXTFIELD_H_
