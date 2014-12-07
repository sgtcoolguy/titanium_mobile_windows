/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#include "Modules/UI/TiUIWindowsProgressRing.h"

namespace Ti { namespace UI {

////////////////////////////////////////////////////////////////////////
//
// Proxy macro infrastructure goes below here.
//
////////////////////////////////////////////////////////////////////////

JSStaticFunction const ProgressRing::ClassMethods[] = {
  { "setIsActive", _setIsActive, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
  { "getIsActive", _getIsActive, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ 0, 0, 0 }
};

}} // namespace Ti { namespace UI {
