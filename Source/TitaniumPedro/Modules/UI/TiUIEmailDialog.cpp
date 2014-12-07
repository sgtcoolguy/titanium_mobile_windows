/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#include "Modules/UI/TiUIEmailDialog.h"

namespace Ti { namespace UI {

////////////////////////////////////////////////////////////////////////
//
// Proxy macro infrastructure goes below here.
//
////////////////////////////////////////////////////////////////////////

JSStaticFunction const EmailDialog::ClassMethods[] = {
	{ "getBarColor", _getBarColor, kJSPropertyAttributeNone },
	{ "setBarColor", _setBarColor, kJSPropertyAttributeNone },
	{ "getBccRecipients", _getBccRecipients, kJSPropertyAttributeNone },
	{ "setBccRecipients", _setBccRecipients, kJSPropertyAttributeNone },
	{ "getCcRecipients", _getCcRecipients, kJSPropertyAttributeNone },
	{ "setCcRecipients", _setCcRecipients, kJSPropertyAttributeNone },
	{ "getHtml", _getHtml, kJSPropertyAttributeNone },
	{ "setHtml", _setHtml, kJSPropertyAttributeNone },
	{ "getMessageBody", _getMessageBody, kJSPropertyAttributeNone },
	{ "setMessageBody", _setMessageBody, kJSPropertyAttributeNone },
	{ "getSubject", _getSubject, kJSPropertyAttributeNone },
	{ "setSubject", _setSubject, kJSPropertyAttributeNone },
	{ "getToRecipients", _getToRecipients, kJSPropertyAttributeNone },
	{ "setToRecipients", _setToRecipients, kJSPropertyAttributeNone },
	{ "addAttachment", _addAttachment, kJSPropertyAttributeNone },
	{ "isSupported", _isSupported, kJSPropertyAttributeNone },
	{ "open", _open, kJSPropertyAttributeNone },
	{ 0, 0, 0 }
};

}} // namespace Ti { namespace UI {
