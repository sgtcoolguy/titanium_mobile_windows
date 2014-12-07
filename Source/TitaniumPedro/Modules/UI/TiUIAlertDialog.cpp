/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#include "Modules/UI/TiUIAlertDialog.h"

using namespace Windows::UI::Popups;

namespace Ti {
	namespace UI {

		JSStaticFunction const AlertDialog::ClassMethods[] = {
				{ "setTitle", _setTitle, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setMessage", _setMessage, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "show", _show, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "addButton", _addButton, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ 0, 0, 0 }
		};

		AlertDialog::AlertDialog(const std::string& name, const std::vector<Ti::Value>& arguments) : Ti::Proxy(name, arguments)
		{

		}
		Ti::Value AlertDialog::addButton(const std::vector<Ti::Value>& arguments) {
			const std::string title = arguments.at(0).toString();
			const std::wstring wTitle = std::wstring(title.begin(), title.end());

			// Bring in the placeholders _1, _2, etc. for std::bind.
			using namespace std::placeholders;
			auto callback = std::bind([](const AlertDialog_weak_ptr_t& weakThis, IUICommand^ command) {
				auto strong_ptr = weakThis.lock();
				if (strong_ptr) {
					strong_ptr->fireEvent(Ti::Constants::EventClick, Ti::Value());
					strong_ptr->self_ = nullptr;
				}
			},
				std::move(get_weak_ptr_for_proxy()), _1);

			auto command_invoked_handler = ref new UICommandInvokedHandler(callback);

			// The alert's "buttons" are UICommand, they take a title and an
			// action.
			message_dialog_.Get()->Commands->Append(ref new UICommand(ref new Platform::String(wTitle.c_str()), command_invoked_handler));

			return Ti::Value::Undefined();
		}


		Ti::Value AlertDialog::show(const std::vector<Ti::Value>& arguments) {
			message_dialog_.Get()->ShowAsync();
			const auto numberOfButtons = message_dialog_.Get()->Commands->Size;
			if (numberOfButtons > 0 && click_event_handler_count_ > 0) {
				self_ = get_shared_ptr_for_proxy();
			}
			return Ti::Value::Undefined();
		}

		Ti::Value AlertDialog::setTitle(const std::vector<Ti::Value>& arguments) {
			std::string title = arguments.at(0).toString();
			std::wstring wTitle = std::wstring(title.begin(), title.end());
			message_dialog_.Get()->Title = ref new Platform::String(wTitle.c_str());;
			return Ti::Value::Undefined();
		}

		Ti::Value AlertDialog::setMessage(const std::vector<Ti::Value>& arguments) {
			std::string title = arguments.at(0).toString();
			std::wstring wTitle = std::wstring(title.begin(), title.end());
			message_dialog_.Get()->Content = ref new Platform::String(wTitle.c_str());
			return Ti::Value::Undefined();
		}

		Ti::Value AlertDialog::eventAdded(const std::vector<Ti::Value>& arguments) {
			if (Ti::Constants::EventClick == arguments.at(0).toString()) {
				++click_event_handler_count_;
			}
			return Ti::Proxy::eventAdded(arguments);
		}

		Ti::Value AlertDialog::eventRemoved(const std::vector<Ti::Value>& arguments) {
			if (Ti::Constants::EventClick == arguments.at(0).toString()) {
				--click_event_handler_count_;
			}
			return Ti::Proxy::eventRemoved(arguments);
		}
	}	// namespace UI {
}
