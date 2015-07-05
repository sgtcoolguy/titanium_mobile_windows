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
		using TableViewSection_shared_ptr_t = std::shared_ptr<Titanium::UI::TableViewSection>;
		using TableViewRow_shared_ptr_t = std::shared_ptr<Titanium::UI::TableViewRow>;

		/*!
		@class ListViewItem

		@discussion This class represents item in ListView which is used for mapping ListView item with index and view
		*/
		ref class ListViewItem {
		public:
			property Windows::UI::Xaml::UIElement^ View
			{
				Windows::UI::Xaml::UIElement^ get() {
					return view__;
				}
				void set(Windows::UI::Xaml::UIElement^ value) {
					view__ = value;
				}
			}
			property uint32_t SectionIndex
			{
				uint32_t get() {
					return sectionIndex__;
				}
				void set(uint32_t value) {
					sectionIndex__ = value;
				}
			}
			property uint32_t ItemIndex
			{
				uint32_t get() {
					return itemIndex__;
				}
				void set(uint32_t value) {
					itemIndex__ = value;
				}
			}
			property bool isHeader
			{
				bool get() {
					return isHeader__;
				}
				void set(bool value) {
					isHeader__ = value;
				}
			}

		private:
			Windows::UI::Xaml::UIElement^ view__;
			uint32_t sectionIndex__;
			uint32_t itemIndex__;
			bool isHeader__;
		};

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

			virtual void set_sections(const std::vector<TableViewSection_shared_ptr_t>& sections) TITANIUM_NOEXCEPT override;
			virtual void setData(std::vector<JSObject>& data, const std::shared_ptr<Titanium::UI::TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT override;

			virtual void appendRow(const TableViewRow_shared_ptr_t row, const std::shared_ptr<Titanium::UI::TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT override;
			virtual void deleteRow(const TableViewRow_shared_ptr_t row, const std::shared_ptr<Titanium::UI::TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT override;

		private:

			void clearTableData(const bool& clearSections = true);
			void resetTableDataBinding();
			void addTableItem(JSObject& item) TITANIUM_NOEXCEPT;

			Windows::UI::Xaml::Controls::ListView^ tableview__;
			Windows::Foundation::Collections::IVector<ListViewItem^>^ tableViewItems__;
			Windows::UI::Xaml::Data::CollectionViewSource^ collectionViewSource__;
			Windows::Foundation::Collections::IObservableVector<::Platform::Object^>^ collectionViewItems__;

			Windows::Foundation::EventRegistrationToken click_event__;
		};
	}  // namespace UI
}  // namespace TitaniumWindows
#endif // _TITANIUMWINDOWS_View_HPP_