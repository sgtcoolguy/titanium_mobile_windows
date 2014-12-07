/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#include "Modules/UI/TiUITableViewRow.h"
#include "TiCore/TiConstants.h"
#include "TiCore/TiUtils.h"

namespace Ti{
	namespace UI {

		JSStaticFunction const TableViewRow::ClassMethods[] = {
				{ 0, 0, 0 }
		};

		TableViewRow::TableViewRow(const std::string& name, const std::vector<Ti::Value>& arguments) : Ti::ViewProxy(name, arguments)
		{
			list_view_row_ = ref new Windows::UI::Xaml::Controls::Canvas();
			setComponent(list_view_row_);
		}

	}	// namespace UI {
}