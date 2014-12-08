/**
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/Filesystem.hpp"
#include "Titanium/detail/TiBase.hpp"
#include <iostream>
#include <objbase.h>

namespace TitaniumWindows {

  FilesystemModule::FilesystemModule(const JSContext& js_context) TITANIUM_NOEXCEPT
    : Titanium::FilesystemModule(js_context) {
    TITANIUM_LOG_DEBUG("TitaniumWindows::FilesystemModule::ctor Initialize");
  }

  FilesystemModule::FilesystemModule(const FilesystemModule& rhs, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
    : Titanium::FilesystemModule(rhs, arguments) {
    TITANIUM_LOG_DEBUG("TitaniumWindows::FilesystemModule::ctor CallAsConstructor");
  }

  FilesystemModule::~FilesystemModule() {
    TITANIUM_LOG_DEBUG("TitaniumWindows::FilesystemModule::dtor");
  }

  void FilesystemModule::JSExportInitialize() {
    JSExport<FilesystemModule>::SetClassVersion(1);
    JSExport<FilesystemModule>::SetParent(JSExport<Titanium::FilesystemModule>::Class());
  }

  JSValue FilesystemModule::separator() const TITANIUM_NOEXCEPT {
    return get_context().CreateString("\\");
  }

}  // namespace TitaniumWindows
