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
		
		class TableView;
		class TableViewRow;
		class View;

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
  			TITANIUM_PROPERTY_IMPL_DEF(std::string, footerTitle);

			/*!
			  @property
			  @abstract footerView
			  @discussion View to use for this section footer.
			*/
  			TITANIUM_PROPERTY_IMPL_DEF(std::shared_ptr<View>, footerView);

			/*!
			  @property
			  @abstract headerTitle
			  @discussion Title of this section header.
			*/
  			TITANIUM_PROPERTY_IMPL_DEF(std::string, headerTitle);

			/*!
			  @property
			  @abstract headerView
			  @discussion View to use for this section header.
			*/
  			TITANIUM_PROPERTY_IMPL_DEF(std::shared_ptr<View>, headerView);

			/*!
			  @property
			  @abstract rowCount
			  @discussion Number of rows in this section.
			*/
  			TITANIUM_PROPERTY_IMPL_READONLY_DEF(std::uint32_t, rowCount);

			/*!
			  @property
			  @abstract rows
			  @discussion Rows in this section.
			*/
  			TITANIUM_PROPERTY_IMPL_READONLY_DEF(std::vector<std::shared_ptr<TableViewRow>>, rows);

			/*!
			  @method
			  @abstract add
			  @discussion Adds a table view row to this section.
			*/
			virtual void add(const std::shared_ptr<TableViewRow>& row) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract remove
			  @discussion Removes a table view row from this section.
			*/
			virtual void remove(const std::shared_ptr<TableViewRow>& row) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract rowAtIndex
			  @discussion Returns a row in this section.
			*/
			virtual std::shared_ptr<TableViewRow> rowAtIndex(const uint32_t& index) TITANIUM_NOEXCEPT;

			TableViewSection(const JSContext&) TITANIUM_NOEXCEPT;
			virtual ~TableViewSection() = default;
			TableViewSection(const TableViewSection&) = default;
			TableViewSection& operator=(const TableViewSection&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			TableViewSection(TableViewSection&&)                 = default;
			TableViewSection& operator=(TableViewSection&&)      = default;
#endif

			static void JSExportInitialize();

			TITANIUM_PROPERTY_DEF(footerTitle);
			TITANIUM_PROPERTY_DEF(footerView);
			TITANIUM_PROPERTY_DEF(headerTitle);
			TITANIUM_PROPERTY_DEF(headerView);
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

			// attach table view to this section so that it receives callback
			virtual void attachTableView(const std::shared_ptr<TableView>& tableView) final
			{
				tableView__ = tableView;
			}

			virtual void fireTableViewSectionEvent(const std::string& event_name, const std::uint32_t& rowIndex);

			protected:
#pragma warning(push)
#pragma warning(disable : 4251)
				std::string footerTitle__;
				std::shared_ptr<View> footerView__;
				std::string headerTitle__;
				std::shared_ptr<View> headerView__;
				std::vector<std::shared_ptr<TableViewRow>> rows__;
				std::shared_ptr<TableView> tableView__;
#pragma warning(pop)
		};
	} // namespace UI
} // namespace Titanium
#endif // _TITANIUM_TABLEVIEWSECTION_HPP_