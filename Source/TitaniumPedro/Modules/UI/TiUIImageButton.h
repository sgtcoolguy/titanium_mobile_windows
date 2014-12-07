/** -*- mode: c++ -*-
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUI_IMAGE_BUTTON_H_
#define _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUI_IMAGE_BUTTON_H_

#include "TiCore/TiViewProxy.h"

namespace Ti {
	namespace UI {

		class ImageButton : public Ti::ViewProxy, public virtual_enable_shared_from_this < ImageButton > 
		{
			TI_CREATE_PROXY(ImageButton);
			static JSClassRef Parent() { return Ti::ViewProxy::ClassDef(); }
		public:
			virtual std::string defaultHeight() const { return Ti::Constants::SizeSIZE; }
			virtual std::string defaultWidth() const { return Ti::Constants::SizeSIZE; }
		
		protected:

			ImageButton(const std::string& name, const std::vector<Ti::Value>& arguments);
			TI_CREATE_METHOD(ImageButton, setTitle);
			Ti::Value setTitle(const std::vector<Ti::Value>& arguments);
			TI_CREATE_METHOD(ImageButton, setImage);
			Ti::Value setImage(const std::vector<Ti::Value>& arguments);
			TI_CREATE_METHOD(ImageButton, setFont);
			Ti::Value setFont(const std::vector<Ti::Value>& arguments);

		private:

			Windows::UI::Xaml::Controls::Button ^button_;
			Windows::UI::Xaml::Controls::TextBlock ^label_;
			Windows::UI::Xaml::Controls::Image ^image_view_;
				
		};

	}	// namespace UI {
}
#endif	// _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUIVIEW_H_
