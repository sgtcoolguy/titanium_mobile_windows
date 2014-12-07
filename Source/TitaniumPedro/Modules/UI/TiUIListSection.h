/** -*- mode: c++ -*-
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUILISTSECTION_H_
#define _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUILISTSECTION_H_

#include "TiCore/TiProxy.h"

namespace Ti { namespace UI {

	class ListSection : public Ti::Proxy, public virtual_enable_shared_from_this < ListSection >
	{
		TI_CREATE_PROXY(ListSection);
		static JSClassRef Parent() { return Ti::Proxy::ClassDef(); }
	public:
		size_t size() {
			return items_.getLength();
		}

	protected:
		ListSection(const std::string& name, const std::vector<Ti::Value>& arguments);
		virtual ~ListSection() {
		}

		// Sets the data entries in the list section.
		TI_CREATE_METHOD(ListSection, setItems);
		Ti::Value ListSection::setItems(const std::vector<Ti::Value>& arguments) {
			if (arguments.size() == 0 || !arguments.at(0).isArray()) {
				std::clog << "[ERROR] ListSection.items should be an array" << std::endl;
				return Ti::Value::Undefined();
			}
			items_ = arguments.at(0);
			return Ti::Value::Undefined();
		}
		// Gets the value of the items property.
		TI_CREATE_METHOD(ListSection, getItems);
		Ti::Value ListSection::getItems(const std::vector<Ti::Value>& arguments) {
			return items_;
		}

		// Sets the value of the footerTitle property.
		TI_CREATE_METHOD(ListSection, setFooterTitle);
		Ti::Value ListSection::setFooterTitle(const std::vector<Ti::Value>& arguments)
		{
			footerTitle_ = arguments.at(0).toString();
			return Ti::Value::Undefined();
		}
		// Gets the value of the footerTitle property.
		TI_CREATE_METHOD(ListSection, getFooterTitle);
		Ti::Value ListSection::getFooterTitle(const std::vector<Ti::Value>& arguments)
		{
			return Ti::Value(footerTitle_);
		}
		// Sets the value of the footerView property.
		TI_CREATE_METHOD(ListSection, setFooterView);
		Ti::Value ListSection::setFooterView(const std::vector<Ti::Value>& arguments)
		{
			std::clog << "[WARN] ListSection.setFooterView() not implemented yet. Returning Undefined" << std::endl;
			return Ti::Value::Undefined();
		}
		// Gets the value of the footerView property.
		TI_CREATE_METHOD(ListSection, getFooterView);
		Ti::Value ListSection::getFooterView(const std::vector<Ti::Value>& arguments)
		{
			std::clog << "[WARN] ListSection.getFooterView() not implemented yet. Returning Undefined" << std::endl;
			return Ti::Value::Undefined();
		}
		// Sets the value of the headerTitle property.
		TI_CREATE_METHOD(ListSection, setHeaderTitle);
		Ti::Value ListSection::setHeaderTitle(const std::vector<Ti::Value>& arguments)
		{
			headerTitle_ = arguments.at(0).toString();
			return Ti::Value::Undefined();
		}
		// Gets the value of the headerTitle property.
		TI_CREATE_METHOD(ListSection, getHeaderTitle);
		Ti::Value ListSection::getHeaderTitle(const std::vector<Ti::Value>& arguments)
		{
			return Ti::Value(headerTitle_);
		}
		// Sets the value of the headerView property.
		TI_CREATE_METHOD(ListSection, setHeaderView);
		Ti::Value ListSection::setHeaderView(const std::vector<Ti::Value>& arguments)
		{
			std::clog << "[WARN] ListSection.setHeaderView() not implemented yet. Returning Undefined" << std::endl;
			return Ti::Value::Undefined();
		}
		// Gets the value of the headerView property.
		TI_CREATE_METHOD(ListSection, getHeaderView);
		Ti::Value ListSection::getHeaderView(const std::vector<Ti::Value>& arguments)
		{
			std::clog << "[WARN] ListSection.getHeaderView() not implemented yet. Returning Undefined" << std::endl;
			return Ti::Value::Undefined();
		}
		// Appends the data entries to the end of the list section.
		TI_CREATE_METHOD(ListSection, appendItems);
		Ti::Value ListSection::appendItems(const std::vector<Ti::Value>& arguments)
		{
			std::clog << "[WARN] ListSection.appendItems() not implemented yet. Returning Undefined" << std::endl;
			return Ti::Value::Undefined();
		}
		// Removes count entries from the list section at the specified index.
		TI_CREATE_METHOD(ListSection, deleteItemsAt);
		Ti::Value ListSection::deleteItemsAt(const std::vector<Ti::Value>& arguments)
		{
			std::clog << "[WARN] ListSection.deleteItemsAt() not implemented yet. Returning Undefined" << std::endl;
			return Ti::Value::Undefined();
		}
		// Returns the item entry from the list view at the specified index.
		TI_CREATE_METHOD(ListSection, getItemAt);
		Ti::Value ListSection::getItemAt(const std::vector<Ti::Value>& arguments)
		{
			std::clog << "[WARN] ListSection.getItemAt() not implemented yet. Returning Undefined" << std::endl;
			return Ti::Value::Undefined();
		}
		// Inserts data entries to the list section at the specified index.
		TI_CREATE_METHOD(ListSection, insertItemsAt);
		Ti::Value ListSection::insertItemsAt(const std::vector<Ti::Value>& arguments)
		{
			std::clog << "[WARN] ListSection.insertItemsAt() not implemented yet. Returning Undefined" << std::endl;
			return Ti::Value::Undefined();
		}
		// Removes count entries from the list section at the specified index,
		// then inserts data entries to the list section at the same index.
		TI_CREATE_METHOD(ListSection, replaceItemsAt);
		Ti::Value ListSection::replaceItemsAt(const std::vector<Ti::Value>& arguments)
		{
			std::clog << "[WARN] ListSection.replaceItemsAt() not implemented yet. Returning Undefined" << std::endl;
			return Ti::Value::Undefined();
		}
		// Updates an item at the specified index.
		TI_CREATE_METHOD(ListSection, updateItemAt);
		Ti::Value ListSection::updateItemAt(const std::vector<Ti::Value>& arguments)
		{
			std::clog << "[WARN] ListSection.updateItemAt() not implemented yet. Returning Undefined" << std::endl;
			return Ti::Value::Undefined();
		}
		private:
			std::string footerTitle_;
			std::string headerTitle_;
			Ti::Value items_;
		};

	}	// namespace UI {
}
#endif // _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUILISTSECTION_H_
