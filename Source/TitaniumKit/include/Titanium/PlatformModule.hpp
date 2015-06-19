/**
 * Copyright (c) 2014-2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_PLATFORMMODULE_HPP_
#define _TITANIUM_PLATFORMMODULE_HPP_

#include "Titanium/Module.hpp"

namespace Titanium
{
	namespace Platform
	{
		enum BatteryState {
			UNKNOWN = 0,
			UNPLUGGED,
			CHARGING,
			FULL
		};
	}

	using namespace HAL;

	/*!
	  @class
	  @discussion This is the Titanium Platform Module.
	  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.Platform
	*/
	class TITANIUMKIT_EXPORT PlatformModule : public Module, public JSExport<PlatformModule>
	{
	public:
		virtual std::string address() const TITANIUM_NOEXCEPT;
		virtual std::string architecture() const TITANIUM_NOEXCEPT;
		virtual std::uint64_t availableMemory() const TITANIUM_NOEXCEPT;
		virtual double batteryLevel() const TITANIUM_NOEXCEPT;
		virtual bool batteryMonitoring() const TITANIUM_NOEXCEPT;
		virtual void set_batteryMonitoring(const bool& batteryMonitoring) TITANIUM_NOEXCEPT;
		virtual Platform::BatteryState batteryState() const TITANIUM_NOEXCEPT;
		virtual std::string id() const TITANIUM_NOEXCEPT;
		virtual std::string locale() const TITANIUM_NOEXCEPT;
		virtual std::string macaddress() const TITANIUM_NOEXCEPT;
		virtual std::string manufacturer() const TITANIUM_NOEXCEPT;
		virtual std::string model() const TITANIUM_NOEXCEPT;
		virtual std::string name() const TITANIUM_NOEXCEPT;
		virtual std::string netmask() const TITANIUM_NOEXCEPT;
		virtual std::string osname() const TITANIUM_NOEXCEPT;
		virtual std::string ostype() const TITANIUM_NOEXCEPT;
		virtual unsigned processorCount() const TITANIUM_NOEXCEPT;
		virtual std::string runtime() const TITANIUM_NOEXCEPT;
		virtual std::string username() const TITANIUM_NOEXCEPT;
		virtual std::string version() const TITANIUM_NOEXCEPT;
		virtual std::string createUUID() TITANIUM_NOEXCEPT;
		virtual bool canOpenURL(const std::string& url) TITANIUM_NOEXCEPT;
		virtual bool openURL(const std::string& url) TITANIUM_NOEXCEPT;
		virtual bool is24HourTimeFormat() TITANIUM_NOEXCEPT;

		PlatformModule(const JSContext&) TITANIUM_NOEXCEPT;

		virtual ~PlatformModule() = default;
		PlatformModule(const PlatformModule&) = default;
		PlatformModule& operator=(const PlatformModule&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
		PlatformModule(PlatformModule&&) = default;
		PlatformModule& operator=(PlatformModule&&) = default;
#endif

		static void JSExportInitialize();
		static JSObject GetStaticObject(const JSContext& js_context) TITANIUM_NOEXCEPT;

		TITANIUM_PROPERTY_READONLY_DEF(address);
		TITANIUM_PROPERTY_READONLY_DEF(architecture);
		TITANIUM_PROPERTY_READONLY_DEF(availableMemory);
		TITANIUM_PROPERTY_READONLY_DEF(batteryLevel);
		TITANIUM_PROPERTY_DEF(batteryMonitoring);
		TITANIUM_PROPERTY_READONLY_DEF(batteryState);
		TITANIUM_PROPERTY_READONLY_DEF(id);
		TITANIUM_PROPERTY_READONLY_DEF(locale);
		TITANIUM_PROPERTY_READONLY_DEF(macaddress);
		TITANIUM_PROPERTY_READONLY_DEF(manufacturer);
		TITANIUM_PROPERTY_READONLY_DEF(model);
		TITANIUM_PROPERTY_READONLY_DEF(name);
		TITANIUM_PROPERTY_READONLY_DEF(netmask);
		TITANIUM_PROPERTY_READONLY_DEF(osname);
		TITANIUM_PROPERTY_READONLY_DEF(ostype);
		TITANIUM_PROPERTY_READONLY_DEF(processorCount);
		TITANIUM_PROPERTY_READONLY_DEF(runtime);
		TITANIUM_PROPERTY_READONLY_DEF(username);
		TITANIUM_PROPERTY_READONLY_DEF(version);
		TITANIUM_PROPERTY_READONLY_DEF(displayCaps);

		TITANIUM_FUNCTION_DEF(getAddress);
		TITANIUM_FUNCTION_DEF(getArchitecture);
		TITANIUM_FUNCTION_DEF(getAvailableMemory);
		TITANIUM_FUNCTION_DEF(getBatteryLevel);
		TITANIUM_FUNCTION_DEF(getBatteryMonitoring);
		TITANIUM_FUNCTION_DEF(setBatteryMonitoring);
		TITANIUM_FUNCTION_DEF(getBatteryState);
		TITANIUM_FUNCTION_DEF(getId);
		TITANIUM_FUNCTION_DEF(getLocale);
		TITANIUM_FUNCTION_DEF(getMacaddress);
		TITANIUM_FUNCTION_DEF(getManufacturer);
		TITANIUM_FUNCTION_DEF(getModel);
		TITANIUM_FUNCTION_DEF(getName);
		TITANIUM_FUNCTION_DEF(getNetmask);
		TITANIUM_FUNCTION_DEF(getOsname);
		TITANIUM_FUNCTION_DEF(getOstype);
		TITANIUM_FUNCTION_DEF(getProcessorCount);
		TITANIUM_FUNCTION_DEF(getRuntime);
		TITANIUM_FUNCTION_DEF(getUsername);
		TITANIUM_FUNCTION_DEF(getVersion);
		TITANIUM_FUNCTION_DEF(getDisplayCaps);

		TITANIUM_FUNCTION_DEF(createUUID);
		TITANIUM_FUNCTION_DEF(canOpenURL);
		TITANIUM_FUNCTION_DEF(openURL);
		TITANIUM_FUNCTION_DEF(is24HourTimeFormat);

		TITANIUM_PROPERTY_READONLY_DEF(BATTERY_STATE_CHARGING);
		TITANIUM_PROPERTY_READONLY_DEF(BATTERY_STATE_FULL);
		TITANIUM_PROPERTY_READONLY_DEF(BATTERY_STATE_UNKNOWN);
		TITANIUM_PROPERTY_READONLY_DEF(BATTERY_STATE_UNPLUGGED);

		virtual void setDisplayCaps(const JSValue&) TITANIUM_NOEXCEPT final;

	private:
		JSValue displayCaps__;
		JSValue BATTERY_STATE_CHARGING__;
		JSValue BATTERY_STATE_FULL__;
		JSValue BATTERY_STATE_UNKNOWN__;
		JSValue BATTERY_STATE_UNPLUGGED__;
	};

}  // namespace Titanium

#endif  // _TITANIUM_PLATFORMMODULE_HPP_
