/**
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_PLATFORM_HPP_
#define _TITANIUMWINDOWS_PLATFORM_HPP_

#include "Titanium/PlatformModule.hpp"
#include "TitaniumWindows_Ti_EXPORT.h"

namespace TitaniumWindows
{
	using namespace HAL;

	/*!
	  @class

	  @discussion This is the Titanium.Platform implementation for Windows.
	*/
	class TITANIUMWINDOWS_TI_EXPORT Platform final : public Titanium::PlatformModule, public JSExport<Platform>
	{
	public:
		Platform(const JSContext&) TITANIUM_NOEXCEPT;

		virtual ~Platform() = default;
		Platform(const Platform&) = default;
		Platform& operator=(const Platform&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
		Platform(Platform&&) = default;
		Platform& operator=(Platform&&) = default;
#endif

		static void JSExportInitialize();

		virtual std::string address() const TITANIUM_NOEXCEPT;
		virtual std::string architecture() const TITANIUM_NOEXCEPT;
		virtual std::uint64_t availableMemory() const TITANIUM_NOEXCEPT;
		virtual double batteryLevel() const TITANIUM_NOEXCEPT;
		virtual bool batteryMonitoring() const TITANIUM_NOEXCEPT;
		virtual Titanium::Platform::BatteryState batteryState() const TITANIUM_NOEXCEPT;
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

	private:
#pragma warning(push)
#pragma warning(disable : 4251)
		std::string osname__;
#pragma warning(pop)
	};

}  // namespace TitaniumWindows

#endif  // _TITANIUMWINDOWS_PLATFORM_HPP_
