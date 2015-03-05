/**
 * Titanium.UI.TableViewSection for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_TABLEVIEWSECTION_HPP_
#define _TITANIUMWINDOWS_TABLEVIEWSECTION_HPP_

#include "TitaniumWindows/UI/detail/UIBase.hpp"

namespace TitaniumWindows
{
	namespace UI
	{

		using namespace HAL;

		/*!
		  @class

		  @discussion This is the Titanium.UI.TableViewSection implementation for Windows.
		*/
		class TITANIUMWINDOWS_UI_EXPORT TableViewSection final : public Titanium::UI::TableViewSection, public JSExport<TableViewSection>
		{

		public:
			TableViewSection(const JSContext&, const std::vector<JSValue>& arguments = {}) TITANIUM_NOEXCEPT;

			virtual ~TableViewSection()                  = default;
			TableViewSection(const TableViewSection&)            = default;
			TableViewSection& operator=(const TableViewSection&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			TableViewSection(TableViewSection&&)                 = default;
			TableViewSection& operator=(TableViewSection&&)      = default;
#endif

			static void JSExportInitialize();

		private:

			virtual std::string footerTitle() const TITANIUM_NOEXCEPT;
			virtual JSValue footerView() const TITANIUM_NOEXCEPT;
			virtual std::string headerTitle() const TITANIUM_NOEXCEPT;
			virtual JSValue headerView() const TITANIUM_NOEXCEPT;
			virtual JSValue rowCount() const TITANIUM_NOEXCEPT;
			virtual JSValue rows() const TITANIUM_NOEXCEPT;

			virtual JSValue add(JSValue row) TITANIUM_NOEXCEPT;
			virtual JSValue remove(JSValue row) TITANIUM_NOEXCEPT;

		};
	}  // namespace UI
}  // namespace TitaniumWindows
#endif // _TITANIUMWINDOWS_TABLEVIEWSECTION_HPP_