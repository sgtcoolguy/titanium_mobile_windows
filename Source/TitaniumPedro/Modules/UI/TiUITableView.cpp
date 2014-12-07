/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#include "Modules/UI/TiUITableView.h"
#include "Modules/UI/TiUITableViewRow.h"
#include "TiCore/TiConstants.h"
#include "TiCore/TiUtils.h"

namespace Ti{
	namespace UI {

		JSStaticFunction const TableView::ClassMethods[] = {
				{ "setAllowsSelection", _setAllowsSelection, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setAllowsSelectionDuringEditing", _setAllowsSelectionDuringEditing, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setData", _setData, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setEditable", _setEditable, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setEditing", _setEditing, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setFilterAnchored", _setFilterAnchored, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setFilterAttribute", _setFilterAttribute, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setFilterCaseInsensitive", _setFilterCaseInsensitive, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setFooterDividersEnabled", _setFooterDividersEnabled, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setFooterTitle", _setFooterTitle, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setFooterView", _setFooterView, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setHeaderDividersEnabled", _setHeaderDividersEnabled, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setHeaderPullView", _setHeaderPullView, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setHeaderTitle", _setHeaderTitle, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setHeaderView", _setHeaderView, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setHideSearchOnSelection", _setHideSearchOnSelection, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setIndex", _setIndex, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setMaxRowHeight", _setMaxRowHeight, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setMinRowHeight", _setMinRowHeight, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setMoveable", _setMoveable, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setMoving", _setMoving, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setOverScrollMode", _setOverScrollMode, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setRefreshControl", _setRefreshControl, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setRowHeight", _setRowHeight, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setScrollIndicatorStyle", _setScrollIndicatorStyle, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setScrollable", _setScrollable, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setSearch", _setSearch, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setSearchAsChild", _setSearchAsChild, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setSearchHidden", _setSearchHidden, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setSections", _setSections, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setSeparatorColor", _setSeparatorColor, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setSeparatorInsets", _setSeparatorInsets, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setSeparatorStyle", _setSeparatorStyle, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setShowVerticalScrollIndicator", _setShowVerticalScrollIndicator, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "appendRow", _appendRow, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "appendSection", _appendSection, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "deleteRow", _deleteRow, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "deleteSection", _deleteSection, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "deselectRow", _deselectRow, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getEditing", _getEditing, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getIndex", _getIndex, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getMoving", _getMoving, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getSectionCount", _getSectionCount, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "insertRowAfter", _insertRowAfter, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "insertRowBefore", _insertRowBefore, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "insertSectionAfter", _insertSectionAfter, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "insertSectionBefore", _insertSectionBefore, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "scrollToIndex", _scrollToIndex, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "scrollToTop", _scrollToTop, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "selectRow", _selectRow, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setContentInsets", _setContentInsets, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "updateRow", _updateRow, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "updateSection", _updateSection, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ 0, 0, 0 }
		};

		TableView::TableView(const std::string& name, const std::vector<Ti::Value>& arguments) : Ti::ViewProxy(name, arguments)
		{
			list_view_ = ref new Windows::UI::Xaml::Controls::ListView();
			setComponent(list_view_);
		}

		Ti::Value TableView::setData(const std::vector<Ti::Value>& args)
		{
			using namespace Windows::UI::Xaml;
			using namespace Windows::UI::Text;
			using namespace Windows::UI::Xaml::Controls;

			if (!args[0].isArray()) {
				return Ti::Value::Undefined();
			}
			data_ = args[0].toVector();
			bool needsLayout = false;
			for (auto item : data_)
			{
				if (!item.isObject()) 
				{
					continue;
				}
				ListViewItem^ listItem = nullptr;
				if (item.isProxy())
				{
					auto proxy = std::dynamic_pointer_cast<TableViewRow>(toProxy(item));
					if (!proxy) 
					{
						continue;
					}
					listItem = ref new ListViewItem();
					listItem->Content = proxy->getComponent();
					Ti::Layout::nodeAddChild(layout_node_, proxy->layout_node_);
					needsLayout = true;
				}

				auto title = item.getProperty("title");
				if (!title.isUndefined())
				{
					auto label = ref new TextBlock();
					label->FontSize = 24;
					label->FontWeight = FontWeights::Light;
					label->Margin = Thickness(10, 10, 0, 0);
					label->HorizontalAlignment = HorizontalAlignment::Left;
					label->TextTrimming = TextTrimming::WordEllipsis;
					label->TextWrapping = TextWrapping::Wrap;
					label->Text = Ti::Utils::GetPlatformString(title.toString());
					if (listItem == nullptr) {
						listItem = ref new ListViewItem();
						listItem->Content = ref new Grid();
					}
					safe_cast<Panel^>(listItem->Content)->Children->Append(label);
				}
				if (listItem != nullptr)
				{
					list_view_->Items->Append(listItem);
				}
			}
			if (needsLayout && isLoaded())
			{
				auto root = Ti::Layout::nodeRequestLayout(layout_node_);
				if (root) 
				{
					Ti::Layout::nodeLayout(root);
				}
			}
			return Ti::Value::Undefined();
		}

