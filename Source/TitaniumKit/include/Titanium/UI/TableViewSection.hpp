/**
 * Titanium.UI.TableViewSection
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_TABLEVIEWSECTION_HPP_
#define _TITANIUM_TABLEVIEWSECTION_HPP_

#include "Titanium/Module.hpp"

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;
		
		class TableViewRow;
		class View;

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
			virtual std::string get_footerTitle() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract footerView
			  @discussion View to use for this section footer.
			*/
			virtual View_shared_ptr_t get_footerView() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract headerTitle
			  @discussion Title of this section header.
			*/
			virtual std::string get_headerTitle() const TITANIUM_NOEXCEPT;
			virtual void set_headerTitle(const std::string& title) TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract headerView
			  @discussion View to use for this section header.
			*/
			virtual View_shared_ptr_t get_headerView() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract rowCount
			  @discussion Number of rows in this section.
			*/
			virtual uint32_t get_rowCount() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract rows
			  @discussion Rows in this section.
			*/
			virtual std::vector<TableViewRow_shared_ptr_t> get_rows() const TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract add
			  @discussion Adds a table view row to this section.
			*/
			virtual void add(TableViewRow_shared_ptr_t row) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract remove
			  @discussion Removes a table view row from this section.
			*/
			virtual void remove(TableViewRow_shared_ptr_t row) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract rowAtIndex
			  @discussion Returns a row in this section.
			*/
			virtual TableViewRow_shared_ptr_t rowAtIndex(uint32_t index) TITANIUM_NOEXCEPT;

			TableViewSection(const JSContext&) TITANIUM_NOEXCEPT;
			virtual ~TableViewSection() = default;
			TableViewSection(const TableViewSection&) = default;
			TableViewSection& operator=(const TableViewSection&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			TableViewSection(TableViewSection&&)                 = default;
			TableViewSection& operator=(TableViewSection&&)      = default;
#endif

			static void JSExportInitialize();

			TITANIUM_PROPERTY_READONLY_DEF(footerTitle);
			TITANIUM_PROPERTY_READONLY_DEF(footerView);
			TITANIUM_PROPERTY_DEF(headerTitle);
			TITANIUM_PROPERTY_READONLY_DEF(headerView);
			TITANIUM_PROPERTY_READONLY_DEF(rowCount);
			TITANIUM_PROPERTY_READONLY_DEF(rows);
			TITANIUM_FUNCTION_DEF(add);
			TITANIUM_FUNCTION_DEF(remove);
			TITANIUM_FUNCTION_DEF(rowAtIndex);
			TITANIUM_FUNCTION_DEF(getFooterTitle);
			TITANIUM_FUNCTION_DEF(setFooterTitle);
			TITANIUM_FUNCTION_DEF(getFooterView);
			TITANIUM_FUNCTION_DEF(setFooterView);
			TITANIUM_FUNCTION_DEF(getHeaderTitle);
			TITANIUM_FUNCTION_DEF(setHeaderTitle);
			TITANIUM_FUNCTION_DEF(getHeaderView);
			TITANIUM_FUNCTION_DEF(setHeaderView);
			TITANIUM_FUNCTION_DEF(getRowCount);
			TITANIUM_FUNCTION_DEF(getRows);

			protected:
#pragma warning(push)
#pragma warning(disable : 4251)
				std::string footerTitle__;
				View_shared_ptr_t footerView__;
				std::string headerTitle__;
				View_shared_ptr_t headerView__;
				std::vector<TableViewRow_shared_ptr_t> rows__;
#pragma warning(pop)
		};
	} // namespace UI
} // namespace Titanium
#endif // _TITANIUM_TABLEVIEWSECTION_HPP_