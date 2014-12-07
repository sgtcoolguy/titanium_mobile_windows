/** -*- mode: c++ -*-
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#ifndef _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TableView_H_
#define _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TableView_H_

#include "TiCore/TiViewProxy.h"

// This is a Ti.UI.TableView

namespace Ti 
{
	namespace UI 
	{
		class TableView : public Ti::ViewProxy, public virtual_enable_shared_from_this < TableView > 
		{
			TI_CREATE_PROXY(TableView);
			static JSClassRef Parent() { return Ti::ViewProxy::ClassDef(); }
		public:
			virtual std::string defaultWidth() const { return Ti::Constants::SizeFILL; }
			virtual std::string defaultHeight() const { return Ti::Constants::SizeFILL; }

		protected:

			TableView(const std::string& name, const std::vector<Ti::Value>& arguments);
			virtual ~TableView() {
				list_view_ = nullptr;
			}
			virtual Ti::Value eventAdded(const std::vector<Ti::Value>&);
			virtual Ti::Value eventRemoved(const std::vector<Ti::Value>&);

			// Sets the value of the allowsSelection property.
			Ti::Value setAllowsSelection(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setAllowsSelection);
			// Sets the value of the allowsSelectionDuringEditing property.
			Ti::Value setAllowsSelectionDuringEditing(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setAllowsSelectionDuringEditing);
			// Sets the data in the table.
			Ti::Value setData(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setData);
			// Sets the value of the editable property.
			Ti::Value setEditable(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setEditable);
			// Sets the value of the editing property.
			Ti::Value setEditing(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setEditing);
			// Sets the value of the filterAnchored property.
			Ti::Value setFilterAnchored(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setFilterAnchored);
			// Sets the value of the filterAttribute property.
			Ti::Value setFilterAttribute(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setFilterAttribute);
			// Sets the value of the filterCaseInsensitive property.
			Ti::Value setFilterCaseInsensitive(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setFilterCaseInsensitive);
			// When set to false, the ListView will not draw the divider before the footer view.
			Ti::Value setFooterDividersEnabled(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setFooterDividersEnabled);
			// Sets the value of the footerTitle property.
			Ti::Value setFooterTitle(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setFooterTitle);
			// Sets the value of the footerView property.
			Ti::Value setFooterView(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setFooterView);
			// When set to false, the ListView will not draw the divider after the header view.
			Ti::Value setHeaderDividersEnabled(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setHeaderDividersEnabled);
			// Sets the value of the [Ti.UI.TableView.headerPullView] property.
			Ti::Value setHeaderPullView(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setHeaderPullView);
			// Sets the value of the headerTitle property.
			Ti::Value setHeaderTitle(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setHeaderTitle);
			// Sets the value of the headerView property.
			Ti::Value setHeaderView(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setHeaderView);
			// Sets the value of the hideSearchOnSelection property.
			Ti::Value setHideSearchOnSelection(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setHideSearchOnSelection);
			// Sets the value of the index property.
			Ti::Value setIndex(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setIndex);
			// Sets the value of the maxRowHeight property.
			Ti::Value setMaxRowHeight(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setMaxRowHeight);
			// Sets the value of the minRowHeight property.
			Ti::Value setMinRowHeight(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setMinRowHeight);
			// Sets the value of the moveable property.
			Ti::Value setMoveable(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setMoveable);
			// Sets the value of the moving property.
			Ti::Value setMoving(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setMoving);
			// Sets the value of the overScrollMode property.
			Ti::Value setOverScrollMode(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setOverScrollMode);
			// Sets the value of the refreshControl property.
			Ti::Value setRefreshControl(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setRefreshControl);
			// Sets the value of the rowHeight property.
			Ti::Value setRowHeight(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setRowHeight);
			// Sets the value of the scrollIndicatorStyle property.
			Ti::Value setScrollIndicatorStyle(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setScrollIndicatorStyle);
			// Sets the value of the scrollable property.
			Ti::Value setScrollable(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setScrollable);
			// Sets the value of the search property.
			Ti::Value setSearch(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setSearch);
			// Sets the value of the searchAsChild property.
			Ti::Value setSearchAsChild(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setSearchAsChild);
			// Sets the value of the searchHidden property.
			Ti::Value setSearchHidden(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setSearchHidden);
			// Gets the value of the sectionCount property.
			Ti::Value getSectionCount(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, getSectionCount);
			// Sets the value of the sections property.
			Ti::Value setSections(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setSections);
			// Sets the value of the separatorColor property.
			Ti::Value setSeparatorColor(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setSeparatorColor);
			// Sets the value of the separatorInsets property.
			Ti::Value setSeparatorInsets(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setSeparatorInsets);
			// Sets the value of the separatorStyle property.
			Ti::Value setSeparatorStyle(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setSeparatorStyle);
			// Sets the value of the showVerticalScrollIndicator property.
			Ti::Value setShowVerticalScrollIndicator(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setShowVerticalScrollIndicator);
			// Appends a single row or an array of rows to the end of the table.
			Ti::Value appendRow(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, appendRow);
			// Appends a single section or an array of sections to the end of the table.
			Ti::Value appendSection(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, appendSection);
			// Deletes an existing row.
			Ti::Value deleteRow(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, deleteRow);
			// Deletes an existing section.
			Ti::Value deleteSection(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, deleteSection);
			// Programmatically deselects a row.
			Ti::Value deselectRow(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, deselectRow);
			// Gets the value of the editing property.
			Ti::Value getEditing(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, getEditing);
			// Gets the value of the index property.
			Ti::Value getIndex(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, getIndex);
			// Gets the value of the moving property.
			Ti::Value getMoving(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, getMoving);
			// Inserts a row after another row.
			Ti::Value insertRowAfter(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, insertRowAfter);
			// Inserts a row before another row.
			Ti::Value insertRowBefore(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, insertRowBefore);
			// Inserts a section after another section.
			Ti::Value insertSectionAfter(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, insertSectionAfter);
			// Inserts a section before another section.
			Ti::Value insertSectionBefore(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, insertSectionBefore);
			// Scrolls the table view to ensure that the specified row is on screen.
			Ti::Value scrollToIndex(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, scrollToIndex);
			// Scrolls the table to a specific top position where 0 is the topmost y position in the 
			// table view.
			Ti::Value scrollToTop(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, scrollToTop);
			// Programmatically selects a row. In Android, it sets the currently selected item. If in touch mode,
			// the item will not be selected but it will still be positioned appropriately. If the specified 
			// selection position is less than 0, then the item at position 0 will be selected.
			Ti::Value selectRow(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, selectRow);
			// Sets this tableview's content insets.
			Ti::Value setContentInsets(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, setContentInsets);
			// Updates an existing row, optionally with animation.
			Ti::Value updateRow(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, updateRow);
			// Updates an existing section, optionally with animation.
			Ti::Value updateSection(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(TableView, updateSection);

		private:
			Windows::UI::Xaml::Controls::ListView^ list_view_;
			std::vector<Ti::Value> data_;
			void OnSelectionChanged(Platform::Object ^sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs ^e);
		};

	}	
}
#endif	
