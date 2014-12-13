/**
 * Titanium.{#Module#} for Windows
 * Author: {#Author#}
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_{#MODULE#}_HPP_
#define _TITANIUM_{#MODULE#}_HPP_

#include "Titanium/Module.hpp"

namespace Titanium {

	using namespace JavaScriptCoreCPP;

	/*!
	 @class
	 @discussion This is the Titanium {#Module#} Module.
	 See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.{#Module#}
	 */
	class TITANIUMKIT_EXPORT {#ModuleName#} : public Module, public JSExport < {#ModuleName#} > {

	public:

{#KIT_PROPERTY_DEFINITIONS#}
{#KIT_METHOD_DEFINITIONS#}

		{#ModuleName#}(const JSContext& js_context) TITANIUM_NOEXCEPT;
		{#ModuleName#}(const {#ModuleName#}&, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT;

		virtual ~{#ModuleName#}() = default;
		{#ModuleName#}(const {#ModuleName#}&) = default;
		{#ModuleName#}& operator=(const {#ModuleName#}&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
		{#ModuleName#}({#ModuleName#}&&)                 = default;
		{#ModuleName#}& operator=({#ModuleName#}&&)      = default;
#endif

		static void JSExportInitialize();

{#KIT_PROPERTY_VALIDATOR_DEFINITIONS#}
{#KIT_METHOD_VALIDATOR_DEFINITIONS#}
	};

} // namespace Titanium

#endif // _TITANIUM_{#MODULE#}_HPP_
