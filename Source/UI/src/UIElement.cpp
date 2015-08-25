/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/UI/UIElement.hpp"
#include "TitaniumWindows/UI/WindowsViewLayoutDelegate.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		UIElement::UIElement(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::UI::View(js_context)
		{
			TITANIUM_LOG_DEBUG("TitaniumWindows::UI::UIElement::ctor ", this);
		}

		UIElement::~UIElement() 
		{
			TITANIUM_LOG_DEBUG("TitaniumWindows::UI::UIElement::dtor ", this);
		}

		void UIElement::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{
			Titanium::UI::View::postCallAsConstructor(js_context, arguments);	

			Titanium::UI::View::setLayoutDelegate<WindowsViewLayoutDelegate>();

			layoutDelegate__->set_defaultHeight(Titanium::UI::LAYOUT::FILL);
			layoutDelegate__->set_defaultWidth(Titanium::UI::LAYOUT::FILL);
			layoutDelegate__->set_autoLayoutForHeight(Titanium::UI::LAYOUT::FILL);
			layoutDelegate__->set_autoLayoutForWidth(Titanium::UI::LAYOUT::FILL);
		}

		void UIElement::JSExportInitialize()
		{
			JSExport<View>::SetClassVersion(1);
			JSExport<View>::SetParent(JSExport<Titanium::UI::View>::Class());
		}

		void UIElement::setComponent(Windows::UI::Xaml::FrameworkElement^ element) TITANIUM_NOEXCEPT
		{
			getViewLayoutDelegate<WindowsViewLayoutDelegate>()->setComponent(element);
		}
	} // namespace UI
} // namespace TitaniumWindows
