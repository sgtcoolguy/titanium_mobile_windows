/**
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "NativeFileExample.hpp"
#include <iostream>

NativeFileExample::NativeFileExample(const JSContext& js_context) TITANIUM_NOEXCEPT
    : Titanium::Filesystem::File(js_context)
{
}

void NativeFileExample::JSExportInitialize()
{
	JSExport<NativeFileExample>::SetClassVersion(1);
	JSExport<NativeFileExample>::SetParent(JSExport<Titanium::Filesystem::File>::Class());
}

bool NativeFileExample::get_executable() const TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeFileExample::get_executable");
	return false;
}
bool NativeFileExample::get_hidden() const TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeFileExample::get_hidden");
	return false;
}
std::string NativeFileExample::get_name() const TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeFileExample::get_name");
	return "";
}
std::string NativeFileExample::get_nativePath() const TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeFileExample::get_nativePath");
	return "";
}
std::shared_ptr<Titanium::Filesystem::File> NativeFileExample::get_parent() const TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeFileExample::get_parent");
	return nullptr;
}
bool NativeFileExample::get_readonly() const TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeFileExample::get_readonly");
	return false;
}
bool NativeFileExample::get_remoteBackup() const TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeFileExample::get_remoteBackup");
	return false;
}
bool NativeFileExample::get_symbolicLink() const TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeFileExample::get_symbolicLink");
	return false;
}
bool NativeFileExample::get_writable() const TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeFileExample::get_writable");
	return false;
}
unsigned long long NativeFileExample::get_size() const TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeFileExample::get_size");
	return 0;
}

bool NativeFileExample::append(const std::shared_ptr<Titanium::Filesystem::File>& data) TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeFileExample::append");
	return false;
}
bool NativeFileExample::copy(const std::string& dest) TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeFileExample::copy");
	return false;
}
bool NativeFileExample::createDirectory() TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeFileExample::createDirectory");
	return false;
}
bool NativeFileExample::createFile() TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeFileExample::createFile");
	return false;
}
std::chrono::milliseconds NativeFileExample::createTimestamp() TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeFileExample::createTimestamp");
	return std::chrono::milliseconds(0);
}
bool NativeFileExample::deleteDirectory(bool recursive) TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeFileExample::deleteDirectory");
	return false;
}
bool NativeFileExample::deleteFile() TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeFileExample::deleteFile");
	return false;
}
bool NativeFileExample::exists() TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeFileExample::exists");
	return false;
}
std::string NativeFileExample::extension() TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeFileExample::extension");
	return "";
}
std::vector<std::string> NativeFileExample::getDirectoryListing() TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeFileExample::getDirectoryListing");
	std::vector<std::string> list;
	return list;
}
bool NativeFileExample::isDirectory() TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeFileExample::isDirectory");
	return false;
}
bool NativeFileExample::isFile() TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeFileExample::isFile");
	return false;
}
std::chrono::milliseconds NativeFileExample::modificationTimestamp() TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeFileExample::modificationTimestamp");
	return std::chrono::milliseconds(0);
}
bool NativeFileExample::move(const std::string& newpath) TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeFileExample::move");
	return false;
}
std::shared_ptr<Titanium::Filesystem::FileStream> NativeFileExample::open(const std::unordered_set<Titanium::Filesystem::MODE>&) TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeFileExample::open");
	return nullptr;
}
std::shared_ptr<Titanium::Blob> NativeFileExample::read() TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeFileExample::read");
	return nullptr;
}
bool NativeFileExample::rename(const std::string& newname) TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeFileExample::rename");
	return false;
}
std::string NativeFileExample::resolve() TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeFileExample::resolve");
	return "";
}
unsigned long long NativeFileExample::spaceAvailable() TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeFileExample::spaceAvailable");
	return false;
}
bool NativeFileExample::write(const std::shared_ptr<Titanium::Filesystem::File>& data, bool append) TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeFileExample::write");
	return false;
}
