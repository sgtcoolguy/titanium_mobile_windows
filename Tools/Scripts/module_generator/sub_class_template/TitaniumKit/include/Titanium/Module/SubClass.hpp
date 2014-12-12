/**
 * {#SubClass#}
 * Author: {#Author#}
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_{#MODULE#}_{#SUBCLASS#}_HPP_
#define _TITANIUM_{#MODULE#}_{#SUBCLASS#}_HPP_

#include "Titanium/Module.hpp"

namespace Titanium { namespace {#Module#} {

	using namespace JavaScriptCoreCPP;
	
	/*!
	@class
	 
	@discussion This is the Titanium {#Module#} {#SubClass#}.
	 
	See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.{#Module#}.{#SubClass#}
	*/
	class TITANIUMKIT_EXPORT {#SubClass#} : public Module, public JSExport<{#SubClass#}> {
	
	public:
	
{#KIT_PROPERTY_DEFINITIONS#}
{#KIT_METHOD_DEFINITIONS#}
		
		{#SubClass#}(const JSContext& js_context)													TITANIUM_NOEXCEPT;
		{#SubClass#}(const {#SubClass#}&, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT;
		
		virtual ~{#SubClass#}()									 = default;
		{#SubClass#}(const {#SubClass#}&)							 = default;
		{#SubClass#}& operator=(const {#SubClass#}&)		= default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
		{#SubClass#}({#SubClass#}&&)										= default;
		{#SubClass#}& operator=({#SubClass#}&&)				 = default;
#endif
		
		static void JSExportInitialize();
		
{#KIT_PROPERTY_VALIDATOR_DEFINITIONS#}
{#KIT_METHOD_VALIDATOR_DEFINITIONS#}
	};
}} // namespace Titanium, namespace {#Module#}

#endif // _TITANIUM_{#MODULE#}_{#SUBCLASS#}_HPP_
