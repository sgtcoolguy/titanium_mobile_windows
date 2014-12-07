/** -*- mode: c++ -*-
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MOBILE_WINDOWS_MODULES_TI_TIMODULE_H_
#define _TITANIUM_MOBILE_WINDOWS_MODULES_TI_TIMODULE_H_

#include "TiCore/TiValue.h"

// TODO: There is no such thing as a Ti module. The code in here needs
// to go to the TiCore
namespace TiModule {

Ti::Value Initialize(const std::string& ns, Ti::Value& obj);

}  // TiModule {

#endif	// _TITANIUM_MOBILE_WINDOWS_MODULES_TI_TIMODULE_H_
