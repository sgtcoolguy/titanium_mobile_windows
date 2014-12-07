/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#include "ExampleProxy.h"

namespace Ti {

////////////////////////////////////////////////////////////////////////
//
// Proxy macro infrastructure goes below here.
//
////////////////////////////////////////////////////////////////////////

const JSStaticFunction ExampleProxy::ClassMethods[] = {
	{"saySomething", _saySomething, kJSPropertyAttributeNone},
	{"createNew", _createNew,kJSPropertyAttributeNone},
	{0,0,0}
};

}  // namespace Ti {
