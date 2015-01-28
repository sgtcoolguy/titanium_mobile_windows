/**
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "HTTPClient.hpp"
#include "Titanium/detail/TiBase.hpp"

#include <collection.h>
#include <algorithm>

using namespace concurrency;

namespace TitaniumWindows
{
	namespace Network
	{
		HTTPClient::HTTPClient(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
		    : Titanium::Network::HTTPClient(js_context, arguments)
		{
			TITANIUM_LOG_DEBUG("TitaniumWindows::Network::HTTPClient::ctor Initialize");

			responseBuffer__ = ref new Windows::Storage::Streams::Buffer(1000);
		}

		HTTPClient::~HTTPClient()
		{
			TITANIUM_LOG_DEBUG("TitaniumWindows::Network::HTTPClient::dtor");
			filter__ = nullptr;
			httpClient__ = nullptr;
			dispatcherTimer__ = nullptr;
			responseBuffer__ = nullptr;
		}

		void HTTPClient::JSExportInitialize()
		{
			JSExport<HTTPClient>::SetClassVersion(1);
			JSExport<HTTPClient>::SetParent(JSExport<Titanium::Network::HTTPClient>::Class());
		}

		void HTTPClient::setTimeout(double timeout) TITANIUM_NOEXCEPT
		{
			std::chrono::milliseconds duration((long long)timeout);
			std::chrono::duration<std::chrono::nanoseconds::rep, std::ratio_multiply<std::ratio<100>, std::nano>> timer_interval_ticks = duration;
			timeoutSpan__.Duration = timer_interval_ticks.count();
		}

		void HTTPClient::open(const std::string& method, const std::string& url) TITANIUM_NOEXCEPT
		{
			auto method__ = N_HTTPCLIENT_METHOD_GET;
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
		}

		void HTTPClient::send() TITANIUM_NOEXCEPT
		{
			std::wstring w_str(url__.begin(), url__.end());
			Platform::String ^ url = ref new Platform::String(w_str.c_str());
			Windows::Foundation::Uri ^ uri = ref new Windows::Foundation::Uri(url);
			Windows::Web::Http::HttpRequestMessage ^ request = ref new Windows::Web::Http::HttpRequestMessage(Windows::Web::Http::HttpMethod::Get, uri);

			// Startup a timer that will abort the request after the timeout period is reached.
			startDispatcherTimer();

			create_task(
			    httpClient__->SendRequestAsync(request, Windows::Web::Http::HttpCompletionOption::ResponseHeadersRead),
			    cancellationTokenSource__.get_token()).then([this](Windows::Web::Http::HttpResponseMessage ^ response) {

		  SerializeHeaders(response);

		  return create_task(response->Content->ReadAsInputStreamAsync(), cancellationTokenSource__.get_token()); }, task_continuation_context::use_current())
			    .then([this](Windows::Storage::Streams::IInputStream ^ stream) {
		  return HTTPResultAsync(stream); }, task_continuation_context::use_current())
			    .then([this](task<Windows::Storage::Streams::IBuffer ^> previousTask) {
		  try {
			  // Check if any previous task threw an exception.
			  previousTask.get();
		  }
		  catch (const task_canceled&) {
			 onerror(0, "Session Cancelled", false);
		  }
		  catch (Platform::Exception^ ex) {
			  std::wstring werror = ex->Message->Data();
			  std::string error((const char*)&werror[0], sizeof(wchar_t) / sizeof(char)*werror.size());
			  onerror(0, error, false);
		  } });
		}

		task<Windows::Storage::Streams::IBuffer ^> HTTPClient::HTTPResultAsync(
		    Windows::Storage::Streams::IInputStream ^ stream)
		{
			return create_task(
			           stream->ReadAsync(responseBuffer__, responseBuffer__->Capacity, Windows::Storage::Streams::InputStreamOptions::Partial),
			           cancellationTokenSource__.get_token()).then([=](task<Windows::Storage::Streams::IBuffer ^> readTask) {

		  // Stop the timeout timer
		  dispatcherTimer__->Stop();

		  //ondatastream(responseBuffer__->Length/headerlength__);

		  if (!responseBuffer__->Length) {
			  onload(0,  "Response has been loaded.", true);
		  }

		  return responseBuffer__->Length ? HTTPResultAsync(stream) : readTask; }, task_continuation_context::use_current());
		}

		void HTTPClient::send(const std::map<std::string, std::vector<char>>& postDataPairs, bool useMultipartForm) TITANIUM_NOEXCEPT
		{
			Windows::Web::Http::IHttpContent ^ postData;

			if (method__ == N_HTTPCLIENT_METHOD_GET) {
				TITANIUM_LOG_WARN("HTTPClient::send: Data found during a GET request. Data will be ignored.");
				send();
			}

			std::wstring w_str(url__.begin(), url__.end());
			Platform::String ^ url = ref new Platform::String(w_str.c_str());
			Windows::Foundation::Uri ^ uri = ref new Windows::Foundation::Uri(url);

			// Startup a timer that will abort the request after the timeout period is reached.
			startDispatcherTimer();

			if (useMultipartForm) {
				postData = ref new Windows::Web::Http::HttpMultipartFormDataContent();

				for (auto pair : postDataPairs) {
					std::wstring w_str(pair.first.begin(), pair.first.end());
					Platform::String ^ name = ref new Platform::String(w_str.c_str());
					static_cast<Windows::Web::Http::HttpMultipartFormDataContent ^>(postData)->Add(ref new Windows::Web::Http::HttpBufferContent(charVecToBuffer(pair.second)), name);
				}
			} else {
				auto keyValues = ref new Platform::Collections::Map<Platform::String ^, Platform::String ^>();
				for (auto pair : postDataPairs) {
					std::wstring w_str(pair.first.begin(), pair.first.end());
					Platform::String ^ name = ref new Platform::String(w_str.c_str());

					std::wstringstream ws_stream;
					for (auto c : pair.second) {
						ws_stream << c;
					}
					w_str = ws_stream.str();

					Platform::String ^ value = ref new Platform::String(w_str.c_str());
					keyValues->Insert(name, value);
				}

				postData = ref new Windows::Web::Http::HttpFormUrlEncodedContent(keyValues);
			}

			create_task(httpClient__->PostAsync(uri, postData), cancellationTokenSource__.get_token()).then([this](Windows::Web::Http::HttpResponseMessage ^ response) {

		 SerializeHeaders(response);

		  return response; }, task_continuation_context::use_current()).then([=](task<Windows::Web::Http::HttpResponseMessage ^> previousTask) {
		  try {
			  // Check if any previous task threw an exception.
			  previousTask.get();
		  }
		  catch (const task_canceled&) {
			  onerror(0, "Session Cancelled", false);
		  }
		  catch (Platform::Exception^ ex) {
			  std::wstring werror = ex->Message->Data();
			  std::string error((const char*)&werror[0], sizeof(wchar_t) / sizeof(char)*werror.size());
			  onerror(0, error, false);
		  } }, task_continuation_context::use_current());
		}

		void HTTPClient::startDispatcherTimer()
		{
			if (dispatcherTimer__ == nullptr) {
				dispatcherTimer__ = ref new Windows::UI::Xaml::DispatcherTimer();
				dispatcherTimer__->Interval = timeoutSpan__;
				auto timeoutRegistrationToken__ =
				    dispatcherTimer__->Tick += ref new Windows::Foundation::EventHandler<Platform::Object ^>([this](Platform::Object ^ sender, Platform::Object ^ e) {
			  cancellationTokenSource__.cancel();
			  dispatcherTimer__->Stop();
			  // re-create the CancellationTokenSource.
			  cancellationTokenSource__ = cancellation_token_source();
					});
				dispatcherTimer__->Start();
			}
		}

		Windows::Storage::Streams::Buffer ^ HTTPClient::charVecToBuffer(std::vector<char> char_vector)
		{
			int size = char_vector.size();

			Windows::Storage::Streams::Buffer ^ buffer = ref new Windows::Storage::Streams::Buffer(size);
			buffer->Length = size;

			Microsoft::WRL::ComPtr<Windows::Storage::Streams::IBufferByteAccess> bufferByteAccess;
			HRESULT hr = reinterpret_cast<IUnknown*>(buffer)->QueryInterface(IID_PPV_ARGS(&bufferByteAccess));
			if (FAILED(hr)) {
				throw ref new Platform::Exception(hr);
			}

			unsigned char* data = (unsigned char*)&char_vector[0];
			hr = bufferByteAccess->Buffer(&data);
			if (FAILED(hr)) {
				throw ref new Platform::Exception(hr);
			}

			return buffer;
		}

		Platform::String ^ HTTPClient::SerializeHeaders(Windows::Web::Http::HttpResponseMessage ^ response)
		{
			Platform::String ^ output = "";

			UINT32 statusCode = (UINT32)response->StatusCode;
			//String^ statusCodeString = CppSamplesUtils::Details::ToString(statusCode);
			//output += statusCodeString + " " + response->ReasonPhrase + "\n";

			output += SerializeHeaderCollection(response->Headers);
			output += SerializeHeaderCollection(response->Content->Headers);
			output += "\r\n";

			return output;
		}

		Platform::String ^ HTTPClient::SerializeHeaderCollection(Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<Platform::String ^, Platform::String ^> ^> ^ headers)
		{
			Platform::String ^ output = "";

			for each(Windows::Foundation::Collections::IKeyValuePair<Platform::String ^, Platform::String ^> ^ pair in headers)
			{
			  output += pair->Key + ": " + pair->Value + "\r\n";
			}

			return output;
		}
	}
} 
