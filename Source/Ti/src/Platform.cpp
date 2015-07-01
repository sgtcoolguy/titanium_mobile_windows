/**
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/Platform.hpp"
#include "Titanium/detail/TiImpl.hpp"
#include "TitaniumWindows/Utility.hpp"
#include "TitaniumWindows/DisplayCaps.hpp"
#include <iostream>
#include <objbase.h>
#include <ppltasks.h>
#include <algorithm>
#include <collection.h>
#include <regex>

namespace TitaniumWindows
{
	Platform::Platform(const JSContext& js_context) TITANIUM_NOEXCEPT
	    : Titanium::PlatformModule(js_context),
#if defined(__cplusplus_winrt)
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
	      osname__("windowsphone")
#else
	      osname__("windowsstore")
#endif
#else
	      osname__("unknown")
#endif
	{
		TITANIUM_LOG_DEBUG("Platform::ctor");
		setDisplayCaps(get_context().CreateObject(JSExport<TitaniumWindows::DisplayCaps>::Class()));
	}

	std::string Platform::osname() const TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_DEBUG("Platform::osname");
		return osname__;
	}

	std::string Platform::createUUID() TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_DEBUG("Platform::createUUID");
		GUID gdn;
		CoCreateGuid(&gdn);
		::Platform::Guid guid(gdn);
		auto guid_str = guid.ToString();
		return std::string((guid_str->Begin()) + 1, (guid_str->End()) - 1);
	}

	std::string Platform::address() const TITANIUM_NOEXCEPT
	{
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
			// Enforce Wifi? This definitely doesn't work for Simulator properly. We also may not want to enforce wifi for desktop...
			//if (host->IPInformation && host->IPInformation->NetworkAdapter->IanaInterfaceType == 71) {
				const auto hostname = TitaniumWindows::Utility::ConvertString(host->CanonicalName);
				std::smatch match;
				if (std::regex_search(hostname, match, pattern)) {
					result = hostname;
				}
			//}
		});
		return result;
	}
	std::string Platform::architecture() const TITANIUM_NOEXCEPT
	{
		// FIXME This is what architectures the _app_ supports, not the current processor architecture!
		// Use GetNativeSystemInfo processor architecture enum value and map it? Maybe only for unknown/neutral?
		using namespace Windows::System;
		switch (Windows::ApplicationModel::Package::Current->Id->Architecture) {
			case ProcessorArchitecture::Arm:
				return "arm";
			case ProcessorArchitecture::X86:
				return "x86";
			case ProcessorArchitecture::X64:
				return "x64";
			case ProcessorArchitecture::Neutral:
				return "neutral";
			default:
				return "unknown";
		}
	}
	
	std::uint64_t Platform::availableMemory() const TITANIUM_NOEXCEPT
	{
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
		return Windows::System::MemoryManager::AppMemoryUsageLimit - Windows::System::MemoryManager::AppMemoryUsage;
#else
		return 0;
#endif
	}

	double Platform::batteryLevel() const TITANIUM_NOEXCEPT
	{
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
		return Windows::Phone::Devices::Power::Battery::GetDefault()->RemainingChargePercent;
#else
		return 0;
#endif
	}

	bool Platform::batteryMonitoring() const TITANIUM_NOEXCEPT
	{
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
		return true;
#else
		return false;
#endif
	}

	Titanium::Platform::BatteryState Platform::batteryState() const TITANIUM_NOEXCEPT
	{
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
		// We can detect if it's fully charged, but we don't know if it's plugged or not.
		// In this case let's return FULL if 100% charged, otherwise return UNKNOWN.
		const auto percent = Windows::Phone::Devices::Power::Battery::GetDefault()->RemainingChargePercent;
		if (percent == 100) {
			return Titanium::Platform::BatteryState::FULL;
		} else {
			return Titanium::Platform::BatteryState::UNKNOWN;
		}
#else
		return Titanium::Platform::BatteryState::UNKNOWN;
#endif
	}
	std::string Platform::id() const TITANIUM_NOEXCEPT
	{
		return TitaniumWindows::Utility::ConvertString(Windows::System::UserProfile::AdvertisingManager::AdvertisingId);
	}
	std::string Platform::locale() const TITANIUM_NOEXCEPT
	{
		return std::locale("").name();
	}
	std::string Platform::macaddress() const TITANIUM_NOEXCEPT
	{
		return "";
	}
	std::string Platform::manufacturer() const TITANIUM_NOEXCEPT
	{
		const auto deviceInfo = ref new Windows::Security::ExchangeActiveSyncProvisioning::EasClientDeviceInformation();
		return TitaniumWindows::Utility::ConvertString(deviceInfo->SystemManufacturer);
	}
	std::string Platform::model() const TITANIUM_NOEXCEPT
	{
		const auto deviceInfo = ref new Windows::Security::ExchangeActiveSyncProvisioning::EasClientDeviceInformation();
		if (deviceInfo->SystemSku->IsEmpty()) {
			return TitaniumWindows::Utility::ConvertString(deviceInfo->SystemProductName);
		} else {
			return TitaniumWindows::Utility::ConvertString(deviceInfo->SystemSku);
		}
	}
	std::string Platform::name() const TITANIUM_NOEXCEPT
	{
		return "windows";
	}
	std::string Platform::netmask() const TITANIUM_NOEXCEPT
	{

		using namespace Windows::Devices::Enumeration;

	

		using namespace Windows::Networking;
		using namespace Windows::Networking::Connectivity;
		const auto hosts = NetworkInformation::GetHostNames();
		std::string result = "";
		std::for_each(begin(hosts), end(hosts), [&result](HostName^ host) {
			if (host->IPInformation) {
				// FIXME How can we ensure this is the Wifi connection?
				auto prefix = host->IPInformation->PrefixLength;
				if (prefix) {
					auto value = prefix->Value;
					// Convert to subnet mask! Any way to do this more conveniently? a giant switch is just plain bad.
					// http://www.gadgetwiz.com/network/netmask.html
					switch (value) {
					case 0:
						result = "0.0.0.0";
						break;
					case 1:
						result = "128.0.0.0";
						break;
					case 2:
						result = "192.0.0.0";
						break;
					case 3:
						result = "224.0.0.0";
						break;
					case 4:
						result = "240.0.0.0";
						break;
					case 5:
						result = "248.0.0.0";
						break;
					case 6:
						result = "252.0.0.0";
						break;
					case 7:
						result = "254.0.0.0";
						break;
					case 8:
						result = "255.0.0.0";
						break;
					case 9:
						result = "255.128.0.0";
						break;
					case 10:
						result = "255.192.0.0";
						break;
					case 11:
						result = "255.224.0.0";
						break;
					case 12:
						result = "255.240.0.0";
						break;
					case 13:
						result = "255.248.0.0";
						break;
					case 14:
						result = "255.252.0.0";
						break;
					case 15:
						result = "255.254.0.0";
						break;
					case 16:
						result = "255.255.0.0";
						break;
					case 17:
						result = "255.255.128.0";
						break;
					case 18:
						result = "255.255.192.0";
						break;
					case 19:
						result = "255.255.224.0";
						break;
					case 20:
						result = "255.255.240.0";
						break;
					case 21:
						result = "255.255.248.0";
						break;
					case 22:
						result = "255.255.252.0";
						break;
					case 23:
						result = "255.255.254.0";
						break;
					case 24:
						result = "255.255.255.0";
						break;
					case 25:
						result = "255.255.255.128";
						break;
					case 26:
						result = "255.255.255.192";
						break;
					case 27:
						result = "255.255.255.224";
						break;
					case 28:
						result = "255.255.255.240";
						break;
					case 29:
						result = "255.255.255.248";
						break;
					case 30:
						result = "255.255.255.252";
						break;
					case 31:
						result = "255.255.255.254";
						break;
					case 32:
						result = "255.255.255.255";
						break;
					default:
						break;
					}
				}
			}
		});
		return result;
	}
	std::string Platform::ostype() const TITANIUM_NOEXCEPT
	{
		return architecture();
	}
	unsigned Platform::processorCount() const TITANIUM_NOEXCEPT
	{
		_SYSTEM_INFO sysInfo;
		GetNativeSystemInfo(&sysInfo);
		return sysInfo.dwNumberOfProcessors;
	}
	std::string Platform::runtime() const TITANIUM_NOEXCEPT
	{
		return "javascriptcore";
	}
	std::string Platform::username() const TITANIUM_NOEXCEPT
	{
		using namespace Windows::System::UserProfile;
		if (UserInformation::NameAccessAllowed) {
			::Platform::String^ name;
			concurrency::event event;
			concurrency::task<::Platform::String^>(UserInformation::GetDisplayNameAsync()).then([&name, &event](concurrency::task<::Platform::String^> task) {
					name = task.get();
					event.set();
				},
				concurrency::task_continuation_context::use_arbitrary());
			event.wait();
			return TitaniumWindows::Utility::ConvertString(name);
		} else {
			TITANIUM_LOG_ERROR("Access to account name disabled by Privacy Setting or Group Policy");
			return "";
		}
	}
	std::string Platform::version() const TITANIUM_NOEXCEPT
	{
		// Looks like there's no way to retrieve OS version from WinRT
		// For now let's return dummy version string
		return "0.0";
	}

	bool Platform::canOpenURL(const std::string& url) TITANIUM_NOEXCEPT
	{
		// On Windows, just check if it's a well-formed uri or not, because
		// the operating system provides the user with a link to search for app from the store on launch.
		const auto uri = ref new Windows::Foundation::Uri(TitaniumWindows::Utility::ConvertString(url));
		return !uri->Suspicious;
	}
	bool Platform::openURL(const std::string& url) TITANIUM_NOEXCEPT
	{
		const auto uri = ref new Windows::Foundation::Uri(TitaniumWindows::Utility::ConvertString(url));
		bool result = false;
		concurrency::event event;
		concurrency::task<bool>(Windows::System::Launcher::LaunchUriAsync(uri)).then([&result, &event](concurrency::task<bool> task) {
				result = task.get();
				event.set();
			},
			concurrency::task_continuation_context::use_arbitrary());
		event.wait();

		return result;
	}
	bool Platform::is24HourTimeFormat() TITANIUM_NOEXCEPT
	{
		return false;
	}

	void Platform::JSExportInitialize()
	{
		JSExport<Platform>::SetClassVersion(1);
		JSExport<Platform>::SetParent(JSExport<Titanium::PlatformModule>::Class());
	}

}  // namespace TitaniumWindows
