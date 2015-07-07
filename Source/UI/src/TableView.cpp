/**
 * Titanium.UI.TableView for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/UI/TableView.hpp"
#include "TitaniumWindows/UI/TableViewRow.hpp"
#include "Titanium/UI/TableViewSection.hpp"
#include "TitaniumWindows/UI/View.hpp"
#include "TitaniumWindows/UI/WindowsViewLayoutDelegate.hpp"
#include "TitaniumWindows/Utility.hpp"
#include "Titanium/detail/TiImpl.hpp"

#include <collection.h>

namespace TitaniumWindows
{
	namespace UI
	{

		using namespace Platform::Collections;
		using namespace Windows::UI::Xaml;


		TableView::TableView(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::UI::TableView(js_context)
		{
			TITANIUM_LOG_DEBUG("TableView::ctor Initialize");
		}

		void TableView::resetTableDataBinding()
		{
			collectionViewSource__ = ref new Data::CollectionViewSource();
			collectionViewSource__->Source = collectionViewItems__;
			collectionViewSource__->IsSourceGrouped = true;

			auto binding = ref new Data::Binding();
			binding->Source = collectionViewSource__;
			Data::BindingOperations::SetBinding(tableview__, Controls::ListView::ItemsSourceProperty, binding);
		}

		void TableView::clearTableData() 
		{
			collectionViewItems__->Clear();
			resetTableDataBinding();
		}

		void TableView::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{
			Titanium::UI::TableView::postCallAsConstructor(js_context, arguments);

			tableview__ = ref new Controls::ListView();
			collectionViewItems__ = ref new Vector<Platform::Object^>();

			resetTableDataBinding();

			tableview__->IsItemClickEnabled = true;

			Titanium::UI::TableView::setLayoutDelegate<WindowsViewLayoutDelegate>();
			layoutDelegate__->set_defaultWidth(Titanium::UI::LAYOUT::FILL);
			layoutDelegate__->set_defaultHeight(Titanium::UI::LAYOUT::FILL);

			getViewLayoutDelegate<WindowsViewLayoutDelegate>()->setComponent(tableview__);
		}

		void TableView::JSExportInitialize() 
		{
			JSExport<TableView>::SetClassVersion(1);
			JSExport<TableView>::SetParent(JSExport<Titanium::UI::TableView>::Class());
		}

		void TableView::set_data(const std::vector<JSObject>& data) TITANIUM_NOEXCEPT
		{
			Titanium::UI::TableView::set_data(data);
			clearTableData();
			for (uint32_t i = 0; i<data.size(); i++) {
				addTableItem(data[i]);
			}
		}

		void TableView::set_sections(const std::vector<std::shared_ptr<Titanium::UI::TableViewSection>>& sections) TITANIUM_NOEXCEPT
		{
			Titanium::UI::TableView::set_sections(sections);
			clearTableData();
			for (uint32_t i=0;i<sections__.size();i++) {
				addTableItem(sections__.at(i)->get_object());
			}
		}

		void TableView::appendRow(const std::vector<std::shared_ptr<Titanium::UI::TableViewRow>>& rows, const std::shared_ptr<Titanium::UI::TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			Titanium::UI::TableView::appendRow(rows, animation);
			unbindCollectionViewSource();
			for (const auto row : rows) {
				addTableItem(row->get_object());
			}
			bindCollectionViewSource();
		}

		void TableView::appendSection(const std::vector<std::shared_ptr<Titanium::UI::TableViewSection>>& sections, const std::shared_ptr<Titanium::UI::TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			Titanium::UI::TableView::appendSection(sections, animation);
			unbindCollectionViewSource();
			for (uint32_t i = 0; i<sections.size(); i++) {
				addTableItem(sections.at(i)->get_object());
			}
			bindCollectionViewSource();
		}

		void TableView::addTableItem(const JSObject& item) TITANIUM_NOEXCEPT
		{
			// Add TableViewRow
			if (item.GetPrivate<TitaniumWindows::UI::TableViewRow>()) {
				auto view = item.GetPrivate<TitaniumWindows::UI::TableViewRow>();
				auto rowContent = view->getViewLayoutDelegate<WindowsViewLayoutDelegate>()->getComponent();
				TITANIUM_ASSERT(rowContent);

				auto group = ref new Vector<UIElement^>();
				group->Append(rowContent);

				auto sectionCount = get_sectionCount();

				if (sectionCount > 0) {
					// append at the end of the table
					sections__.at(sectionCount - 1)->add(view);
				} else {
					// Add new section if we don't have any sections
					auto section_obj = item.get_context().CreateObject(JSExport<Titanium::UI::TableViewSection>::Class());
					auto section = section_obj.GetPrivate<Titanium::UI::TableViewSection>();

					// attach table view to this section so it receives callback
					section->attachTableView(get_object().GetPrivate<Titanium::UI::TableView>());

					section->add(view);
					sections__.push_back(section);
				}

				// Add as child view to make layout engine work
				registerTableViewRowAsLayoutNode(view);
				collectionViewItems__->Append(group);
				return;

			// Add TableViewSection
			} else if (item.GetPrivate<Titanium::UI::TableViewSection>()) {
				auto section = item.GetPrivate<Titanium::UI::TableViewSection>();
				auto rows = section->get_rows();
				auto group = ref new Vector<UIElement^>();

				// attach table view to this section so it receives callback
				section->attachTableView(get_object().GetPrivate<Titanium::UI::TableView>());

				// Set section header
				auto view = section->get_headerView();
				if (view != nullptr) {
					auto windows_view = dynamic_cast<TitaniumWindows::UI::View*>(view.get());
					auto component = windows_view->getComponent();
					group->Append(component);

					// Add as child view to make layout engine work
					registerTableViewRowAsLayoutNode(view);
				}
				else {
					Controls::ListViewHeaderItem^ header = ref new Controls::ListViewHeaderItem();
					auto headerText = ref new Controls::TextBlock();
					headerText->Text = Utility::ConvertUTF8String(section->get_headerTitle());
					headerText->FontSize = 28; // Change this?
					header->Content = headerText;
					group->Append(header);
				}

				for (uint32_t i=0;i<rows.size();i++) {
					auto row = rows.at(i);
					auto view = row->get_object().GetPrivate<TitaniumWindows::UI::TableViewRow>();
					auto rowContent = view->getViewLayoutDelegate<WindowsViewLayoutDelegate>()->getComponent();
					TITANIUM_ASSERT(rowContent);

					// Add as list item
					group->Append(rowContent);

					// Add as child view to make layout engine work
					registerTableViewRowAsLayoutNode(view);
				}
				collectionViewItems__->Append(group);
				return;

			// JSObject array
			} else if (item.IsArray()) {
				std::vector<JSValue> items = static_cast<std::vector<JSValue>>(static_cast<JSArray>(item));;
				for (uint32_t i=0;i<items.size();i++) {
					addTableItem(static_cast<JSObject>(items[i]));
				}
				return;

			// JSObject to create TableViewSection
			} else if (item.HasProperty("headerTitle")) {
				// TODO : Create section
				return;
			}

			// JSObject to create TableViewRow
			if (item.HasProperty("title")) {

				JSValue Titanium_property = get_context().get_global_object().GetProperty("Titanium");
				TITANIUM_ASSERT(Titanium_property.IsObject());
				JSObject Titanium = static_cast<JSObject>(Titanium_property);

				JSValue UI_property = Titanium.GetProperty("UI");
				TITANIUM_ASSERT(UI_property.IsObject());
				JSObject UI = static_cast<JSObject>(UI_property);

				JSValue TableViewRow_property = UI.GetProperty("TableViewRow");
				TITANIUM_ASSERT(TableViewRow_property.IsObject());
				JSObject TableViewRow = static_cast<JSObject>(TableViewRow_property);

				auto row = TableViewRow.CallAsConstructor();
				applyProperties(item, row);
				addTableItem(row);
			}
		}

		// Add as child view to make layout engine work
		void TableView::registerTableViewRowAsLayoutNode(const std::shared_ptr<Titanium::UI::View>& view)
		{
			auto layoutDelegate = getViewLayoutDelegate<TitaniumWindows::UI::WindowsViewLayoutDelegate>();
			Titanium::LayoutEngine::nodeAddChild(layoutDelegate->getLayoutNode(), view->getViewLayoutDelegate<TitaniumWindows::UI::WindowsViewLayoutDelegate>()->getLayoutNode());
			if (layoutDelegate->isLoaded()) {
				layoutDelegate->requestLayout();
			}
		}

		/*
		* Search for section index and item index
		* TODO: Is there a better way to do this?
		*/
		std::tuple<std::uint32_t, std::int32_t> TableView::searchFromSelectedIndex(const std::uint32_t& selectedIndex) {
			std::int32_t  itemIndex = -1; // -1 means it's a header
			std::uint32_t sectionIndex   = 0;
			std::uint32_t totalItemCount = 0;

			TITANIUM_ASSERT(data__.size() > 0);

			// Is data constructed from TableViewSection?
			const auto fromSection = data__.at(0).GetPrivate<Titanium::UI::TableViewSection>() != nullptr;

			for (sectionIndex = 0; sectionIndex < sections__.size(); sectionIndex++) {
				const auto section = sections__.at(sectionIndex);
				const auto rowCountIncludingHeader = section->get_rowCount() + (fromSection ? 1 : 0);
				totalItemCount += rowCountIncludingHeader;
				if (totalItemCount < selectedIndex) {
					// we just count the total item
					continue;
				} else if (fromSection && selectedIndex == 0) {
					// that's a first header
					break;
				} else if (totalItemCount == selectedIndex) {
					// this indicates header is selected
					itemIndex = -1;
					sectionIndex++;
					break;
				} else {
					// this indicates selected index is in this section
					itemIndex = selectedIndex - (totalItemCount - rowCountIncludingHeader) - (fromSection ? 1 : 0);
					break;
				}
			}
			return std::make_tuple(sectionIndex, itemIndex);
		}

		void TableView::enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
		{
			Titanium::UI::TableView::enableEvent(event_name);

			const JSContext ctx = this->get_context();

			if (event_name == "click") {
				click_event__ = tableview__->ItemClick += ref new Controls::ItemClickEventHandler(
					[this, ctx](Platform::Object^ sender, Controls::ItemClickEventArgs^ e) {

					if (data__.size() == 0) {
						TITANIUM_LOG_DEBUG("TableView is clicked but there's no data");
						return;
					}

					const auto listview = safe_cast<Controls::ListView^>(sender);

					uint32_t selectedIndex = -1;
					listview->Items->IndexOf(e->ClickedItem, &selectedIndex);
					if (selectedIndex == -1) return;

					const auto result = searchFromSelectedIndex(selectedIndex);

					const auto sectionIndex = std::get<0>(result);
					const auto itemIndex    = std::get<1>(result);

					TITANIUM_ASSERT(sections__.size() > sectionIndex);

					// Is data constructed from TableViewSection?
					const auto fromSection = data__.at(0).GetPrivate<Titanium::UI::TableViewSection>() != nullptr;

					JSObject  eventArgs = ctx.CreateObject();
					eventArgs.SetProperty("sectionIndex", ctx.CreateNumber(sectionIndex));
					eventArgs.SetProperty("index", ctx.CreateNumber(itemIndex));

					// add row info if it's not a header
					if (itemIndex >= 0) {
						const auto row = sections__.at(sectionIndex)->get_rows().at(itemIndex);
						eventArgs.SetProperty("row", row->get_object());
						eventArgs.SetProperty("rowData", fromSection ? row->get_object() : data__.at(itemIndex));
					}

					fireEvent("click", eventArgs);
				});
			}
		}

		void TableView::disableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
		{
			Titanium::UI::TableView::disableEvent(event_name);

			if (event_name == "click") {
				tableview__->ItemClick -= click_event__;
			}
		}

		void TableView::bindCollectionViewSource()
		{
			collectionViewSource__->Source = collectionViewItems__;
		}

		void TableView::unbindCollectionViewSource()
		{
			collectionViewSource__->Source = ref new Vector<Platform::Object^>();
		}

		void TableView::fireTableViewSectionEvent(const std::string& name, const std::shared_ptr<Titanium::UI::TableViewSection>& section, const std::uint32_t& rowIndex) 
		{
			const std::uint32_t sectionIndex = std::distance(sections__.begin(), std::find(sections__.begin(), sections__.end(), section));

			if (name == "append") {
				unbindCollectionViewSource();
				const auto views = static_cast<Vector<UIElement^>^>(collectionViewItems__->GetAt(sectionIndex));
				const auto row   = section->get_rows().at(rowIndex);
				const auto rowContent = row->getViewLayoutDelegate<WindowsViewLayoutDelegate>()->getComponent();
				TITANIUM_ASSERT(rowContent);
				views->Append(rowContent);
				registerTableViewRowAsLayoutNode(row);
				bindCollectionViewSource();
			} else if (name == "remove") {
				unbindCollectionViewSource();
				const auto views = static_cast<Vector<UIElement^>^>(collectionViewItems__->GetAt(sectionIndex));
				views->RemoveAt(rowIndex);
				bindCollectionViewSource();
			}

			Titanium::UI::TableView::fireTableViewSectionEvent(name, section, rowIndex);
		}

	}  // namespace UI
}  // namespace TitaniumWindows