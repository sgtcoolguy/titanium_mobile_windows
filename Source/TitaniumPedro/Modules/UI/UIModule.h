/** -*- mode: c++ -*-
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MOBILE_WINDOWS_MODULES_UI_UIMODULE_H_
#define _TITANIUM_MOBILE_WINDOWS_MODULES_UI_UIMODULE_H_

#include "TiCore/TiValue.h"

// TODO: Make this the header file for the UI Module. Use this as a
// reference for the rest of the modules
//
// The header for each module (library) shoild be the same:
//
// Namespaca::AddModuleToObject("module_namespace", Ti::Value(some_object));
//
// Eventually, this will look like this:
//
// namespace UI {
//	extern AddModuleToObject(const std::string& namespace, Ti::Value& parentObject);
// }

namespace UI { namespace UIModule {

    // Taken from NSURLError.h on iOS
    static const int URL_ERROR_UNKNOWN = -1;
    static const int URL_ERROR_AUTHENTICATION = 0;
    static const int URL_ERROR_BAD_URL = -1000;
    static const int URL_ERROR_TIMEOUT = -1001;
    static const int URL_ERROR_HOST_LOOKUP = -1003;
    static const int URL_ERROR_REDIRECT_LOOP = -1007;
    static const int URL_ERROR_UNSUPPORTED_SCHEME = -1002;
    static const int URL_ERROR_CONNECT = -1004;
    static const int URL_ERROR_SSL_FAILED = -1200;
    static const int URL_ERROR_FILE = -3001;
    static const int URL_ERROR_FILE_NOT_FOUND = -1100;

	static const int UNKNOWN = 0;
	static const int PORTRAIT = 1;
	static const int UPSIDE_PORTRAIT = 2;
	static const int LANDSCAPE_LEFT = 3;
	static const int LANDSCAPE_RIGHT = 4;
	static const int FACE_UP = 5;
	static const int FACE_DOWN = 6;

	// Taken from ti.modules.titanium.ui.UIModule on Android
	static const int RETURNKEY_GO = 0;
	static const int RETURNKEY_GOOGLE = 1;
	static const int RETURNKEY_JOIN = 2;
	static const int RETURNKEY_NEXT = 3;
	static const int RETURNKEY_ROUTE = 4;
	static const int RETURNKEY_SEARCH = 5;
	static const int RETURNKEY_YAHOO = 6;
	static const int RETURNKEY_DONE = 7;
	static const int RETURNKEY_EMERGENCY_CALL = 8;
	static const int RETURNKEY_DEFAULT = 9;
	static const int RETURNKEY_SEND = 10;

	static const int KEYBOARD_APPEARANCE_DEFAULT = -1; // Not supported
	static const int KEYBOARD_APPEARANCE_ALERT = -1; // Not supported

	static const int KEYBOARD_ASCII = 0;
	static const int KEYBOARD_NUMBERS_PUNCTUATION = 1;
	static const int KEYBOARD_URL = 2;
	static const int KEYBOARD_NUMBER_PAD = 3;
	static const int KEYBOARD_PHONE_PAD = 4;
	static const int KEYBOARD_EMAIL = 5;
	static const int KEYBOARD_NAMEPHONE_PAD = 6;
	static const int KEYBOARD_DEFAULT = 7;
	static const int KEYBOARD_DECIMAL_PAD = 8;

	static const int AUTOLINK_EMAIL_ADDRESSES = 0x02;
	static const int AUTOLINK_MAP_ADDRESSES = 0x08;
	static const int AUTOLINK_PHONE_NUMBERS = 0x04;
	static const int AUTOLINK_URLS = 0x01;
	static const int AUTOLINK_NONE = 16;
	static const int AUTOLINK_ALL = AUTOLINK_URLS | AUTOLINK_EMAIL_ADDRESSES | AUTOLINK_PHONE_NUMBERS | AUTOLINK_MAP_ADDRESSES;;

	static const int INPUT_BORDERSTYLE_NONE = 0;
	static const int INPUT_BORDERSTYLE_ROUNDED = 1;
	static const int INPUT_BORDERSTYLE_BEZEL = 2;
	static const int INPUT_BORDERSTYLE_LINE = 3;
	static const int INPUT_BUTTONMODE_ONFOCUS = 0;
	static const int INPUT_BUTTONMODE_ALWAYS = 1;
	static const int INPUT_BUTTONMODE_NEVER = 2;

	static const std::string LIST_ITEM_TEMPLATE_DEFAULT = "listDefaultTemplate";
	static const int LIST_ACCESSORY_TYPE_NONE = 0;
	static const int LIST_ACCESSORY_TYPE_CHECKMARK = 1;
	static const int LIST_ACCESSORY_TYPE_DETAIL = 2;
	static const int LIST_ACCESSORY_TYPE_DISCLOSURE = 3;

	static const int MAP_VIEW_STANDARD = 1;
	static const int MAP_VIEW_SATELLITE = 2;
	static const int MAP_VIEW_HYBRID = 3;

  static const int NOTIFICATION_DURATION_SHORT = 1;
  static const int NOTIFICATION_DURATION_LONG = 2;

	static const int TABLEVIEW_POSITION_ANY = 0;
	static const int TABLEVIEW_POSITION_TOP = 1;
	static const int TABLEVIEW_POSITION_MIDDLE = 2;
	static const int TABLEVIEW_POSITION_BOTTOM = 3;

	static const std::string TEXT_ALIGNMENT_LEFT = "left";
	static const std::string TEXT_ALIGNMENT_CENTER = "center";
	static const std::string TEXT_ALIGNMENT_RIGHT = "right";
	static const std::string TEXT_VERTICAL_ALIGNMENT_BOTTOM = "bottom";
	static const std::string TEXT_VERTICAL_ALIGNMENT_CENTER = "middle";
	static const std::string TEXT_VERTICAL_ALIGNMENT_TOP = "top";

	static const int PICKER_TYPE_PLAIN = -1;
	static const int PICKER_TYPE_TIME = 0;
	static const int PICKER_TYPE_DATE = 1;
	static const int PICKER_TYPE_DATE_AND_TIME = 2;
	static const int PICKER_TYPE_COUNT_DOWN_TIMER = 3;

	static const int TEXT_AUTOCAPITALIZATION_NONE = 0;
	static const int TEXT_AUTOCAPITALIZATION_SENTENCES = 1;
	static const int TEXT_AUTOCAPITALIZATION_WORDS = 2;
	static const int TEXT_AUTOCAPITALIZATION_ALL = 3;

	static const std::string UNIT_PX = "px";
	static const std::string UNIT_MM = "mm";
	static const std::string UNIT_CM = "cm";
	static const std::string UNIT_IN = "in";
	static const std::string UNIT_DIP = "dip";

Ti::Value Initialize(const std::string& ns, Ti::Value& obj);

}} // namespace UI { namespace UIModule {

#endif	// _TITANIUM_MOBILE_WINDOWS_MODULES_UI_UIMODULE_H_
