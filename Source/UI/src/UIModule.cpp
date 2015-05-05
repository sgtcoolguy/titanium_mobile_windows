/**
* Titanium.UI for Windows
*
* Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/
#include "Titanium/detail/TiBase.hpp"
#include "TitaniumWindows/UIModule.hpp"
#include "TitaniumWindows/UI/WindowsModule.hpp"
#include "TitaniumWindows/UI/WindowsViewLayoutDelegate.hpp"

#include "Windows.UI.Xaml.Window.hpp"
#include "Windows.UI.Xaml.Controls.Canvas.hpp"
#include "Windows.UI.Xaml.Controls.TextBlock.hpp"
#include "Windows.UI.Xaml.Controls.Page.hpp"

namespace TitaniumWindows
{

	using namespace TitaniumWindows::UI;

	UIModule::UIModule(const JSContext& js_context) TITANIUM_NOEXCEPT
		: Titanium::UIModule(js_context)
		, windows__(js_context.CreateObject(JSExport<TitaniumWindows::WindowsModule>::Class()))
	{
	}

	UIModule::~UIModule() TITANIUM_NOEXCEPT
	{
	}

	// Initialize Windows-specific UI types
	void UIModule::postInitialize(JSObject& js_object) 
	{
		Titanium::UIModule::postInitialize(js_object);
		js_object.SetProperty("Windows", windows__);

		// Hook up native wrappers!
		auto context = js_object.get_context();
		
		auto windows_ui_xaml_controls_canvas_object = context.CreateObject(JSExport<Titanium::Windows::UI::Xaml::Controls::Canvas>::Class());
		auto windows_ui_xaml_controls_textblock_object = context.CreateObject(JSExport<Titanium::Windows::UI::Xaml::Controls::TextBlock>::Class());
		auto windows_ui_xaml_controls_page_object = context.CreateObject(JSExport<Titanium::Windows::UI::Xaml::Controls::Page>::Class());

		auto windows_ui_xaml_controls_object = context.CreateObject();
		windows_ui_xaml_controls_object.SetProperty("Canvas", windows_ui_xaml_controls_canvas_object);
		windows_ui_xaml_controls_object.SetProperty("Page", windows_ui_xaml_controls_page_object);
		windows_ui_xaml_controls_object.SetProperty("TextBlock", windows_ui_xaml_controls_textblock_object);

		auto windows_ui_xaml_window_object = context.CreateObject(JSExport<Titanium::Windows::UI::Xaml::Window>::Class());

		auto windows_ui_xaml_object = context.CreateObject();
		windows_ui_xaml_object.SetProperty("Controls", windows_ui_xaml_controls_object);
		windows_ui_xaml_object.SetProperty("Window", windows_ui_xaml_window_object);

		auto windows_ui_object = context.CreateObject();
		windows_ui_object.SetProperty("Xaml", windows_ui_xaml_object);

		auto windows_object = context.CreateObject();
		windows_object.SetProperty("UI", windows_ui_object);

		auto global = context.get_global_object();
		global.SetProperty("Windows", windows_object);

	}

	void UIModule::JSExportInitialize() {
		JSExport<UIModule>::SetClassVersion(1);
		JSExport<UIModule>::SetParent(JSExport<Titanium::UIModule>::Class());
	}

	void UIModule::set_backgroundColor(const std::string& color) TITANIUM_NOEXCEPT
	{
		Titanium::UIModule::set_backgroundColor(color);
		auto rootFrame = dynamic_cast<Windows::UI::Xaml::Controls::Frame ^>(Windows::UI::Xaml::Window::Current->Content);
		if (rootFrame != nullptr) {
			rootFrame->Background = ref new Windows::UI::Xaml::Media::SolidColorBrush(WindowsViewLayoutDelegate::ColorForName(color));
		}
	}

}  // namespace TitaniumWindows
