/**
 * Titanium.UI.TableView for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_View_HPP_
#define _TITANIUMWINDOWS_View_HPP_

#include "TitaniumWindows_UI_EXPORT.h"
#include "Titanium/UI/TableView.hpp"
#include <collection.h>

namespace TitaniumWindows
{
	namespace UI
	{
		using namespace HAL;

		/*!
		  @class TableView
		  @ingroup Titanium.UI.TableView

		  @discussion This is the Titanium.UI.TableView implementation for Windows.
		*/
#pragma warning(push)
#pragma warning(disable : 4275)
		class TITANIUMWINDOWS_UI_EXPORT TableView final : public Titanium::UI::TableView, public JSExport<TableView>
		{
#pragma warning(pop)
		public:

			TITANIUM_PROPERTY_UNIMPLEMENTED(filterAttribute);
			TITANIUM_PROPERTY_UNIMPLEMENTED(filterAnchored);
			TITANIUM_PROPERTY_UNIMPLEMENTED(filterCaseInsensitive);
			TITANIUM_PROPERTY_UNIMPLEMENTED(footerTitle);
			TITANIUM_PROPERTY_UNIMPLEMENTED(footerView);
			TITANIUM_PROPERTY_UNIMPLEMENTED(maxRowHeight);
			TITANIUM_PROPERTY_UNIMPLEMENTED(minRowHeight);
			TITANIUM_PROPERTY_UNIMPLEMENTED(rowHeight);
			TITANIUM_PROPERTY_UNIMPLEMENTED(search);
			TITANIUM_PROPERTY_UNIMPLEMENTED(separatorColor);

			TITANIUM_FUNCTION_UNIMPLEMENTED(deleteRow);
			TITANIUM_FUNCTION_UNIMPLEMENTED(deleteSection);
			TITANIUM_FUNCTION_UNIMPLEMENTED(insertRowAfter);
			TITANIUM_FUNCTION_UNIMPLEMENTED(insertSectionAfter);
			TITANIUM_FUNCTION_UNIMPLEMENTED(insertRowBefore);
			TITANIUM_FUNCTION_UNIMPLEMENTED(insertSectionBefore);
			TITANIUM_FUNCTION_UNIMPLEMENTED(scrollToIndex);
			TITANIUM_FUNCTION_UNIMPLEMENTED(scrollToTop);
			TITANIUM_FUNCTION_UNIMPLEMENTED(selectRow);
			TITANIUM_FUNCTION_UNIMPLEMENTED(updateRow);

			TableView(const JSContext&) TITANIUM_NOEXCEPT;
			virtual ~TableView()                  = default;
			TableView(const TableView&)            = default;
			TableView& operator=(const TableView&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			TableView(TableView&&)                 = default;
			TableView& operator=(TableView&&)      = default;
#endif
			static void JSExportInitialize();

			virtual void postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) override;

			virtual void enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT override final;
			virtual void disableEvent(const std::string& event_name) TITANIUM_NOEXCEPT override final;

			virtual void set_sections(const std::vector<std::shared_ptr<Titanium::UI::TableViewSection>>& sections) TITANIUM_NOEXCEPT override;
			virtual void set_data(const std::vector<JSObject>& data) TITANIUM_NOEXCEPT override;

			virtual void appendRowAtSection(const std::uint32_t& sectionIndex, const std::vector<std::shared_ptr<Titanium::UI::TableViewRow>>& row) TITANIUM_NOEXCEPT override;
			virtual void appendSection(const std::vector<std::shared_ptr<Titanium::UI::TableViewSection>>& sections, const std::shared_ptr<Titanium::UI::TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT override;

		private:
			// Search for section index and item index. Returns {sectionIndex, itemIndex}
			std::tuple<std::uint32_t, std::int32_t> searchFromSelectedIndex(const std::uint32_t& selectedIndex);
			void bindCollectionViewSource();
			void unbindCollectionViewSource();

			::Platform::Collections::Vector<Windows::UI::Xaml::UIElement^>^ createUIElementsForSection(const std::uint32_t& sectionIndex) TITANIUM_NOEXCEPT;
			Windows::UI::Xaml::Controls::ListViewHeaderItem^ createDefaultSectionHeader(const std::shared_ptr<Titanium::UI::TableViewSection>& seciton);
			void registerTableViewRowAsLayoutNode(const std::shared_ptr<Titanium::UI::View>& view);

			// Receive all events fired from TableViewSection.
			// Subclass may override this to catch changes for section.
			virtual void fireTableViewSectionEvent(const std::string& name, const std::shared_ptr<Titanium::UI::TableViewSection>& section, const std::uint32_t& rowIndex) override;

			void clearTableData();
			void resetTableDataBinding();

			Windows::UI::Xaml::Controls::ListView^ tableview__;
			Windows::UI::Xaml::Data::CollectionViewSource^ collectionViewSource__;
			Windows::Foundation::Collections::IObservableVector<::Platform::Object^>^ collectionViewItems__;

			Windows::Foundation::EventRegistrationToken click_event__;
		};
	}  // namespace UI
}  // namespace TitaniumWindows
#endif // _TITANIUMWINDOWS_View_HPP_