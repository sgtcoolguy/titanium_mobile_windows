/**
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_EXAMPLES_NATIVETitaniumEXAMPLE_HPP_
#define _TITANIUM_EXAMPLES_NATIVETitaniumEXAMPLE_HPP_

#include "Titanium/Titanium.hpp"

using namespace HAL;

/*!
 @class
 @discussion This is an example of how to implement Titanium::Titanium
 for a native Titanium.
 */
class NativeTitaniumExample final : public Titanium::TitaniumModule, public JSExport<NativeTitaniumExample> {
  
public:
  
  NativeTitaniumExample(const JSContext& js_context)                                    TITANIUM_NOEXCEPT;
  NativeTitaniumExample(const NativeTitaniumExample&, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT;
  
  virtual ~NativeTitaniumExample()                          = default;
  NativeTitaniumExample(const NativeTitaniumExample&)            = default;
  NativeTitaniumExample& operator=(const NativeTitaniumExample&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
  NativeTitaniumExample(NativeTitaniumExample&&)                 = default;
  NativeTitaniumExample& operator=(NativeTitaniumExample&&)      = default;
#endif
  
  static void JSExportInitialize();
  
protected:
  
  virtual std::string version() const TITANIUM_NOEXCEPT override final;
  virtual std::string buildDate() const TITANIUM_NOEXCEPT override final;
  virtual std::string buildHash() const TITANIUM_NOEXCEPT override final;
};

#endif // _TITANIUM_EXAMPLES_NATIVETitaniumEXAMPLE_HPP_
