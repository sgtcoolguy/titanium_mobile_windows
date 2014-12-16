/**
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/TitaniumModule.hpp"
#include <unordered_map>
#include <sstream>

namespace Titanium {

  TitaniumModule::TitaniumModule(const JSContext& js_context) TITANIUM_NOEXCEPT
    : Module(js_context),
        userAgent__(js_context.CreateString()) {
  }

  TitaniumModule::TitaniumModule(const TitaniumModule& rhs, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
    : Module(rhs, arguments),
        userAgent__(rhs.userAgent__) {
  }

  void TitaniumModule::JSExportInitialize() {
      JSExport<TitaniumModule>::SetClassVersion(1);
      JSExport<TitaniumModule>::SetParent(JSExport<Module>::Class());
      JSExport<TitaniumModule>::AddValueProperty("version", std::mem_fn(&TitaniumModule::get_version_ArgumentValidator));
      JSExport<TitaniumModule>::AddFunctionProperty("getVersion", std::mem_fn(&TitaniumModule::getVersionArgumentValidator));
      JSExport<TitaniumModule>::AddValueProperty("buildDate", std::mem_fn(&TitaniumModule::get_buildDate_ArgumentValidator));
      JSExport<TitaniumModule>::AddFunctionProperty("getBuildDate", std::mem_fn(&TitaniumModule::getBuildDateArgumentValidator));
      JSExport<TitaniumModule>::AddValueProperty("buildHash", std::mem_fn(&TitaniumModule::get_buildHash_ArgumentValidator));
      JSExport<TitaniumModule>::AddFunctionProperty("getBuildHash", std::mem_fn(&TitaniumModule::getBuildHashArgumentValidator));
      JSExport<TitaniumModule>::AddValueProperty("userAgent", std::mem_fn(&TitaniumModule::get_userAgent_ArgumentValidator));
      JSExport<TitaniumModule>::AddFunctionProperty("getUserAgent", std::mem_fn(&TitaniumModule::getUserAgentArgumentValidator));
      JSExport<TitaniumModule>::AddFunctionProperty("createBuffer", std::mem_fn(&TitaniumModule::createBufferArgumentValidator));
  }
    
    std::string TitaniumModule::version() const TITANIUM_NOEXCEPT {
        TITANIUM_LOG_WARN("TitaniumModule::version: Unimplemented");
        return "";
    }

    JSValue TitaniumModule::get_version_ArgumentValidator() const TITANIUM_NOEXCEPT {
        return get_context().CreateString(version());
    }
    
    JSValue TitaniumModule::getVersionArgumentValidator(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT {
        return get_version_ArgumentValidator();
    }

    std::string TitaniumModule::buildDate() const TITANIUM_NOEXCEPT {
        TITANIUM_LOG_WARN("TitaniumModule::buildDate: Unimplemented");
        return "";
    }

    JSValue TitaniumModule::get_buildDate_ArgumentValidator() const TITANIUM_NOEXCEPT {
        return get_context().CreateString(buildDate());
    }
    
    JSValue TitaniumModule::getBuildDateArgumentValidator(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT {
        return get_buildDate_ArgumentValidator();
    }

    std::string TitaniumModule::buildHash() const TITANIUM_NOEXCEPT {
        TITANIUM_LOG_WARN("TitaniumModule::buildHash: Unimplemented");
        return "";
    }

    JSValue TitaniumModule::get_buildHash_ArgumentValidator() const TITANIUM_NOEXCEPT {
        return get_context().CreateString(buildHash());
    }
    
    JSValue TitaniumModule::getBuildHashArgumentValidator(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT {
        return get_buildHash_ArgumentValidator();
    }

    JSValue TitaniumModule::get_userAgent_ArgumentValidator() const TITANIUM_NOEXCEPT {
        return userAgent__;
    }
    
    JSValue TitaniumModule::getUserAgentArgumentValidator(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT {
        return get_userAgent_ArgumentValidator();
    }

    void TitaniumModule::setUserAgent(const JSValue& userAgent) TITANIUM_NOEXCEPT {
        userAgent__ = userAgent;
    }

    bool TitaniumModule::setUserAgentArgumentValidator(const JSValue& argument) TITANIUM_NOEXCEPT {
        setUserAgent(argument);
        return true; 
    }

    JSValue TitaniumModule::createBufferArgumentValidator(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT {
        TITANIUM_LOG_WARN("TitaniumModule::createBufferArgumentValidator: Unimplemented");
        return get_context().CreateNull();
    }


} // namespace Titanium
