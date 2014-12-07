/** -*- mode: c++ -*-
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#ifndef _TITANIUM_MOBILE_WINDOWS_MODULES_SHAKEGESTUREHELPER_H_
#define _TITANIUM_MOBILE_WINDOWS_MODULES_SHAKEGESTUREHELPER_H_

#define _USE_MATH_DEFINES

#include "TiCore/TiProxy.h"
#include "TiCore/TiConstants.h"
#include <chrono>

namespace Ti { namespace Gesture {

	class ShakeGestureHelper : public virtual_enable_shared_from_this<ShakeGestureHelper> {

	public:
		ShakeGestureHelper();
		virtual ~ShakeGestureHelper();

		bool isShaken(Windows::Devices::Sensors::AccelerometerReading^ reading);
	protected:
	private:
		std::chrono::system_clock::time_point shakeStart_;
	};
}} // namespace Ti { namespace Gesture {

#endif // _TITANIUM_MOBILE_WINDOWS_MODULES_SHAKEGESTUREHELPER_H_
