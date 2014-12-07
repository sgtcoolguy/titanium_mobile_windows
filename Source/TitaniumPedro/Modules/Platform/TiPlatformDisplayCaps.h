/** -*- mode: c++ -*-
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MOBILE_WINDOWS_MODULES_PLATFORM_TIDISPLAYCAPS_H_
#define _TITANIUM_MOBILE_WINDOWS_MODULES_PLATFORM_TIDISPLAYCAPS_H_

#include "TiCore/TiProxy.h"

namespace Ti { namespace Platform {

    class DisplayCaps : public Ti::Proxy, public virtual_enable_shared_from_this < DisplayCaps > {

    public:

    protected:

        DisplayCaps(const std::string& name, const std::vector<Ti::Value>& arguments);

        TI_CREATE_PROXY(DisplayCaps);

        static JSClassRef Parent() {
            return Ti::Proxy::ClassDef();
        }

        // Public API
        // Gets the value of the density property.
        TI_CREATE_METHOD(DisplayCaps, getDensity);
        Ti::Value DisplayCaps::getDensity(const std::vector<Ti::Value>& arguments);

        // Gets the value of the dpi property.
        TI_CREATE_METHOD(DisplayCaps, getDpi);
        Ti::Value DisplayCaps::getDpi(const std::vector<Ti::Value>& arguments);

        // Gets the value of the logicalDensityFactor property.
        TI_CREATE_METHOD(DisplayCaps, getLogicalDensityFactor);
        Ti::Value DisplayCaps::getLogicalDensityFactor(const std::vector<Ti::Value>& arguments);

        // Gets the value of the platformHeight property.
        TI_CREATE_METHOD(DisplayCaps, getPlatformHeight);
        Ti::Value DisplayCaps::getPlatformHeight(const std::vector<Ti::Value>& arguments);

        // Gets the value of the platformWidth property.
        TI_CREATE_METHOD(DisplayCaps, getPlatformWidth);
        Ti::Value DisplayCaps::getPlatformWidth(const std::vector<Ti::Value>& arguments);

        // Gets the value of the xdpi property.
        TI_CREATE_METHOD(DisplayCaps, getXdpi);
        Ti::Value DisplayCaps::getXdpi(const std::vector<Ti::Value>& arguments);

        // Gets the value of the ydpi property.
        TI_CREATE_METHOD(DisplayCaps, getYdpi);
        Ti::Value DisplayCaps::getYdpi(const std::vector<Ti::Value>& arguments);

    private:
        Windows::Graphics::Display::DisplayInformation^ display_;
    };

}} // namespace Ti { namespace Platform {

#endif // _TITANIUM_MOBILE_WINDOWS_MODULES_PLATFORM_TIDISPLAYCAPS_H_
