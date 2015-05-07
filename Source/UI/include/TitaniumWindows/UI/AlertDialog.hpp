/**
* Titanium.UI.AlertDialog for Windows
*
* Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/

#ifndef _TITANIUMWINDOWS_UI_ALERTDIALOG_HPP_
#define _TITANIUMWINDOWS_UI_ALERTDIALOG_HPP_

#include "TitaniumWindows/UI/detail/UIBase.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		using namespace HAL;

		/*!
		  @class

		  @discussion This is the Titanium.UI.AlertDialog implementation for
		  Windows.
		*/
		class TITANIUMWINDOWS_UI_EXPORT AlertDialog final : public Titanium::UI::AlertDialog, public JSExport<AlertDialog>
		{
		public:
			AlertDialog(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~AlertDialog() = default;
			AlertDialog(const AlertDialog&) = default;
			AlertDialog& operator=(const AlertDialog&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			AlertDialog(AlertDialog&&) = default;
			AlertDialog& operator=(AlertDialog&&) = default;
#endif

			static void JSExportInitialize();

			virtual void hide() TITANIUM_NOEXCEPT override;
			virtual void show() TITANIUM_NOEXCEPT override;
			virtual void addButton(const std::string& buttonName) TITANIUM_NOEXCEPT override final;

		private:
#pragma warning(push)
#pragma warning(disable : 4251)
			std::vector<std::string> buttons__;
#pragma warning(pop)
		};
	} // namespace UI
} // namespace TitaniumWindows

#endif  // _TITANIUMWINDOWS_UI_ALERTDIALOG_HPP_
