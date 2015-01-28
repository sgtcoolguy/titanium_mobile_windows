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
		HTTPClient::HTTPClient(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
		    : Module(js_context),
		      timeout__(js_context.CreateString()),
		      onload_callback__(js_context.CreateObject()),
		      onerror_callback__(js_context.CreateObject())
		{
		}

		void HTTPClient::JSExportInitialize()
		{
			JSExport<HTTPClient>::SetClassVersion(1);
			JSExport<HTTPClient>::SetParent(JSExport<Module>::Class());

			JSExport<HTTPClient>::AddValueProperty("timeout", std::mem_fn(&HTTPClient::js_getTimeout), std::mem_fn(&HTTPClient::js_setTimeout));
			JSExport<HTTPClient>::AddValueProperty("responseText", std::mem_fn(&HTTPClient::js_getResponseText), nullptr);
			JSExport<HTTPClient>::AddValueProperty("responseData", std::mem_fn(&HTTPClient::js_getResponseData), nullptr);
			JSExport<HTTPClient>::AddValueProperty("onload", std::mem_fn(&HTTPClient::js_getOnLoad), std::mem_fn(&HTTPClient::js_setOnLoad));
			JSExport<HTTPClient>::AddValueProperty("onerror", std::mem_fn(&HTTPClient::js_getOnError), std::mem_fn(&HTTPClient::js_setOnError));

			JSExport<HTTPClient>::AddFunctionProperty("open", std::mem_fn(&HTTPClient::js_open));
			JSExport<HTTPClient>::AddFunctionProperty("send", std::mem_fn(&HTTPClient::js_send));
		}

		void HTTPClient::setTimeout(const double timeout) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("HTTPClient::setTimeout: Unimplemented");
		}

		bool HTTPClient::js_setTimeout(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsNumber());
			setTimeout(static_cast<double>(argument));
			timeout__ = argument;
			return true;
		}

		JSValue HTTPClient::js_getTimeout() const TITANIUM_NOEXCEPT
		{
			return timeout__;
		}

		std::string HTTPClient::getResponseText() const TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("HTTPClient::getResponseText: Unimplemented");
			return std::string();  // empty
		}

		JSValue HTTPClient::js_getResponseText() const TITANIUM_NOEXCEPT
		{
			const JSContext ctx = get_context();
			return ctx.CreateString(getResponseText());
		}

		std::vector<unsigned char> HTTPClient::getResponseData() const TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("HTTPClient::getResponseData: Unimplemented");
			return std::vector<unsigned char>();  //empty
		}

		JSValue HTTPClient::js_getResponseData() const TITANIUM_NOEXCEPT
		{
			auto Blob = get_context().CreateObject(JSExport<Titanium::Blob>::Class());
			auto blob = Blob.CallAsConstructor();
			auto blob_ptr = blob.GetPrivate<Titanium::Blob>();

			// ToDo hookup to blob object
			//blob_ptr->construct(getResponseData());

			return blob;
		}

		bool HTTPClient::js_setOnLoad(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			using namespace std::placeholders;
			TITANIUM_ASSERT(static_cast<JSObject>(argument).IsFunction());

			// connect the slot
			loaded.connect(std::bind(&HTTPClient::onload, this, _1, _2, _3));

			onload_callback__ = static_cast<JSObject>(argument);
			return true;
		}

		JSValue HTTPClient::js_getOnLoad() const TITANIUM_NOEXCEPT
		{
			return onload_callback__;
		}

		bool HTTPClient::js_setOnError(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			using namespace std::placeholders;
			TITANIUM_ASSERT(static_cast<JSObject>(argument).IsFunction());

			// connect the slot
			error.connect(std::bind(&HTTPClient::onerror, this, _1, _2, _3));

			onerror_callback__ = static_cast<JSObject>(argument);
			return true;
		}

		JSValue HTTPClient::js_getOnError() const TITANIUM_NOEXCEPT
		{
			return onerror_callback__;
		}

		void HTTPClient::open(const std::string& method, const std::string& url) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("HTTPClient::open: Unimplemented");
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

		void HTTPClient::send() TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("HTTPClient::send: Unimplemented");
		}

		void HTTPClient::send(const std::map<std::string, std::vector<char>>& postDataPairs, const bool useMultipartForm) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("HTTPClient::send<data>: Unimplemented");
		}

		JSValue HTTPClient::js_send(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (!arguments.empty()) {
				TITANIUM_ASSERT(arguments.at(0).IsObject());
				bool useMultipartForm = false;
				std::map<std::string, std::vector<char>> map;
				JSObject sendArgs = static_cast<JSObject>(arguments.at(0));
				for (const auto& property_name : static_cast<std::vector<JSString>>(sendArgs.GetPropertyNames())) {
					TITANIUM_ASSERT(sendArgs.GetProperty(property_name).IsObject() || sendArgs.GetProperty(property_name).IsString());
					JSValue prop = sendArgs.GetProperty(property_name);
					if (prop.IsString()) {
						std::string str = static_cast<std::string>(prop);
						std::vector<char> data(str.begin(), str.end());
						map.insert(std::make_pair(property_name, data));
					} else {
						useMultipartForm = true;
						auto blob_ptr = static_cast<JSObject>(prop).GetPrivate<Titanium::Blob>();

						// ToDo hook up to Blob object
						//map.insert(std::make_pair(property_name, blob_ptr->getData()));
					}
				}
				send(map, useMultipartForm);
			} else {
				send();
			}

			return get_context().CreateUndefined();
		}

		////// slots
		void HTTPClient::onload(const std::uint32_t id, const std::string error, const bool success)
		{
			const JSContext ctx = get_context();

			JSObject eventArgs = ctx.CreateObject();
			eventArgs.SetProperty("id", ctx.CreateNumber(id));
			eventArgs.SetProperty("error", ctx.CreateString(error));
			eventArgs.SetProperty("success", ctx.CreateBoolean(success));

			std::vector<JSValue> arguments;
			arguments.push_back(eventArgs);

			//onload_callback__.CallAsFunction(arguments, this);
		}

		void HTTPClient::onerror(const std::uint32_t id, const std::string error, const bool success)
		{
			const JSContext ctx = get_context();

			JSObject eventArgs = ctx.CreateObject();
			eventArgs.SetProperty("id", ctx.CreateNumber(id));
			eventArgs.SetProperty("error", ctx.CreateString(error));
			eventArgs.SetProperty("success", ctx.CreateBoolean(success));

			std::vector<JSValue> arguments;
			arguments.push_back(eventArgs);

			//onerror_callback__.CallAsFunction(arguments, this);
		}
	}
}  
