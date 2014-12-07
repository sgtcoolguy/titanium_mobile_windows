/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#include "TiHTTPClient.h"

namespace Network {

// called when this js proxy is created
HTTPClient::HTTPClient(const std::string& name, const std::vector<Ti::Value>& arguments) : Ti::Proxy(name, arguments) {}

HTTPClient::~HTTPClient() {
  filter_ = nullptr;
  httpClient_ = nullptr;
  dispatcherTimer_ = nullptr;
}  

Ti::Value HTTPClient::setTimeout(const std::vector<Ti::Value>& arguments) {

  timeout_ = static_cast<int32>(arguments.at(0).toDouble());
  Windows::Foundation::TimeSpan span;
  span.Duration = timeout_ * 1000; // TimeSpan is in nano seconds
  if (dispatcherTimer_ == nullptr) {
    dispatcherTimer_ = ref new Windows::UI::Xaml::DispatcherTimer();
    auto timeoutRegistrationToken_ =
      dispatcherTimer_->Tick += ref new Windows::Foundation::EventHandler<Platform::Object^>([this](Platform::Object^ sender, Platform::Object^ e) {
        dispatcherTimer_->Stop();
        // re-create the CancellationTokenSource.
        cancellationTokenSource_ = cancellation_token_source();
    });
  }
  dispatcherTimer_->Interval = span;
  dispatcherTimer_->Start();

  return Ti::Value::Undefined();
}

Ti::Value HTTPClient::open(const std::vector<Ti::Value>& arguments) {

  std::string method = arguments.at(0).toString();
  url_ = arguments.at(1).toString();
  auto method_ = N_HTTPCLIENT_METHOD_GET;
  if (method == "DELETE") {
    method_ = N_HTTPCLIENT_METHOD_DELETE;
  }
  else if (method == "POST") {
    method_ = N_HTTPCLIENT_METHOD_POST;
  }

  filter_ = ref new Windows::Web::Http::Filters::HttpBaseProtocolFilter();
  httpClient_ = ref new Windows::Web::Http::HttpClient(filter_);
  cancellationTokenSource_ = concurrency::cancellation_token_source();
  filter_->AllowAutoRedirect;
  filter_->CacheControl->ReadBehavior = Windows::Web::Http::Filters::HttpCacheReadBehavior::MostRecent;

  return Ti::Value::Undefined();
}

task<Windows::Web::Http::HttpResponseMessage^> HTTPClient::DisplayTextResultAsync(
  Windows::Web::Http::HttpResponseMessage^ response,
  cancellation_token token) {

  // read content as string. We need to use use_current() with the continuations since the tasks are completed on
  // background threads and we need to run on the UI thread to update the UI.
  task<Platform::String^> readAsStringTask(response->Content->ReadAsStringAsync(), token);
  return readAsStringTask.then([=](Platform::String^ responseBodyAsText) {
    dispatcherTimer_->Stop();
    std::wstring ws = responseBodyAsText->Data();
    std::string text(ws.begin(), ws.end());
    rText_ = text; // this.getReponseText() will retrieve the response data as text
    return response;
  }, task_continuation_context::use_current());
}

Ti::Value HTTPClient::send(const std::vector<Ti::Value>& arguments) {

  std::wstring w_str(url_.begin(), url_.end());
  Platform::String^ url = ref new Platform::String(w_str.c_str());
  Windows::Foundation::Uri^ uri = ref new Windows::Foundation::Uri(url);

  // do an asynchronous GET. We need to use use_current() with the continuations since the tasks are completed on
  // background threads and we need to run on the UI thread to update the UI.
  create_task(httpClient_->GetAsync(uri), cancellationTokenSource_.get_token()).then([=](Windows::Web::Http::HttpResponseMessage^ response) {
    return DisplayTextResultAsync(response, cancellationTokenSource_.get_token());
  }, task_continuation_context::use_current()).then([=](task<Windows::Web::Http::HttpResponseMessage^> previousTask) {  
    try {
      // Check if any previous task threw an exception.
      Windows::Web::Http::HttpResponseMessage^ response = previousTask.get();
      {
        Ti::Value response;
        response.setProperty("text", Ti::Value(rText_));
        fireCallback("onload", response);
      }
    }
    catch (const task_canceled&) {
      {
        Ti::Value response;
        response.setProperty("error", Ti::Value("session cancelled by timeout"));
        //  onerror function called when an error occurs, including a timeout
        fireCallback("onerror", response);
      }
    }
    catch (Platform::Exception^ ex) {
      {
        Ti::Value response;
        response.setProperty("error", Ti::Value("caught exception")); //  ToDo need cnstr for String^ Ti::Value(ex->ToString()));
        //  onerror function called when an error occurs, including a timeout
        fireCallback("onerror", response);
      }
    }
  });

  return Ti::Value::Undefined();
}

////////////////////////////////////////////////////////////////////////
//
// Proxy macro infrastructure goes below here.
//
////////////////////////////////////////////////////////////////////////

const JSStaticFunction HTTPClient::ClassMethods[] = {
	{ "getTimeout", _getTimeout, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "setTimeout", _setTimeout, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },	
	{ "getResponseText", _getResponseText, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete},
	{ "open", _open, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "send", _send, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ 0, 0, 0 }
};

}  // namespace Network {
