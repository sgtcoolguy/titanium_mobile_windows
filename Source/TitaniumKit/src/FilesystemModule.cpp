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

  JSValue FilesystemModule::separator() const TITANIUM_NOEXCEPT {
    return get_context().CreateString("/");
  }
  
  void FilesystemModule::JSExportInitialize() {
    JSExport<FilesystemModule>::SetClassVersion(1);
    JSExport<FilesystemModule>::SetParent(JSExport<Module>::Class());
    JSExport<FilesystemModule>::AddFunctionProperty("getFile",  std::mem_fn(&FilesystemModule::getFile_ArgumentValidator));
    JSExport<FilesystemModule>::AddValueProperty("MODE_READ",   std::mem_fn(&FilesystemModule::MODE_READ));
    JSExport<FilesystemModule>::AddValueProperty("MODE_WRITE",  std::mem_fn(&FilesystemModule::MODE_WRITE));
    JSExport<FilesystemModule>::AddValueProperty("MODE_APPEND", std::mem_fn(&FilesystemModule::MODE_APPEND));
    JSExport<FilesystemModule>::AddValueProperty("separator",   std::mem_fn(&FilesystemModule::separator));
  }
  
  JSObject FilesystemModule::getFile(const JSString& path) TITANIUM_NOEXCEPT {
    TITANIUM_LOG_DEBUG("Filesystem::getFile: ", path);

    JSValue Titanium_property = get_context().get_global_object().GetProperty("Titanium");
    TITANIUM_ASSERT(Titanium_property.IsObject()); // precondition
    JSObject Titanium = Titanium_property;

    JSValue FS_property = Titanium.GetProperty("Filesystem");
    TITANIUM_ASSERT(FS_property.IsObject()); // precondition
    JSObject FS = FS_property;

    JSValue File_property = FS.GetProperty("File");
    TITANIUM_ASSERT(File_property.IsObject()); // precondition
    JSObject File = File_property;

    return File.CallAsConstructor(path);
  }
  
  JSValue FilesystemModule::getFile_ArgumentValidator(const std::vector<JSValue>& arguments, JSObject& this_object) {
    JSValue Titanium_property = get_context().get_global_object().GetProperty("Titanium");
    TITANIUM_ASSERT(Titanium_property.IsObject()); // precondition
    JSObject Titanium = Titanium_property;

    JSValue FS_property = Titanium.GetProperty("Filesystem");
    TITANIUM_ASSERT(FS_property.IsObject()); // precondition
    JSObject FS = FS_property;

    JSValue sep_property = FS.GetProperty("separator");
    TITANIUM_ASSERT(sep_property.IsString()); // precondition
    JSString separator = static_cast<JSString>(sep_property);

    // join paths with separator
    std::ostringstream oss;
    const auto size = arguments.size();
    for (auto i = 0; i < size; i++) {
      oss << static_cast<JSString>(arguments.at(i));
      if (i+1 < size) {
        oss << separator;
      }
    }
    return getFile(oss.str());
  }
  
} // namespace Titanium {