		Ti::Value TableView::eventAdded(const std::vector<Ti::Value>& args)
		{
			auto eventName = args[0].toString();
			if (eventName == Ti::Constants::EventClick) {
				auto weak = get_weak_ptr_for_proxy();
				list_view_->SelectionChanged += ref new Windows::UI::Xaml::Controls::SelectionChangedEventHandler([weak](Platform::Object ^sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs ^e){
					auto proxy = weak.lock();
					assert(proxy != nullptr);

					auto index = proxy->list_view_->SelectedIndex;
					Ti::Value eventArgs;
					eventArgs.setProperty("rowData", proxy->data_[index]);
					eventArgs.setProperty("index", Ti::Value(static_cast<double>(index)));
					proxy->fireEvent(Ti::Constants::EventClick, eventArgs);
				});
				return Ti::Value::Undefined();
			}
			return ViewProxy::eventAdded(args);
		}
		Ti::Value TableView::eventRemoved(const std::vector<Ti::Value>& args)
		{
			return ViewProxy::eventRemoved(args);
		}
		// Public API
		// Sets the value of the allowsSelection property.
		Ti::Value TableView::setAllowsSelection(const std::vector<Ti::Value>& args)
		{
			if (args[0].toBool()) {
				list_view_->SelectionMode = Windows::UI::Xaml::Controls::ListViewSelectionMode::Single;
			} else {
				list_view_->SelectionMode = Windows::UI::Xaml::Controls::ListViewSelectionMode::None;
			}
			return Ti::Value::Undefined();
		}
		// Sets the value of the allowsSelectionDuringEditing property.
		Ti::Value TableView::setAllowsSelectionDuringEditing(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.setAllowsSelectionDuringEditing() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Sets the value of the editable property.
		Ti::Value TableView::setEditable(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.setEditable() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Sets the value of the editing property.
		Ti::Value TableView::setEditing(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.setEditing() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Sets the value of the filterAnchored property.
		Ti::Value TableView::setFilterAnchored(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.setFilterAnchored() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Sets the value of the filterAttribute property.
		Ti::Value TableView::setFilterAttribute(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.setFilterAttribute() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Sets the value of the filterCaseInsensitive property.
		Ti::Value TableView::setFilterCaseInsensitive(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.setFilterCaseInsensitive() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// When set to false, the ListView will not draw the divider before the footer view.
		Ti::Value TableView::setFooterDividersEnabled(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.setFooterDividersEnabled() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Sets the value of the footerTitle property.
		Ti::Value TableView::setFooterTitle(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.setFooterTitle() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Sets the value of the footerView property.
		Ti::Value TableView::setFooterView(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.setFooterView() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// When set to false, the ListView will not draw the divider after the header view.
		Ti::Value TableView::setHeaderDividersEnabled(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.setHeaderDividersEnabled() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Sets the value of the [Ti.UI.TableView.headerPullView] property.
		Ti::Value TableView::setHeaderPullView(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.setHeaderPullView() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Sets the value of the headerTitle property.
		Ti::Value TableView::setHeaderTitle(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.setHeaderTitle() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Sets the value of the headerView property.
		Ti::Value TableView::setHeaderView(const std::vector<Ti::Value>& args)
		{
			auto proxy = std::dynamic_pointer_cast<ViewProxy>(toProxy(args[0]));
			list_view_->Header = proxy->getComponent();
			Ti::Layout::nodeAddChild(layout_node_, proxy->layout_node_);
			if (isLoaded()) {
				auto root = Ti::Layout::nodeRequestLayout(layout_node_);
				if (root) {
					Ti::Layout::nodeLayout(root);
				}
			}

			return Ti::Value::Undefined();
		}
		// Sets the value of the hideSearchOnSelection property.
		Ti::Value TableView::setHideSearchOnSelection(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.setHideSearchOnSelection() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Sets the value of the index property.
		Ti::Value TableView::setIndex(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.setIndex() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Sets the value of the maxRowHeight property.
		Ti::Value TableView::setMaxRowHeight(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.setMaxRowHeight() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Sets the value of the minRowHeight property.
		Ti::Value TableView::setMinRowHeight(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.setMinRowHeight() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Sets the value of the moveable property.
		Ti::Value TableView::setMoveable(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.setMoveable() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Sets the value of the moving property.
		Ti::Value TableView::setMoving(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.setMoving() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Sets the value of the overScrollMode property.
		Ti::Value TableView::setOverScrollMode(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.setOverScrollMode() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Sets the value of the refreshControl property.
		Ti::Value TableView::setRefreshControl(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.setRefreshControl() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Sets the value of the rowHeight property.
		Ti::Value TableView::setRowHeight(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.setRowHeight() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Sets the value of the scrollIndicatorStyle property.
		Ti::Value TableView::setScrollIndicatorStyle(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.setScrollIndicatorStyle() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Sets the value of the scrollable property.
		Ti::Value TableView::setScrollable(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.setScrollable() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Sets the value of the search property.
		Ti::Value TableView::setSearch(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.setSearch() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Sets the value of the searchAsChild property.
		Ti::Value TableView::setSearchAsChild(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.setSearchAsChild() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Sets the value of the searchHidden property.
		Ti::Value TableView::setSearchHidden(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.setSearchHidden() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Gets the value of the sectionCount property.
		Ti::Value TableView::getSectionCount(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.getSectionCount() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Sets the value of the sections property.
		Ti::Value TableView::setSections(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.setSections() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Sets the value of the separatorColor property.
		Ti::Value TableView::setSeparatorColor(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.setSeparatorColor() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Sets the value of the separatorInsets property.
		Ti::Value TableView::setSeparatorInsets(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.setSeparatorInsets() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Sets the value of the separatorStyle property.
		Ti::Value TableView::setSeparatorStyle(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.setSeparatorStyle() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Sets the value of the showVerticalScrollIndicator property.
		Ti::Value TableView::setShowVerticalScrollIndicator(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.setShowVerticalScrollIndicator() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Appends a single row or an array of rows to the end of the table.
		Ti::Value TableView::appendRow(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.appendRow() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Appends a single section or an array of sections to the end of the table.
		Ti::Value TableView::appendSection(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.appendSection() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Deletes an existing row.
		Ti::Value TableView::deleteRow(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.deleteRow() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Deletes an existing section.
		Ti::Value TableView::deleteSection(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.deleteSection() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Programmatically deselects a row.
		Ti::Value TableView::deselectRow(const std::vector<Ti::Value>& args)
		{
			if (args[0].isNumber()) {
			}
			return Ti::Value::Undefined();
		}
		// Gets the value of the editing property.
		Ti::Value TableView::getEditing(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.getEditing() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Gets the value of the index property.
		Ti::Value TableView::getIndex(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.getIndex() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Gets the value of the moving property.
		Ti::Value TableView::getMoving(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.getMoving() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Inserts a row after another row.
		Ti::Value TableView::insertRowAfter(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.insertRowAfter() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Inserts a row before another row.
		Ti::Value TableView::insertRowBefore(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.insertRowBefore() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Inserts a section after another section.
		Ti::Value TableView::insertSectionAfter(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.insertSectionAfter() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Inserts a section before another section.
		Ti::Value TableView::insertSectionBefore(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.insertSectionBefore() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Scrolls the table view to ensure that the specified row is on screen.
		Ti::Value TableView::scrollToIndex(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.scrollToIndex() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Scrolls the table to a specific top position where 0 is the topmost y position in the 
		// table view.
		Ti::Value TableView::scrollToTop(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.scrollToTop() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Programmatically selects a row. In Android, it sets the currently selected item. If in touch mode,
		// the item will not be selected but it will still be positioned appropriately. If the specified 
		// selection position is less than 0, then the item at position 0 will be selected.
		Ti::Value TableView::selectRow(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.selectRow() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Sets this tableview's content insets.
		Ti::Value TableView::setContentInsets(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.setContentInsets() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Updates an existing row, optionally with animation.
		Ti::Value TableView::updateRow(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.updateRow() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Updates an existing section, optionally with animation.
		Ti::Value TableView::updateSection(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] TableView.updateSection() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}

	}
}

