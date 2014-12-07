/**
 * Titanium.Platform for Windows
 * Author: Gary Mathews
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_PLATFORM_HPP_
#define _TITANIUMWINDOWS_PLATFORM_HPP_

#include "TitaniumWindows/detail/PlatformBase.hpp"

namespace TitaniumWindows {

  using namespace JavaScriptCoreCPP;

  /*!
    @class

    @discussion This is the Titanium.Platform implementation for Windows.
    */
  class TITANIUMWINDOWS_PLATFORM_EXPORT Platform final : public Titanium::Platform, public JSExport < Platform >{

  public:

    Platform(const JSContext& js_context) TITANIUM_NOEXCEPT;
    Platform(const Platform&, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT;

    virtual ~Platform()             = default;
    Platform(const Platform&)            = default;
    Platform& operator=(const Platform&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
    Platform(Platform&&)                 = default;
    Platform& operator=(Platform&&)      = default;
#endif

    static void JSExportInitialize();

  protected:

    virtual JSString osname() const TITANIUM_NOEXCEPT override final;
	virtual JSString createUUID() TITANIUM_NOEXCEPT override final;
	
  private:
    JSString osname__;
	
  };

}  // namespace TitaniumWindows

#endif // _TITANIUMWINDOWS_PLATFORM_HPP_
