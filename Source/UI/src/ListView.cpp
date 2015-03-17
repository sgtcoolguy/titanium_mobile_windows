/**
 * Titanium.UI.ListView for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/UI/ListView.hpp"
#include "TitaniumWindows/UI/View.hpp"
#include <collection.h>
#include "TitaniumWindows/UI/WindowsViewLayoutPolicy.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		ListView::ListView(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::UI::ListView(js_context)
		{
		}

		void ListView::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{
			Titanium::UI::ListView::postCallAsConstructor(js_context, arguments);	
			
			listview__ = ref new Windows::UI::Xaml::Controls::ListView();

			collectionViewSource__ = ref new Windows::UI::Xaml::Data::CollectionViewSource();
			collectionViewItems__  = ref new ::Platform::Collections::Vector<::Platform::Object^>();
			collectionViewSource__->Source = collectionViewItems__;
			collectionViewSource__->IsSourceGrouped = true;

			auto binding = ref new Windows::UI::Xaml::Data::Binding();
			binding->Source = collectionViewSource__;
			Windows::UI::Xaml::Data::BindingOperations::SetBinding(listview__, Windows::UI::Xaml::Controls::ListView::ItemsSourceProperty, binding);

			// Use "SelectionChanged" event to handle click event
			listview__->IsItemClickEnabled = false;

			listViewItems__ = ref new ::Platform::Collections::Vector<ListViewItem^>();

			Titanium::UI::ListView::setLayoutPolicy<WindowsViewLayoutPolicy>();
			layoutPolicy__->set_defaultWidth(Titanium::UI::LAYOUT::FILL);
			layoutPolicy__->set_defaultHeight(Titanium::UI::LAYOUT::FILL);

			getViewLayoutPolicy<WindowsViewLayoutPolicy>()->setComponent(listview__);
		}

		void ListView::JSExportInitialize() 
		{
			JSExport<ListView>::SetClassVersion(1);
			JSExport<ListView>::SetParent(JSExport<Titanium::UI::ListView>::Class());
		}

		void ListView::enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
		{
			const JSContext ctx = this->get_context();

			if (event_name == "itemclick") {
				click_event__ = listview__->SelectionChanged += ref new Windows::UI::Xaml::Controls::SelectionChangedEventHandler(
					[this, ctx](::Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e) {
					auto listview = safe_cast<Windows::UI::Xaml::Controls::ListView^>(sender);

					TITANIUM_ASSERT((listview->SelectedIndex < 0) || (static_cast<unsigned int>(listview->SelectedIndex) < listViewItems__->Size));
					auto listViewItem = listViewItems__->GetAt(listview->SelectedIndex);

					JSObject  eventArgs = ctx.CreateObject();
					eventArgs.SetProperty("sectionIndex", ctx.CreateNumber(listViewItem->SectionIndex));
					eventArgs.SetProperty("itemIndex", ctx.CreateNumber(listViewItem->ItemIndex));

				  // TODO more properties
					this->fireEvent("itemclick", eventArgs);
				});
			}
		}

		void ListView::disableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
		{
			if (event_name == "itemclick") {
				listview__->ItemClick -= click_event__;
			}
		}

		void ListView::set_sections(const std::vector<ListSection_shared_ptr_t>& sections) TITANIUM_NOEXCEPT
		{
			Titanium::UI::ListView::set_sections(sections);

			listViewItems__->Clear();
			collectionViewItems__->Clear();

			for (uint32_t sectionIndex = 0; sectionIndex < get_sectionCount(); sectionIndex++) {
				auto views = createSectionViewAt<TitaniumWindows::UI::View>(sectionIndex);
				auto group = ref new ::Platform::Collections::Vector<Windows::UI::Xaml::UIElement^>();
				for (uint32_t itemIndex = 0; itemIndex < views.size(); itemIndex++) {
					auto view = views.at(itemIndex);
					auto nativeChildView = view->getComponent();
					TITANIUM_ASSERT(nativeChildView);

					// Add as list item
					group->Append(nativeChildView);

					// Add as ListViewItem so that we can map item index
					auto item = ref new ListViewItem();
					item->View = nativeChildView;
					item->ItemIndex = itemIndex;
					item->SectionIndex = sectionIndex;
					listViewItems__->Append(item);

					// Add as child view to make layout engine work
					auto layoutPolicy = getViewLayoutPolicy<TitaniumWindows::UI::WindowsViewLayoutPolicy>();
					Titanium::LayoutEngine::nodeAddChild(layoutPolicy->getLayoutNode(), view->getViewLayoutPolicy<TitaniumWindows::UI::WindowsViewLayoutPolicy>()->getLayoutNode());
					if (layoutPolicy->isLoaded()) {
						auto root = Titanium::LayoutEngine::nodeRequestLayout(layoutPolicy->getLayoutNode());
						if (root) {
							Titanium::LayoutEngine::nodeLayout(root);
						}
					}
				}

				collectionViewItems__->Append(group);
			}
		}

	}  // namespace UI
}  // namespace TitaniumWindows