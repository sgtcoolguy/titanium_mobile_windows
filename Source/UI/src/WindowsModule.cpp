/**
* Windows module
*
* Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/
#include "TitaniumWindows/UI/WindowsModule.hpp"
#include "TitaniumWindows/UI/Windows/CommandBar.hpp"
#include "TitaniumWindows/UI/Windows/AppBarButton.hpp"
#include "TitaniumWindows/UI/Windows/AppBarToggleButton.hpp"
#include "TitaniumWindows/UI/Windows/AppBarSeparator.hpp"
#include "TitaniumWindows/UI/Windows/SystemIcon.hpp"

#define CREATE_TITANIUM_UI_WINDOWS(NAME) \
  JSValue Titanium_property = this_object.get_context().get_global_object().GetProperty("Titanium"); \
  TITANIUM_ASSERT(Titanium_property.IsObject()); \
  JSObject Titanium = static_cast<JSObject>(Titanium_property); \
  JSValue UI_property = Titanium.GetProperty("UI"); \
  TITANIUM_ASSERT(UI_property.IsObject()); \
  JSObject UI = static_cast<JSObject>(UI_property); \
  JSValue UI_WIN_property = UI.GetProperty("Windows"); \
  TITANIUM_ASSERT(UI_WIN_property.IsObject()); \
  JSObject UI_WIN = static_cast<JSObject>(UI_WIN_property); \
  JSValue NAME##_property = UI_WIN.GetProperty(#NAME); \
  TITANIUM_ASSERT(NAME##_property.IsObject()); \
  JSObject NAME = static_cast<JSObject>(NAME##_property); \
  auto NAME##_obj = NAME.CallAsConstructor(parameters); \
  applyProperties(parameters, NAME##_obj); \
  return NAME##_obj;

namespace TitaniumWindows
{
	namespace UI
	{
		using namespace ::Windows::UI::Xaml;

		WindowsModule::WindowsModule(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Module(js_context)
			, commandBar__(js_context.CreateObject(JSExport<TitaniumWindows::UI::WindowsXaml::CommandBar>::Class()))
			, appBarButton__(js_context.CreateObject(JSExport<TitaniumWindows::UI::WindowsXaml::AppBarButton>::Class()))
			, appBarToggleButton__(js_context.CreateObject(JSExport<TitaniumWindows::UI::WindowsXaml::AppBarToggleButton>::Class())) 
			, appBarSeparator__(js_context.CreateObject(JSExport<TitaniumWindows::UI::WindowsXaml::AppBarSeparator>::Class())) 
			, systemIcon__(js_context.CreateObject(JSExport<TitaniumWindows::UI::WindowsXaml::SystemIcon>::Class())) 
		{
			TITANIUM_LOG_DEBUG("WindowsModule::ctor Initialize");
		}

		void WindowsModule::postInitialize(JSObject& js_object) 
		{
			js_object.SetProperty("CommandBar", commandBar__);
			js_object.SetProperty("AppBarButton", appBarButton__);
			js_object.SetProperty("AppBarSeparator", appBarSeparator__);
			js_object.SetProperty("AppBarToggleButton", appBarToggleButton__);
			js_object.SetProperty("SystemIcon", systemIcon__);
		}

		void WindowsModule::JSExportInitialize() 
		{
			JSExport<WindowsModule>::SetClassVersion(1);
			JSExport<WindowsModule>::SetParent(JSExport<Titanium::Module>::Class());
			TITANIUM_ADD_FUNCTION(WindowsModule, createCommandBar);
			TITANIUM_ADD_FUNCTION(WindowsModule, createAppBarButton);
			TITANIUM_ADD_FUNCTION(WindowsModule, createAppBarToggleButton);
			TITANIUM_ADD_FUNCTION(WindowsModule, createAppBarSeparator);
		}

		TITANIUM_FUNCTION(WindowsModule, createCommandBar) 
		{
			ENSURE_OPTIONAL_OBJECT_AT_INDEX(parameters, 0);
			CREATE_TITANIUM_UI_WINDOWS(CommandBar);
		}

		TITANIUM_FUNCTION(WindowsModule, createAppBarButton) 
		{
			ENSURE_OPTIONAL_OBJECT_AT_INDEX(parameters, 0);
			CREATE_TITANIUM_UI_WINDOWS(AppBarButton);
		}

		TITANIUM_FUNCTION(WindowsModule, createAppBarToggleButton) 
		{
			ENSURE_OPTIONAL_OBJECT_AT_INDEX(parameters, 0);
			CREATE_TITANIUM_UI_WINDOWS(AppBarToggleButton);
		}

		TITANIUM_FUNCTION(WindowsModule, createAppBarSeparator) 
		{
			ENSURE_OPTIONAL_OBJECT_AT_INDEX(parameters, 0);
			CREATE_TITANIUM_UI_WINDOWS(AppBarSeparator);
		}

	}  // namespace UI
}  // namespace TitaniumWindows
