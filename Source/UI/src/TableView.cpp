/**
 * Titanium.UI.TableView for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/UI/ListView.hpp"
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
		TableView::TableView(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::UI::TableView(js_context)
		{
			TITANIUM_LOG_DEBUG("TableView::ctor Initialize");
		}

		void TableView::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{
			Titanium::UI::TableView::postCallAsConstructor(js_context, arguments);

			tableview__ = ref new Windows::UI::Xaml::Controls::ListView();

			collectionViewSource__ = ref new Windows::UI::Xaml::Data::CollectionViewSource();
			collectionViewItems__  = ref new ::Platform::Collections::Vector<::Platform::Object^>();
			collectionViewSource__->Source = collectionViewItems__;
			collectionViewSource__->IsSourceGrouped = true;

			auto binding = ref new Windows::UI::Xaml::Data::Binding();
			binding->Source = collectionViewSource__;
			Windows::UI::Xaml::Data::BindingOperations::SetBinding(tableview__, Windows::UI::Xaml::Controls::ListView::ItemsSourceProperty, binding);

			tableview__->IsItemClickEnabled = true;

			tableViewItems__ = ref new ::Platform::Collections::Vector<ListViewItem^>();

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

		void TableView::setData(std::vector<JSObject>& data, const std::shared_ptr<Titanium::UI::TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			Titanium::UI::TableView::setData(data, animation);
			tableViewItems__->Clear();
			for (uint32_t i=0;i<data.size();i++) {
				addTableItem(data[i]);
			}
		}

		void TableView::set_sections(const std::vector<TableViewSection_shared_ptr_t>& sections) TITANIUM_NOEXCEPT
		{
			tableViewItems__->Clear();
			std::vector<TableViewSection_shared_ptr_t> new_sections(sections.begin(), sections.end());
			for (uint32_t i=0;i<new_sections.size();i++) {
				auto section = new_sections[i]->get_object();
				addTableItem(section);
			}
			Titanium::UI::TableView::set_sections(new_sections);
		}

		void TableView::appendRow(const TableViewRow_shared_ptr_t row, const std::shared_ptr<Titanium::UI::TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			addTableItem(row->get_object());
		}

		void TableView::deleteRow(const TableViewRow_shared_ptr_t row, const std::shared_ptr<Titanium::UI::TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			//TODO : Implement this
			unsigned int index = -1;
			//tableViewItems__->IndexOf();
			if (index > -1) {
				tableViewItems__->RemoveAt(index);
			}
		}

		void TableView::addTableItem(JSObject& item) TITANIUM_NOEXCEPT
		{
			// Add TableViewRow
			if (item.GetPrivate<TitaniumWindows::UI::TableViewRow>()) {
				auto view = item.GetPrivate<TitaniumWindows::UI::TableViewRow>();
				auto rowContent = view->getViewLayoutDelegate<WindowsViewLayoutDelegate>()->getComponent();
				TITANIUM_ASSERT(rowContent);

				auto group = ref new ::Platform::Collections::Vector<Windows::UI::Xaml::UIElement^>();
				group->Append(rowContent);

				auto sectionCount = get_sectionCount();

				// Add as ListViewItem so that we can map item index
				auto list_item = ref new ListViewItem();
				list_item->View = rowContent;
				list_item->ItemIndex = tableViewItems__->Size;
				list_item->SectionIndex = sectionCount > 0 ? sectionCount - 1 : 0;
				tableViewItems__->Append(list_item);

				if (sectionCount > 0) {
					auto section = sections__.at(list_item->SectionIndex);
					section->add(view);
				} else {
					// Add new section if we don't have any sections
					auto section_obj = item.get_context().CreateObject(JSExport<Titanium::UI::TableViewSection>::Class());
					auto section = section_obj.GetPrivate<Titanium::UI::TableViewSection>();

					section->add(view);
					sections__.push_back(section);
				}

				// Add as child view to make layout engine work
				auto layoutDelegate = getViewLayoutDelegate<WindowsViewLayoutDelegate>();
				Titanium::LayoutEngine::nodeAddChild(layoutDelegate->getLayoutNode(), view->getViewLayoutDelegate<TitaniumWindows::UI::WindowsViewLayoutDelegate>()->getLayoutNode());
				if (layoutDelegate->isLoaded()) {
					layoutDelegate->requestLayout();
				}
				collectionViewItems__->Append(group);
				return;

			// Add TableViewSection
			} else if (item.GetPrivate<Titanium::UI::TableViewSection>()) {
				auto section = item.GetPrivate<Titanium::UI::TableViewSection>();
				auto rows = section->get_rows();
				auto group = ref new ::Platform::Collections::Vector<Windows::UI::Xaml::UIElement^>();

				// Create ListViewItem header placeholder to keep index mapping valid
				auto header_item = ref new ListViewItem();
				header_item->isHeader = true;
				tableViewItems__->Append(header_item);

				// Set section header
				auto view = section->get_headerView();
				if (view != nullptr) {
					auto windows_view = dynamic_cast<TitaniumWindows::UI::View*>(view.get());
					auto component = windows_view->getComponent();
					group->Append(component);
					header_item->View = component;

					// Add as child view to make layout engine work
					auto layoutDelegate = getViewLayoutDelegate<TitaniumWindows::UI::WindowsViewLayoutDelegate>();
					Titanium::LayoutEngine::nodeAddChild(layoutDelegate->getLayoutNode(), view->getViewLayoutDelegate<TitaniumWindows::UI::WindowsViewLayoutDelegate>()->getLayoutNode());
					if (layoutDelegate->isLoaded()) {
						layoutDelegate->requestLayout();
					}
				} else {
					Windows::UI::Xaml::Controls::ListViewHeaderItem^ header = ref new Windows::UI::Xaml::Controls::ListViewHeaderItem();
					auto headerText = ref new Windows::UI::Xaml::Controls::TextBlock();
					headerText->Text = Utility::ConvertUTF8String(section->get_headerTitle());
					headerText->FontSize = 28; // Change this?
					header->Content = headerText;
					group->Append(header);
				}

				sections__.push_back(section);

				for (uint32_t i=0;i<rows.size();i++) {
					auto row = rows.at(i);
					auto view = row->get_object().GetPrivate<TitaniumWindows::UI::TableViewRow>();
					auto rowContent = view->getViewLayoutDelegate<WindowsViewLayoutDelegate>()->getComponent();
					TITANIUM_ASSERT(rowContent);

					// Add as list item
					group->Append(rowContent);

					// Add as ListViewItem so that we can map item index
					auto item = ref new ListViewItem();
					item->View = rowContent;
					item->ItemIndex = i;
					item->SectionIndex = get_sectionCount()-1;
					tableViewItems__->Append(item);

					// Add as child view to make layout engine work
					auto layoutDelegate = getViewLayoutDelegate<TitaniumWindows::UI::WindowsViewLayoutDelegate>();
					Titanium::LayoutEngine::nodeAddChild(layoutDelegate->getLayoutNode(), view->getViewLayoutDelegate<TitaniumWindows::UI::WindowsViewLayoutDelegate>()->getLayoutNode());
					if (layoutDelegate->isLoaded()) {
						layoutDelegate->requestLayout();
					}
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

		void TableView::enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
		{
			Titanium::UI::TableView::enableEvent(event_name);

			const JSContext ctx = this->get_context();

			if (event_name == "click") {
				click_event__ = tableview__->ItemClick += ref new Windows::UI::Xaml::Controls::ItemClickEventHandler(
					[this, ctx](::Platform::Object^ sender, Windows::UI::Xaml::Controls::ItemClickEventArgs^ e) {

					if (data__.size() == 0) {
						TITANIUM_LOG_DEBUG("TableView is clicked but there's no data");
						return;
					}

					auto listview = safe_cast<Windows::UI::Xaml::Controls::ListView^>(sender);

					uint32_t index = -1;
					listview->Items->IndexOf(e->ClickedItem, &index);
					if (index == -1) return;
					TITANIUM_ASSERT(index > -1 || index < tableViewItems__->Size);
					
					auto listViewItem = tableViewItems__->GetAt(index);
					if (listViewItem->isHeader) return;

					auto sindex = listViewItem->SectionIndex;
					auto row = sections__[listViewItem->SectionIndex]->get_rows().at(listViewItem->ItemIndex);

					// Is data constructed from TableViewSection?
					auto fromSection = data__[0].GetPrivate<Titanium::UI::TableViewSection>() != nullptr;

					JSObject  eventArgs = ctx.CreateObject();
					eventArgs.SetProperty("sectionIndex", ctx.CreateNumber(listViewItem->SectionIndex));
					eventArgs.SetProperty("index", ctx.CreateNumber(listViewItem->ItemIndex));
					eventArgs.SetProperty("row", row->get_object());
					eventArgs.SetProperty("rowData", fromSection ? row->get_object() : data__.at(listViewItem->ItemIndex));

					this->fireEvent("click", eventArgs);
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

	}  // namespace UI
}  // namespace TitaniumWindows