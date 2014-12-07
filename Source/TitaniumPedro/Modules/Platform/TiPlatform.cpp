/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#include "Modules/Platform/TiPlatform.h"
#include "Modules/Platform/TiPlatformDisplayCaps.h"
#include <objbase.h>
#include <ppltasks.h>
#include <algorithm>
#include <collection.h>
#include <regex>
#include "TiCore/TiRuntimeFunctions.h"
#include "TiCore/TiUtils.h"

namespace Ti { namespace Platform {


Ti::Value Platform::Initialize(const std::string& ns, Ti::Value& obj) {
	Ti::Value result;
	static std::once_flag of;
	std::call_once(of, [&result, &ns, &obj] {
			// Create a temporary object

			Ti::Value pfModule;
			pfModule.setProperty("global", Ti::Value(Ti::Runtime::instance().globalObject()));
			pfModule.setProperty("TiPlatform", Platform::CreateConstructor());
			pfModule.setProperty("TiPlatformDisplayCaps", DisplayCaps::CreateConstructor());
			result = Ti::evaluateScriptFileInObject("TitaniumPedro/ti.platform.js", pfModule);
			obj.setProperty(ns, result);
		});

	return result;
}

void Ti::Platform::Platform::logStatistics() {
	static const std::string log_prefix { "MDL: Ti::Platform::Platform:logStatistics:" };
	std::clog << log_prefix << " [DEBUG] TiValue: " << Ti::Value::get_ctor_counter() << " created, " << Ti::Value::get_dtor_counter() << " destroyed." << std::endl;
	std::clog << log_prefix << " [DEBUG] BaseProxy: " << BaseProxy::get_ctor_counter() << " created, " << BaseProxy::get_dtor_counter() << " destroyed." << std::endl;

	using namespace std::chrono;
	ProxyStatistics_t& proxy_statistics = get_proxy_statistics();
	for (auto iter = proxy_statistics.begin(); iter != proxy_statistics.end(); ++iter) {
		const auto &name = iter->first;
		const auto &stats = iter->second;
		const double mean_ms = duration_cast<microseconds>(stats.mean()).count();
		const double standard_deviation_ms = duration_cast<microseconds>(stats.standard_deviation()).count();
		std::clog << log_prefix << " [DEBUG] " << name << " had " << stats.count() << " calls and ran for " << mean_ms << " +/- " << standard_deviation_ms << " us." << std::endl;
	}
}

Ti::Value Ti::Platform::Platform::getStatistics(const std::vector<Ti::Value>& arguments) {
	Ti::Value val;
	val.setProperty("TiValue_ctor_count", Ti::Value(double(Ti::Value::get_ctor_counter())));
	val.setProperty("TiValue_dtor_count", Ti::Value(double(Ti::Value::get_dtor_counter())));
	val.setProperty("BaseProxy_ctor_count", Ti::Value(double(BaseProxy::get_ctor_counter())));
	val.setProperty("BaseProxy_dtor_count", Ti::Value(double(BaseProxy::get_dtor_counter())));
	logStatistics();
	return val;
}

// Gets the value of the address property.
Ti::Value Platform::getAddress(const std::vector<Ti::Value>& arguments) {
	using namespace Windows::Networking;
	using namespace Windows::Networking::Connectivity;

	const auto hosts = NetworkInformation::GetHostNames();
	// Check if it's ipaddress because Windows returns muliple result which contains both host name and ip address
	const std::regex pattern("(\\d{1,3}(\\.\\d{1,3}){3})");
	std::string result;
	std::for_each(begin(hosts), end(hosts), [&result, &pattern](HostName^ host) {
		// Let's take the first one and ignore others
		if (!result.empty()) {
			return;
		}
		const auto hostname = Ti::Utils::GetPlatformString(host->CanonicalName);
		std::smatch match;
		if (std::regex_search(hostname, match, pattern)) {
			result = hostname;
		}
	});
	if (result.empty()) {
		return Ti::Value::Undefined();
	} else {
		return Ti::Value(result);
	}
}

// Returns whether the system is configured with a default
// application to handle the URL's protocol.
Ti::Value Platform::canOpenURL(const std::vector<Ti::Value>& arguments) {
	// On Windows, just check if it's a well-formed uri or not, because
	// the operating system provides the user with a link to search for app from the store on launch.
	const auto uri = ref new Windows::Foundation::Uri(Ti::Utils::GetPlatformString(arguments.at(0).toString()));
	return Ti::Value(!uri->Suspicious);
}

// Opens this URL using the system's default application for its protocol.
Ti::Value Platform::openURL(const std::vector<Ti::Value>& arguments) {
	const auto uri = ref new Windows::Foundation::Uri(Ti::Utils::GetPlatformString(arguments.at(0).toString()));
	bool result = false;
	concurrency::event event;
	concurrency::task<bool>(Windows::System::Launcher::LaunchUriAsync(uri)).then([&result, &event](concurrency::task<bool> task) {
		result = task.get();
		event.set();
	}, concurrency::task_continuation_context::use_arbitrary());
	event.wait();
	return Ti::Value(result);
}

// Creates a globally-unique identifier.
Ti::Value Platform::createUUID(const std::vector<Ti::Value>& arguments) {
	GUID gdn;
	CoCreateGuid(&gdn);
	::Platform::Guid guid(gdn);
	return Ti::Value(Ti::Utils::GetPlatformString(guid.ToString()));
}

// Gets the value of the architecture property.
Ti::Value Platform::getArchitecture(const std::vector<Ti::Value>& arguments) {
	using namespace Windows::System;
	switch (Windows::ApplicationModel::Package::Current->Id->Architecture) {
	case ProcessorArchitecture::Arm:
		return Ti::Value("arm");
	case ProcessorArchitecture::X86:
		return Ti::Value("x86");
	case ProcessorArchitecture::X64:
		return Ti::Value("x64");
	case ProcessorArchitecture::Neutral:
		return Ti::Value("neutral");
	default:
		return Ti::Value("unknown");
	}
}

// Gets the value of the ostype property.
Ti::Value Platform::getOstype(const std::vector<Ti::Value>& arguments) {
	return this->getArchitecture(arguments);
}

// Gets the value of the version property.
Ti::Value Platform::getVersion(const std::vector<Ti::Value>& arguments) {
	// Looks like there's no way to retrieve OS version from WinRT
	// For now let's return dummy version string
	return Ti::Value("0.0");
}

// Gets the value of the id property.
Ti::Value Platform::getId(const std::vector<Ti::Value>& arguments) {
	return Ti::Value(Ti::Utils::GetPlatformString(Windows::System::UserProfile::AdvertisingManager::AdvertisingId));
}

// Gets the value of the manufacturer property.
Ti::Value Platform::getManufacturer(const std::vector<Ti::Value>& arguments) {
	const auto deviceInfo = ref new Windows::Security::ExchangeActiveSyncProvisioning::EasClientDeviceInformation();
	return Ti::Value(Ti::Utils::GetPlatformString(deviceInfo->SystemManufacturer));
}

// Gets the value of the model property.
Ti::Value Platform::getModel(const std::vector<Ti::Value>& arguments) {
	const auto deviceInfo = ref new Windows::Security::ExchangeActiveSyncProvisioning::EasClientDeviceInformation();
	if (deviceInfo->SystemSku->IsEmpty()) {
		return Ti::Value(Ti::Utils::GetPlatformString(deviceInfo->SystemProductName));
	} else {
		return Ti::Value(Ti::Utils::GetPlatformString(deviceInfo->SystemSku));
	}
}

// Gets the value of the username property.
Ti::Value Platform::getUsername(const std::vector<Ti::Value>& arguments) {
	using namespace Windows::System::UserProfile;
	if (UserInformation::NameAccessAllowed) {
		::Platform::String^ name;
		concurrency::event event;
		concurrency::task<::Platform::String^>(UserInformation::GetDisplayNameAsync()).then([&name, &event](concurrency::task<::Platform::String^> task) {
			name = task.get();
			event.set();
		}, concurrency::task_continuation_context::use_arbitrary());
		event.wait();
		return Ti::Value(Ti::Utils::GetPlatformString(name));
	} else {
		std::clog << "[ERROR] Access to account name disabled by Privacy Setting or Group Policy" << std::endl;
		return Ti::Value::Undefined();
	}
}

// Gets the value of the locale property.
Ti::Value Platform::getLocale(const std::vector<Ti::Value>& arguments) {
	return Ti::Value(std::locale("").name());
}


const JSStaticFunction Platform::ClassMethods[] = {
	{ "getStatistics", _getStatistics, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getBATTERY_STATE_CHARGING", _getBATTERY_STATE_CHARGING, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getBATTERY_STATE_FULL", _getBATTERY_STATE_FULL, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getBATTERY_STATE_UNKNOWN", _getBATTERY_STATE_UNKNOWN, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getBATTERY_STATE_UNPLUGGED", _getBATTERY_STATE_UNPLUGGED, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getAddress", _getAddress, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getArchitecture", _getArchitecture, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getAvailableMemory", _getAvailableMemory, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getBatteryLevel", _getBatteryLevel, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getBatteryMonitoring", _getBatteryMonitoring, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getBatteryState", _getBatteryState, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getId", _getId, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getLocale", _getLocale, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getMacaddress", _getMacaddress, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getManufacturer", _getManufacturer, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getModel", _getModel, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getName", _getName, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getNetmask", _getNetmask, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getOsname", _getOsname, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getOstype", _getOstype, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getProcessorCount", _getProcessorCount, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getRuntime", _getRuntime, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getUsername", _getUsername, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getVersion", _getVersion, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "canOpenURL", _canOpenURL, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "createUUID", _createUUID, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "is24HourTimeFormat", _is24HourTimeFormat, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "openURL", _openURL, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ 0, 0, 0 }
};

}} // namespace Ti { namespace Platform {
