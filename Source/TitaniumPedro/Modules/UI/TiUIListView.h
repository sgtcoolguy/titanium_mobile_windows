/** -*- mode: c++ -*-
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUILISTVIEW_H_
#define _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUILISTVIEW_H_

#include "TiCore/TiViewProxy.h"

namespace Ti
{
	namespace UI
	{
		class ListView : public Ti::ViewProxy, public virtual_enable_shared_from_this < ListView >
		{
			TI_CREATE_PROXY(ListView);
			static JSClassRef Parent() { return Ti::ViewProxy::ClassDef(); }
		public:
			std::string defaultHeight() const override;
			std::string defaultWidth() const override;
			virtual Ti::Value eventAdded(const std::vector<Ti::Value>& args) override;
			virtual Ti::Value eventRemoved(const std::vector<Ti::Value>& args) override;

		protected:
			ListView(const std::string& name, const std::vector<Ti::Value>& arguments);
			virtual ~ListView() {
				listview_ = nullptr;
			}
			// Sets the value of the sections property.
			TI_CREATE_METHOD(ListView, setSections);
			Ti::Value ListView::setSections(const std::vector<Ti::Value>& arguments) {
				if (arguments.size() < 1) {
					std::clog << "[WARN] argument not found for ListView.setSections()" << std::endl;
					return Ti::Value::Undefined();
				}
				sections_ = arguments.at(0);
				collectionViewItems_->Clear();
				appendSection(arguments);

				return Ti::Value::Undefined();
			}

			// Gets the value of the sections property.
			TI_CREATE_METHOD(ListView, getSections);
			Ti::Value ListView::getSections(const std::vector<Ti::Value>& arguments) {
				return sections_;
			}
			// Sets the value of the allowsSelection property.
			TI_CREATE_METHOD(ListView, setAllowsSelection);
			Ti::Value ListView::setAllowsSelection(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.setAllowsSelection() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Gets the value of the allowsSelection property.
			TI_CREATE_METHOD(ListView, getAllowsSelection);
			Ti::Value ListView::getAllowsSelection(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.getAllowsSelection() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Sets the value of the canScroll property.
			TI_CREATE_METHOD(ListView, setCanScroll);
			Ti::Value ListView::setCanScroll(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.setCanScroll() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Gets the value of the canScroll property.
			TI_CREATE_METHOD(ListView, getCanScroll);
			Ti::Value ListView::getCanScroll(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.getCanScroll() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Sets the value of the caseInsensitiveSearch property.
			TI_CREATE_METHOD(ListView, setCaseInsensitiveSearch);
			Ti::Value ListView::setCaseInsensitiveSearch(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.setCaseInsensitiveSearch() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Gets the value of the caseInsensitiveSearch property.
			TI_CREATE_METHOD(ListView, getCaseInsensitiveSearch);
			Ti::Value ListView::getCaseInsensitiveSearch(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.getCaseInsensitiveSearch() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Sets the value of the editing property.
			TI_CREATE_METHOD(ListView, setEditing);
			Ti::Value ListView::setEditing(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.setEditing() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Gets the value of the editing property.
			TI_CREATE_METHOD(ListView, getEditing);
			Ti::Value ListView::getEditing(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.getEditing() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// When set to false, the ListView will not draw the divider before the footer view.
			TI_CREATE_METHOD(ListView, setFooterDividersEnabled);
			Ti::Value ListView::setFooterDividersEnabled(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.setFooterDividersEnabled() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Gets the value of the footerDividersEnabled property.
			TI_CREATE_METHOD(ListView, getFooterDividersEnabled);
			Ti::Value ListView::getFooterDividersEnabled(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.getFooterDividersEnabled() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Sets the value of the footerTitle property.
			TI_CREATE_METHOD(ListView, setFooterTitle);
			Ti::Value ListView::setFooterTitle(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.setFooterTitle() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Gets the value of the footerTitle property.
			TI_CREATE_METHOD(ListView, getFooterTitle);
			Ti::Value ListView::getFooterTitle(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.getFooterTitle() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Sets the value of the footerView property.
			TI_CREATE_METHOD(ListView, setFooterView);
			Ti::Value ListView::setFooterView(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.setFooterView() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Gets the value of the footerView property.
			TI_CREATE_METHOD(ListView, getFooterView);
			Ti::Value ListView::getFooterView(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.getFooterView() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// When set to false, the ListView will not draw the divider after the header view.
			TI_CREATE_METHOD(ListView, setHeaderDividersEnabled);
			Ti::Value ListView::setHeaderDividersEnabled(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.setHeaderDividersEnabled() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Gets the value of the headerDividersEnabled property.
			TI_CREATE_METHOD(ListView, getHeaderDividersEnabled);
			Ti::Value ListView::getHeaderDividersEnabled(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.getHeaderDividersEnabled() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Sets the value of the headerTitle property.
			TI_CREATE_METHOD(ListView, setHeaderTitle);
			Ti::Value ListView::setHeaderTitle(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.setHeaderTitle() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Gets the value of the headerTitle property.
			TI_CREATE_METHOD(ListView, getHeaderTitle);
			Ti::Value ListView::getHeaderTitle(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.getHeaderTitle() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Sets the value of the headerView property.
			TI_CREATE_METHOD(ListView, setHeaderView);
			Ti::Value ListView::setHeaderView(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.setHeaderView() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Gets the value of the headerView property.
			TI_CREATE_METHOD(ListView, getHeaderView);
			Ti::Value ListView::getHeaderView(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.getHeaderView() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Sets the value of the keepSectionsInSearch property.
			TI_CREATE_METHOD(ListView, setKeepSectionsInSearch);
			Ti::Value ListView::setKeepSectionsInSearch(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.setKeepSectionsInSearch() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Gets the value of the keepSectionsInSearch property.
			TI_CREATE_METHOD(ListView, getKeepSectionsInSearch);
			Ti::Value ListView::getKeepSectionsInSearch(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.getKeepSectionsInSearch() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Sets the value of the pruneSectionsOnEdit property.
			TI_CREATE_METHOD(ListView, setPruneSectionsOnEdit);
			Ti::Value ListView::setPruneSectionsOnEdit(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.setPruneSectionsOnEdit() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Gets the value of the pruneSectionsOnEdit property.
			TI_CREATE_METHOD(ListView, getPruneSectionsOnEdit);
			Ti::Value ListView::getPruneSectionsOnEdit(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.getPruneSectionsOnEdit() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Sets the value of the pullView property.
			TI_CREATE_METHOD(ListView, setPullView);
			Ti::Value ListView::setPullView(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.setPullView() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Gets the value of the pullView property.
			TI_CREATE_METHOD(ListView, getPullView);
			Ti::Value ListView::getPullView(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.getPullView() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Sets the value of the refreshControl property.
			TI_CREATE_METHOD(ListView, setRefreshControl);
			Ti::Value ListView::setRefreshControl(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.setRefreshControl() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Gets the value of the refreshControl property.
			TI_CREATE_METHOD(ListView, getRefreshControl);
			Ti::Value ListView::getRefreshControl(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.getRefreshControl() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Sets the value of the scrollIndicatorStyle property.
			TI_CREATE_METHOD(ListView, setScrollIndicatorStyle);
			Ti::Value ListView::setScrollIndicatorStyle(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.setScrollIndicatorStyle() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Gets the value of the scrollIndicatorStyle property.
			TI_CREATE_METHOD(ListView, getScrollIndicatorStyle);
			Ti::Value ListView::getScrollIndicatorStyle(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.getScrollIndicatorStyle() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Sets the value of the searchText property.
			TI_CREATE_METHOD(ListView, setSearchText);
			Ti::Value ListView::setSearchText(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.setSearchText() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Gets the value of the searchText property.
			TI_CREATE_METHOD(ListView, getSearchText);
			Ti::Value ListView::getSearchText(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.getSearchText() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Sets the value of the searchView property.
			TI_CREATE_METHOD(ListView, setSearchView);
			Ti::Value ListView::setSearchView(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.setSearchView() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Gets the value of the searchView property.
			TI_CREATE_METHOD(ListView, getSearchView);
			Ti::Value ListView::getSearchView(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.getSearchView() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Gets the value of the sectionCount property.
			TI_CREATE_METHOD(ListView, getSectionCount);
			Ti::Value ListView::getSectionCount(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.getSectionCount() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Sets the value of the sectionIndexTitles property.
			TI_CREATE_METHOD(ListView, setSectionIndexTitles);
			Ti::Value ListView::setSectionIndexTitles(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.setSectionIndexTitles() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Gets the value of the sectionIndexTitles property.
			TI_CREATE_METHOD(ListView, getSectionIndexTitles);
			Ti::Value ListView::getSectionIndexTitles(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.getSectionIndexTitles() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Sets the value of the separatorColor property.
			TI_CREATE_METHOD(ListView, setSeparatorColor);
			Ti::Value ListView::setSeparatorColor(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.setSeparatorColor() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Gets the value of the separatorColor property.
			TI_CREATE_METHOD(ListView, getSeparatorColor);
			Ti::Value ListView::getSeparatorColor(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.getSeparatorColor() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Sets the value of the separatorInsets property.
			TI_CREATE_METHOD(ListView, setSeparatorInsets);
			Ti::Value ListView::setSeparatorInsets(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.setSeparatorInsets() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Gets the value of the separatorInsets property.
			TI_CREATE_METHOD(ListView, getSeparatorInsets);
			Ti::Value ListView::getSeparatorInsets(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.getSeparatorInsets() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Sets the value of the separatorStyle property.
			TI_CREATE_METHOD(ListView, setSeparatorStyle);
			Ti::Value ListView::setSeparatorStyle(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.setSeparatorStyle() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Gets the value of the separatorStyle property.
			TI_CREATE_METHOD(ListView, getSeparatorStyle);
			Ti::Value ListView::getSeparatorStyle(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.getSeparatorStyle() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Sets the value of the showVerticalScrollIndicator property.
			TI_CREATE_METHOD(ListView, setShowVerticalScrollIndicator);
			Ti::Value ListView::setShowVerticalScrollIndicator(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.setShowVerticalScrollIndicator() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Gets the value of the showVerticalScrollIndicator property.
			TI_CREATE_METHOD(ListView, getShowVerticalScrollIndicator);
			Ti::Value ListView::getShowVerticalScrollIndicator(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.getShowVerticalScrollIndicator() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Style of the list view.
			TI_CREATE_METHOD(ListView, setStyle);
			Ti::Value ListView::setStyle(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.setStyle() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Gets the value of the style property.
			TI_CREATE_METHOD(ListView, getStyle);
			Ti::Value ListView::getStyle(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.getStyle() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Sets the value of the willScrollOnStatusTap property.
			TI_CREATE_METHOD(ListView, setWillScrollOnStatusTap);
			Ti::Value ListView::setWillScrollOnStatusTap(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.setWillScrollOnStatusTap() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Gets the value of the willScrollOnStatusTap property.
			TI_CREATE_METHOD(ListView, getWillScrollOnStatusTap);
			Ti::Value ListView::getWillScrollOnStatusTap(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.getWillScrollOnStatusTap() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Appends a single section or an array of sections to the end of the list.
			TI_CREATE_METHOD(ListView, appendSection);
			Ti::Value ListView::appendSection(const std::vector<Ti::Value>& arguments);

			// Deletes an existing section.
			TI_CREATE_METHOD(ListView, deleteSectionAt);
			Ti::Value ListView::deleteSectionAt(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.deleteSectionAt() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Deselects a specific item.
			TI_CREATE_METHOD(ListView, deselectItem);
			Ti::Value ListView::deselectItem(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.deselectItem() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Finishes a batch update of the View's layout properties and schedules a layout pass of the 
			// view tree.
			TI_CREATE_METHOD(ListView, finishLayout);
			Ti::Value ListView::finishLayout(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.finishLayout() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Inserts a section or an array of sections at a specific index.
			TI_CREATE_METHOD(ListView, insertSectionAt);
			Ti::Value ListView::insertSectionAt(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.insertSectionAt() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Replaces an existing section.
			TI_CREATE_METHOD(ListView, replaceSectionAt);
			Ti::Value ListView::replaceSectionAt(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.replaceSectionAt() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Scrolls to a specific item.
			TI_CREATE_METHOD(ListView, scrollToItem);
			Ti::Value ListView::scrollToItem(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.scrollToItem() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Selects an item in the list using the specified item and section indices.
			TI_CREATE_METHOD(ListView, selectItem);
			Ti::Value ListView::selectItem(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.selectItem() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Sets this list view's content insets.
			TI_CREATE_METHOD(ListView, setContentInsets);
			Ti::Value ListView::setContentInsets(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.setContentInsets() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Sets a reference item in the list view.
			TI_CREATE_METHOD(ListView, setMarker);
			Ti::Value ListView::setMarker(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.setMarker() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Starts a batch update of this view's layout properties.
			TI_CREATE_METHOD(ListView, startLayout);
			Ti::Value ListView::startLayout(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.startLayout() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Performs a batch update of all supplied layout properties and schedules a layout pass after 
			// they have been updated.
			TI_CREATE_METHOD(ListView, updateLayout);
			Ti::Value ListView::updateLayout(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListView.updateLayout() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
		private:
			Windows::UI::Xaml::Controls::ListView^ listview_;
			Windows::UI::Xaml::Data::CollectionViewSource^ collectionViewSource_;
			Windows::Foundation::Collections::IObservableVector<Platform::Object^>^ collectionViewItems_;
			Ti::Value sections_;
		};

	}	// namespace UI {
}
#endif // _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUILISTVIEW_H_
