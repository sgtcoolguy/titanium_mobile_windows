/**
 * Titanium.{#Module#} for Windows
 * Author: {#Author#}
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_{#MODULE#}_HPP_
#define _TITANIUMWINDOWS_{#MODULE#}_HPP_

#include "TitaniumWindows/detail/{#Module#}Base.hpp"

namespace TitaniumWindows {

  using namespace JavaScriptCoreCPP;

  /*!
    @class

    @discussion This is the Titanium.{#Module#} implementation for Windows.
    */
  class TITANIUMWINDOWS_{#MODULE#}_EXPORT {#ModuleName#} final : public Titanium::{#ModuleName#}, public JSExport < {#ModuleName#} > {

  public:

    {#ModuleName#}(const JSContext& js_context) TITANIUM_NOEXCEPT;
    {#ModuleName#}(const {#ModuleName#}&, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT;

    virtual ~{#ModuleName#}()                  = default;
    {#ModuleName#}(const {#ModuleName#}&)            = default;
    {#ModuleName#}& operator=(const {#ModuleName#}&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
    {#ModuleName#}({#ModuleName#}&&)                 = default;
    {#ModuleName#}& operator=({#ModuleName#}&&)      = default;
#endif

{#MODULE_PROPERTY_DEFINITIONS#}
{#MODULE_METHOD_DEFINITIONS#}

    static void JSExportInitialize();
	
  };

}  // namespace TitaniumWindows
#endif // _TITANIUMWINDOWS_{#MODULE#}_HPP_
