/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_NETWORKMODULE_HPP_
#define _TITANIUMWINDOWS_NETWORKMODULE_HPP_

#include "TitaniumWindows/detail/NetworkBase.hpp"
#include "TitaniumWindows/Network/HTTPClient.hpp"

namespace TitaniumWindows
{
	using namespace HAL;

	/*!
      @class

      @discussion This is the Titanium.Network implementation for Windows.
    */
	class TITANIUMWINDOWS_NETWORK_EXPORT NetworkModule final : public Titanium::NetworkModule, public JSExport<NetworkModule>
	{
	public:
		NetworkModule(const JSContext&) TITANIUM_NOEXCEPT;

		virtual ~NetworkModule();
		NetworkModule(const NetworkModule&) = default;
		NetworkModule& operator=(const NetworkModule&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
		NetworkModule(NetworkModule&&) = default;
		NetworkModule& operator=(NetworkModule&&) = default;
#endif

		static void JSExportInitialize();

		virtual Titanium::Network::TYPE get_networkType() const TITANIUM_NOEXCEPT override final;
		virtual bool get_online() const TITANIUM_NOEXCEPT override final;

		virtual void enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT override final;
		virtual void disableEvent(const std::string& event_name) TITANIUM_NOEXCEPT override final;

	protected:
		Windows::Foundation::EventRegistrationToken change_event__;
	};

}  

#endif  // _TITANIUMWINDOWS_NETWORKMODULE_HPP_
