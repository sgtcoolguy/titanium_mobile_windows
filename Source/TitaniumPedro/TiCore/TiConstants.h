/** -*- mode: c++ -*-
 * Constants.h
 *
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2013 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MOBILE_WINDOWS_TICORE_TICONSTANTS_H_
#define _TITANIUM_MOBILE_WINDOWS_TICORE_TICONSTANTS_H_

#include <string>

namespace Ti {

class Constants {

 public:

	static const std::string EventType;

	// Touch events:
	static const std::string EventClick;
	static const std::string EventDoubleClick;
	static const std::string EventSingleTap;
	static const std::string EventDoubleTap;
	static const std::string EventLongPress;
	static const std::string EventLongClick;
	static const std::string EventPinch;
	static const std::string EventTouchStart;
	static const std::string EventTouchMove;
	static const std::string EventTouchEnd;
	static const std::string EventTouchCancel;

	static const std::string EventReturn;
	static const std::string EventFocus;
	static const std::string EventBlur;
	static const std::string EventChange;
	static const std::string EventComplete;
	static const std::string EventError;

	static const std::string EventClose;
	static const std::string EventOpen;
	static const std::string EventBackButton;

	static const std::string EventUpdate;
	static const std::string EventShake;
	static const std::string EventOrientationChange;
  static const std::string EventBeforeLoad;
  static const std::string EventLoad;

	static const std::string EventAuthorization;
	static const std::string EventCalibration;
	static const std::string EventLocation;
	static const std::string EventHeading;
	static const std::string EventLocationUpdatePaused;
	static const std::string EventLocationUpdateResumed;

	static const std::string EventPostLayout;

	static const std::string SizeSIZE;
	static const std::string SizeFILL;

	static const std::string LayoutHorizontal;
	static const std::string LayoutVertical;
	static const std::string NotSupported;

	static const int TI_READ;
	static const int TI_WRITE;
	static const int TI_APPEND;

	static const std::string ResourcesDir;

	static const std::string separator;
	static const std::string lineEnding;

};

}	// namespace Ti {

#endif	// _TITANIUM_MOBILE_WINDOWS_TICORE_TICONSTANTS_H_
