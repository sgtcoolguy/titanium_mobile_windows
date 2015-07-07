/**
 * Titanium.UI.TableView
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/TableView.hpp"
#include "Titanium/UI/TableViewRow.hpp"
#include "Titanium/UI/TableViewSection.hpp"
#include "Titanium/UI/TableViewAnimationProperties.hpp"
#include "Titanium/detail/TiImpl.hpp"

namespace Titanium
{
	namespace UI
	{
		TableView::TableView(const JSContext& js_context) TITANIUM_NOEXCEPT
			: View(js_context),
			search__(get_context().CreateUndefined()),
			tableviewAnimationProperties_ctor__(js_context.CreateObject(JSExport<Titanium::UI::TableViewAnimationProperties>::Class())),
			filterAttribute__(""),
			filterAnchored__(false),
			filterCaseInsensitive__(true),
			footerTitle__(""),
			headerTitle__(""),
			maxRowHeight__(0),
			minRowHeight__(0),
			rowHeight__(0),
			separatorColor__("")
		{
			TITANIUM_LOG_INFO("TableView ctor");
		}

		TITANIUM_PROPERTY_READ(TableView, std::vector<std::shared_ptr<TableViewSection>>, sections)

		void TableView::set_sections(const std::vector<std::shared_ptr<TableViewSection>>& sections) TITANIUM_NOEXCEPT
		{
			sections__ = sections;
			data__.clear();
		}

		TITANIUM_PROPERTY_READ(TableView, std::vector<JSObject>, data)

		void TableView::set_data(const std::vector<JSObject>& data) TITANIUM_NOEXCEPT
		{
			data__ = data;
			sections__.clear();
			for (std::uint32_t i = 0; i < data.size(); i++) {
				const auto section = data.at(i).GetPrivate<TableViewSection>();
				if (section != nullptr) {
					sections__.push_back(section);
				}
			}
		}

		void TableView::setData(const std::vector<JSObject>& data, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			set_data(data);
		}

		TITANIUM_PROPERTY_READWRITE(TableView, std::string, filterAttribute)
		TITANIUM_PROPERTY_READWRITE(TableView, bool, filterAnchored)
		TITANIUM_PROPERTY_READWRITE(TableView, bool, filterCaseInsensitive)
		TITANIUM_PROPERTY_READWRITE(TableView, std::string, footerTitle)
		TITANIUM_PROPERTY_READWRITE(TableView, std::shared_ptr<View>, footerView)
		TITANIUM_PROPERTY_READWRITE(TableView, std::string, headerTitle)
		TITANIUM_PROPERTY_READWRITE(TableView, std::shared_ptr<View>, headerView)
		TITANIUM_PROPERTY_READWRITE(TableView, double, maxRowHeight)
		TITANIUM_PROPERTY_READWRITE(TableView, double, minRowHeight)
		TITANIUM_PROPERTY_READWRITE(TableView, double, rowHeight)
		TITANIUM_PROPERTY_READWRITE(TableView, JSValue, search)
		TITANIUM_PROPERTY_READWRITE(TableView, std::string, separatorColor)

		std::uint32_t TableView::get_sectionCount() const TITANIUM_NOEXCEPT
		{
			return static_cast<std::uint32_t>(sections__.size());
		}

		void TableView::appendRow(const std::vector<std::shared_ptr<TableViewRow>>& rows, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			// create new section if there's no section
			if (sections__.size() == 0) {
				const auto js_section = get_context().CreateObject(JSExport<Titanium::UI::TableViewSection>::Class());
				appendSection({ js_section.GetPrivate<Titanium::UI::TableViewSection>() }, nullptr);
			}

			std::shared_ptr<Titanium::UI::TableViewSection> section = sections__.at(sections__.size() - 1);
			for (const auto row : rows) {
				section->add(row);
			}
		}

		void TableView::appendSection(const std::vector<std::shared_ptr<TableViewSection>>& sections, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			for (const auto section : sections) {
				sections__.push_back(section);
			}
		}

		void TableView::deleteRow(const std::uint32_t& rowIndex, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView::deleteRow: Unimplemented");
		}

		void TableView::deleteSection(const uint32_t& sectionIndex, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			sections__.erase(sections__.begin()+sectionIndex);
		}

		void TableView::insertRowAfter(const uint32_t& index, const std::vector<std::shared_ptr<TableViewRow>>& row, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView::insertRowAfter: Unimplemented");
		}

		void TableView::insertSectionAfter(const uint32_t& index, const std::vector<std::shared_ptr<TableViewSection>>& sections, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			sections__.insert(sections__.begin() + index + 1, sections.begin(), sections.end());
		}

		void TableView::insertRowBefore(const uint32_t& index, const std::vector<std::shared_ptr<TableViewRow>>& row, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView::insertRowBefore: Unimplemented");
		}

		void TableView::insertSectionBefore(const uint32_t& index, const std::vector<std::shared_ptr<TableViewSection>>& sections, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			sections__.insert(sections__.begin() + index, sections.begin(), sections.end());
		}

		void TableView::scrollToIndex(const uint32_t& index, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView::scrollToIndex: Unimplemented");
		}

		void TableView::scrollToTop(const uint32_t& top, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView::scrollToTop: Unimplemented");
		}

		void TableView::selectRow(const uint32_t& row) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView::selectRow: Unimplemented");
		}

		void TableView::updateRow(const uint32_t& index, const std::shared_ptr<TableViewRow>& row, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView::updateRow: Unimplemented");
		}

		void TableView::updateSection(const uint32_t& index, const std::shared_ptr<TableViewSection>& section, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			sections__.emplace(sections__.begin() + index, section);
		}

		void TableView::fireTableViewSectionEvent(const std::string& name, const std::shared_ptr<TableViewSection>& section, const std::uint32_t& rowIndex) 
		{
			const auto ctx = get_context();
			auto event_args = ctx.CreateObject();
			event_args.SetProperty("section", get_object());
			event_args.SetProperty("index", ctx.CreateNumber(rowIndex));

			fireEvent(name, event_args);
		}

		void TableView::JSExportInitialize() 
		{
			JSExport<TableView>::SetClassVersion(1);
			JSExport<TableView>::SetParent(JSExport<View>::Class());

			TITANIUM_ADD_PROPERTY(TableView, data);
			TITANIUM_ADD_FUNCTION(TableView, getData);
			TITANIUM_ADD_FUNCTION(TableView, setData);

			TITANIUM_ADD_PROPERTY(TableView, filterAttribute);
			TITANIUM_ADD_PROPERTY(TableView, filterAnchored);
			TITANIUM_ADD_PROPERTY(TableView, filterCaseInsensitive);
			TITANIUM_ADD_PROPERTY(TableView, footerTitle);
			TITANIUM_ADD_PROPERTY(TableView, footerView);
			TITANIUM_ADD_PROPERTY(TableView, headerTitle);
			TITANIUM_ADD_PROPERTY(TableView, headerView);
			TITANIUM_ADD_PROPERTY(TableView, maxRowHeight);
			TITANIUM_ADD_PROPERTY(TableView, minRowHeight);
			TITANIUM_ADD_PROPERTY(TableView, rowHeight);
			TITANIUM_ADD_PROPERTY(TableView, search);
			TITANIUM_ADD_PROPERTY_READONLY(TableView, sectionCount);
			TITANIUM_ADD_PROPERTY(TableView, sections);
			TITANIUM_ADD_PROPERTY(TableView, separatorColor);

			TITANIUM_ADD_FUNCTION(TableView, appendRow);
			TITANIUM_ADD_FUNCTION(TableView, appendSection);
			TITANIUM_ADD_FUNCTION(TableView, deleteRow);
			TITANIUM_ADD_FUNCTION(TableView, deleteSection);
			TITANIUM_ADD_FUNCTION(TableView, insertRowAfter);
			TITANIUM_ADD_FUNCTION(TableView, insertSectionAfter);
			TITANIUM_ADD_FUNCTION(TableView, insertRowBefore);
			TITANIUM_ADD_FUNCTION(TableView, insertSectionBefore);
			TITANIUM_ADD_FUNCTION(TableView, scrollToIndex);
			TITANIUM_ADD_FUNCTION(TableView, scrollToTop);
			TITANIUM_ADD_FUNCTION(TableView, selectRow);
			TITANIUM_ADD_FUNCTION(TableView, updateRow);
			TITANIUM_ADD_FUNCTION(TableView, updateSection);
			TITANIUM_ADD_FUNCTION(TableView, getFilterAttribute);
			TITANIUM_ADD_FUNCTION(TableView, setFilterAttribute);
			TITANIUM_ADD_FUNCTION(TableView, getFilterAnchored);
			TITANIUM_ADD_FUNCTION(TableView, setFilterAnchored);
			TITANIUM_ADD_FUNCTION(TableView, getFilterCaseInsensitive);
			TITANIUM_ADD_FUNCTION(TableView, setFilterCaseInsensitive);
			TITANIUM_ADD_FUNCTION(TableView, getFooterTitle);
			TITANIUM_ADD_FUNCTION(TableView, setFooterTitle);
			TITANIUM_ADD_FUNCTION(TableView, getFooterView);
			TITANIUM_ADD_FUNCTION(TableView, setFooterView);
			TITANIUM_ADD_FUNCTION(TableView, getHeaderTitle);
			TITANIUM_ADD_FUNCTION(TableView, setHeaderTitle);
			TITANIUM_ADD_FUNCTION(TableView, getHeaderView);
			TITANIUM_ADD_FUNCTION(TableView, setHeaderView);
			TITANIUM_ADD_FUNCTION(TableView, getMaxRowHeight);
			TITANIUM_ADD_FUNCTION(TableView, setMaxRowHeight);
			TITANIUM_ADD_FUNCTION(TableView, getMinRowHeight);
			TITANIUM_ADD_FUNCTION(TableView, setMinRowHeight);
			TITANIUM_ADD_FUNCTION(TableView, getRowHeight);
			TITANIUM_ADD_FUNCTION(TableView, setRowHeight);
			TITANIUM_ADD_FUNCTION(TableView, getSearch);
			TITANIUM_ADD_FUNCTION(TableView, setSearch);
			TITANIUM_ADD_FUNCTION(TableView, getSectionCount);
			TITANIUM_ADD_FUNCTION(TableView, getSections);
			TITANIUM_ADD_FUNCTION(TableView, setSections);
			TITANIUM_ADD_FUNCTION(TableView, getSeparatorColor);
			TITANIUM_ADD_FUNCTION(TableView, setSeparatorColor);
		}

		TITANIUM_PROPERTY_GETTER(TableView, data)
		{
			std::vector<JSValue> data_array;
			const auto rows = get_data();
			for (auto row : rows) {
				data_array.push_back(row);
			}
			return get_context().CreateArray(data_array);
		}

		TITANIUM_PROPERTY_SETTER(TableView, data)
		{
			TITANIUM_ASSERT(argument.IsObject());

			auto data_obj = static_cast<JSObject>(argument);
			TITANIUM_ASSERT(data_obj.IsArray());
			auto data = static_cast<std::vector<JSValue>>(static_cast<JSArray>(data_obj));

			std::vector<JSObject> tableObjects;
			for (uint32_t i=0;i<data.size();i++) {
				auto tableObject = static_cast<JSObject>(data[i]);
				tableObjects.push_back(tableObject);
			}
			set_data(tableObjects);

			return false;
		}

		TITANIUM_PROPERTY_GETTER_STRING(TableView, filterAttribute)
		TITANIUM_PROPERTY_SETTER_STRING(TableView, filterAttribute)
		TITANIUM_PROPERTY_GETTER_BOOL(TableView, filterAnchored)
		TITANIUM_PROPERTY_SETTER_BOOL(TableView, filterAnchored)
		TITANIUM_PROPERTY_GETTER_BOOL(TableView, filterCaseInsensitive)
		TITANIUM_PROPERTY_SETTER_BOOL(TableView, filterCaseInsensitive)
		TITANIUM_PROPERTY_GETTER_STRING(TableView, footerTitle)
		TITANIUM_PROPERTY_SETTER_STRING(TableView, footerTitle)
		TITANIUM_PROPERTY_GETTER_OBJECT(TableView, footerView)
		TITANIUM_PROPERTY_SETTER_OBJECT(TableView, footerView, View)
		TITANIUM_PROPERTY_GETTER_STRING(TableView, headerTitle)
		TITANIUM_PROPERTY_SETTER_STRING(TableView, headerTitle)
		TITANIUM_PROPERTY_GETTER_OBJECT(TableView, headerView)
		TITANIUM_PROPERTY_SETTER_OBJECT(TableView, headerView, View)
		TITANIUM_PROPERTY_GETTER_DOUBLE(TableView, maxRowHeight)
		TITANIUM_PROPERTY_SETTER_DOUBLE(TableView, maxRowHeight)
		TITANIUM_PROPERTY_GETTER_DOUBLE(TableView, minRowHeight)
		TITANIUM_PROPERTY_SETTER_DOUBLE(TableView, minRowHeight)
		TITANIUM_PROPERTY_GETTER_DOUBLE(TableView, rowHeight)
		TITANIUM_PROPERTY_SETTER_DOUBLE(TableView, rowHeight)

		TITANIUM_PROPERTY_GETTER(TableView, search)
		{
			return get_search();
		}
		TITANIUM_PROPERTY_SETTER(TableView, search)
		{
			set_search(argument);
			return true;
		}

		TITANIUM_PROPERTY_GETTER_OBJECT_ARRAY(TableView, sections)
		TITANIUM_PROPERTY_SETTER_OBJECT_ARRAY(TableView, sections, TableViewSection)
		TITANIUM_PROPERTY_GETTER_UINT(TableView, sectionCount)
		TITANIUM_PROPERTY_GETTER_STRING(TableView, separatorColor)
		TITANIUM_PROPERTY_SETTER_STRING(TableView, separatorColor)

		TITANIUM_FUNCTION(TableView, appendRow)
		{
			const auto js_context = this_object.get_context();

			if (arguments.size() >= 1) {
				JSObject animation = js_context.CreateObject();
				std::vector<std::shared_ptr<TableViewRow>> rows;

				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsObject());
				const auto js_rows = static_cast<JSObject>(_0);

				if (js_rows.IsArray()) {
					rows = static_cast<JSArray>(js_rows).GetPrivateItems<TableViewRow>();
				} else {
					rows.push_back(js_rows.GetPrivate<TableViewRow>());
				}

				if (arguments.size() >= 2) {
					const auto _1 = arguments.at(1);
					if (_1.IsObject()) {
						animation = tableviewAnimationProperties_ctor__.CallAsConstructor({_1});
					}
				}

				appendRow(rows, animation.GetPrivate<TableViewAnimationProperties>());
			}
			return this_object.get_context().CreateUndefined();	
		}

		TITANIUM_FUNCTION(TableView, appendSection)
		{
			const auto js_context = this_object.get_context();

			if (arguments.size() >= 1) {
				JSObject animation = js_context.CreateObject();
				std::vector<std::shared_ptr<TableViewSection>> sections;

				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsObject());
				const auto js_sections = static_cast<JSObject>(_0);

				if (js_sections.IsArray()) {
					sections = static_cast<JSArray>(js_sections).GetPrivateItems<TableViewSection>();
				} else {
					sections.push_back(js_sections.GetPrivate<TableViewSection>());
				}

				if (arguments.size() >= 2) {
					const auto _1 = arguments.at(1);
					if (_1.IsObject()) {
						animation = tableviewAnimationProperties_ctor__.CallAsConstructor({_1});
					}
				}

				appendSection(sections, animation.GetPrivate<TableViewAnimationProperties>());
			}
			return this_object.get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableView, deleteRow)
		{
			TITANIUM_LOG_WARN("TableView.deleteRow is not implemented yet");
			if (arguments.size() < 2) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 2) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsObject());
				const auto _1 = arguments.at(1);
				//TITANIUM_ASSERT(_1.IsTableViewAnimationProperties());
				const auto row = static_cast<JSObject>(_0);
				const auto animation = static_cast<JSObject>(_1);
				// deleteRow(row, animation);
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsObject());
				const auto row = static_cast<JSObject>(_0);
				// deleteRow(row);
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableView, deleteSection)
		{
			if (arguments.size() < 2) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 2) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto _1 = arguments.at(1);
				TITANIUM_ASSERT(_1.IsObject());
				const uint32_t section = static_cast<uint32_t>(_0);
				const auto animation = static_cast<JSObject>(_1);
				deleteSection(section, animation.GetPrivate<TableViewAnimationProperties>());
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const uint32_t section = static_cast<uint32_t>(_0);
				const auto animation = get_context().CreateObject();
				deleteSection(section, animation.GetPrivate<TableViewAnimationProperties>());
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableView, insertRowAfter)
		{
			TITANIUM_LOG_WARN("TableView.insertRowAfter is not implemented yet");
			if (arguments.size() < 3) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 3) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto _1 = arguments.at(1);
				TITANIUM_ASSERT(_1.IsObject());
				const auto _2 = arguments.at(2);
				//TITANIUM_ASSERT(_2.IsTableViewAnimationProperties());
				const double index = static_cast<double>(_0);
				const auto row = static_cast<JSObject>(_1);
				const auto animation = static_cast<JSObject>(_2);
				// insertRowAfter(index, row, animation);
			} else if (arguments.size() >= 2) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto _1 = arguments.at(1);
				TITANIUM_ASSERT(_1.IsObject());
				const double index = static_cast<double>(_0);
				const auto row = static_cast<JSObject>(_1);
				// insertRowAfter(index, row);
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const double index = static_cast<double>(_0);
				// insertRowAfter(index);
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableView, insertSectionAfter)
		{
			TITANIUM_LOG_WARN("TableView.insertSectionAfter is not implemented yet");
			if (arguments.size() < 3) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 3) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto _1 = arguments.at(1);
				TITANIUM_ASSERT(_1.IsObject());
				const auto _2 = arguments.at(2);
				//TITANIUM_ASSERT(_2.IsTableViewAnimationProperties());
				const double index = static_cast<double>(_0);
				const auto section = static_cast<JSObject>(_1);
				const auto animation = static_cast<JSObject>(_2);
				// insertSectionAfter(index, section, animation);
			} else if (arguments.size() >= 2) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto _1 = arguments.at(1);
				TITANIUM_ASSERT(_1.IsObject());
				const double index = static_cast<double>(_0);
				const auto section = static_cast<JSObject>(_1);
				// insertSectionAfter(index, section);
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const double index = static_cast<double>(_0);
				// insertSectionAfter(index);
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableView, insertRowBefore)
		{
			TITANIUM_LOG_WARN("TableView.insertRowBefore is not implemented yet");
			if (arguments.size() < 3) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 3) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto _1 = arguments.at(1);
				TITANIUM_ASSERT(_1.IsObject());
				const auto _2 = arguments.at(2);
				//TITANIUM_ASSERT(_2.IsTableViewAnimationProperties());
				const double index = static_cast<double>(_0);
				const auto row = static_cast<JSObject>(_1);
				const auto animation = static_cast<JSObject>(_2);
				// insertRowBefore(index, row, animation);
			} else if (arguments.size() >= 2) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto _1 = arguments.at(1);
				TITANIUM_ASSERT(_1.IsObject());
				const double index = static_cast<double>(_0);
				const auto row = static_cast<JSObject>(_1);
				// insertRowBefore(index, row);
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const double index = static_cast<double>(_0);
				// insertRowBefore(index);
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableView, insertSectionBefore)
		{
			TITANIUM_LOG_WARN("TableView.insertSectionBefore is not implemented yet");
			if (arguments.size() < 3) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 3) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto _1 = arguments.at(1);
				TITANIUM_ASSERT(_1.IsObject());
				const auto _2 = arguments.at(2);
				//TITANIUM_ASSERT(_2.IsTableViewAnimationProperties());
				const double index = static_cast<double>(_0);
				const auto section = static_cast<JSObject>(_1);
				const auto animation = static_cast<JSObject>(_2);
				// insertSectionBefore(index, section, animation);
			} else if (arguments.size() >= 2) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto _1 = arguments.at(1);
				TITANIUM_ASSERT(_1.IsObject());
				const double index = static_cast<double>(_0);
				const auto section = static_cast<JSObject>(_1);
				// insertSectionBefore(index, section);
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const double index = static_cast<double>(_0);
				// insertSectionBefore(index);
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableView, scrollToIndex)
		{
			TITANIUM_LOG_WARN("TableView.scrollToIndex is not implemented yet");
			if (arguments.size() < 2) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 2) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto _1 = arguments.at(1);
				//TITANIUM_ASSERT(_1.IsTableViewAnimationProperties());
				const double index = static_cast<double>(_0);
				const auto animation = static_cast<JSObject>(_1);
				// scrollToIndex(index, animation);
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const double index = static_cast<double>(_0);
				// scrollToIndex(index);
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableView, scrollToTop)
		{
			TITANIUM_LOG_WARN("TableView.scrollToTop is not implemented yet");
			if (arguments.size() < 2) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 2) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto _1 = arguments.at(1);
				//TITANIUM_ASSERT(_1.IsTableViewAnimationProperties());
				const double top = static_cast<double>(_0);
				const auto animation = static_cast<JSObject>(_1);
				// scrollToTop(top, animation);
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const double top = static_cast<double>(_0);
				// scrollToTop(top);
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableView, selectRow)
		{
			TITANIUM_LOG_WARN("TableView.selectRow is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const double row = static_cast<double>(_0);
				// selectRow(row);
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableView, updateRow)
		{
			TITANIUM_LOG_WARN("TableView.updateRow is not implemented yet");
			if (arguments.size() < 3) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 3) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto _1 = arguments.at(1);
				//TITANIUM_ASSERT(_1.IsTitanium.UI.TableViewRow());
				const auto _2 = arguments.at(2);
				//TITANIUM_ASSERT(_2.IsTableViewAnimationProperties());
				const double index = static_cast<double>(_0);
				const auto row = static_cast<JSObject>(_1);
				const auto animation = static_cast<JSObject>(_2);
				// updateRow(index, row, animation);
			} else if (arguments.size() >= 2) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto _1 = arguments.at(1);
				//TITANIUM_ASSERT(_1.IsTitanium.UI.TableViewRow());
				const double index = static_cast<double>(_0);
				const auto row = static_cast<JSObject>(_1);
				// updateRow(index, row);
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const double index = static_cast<double>(_0);
				// updateRow(index);
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableView, updateSection)
		{
			TITANIUM_LOG_WARN("TableView.updateSection is not implemented yet");
			if (arguments.size() < 3) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 3) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto _1 = arguments.at(1);
				//TITANIUM_ASSERT(_1.IsTitanium.UI.TableViewSection());
				const auto _2 = arguments.at(2);
				//TITANIUM_ASSERT(_2.IsTableViewAnimationProperties());
				const double index = static_cast<double>(_0);
				const auto section = static_cast<JSObject>(_1);
				const auto animation = static_cast<JSObject>(_2);
				// updateSection(index, section, animation);
			} else if (arguments.size() >= 2) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto _1 = arguments.at(1);
				//TITANIUM_ASSERT(_1.IsTitanium.UI.TableViewSection());
				const double index = static_cast<double>(_0);
				const auto section = static_cast<JSObject>(_1);
				// updateSection(index, section);
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const double index = static_cast<double>(_0);
				// updateSection(index);
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION_AS_GETTER(TableView, getData, data)
		TITANIUM_FUNCTION_AS_SETTER(TableView, setData, data)
		TITANIUM_FUNCTION_AS_GETTER(TableView, getFilterAttribute, filterAttribute)
		TITANIUM_FUNCTION_AS_SETTER(TableView, setFilterAttribute, filterAttribute)
		TITANIUM_FUNCTION_AS_GETTER(TableView, getFilterAnchored, filterAnchored)
		TITANIUM_FUNCTION_AS_SETTER(TableView, setFilterAnchored, filterAnchored)
		TITANIUM_FUNCTION_AS_GETTER(TableView, getFilterCaseInsensitive, filterCaseInsensitive)
		TITANIUM_FUNCTION_AS_SETTER(TableView, setFilterCaseInsensitive, filterCaseInsensitive)
		TITANIUM_FUNCTION_AS_GETTER(TableView, getFooterTitle, footerTitle)
		TITANIUM_FUNCTION_AS_SETTER(TableView, setFooterTitle, footerTitle)
		TITANIUM_FUNCTION_AS_GETTER(TableView, getFooterView, footerView)
		TITANIUM_FUNCTION_AS_SETTER(TableView, setFooterView, footerView)
		TITANIUM_FUNCTION_AS_GETTER(TableView, getHeaderTitle, headerTitle)
		TITANIUM_FUNCTION_AS_SETTER(TableView, setHeaderTitle, headerTitle)
		TITANIUM_FUNCTION_AS_GETTER(TableView, getHeaderView, headerView)
		TITANIUM_FUNCTION_AS_SETTER(TableView, setHeaderView, headerView)
		TITANIUM_FUNCTION_AS_GETTER(TableView, getMaxRowHeight, maxRowHeight)
		TITANIUM_FUNCTION_AS_SETTER(TableView, setMaxRowHeight, maxRowHeight)
		TITANIUM_FUNCTION_AS_GETTER(TableView, getMinRowHeight, minRowHeight)
		TITANIUM_FUNCTION_AS_SETTER(TableView, setMinRowHeight, minRowHeight)
		TITANIUM_FUNCTION_AS_GETTER(TableView, getRowHeight, rowHeight)
		TITANIUM_FUNCTION_AS_SETTER(TableView, setRowHeight, rowHeight)
		TITANIUM_FUNCTION_AS_GETTER(TableView, getSearch, search)
		TITANIUM_FUNCTION_AS_SETTER(TableView, setSearch, search)
		TITANIUM_FUNCTION_AS_GETTER(TableView, getSectionCount, sectionCount)
		TITANIUM_FUNCTION_AS_GETTER(TableView, getSections, search)
		TITANIUM_FUNCTION_AS_SETTER(TableView, setSections, search)
		TITANIUM_FUNCTION_AS_GETTER(TableView, getSeparatorColor, separatorColor)
		TITANIUM_FUNCTION_AS_SETTER(TableView, setSeparatorColor, separatorColor)

	} // namespace UI
} // namespace Titanium