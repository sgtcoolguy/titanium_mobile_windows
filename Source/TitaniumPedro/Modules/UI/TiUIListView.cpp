/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#include "Modules/UI/TiUIListView.h"
#include "Modules/UI/TiUIListSection.h"
#include <collection.h>

namespace Ti
{
	namespace UI
	{
		std::string ListView::defaultHeight() const {
			return Ti::Constants::SizeFILL;
		}

		std::string ListView::defaultWidth() const {
			return Ti::Constants::SizeFILL;
		}

		Ti::Value ListView::eventAdded(const std::vector<Ti::Value>& args) {
			if (args.size() < 1) {
				return Ti::Value::Undefined();
			}
			const auto arg = args.at(0).toString();
			return Ti::ViewProxy::eventAdded(args);
		}

		Ti::Value ListView::eventRemoved(const std::vector<Ti::Value>& args) {
			if (args.size() < 1) {
				return Ti::Value::Undefined();
			}
			return Ti::ViewProxy::eventRemoved(args);
		}

		JSStaticFunction const ListView::ClassMethods[] = {
				{ "setAllowsSelection", _setAllowsSelection, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getAllowsSelection", _getAllowsSelection, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setCanScroll", _setCanScroll, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getCanScroll", _getCanScroll, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setCaseInsensitiveSearch", _setCaseInsensitiveSearch, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getCaseInsensitiveSearch", _getCaseInsensitiveSearch, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setEditing", _setEditing, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getEditing", _getEditing, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setFooterDividersEnabled", _setFooterDividersEnabled, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getFooterDividersEnabled", _getFooterDividersEnabled, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setFooterTitle", _setFooterTitle, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getFooterTitle", _getFooterTitle, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setFooterView", _setFooterView, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getFooterView", _getFooterView, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setHeaderDividersEnabled", _setHeaderDividersEnabled, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getHeaderDividersEnabled", _getHeaderDividersEnabled, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setHeaderTitle", _setHeaderTitle, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getHeaderTitle", _getHeaderTitle, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setHeaderView", _setHeaderView, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getHeaderView", _getHeaderView, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setKeepSectionsInSearch", _setKeepSectionsInSearch, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getKeepSectionsInSearch", _getKeepSectionsInSearch, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setPruneSectionsOnEdit", _setPruneSectionsOnEdit, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getPruneSectionsOnEdit", _getPruneSectionsOnEdit, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setPullView", _setPullView, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getPullView", _getPullView, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setRefreshControl", _setRefreshControl, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getRefreshControl", _getRefreshControl, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setScrollIndicatorStyle", _setScrollIndicatorStyle, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getScrollIndicatorStyle", _getScrollIndicatorStyle, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setSections", _setSections, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getSections", _getSections, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setSearchText", _setSearchText, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getSearchText", _getSearchText, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setSearchView", _setSearchView, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getSearchView", _getSearchView, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getSectionCount", _getSectionCount, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setSectionIndexTitles", _setSectionIndexTitles, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getSectionIndexTitles", _getSectionIndexTitles, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setSeparatorColor", _setSeparatorColor, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getSeparatorColor", _getSeparatorColor, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setSeparatorInsets", _setSeparatorInsets, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getSeparatorInsets", _getSeparatorInsets, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setSeparatorStyle", _setSeparatorStyle, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getSeparatorStyle", _getSeparatorStyle, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setShowVerticalScrollIndicator", _setShowVerticalScrollIndicator, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getShowVerticalScrollIndicator", _getShowVerticalScrollIndicator, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setStyle", _setStyle, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getStyle", _getStyle, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setWillScrollOnStatusTap", _setWillScrollOnStatusTap, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getWillScrollOnStatusTap", _getWillScrollOnStatusTap, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "appendSection", _appendSection, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "deleteSectionAt", _deleteSectionAt, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "deselectItem", _deselectItem, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "finishLayout", _finishLayout, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "insertSectionAt", _insertSectionAt, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "replaceSectionAt", _replaceSectionAt, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "scrollToItem", _scrollToItem, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "selectItem", _selectItem, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setContentInsets", _setContentInsets, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setMarker", _setMarker, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "startLayout", _startLayout, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "updateLayout", _updateLayout, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ 0, 0, 0 }
		};

		ListView::ListView(const std::string& name, const std::vector<Ti::Value>& arguments) : Ti::ViewProxy(name, arguments)
		{
			listview_ = ref new Windows::UI::Xaml::Controls::ListView();
			setComponent(listview_);

			collectionViewSource_ = ref new Windows::UI::Xaml::Data::CollectionViewSource();
			collectionViewItems_ = ref new Platform::Collections::Vector<::Platform::Object^>();
			collectionViewSource_->Source = collectionViewItems_;
			collectionViewSource_->IsSourceGrouped = true;

			auto binding = ref new Windows::UI::Xaml::Data::Binding();
			binding->Source = collectionViewSource_;
			Windows::UI::Xaml::Data::BindingOperations::SetBinding(listview_, Windows::UI::Xaml::Controls::ListView::ItemsSourceProperty, binding);
		}

		// Appends a single section or an array of sections to the end of the list.
		Ti::Value ListView::appendSection(const std::vector<Ti::Value>& arguments) {
			if (arguments.size() < 1) {
				std::clog << "[ERROR] section not found for ListView.appendSection(section) " << std::endl;
				return Ti::Value::Undefined();
			}
			const auto value = arguments.at(0);

			if (value.isArray()) {
				for (auto i = 0; i < value.getLength(); i++) {
					std::vector<Ti::Value> args;
					args.push_back(value.getValueAtIndex(i));
					appendSection(args);
				}
				return Ti::Value::Undefined();
			}

			auto group = ref new ::Platform::Collections::Vector<Windows::UI::Xaml::FrameworkElement^>();
			const auto section = dynamic_cast<UI::ListSection*>(toProxy(value).get());

			// Create UI element
			for (auto i = 0; i < section->size(); i++) {
				std::vector<Ti::Value> func_args;
				func_args.push_back(value);
				func_args.push_back(Ti::Value(static_cast<double>(i)));
				const auto result = this->callFunction("_createSectionItemAt", func_args);
				if (result.isObject() && !result.isNull()) {
					const auto item = dynamic_cast<Ti::ViewProxy*>(toProxy(result).get());
					if (item != nullptr) {
						group->Append(item->getComponent());
					}
				}
			}

			this->collectionViewItems_->Append(group);

			return Ti::Value::Undefined();
		}
	}
}
