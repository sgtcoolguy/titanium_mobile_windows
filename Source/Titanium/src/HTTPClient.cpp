/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "HTTPClient.hpp"
#include "Titanium/detail/TiBase.hpp"
#include "TitaniumWindows/Utility.hpp"

#include <collection.h>
#include <algorithm>

using namespace concurrency;

namespace TitaniumWindows
{
	namespace Network
	{
		HTTPClient::HTTPClient(const JSContext& js_context) TITANIUM_NOEXCEPT
		    : Titanium::Network::HTTPClient(js_context)
		{
			TITANIUM_LOG_DEBUG("TitaniumWindows::Network::HTTPClient::ctor Initialize");

			responseData__ = std::vector<std::uint8_t>();
			responseDataLen__ = 0;
			readyState__ = Titanium::Network::N_REQUEST_STATE_UNSENT;
		}

		HTTPClient::~HTTPClient()
		{
			TITANIUM_LOG_DEBUG("TitaniumWindows::Network::HTTPClient::dtor");
			abort();

			filter__ = nullptr;
			httpClient__ = nullptr;
			dispatcherTimer__ = nullptr;
		}

		void HTTPClient::JSExportInitialize()
		{
			JSExport<HTTPClient>::SetClassVersion(1);
			JSExport<HTTPClient>::SetParent(JSExport<Titanium::Network::HTTPClient>::Class());
		}

		void HTTPClient::abort() TITANIUM_NOEXCEPT
		{
			cancellationTokenSource__.cancel();

			if (dispatcherTimer__ != nullptr && dispatcherTimer__->IsEnabled) {
				dispatcherTimer__->Stop();
			}
		}

		void HTTPClient::clearCookies(const std::string& url) TITANIUM_NOEXCEPT
		{
			auto filter = ref new Windows::Web::Http::Filters::HttpBaseProtocolFilter();

			Windows::Foundation::Uri ^ uri = ref new Windows::Foundation::Uri(TitaniumWindows::Utility::ConvertString(url));
			auto cookieCollection = filter->CookieManager->GetCookies(uri);

			Windows::Foundation::Collections::IIterator<Windows::Web::Http::HttpCookie^>^ iterator = cookieCollection->First();
			while (iterator->HasCurrent) {
				Windows::Web::Http::HttpCookie ^ cookie = iterator->Current;
				filter->CookieManager->DeleteCookie(cookie);
			}
		}

		std::string HTTPClient::getResponseHeader(const std::string& name) TITANIUM_NOEXCEPT
		{
			auto it = responseHeaders__.find(name.c_str());
			if (it != responseHeaders__.end()) {
				return it->second;
			} else {
				return "";
			}
		}

		void HTTPClient::open(const std::string& method, const std::string& url) TITANIUM_NOEXCEPT
		{
			method__ = N_HTTPCLIENT_METHOD_GET;
			if (method == "DELETE") {
				method__ = N_HTTPCLIENT_METHOD_DELETE;
			} else if (method == "POST") {
				method__ = N_HTTPCLIENT_METHOD_POST;
			} else if (method == "PUT") {
				method__ = N_HTTPCLIENT_METHOD_PUT;
			}

			url__ = url;
			filter__ = ref new Windows::Web::Http::Filters::HttpBaseProtocolFilter();
			httpClient__ = ref new Windows::Web::Http::HttpClient(filter__);
			cancellationTokenSource__ = concurrency::cancellation_token_source();
			filter__->AllowAutoRedirect;
			filter__->CacheControl->ReadBehavior = Windows::Web::Http::Filters::HttpCacheReadBehavior::MostRecent;

			addCookiesToRequest();
		}

