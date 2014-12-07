/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */
#include "Modules/UI/UIModule.h"
#include <mutex>

// This module will have the following proxies:
#include "Modules/UI/TiUIAlertDialog.h"
#include "Modules/UI/TiUIButton.h"
#include "Modules/UI/TiUIEmailDialog.h"
#include "Modules/UI/TiUIImageButton.h"
#include "Modules/UI/TiUIImageView.h"
#include "Modules/UI/TiUILabel.h"
#include "Modules/UI/TiUINotification.h"
#include "Modules/UI/TiUIProgressBar.h"
#include "Modules/UI/TiUIScrollView.h"
#include "Modules/UI/TiUISearchBar.h"
#include "Modules/UI/TiUISlider.h"
#include "Modules/UI/TiUISwitch.h"
#include "Modules/UI/TiUITableView.h"
#include "Modules/UI/TiUITableViewRow.h"
#include "Modules/UI/TiUITextField.h"
#include "Modules/UI/TiUIView.h"
#include "Modules/UI/TiUIWebView.h"
#include "Modules/UI/TiUIWindow.h"
#include "Modules/UI/TiUIWindowsProgressRing.h"
#include "TiCore/TiConstants.h"
#include "TiCore/TiViewProxy.h"
#include "TiCore/TiRuntimeFunctions.h"

