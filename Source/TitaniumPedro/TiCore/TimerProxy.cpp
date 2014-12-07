/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#include "TiCore/TimerProxy.h"


////////////////////////////////////////////////////////////////////////
//
// Proxy macro infrastructure goes below here.
//
////////////////////////////////////////////////////////////////////////

JSStaticFunction const TimerProxy::ClassMethods[] = {
	{ "start", _start, 0 },
	{ "stop", _stop, 0 },
	{ 0, 0, 0 }
};
