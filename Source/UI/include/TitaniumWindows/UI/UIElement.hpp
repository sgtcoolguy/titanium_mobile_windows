/**
 * Titanium.UI.View for Windows
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_UI_VIEW_HPP_
#define _TITANIUMWINDOWS_UI_VIEW_HPP_

#include "TitaniumWindows_UI_EXPORT.h"
#include "Titanium/UI/View.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		using namespace HAL;

		class TITANIUMWINDOWS_UI_EXPORT UIElement final : public Titanium::UI::View, public JSExport<UIElement>
		{

		public:
			UIElement(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~UIElement();
			UIElement(const UIElement&) = default;
			UIElement& operator=(const UIElement&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			UIElement(UIElement&&) = default;
			UIElement& operator=(UIElement&&) = default;
#endif

			static void JSExportInitialize();

			virtual void postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) override;

			virtual void setComponent(Windows::UI::Xaml::FrameworkElement^) TITANIUM_NOEXCEPT;

		private:
		};
	} // namespace UI
} // namespace TitaniumWindows

#endif  // _TITANIUMWINDOWS_UI_VIEW_HPP_
