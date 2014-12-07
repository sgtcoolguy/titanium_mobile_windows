/** -*- mode: c++ -*-
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MOBILE_WINDOWS_MODULES_PLATFORM_TIPLATFORM_H_
#define _TITANIUM_MOBILE_WINDOWS_MODULES_PLATFORM_TIPLATFORM_H_

#include "TiCore/TiProxy.h"

namespace Ti { namespace Platform {

enum BatteryState {
	UNKNOWN = 0,
	UNPLUGGED,
	CHARGING,
	FULL
};

class Platform : public Ti::Proxy, public virtual_enable_shared_from_this<Platform> {

 public:

	static Ti::Value Initialize(const std::string& ns, Ti::Value& obj);
	static void logStatistics();

 protected:

	Platform(const std::string& name, const std::vector<Ti::Value>& arguments) : Ti::Proxy(name, arguments) {
	}

	////////////////////////////////////////////////////////////////////////
	//
	// Proxy macro infrastructure goes below here.
	//
	////////////////////////////////////////////////////////////////////////

	TI_CREATE_PROXY(Platform);

	static JSClassRef Parent() {
		return Ti::Proxy::ClassDef();
	}

	TI_CREATE_METHOD(Platform, getStatistics);
	Ti::Value getStatistics(const std::vector<Ti::Value>& arguments);

	// Constant to indicate that the system is plugged in and
	// currently being charged.
	TI_CREATE_METHOD(Platform, getBATTERY_STATE_CHARGING);
	Ti::Value getBATTERY_STATE_CHARGING(const std::vector<Ti::Value>& arguments) {
		return Ti::Value(static_cast<double>(BatteryState::CHARGING));
	}

	// Constant to indicate that the battery is fully charged.
	TI_CREATE_METHOD(Platform, getBATTERY_STATE_FULL);
	Ti::Value getBATTERY_STATE_FULL(const std::vector<Ti::Value>& arguments) {
		return Ti::Value(static_cast<double>(BatteryState::FULL));
	}

	// Constant to indicate that the battery state is not known or
	// monitoring is disabled.
	TI_CREATE_METHOD(Platform, getBATTERY_STATE_UNKNOWN);
	Ti::Value getBATTERY_STATE_UNKNOWN(const std::vector<Ti::Value>& arguments) {
		return Ti::Value(static_cast<double>(BatteryState::UNKNOWN));
	}

	// Constant to indicate that the system is unplugged.
	TI_CREATE_METHOD(Platform, getBATTERY_STATE_UNPLUGGED);
	Ti::Value getBATTERY_STATE_UNPLUGGED(const std::vector<Ti::Value>& arguments) {
		return Ti::Value(static_cast<double>(BatteryState::UNPLUGGED));
	}

	// Gets the value of the address property.
	TI_CREATE_METHOD(Platform, getAddress);
	Ti::Value getAddress(const std::vector<Ti::Value>& arguments);

	// Gets the value of the architecture property.
	TI_CREATE_METHOD(Platform, getArchitecture);
	Ti::Value getArchitecture(const std::vector<Ti::Value>& arguments);

	// Gets the value of the availableMemory property.
	TI_CREATE_METHOD(Platform, getAvailableMemory);
	Ti::Value getAvailableMemory(const std::vector<Ti::Value>& arguments) {
		return Ti::Value::Undefined();
	}

	// Gets the value of the batteryLevel property.
	TI_CREATE_METHOD(Platform, getBatteryLevel);
	Ti::Value getBatteryLevel(const std::vector<Ti::Value>& arguments) {
#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
		return Ti::Value(static_cast<double>(Windows::Phone::Devices::Power::Battery::GetDefault()->RemainingChargePercent));
#else
		return Ti::Value::Undefined();
#endif
	}

	// Gets the value of the batteryMonitoring property.
	TI_CREATE_METHOD(Platform, getBatteryMonitoring);
	Ti::Value getBatteryMonitoring(const std::vector<Ti::Value>& arguments) {
#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
		return Ti::Value(true);
#else
		return Ti::Value(false);
#endif
	}

	// Gets the value of the batteryState property.
	TI_CREATE_METHOD(Platform, getBatteryState);
	Ti::Value getBatteryState(const std::vector<Ti::Value>& arguments) {
#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
		// We can detect if it's fully charged, but we don't know if it's plugged or not.
		// In this case let's return FULL if 100% charged, otherwise return UNKNOWN.
		const auto percent = Windows::Phone::Devices::Power::Battery::GetDefault()->RemainingChargePercent;
		if (percent == 100) {
			return Ti::Value(static_cast<double>(BatteryState::FULL));
		} else {
			return Ti::Value(static_cast<double>(BatteryState::UNKNOWN));
		}
#else
		return Ti::Value(static_cast<double>(BatteryState::UNKNOWN));
#endif
	}

	// Gets the value of the id property.
	TI_CREATE_METHOD(Platform, getId);
	Ti::Value getId(const std::vector<Ti::Value>& arguments);

	// Gets the value of the locale property.
	TI_CREATE_METHOD(Platform, getLocale);
	Ti::Value getLocale(const std::vector<Ti::Value>& arguments);

	// Gets the value of the macaddress property.
	TI_CREATE_METHOD(Platform, getMacaddress);
	Ti::Value getMacaddress(const std::vector<Ti::Value>& arguments) {
		// returns application unique id
		return this->getId(arguments);
	}

	// Gets the value of the manufacturer property.
	TI_CREATE_METHOD(Platform, getManufacturer);
	Ti::Value getManufacturer(const std::vector<Ti::Value>& arguments);

	// Gets the value of the model property.
	TI_CREATE_METHOD(Platform, getModel);
	Ti::Value getModel(const std::vector<Ti::Value>& arguments);

	// Gets the value of the name property.
	TI_CREATE_METHOD(Platform, getName);
	Ti::Value getName(const std::vector<Ti::Value>& arguments) {
		return Ti::Value("windows");
	}

	// Gets the value of the netmask property.
	TI_CREATE_METHOD(Platform, getNetmask);
	Ti::Value getNetmask(const std::vector<Ti::Value>& arguments) {
		return Ti::Value::Undefined();
	}

	// Gets the value of the osname property.
	TI_CREATE_METHOD(Platform, getOsname);
	Ti::Value getOsname(const std::vector<Ti::Value>& arguments) {
#if defined(__cplusplus_winrt)
#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
		return Ti::Value("windowsphone");
#else
		return Ti::Value("windowsstore");
#endif
#else
		return Ti::Value("unknown");
#endif
	}

	// Gets the value of the ostype property.
	TI_CREATE_METHOD(Platform, getOstype);
	Ti::Value getOstype(const std::vector<Ti::Value>& arguments);

	// Gets the value of the processorCount property.
	TI_CREATE_METHOD(Platform, getProcessorCount);
	Ti::Value getProcessorCount(const std::vector<Ti::Value>& arguments) {
		return Ti::Value::Undefined();
	}

	// Gets the value of the runtime property.
	TI_CREATE_METHOD(Platform, getRuntime);
	Ti::Value getRuntime(const std::vector<Ti::Value>& arguments) {
		return Ti::Value("javascriptcore");
	}

	// Gets the value of the username property.
	TI_CREATE_METHOD(Platform, getUsername);
	Ti::Value getUsername(const std::vector<Ti::Value>& arguments);

	// Gets the value of the version property.
	TI_CREATE_METHOD(Platform, getVersion);
	Ti::Value getVersion(const std::vector<Ti::Value>& arguments);

	// Returns whether the system is configured with a default
	// application to handle the URL's protocol.
	TI_CREATE_METHOD(Platform, canOpenURL);
	Ti::Value canOpenURL(const std::vector<Ti::Value>& arguments);

	// Creates a globally-unique identifier.
	TI_CREATE_METHOD(Platform, createUUID);
	Ti::Value createUUID(const std::vector<Ti::Value>& arguments);

	// Returns whether the system settings are configured to show
	// times in 24-hour format.
	TI_CREATE_METHOD(Platform, is24HourTimeFormat);
	Ti::Value is24HourTimeFormat(const std::vector<Ti::Value>& arguments) {
		return Ti::Value::Undefined();
	}

	// Opens this URL using the system's default application for its
	// protocol.
	TI_CREATE_METHOD(Platform, openURL);
	Ti::Value openURL(const std::vector<Ti::Value>& arguments);

private:

};

}} // namespace Ti { namespace Platform {

#endif // _TITANIUM_MOBILE_WINDOWS_MODULES_PLATFORM_TIPLATFORM_H_
