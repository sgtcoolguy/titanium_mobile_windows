/** -*- mode: c++ -*-
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MOBILE_WINDOWS_MODULES_NETWORK_TIHTTPClient_H_
#define _TITANIUM_MOBILE_WINDOWS_MODULES_NETWORK_TIHTTPClient_H_

#include "TiCore/TiProxy.h"
#include <string>
#include <ppltasks.h>

using namespace Concurrency;

namespace Network {

enum NATIVE_HTTPCLIENT_METHOD
{
	N_HTTPCLIENT_METHOD_GET
	//, N_HTTPCLIENT_METHOD_PUT - PUT method type not yet implemented
	, N_HTTPCLIENT_METHOD_POST
	, N_HTTPCLIENT_METHOD_DELETE
	, N_HTTPCLIENT_METHOD_HEAD
};

class HTTPClient final : public Ti::Proxy, public virtual_enable_shared_from_this<HTTPClient> {
	
  protected:
		 HTTPClient(const std::string& name, const std::vector<Ti::Value>& arguments);
     virtual ~HTTPClient();
	
	private:
    // method_ - type of HTTP request (GET, POST, PUT)
		std::string method_;
    // url_ - the full address of the HTTP request for example http://www.appcelerator.com
		std::string url_;
    // filter_ - controls the HTTP session and data flow
		Windows::Web::Http::Filters::HttpBaseProtocolFilter^ filter_;
    // httpClient - higher level HTTP client that provides WinRT API to HTTP sessions and communications
		Windows::Web::Http::HttpClient^ httpClient_;
    // cancellationTokenSource_ - HttpClient provides an asynchronous channel to handle HTTP reponses and
    // errors. Cancellation tokens allow the current HTTP 
		concurrency::cancellation_token_source cancellationTokenSource_;
    // timeout_ - when set will use cancellation token to cancel current HTTP session
    int32 timeout_;
    //  timeoutRegistrationToken_ - used to remove the timeout handler
    Windows::Foundation::EventRegistrationToken timeoutRegistrationToken_;
    // dispatcherTimer_ - WinRT timer used to cancel a HTTP connection if timeout specified 
    Windows::UI::Xaml::DispatcherTimer^ dispatcherTimer_;
    // rText_ - the data as text returned from a Get request 
    std::string rText_;

    task<Windows::Web::Http::HttpResponseMessage^> HTTPClient::DisplayTextResultAsync(
      Windows::Web::Http::HttpResponseMessage^ response,
      cancellation_token token);

	  ////////////////////////////////////////////////////////////////////////
	  //
	  // Proxy macro infrastructure goes below here.
	  //
	  ////////////////////////////////////////////////////////////////////////

	  TI_CREATE_PROXY(HTTPClient);

	  static JSClassRef Parent() {
		  return Ti::Proxy::ClassDef();
	  }

	  // Gets the value of the timeout property.
	  TI_CREATE_METHOD(HTTPClient, getTimeout);
	  Ti::Value getTimeout(const std::vector<Ti::Value>& arguments) const {
      return Ti::Value(static_cast<double>(timeout_));
	  }

	  // Sets the value of the timeout property.
	  TI_CREATE_METHOD(HTTPClient, setTimeout);
    Ti::Value setTimeout(const std::vector<Ti::Value>& arguments);

	  TI_CREATE_METHOD(HTTPClient, getResponseText);
	  Ti::Value getResponseText(const std::vector<Ti::Value>& arguments) {
		  return Ti::Value(rText_);
	  }

	  TI_CREATE_METHOD(HTTPClient, open);
    Ti::Value open(const std::vector<Ti::Value>& arguments);

	  TI_CREATE_METHOD(HTTPClient, send);
    Ti::Value send(const std::vector<Ti::Value>& arguments);

}; // class HTTPClient

}  // namespace Network {

#endif // _TITANIUM_MOBILE_WINDOWS_MODULES_NETWORK_TIHTTPClient_H_
