/** -*- mode: c++ -*-
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MOBILE_WINDOWS_MODULES_FILESYSTEM_TIFILESYSTEM_H_
#define _TITANIUM_MOBILE_WINDOWS_MODULES_FILESYSTEM_TIFILESYSTEM_H_

#include "TiCore/TiProxy.h"
#include <iostream>
#include "TiCore/TiConstants.h"
#include "TiCore/TiUtils.h"

namespace Filesystem {

class FSModule final : public Ti::Proxy, public virtual_enable_shared_from_this<FSModule> {

 public:

	static Ti::Value Initialize(const std::string& ns, Ti::Value& obj);

 protected:

	FSModule(const std::string& name, const std::vector<Ti::Value>& arguments) : Ti::Proxy(name, arguments) {
	}

 private:


	////////////////////////////////////////////////////////////////////////
	//
	// Proxy macro infrastructure goes below here.
	//
	////////////////////////////////////////////////////////////////////////

	TI_CREATE_PROXY(FSModule);

	static JSClassRef Parent() {
		return Ti::Proxy::ClassDef();
	}

	// Constant for append mode for file operations.
	TI_CREATE_METHOD(FSModule, getMODE_APPEND);
	Ti::Value getMODE_APPEND(const std::vector<Ti::Value>& arguments) const {
		return Ti::Value(static_cast<double>(Ti::Constants::TI_APPEND));
	}

	// Constant for read mode for file operations.
	TI_CREATE_METHOD(FSModule, getMODE_READ);
	Ti::Value getMODE_READ(const std::vector<Ti::Value>& arguments) const {
		return Ti::Value(static_cast<double>(Ti::Constants::TI_READ));
	}

	// Constant for write mode for file operations.
	TI_CREATE_METHOD(FSModule, getMODE_WRITE);
	Ti::Value getMODE_WRITE(const std::vector<Ti::Value>& arguments) const {
		return Ti::Value(static_cast<double>(Ti::Constants::TI_WRITE));
	}

	// Gets the value of the applicationCacheDirectory property.
	TI_CREATE_METHOD(FSModule, getApplicationCacheDirectory);
	Ti::Value getApplicationCacheDirectory(const std::vector<Ti::Value>& arguments) const {
#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
		const auto value = Windows::Storage::ApplicationData::Current->LocalCacheFolder->Path;
		return Ti::Value(Ti::Utils::GetPlatformString(value));
#else
		std::clog << "[WARN] Filesystem.applicationCacheDirectory is not supported on Windows Store. Returning Undefined" << std::endl;
		return Ti::Value::Undefined();
#endif
    }

	// Gets the value of the applicationDataDirectory property.
	TI_CREATE_METHOD(FSModule, getApplicationDataDirectory);
	Ti::Value getApplicationDataDirectory(const std::vector<Ti::Value>& arguments) const {
		const auto value = Windows::Storage::ApplicationData::Current->LocalFolder->Path;
		return Ti::Value(Ti::Utils::GetPlatformString(value));
	}

	// Gets the value of the applicationDirectory property.
	TI_CREATE_METHOD(FSModule, getApplicationDirectory);
	Ti::Value getApplicationDirectory(const std::vector<Ti::Value>& arguments) const {
		const auto value = Windows::ApplicationModel::Package::Current->InstalledLocation->Path;
		return Ti::Value(Ti::Utils::GetPlatformString(value));
	}

	// Gets the value of the applicationSupportDirectory property.
	TI_CREATE_METHOD(FSModule, getApplicationSupportDirectory);
	Ti::Value getApplicationSupportDirectory(const std::vector<Ti::Value>& arguments) const {
		// Need to check exception here because this requires "Documents" capability
		try {
			const auto value = Windows::Storage::KnownFolders::DocumentsLibrary->Path;
			return Ti::Value(Ti::Utils::GetPlatformString(value));
		} catch (Platform::AccessDeniedException^ e) {
			return Ti::Value::Null();
		}
	}

	// Gets the value of the externalStorageDirectory property.
	TI_CREATE_METHOD(FSModule, getExternalStorageDirectory);
	Ti::Value getExternalStorageDirectory(const std::vector<Ti::Value>& arguments) const {
		// Need to check exception here because this requires "Removable Storage" capability
		try {
			const auto value = Windows::Storage::KnownFolders::RemovableDevices->Path;
			return Ti::Value(Ti::Utils::GetPlatformString(value));
		}
		catch (Platform::AccessDeniedException^ e) {
			return Ti::Value::Null();
		}
	}

	// Gets the value of the lineEnding property.
	TI_CREATE_METHOD(FSModule, getLineEnding);
	Ti::Value getLineEnding(const std::vector<Ti::Value>& arguments) const {
		return Ti::Value(Ti::Constants::lineEnding);
	}

	// Gets the value of the resRawDirectory property.
	TI_CREATE_METHOD(FSModule, getResRawDirectory);
	Ti::Value getResRawDirectory(const std::vector<Ti::Value>& arguments) const {
		return Ti::Value::Undefined();
	}

	// Gets the value of the resourcesDirectory property.
	TI_CREATE_METHOD(FSModule, getResourcesDirectory);
	Ti::Value getResourcesDirectory(const std::vector<Ti::Value>& arguments) const {
		const auto value = Windows::ApplicationModel::Package::Current->InstalledLocation->Path;
		return Ti::Value(Ti::Utils::GetPlatformString(value) + Ti::Constants::separator + Ti::Constants::ResourcesDir);
	}

	// Gets the value of the separator property.
	TI_CREATE_METHOD(FSModule, getSeparator);
	Ti::Value getSeparator(const std::vector<Ti::Value>& arguments) const {
		return Ti::Value(Ti::Constants::separator);
	}

	// Gets the value of the tempDirectory property.
	TI_CREATE_METHOD(FSModule, getTempDirectory);
	Ti::Value getTempDirectory(const std::vector<Ti::Value>& arguments) const {
		const auto value = Windows::Storage::ApplicationData::Current->TemporaryFolder->Path;
		return Ti::Value(Ti::Utils::GetPlatformString(value));
	}

	// Returns true if the device supports external storage and the
	// external storage device is mounted.
	TI_CREATE_METHOD(FSModule, isExternalStoragePresent);
	Ti::Value isExternalStoragePresent(const std::vector<Ti::Value>& arguments) const {
		return Ti::Value(!getExternalStorageDirectory(arguments).isNull());
	}

	// Opens file using the Ti.IOStream interface.
	TI_CREATE_METHOD(FSModule, openStream);
	Ti::Value openStream(const std::vector<Ti::Value>& arguments) const {
		std::clog << "[WARN] Filesystem.openStream() not implemented yet. Returning Undefined" << std::endl;
		return Ti::Value::Undefined();
	}
};

}	 // namespace Filesystem {

#endif // _TITANIUM_MOBILE_WINDOWS_MODULES_FILESYSTEM_TIFILESYSTEM_H_
