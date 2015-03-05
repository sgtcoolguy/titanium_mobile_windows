/**
 * Titanium.UI.View for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_View_HPP_
#define _TITANIUMWINDOWS_View_HPP_

#include "TitaniumWindows/UI/detail/UIBase.hpp"
#include "ViewBase.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		using namespace HAL;
		using TableViewSection_shared_ptr_t = std::shared_ptr<Titanium::UI::TableViewSection>;
		using TableViewRow_shared_ptr_t = std::shared_ptr<Titanium::UI::TableViewRow>;

		/*!
		  @class

		  @discussion This is the Titanium.UI.View implementation for Windows.
		*/
#pragma warning(push)
#pragma warning(disable : 4275)
		class TITANIUMWINDOWS_UI_EXPORT TableView final : public Titanium::UI::TableView, public JSExport<TableView>, public ViewBase
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

			virtual void enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT override final;
			virtual void disableEvent(const std::string& event_name) TITANIUM_NOEXCEPT override final;

			virtual void set_sections(const std::vector<TableViewSection_shared_ptr_t>& sections) TITANIUM_NOEXCEPT override;
			virtual void setData(std::vector<JSObject>& data, JSValue animation) TITANIUM_NOEXCEPT override;

			virtual void appendRow(const TableViewRow_shared_ptr_t row, JSValue animation) TITANIUM_NOEXCEPT override;
			virtual void appendSection(const TableViewSection_shared_ptr_t section, JSValue animation) TITANIUM_NOEXCEPT override;
			virtual void deleteRow(const TableViewRow_shared_ptr_t row, JSValue animation) TITANIUM_NOEXCEPT override;
			virtual void deleteSection(uint32_t section, JSValue animation) TITANIUM_NOEXCEPT override;

		private:

			void addTableItem(JSObject& item) TITANIUM_NOEXCEPT;

			Windows::UI::Xaml::Controls::ListView^ tableview__;
			Windows::Foundation::Collections::IVector<ListViewItem^>^ tableViewItems__;
			Windows::UI::Xaml::Data::CollectionViewSource^ collectionViewSource__;
			Windows::Foundation::Collections::IObservableVector<Platform::Object^>^ collectionViewItems__;

			Windows::Foundation::EventRegistrationToken click_event__;
		};
	}  // namespace UI
}  // namespace TitaniumWindows
#endif // _TITANIUMWINDOWS_View_HPP_