		void HTTPClient::send() TITANIUM_NOEXCEPT
		{
			Windows::Foundation::Uri^ uri = ref new Windows::Foundation::Uri(TitaniumWindows::Utility::ConvertString(url__));
			Windows::Web::Http::HttpRequestMessage^ request = ref new Windows::Web::Http::HttpRequestMessage(Windows::Web::Http::HttpMethod::Get, uri);

			setRequestHeaders(request);

			// Startup a timer that will abort the request after the timeout period is reached.
			startDispatcherTimer();
			// FIXME Combine logic from all three send overloads. The others don't set request headers, but handling of response is all the same. Just a matter of constructing the request is different
			// clang-format off
			create_task(
			    httpClient__->SendRequestAsync(request, Windows::Web::Http::HttpCompletionOption::ResponseHeadersRead),
			    cancellationTokenSource__.get_token())
			.then([this](Windows::Web::Http::HttpResponseMessage^ response) {
		  
				readyState__ = Titanium::Network::N_REQUEST_STATE_OPENED;
				onreadystatechange(Titanium::Network::N_REQUEST_STATE_OPENED);

				SerializeHeaders(response);

				return create_task(response->Content->ReadAsInputStreamAsync(), cancellationTokenSource__.get_token());
			}, task_continuation_context::use_current())
			.then([this](Windows::Storage::Streams::IInputStream^ stream) {
			  
				readyState__ = Titanium::Network::N_REQUEST_STATE_LOADING;
				onreadystatechange(Titanium::Network::N_REQUEST_STATE_LOADING);

				return HTTPResultAsync(stream);
			}, task_continuation_context::use_current())
			.then([this](task<Windows::Storage::Streams::IBuffer^> previousTask) {
				try {
					// Check if any previous task threw an exception.
					previousTask.get();

					readyState__ = Titanium::Network::N_REQUEST_STATE_DONE;
					onreadystatechange(Titanium::Network::N_REQUEST_STATE_DONE);
				}
				catch (const task_canceled&) {
					onerror(-1, "Session Cancelled", false);
				}
				catch (Platform::Exception^ ex) {
					std::string error(TitaniumWindows::Utility::ConvertString(ex->Message));
					onerror(ex->HResult, error, false);
				}
			});
			// clang-format on
		}

		void HTTPClient::send(const std::map<std::string, std::vector<std::uint8_t>>& postDataPairs, const bool& useMultipartForm) TITANIUM_NOEXCEPT
		{
			Windows::Web::Http::IHttpContent^ postData;
			Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage^, Windows::Web::Http::HttpProgress>^ operation;

			if (method__ == N_HTTPCLIENT_METHOD_GET) {
				TITANIUM_LOG_WARN("HTTPClient::send: Data found during a GET request. Data will be ignored.");
				send();
			}

			Windows::Foundation::Uri ^ uri = ref new Windows::Foundation::Uri(TitaniumWindows::Utility::ConvertString(url__));

			// Startup a timer that will abort the request after the timeout period is reached.
			startDispatcherTimer();

			if (useMultipartForm) {
				postData = ref new Windows::Web::Http::HttpMultipartFormDataContent();

				for (auto pair : postDataPairs) {
					Platform::String ^ name = TitaniumWindows::Utility::ConvertString(pair.first);
					static_cast<Windows::Web::Http::HttpMultipartFormDataContent^>(postData)->Add(ref new Windows::Web::Http::HttpBufferContent(charVecToBuffer(pair.second)), name);
				}
			} else {
				auto keyValues = ref new Platform::Collections::Map<Platform::String^, Platform::String^>();
				for (auto pair : postDataPairs) {
					Platform::String ^ name = TitaniumWindows::Utility::ConvertString(pair.first);

					std::stringstream ws_stream;
					for (auto c : pair.second) {
						ws_stream << c;
					}

					Platform::String ^ value = TitaniumWindows::Utility::ConvertString(ws_stream.str());
					keyValues->Insert(name, value);
				}

				postData = ref new Windows::Web::Http::HttpFormUrlEncodedContent(keyValues);
			}

			if (method__ == N_HTTPCLIENT_METHOD_POST) {
				operation = httpClient__->PostAsync(uri, postData);
			} else {
				operation = httpClient__->PutAsync(uri, postData);
			}
			// clang-format off
			create_task(operation, cancellationTokenSource__.get_token())
			.then([this](Windows::Web::Http::HttpResponseMessage^ response) {

				readyState__ = Titanium::Network::N_REQUEST_STATE_OPENED;
				onreadystatechange(Titanium::Network::N_REQUEST_STATE_OPENED);

				SerializeHeaders(response);

				return response;
			}, task_continuation_context::use_current())
			.then([=](task<Windows::Web::Http::HttpResponseMessage^> previousTask) {
				try {
					// Check if any previous task threw an exception.
					previousTask.get();

					readyState__ = Titanium::Network::N_REQUEST_STATE_DONE;
					onreadystatechange(Titanium::Network::N_REQUEST_STATE_DONE);

					onload(0, "Response has been loaded.", true);
					onsendstream(1.0);
				}
				catch (const task_canceled&) {
					onerror(-1, "Session Cancelled", false);
				}
				catch (Platform::Exception^ ex) {
					std::string error(TitaniumWindows::Utility::ConvertString(ex->Message));
					onerror(ex->HResult, error, false);
				}
			}, task_continuation_context::use_current());
			// clang-format on
		}

