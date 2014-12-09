/**
 * Titanium.{#Name#} for Windows
 * Author: {#Author#}
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_{#NAME#}_HPP_
#define _TITANIUMWINDOWS_{#NAME#}_HPP_

#include "TitaniumWindows/detail/{#Name#}Base.hpp"

namespace TitaniumWindows {

  using namespace JavaScriptCoreCPP;

  /*!
    @class

    @discussion This is the Titanium.{#Name#} implementation for Windows.
    */
  class TITANIUMWINDOWS_{#NAME#}_EXPORT {#Name#} final : public Titanium::{#Name#}, public JSExport < {#Name#} > {

  public:

    {#Name#}(const JSContext& js_context) TITANIUM_NOEXCEPT;
    {#Name#}(const {#Name#}&, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT;

    virtual ~{#Name#}()                  = default;
    {#Name#}(const {#Name#}&)            = default;
    {#Name#}& operator=(const {#Name#}&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
    {#Name#}({#Name#}&&)                 = default;
    {#Name#}& operator=({#Name#}&&)      = default;
#endif

{#MODULE_PROPERTY_DEFINITIONS#}
{#MODULE_METHOD_DEFINITIONS#}

    static void JSExportInitialize();
	
  };

}  // namespace TitaniumWindows

#endif // _TITANIUMWINDOWS_{#NAME#}_HPP_
