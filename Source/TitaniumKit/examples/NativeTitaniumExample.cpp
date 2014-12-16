/**
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "NativeTitaniumExample.hpp"
#include <iostream>

NativeTitaniumExample::NativeTitaniumExample(const JSContext& js_context) TITANIUM_NOEXCEPT
: Titanium::TitaniumModule(js_context) {
  setUserAgent(get_context().CreateString("__TITANIUM_USER_AGENT__"));
}

NativeTitaniumExample::NativeTitaniumExample(const NativeTitaniumExample& rhs, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
: Titanium::TitaniumModule(rhs, arguments) {
}

std::string NativeTitaniumExample::version() const TITANIUM_NOEXCEPT {
  TITANIUM_LOG_DEBUG("NativeTitaniumExample::version");
  return "__TITANIUM_VERSION__";
}

std::string NativeTitaniumExample::buildDate() const TITANIUM_NOEXCEPT {
  TITANIUM_LOG_DEBUG("NativeTitaniumExample::buildDate");
  return "__TITANIUM_BUILD_DATE__";
}

std::string NativeTitaniumExample::buildHash() const TITANIUM_NOEXCEPT {
  TITANIUM_LOG_DEBUG("NativeTitaniumExample::buildHash");
  return "__TITANIUM_BUILD_HASH__";
}

void NativeTitaniumExample::JSExportInitialize() {
  JSExport<NativeTitaniumExample>::SetClassVersion(1);
  JSExport<NativeTitaniumExample>::SetParent(JSExport<Titanium::TitaniumModule>::Class());
}
