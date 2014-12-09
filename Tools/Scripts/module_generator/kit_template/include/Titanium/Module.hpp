/**
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_{#NAME#}_HPP_
#define _TITANIUM_{#NAME#}_HPP_

#include "Titanium/Module.hpp"

namespace Titanium {

	using namespace JavaScriptCoreCPP;

	/*!
	 @class
	 @discussion This is the Titanium {#Name#} Module.
	 See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.{#Name#}
	 */
	class TITANIUMKIT_EXPORT {#Name#} : public Module, public JSExport < {#Name#} > {

	public:

{#KIT_PROPERTY_DEFINITIONS#}
{#KIT_METHOD_DEFINITIONS#}

		{#Name#}(const JSContext& js_context) TITANIUM_NOEXCEPT;
		{#Name#}(const {#Name#}&, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT;

		virtual ~{#Name#}() = default;
		{#Name#}(const {#Name#}&) = default;
		{#Name#}& operator=(const {#Name#}&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
		{#Name#}({#Name#}&&)                 = default;
		{#Name#}& operator=({#Name#}&&)      = default;
#endif

		static void JSExportInitialize();

{#KIT_PROPERTY_VALIDATOR_DEFINITIONS#}
{#KIT_METHOD_VALIDATOR_DEFINITIONS#}
	};

} // namespace Titanium

#endif // _TITANIUM_{#NAME#}_HPP_
