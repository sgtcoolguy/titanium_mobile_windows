/**
 * Titanium.UI.View for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/UI/ListView.hpp"
#include "TitaniumWindows/UI/TableView.hpp"
#include "TitaniumWindows/UI/TableViewRow.hpp"
#include "TitaniumWindows/UI/View.hpp"
#include <collection.h>

namespace TitaniumWindows
{
	namespace UI
	{
		TableView::TableView(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
			: Titanium::UI::TableView(js_context, arguments)
		{
			TITANIUM_LOG_DEBUG("TableView::ctor Initialize");

			tableview__ = ref new Windows::UI::Xaml::Controls::ListView();

			collectionViewSource__ = ref new Windows::UI::Xaml::Data::CollectionViewSource();
			collectionViewItems__  = ref new ::Platform::Collections::Vector<::Platform::Object^>();
			collectionViewSource__->Source = collectionViewItems__;
			collectionViewSource__->IsSourceGrouped = true;

			auto binding = ref new Windows::UI::Xaml::Data::Binding();
			binding->Source = collectionViewSource__;
			Windows::UI::Xaml::Data::BindingOperations::SetBinding(tableview__, Windows::UI::Xaml::Controls::ListView::ItemsSourceProperty, binding);

			// Use "SelectionChanged" event to handle click event
			tableview__->IsItemClickEnabled = false;

			setDefaultHeight(Titanium::UI::Constants::to_string(Titanium::UI::LAYOUT::FILL));
			setDefaultWidth(Titanium::UI::Constants::to_string(Titanium::UI::LAYOUT::FILL));

			tableViewItems__ = ref new ::Platform::Collections::Vector<ListViewItem^>();

			setComponent(tableview__);
		}

		void TableView::JSExportInitialize() 
		{
			JSExport<TableView>::SetClassVersion(1);
			JSExport<TableView>::SetParent(JSExport<Titanium::UI::TableView>::Class());
		}

		void TableView::setData(std::vector<JSObject>& data, JSValue animation) TITANIUM_NOEXCEPT
		{
			tableViewItems__->Clear();
			for (uint32_t i=0;i<data.size();i++) {
				addTableItem(data[i]);
			}
		}

		void TableView::set_sections(const std::vector<TableViewSection_shared_ptr_t>& sections) TITANIUM_NOEXCEPT
		{
			tableViewItems__->Clear();
			for (uint32_t i=0;i<sectionCount();i++) {
				auto section = this->sections()[i]->get_object();
				addTableItem(section);
			}
			Titanium::UI::TableView::set_sections(sections);
		}

		void TableView::appendRow(const TableViewRow_shared_ptr_t row, JSValue animation) TITANIUM_NOEXCEPT
		{
			addTableItem(row->get_object());
		}
		void TableView::appendSection(const TableViewSection_shared_ptr_t section, JSValue animation) TITANIUM_NOEXCEPT
		{
			addTableItem(section->get_object());
		}
		void TableView::deleteRow(const TableViewRow_shared_ptr_t row, JSValue animation) TITANIUM_NOEXCEPT
		{
			//TODO : Implement this
			unsigned int index = -1;
			//tableViewItems__->IndexOf();
			if (index > -1) {
				tableViewItems__->RemoveAt(index);
			}
		}
		void TableView::deleteSection(uint32_t section, JSValue animation) TITANIUM_NOEXCEPT
		{
			sections__.erase(sections__.begin()+section);
			set_sections(sections__);
		}

		void TableView::addTableItem(JSObject& item) TITANIUM_NOEXCEPT
		{
			JSValue js_item = static_cast<JSValue>(item);

			// Add TableViewRow
			if (js_item.IsObjectOfClass(JSExport<TitaniumWindows::UI::TableViewRow>::Class())) {
				auto view = item.GetPrivate<TitaniumWindows::UI::TableViewRow>();
				auto rowContent = view->getComponent();
				TITANIUM_ASSERT(rowContent);

				auto group = ref new ::Platform::Collections::Vector<Windows::UI::Xaml::UIElement^>();
				group->Append(rowContent);

				// Add as ListViewItem so that we can map item index
				auto item = ref new ListViewItem();
				item->View = rowContent;
				item->ItemIndex = tableViewItems__->Size;
				item->SectionIndex = sectionCount()-1;
				tableViewItems__->Append(item);

				// Add as child view to make layout engine work
				Titanium::LayoutEngine::nodeAddChild(layout_node_, view->layout_node_);
				if (isLoaded()) {
					auto root = Titanium::LayoutEngine::nodeRequestLayout(layout_node_);
					if (root) {
						Titanium::LayoutEngine::nodeLayout(root);
					}
				}
				
				collectionViewItems__->Append(group);
				return;

			// Add TableViewSection
			} else if (js_item.IsObjectOfClass(JSExport<Titanium::UI::TableViewSection>::Class())) {
				auto section = item.GetPrivate<Titanium::UI::TableViewSection>();
				auto rows = section->rows();
				auto group = ref new ::Platform::Collections::Vector<Windows::UI::Xaml::UIElement^>();

				sections__.push_back(section);

				for (uint32_t i=0;i<rows.size();i++) {
					auto row = rows.at(i);
					auto view = row->get_object().GetPrivate<TitaniumWindows::UI::TableViewRow>();
					auto rowContent = view->getComponent();
					TITANIUM_ASSERT(rowContent);

					// Add as list item
					group->Append(rowContent);

					// Add as ListViewItem so that we can map item index
					auto item = ref new ListViewItem();
					item->View = rowContent;
					item->ItemIndex = i;
					item->SectionIndex = sectionCount();
					tableViewItems__->Append(item);

					// Add as child view to make layout engine work
					Titanium::LayoutEngine::nodeAddChild(layout_node_, view->layout_node_);
					if (isLoaded()) {
						auto root = Titanium::LayoutEngine::nodeRequestLayout(layout_node_);
						if (root) {
							Titanium::LayoutEngine::nodeLayout(root);
						}
					}
				}

				sectionCount__++;
				collectionViewItems__->Append(group);
				return;

			// JSObject to create TableViewSection
			} else if (item.HasProperty("headerTitle")) {
				// TODO : Create section
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

		void TableView::enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
		{
			const JSContext ctx = this->get_context();

			if (event_name == "click") {
				click_event__ = tableview__->SelectionChanged += ref new Windows::UI::Xaml::Controls::SelectionChangedEventHandler(
					[this, ctx](::Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e) {
					auto listview = safe_cast<Windows::UI::Xaml::Controls::ListView^>(sender);

					TITANIUM_ASSERT((listview->SelectedIndex < 0) || (static_cast<unsigned int>(listview->SelectedIndex) < tableViewItems__->Size));
					auto listViewItem = tableViewItems__->GetAt(listview->SelectedIndex);

					JSObject  eventArgs = ctx.CreateObject();
					eventArgs.SetProperty("section", sections__[listViewItem->SectionIndex]->get_object());
					eventArgs.SetProperty("index", ctx.CreateNumber(listViewItem->ItemIndex));

					this->fireEvent("click", eventArgs);
				});
			}
		}

		void TableView::disableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
		{
			if (event_name == "click") {
				tableview__->ItemClick -= click_event__;
			}
		}

	}  // namespace UI
}  // namespace TitaniumWindows