		void HTTPClient::send(const std::string& postDataStr) TITANIUM_NOEXCEPT
		{
			Windows::Web::Http::IHttpContent^ postData;
			Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage^, Windows::Web::Http::HttpProgress>^ operation;

			if (method__ == N_HTTPCLIENT_METHOD_GET) {
				TITANIUM_LOG_WARN("HTTPClient::send: Data found during a GET request. Data will be ignored.");
				send();
			}

			Windows::Foundation::Uri ^ uri = ref new Windows::Foundation::Uri(TitaniumWindows::Utility::ConvertString(url__));

			// Startup a timer that will abort the request after the timeout period is reached.
			startDispatcherTimer();

			postData = ref new Windows::Web::Http::HttpStringContent(TitaniumWindows::Utility::ConvertString(postDataStr));

			if (method__ == N_HTTPCLIENT_METHOD_POST) {
				operation = httpClient__->PostAsync(uri, postData);
			} else {
				operation = httpClient__->PutAsync(uri, postData);
			}
			// clang-format off
			create_task(operation, cancellationTokenSource__.get_token())
			.then([this](Windows::Web::Http::HttpResponseMessage^ response) {
				SerializeHeaders(response);

				readyState__ = Titanium::Network::N_REQUEST_STATE_OPENED;
				onreadystatechange(Titanium::Network::N_REQUEST_STATE_OPENED);

				return response;
			}, task_continuation_context::use_current())
			.then([=](task<Windows::Web::Http::HttpResponseMessage^> previousTask) {
				try {
					// Check if any previous task threw an exception.
					previousTask.get();

					readyState__ = Titanium::Network::N_REQUEST_STATE_DONE;
					onreadystatechange(Titanium::Network::N_REQUEST_STATE_DONE);

					onload(0, "Response has been loaded.", true);
					onsendstream(1.0); 
				}
				catch (const task_canceled&) {
					onerror(-1, "Session Cancelled", false);
				}
				catch (Platform::Exception^ ex) {
					std::string error(TitaniumWindows::Utility::ConvertString(ex->Message));
					onerror(ex->HResult, error, false);
				}
			}, task_continuation_context::use_current());
			// clang-format on
		}

		void HTTPClient::setRequestHeader(const std::string& key, const std::string& value) TITANIUM_NOEXCEPT
		{
			requestHeaders__.insert(std::make_pair(key, value));
		}

		// properties
		std::string HTTPClient::get_allResponseHeaders() const TITANIUM_NOEXCEPT
		{
			std::stringstream s_stream;
			for (auto it = responseHeaders__.begin(); it != responseHeaders__.end(); ++it) {
				s_stream << it->first.c_str() << ":" << it->second.c_str() << ";";
			}

			return s_stream.str();
		}

