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

namespace TitaniumWindows
{
	namespace UI
	{
		using namespace HAL;

		/*!
		  @class

		  @discussion This is the Titanium.UI.View implementation for Windows.
		*/
#pragma warning(push)
#pragma warning(disable : 4275)
		class TITANIUMWINDOWS_UI_EXPORT TableView final : public Titanium::UI::TableView, public JSExport<TableView>
		{
#pragma warning(pop)
		public:
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

			virtual void appendRow(const std::vector<std::shared_ptr<Titanium::UI::TableViewRow>>& row, const std::shared_ptr<Titanium::UI::TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT override;
			virtual void appendSection(const std::vector<std::shared_ptr<Titanium::UI::TableViewSection>>& sections, const std::shared_ptr<Titanium::UI::TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT override;

		private:
			// Search for section index and item index. Returns {sectionIndex, itemIndex}
			std::tuple<std::uint32_t, std::int32_t> searchFromSelectedIndex(const std::uint32_t& selectedIndex);
			void bindCollectionViewSource();
			void unbindCollectionViewSource();

			void registerTableViewRowAsLayoutNode(const std::shared_ptr<Titanium::UI::View>& view);

			// Receive all events fired from TableViewSection.
			// Subclass may override this to catch changes for section.
			virtual void fireTableViewSectionEvent(const std::string& name, const std::shared_ptr<Titanium::UI::TableViewSection>& section, const std::uint32_t& rowIndex) override;

			void clearTableData();
			void resetTableDataBinding();
			void addTableItem(const JSObject& item) TITANIUM_NOEXCEPT;

			Windows::UI::Xaml::Controls::ListView^ tableview__;
			Windows::UI::Xaml::Data::CollectionViewSource^ collectionViewSource__;
			Windows::Foundation::Collections::IObservableVector<::Platform::Object^>^ collectionViewItems__;

			Windows::Foundation::EventRegistrationToken click_event__;
		};
	}  // namespace UI
}  // namespace TitaniumWindows
#endif // _TITANIUMWINDOWS_View_HPP_