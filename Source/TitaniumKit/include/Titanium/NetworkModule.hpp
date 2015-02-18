/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_NETWORK_HPP_
#define _TITANIUM_NETWORK_HPP_

#include "Titanium/Module.hpp"
#include "Titanium/Network/Constants.hpp"
#include "Titanium/Network/HTTPClient.hpp"

namespace Titanium
{
	using namespace HAL;

	/*!
      @class
      @discussion This is the Ti.Network Module.
      See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.Network
    */
	class TITANIUMKIT_EXPORT NetworkModule : public Module, public JSExport<NetworkModule>
	{
	public:
		/*!
		  @method
		  @abstract createHTTPClient 
		  @discussion Returns a HTTP object allowing users to make http request and query the HTTP object.
		*/
		virtual JSObject createHTTPClient(const JSObject& parameters, JSObject& this_object) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract networkType : Number
		  @discussion Network type value as a constant.

		  One of the NETWORK constants defined in Titanium.Network.
		*/
		virtual Titanium::Network::TYPE get_networkType() const TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract networkTypeName : String
		  @discussion Network type as a String. Returns one of NONE, WIFI, LAN, MOBILE, or UNKNOWN.
		*/
		virtual std::string get_networkTypeName() const TITANIUM_NOEXCEPT final;

		/*!
		  @method
		  @abstract online : Boolean
		  @discussion Boolean value indicating if the device can reach the Internet.
		*/
		virtual bool get_online() const TITANIUM_NOEXCEPT;

		virtual JSValue NETWORK_LAN() const TITANIUM_NOEXCEPT final;
		virtual JSValue NETWORK_MOBILE() const TITANIUM_NOEXCEPT final;
		virtual JSValue NETWORK_NONE() const TITANIUM_NOEXCEPT final;
		virtual JSValue NETWORK_UNKNOWN() const TITANIUM_NOEXCEPT final;
		virtual JSValue NETWORK_WIFI() const TITANIUM_NOEXCEPT final;
		virtual JSValue NOTIFICATION_TYPE_ALERT() const TITANIUM_NOEXCEPT final;
		virtual JSValue NOTIFICATION_TYPE_BADGE() const TITANIUM_NOEXCEPT final;
		virtual JSValue NOTIFICATION_TYPE_NEWSSTAND() const TITANIUM_NOEXCEPT final;
		virtual JSValue NOTIFICATION_TYPE_SOUND() const TITANIUM_NOEXCEPT final;
		virtual JSValue PROGRESS_UNKNOWN() const TITANIUM_NOEXCEPT final;
		virtual JSValue TLS_VERSION_1_0() const TITANIUM_NOEXCEPT final;
		virtual JSValue TLS_VERSION_1_1() const TITANIUM_NOEXCEPT final;
		virtual JSValue TLS_VERSION_1_2() const TITANIUM_NOEXCEPT final;

		NetworkModule(const JSContext&, const std::vector<JSValue>& arguments = {}) TITANIUM_NOEXCEPT;

		virtual ~NetworkModule() = default;
		NetworkModule(const NetworkModule&) = default;
		NetworkModule& operator=(const NetworkModule&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
		NetworkModule(NetworkModule&&) = default;
		NetworkModule& operator=(NetworkModule&&) = default;
#endif

		static void JSExportInitialize();

		JSObject js_createHTTPClient(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT;
		virtual JSValue js_get_networkType() const TITANIUM_NOEXCEPT final;
		virtual JSValue js_get_networkTypeName() const TITANIUM_NOEXCEPT final;
		virtual JSValue js_get_online() const TITANIUM_NOEXCEPT final;

	private:
		JSValue network_lan__;
		JSValue network_mobile__;
		JSValue network_none__;
		JSValue network_unknown__;
		JSValue network_wifi__;
		JSValue notification_type_alert__;
		JSValue notification_type_badge__;
		JSValue notification_type_newsstand__;
		JSValue notification_type_sound__;
		JSValue progress_unknown__;
		JSValue tls_version_1_0__;
		JSValue tls_version_1_1__;
		JSValue tls_version_1_2__;
	};
} // namespace Titanium

#endif  // _TITANIUM_NETWORK_HPP_
