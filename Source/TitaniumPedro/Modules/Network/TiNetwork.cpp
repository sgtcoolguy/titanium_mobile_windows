/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#include "TiNetwork.h"
#include "TiHTTPClient.h"
#include <Windows.h>
#include "TiCore/TiRuntimeFunctions.h"

namespace Network {

	static const std::string gCode =
		"(function(self){"
		"   Object.defineProperties(self.TiHTTPClient.prototype, {"
		"       'timeout': {set:function(value){this.setTimeout(value);},get:function(){return this.getTimeout();}, enumerable:true},"
		"       'responseText': {get:function(){return this.getResponseText();}, enumerable:true},"
		"   });"
		"   Object.defineProperties(self.TiNetwork.prototype, {"
		"       'MODE_APPEND': {get:function(){return this.getMODE_APPEND();}, enumerable:true},"
		"   });"
		""
		"   var exports = new self.TiNetwork();"
		""
		"   /*"
		"    * Ti.Network.createHTTPClient"
		"    * Returns a HTTP object to used in client network communications including HTML."
		"    */"
		"   exports.createHTTPClient = function(_args) {												"
		"       var httpClient =  new self.TiHTTPClient();"
		"		httpClient.applyProperties(_args);"
		"       return httpClient;"
		"   };"
		""
		"   return exports;"
		"})(this);"
		;

Ti::Value NetworkModule::Initialize(const std::string& ns, Ti::Value& obj) {
	Ti::Value networkModule;

	networkModule.setProperty("global", Ti::Value(Ti::Runtime::instance().globalObject()));
	networkModule.setProperty("TiHTTPClient", Network::HTTPClient::CreateConstructor());
	networkModule.setProperty("TiNetwork", Network::NetworkModule::CreateConstructor());

	Ti::Value result = Ti::evaluateScriptInObject(gCode, networkModule);

	obj.setProperty(ns, result);

	return result;
}


////////////////////////////////////////////////////////////////////////
//
// Proxy macro infrastructure goes below here.
//
////////////////////////////////////////////////////////////////////////

const JSStaticFunction NetworkModule::ClassMethods[] = {
	{ "getMODE_APPEND", _getMODE_APPEND, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getApplicationCacheDirectory", _getApplicationCacheDirectory, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ 0, 0, 0 }
};

}  // namespace Network {
