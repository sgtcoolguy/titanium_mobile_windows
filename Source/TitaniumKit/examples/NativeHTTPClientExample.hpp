/**
 * TitaniumKit
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_EXAMPLES_HTTPCLIENTEXAMPLE_HPP_
#define _TITANIUM_EXAMPLES_HTTPCLIENTEXAMPLE_HPP_

#include "Titanium/Network/HTTPClient.hpp"

using namespace HAL;

/*!
  @class
  @discussion This is an example of how to implement Titanium::Network::HTTPClient
  for a native platform.
 */
class NativeHTTPClientExample final : public Titanium::Network::HTTPClient, public JSExport<NativeHTTPClientExample>
{
public:
	NativeHTTPClientExample(const JSContext&) TITANIUM_NOEXCEPT;

	virtual ~NativeHTTPClientExample() TITANIUM_NOEXCEPT;
	NativeHTTPClientExample(const NativeHTTPClientExample&) = default;
	NativeHTTPClientExample& operator=(const NativeHTTPClientExample&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
	NativeHTTPClientExample(NativeHTTPClientExample&&) = default;
	NativeHTTPClientExample& operator=(NativeHTTPClientExample&&) = default;
#endif

	static void JSExportInitialize();
};

#endif  // _TITANIUM_EXAMPLES_HTTPCLIENTEXAMPLE_HPP_
