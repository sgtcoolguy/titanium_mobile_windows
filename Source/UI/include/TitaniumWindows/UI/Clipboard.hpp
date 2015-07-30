/**
 * Titanium.UI.Clipboard for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_CLIPBOARD_HPP_
#define _TITANIUMWINDOWS_CLIPBOARD_HPP_

#include "TitaniumWindows_UI_EXPORT.h"
#include "Titanium/UI/Clipboard.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		using namespace HAL;

		/*!
		  @class

		  @discussion This is the Titanium.UI.Clipboard implementation for Windows.
		*/
		class TITANIUMWINDOWS_UI_EXPORT Clipboard final : public Titanium::UI::Clipboard, public JSExport<Clipboard>
		{

		public:
			
			Clipboard(const JSContext&, const std::vector<JSValue>& arguments = {}) TITANIUM_NOEXCEPT;
			virtual ~Clipboard()                   = default;
			Clipboard(const Clipboard&)            = default;
			Clipboard& operator=(const Clipboard&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			Clipboard(Clipboard&&)                 = default;
			Clipboard& operator=(Clipboard&&)      = default;
#endif

			static void JSExportInitialize();

		private:

			virtual void clearData(const std::string& type) TITANIUM_NOEXCEPT;
			virtual void clearText() TITANIUM_NOEXCEPT;
			virtual JSObject getData(const std::string& type) TITANIUM_NOEXCEPT;
			virtual std::string getText() TITANIUM_NOEXCEPT;
			virtual bool hasData(const std::string& type) TITANIUM_NOEXCEPT;
			virtual bool hasText() TITANIUM_NOEXCEPT;
			virtual void setData(const std::string& type, JSObject data) TITANIUM_NOEXCEPT;
			virtual void setText(const std::string& text) TITANIUM_NOEXCEPT;

		};
	}  // namespace UI
}  // namespace TitaniumWindows
#endif // _TITANIUMWINDOWS_CLIPBOARD_HPP_