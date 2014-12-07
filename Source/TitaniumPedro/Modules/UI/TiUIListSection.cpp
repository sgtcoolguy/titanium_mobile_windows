/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#include "Modules/UI/TiUIListSection.h"

namespace Ti
{
	namespace UI
	{
		JSStaticFunction const ListSection::ClassMethods[] = {
				{ "setFooterTitle", _setFooterTitle, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getFooterTitle", _getFooterTitle, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setFooterView", _setFooterView, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getFooterView", _getFooterView, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setItems", _setItems, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getItems", _getItems, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setHeaderTitle", _setHeaderTitle, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getHeaderTitle", _getHeaderTitle, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setHeaderView", _setHeaderView, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getHeaderView", _getHeaderView, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "appendItems", _appendItems, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "deleteItemsAt", _deleteItemsAt, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getItemAt", _getItemAt, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "insertItemsAt", _insertItemsAt, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "replaceItemsAt", _replaceItemsAt, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "updateItemAt", _updateItemAt, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ 0, 0, 0 }
		};

		ListSection::ListSection(const std::string& name, const std::vector<Ti::Value>& arguments) : Ti::Proxy(name, arguments)
		{
			
		}
	}
}