		std::uint32_t HTTPClient::get_readyState() const TITANIUM_NOEXCEPT
		{
			return readyState__;
		}

		std::vector<std::uint8_t> HTTPClient::get_responseData() const TITANIUM_NOEXCEPT
		{
			return responseData__;
		}

		std::string HTTPClient::get_responseText() const TITANIUM_NOEXCEPT
		{
			return std::string(responseData__.begin(), responseData__.end());
		}

		std::uint32_t HTTPClient::get_status() const TITANIUM_NOEXCEPT
		{
			return requestStatus__;
		}

		void HTTPClient::set_timeout(const std::chrono::milliseconds& timeout) TITANIUM_NOEXCEPT
		{
			std::chrono::duration<std::chrono::nanoseconds::rep, std::ratio_multiply<std::ratio<100>, std::nano>> timer_interval_ticks = timeout;
			timeoutSpan__.Duration = timer_interval_ticks.count();
		}

		// Native
		void HTTPClient::setRequestHeaders(Windows::Web::Http::HttpRequestMessage^ request) TITANIUM_NOEXCEPT
		{
			// Set type safe headers. Content-Type is the most popular may need to set others.
			auto it = requestHeaders__.find("Content-Type");
			if (it != requestHeaders__.end()) {
				request->Content->Headers->ContentType =
					ref new Windows::Web::Http::Headers::HttpMediaTypeHeaderValue(TitaniumWindows::Utility::ConvertString(it->second));
				requestHeaders__.erase(it);
			}

			for (it = requestHeaders__.begin(); it != requestHeaders__.end(); ++it) {
				auto key = TitaniumWindows::Utility::ConvertString(it->first);
				auto value = TitaniumWindows::Utility::ConvertString(it->second);

				// ignore cookies they are added during open to the request filter.
				if (!key->Equals("Cookie")) {
					request->Headers->Append(key, value);
				}
			}
		}

		task<Windows::Storage::Streams::IBuffer^> HTTPClient::HTTPResultAsync(
		    Windows::Storage::Streams::IInputStream^ stream)
		{
			Windows::Storage::Streams::IBuffer^ responseBuffer = ref new Windows::Storage::Streams::Buffer(1000); // Default size from MS samples
			// clang-format off
			return create_task(
			           stream->ReadAsync(responseBuffer, responseBuffer->Capacity, Windows::Storage::Streams::InputStreamOptions::Partial),
			           cancellationTokenSource__.get_token())
			.then([=](task<Windows::Storage::Streams::IBuffer ^> readTask) {

				// Stop the timeout timer
				dispatcherTimer__->Stop();

				if (contentLength__ != -1) {
					ondatastream(responseBuffer->Length / contentLength__);
				}
				else {
					ondatastream(-1.0); // chunked encoding was used
				}

				if (!responseBuffer->Length) {
					onload(0, "Response has been loaded.", true);
				}
				else {
					auto reader = ::Windows::Storage::Streams::DataReader::FromBuffer(responseBuffer);
					responseData__.resize(responseDataLen__ + responseBuffer->Length);
					reader->ReadBytes(
						::Platform::ArrayReference<std::uint8_t>(
						&responseData__[responseDataLen__], responseBuffer->Length));
					responseDataLen__ += responseBuffer->Length;
				}

				return responseBuffer->Length ? HTTPResultAsync(stream) : readTask;
			}, task_continuation_context::use_current());
			// clang-format on
		}

		void HTTPClient::startDispatcherTimer()
		{
			if (dispatcherTimer__ == nullptr) {
				dispatcherTimer__ = ref new Windows::UI::Xaml::DispatcherTimer();
				dispatcherTimer__->Interval = timeoutSpan__;
				auto timeoutRegistrationToken__ = dispatcherTimer__->Tick += ref new Windows::Foundation::EventHandler<Platform::Object^>([this](Platform::Object^ sender, Platform::Object^ e) {
					cancellationTokenSource__.cancel();
					dispatcherTimer__->Stop();
					// re-create the CancellationTokenSource.
					cancellationTokenSource__ = cancellation_token_source();
				});
				dispatcherTimer__->Start();
			}
		}

