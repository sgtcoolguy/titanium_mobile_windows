/**
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/Network/HTTPClient.hpp"
#include "Titanium/Blob.hpp"

namespace Titanium
{
	namespace Network
	{
		HTTPClient::HTTPClient(const JSContext& js_context) TITANIUM_NOEXCEPT
		    : Module(js_context),
		      onload_callback__(js_context.CreateObject()),
		      onerror_callback__(js_context.CreateObject()),
			  ondatastream_callback__(js_context.CreateObject()),
		      onsendstream_callback__(js_context.CreateObject()),
		      onreadystatechange_callback__(js_context.CreateObject())
		{
			setHTTPStatusPhrase();
		}

		std::chrono::milliseconds HTTPClient::get_timeout() const TITANIUM_NOEXCEPT
		{
			return timeout__;
		}

		void HTTPClient::set_timeout(const std::chrono::milliseconds& timeout) TITANIUM_NOEXCEPT
		{
			timeout__ = timeout;
		}

		std::string HTTPClient::get_responseText() const TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("HTTPClient::get_responseText: Unimplemented");
			return "";
		}

		std::vector<std::uint8_t> HTTPClient::get_responseData() const TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("HTTPClient::get_responseData: Unimplemented");
			return std::vector<std::uint8_t>();  //empty
		}

		std::string HTTPClient::get_allResponseHeaders() const TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("HTTPClient::get_allResponseHeaders: Unimplemented");
			return "";
		}

		std::uint32_t HTTPClient::get_readyState() const TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("HTTPClient::getReadyState: Unimplemented");
			return N_REQUEST_STATE_UNSENT;
		}

		std::uint32_t HTTPClient::get_status() const TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("HTTPClient::getStatus: Unimplemented");
			return 200;
		}

		std::string HTTPClient::get_statusText() const TITANIUM_NOEXCEPT
		{
			auto it = httpStatusPhrase__.find(get_status());
			if (it != httpStatusPhrase__.end()) {
				return it->second;
			}

			return "HTTP Status Phrase Not Found";
		}

		// Methods
		void HTTPClient::abort() TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("HTTPClient::abort: Unimplemented");
		}

		void HTTPClient::clearCookies(const std::string& url) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("HTTPClient::clearCookies: Unimplemented");
		}

		std::string HTTPClient::getResponseHeader(const std::string& name) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("HTTPClient::getResponseHeader: Unimplemented");
			return "";
		}

		void HTTPClient::open(const std::string& method, const std::string& url) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("HTTPClient::open: Unimplemented");
		}

		void HTTPClient::send() TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("HTTPClient::send: Unimplemented");
		}

		void HTTPClient::send(const std::map<std::string, std::vector<std::uint8_t>>& postDataPairs, const bool& useMultipartForm) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("HTTPClient::send<data>: Unimplemented");
		}

		void HTTPClient::send(const std::string& postDataStr) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("HTTPClient::send<data string>: Unimplemented");
		}
		
		void HTTPClient::setRequestHeader(const std::string& name, const std::string& value) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("HTTPClient::setRequestHeader: Unimplemented");
		}

		void HTTPClient::JSExportInitialize()
		{
			JSExport<HTTPClient>::SetClassVersion(1);
			JSExport<HTTPClient>::SetParent(JSExport<Module>::Class());
			// constants
			JSExport<HTTPClient>::AddValueProperty("LOADING", std::mem_fn(&HTTPClient::js_getLOADING));
			JSExport<HTTPClient>::AddValueProperty("OPENED", std::mem_fn(&HTTPClient::js_getOPENED));
			JSExport<HTTPClient>::AddValueProperty("DONE", std::mem_fn(&HTTPClient::js_getDONE));
			JSExport<HTTPClient>::AddValueProperty("UNSENT", std::mem_fn(&HTTPClient::js_getUNSENT));
			JSExport<HTTPClient>::AddValueProperty("HEADERS_RECEIVED", std::mem_fn(&HTTPClient::js_getHEADERS_RECEIVED));
			// properties
			JSExport<HTTPClient>::AddValueProperty("allResponseHeaders", std::mem_fn(&HTTPClient::js_get_allResponseHeaders));
			JSExport<HTTPClient>::AddValueProperty("ondatastream", std::mem_fn(&HTTPClient::js_get_ondatastream), std::mem_fn(&HTTPClient::js_set_ondatastream));
			JSExport<HTTPClient>::AddValueProperty("onerror", std::mem_fn(&HTTPClient::js_get_onerror), std::mem_fn(&HTTPClient::js_set_onerror));
			JSExport<HTTPClient>::AddValueProperty("onload", std::mem_fn(&HTTPClient::js_get_onload), std::mem_fn(&HTTPClient::js_set_onload));
			JSExport<HTTPClient>::AddValueProperty("onreadystatechange", std::mem_fn(&HTTPClient::js_get_onreadystatechange), std::mem_fn(&HTTPClient::js_set_onreadystatechange));
			JSExport<HTTPClient>::AddValueProperty("onsendstream", std::mem_fn(&HTTPClient::js_get_onsendstream), std::mem_fn(&HTTPClient::js_set_onsendstream));
			JSExport<HTTPClient>::AddValueProperty("readyState", std::mem_fn(&HTTPClient::js_get_readyState));
			JSExport<HTTPClient>::AddValueProperty("responseData", std::mem_fn(&HTTPClient::js_get_responseData));
			JSExport<HTTPClient>::AddValueProperty("responseText", std::mem_fn(&HTTPClient::js_get_responseText));
			JSExport<HTTPClient>::AddValueProperty("status", std::mem_fn(&HTTPClient::js_get_status));
			JSExport<HTTPClient>::AddValueProperty("statusText", std::mem_fn(&HTTPClient::js_get_statusText));
			JSExport<HTTPClient>::AddValueProperty("timeout", std::mem_fn(&HTTPClient::js_get_timeout), std::mem_fn(&HTTPClient::js_set_timeout));
			// methods
			JSExport<HTTPClient>::AddFunctionProperty("open", std::mem_fn(&HTTPClient::js_open));
			JSExport<HTTPClient>::AddFunctionProperty("send", std::mem_fn(&HTTPClient::js_send));
			JSExport<HTTPClient>::AddFunctionProperty("abort", std::mem_fn(&HTTPClient::js_abort));
			JSExport<HTTPClient>::AddFunctionProperty("setRequestHeader", std::mem_fn(&HTTPClient::js_setRequestHeader));
			JSExport<HTTPClient>::AddFunctionProperty("getResponseHeader", std::mem_fn(&HTTPClient::js_getResponseHeader));
			JSExport<HTTPClient>::AddFunctionProperty("clearCookies", std::mem_fn(&HTTPClient::js_clearCookies));

			// accessors
			JSExport<HTTPClient>::AddFunctionProperty("getAllResponseHeaders", std::mem_fn(&HTTPClient::js_getAllResponseHeaders));
			JSExport<HTTPClient>::AddFunctionProperty("getOndatastream", std::mem_fn(&HTTPClient::js_getOndatastream));
			JSExport<HTTPClient>::AddFunctionProperty("setOndatastream", std::mem_fn(&HTTPClient::js_setOndatastream));
			JSExport<HTTPClient>::AddFunctionProperty("getOnerror", std::mem_fn(&HTTPClient::js_getOnerror));
			JSExport<HTTPClient>::AddFunctionProperty("setOnerror", std::mem_fn(&HTTPClient::js_setOnerror));
			JSExport<HTTPClient>::AddFunctionProperty("getOnload", std::mem_fn(&HTTPClient::js_getOnload));
			JSExport<HTTPClient>::AddFunctionProperty("setOnload", std::mem_fn(&HTTPClient::js_setOnload));
			JSExport<HTTPClient>::AddFunctionProperty("getOnreadystatechange", std::mem_fn(&HTTPClient::js_getOnreadystatechange));
			JSExport<HTTPClient>::AddFunctionProperty("setOnreadystatechange", std::mem_fn(&HTTPClient::js_setOnreadystatechange));
			JSExport<HTTPClient>::AddFunctionProperty("getOnsendstream", std::mem_fn(&HTTPClient::js_getOnsendstream));
			JSExport<HTTPClient>::AddFunctionProperty("setOnsendstream", std::mem_fn(&HTTPClient::js_setOnsendstream));
			JSExport<HTTPClient>::AddFunctionProperty("getReadyState", std::mem_fn(&HTTPClient::js_getReadyState));
			JSExport<HTTPClient>::AddFunctionProperty("getResponseData", std::mem_fn(&HTTPClient::js_getResponseData));
			JSExport<HTTPClient>::AddFunctionProperty("getResponseText", std::mem_fn(&HTTPClient::js_getResponseText));
			JSExport<HTTPClient>::AddFunctionProperty("getStatus", std::mem_fn(&HTTPClient::js_getStatus));
			JSExport<HTTPClient>::AddFunctionProperty("getStatusText", std::mem_fn(&HTTPClient::js_getStatusText));
			JSExport<HTTPClient>::AddFunctionProperty("getTimeout", std::mem_fn(&HTTPClient::js_getTimeout));
			JSExport<HTTPClient>::AddFunctionProperty("setTimeout", std::mem_fn(&HTTPClient::js_setTimeout));
		}

		JSValue HTTPClient::js_getLOADING() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(N_REQUEST_STATE_LOADING);
		}

		JSValue HTTPClient::js_getOPENED() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(N_REQUEST_STATE_OPENED);
		}

		JSValue HTTPClient::js_getDONE() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(N_REQUEST_STATE_DONE);
		}

		JSValue HTTPClient::js_getUNSENT() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(N_REQUEST_STATE_UNSENT);
		}

		JSValue HTTPClient::js_getHEADERS_RECEIVED() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(N_REQUEST_STATE_HEADERS_RECEIVED);
		}

		// Methods
		JSValue HTTPClient::js_abort(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			abort();
			return get_context().CreateUndefined();
		}

		JSValue HTTPClient::js_clearCookies(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			const auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsString());
			const auto url = static_cast<std::string>(_0);
			clearCookies(url);
			return get_context().CreateUndefined();
		}

		JSValue HTTPClient::js_getResponseHeader(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			const auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsString());
			const auto name = static_cast<std::string>(_0);
			return get_context().CreateString(getResponseHeader(name));
		}

		JSValue HTTPClient::js_open(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			const auto _0 = arguments.at(0);
			const auto _1 = arguments.at(1);
			TITANIUM_ASSERT(_0.IsString() && _1.IsString());
			const auto method = static_cast<std::string>(_0);
			const auto url = static_cast<std::string>(_1);
			open(method, url);
			return get_context().CreateUndefined();
		}

		JSValue HTTPClient::js_send(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (!arguments.empty()) {
				TITANIUM_ASSERT(arguments.at(0).IsObject() || arguments.at(0).IsString());

				if (arguments.at(0).IsString()) {
					std::string postDataString = static_cast<std::string>(arguments.at(0));
					send(postDataString);
				} else {
					bool useMultipartForm = false;
					std::map<std::string, std::vector<std::uint8_t>> map;
					JSObject sendArgs = static_cast<JSObject>(arguments.at(0));
					for (const auto& property_name : static_cast<std::vector<JSString>>(sendArgs.GetPropertyNames())) {
						TITANIUM_ASSERT(sendArgs.GetProperty(property_name).IsObject() || sendArgs.GetProperty(property_name).IsString());
						JSValue prop = sendArgs.GetProperty(property_name);
						if (prop.IsString()) {
							std::string str = static_cast<std::string>(prop);
							std::vector<std::uint8_t> data(str.begin(), str.end());
							map.insert(std::make_pair(property_name, data));
						} else {
							useMultipartForm = true;
							auto blob_ptr = static_cast<JSObject>(prop).GetPrivate<Titanium::Blob>();
							map.insert(std::make_pair(property_name, blob_ptr->getData()));
						}
					}
					send(map, useMultipartForm);
				}
			} else {
				send();
			}

			return get_context().CreateUndefined();
		}

		JSValue HTTPClient::js_setRequestHeader(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			const auto _0 = arguments.at(0);
			const auto _1 = arguments.at(1);
			TITANIUM_ASSERT(_0.IsString() && _1.IsString());
			const auto name = static_cast<std::string>(_0);
			const auto value = static_cast<std::string>(_1);
			setRequestHeader(name, value);
			return get_context().CreateUndefined();
		}

		// properties
		JSValue HTTPClient::js_get_allResponseHeaders() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(get_allResponseHeaders());
		}

		JSValue HTTPClient::js_getAllResponseHeaders(const std::vector<JSValue>& arguments, JSObject& this_object) const TITANIUM_NOEXCEPT
		{
			return js_get_allResponseHeaders();
		}

		JSValue HTTPClient::js_get_readyState() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(get_readyState());
		}

		JSValue HTTPClient::js_getReadyState(const std::vector<JSValue>& arguments, JSObject& this_object) const TITANIUM_NOEXCEPT
		{
			return js_get_readyState();
		}

		JSValue HTTPClient::js_get_responseData() const TITANIUM_NOEXCEPT
		{
			auto Blob = get_context().CreateObject(JSExport<Titanium::Blob>::Class());
			auto blob = Blob.CallAsConstructor();
			auto blob_ptr = blob.GetPrivate<Titanium::Blob>();

			blob_ptr->construct(get_responseData());

			return blob;
		}

		JSValue HTTPClient::js_getResponseData(const std::vector<JSValue>& arguments, JSObject& this_object) const TITANIUM_NOEXCEPT
		{
			return js_get_responseData();
		}

		JSValue HTTPClient::js_get_responseText() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(get_responseText());
		}

		JSValue HTTPClient::js_getResponseText(const std::vector<JSValue>& arguments, JSObject& this_object) const TITANIUM_NOEXCEPT
		{
			return js_get_responseText();
		}

		JSValue HTTPClient::js_get_status() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(get_status());
		}
			
		JSValue HTTPClient::js_getStatus(const std::vector<JSValue>& arguments, JSObject& this_object) const TITANIUM_NOEXCEPT
		{
			return js_get_status();
		}

		JSValue HTTPClient::js_get_statusText() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(get_statusText());
		}

		JSValue HTTPClient::js_getStatusText(const std::vector<JSValue>& arguments, JSObject& this_object) const TITANIUM_NOEXCEPT
		{
			return js_get_statusText();
		}

		bool HTTPClient::js_set_ondatastream(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			using namespace std::placeholders;
			TITANIUM_ASSERT(static_cast<JSObject>(argument).IsFunction());

			// connect the slot
			datastream.connect(std::bind(&HTTPClient::ondatastream, this, _1));

			ondatastream_callback__ = static_cast<JSObject>(argument);
			return true;
		}

		JSValue HTTPClient::js_get_ondatastream() const TITANIUM_NOEXCEPT
		{
			return ondatastream_callback__;
		}

		JSValue HTTPClient::js_getOndatastream(const std::vector<JSValue>& arguments, JSObject& this_object) const TITANIUM_NOEXCEPT
		{
			return js_get_ondatastream();
		}

		JSValue HTTPClient::js_setOndatastream(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_ondatastream(arguments.at(0));
			}
			return this_object.get_context().CreateUndefined();
		}

		bool HTTPClient::js_set_onerror(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			using namespace std::placeholders;
			TITANIUM_ASSERT(static_cast<JSObject>(argument).IsFunction());

			// connect the slot
			error.connect(std::bind(&HTTPClient::onerror, this, _1, _2, _3));

			onerror_callback__ = static_cast<JSObject>(argument);
			return true;
		}

		JSValue HTTPClient::js_get_onerror() const TITANIUM_NOEXCEPT
		{
			return onerror_callback__;
		}

		JSValue HTTPClient::js_getOnerror(const std::vector<JSValue>& arguments, JSObject& this_object) const TITANIUM_NOEXCEPT
		{
			return js_get_onerror();
		}

		JSValue HTTPClient::js_setOnerror(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_onerror(arguments.at(0));
			}
			return this_object.get_context().CreateUndefined();
		}

		bool HTTPClient::js_set_onload(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			using namespace std::placeholders;
			TITANIUM_ASSERT(static_cast<JSObject>(argument).IsFunction());

			// connect the slot
			loaded.connect(std::bind(&HTTPClient::onload, this, _1, _2, _3));

			onload_callback__ = static_cast<JSObject>(argument);
			return true;
		}

		JSValue HTTPClient::js_get_onload() const TITANIUM_NOEXCEPT
		{
			return onload_callback__;
		}

		JSValue HTTPClient::js_getOnload(const std::vector<JSValue>& arguments, JSObject& this_object) const TITANIUM_NOEXCEPT
		{
			return js_get_onload();
		}

		JSValue HTTPClient::js_setOnload(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_onload(arguments.at(0));
			}
			return this_object.get_context().CreateUndefined();
		}

		bool HTTPClient::js_set_onreadystatechange(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			using namespace std::placeholders;
			TITANIUM_ASSERT(static_cast<JSObject>(argument).IsFunction());

			// connect the slot
			readystatechange.connect(std::bind(&HTTPClient::onreadystatechange, this, _1));

			onreadystatechange_callback__ = static_cast<JSObject>(argument);
			return true;
		}

		JSValue HTTPClient::js_get_onreadystatechange() const TITANIUM_NOEXCEPT
		{
			return onreadystatechange_callback__;
		}

		JSValue HTTPClient::js_getOnreadystatechange(const std::vector<JSValue>& arguments, JSObject& this_object) const TITANIUM_NOEXCEPT
		{
			return js_get_onreadystatechange();
		}

		JSValue HTTPClient::js_setOnreadystatechange(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_onreadystatechange(arguments.at(0));
			}
			return this_object.get_context().CreateUndefined();
		}

		bool HTTPClient::js_set_onsendstream(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			using namespace std::placeholders;
			TITANIUM_ASSERT(static_cast<JSObject>(argument).IsFunction());

			// connect the slot
			sendstream.connect(std::bind(&HTTPClient::onsendstream, this, _1));

			onsendstream_callback__ = static_cast<JSObject>(argument);
			return true;
		}

		JSValue HTTPClient::js_get_onsendstream() const TITANIUM_NOEXCEPT
		{
			return onsendstream_callback__;
		}

		JSValue HTTPClient::js_getOnsendstream(const std::vector<JSValue>& arguments, JSObject& this_object) const TITANIUM_NOEXCEPT
		{
			return js_get_onsendstream();
		}

		JSValue HTTPClient::js_setOnsendstream(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_onsendstream(arguments.at(0));
			}
			return this_object.get_context().CreateUndefined();
		}
			
		JSValue HTTPClient::js_get_timeout() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(static_cast<double>(get_timeout().count()));
		}

		bool HTTPClient::js_set_timeout(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsNumber());
			double d = static_cast<double>(argument);
			std::chrono::milliseconds timeout((long long)d);
			set_timeout(timeout);
			return true;
		}

		JSValue HTTPClient::js_getTimeout(const std::vector<JSValue>& arguments, JSObject& this_object) const TITANIUM_NOEXCEPT
		{
			return js_get_timeout();
		}

		JSValue HTTPClient::js_setTimeout(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_timeout(arguments.at(0));
			}
			return this_object.get_context().CreateUndefined();
		}

		////// slots
		void HTTPClient::onload(const std::uint32_t code, const std::string error, const bool success) TITANIUM_NOEXCEPT
		{
			if (onload_callback__.IsFunction()) {
				const JSContext ctx = get_context();

				JSObject this_object = get_object();

				JSObject eventArgs = ctx.CreateObject();
				eventArgs.SetProperty("code", ctx.CreateNumber(code));
				eventArgs.SetProperty("error", ctx.CreateString(error));
				eventArgs.SetProperty("success", ctx.CreateBoolean(success));

				std::vector<JSValue> arguments;
				arguments.push_back(eventArgs);

				onload_callback__(arguments, this_object);
			}
		}

		void HTTPClient::onerror(const std::uint32_t code, const std::string error, const bool success) TITANIUM_NOEXCEPT
		{
			if (onerror_callback__.IsFunction()) {
				const JSContext ctx = get_context();

				JSObject this_object = get_object();

				JSObject eventArgs = ctx.CreateObject();
				eventArgs.SetProperty("code", ctx.CreateNumber(code));
				eventArgs.SetProperty("error", ctx.CreateString(error));
				eventArgs.SetProperty("success", ctx.CreateBoolean(success));

				std::vector<JSValue> arguments;
				arguments.push_back(eventArgs);

				onerror_callback__(arguments, this_object);
			}
		}

		void HTTPClient::ondatastream(const double progress) TITANIUM_NOEXCEPT
		{
			if (ondatastream_callback__.IsFunction()) {
				const JSContext ctx = get_context();

				JSObject this_object = get_object();

				JSObject eventArgs = ctx.CreateObject();
				eventArgs.SetProperty("progress", ctx.CreateNumber(progress));

				std::vector<JSValue> arguments;
				arguments.push_back(eventArgs);

				ondatastream_callback__(arguments, this_object);
			}
		}

		void HTTPClient::onsendstream(const double progress) TITANIUM_NOEXCEPT
		{
			if (onsendstream_callback__.IsFunction()) {
				const JSContext ctx = get_context();

				JSObject this_object = get_object();

				JSObject eventArgs = ctx.CreateObject();
				eventArgs.SetProperty("progress", ctx.CreateNumber(progress));

				std::vector<JSValue> arguments;
				arguments.push_back(eventArgs);

				onsendstream_callback__(arguments, this_object);
			}
		}

		void HTTPClient::onreadystatechange(const std::uint32_t state) TITANIUM_NOEXCEPT
		{
			if (onreadystatechange_callback__.IsFunction()) {
				const JSContext ctx = get_context();

				JSObject this_object = get_object();

				JSObject eventArgs = ctx.CreateObject();
				eventArgs.SetProperty("readyState", ctx.CreateNumber(state));

				std::vector<JSValue> arguments;
				arguments.push_back(eventArgs);

				onreadystatechange_callback__(arguments, this_object);
			}
		}

		void HTTPClient::setHTTPStatusPhrase()
		{
			httpStatusPhrase__[100] = "Continue";
			httpStatusPhrase__[101] = "Processing";
			httpStatusPhrase__[102] = "Processing";
			httpStatusPhrase__[200] = "OK";
			httpStatusPhrase__[201] = "Created";
			httpStatusPhrase__[202] = "Accepted";
			httpStatusPhrase__[203] = "Non-Authoritative Information";
			httpStatusPhrase__[204] = "No Content";
			httpStatusPhrase__[205] = "Reset Content";
			httpStatusPhrase__[206] = "Partial Content";
			httpStatusPhrase__[207] = "Multi-Status";
			httpStatusPhrase__[300] = "Multiple Choices";
			httpStatusPhrase__[301] = "Moved Permanently";
			httpStatusPhrase__[302] = "Moved Temporarily";
			httpStatusPhrase__[303] = "See Other";
			httpStatusPhrase__[304] = "Not Modified";
			httpStatusPhrase__[305] = "Use Proxy";
			httpStatusPhrase__[307] = "Temporary Redirect";
			httpStatusPhrase__[400] = "Bad Request";
			httpStatusPhrase__[401] = "Unauthorized";
			httpStatusPhrase__[402] = "Payment Required";
			httpStatusPhrase__[403] = "Forbidden";
			httpStatusPhrase__[404] = "Not Found";
			httpStatusPhrase__[405] = "Method Not Allowed";
			httpStatusPhrase__[406] = "Not Acceptable";
			httpStatusPhrase__[407] = "Proxy Authentication Required";
			httpStatusPhrase__[408] = "Request Time-out";
			httpStatusPhrase__[409] = "Conflict";
			httpStatusPhrase__[410] = "Gone";
			httpStatusPhrase__[411] = "Length Required";
			httpStatusPhrase__[412] = "Precondition Failed";
			httpStatusPhrase__[413] = "Request Entity Too Large";
			httpStatusPhrase__[414] = "Request-URI Too Large";
			httpStatusPhrase__[415] = "Unsupported Media Type";
			httpStatusPhrase__[416] = "Requested Range Not Satisfiable";
			httpStatusPhrase__[417] = "Expectation Failed";
			httpStatusPhrase__[418] = "I'm a teapot";
			httpStatusPhrase__[422] = "Unprocessable Entity";
			httpStatusPhrase__[423] = "Locked";
			httpStatusPhrase__[424] = "Failed Dependency";
			httpStatusPhrase__[425] = "Unordered Collection";
			httpStatusPhrase__[426] = "Upgrade Required";
			httpStatusPhrase__[428] = "Precondition Required";
			httpStatusPhrase__[429] = "Too Many Requests";
			httpStatusPhrase__[431] = "Request Header Fields Too Large";
			httpStatusPhrase__[500] = "Internal Server Error";
			httpStatusPhrase__[501] = "Not Implemented";
			httpStatusPhrase__[502] = "Bad Gateway";
			httpStatusPhrase__[503] = "Service Unavailable";
			httpStatusPhrase__[504] = "Gateway Time-out";
			httpStatusPhrase__[505] = "HTTP Version Not Supported";
			httpStatusPhrase__[506] = "Variant Also Negotiates";
			httpStatusPhrase__[507] = "Insufficient Storage";
			httpStatusPhrase__[509] = "Bandwidth Limit Exceeded";
			httpStatusPhrase__[510] = "Not Extended";
			httpStatusPhrase__[511] = "Network Authentication Required";
		}
	}
}
