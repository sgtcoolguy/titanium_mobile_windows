/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#include "Modules/UI/TiUIProgressBar.h"
#include <Windows.h>
#include "TiCore/TiWebColor.h"

namespace Ti { namespace UI {

////////////////////////////////////////////////////////////////////////
//
// Proxy macro infrastructure goes below here.
//
////////////////////////////////////////////////////////////////////////

const JSStaticFunction ProgressBar::ClassMethods[] = {
	{ "setIsIndeterminate", _setIsIndeterminate, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getIsIndeterminate", _getIsIndeterminate, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "setMax", _setMax, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getMax", _getMax, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "setMin", _setMin, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getMin", _getMin, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "setShowError", _setShowError, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getShowError", _getShowError, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "setShowPaused", _setShowPaused, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getShowPaused", _getShowPaused, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "setValue", _setValue, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getValue", _getValue, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ 0, 0, 0 }
};

}} // namespace Ti { namespace UI {