		Windows::Storage::Streams::Buffer^ HTTPClient::charVecToBuffer(std::vector<std::uint8_t> char_vector)
		{
			int size = char_vector.size();

			Windows::Storage::Streams::Buffer^ buffer = ref new Windows::Storage::Streams::Buffer(size);
			buffer->Length = size;

			Microsoft::WRL::ComPtr<Windows::Storage::Streams::IBufferByteAccess> bufferByteAccess;
			HRESULT hr = reinterpret_cast<IUnknown*>(buffer)->QueryInterface(IID_PPV_ARGS(&bufferByteAccess));
			if (FAILED(hr)) {
				throw ref new Platform::Exception(hr);
			}

			std::uint8_t* data = (std::uint8_t*)&char_vector[0];
			hr = bufferByteAccess->Buffer(&data);
			if (FAILED(hr)) {
				throw ref new Platform::Exception(hr);
			}

			return buffer;
		}

		void HTTPClient::SerializeHeaders(Windows::Web::Http::HttpResponseMessage^ response)
		{
			requestStatus__ = (std::uint32_t)response->StatusCode;

			SerializeHeaderCollection(response->Headers);
			SerializeHeaderCollection(response->Content->Headers);

			std::map<std::string, std::string>::iterator it;
			it = responseHeaders__.find("Content-Length");
			if (it != responseHeaders__.end()) {
				contentLength__ = atol(it->second.c_str());
			} else {
				contentLength__ = -1;  // chunked encoding
			}

			readyState__ = Titanium::Network::N_REQUEST_STATE_HEADERS_RECEIVED;
			onreadystatechange(Titanium::Network::N_REQUEST_STATE_HEADERS_RECEIVED);
		}

		void HTTPClient::SerializeHeaderCollection(Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<Platform::String^, Platform::String^>^>^ headers)
		{
			for each(Windows::Foundation::Collections::IKeyValuePair<Platform::String^, Platform::String^>^ pair in headers)
			{
				responseHeaders__.insert(std::make_pair(TitaniumWindows::Utility::ConvertString(pair->Key), TitaniumWindows::Utility::ConvertString(pair->Value)));
			}
		}

		void HTTPClient::addCookiesToRequest()
		{
			auto url = TitaniumWindows::Utility::ConvertString(url__);

			for (auto it = requestHeaders__.begin(); it != requestHeaders__.end(); ++it) {
				
				auto key   = TitaniumWindows::Utility::ConvertString(it->first);
				auto value = TitaniumWindows::Utility::ConvertString(it->second);

				if (key->Equals("Cookie")) {
					//////////////////////////////////////////////////////////////////
					try {
						auto cookie = ref new Windows::Web::Http::HttpCookie(key, url, "/");

						char* context = nullptr;
						char* pvalue = strtok_s((char*)it->second.c_str(), "=", &context);
						if (pvalue != nullptr) {
							std::string str = std::string(pvalue);
							cookie->Value = TitaniumWindows::Utility::ConvertString(str);
							cookie->Expires = nullptr;
							cookie->Secure = false;
							cookie->HttpOnly = true;
							filter__->CookieManager->SetCookie(cookie, false);
						}
					} catch (Platform::InvalidArgumentException^ ex) {
						std::string error(TitaniumWindows::Utility::ConvertString(ex->Message));
						onerror(ex->HResult, error, false);
					} catch (Platform::Exception^ ex) {
						std::string error(TitaniumWindows::Utility::ConvertString(ex->Message));
						onerror(ex->HResult, error, false);
					}
				}
			}
		}
	}
}
