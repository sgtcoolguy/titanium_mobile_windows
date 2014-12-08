/**
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/FilesystemModule.hpp"
#include <sstream>

namespace Titanium {
  
  FilesystemModule::FilesystemModule(const JSContext& js_context) TITANIUM_NOEXCEPT
  : Module(js_context)
  ,mode_read__(js_context.CreateNumber(Titanium::Filesystem::Constants::to_underlying_type(Titanium::Filesystem::MODE::READ)))
  ,mode_write__(js_context.CreateNumber(Titanium::Filesystem::Constants::to_underlying_type(Titanium::Filesystem::MODE::WRITE)))
  ,mode_append__(js_context.CreateNumber(Titanium::Filesystem::Constants::to_underlying_type(Titanium::Filesystem::MODE::APPEND)))
  {
  }
  
  FilesystemModule::FilesystemModule(const FilesystemModule& rhs, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
  : Module(rhs, arguments)
  ,mode_read__(rhs.mode_read__)
  ,mode_write__(rhs.mode_write__)
  ,mode_append__(rhs.mode_append__)
  {
  }
  
  JSValue FilesystemModule::MODE_READ() const TITANIUM_NOEXCEPT {
    return mode_read__;
  }
  JSValue FilesystemModule::MODE_WRITE() const TITANIUM_NOEXCEPT {
    return mode_write__;
  }
  JSValue FilesystemModule::MODE_APPEND() const TITANIUM_NOEXCEPT {
    return mode_append__;
  }
  
  void FilesystemModule::JSExportInitialize() {
    JSExport<FilesystemModule>::SetClassVersion(1);
    JSExport<FilesystemModule>::SetParent(JSExport<Module>::Class());
    JSExport<FilesystemModule>::AddFunctionProperty("getFile",  std::mem_fn(&FilesystemModule::getFile_ArgumentValidator));
    JSExport<FilesystemModule>::AddValueProperty("MODE_READ",   std::mem_fn(&FilesystemModule::MODE_READ));
    JSExport<FilesystemModule>::AddValueProperty("MODE_WRITE",  std::mem_fn(&FilesystemModule::MODE_WRITE));
    JSExport<FilesystemModule>::AddValueProperty("MODE_APPEND", std::mem_fn(&FilesystemModule::MODE_APPEND));
  }
  
  JSObject FilesystemModule::getFile(const JSObject& parameters, JSObject& this_object) TITANIUM_NOEXCEPT {
    return get_context().CreateUndefined();
  }
  
  JSValue FilesystemModule::getFile_ArgumentValidator(const std::vector<JSValue>& arguments, JSObject& this_object) {
    JSObject parameters = get_context().CreateObject();
    if (arguments.size() >= 1) {
      const auto _0 = arguments.at(0);
      TITANIUM_ASSERT(_0.IsObject());
      parameters = _0;
    }
    return getFile(parameters, this_object);
  }
  
} // namespace Titanium {
