/**
 * Titanium.Platform for Windows
 * Author: Gary Mathews
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/Platform.hpp"
#include "Titanium/detail/TiBase.hpp"
#include <iostream>
#include <objbase.h>

namespace TitaniumWindows {

  Platform::Platform(const JSContext& js_context) TITANIUM_NOEXCEPT
    : Titanium::Platform(js_context),
#if defined(__cplusplus_winrt)
#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
    osname__("windowsphone")
#else
    osname__("windowsstore")
#endif
#else
    osname__("unknown")
#endif
  {
    TITANIUM_LOG_DEBUG("Platform::ctor Initialize");
  }

  Platform::Platform(const Platform& rhs, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
    : Titanium::Platform(rhs, arguments),
	osname__(rhs.osname__)
  {
    TITANIUM_LOG_DEBUG("Platform::ctor CallAsConstructor");
  }

  std::string Platform::osname() const TITANIUM_NOEXCEPT{
    TITANIUM_LOG_DEBUG("Platform::osname");
	return osname__;
  }

  std::string Platform::createUUID() TITANIUM_NOEXCEPT{
    TITANIUM_LOG_DEBUG("Platform::createUUID");
	GUID gdn;
	CoCreateGuid(&gdn);
	::Platform::Guid guid(gdn);
	std::string guid_str = std::string(guid.ToString()->Begin(), guid.ToString()->End());
	return guid_str;
  }

    void Platform::JSExportInitialize() {
    JSExport<Platform>::SetClassVersion(1);
    JSExport<Platform>::SetParent(JSExport<Titanium::Platform>::Class());
  }

}  // namespace TitaniumWindows
