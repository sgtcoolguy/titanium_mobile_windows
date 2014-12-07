/** -*- mode: c++ -*-
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#ifndef _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TableView_Row_H_
#define _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TableView_Row_H_

#include "TiCore/TiViewProxy.h"

// This is a Ti.UI.TableView

namespace Ti{
	namespace UI {

		class TableViewRow : public Ti::ViewProxy, public virtual_enable_shared_from_this < TableViewRow >
		{
			TI_CREATE_PROXY(TableViewRow);
			static JSClassRef Parent() { return Ti::ViewProxy::ClassDef(); }
		public:
			virtual std::string defaultWidth() const { return Ti::Constants::SizeFILL; }
			virtual std::string defaultHeight() const { return Ti::Constants::SizeSIZE; }

		protected:
			TableViewRow(const std::string& name, const std::vector<Ti::Value>& arguments);

			virtual ~TableViewRow() {
				list_view_row_ = nullptr;
			}

			// Disable these
			virtual Ti::Value setWidth(const std::vector<Ti::Value>& args){ return Ti::Value::Undefined(); }
			virtual Ti::Value setLeft(const std::vector<Ti::Value>& args){ return Ti::Value::Undefined(); }
			virtual Ti::Value setRight(const std::vector<Ti::Value>& args){ return Ti::Value::Undefined(); }
			virtual Ti::Value setTop(const std::vector<Ti::Value>& args){ return Ti::Value::Undefined(); }
			virtual Ti::Value setBottom(const std::vector<Ti::Value>& args){ return Ti::Value::Undefined(); }

		private:

			Windows::UI::Xaml::Controls::Canvas^ list_view_row_;
		};

	}	// namespace UI {
}
#endif	// _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUISLIDER_H_
