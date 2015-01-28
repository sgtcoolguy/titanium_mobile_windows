/**
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_NETWORK_HTTPCLIENT_HPP_
#define _TITANIUM_NETWORK_HTTPCLIENT_HPP_

#include "Titanium/Module.hpp"

#define BOOST_BIND_NO_PLACEHOLDERS
#include <boost/signals2/signal.hpp>

namespace Titanium
{
	namespace Network
	{
		using namespace HAL;

		/*!
   @class
   @discussion This is the Titanium.Network.HTTPClient module.
   See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.Network.HTTPClient
   */
		class TITANIUMKIT_EXPORT HTTPClient : public Module, public JSExport<HTTPClient>
		{
		public:
			HTTPClient(const JSContext&, const std::vector<JSValue>& arguments = {}) TITANIUM_NOEXCEPT;

			virtual ~HTTPClient() = default;
			HTTPClient(const HTTPClient&) = default;
			HTTPClient& operator=(const HTTPClient&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			HTTPClient(HTTPClient&&) = default;
			HTTPClient& operator=(HTTPClient&&) = default;
#endif

			static void JSExportInitialize();

			/////// properties
			virtual void setTimeout(const std::double_t timeout) TITANIUM_NOEXCEPT;
			virtual bool js_setTimeout(const JSValue& argument) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getTimeout() const TITANIUM_NOEXCEPT final;
			virtual std::string getResponseText() const TITANIUM_NOEXCEPT;
			virtual JSValue js_getResponseText() const TITANIUM_NOEXCEPT final;
			virtual std::vector<unsigned char> getResponseData() const TITANIUM_NOEXCEPT;
			virtual JSValue js_getResponseData() const TITANIUM_NOEXCEPT final;
			virtual bool js_setOnLoad(const JSValue& argument) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getOnLoad() const TITANIUM_NOEXCEPT final;
			virtual bool js_setOnError(const JSValue& argument) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getOnError() const TITANIUM_NOEXCEPT final;

			/////// methods
			virtual void open(const std::string& method, const std::string& url) TITANIUM_NOEXCEPT;
			virtual JSValue js_open(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;
			virtual void send() TITANIUM_NOEXCEPT;
			virtual void send(const std::map<std::string, std::vector<char>>& postDataPairs, const bool useMultipartForm) TITANIUM_NOEXCEPT;
			virtual JSValue js_send(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;

			/////// slots
			void onload(const std::uint32_t id, const std::string error, const bool success);
			virtual void onerror(const std::uint32_t id, const std::string error, const bool success) TITANIUM_NOEXCEPT final;

			/////// signals
			boost::signals2::signal<void(const std::uint32_t id, const std::string error, const bool success)> loaded;
			boost::signals2::signal<void(const std::uint32_t id, const std::string error, const bool success)> error;

		private:
			JSValue timeout__;

			// Javascript function that will be called when the http request page is loaded.
			JSObject onload_callback__;
			JSObject onerror_callback__;
		};
	}
}  

#endif  // _TITANIUM_NETWORK_HTTPCLIENT_HPP_
