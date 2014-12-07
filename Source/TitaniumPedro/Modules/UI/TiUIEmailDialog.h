/** -*- mode: c++ -*-
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUIEMAILDIALOG_H_
#define _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUIEMAILDIALOG_H_

#include <agile.h>
#include <vector>
#include <Windows.h>
#include "TiCore/TiProxy.h"
#include "TiCore/TiConstants.h"
#include "TiCore/TiUtils.h"

// This is the Ti.UI.EmailDialog
namespace Ti { 	namespace UI {

// Although in the UI namespace, this is _not_ a ViewProxy, just a
// Proxy.
class EmailDialog : public Ti::Proxy, public virtual_enable_shared_from_this<EmailDialog> {

protected:

	EmailDialog(const std::string& name, const std::vector<Ti::Value>& arguments) : Ti::Proxy(name, arguments) {
	}

	~EmailDialog() {
#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
		email_message_ = nullptr;
#endif
	}

 private:

#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
   Platform::Agile<Windows::ApplicationModel::Email::EmailMessage> email_message_ = ref new Windows::ApplicationModel::Email::EmailMessage();
#endif
	std::atomic<long>                                   complete_event_handler_count_;

	////////////////////////////////////////////////////////////////////////
	//
	// Proxy macro infrastructure goes below here.
	//
	////////////////////////////////////////////////////////////////////////

	TI_CREATE_PROXY(EmailDialog);

	static JSClassRef Parent() {
		return Ti::Proxy::ClassDef();
	}

	// JavaScript methods:
	// properties
	TI_CREATE_METHOD(EmailDialog, getBarColor);
	Ti::Value getBarColor(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] EmailDialog.getBarColor() not implemented. Returning Undefined");
		return Ti::Value::Undefined();
	}

	TI_CREATE_METHOD(EmailDialog, setBarColor);
	Ti::Value setBarColor(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] EmailDialog.setBarColor() not implemented. Returning Undefined");
		return Ti::Value::Undefined();
	}

	TI_CREATE_METHOD(EmailDialog, getHtml);
	Ti::Value getHtml(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] EmailDialog.getHtml() not implemented. Returning Undefined");
		return Ti::Value::Undefined();
	}

	TI_CREATE_METHOD(EmailDialog, setHtml);
	Ti::Value setHtml(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] EmailDialog.setHtml() not implemented. Returning Undefined");
		return Ti::Value::Undefined();
	}

	TI_CREATE_METHOD(EmailDialog, getMessageBody);
	Ti::Value getMessageBody(const std::vector<Ti::Value>& arguments) {
#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
		return Ti::Value(Ti::Utils::GetPlatformString(email_message_.Get()->Body));
#else
		OutputDebugString(L"[WARN] EmailDialog not supported on Windows Store apps. Returning Undefined");
		return Ti::Value::Undefined();
#endif
	}

	TI_CREATE_METHOD(EmailDialog, setMessageBody);
	Ti::Value setMessageBody(const std::vector<Ti::Value>& arguments) {
#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
		email_message_.Get()->Body = Ti::Utils::GetPlatformString(arguments.at(0).toString());
#else
		OutputDebugString(L"[WARN] EmailDialog not supported on Windows Store apps. Returning Undefined");
#endif
		return Ti::Value::Undefined();
	}

	TI_CREATE_METHOD(EmailDialog, getSubject);
	Ti::Value getSubject(const std::vector<Ti::Value>& arguments) {
#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
		return Ti::Value(Ti::Utils::GetPlatformString(email_message_.Get()->Subject));
#else
		OutputDebugString(L"[WARN] EmailDialog not supported on Windows Store apps. Returning Undefined");
		return Ti::Value::Undefined();
#endif
	}

	TI_CREATE_METHOD(EmailDialog, setSubject);
	Ti::Value setSubject(const std::vector<Ti::Value>& arguments) {
#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
		email_message_.Get()->Subject = Ti::Utils::GetPlatformString(arguments.at(0).toString());
#else
		OutputDebugString(L"[WARN] EmailDialog not supported on Windows Store apps. Returning Undefined");
#endif
		return Ti::Value::Undefined();
	}

	TI_CREATE_METHOD(EmailDialog, getToRecipients);
	Ti::Value getToRecipients(const std::vector<Ti::Value>& arguments) {
#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
		return getRecipients(email_message_.Get()->To);
#else
		OutputDebugString(L"[WARN] EmailDialog not supported on Windows Store apps. Returning Undefined");
		return Ti::Value::Undefined();
#endif
	}

	TI_CREATE_METHOD(EmailDialog, setToRecipients);
	Ti::Value setToRecipients(const std::vector<Ti::Value>& arguments) {
#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
		return setRecipients(arguments, email_message_.Get()->To);
#else
		OutputDebugString(L"[WARN] EmailDialog not supported on Windows Store apps. Returning Undefined");
		return Ti::Value::Undefined();
#endif
	}

	TI_CREATE_METHOD(EmailDialog, getCcRecipients);
	Ti::Value getCcRecipients(const std::vector<Ti::Value>& arguments) {
#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
		return getRecipients(email_message_.Get()->CC);
#else
		OutputDebugString(L"[WARN] EmailDialog not supported on Windows Store apps. Returning Undefined");
		return Ti::Value::Undefined();
#endif
	}

	TI_CREATE_METHOD(EmailDialog, setCcRecipients);
	Ti::Value setCcRecipients(const std::vector<Ti::Value>& arguments) {
#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
		return setRecipients(arguments, email_message_.Get()->CC);
#else
		OutputDebugString(L"[WARN] EmailDialog not supported on Windows Store apps. Returning Undefined");
		return Ti::Value::Undefined();
#endif
	}

	TI_CREATE_METHOD(EmailDialog, getBccRecipients);
	Ti::Value getBccRecipients(const std::vector<Ti::Value>& arguments) {
#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
		return getRecipients(email_message_.Get()->Bcc);
#else
		OutputDebugString(L"[WARN] EmailDialog not supported on Windows Store apps. Returning Undefined");
		return Ti::Value::Undefined();
#endif
	}

	TI_CREATE_METHOD(EmailDialog, setBccRecipients);
	Ti::Value setBccRecipients(const std::vector<Ti::Value>& arguments) {
#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
		return setRecipients(arguments, email_message_.Get()->Bcc);
#else
		OutputDebugString(L"[WARN] EmailDialog not supported on Windows Store apps. Returning Undefined");
		return Ti::Value::Undefined();
#endif
	}

#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
	// Common code for getting/setting recipients on To/Bcc/Cc
  Ti::Value EmailDialog::getRecipients(Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Email::EmailRecipient^>^ recipients) {
		// create an array to stuff the email addresses in
		std::vector<Ti::Value> addresses;
		const auto len = recipients->Size;
		addresses.reserve(len); // make sure it holds enough for number of addresses we'll stuff in
		for (int i = 0; i < len; i++) {
			const auto recipient = recipients->GetAt(i);
			addresses.push_back(Ti::Value(Ti::Utils::GetPlatformString(recipient->Address)));
		}
		return Ti::Value(addresses);
	}

  Ti::Value EmailDialog::setRecipients(const std::vector<Ti::Value>& arguments, Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Email::EmailRecipient^>^ recipients) {
		// clear out an existing entries so we fully replace with new
		recipients->Clear();
		// should be one array arg
		const auto arg = arguments.at(0);
		const auto parameters = (arg.isArray() ? arg.getLength() : 1);
		// loop through array, each entry should be an email address as string
		for (int j = 0; j < parameters; j++) {
			const auto parameter = arg.getValueAtIndex(j);
			if (parameter.isString()) {
				const auto address = parameter.toString();
        const auto emailRecipient = ref new Windows::ApplicationModel::Email::EmailRecipient(Ti::Utils::GetPlatformString(address));
   			recipients->Append(emailRecipient); 
			}
		}
		return Ti::Value::Undefined();
	}
#endif

	// methods
	TI_CREATE_METHOD(EmailDialog, addAttachment);
	Ti::Value addAttachment(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] EmailDialog.addAttachment() not yet implemented. Returning Undefined");
		return Ti::Value::Undefined();
	}

	TI_CREATE_METHOD(EmailDialog, isSupported);
	Ti::Value isSupported(const std::vector<Ti::Value>& arguments) {
#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
		return Ti::Value(true);
#else
		return Ti::Value(false);
#endif
	}

	TI_CREATE_METHOD(EmailDialog, open);
	Ti::Value open(const std::vector<Ti::Value>& arguments) {
#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
    auto composer = Windows::ApplicationModel::Email::EmailManager::ShowComposeNewEmailAsync(email_message_.Get());
		if (complete_event_handler_count_ > 0) {
      // NOTE this ends up firing the complete event immediately after dialog opens, not after we actually finish the dialog/send the email!
      using namespace std::placeholders;
      const auto current = Windows::UI::Xaml::Window::Current;
      const auto completedCallback = std::bind([current](const std::weak_ptr<EmailDialog>& weakThis, Windows::Foundation::IAsyncAction^ action, Windows::Foundation::AsyncStatus status) {
        const auto strong_ptr = weakThis.lock();
        if (strong_ptr) {
          const auto dispatchedCallback = std::bind([](const std::weak_ptr<EmailDialog>& weakThis) {
            const auto strong_ptr = weakThis.lock();
            if (strong_ptr) {
              strong_ptr->fireEvent(Ti::Constants::EventComplete, Ti::Value());
            }
          }, /* std::move(strong_ptr->get_weak_ptr_for_proxy()) causes crash */ weakThis);

          if (current) {
            current->Dispatcher->RunAsync(
              Windows::UI::Core::CoreDispatcherPriority::Normal,
              ref new Windows::UI::Core::DispatchedHandler(dispatchedCallback));
          }
        }
      }, std::move(get_weak_ptr_for_proxy()), _1, _2);
      composer->Completed = ref new Windows::Foundation::AsyncActionCompletedHandler(completedCallback);
		}
#else
		OutputDebugString(L"[WARN] EmailDialog not supported on Windows Store apps. Returning Undefined");		
#endif
		return Ti::Value::Undefined();
	}

	virtual Ti::Value eventAdded(const std::vector<Ti::Value>& arguments) override {
		if (Ti::Constants::EventComplete == arguments.at(0).toString()) {
			++complete_event_handler_count_;
		}
		return Ti::Proxy::eventAdded(arguments);
	}

	virtual Ti::Value eventRemoved(const std::vector<Ti::Value>& arguments) override {
		if (Ti::Constants::EventComplete == arguments.at(0).toString()) {
			--complete_event_handler_count_;
		}
		return Ti::Proxy::eventRemoved(arguments);
	}
};

}} // namespace Ti { namespace UI {

#endif // _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUIEMAILDIALOG_H_
