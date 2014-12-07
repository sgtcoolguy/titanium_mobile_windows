/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#include "Modules/UI/TiUIListItem.h"

namespace Ti
{
	namespace UI
	{
		JSStaticFunction const ListItem::ClassMethods[] = {
				{ "setAccessoryType", _setAccessoryType, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getAccessoryType", _getAccessoryType, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setBackgroundGradient", _setBackgroundGradient, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getBackgroundGradient", _getBackgroundGradient, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setBackgroundImage", _setBackgroundImage, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getBackgroundImage", _getBackgroundImage, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setCanEdit", _setCanEdit, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getCanEdit", _getCanEdit, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setCanMove", _setCanMove, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getCanMove", _getCanMove, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setFont", _setFont, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getFont", _getFont, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setImage", _setImage, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getImage", _getImage, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setItemId", _setItemId, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getItemId", _getItemId, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setSearchableText", _setSearchableText, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getSearchableText", _getSearchableText, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setSelectedBackgroundColor", _setSelectedBackgroundColor, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getSelectedBackgroundColor", _getSelectedBackgroundColor, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setSelectedBackgroundGradient", _setSelectedBackgroundGradient, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getSelectedBackgroundGradient", _getSelectedBackgroundGradient, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setSelectedBackgroundImage", _setSelectedBackgroundImage, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getSelectedBackgroundImage", _getSelectedBackgroundImage, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setSelectionStyle", _setSelectionStyle, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getSelectionStyle", _getSelectionStyle, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setSubtitle", _setSubtitle, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getSubtitle", _getSubtitle, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setTitle", _setTitle, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getTitle", _getTitle, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ 0, 0, 0 }
		};

		ListItem::ListItem(const std::string& name, const std::vector<Ti::Value>& arguments) : Ti::ViewProxy(name, arguments)
		{
			canvas_ = ref new Windows::UI::Xaml::Controls::Canvas();
			setComponent(canvas_);
		}

		Ti::Value ListItem::eventAdded(const std::vector<Ti::Value>& args) {
			if (args.size() < 1) {
				return Ti::Value::Undefined();
			}
			const auto arg = args.at(0).toString();
			return Ti::ViewProxy::eventAdded(args);
		}

		Ti::Value ListItem::eventRemoved(const std::vector<Ti::Value>& args) {
			if (args.size() < 1) {
				return Ti::Value::Undefined();
			}
			return Ti::ViewProxy::eventRemoved(args);
		}

	}
}
