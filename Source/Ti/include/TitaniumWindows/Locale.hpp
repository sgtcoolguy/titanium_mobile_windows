/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_LOCALE_HPP_
#define _TITANIUMWINDOWS_LOCALE_HPP_

#include "Titanium/Locale.hpp"
#include "TitaniumWindows_Ti_EXPORT.h"

namespace TitaniumWindows
{
	using namespace HAL;

	/*!
	  @class

	  @discussion This is the top-level Titanium module implementation for Windows.
	*/
	class TITANIUMWINDOWS_TI_EXPORT Locale final : public Titanium::Locale, public JSExport<Locale>
	{
	public:

		Locale(const JSContext&) TITANIUM_NOEXCEPT;

		virtual ~Locale();
		Locale(const Locale&) = default;
		Locale& operator=(const Locale&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
		Locale(Locale&&) = default;
		Locale& operator=(Locale&&) = default;
#endif

		static void JSExportInitialize();

	private:
	};

}  // namespace TitaniumWindows

#endif  // _TITANIUMWINDOWS_LOCALE_HPP_
