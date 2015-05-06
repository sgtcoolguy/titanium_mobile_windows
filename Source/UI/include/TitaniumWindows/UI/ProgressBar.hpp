/**
 * Titanium.UI.ProgressBar for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_PROGRESSBAR_HPP_
#define _TITANIUMWINDOWS_PROGRESSBAR_HPP_

#include "TitaniumWindows/UI/detail/UIBase.hpp"
#include "Titanium/UI/ProgressBar.hpp"
#include "TitaniumWindows/UI/WindowsViewLayoutDelegate.hpp"

namespace TitaniumWindows
{
	namespace UI
	{

		using namespace HAL;

		/*!
		  @class

		  @discussion This is the Titanium.UI.ProgressBar implementation for Windows.
		*/
		class TITANIUMWINDOWS_UI_EXPORT ProgressBar final : public Titanium::UI::ProgressBar, public JSExport<ProgressBar>
		{

		public:
			ProgressBar(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~ProgressBar()                  = default;
			ProgressBar(const ProgressBar&)            = default;
			ProgressBar& operator=(const ProgressBar&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			ProgressBar(ProgressBar&&)                 = default;
			ProgressBar& operator=(ProgressBar&&)      = default;
#endif

			virtual void postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) override;
			static void JSExportInitialize();

			virtual void set_message(const std::string&) TITANIUM_NOEXCEPT override;
			virtual void set_min(const double&)   TITANIUM_NOEXCEPT override;
			virtual void set_max(const double&)   TITANIUM_NOEXCEPT override;
			virtual void set_value(const double&) TITANIUM_NOEXCEPT override;
			virtual void set_color(const std::string&) TITANIUM_NOEXCEPT override;

		private:
			Windows::UI::Xaml::Controls::StackPanel^ panel__;
			Windows::UI::Xaml::Controls::ProgressBar^ bar__;
			Windows::UI::Xaml::Controls::TextBlock^ label__;

		};
	}  // namespace UI
}  // namespace TitaniumWindows
#endif // _TITANIUMWINDOWS_PROGRESSBAR_HPP_