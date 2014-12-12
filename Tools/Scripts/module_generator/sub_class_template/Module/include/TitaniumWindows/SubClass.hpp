/**
 * Titanium.{#Module#}.{#SubClass#} for Windows
 * Author: {#Author#}
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_PLATFORM_{#SUBCLASS#}_HPP_
#define _TITANIUMWINDOWS_PLATFORM_{#SUBCLASS#}_HPP_

#include "TitaniumWindows/detail/{#Module#}Base.hpp"

namespace TitaniumWindows { namespace {#Module#} {

	using namespace JavaScriptCoreCPP;

	/*!
	@class
	@discussion This is the Titanium.{#Module#}.{#SubClass#} implementation for Windows.
	*/
	class TITANIUMWINDOWS_{#MODULE#}_EXPORT {#SubClass#} final : public Titanium::{#Module#}::{#SubClass#}, public JSExport < {#SubClass#} > {

	public:

		{#SubClass#}(const JSContext& js_context) TITANIUM_NOEXCEPT;
		{#SubClass#}(const {#SubClass#}&, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT;

		virtual ~{#SubClass#}() = default;
		{#SubClass#}(const {#SubClass#}&) = default;
		{#SubClass#}& operator=(const {#SubClass#}&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
		{#SubClass#}({#SubClass#}&&) = default;
		{#SubClass#}& operator=(Platform&&) = default;
#endif

{#MODULE_PROPERTY_DEFINITIONS#}
{#MODULE_METHOD_DEFINITIONS#}
		static void JSExportInitialize();

	private:

	};

}} // namespace Titanium, namespace {#SubClass#}
#endif // _TITANIUMWINDOWS_PLATFORM_HPP_