namespace UI {

Ti::Value UIModule::Initialize(const std::string& ns, Ti::Value& obj)	{
	Ti::Value result;
	static std::once_flag of;
	std::call_once(of, [&result, &ns, &obj] {
			// Create a temporary object
			Ti::Value uiModule;
			// Add the proxies, and a reference to the global object, to this object
			uiModule.setProperty("global", Ti::Value(Ti::Runtime::instance().globalObject()));
			uiModule.setProperty("TiUIAlertDialog", Ti::UI::AlertDialog::CreateConstructor());
			uiModule.setProperty("TiUIButton", Ti::UI::Button::CreateConstructor());
			uiModule.setProperty("TiUIEmailDialog", Ti::UI::EmailDialog::CreateConstructor());			
			uiModule.setProperty("TiUIImageButton", Ti::UI::ImageButton::CreateConstructor());
			uiModule.setProperty("TiUIImageView", Ti::UI::ImageView::CreateConstructor());
			uiModule.setProperty("TiUILabel", Ti::UI::Label::CreateConstructor());
			uiModule.setProperty("TiUINotification", Ti::UI::Notification::CreateConstructor());
			uiModule.setProperty("TiUIScrollView", Ti::UI::ScrollView::CreateConstructor());			
			uiModule.setProperty("TiUISearchBar", Ti::UI::SearchBar::CreateConstructor());
			uiModule.setProperty("TiUISlider", Ti::UI::Slider::CreateConstructor());
			uiModule.setProperty("TiUISwitch", Ti::UI::Switch::CreateConstructor());
			uiModule.setProperty("TiUITableView", Ti::UI::TableView::CreateConstructor());
			uiModule.setProperty("TiUITableViewRow", Ti::UI::TableViewRow::CreateConstructor());
			uiModule.setProperty("TiUITextField", Ti::UI::TextField::CreateConstructor());
			uiModule.setProperty("TiUIView", Ti::UI::View::CreateConstructor());
			uiModule.setProperty("TiUIWebView", TiUIWebView::CreateConstructor());
			uiModule.setProperty("TiUIWindow", Ti::UI::Window::CreateConstructor());			
			uiModule.setProperty("TiUIWindowsProgressBar", Ti::UI::ProgressBar::CreateConstructor());
			uiModule.setProperty("TiUIWindowsProgressRing", Ti::UI::ProgressRing::CreateConstructor());

			Ti::Value internalRequireFunc(JSObjectMakeFunctionWithCallback(Ti::Runtime::instance().globalContext(), nullptr, Ti::JSInternalModuleRequire));
			uiModule.setProperty("internal_require", internalRequireFunc);
			// Evaluate the code on the temp object "uiModule"
			result = Ti::evaluateScriptFileInObject("TitaniumPedro/ti.ui.js", uiModule);
			std::string strResult = result.toString();
			// Take the result and add a couple of constants: UI.SIZE and UI.FILL
			result.setProperty("SIZE", Ti::Value(Ti::Constants::SizeSIZE));
			result.setProperty("FILL", Ti::Value(Ti::Constants::SizeFILL));
			result.setProperty("UNKNOWN",  Ti::Value(static_cast<double>(UNKNOWN)));
			result.setProperty("PORTRAIT", Ti::Value(static_cast<double>(PORTRAIT)));
			result.setProperty("UPSIDE_PORTRAIT", Ti::Value(static_cast<double>(UPSIDE_PORTRAIT)));
			result.setProperty("LANDSCAPE_LEFT",  Ti::Value(static_cast<double>(LANDSCAPE_LEFT)));
			result.setProperty("LANDSCAPE_RIGHT", Ti::Value(static_cast<double>(LANDSCAPE_RIGHT)));
			result.setProperty("FACE_UP",  Ti::Value(static_cast<double>(FACE_UP)));
			result.setProperty("FACE_DOWN", Ti::Value(static_cast<double>(FACE_DOWN)));

			result.setProperty("NOTIFICATION_DURATION_SHORT", Ti::Value(static_cast<double>(NOTIFICATION_DURATION_SHORT)));
			result.setProperty("NOTIFICATION_DURATION_LONG", Ti::Value(static_cast<double>(NOTIFICATION_DURATION_LONG)));
			result.setProperty("RETURNKEY_GO", Ti::Value(static_cast<double>(RETURNKEY_GO)));
			result.setProperty("RETURNKEY_GOOGLE", Ti::Value(static_cast<double>(RETURNKEY_GOOGLE)));
			result.setProperty("RETURNKEY_JOIN", Ti::Value(static_cast<double>(RETURNKEY_JOIN)));
			result.setProperty("RETURNKEY_NEXT", Ti::Value(static_cast<double>(RETURNKEY_NEXT)));
			result.setProperty("RETURNKEY_ROUTE", Ti::Value(static_cast<double>(RETURNKEY_ROUTE)));
			result.setProperty("RETURNKEY_SEARCH", Ti::Value(static_cast<double>(RETURNKEY_SEARCH)));
			result.setProperty("RETURNKEY_YAHOO", Ti::Value(static_cast<double>(RETURNKEY_YAHOO)));
			result.setProperty("RETURNKEY_DONE", Ti::Value(static_cast<double>(RETURNKEY_DONE)));
			result.setProperty("RETURNKEY_EMERGENCY_CALL", Ti::Value(static_cast<double>(RETURNKEY_EMERGENCY_CALL)));
			result.setProperty("RETURNKEY_DEFAULT", Ti::Value(static_cast<double>(RETURNKEY_DEFAULT)));
			result.setProperty("RETURNKEY_SEND", Ti::Value(static_cast<double>(RETURNKEY_SEND)));
			result.setProperty("KEYBOARD_APPEARANCE_DEFAULT", Ti::Value(static_cast<double>(KEYBOARD_APPEARANCE_DEFAULT)));
			result.setProperty("KEYBOARD_APPEARANCE_ALERT", Ti::Value(static_cast<double>(KEYBOARD_APPEARANCE_ALERT)));
			result.setProperty("KEYBOARD_ASCII", Ti::Value(static_cast<double>(KEYBOARD_ASCII)));
			result.setProperty("KEYBOARD_NUMBERS_PUNCTUATION", Ti::Value(static_cast<double>(KEYBOARD_NUMBERS_PUNCTUATION)));
			result.setProperty("KEYBOARD_URL", Ti::Value(static_cast<double>(KEYBOARD_URL)));
			result.setProperty("KEYBOARD_NUMBER_PAD", Ti::Value(static_cast<double>(KEYBOARD_NUMBER_PAD)));
			result.setProperty("KEYBOARD_PHONE_PAD", Ti::Value(static_cast<double>(KEYBOARD_PHONE_PAD)));
			result.setProperty("KEYBOARD_EMAIL", Ti::Value(static_cast<double>(KEYBOARD_EMAIL)));
			result.setProperty("KEYBOARD_NAMEPHONE_PAD", Ti::Value(static_cast<double>(KEYBOARD_NAMEPHONE_PAD)));
			result.setProperty("KEYBOARD_DEFAULT", Ti::Value(static_cast<double>(KEYBOARD_DEFAULT)));
			result.setProperty("KEYBOARD_DECIMAL_PAD", Ti::Value(static_cast<double>(KEYBOARD_DECIMAL_PAD)));
			result.setProperty("AUTOLINK_EMAIL_ADDRESSES", Ti::Value(static_cast<double>(AUTOLINK_EMAIL_ADDRESSES)));
			result.setProperty("AUTOLINK_MAP_ADDRESSES", Ti::Value(static_cast<double>(AUTOLINK_MAP_ADDRESSES)));
			result.setProperty("AUTOLINK_PHONE_NUMBERS", Ti::Value(static_cast<double>(AUTOLINK_PHONE_NUMBERS)));
			result.setProperty("AUTOLINK_URLS", Ti::Value(static_cast<double>(AUTOLINK_URLS)));
			result.setProperty("AUTOLINK_NONE", Ti::Value(static_cast<double>(AUTOLINK_NONE)));
			result.setProperty("AUTOLINK_ALL", Ti::Value(static_cast<double>(AUTOLINK_ALL)));
			result.setProperty("INPUT_BORDERSTYLE_NONE", Ti::Value(static_cast<double>(INPUT_BORDERSTYLE_NONE)));
			result.setProperty("INPUT_BORDERSTYLE_ROUNDED", Ti::Value(static_cast<double>(INPUT_BORDERSTYLE_ROUNDED)));
			result.setProperty("INPUT_BORDERSTYLE_BEZEL", Ti::Value(static_cast<double>(INPUT_BORDERSTYLE_BEZEL)));
			result.setProperty("INPUT_BORDERSTYLE_LINE", Ti::Value(static_cast<double>(INPUT_BORDERSTYLE_LINE)));
			result.setProperty("INPUT_BUTTONMODE_ONFOCUS", Ti::Value(static_cast<double>(INPUT_BUTTONMODE_ONFOCUS)));
			result.setProperty("INPUT_BUTTONMODE_ALWAYS", Ti::Value(static_cast<double>(INPUT_BUTTONMODE_ALWAYS)));
			result.setProperty("INPUT_BUTTONMODE_NEVER", Ti::Value(static_cast<double>(INPUT_BUTTONMODE_NEVER)));
			result.setProperty("LIST_ITEM_TEMPLATE_DEFAULT", Ti::Value(LIST_ITEM_TEMPLATE_DEFAULT));
			result.setProperty("LIST_ACCESSORY_TYPE_NONE", Ti::Value(static_cast<double>(LIST_ACCESSORY_TYPE_NONE)));
			result.setProperty("LIST_ACCESSORY_TYPE_CHECKMARK", Ti::Value(static_cast<double>(LIST_ACCESSORY_TYPE_CHECKMARK)));
			result.setProperty("LIST_ACCESSORY_TYPE_DETAIL", Ti::Value(static_cast<double>(LIST_ACCESSORY_TYPE_DETAIL)));
			result.setProperty("LIST_ACCESSORY_TYPE_DISCLOSURE", Ti::Value(static_cast<double>(LIST_ACCESSORY_TYPE_DISCLOSURE)));
			result.setProperty("MAP_VIEW_STANDARD", Ti::Value(static_cast<double>(MAP_VIEW_STANDARD)));
			result.setProperty("MAP_VIEW_SATELLITE", Ti::Value(static_cast<double>(MAP_VIEW_SATELLITE)));
			result.setProperty("MAP_VIEW_HYBRID", Ti::Value(static_cast<double>(MAP_VIEW_HYBRID)));
			result.setProperty("TABLEVIEW_POSITION_ANY", Ti::Value(static_cast<double>(TABLEVIEW_POSITION_ANY)));
			result.setProperty("TABLEVIEW_POSITION_TOP", Ti::Value(static_cast<double>(TABLEVIEW_POSITION_TOP)));
			result.setProperty("TABLEVIEW_POSITION_MIDDLE", Ti::Value(static_cast<double>(TABLEVIEW_POSITION_MIDDLE)));
			result.setProperty("TABLEVIEW_POSITION_BOTTOM", Ti::Value(static_cast<double>(TABLEVIEW_POSITION_BOTTOM)));
			result.setProperty("TEXT_ALIGNMENT_LEFT", Ti::Value(TEXT_ALIGNMENT_LEFT));
			result.setProperty("TEXT_ALIGNMENT_CENTER", Ti::Value(TEXT_ALIGNMENT_CENTER));
			result.setProperty("TEXT_ALIGNMENT_RIGHT", Ti::Value(TEXT_ALIGNMENT_RIGHT));
			result.setProperty("TEXT_VERTICAL_ALIGNMENT_BOTTOM", Ti::Value(TEXT_VERTICAL_ALIGNMENT_BOTTOM));
			result.setProperty("TEXT_VERTICAL_ALIGNMENT_CENTER", Ti::Value(TEXT_VERTICAL_ALIGNMENT_CENTER));
			result.setProperty("TEXT_VERTICAL_ALIGNMENT_TOP", Ti::Value(TEXT_VERTICAL_ALIGNMENT_TOP));
			result.setProperty("PICKER_TYPE_PLAIN", Ti::Value(static_cast<double>(PICKER_TYPE_PLAIN)));
			result.setProperty("PICKER_TYPE_TIME", Ti::Value(static_cast<double>(PICKER_TYPE_TIME)));
			result.setProperty("PICKER_TYPE_DATE", Ti::Value(static_cast<double>(PICKER_TYPE_DATE)));
			result.setProperty("PICKER_TYPE_DATE_AND_TIME", Ti::Value(static_cast<double>(PICKER_TYPE_DATE_AND_TIME)));
			result.setProperty("PICKER_TYPE_COUNT_DOWN_TIMER", Ti::Value(static_cast<double>(PICKER_TYPE_COUNT_DOWN_TIMER)));
			result.setProperty("TEXT_AUTOCAPITALIZATION_NONE", Ti::Value(static_cast<double>(TEXT_AUTOCAPITALIZATION_NONE)));
			result.setProperty("TEXT_AUTOCAPITALIZATION_SENTENCES", Ti::Value(static_cast<double>(TEXT_AUTOCAPITALIZATION_SENTENCES)));
			result.setProperty("TEXT_AUTOCAPITALIZATION_WORDS", Ti::Value(static_cast<double>(TEXT_AUTOCAPITALIZATION_WORDS)));
			result.setProperty("TEXT_AUTOCAPITALIZATION_ALL", Ti::Value(static_cast<double>(TEXT_AUTOCAPITALIZATION_ALL)));
			result.setProperty("UNIT_PX", Ti::Value(UNIT_PX));
			result.setProperty("UNIT_MM", Ti::Value(UNIT_MM));
			result.setProperty("UNIT_CM", Ti::Value(UNIT_CM));
			result.setProperty("UNIT_IN", Ti::Value(UNIT_IN));
			result.setProperty("UNIT_DIP", Ti::Value(UNIT_DIP));

			// Attach this object to "obj", which was passed in to us from the function call
			obj.setProperty(ns, result);
			
			// For debug, place a break point to see the result
		});
	
	// Return the new object
	return result;
}

} // namespace UI {
