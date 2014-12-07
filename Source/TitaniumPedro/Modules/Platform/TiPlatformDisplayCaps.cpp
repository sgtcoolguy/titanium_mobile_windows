/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#include "TiPlatformDisplayCaps.h"
#include "TiCore\TiRuntimeFunctions.h"

namespace Ti { namespace Platform {

    // These are JavaScript methods they will call class methods
    const JSStaticFunction DisplayCaps::ClassMethods[] = {
            { "getDensity", _getDensity, 0 },
            { "getDpi", _getDpi, 0 },
            { "getLogicalDensityFactor", _getLogicalDensityFactor, 0 },
            { "getPlatformHeight", _getPlatformHeight, 0 },
            { "getPlatformWidth", _getPlatformWidth, 0 },
            { "getXdpi", _getXdpi, 0 },
            { "getYdpi", _getYdpi, 0 },
            { 0, 0, 0 }
    };

    DisplayCaps::DisplayCaps(const std::string& name, const std::vector<Ti::Value>& arguments) : Ti::Proxy(name, arguments) {
        display_ = Windows::Graphics::Display::DisplayInformation::GetForCurrentView();
    }

    // Public API
    // Gets the value of the density property.
    Ti::Value DisplayCaps::getDensity(const std::vector<Ti::Value>& arguments) {
        // On Windows, there's no string value to describe screen density like "high" and "medium".
        // Returning undefined for now
        return Ti::Value::Undefined();
    }
    // Gets the value of the dpi property.
    Ti::Value DisplayCaps::getDpi(const std::vector<Ti::Value>& arguments) {
        return Ti::Value(display_->LogicalDpi);
    }
    // Gets the value of the logicalDensityFactor property.
    Ti::Value DisplayCaps::getLogicalDensityFactor(const std::vector<Ti::Value>& arguments) {
#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
        return Ti::Value(display_->RawPixelsPerViewPixel);
#else
        return Ti::Value(static_cast<double>(static_cast<int>(display_->ResolutionScale) / 100.0));
#endif
    }
    // Gets the value of the platformHeight property.
    Ti::Value DisplayCaps::getPlatformHeight(const std::vector<Ti::Value>& arguments) {
        return Ti::Value(Windows::UI::Xaml::Window::Current->Bounds.Height);
    }
    // Gets the value of the platformWidth property.
    Ti::Value DisplayCaps::getPlatformWidth(const std::vector<Ti::Value>& arguments) {
        return Ti::Value(Windows::UI::Xaml::Window::Current->Bounds.Width);
    }
    // Gets the value of the xdpi property.
    Ti::Value DisplayCaps::getXdpi(const std::vector<Ti::Value>& arguments) {
        return Ti::Value(display_->RawDpiX);
    }
    // Gets the value of the ydpi property.
    Ti::Value DisplayCaps::getYdpi(const std::vector<Ti::Value>& arguments) {
        return Ti::Value(display_->RawDpiY);
    }

} } // namespace Ti { namespace Platform {
