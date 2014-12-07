/** -*- mode: c++ -*-
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#ifndef _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUIALERTDIALOG_H_
#define _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUIALERTDIALOG_H_

#include <agile.h>
#include "TiCore/TiProxy.h"
#include "TiCore/TiConstants.h"

// This is the Ti.UI.AlertDialog
// Also used in the alert() function
namespace Ti {
	namespace UI {

		// Although in the UI namespace, this is _not_ a ViewProxy, just a
		// Proxy.
		class AlertDialog : public Ti::Proxy, public virtual_enable_shared_from_this < AlertDialog > 
		{
			TI_CREATE_PROXY(AlertDialog);
			static JSClassRef Parent() { return Ti::Proxy::ClassDef(); }

		protected:
			AlertDialog(const std::string& name, const std::vector<Ti::Value>& arguments);
			~AlertDialog() {
				message_dialog_ = nullptr;
			}

		private:

			// Native component.	This component does not live outside of a
			// function scope, so it needs to be placed in an Agile object
			Platform::Agile<Windows::UI::Popups::MessageDialog> message_dialog_{ Platform::Agile<Windows::UI::Popups::MessageDialog>(ref new Windows::UI::Popups::MessageDialog(nullptr)) };
			std::atomic<long> click_event_handler_count_;
			std::shared_ptr<AlertDialog> self_{ nullptr };


			// JavaScript methods:
			TI_CREATE_METHOD(AlertDialog, show);
			Ti::Value show(const std::vector<Ti::Value>& arguments);
			TI_CREATE_METHOD(AlertDialog, setTitle);
			Ti::Value setTitle(const std::vector<Ti::Value>& arguments);
			TI_CREATE_METHOD(AlertDialog, setMessage);
			Ti::Value setMessage(const std::vector<Ti::Value>& arguments);
			TI_CREATE_METHOD(AlertDialog, addButton);
			Ti::Value addButton(const std::vector<Ti::Value>& arguments);

			virtual Ti::Value eventAdded(const std::vector<Ti::Value>& arguments);
			virtual Ti::Value eventRemoved(const std::vector<Ti::Value>& arguments);
		};

	}
}
// namespace UI {

#endif // _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUIALERTDIALOG_H_
