/** -*- mode: c++ -*-
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MOBILE_WINDOWS_MODULES_NETWORK_TINETWORK_H_
#define _TITANIUM_MOBILE_WINDOWS_MODULES_NETWORK_TINETWORK_H_

#include "TiCore/TiProxy.h"
#include <iostream>
#include "TiCore/TiConstants.h"
#include "TiCore/TiUtils.h"

namespace Network {

class NetworkModule final : public Ti::Proxy, public virtual_enable_shared_from_this<NetworkModule> {

 public:

	static Ti::Value Initialize(const std::string& ns, Ti::Value& obj);

 protected:

	NetworkModule(const std::string& name, const std::vector<Ti::Value>& arguments) : Ti::Proxy(name, arguments) {
	}

 private:


	////////////////////////////////////////////////////////////////////////
	//
	// Proxy macro infrastructure goes below here.
	//
	////////////////////////////////////////////////////////////////////////

	TI_CREATE_PROXY(NetworkModule);

	static JSClassRef Parent() {
		return Ti::Proxy::ClassDef();
	}

	// Constant for append mode for file operations.
	TI_CREATE_METHOD(NetworkModule, getMODE_APPEND);
	Ti::Value getMODE_APPEND(const std::vector<Ti::Value>& arguments) const {
		return Ti::Value(static_cast<double>(Ti::Constants::TI_APPEND));
	}

	// Gets the value of the applicationCacheDirectory property.
	TI_CREATE_METHOD(NetworkModule, getApplicationCacheDirectory);
	Ti::Value getApplicationCacheDirectory(const std::vector<Ti::Value>& arguments) const {
#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
		const auto value = Windows::Storage::ApplicationData::Current->LocalCacheFolder->Path;
		return Ti::Value(Ti::Utils::GetPlatformString(value));
#else
		std::clog << "[WARN] Filesystem.applicationCacheDirectory is not supported on Windows Store. Returning Undefined" << std::endl;
		return Ti::Value::Undefined();
#endif
    }


};

}	 // namespace Network {

#endif // _TITANIUM_MOBILE_WINDOWS_MODULES_NETWORK_TINETWORK_H_
