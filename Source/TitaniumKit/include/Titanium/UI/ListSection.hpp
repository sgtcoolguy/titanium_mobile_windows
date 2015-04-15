/**
 * TitaniumKit Titanium.UI.ListSection
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_UI_LISTSECTION_HPP_
#define _TITANIUM_UI_LISTSECTION_HPP_

#include "Titanium/Module.hpp"
#include "Titanium/UI/View.hpp"
#include "Titanium/UI/ListViewAnimationProperties.hpp"

namespace Titanium
{
	namespace UI
	{

		using namespace HAL;
		using View_shared_ptr_t = std::shared_ptr<View>;

		/*!
		  @struct
		  @discussion An abstract datatype for specifying an item data.
  		  This is an abstract type. Any object meeting this description can be used where this type is used.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/ListDataItem
		*/
		struct ListDataItem {
			// Contains key-value pairs of properties and values that are applied to the ListItem.
			std::unordered_map<std::string, JSValue> properties;
			// Template ID configured with the ListView.templates property
			std::string templateId;
			// Contains key-value pairs of properties and values that are applied to the custom property binding
			std::unordered_map<std::string, JSValue> bindings;
		};

		// Convert JSObject into ListDataItem
		ListDataItem js_to_ListDataItem(const JSObject& object);
		JSObject ListDataItem_to_js(const JSContext& js_context, const ListDataItem& item);

		/*!
		  @class
		  @discussion This is the Titanium ListSection Module.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.UI.ListSection
		*/
		class TITANIUMKIT_EXPORT ListSection : public Module, public JSExport<ListSection>
		{

		public:

			/*!
			  @property
			  @abstract footerTitle
			  @discussion Title of this section footer.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, footerTitle);

			/*!
			  @property
			  @abstract headerTitle
			  @discussion Title of this section header.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, headerTitle);

			/*!
			  @property
			  @abstract footerView
			  @discussion View to use for this section footer.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(View_shared_ptr_t, footerView);

			/*!
			  @property
			  @abstract headerView
			  @discussion View to use for this section header
			*/
			TITANIUM_PROPERTY_IMPL_DEF(View_shared_ptr_t, headerView);

			/*!
			  @property
			  @abstract items
			  @discussion Items of this list section.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::vector<ListDataItem>, items);
			virtual void items_set_notify(size_t index, size_t count); // for subclass

			/*!
			  @method
			  @abstract setItems
			  @discussion Sets the data entries in the list section.
			*/
			virtual void setItems(const std::vector<ListDataItem>& dataItems, const std::shared_ptr<ListViewAnimationProperties>& animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract appendItems
			  @discussion Appends the data entries to the end of the list section.
			*/
			virtual void appendItems(const std::vector<ListDataItem>& dataItems, const std::shared_ptr<ListViewAnimationProperties>& animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract insertItemsAt
			  @discussion Inserts data entries to the list section at the specified index.
			*/
			virtual void insertItemsAt(uint32_t itemIndex, const std::vector<ListDataItem>& dataItems, const std::shared_ptr<ListViewAnimationProperties>& animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract replaceItemsAt
			  @discussion Removes count entries from the list section at the specified index,then inserts data entries to the list section at the same index.
			*/
			virtual void replaceItemsAt(uint32_t index, uint32_t count, const std::vector<ListDataItem>& dataItems, const std::shared_ptr<ListViewAnimationProperties>& animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract deleteItemsAt
			  @discussion Removes count entries from the list section at the specified index.
			*/
			virtual void deleteItemsAt(uint32_t itemIndex, uint32_t count, const std::shared_ptr<ListViewAnimationProperties>& animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract getItemAt
			  @discussion Returns the item entry from the list view at the specified index.
			*/
			virtual ListDataItem getItemAt(uint32_t itemIndex) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract updateItemAt
			  @discussion Updates an item at the specified index.
			*/
			virtual void updateItemAt(uint32_t index, const ListDataItem& dataItem, const std::shared_ptr<ListViewAnimationProperties>& animation) TITANIUM_NOEXCEPT;

			ListSection(const JSContext&) TITANIUM_NOEXCEPT;
			virtual void postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) override;

			virtual ~ListSection() = default;
			ListSection(const ListSection&) = default;
			ListSection& operator=(const ListSection&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			ListSection(ListSection&&)                 = default;
			ListSection& operator=(ListSection&&)      = default;
#endif

			static void JSExportInitialize();

			TITANIUM_PROPERTY_DEF(footerTitle);
			TITANIUM_PROPERTY_DEF(headerTitle);
			TITANIUM_PROPERTY_DEF(footerView);
			TITANIUM_PROPERTY_DEF(headerView);
			TITANIUM_PROPERTY_DEF(items);
			TITANIUM_FUNCTION_DEF(setItems);
			TITANIUM_FUNCTION_DEF(appendItems);
			TITANIUM_FUNCTION_DEF(insertItemsAt);
			TITANIUM_FUNCTION_DEF(replaceItemsAt);
			TITANIUM_FUNCTION_DEF(deleteItemsAt);
			TITANIUM_FUNCTION_DEF(getItemAt);
			TITANIUM_FUNCTION_DEF(updateItemAt);
			TITANIUM_FUNCTION_DEF(getFooterTitle);
			TITANIUM_FUNCTION_DEF(setFooterTitle);
			TITANIUM_FUNCTION_DEF(getFooterView);
			TITANIUM_FUNCTION_DEF(setFooterView);
			TITANIUM_FUNCTION_DEF(getHeaderTitle);
			TITANIUM_FUNCTION_DEF(setHeaderTitle);
			TITANIUM_FUNCTION_DEF(getHeaderView);
			TITANIUM_FUNCTION_DEF(setHeaderView);
			TITANIUM_FUNCTION_DEF(getItems);

		protected:
#pragma warning(push)
#pragma warning(disable : 4251)
			std::string footerTitle__;
			std::string headerTitle__;
			View_shared_ptr_t footerView__;
			View_shared_ptr_t headerView__;
			std::vector<ListDataItem> items__;

			JSObject listviewAnimationProperties_ctor__;
#pragma warning(pop)
		};

	} // namespace UI
} // namespace Titanium
#endif // _TITANIUM_UI_LISTSECTION_HPP_