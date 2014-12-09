/**
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "NativeFilesystemExample.hpp"
#include <iostream>

NativeFilesystemExample::NativeFilesystemExample(const JSContext& js_context) TITANIUM_NOEXCEPT
: Titanium::FilesystemModule(js_context) {
}

NativeFilesystemExample::NativeFilesystemExample(const NativeFilesystemExample& rhs, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
: Titanium::FilesystemModule(rhs, arguments) {
}

void NativeFilesystemExample::JSExportInitialize() {
  JSExport<NativeFilesystemExample>::SetClassVersion(1);
  JSExport<NativeFilesystemExample>::SetParent(JSExport<Titanium::FilesystemModule>::Class());
}

JSValue NativeFilesystemExample::getFile(const JSString&) TITANIUM_NOEXCEPT {
  return get_context().CreateNull();
}
JSValue NativeFilesystemExample::createTempDirectory() TITANIUM_NOEXCEPT {
  return get_context().CreateNull();
}
JSValue NativeFilesystemExample::createTempFile() TITANIUM_NOEXCEPT {
  return get_context().CreateNull();
}
bool NativeFilesystemExample::isExternalStoragePresent() TITANIUM_NOEXCEPT {
  return false;
}
JSValue NativeFilesystemExample::openStream(std::unordered_set<Titanium::Filesystem::MODE> modes, const JSString& path) TITANIUM_NOEXCEPT {
  return get_context().CreateNull();
}
JSString NativeFilesystemExample::separator() const TITANIUM_NOEXCEPT {
  return "/";
}
JSString NativeFilesystemExample::applicationCacheDirectory() const TITANIUM_NOEXCEPT {
  return "";
}
JSString NativeFilesystemExample::applicationDataDirectory() const TITANIUM_NOEXCEPT {
  return "";
}
JSString NativeFilesystemExample::applicationDirectory() const TITANIUM_NOEXCEPT {
  return "";
}
JSString NativeFilesystemExample::applicationSupportDirectory() const TITANIUM_NOEXCEPT {
  return "";
}
JSString NativeFilesystemExample::externalStorageDirectory() const TITANIUM_NOEXCEPT {
  return "";
}
JSString NativeFilesystemExample::lineEnding() const TITANIUM_NOEXCEPT {
  return "\n";
}
JSString NativeFilesystemExample::resourcesDirectory() const TITANIUM_NOEXCEPT {
  return "";
}
JSString NativeFilesystemExample::tempDirectory() const TITANIUM_NOEXCEPT {
  return "";
}