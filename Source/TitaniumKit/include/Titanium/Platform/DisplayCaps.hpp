/**
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_PLATFORM_DISPLAYCAPS_HPP_
#define _TITANIUM_PLATFORM_DISPLAYCAPS_HPP_

#include "Titanium/Module.hpp"

namespace Titanium { namespace Platform {

  using namespace HAL;

  enum BatteryState {
    UNKNOWN = 0,
    UNPLUGGED,
    CHARGING,
    FULL
  };
  
  /*!
   @class
   @discussion This is the Ti.Platform.DisplayCaps Module.
   See http://docs.appcelerator.com/titanium/latest/#!/api/Ti.Platform.DisplayCaps
  */
  class TITANIUMKIT_EXPORT DisplayCaps : public Module, public JSExport < DisplayCaps > {

  public:

    virtual std::string density() const TITANIUM_NOEXCEPT;
    virtual unsigned dpi() const TITANIUM_NOEXCEPT;
    virtual unsigned logicalDensityFactor() const TITANIUM_NOEXCEPT;
    virtual unsigned platformHeight() const TITANIUM_NOEXCEPT;
    virtual unsigned platformWidth()  const TITANIUM_NOEXCEPT;
    virtual unsigned xdpi()  const TITANIUM_NOEXCEPT;
    virtual unsigned ydpi()  const TITANIUM_NOEXCEPT;

    DisplayCaps(const JSContext& js_context)                       TITANIUM_NOEXCEPT;
    DisplayCaps(const DisplayCaps&, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT;

    virtual ~DisplayCaps() = default;
    DisplayCaps(const DisplayCaps&) = default;
    DisplayCaps& operator=(const DisplayCaps&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
    DisplayCaps(DisplayCaps&&)                 = default;
    DisplayCaps& operator=(DisplayCaps&&)      = default;
#endif

    static void JSExportInitialize();

    virtual JSValue get_density_ArgumentValidator() const TITANIUM_NOEXCEPT final;
    virtual JSValue getDensityArgumentValidator(const std::vector<JSValue>&, JSObject&) const TITANIUM_NOEXCEPT final;
    virtual JSValue get_dpi_ArgumentValidator() const TITANIUM_NOEXCEPT final;
    virtual JSValue getDpiArgumentValidator(const std::vector<JSValue>&, JSObject&) const TITANIUM_NOEXCEPT final;
    virtual JSValue get_logicalDensityFactor_ArgumentValidator() const TITANIUM_NOEXCEPT final;
    virtual JSValue getLogicalDensityFactorArgumentValidator(const std::vector<JSValue>&, JSObject&) const TITANIUM_NOEXCEPT final;
    virtual JSValue get_platformHeight_ArgumentValidator() const TITANIUM_NOEXCEPT final;
    virtual JSValue getPlatformHeightArgumentValidator(const std::vector<JSValue>&, JSObject&) const TITANIUM_NOEXCEPT final;
    virtual JSValue get_platformWidth_ArgumentValidator() const TITANIUM_NOEXCEPT final;
    virtual JSValue getPlatformWidthArgumentValidator(const std::vector<JSValue>&, JSObject&) const TITANIUM_NOEXCEPT final;
    virtual JSValue get_xdpi_ArgumentValidator() const TITANIUM_NOEXCEPT final;
    virtual JSValue getXdpiArgumentValidator(const std::vector<JSValue>&, JSObject&) const TITANIUM_NOEXCEPT final;
    virtual JSValue get_ydpi_ArgumentValidator() const TITANIUM_NOEXCEPT final;
    virtual JSValue getYdpiArgumentValidator(const std::vector<JSValue>&, JSObject&) const TITANIUM_NOEXCEPT final;

  };

} } // namespace Titanium { namespace Platform {

#endif // _TITANIUM_PLATFORM_DISPLAYCAPS_HPP_
