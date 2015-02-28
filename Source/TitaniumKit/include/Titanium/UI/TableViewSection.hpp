/**
 * Titanium.UI.TableViewSection for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_TABLEVIEWSECTION_HPP_
#define _TITANIUM_TABLEVIEWSECTION_HPP_

#include "Titanium/Module.hpp"
#include "Titanium/UI/View.hpp"
#include "Titanium/UI/TableViewRow.hpp"

namespace Titanium
{
	namespace UI
	{

		using namespace HAL;
		using TableViewRow_shared_ptr_t = std::shared_ptr<TableViewRow>;
		using View_shared_ptr_t = std::shared_ptr<View>;

		/*!
		  @class
		  @discussion This is the Titanium TableViewSection Module.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.UI.TableViewSection
		*/
		class TITANIUMKIT_EXPORT TableViewSection : public Module, public JSExport<TableViewSection>
		{

		public:

			/*!
			  @property
			  @abstract footerTitle
			  @discussion Title of this section footer.
			*/
			virtual std::string footerTitle() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract footerView
			  @discussion View to use for this section footer.
			*/
			virtual JSValue footerView() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract headerTitle
			  @discussion Title of this section header.
			*/
			virtual std::string headerTitle() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract headerView
			  @discussion View to use for this section header.
			*/
			virtual JSValue headerView() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract rowCount
			  @discussion Number of rows in this section.
			*/
			virtual JSValue rowCount() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract rows
			  @discussion Rows in this section.
			*/
			virtual JSValue rows() const TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract add
			  @discussion Adds a table view row to this section.
			*/
			virtual JSValue add(JSValue row) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract remove
			  @discussion Removes a table view row from this section.
			*/
			virtual JSValue remove(JSValue row) TITANIUM_NOEXCEPT;

			TableViewSection(const JSContext&, const std::vector<JSValue>& arguments = {}) TITANIUM_NOEXCEPT;

			virtual ~TableViewSection() = default;
			TableViewSection(const TableViewSection&) = default;
			TableViewSection& operator=(const TableViewSection&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			TableViewSection(TableViewSection&&)                 = default;
			TableViewSection& operator=(TableViewSection&&)      = default;
#endif

			static void JSExportInitialize();

			virtual JSValue js_footerTitle() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_footerView() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_headerTitle() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_headerView() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_rowCount() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_rows() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_add(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_remove(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getFooterTitle(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setFooterTitle(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getFooterView(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setFooterView(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getHeaderTitle(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setHeaderTitle(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getHeaderView(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setHeaderView(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getRowCount(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getRows(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;

			protected:
#pragma warning(push)
#pragma warning(disable : 4251)
				std::string footerTitle__;
				View_shared_ptr_t footerView__;
				std::string headerTitle__;
				View_shared_ptr_t headerView__;
				uint32_t rowCount__;
				TableViewRow_shared_ptr_t rows__;
#pragma warning(pop)
		};

	} // namespace UI
} // namespace Titanium
#endif // _TITANIUM_TABLEVIEWSECTION_HPP_