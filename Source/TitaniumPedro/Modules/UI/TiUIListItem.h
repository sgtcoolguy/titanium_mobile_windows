/** -*- mode: c++ -*-
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUILISTITEM_H_
#define _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUILISTITEM_H_

#include "TiCore/TiViewProxy.h"

namespace Ti
{
	namespace UI
	{
		class ListItem : public Ti::ViewProxy, public virtual_enable_shared_from_this < ListItem >
		{
			TI_CREATE_PROXY(ListItem);
			static JSClassRef Parent() { return Ti::ViewProxy::ClassDef(); }
		public:
			virtual std::string defaultHeight() const override { return Ti::Constants::SizeFILL; }
			virtual std::string defaultWidth() const override { return Ti::Constants::SizeFILL; }
			virtual Ti::Value eventAdded(const std::vector<Ti::Value>& args) override;
			virtual Ti::Value eventRemoved(const std::vector<Ti::Value>& args) override;

		protected:
			ListItem(const std::string& name, const std::vector<Ti::Value>& arguments);
			virtual ~ListItem() {
				canvas_ = nullptr;
			}

			// Sets an accessory on the right side of an item.
			TI_CREATE_METHOD(ListItem, setAccessoryType);
			Ti::Value ListItem::setAccessoryType(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListItem.setAccessoryType() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Sets an accessory on the right side of an item.
			TI_CREATE_METHOD(ListItem, getAccessoryType);
			Ti::Value ListItem::getAccessoryType(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListItem.getAccessoryType() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Background gradient to render when the item is not selected.
			TI_CREATE_METHOD(ListItem, setBackgroundGradient);
			Ti::Value ListItem::setBackgroundGradient(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListItem.setBackgroundGradient() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Background gradient to render when the item is not selected.
			TI_CREATE_METHOD(ListItem, getBackgroundGradient);
			Ti::Value ListItem::getBackgroundGradient(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListItem.getBackgroundGradient() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Background image to render when the item is not selected.
			TI_CREATE_METHOD(ListItem, setBackgroundImage);
			Ti::Value ListItem::setBackgroundImage(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListItem.setBackgroundImage() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Background image to render when the item is not selected.
			TI_CREATE_METHOD(ListItem, getBackgroundImage);
			Ti::Value ListItem::getBackgroundImage(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListItem.getBackgroundImage() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Specifies if the item can be deleted by a user initiated action.
			TI_CREATE_METHOD(ListItem, setCanEdit);
			Ti::Value ListItem::setCanEdit(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListItem.setCanEdit() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Specifies if the item can be deleted by a user initiated action.
			TI_CREATE_METHOD(ListItem, getCanEdit);
			Ti::Value ListItem::getCanEdit(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListItem.getCanEdit() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Specifies if the item can be reordered within the list view by a user initiated action.
			TI_CREATE_METHOD(ListItem, setCanMove);
			Ti::Value ListItem::setCanMove(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListItem.setCanMove() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Specifies if the item can be reordered within the list view by a user initiated action.
			TI_CREATE_METHOD(ListItem, getCanMove);
			Ti::Value ListItem::getCanMove(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListItem.getCanMove() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Font to use for the item title.
			TI_CREATE_METHOD(ListItem, setFont);
			Ti::Value ListItem::setFont(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListItem.setFont() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Font to use for the item title.
			TI_CREATE_METHOD(ListItem, getFont);
			Ti::Value ListItem::getFont(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListItem.getFont() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Image to render in the image area of the item, specified as a local path or URL.
			TI_CREATE_METHOD(ListItem, setImage);
			Ti::Value ListItem::setImage(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListItem.setImage() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Image to render in the image area of the item, specified as a local path or URL.
			TI_CREATE_METHOD(ListItem, getImage);
			Ti::Value ListItem::getImage(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListItem.getImage() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// A user defined string that gets passed to events.
			TI_CREATE_METHOD(ListItem, setItemId);
			Ti::Value ListItem::setItemId(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListItem.setItemId() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// A user defined string that gets passed to events.
			TI_CREATE_METHOD(ListItem, getItemId);
			Ti::Value ListItem::getItemId(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListItem.getItemId() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// The text to match against when the ListView is performing a search.
			TI_CREATE_METHOD(ListItem, setSearchableText);
			Ti::Value ListItem::setSearchableText(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListItem.setSearchableText() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// The text to match against when the ListView is performing a search.
			TI_CREATE_METHOD(ListItem, getSearchableText);
			Ti::Value ListItem::getSearchableText(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListItem.getSearchableText() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Background color of the view, as a color name or hex triplet when item is selected.
			TI_CREATE_METHOD(ListItem, setSelectedBackgroundColor);
			Ti::Value ListItem::setSelectedBackgroundColor(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListItem.setSelectedBackgroundColor() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Background color of the view, as a color name or hex triplet when item is selected.
			TI_CREATE_METHOD(ListItem, getSelectedBackgroundColor);
			Ti::Value ListItem::getSelectedBackgroundColor(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListItem.getSelectedBackgroundColor() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Background gradient to render when the item is selected.
			TI_CREATE_METHOD(ListItem, setSelectedBackgroundGradient);
			Ti::Value ListItem::setSelectedBackgroundGradient(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListItem.setSelectedBackgroundGradient() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Background gradient to render when the item is selected.
			TI_CREATE_METHOD(ListItem, getSelectedBackgroundGradient);
			Ti::Value ListItem::getSelectedBackgroundGradient(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListItem.getSelectedBackgroundGradient() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Background image to render when the item is selected.
			TI_CREATE_METHOD(ListItem, setSelectedBackgroundImage);
			Ti::Value ListItem::setSelectedBackgroundImage(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListItem.setSelectedBackgroundImage() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Background image to render when the item is selected.
			TI_CREATE_METHOD(ListItem, getSelectedBackgroundImage);
			Ti::Value ListItem::getSelectedBackgroundImage(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListItem.getSelectedBackgroundImage() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Selection style constant to control the selection color.
			TI_CREATE_METHOD(ListItem, setSelectionStyle);
			Ti::Value ListItem::setSelectionStyle(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListItem.setSelectionStyle() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Selection style constant to control the selection color.
			TI_CREATE_METHOD(ListItem, getSelectionStyle);
			Ti::Value ListItem::getSelectionStyle(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListItem.getSelectionStyle() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Subtitle to set in the text area of the item.
			TI_CREATE_METHOD(ListItem, setSubtitle);
			Ti::Value ListItem::setSubtitle(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListItem.setSubtitle() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Subtitle to set in the text area of the item.
			TI_CREATE_METHOD(ListItem, getSubtitle);
			Ti::Value ListItem::getSubtitle(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListItem.getSubtitle() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Title to set in the text area of the item.
			TI_CREATE_METHOD(ListItem, setTitle);
			Ti::Value ListItem::setTitle(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListItem.setTitle() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}
			// Title to set in the text area of the item.
			TI_CREATE_METHOD(ListItem, getTitle);
			Ti::Value ListItem::getTitle(const std::vector<Ti::Value>& arguments) {
				std::clog << "[WARN] ListItem.getTitle() not implemented yet. Returning Undefined" << std::endl;
				return Ti::Value::Undefined();
			}

		private:
			Windows::UI::Xaml::Controls::Canvas^ canvas_;

		};

	}	// namespace UI {
}
#endif // _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUILISTITEM_H_
