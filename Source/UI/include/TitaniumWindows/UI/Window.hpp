/**
 * Titanium.UI.Window for Windows
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_UI_WINDOW_HPP_
#define _TITANIUMWINDOWS_UI_WINDOW_HPP_

#include "TitaniumWindows_UI_EXPORT.h"
#include "Titanium/UI/Window.hpp"
#include "TitaniumWindows/UI/WindowsViewLayoutDelegate.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		using namespace HAL;

		namespace WindowsXaml
		{
			class CommandBar;
		}

		/*!
		  @class

		  @discussion This is the Titanium.UI.Window implementation for
		  Windows.
		*/
		class TITANIUMWINDOWS_UI_EXPORT Window final : public Titanium::UI::Window, public JSExport<Window>
		{
		public:
			TITANIUM_FUNCTION_DEF(add);

			virtual void close(const std::shared_ptr<Titanium::UI::CloseWindowParams>&) TITANIUM_NOEXCEPT override final;
			virtual void open(const std::shared_ptr<Titanium::UI::OpenWindowParams>&) TITANIUM_NOEXCEPT override final;
			virtual void set_fullscreen(const bool& fullscreen) TITANIUM_NOEXCEPT override final;

			Window(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~Window();
			Window(const Window&) = default;
			Window& operator=(const Window&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			Window(Window&&) = default;
			Window& operator=(Window&&) = default;
#endif

			static void JSExportInitialize();
			virtual void postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) override;

			virtual Windows::UI::Xaml::Controls::Canvas^ getComponent() const TITANIUM_NOEXCEPT
			{
				return canvas__;
			}

			virtual std::shared_ptr<TitaniumWindows::UI::WindowsXaml::CommandBar> getBottomAppBar() const TITANIUM_NOEXCEPT
			{
				return bottomAppBar__;
			}

			virtual void enableEvents()  TITANIUM_NOEXCEPT override;
			virtual void disableEvents() TITANIUM_NOEXCEPT override;

			virtual void enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT override;
			virtual void disableEvent(const std::string& event_name) TITANIUM_NOEXCEPT override;

			void updateWindowsCommandBar(const std::shared_ptr<TitaniumWindows::UI::WindowsXaml::CommandBar>& commandbar);

		private:
#pragma warning(push)
#pragma warning(disable : 4251)
			Windows::UI::Xaml::Controls::Canvas^ canvas__;
			static std::vector<std::shared_ptr<Window>> window_stack__;
			std::shared_ptr<TitaniumWindows::UI::WindowsXaml::CommandBar> bottomAppBar__;
			Windows::Foundation::EventRegistrationToken backpressed_event__;
			bool is_custom_backpress_event__ { false };
			bool is_window_event_active__ { false };
#pragma warning(pop)
		};

		class TITANIUMWINDOWS_UI_EXPORT WindowLayoutDelegate : public WindowsViewLayoutDelegate {
		public:
			WindowLayoutDelegate() TITANIUM_NOEXCEPT;
			virtual ~WindowLayoutDelegate() = default;

			virtual void onComponentSizeChange(const Titanium::LayoutEngine::Rect&) override;
			virtual void onLayoutEngineCallback(Titanium::LayoutEngine::Rect rect, const std::string& name) override;
		};
	} // namespace UI
} // namespace TitaniumWindows

#endif  // _TITANIUMWINDOWS_UI_WINDOW_HPP_
