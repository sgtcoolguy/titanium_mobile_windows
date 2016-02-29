/**
* Ti.App.Windows module
*
* Copyright (c) 2016 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/
#include "TitaniumWindows/App/WindowsModule.hpp"
#include "TitaniumWindows/App/BackgroundService.hpp"
#include "Titanium/detail/TiImpl.hpp"

#define CREATE_TITANIUM_APP_WINDOWS(NAME) \
  JSValue Titanium_property = this_object.get_context().get_global_object().GetProperty("Titanium"); \
  TITANIUM_ASSERT(Titanium_property.IsObject()); \
  JSObject Titanium = static_cast<JSObject>(Titanium_property); \
  JSValue App_property = Titanium.GetProperty("App"); \
  TITANIUM_ASSERT(App_property.IsObject()); \
  JSObject App = static_cast<JSObject>(App_property); \
  JSValue App_WIN_property = App.GetProperty("Windows"); \
  TITANIUM_ASSERT(App_WIN_property.IsObject()); \
  JSObject App_WIN = static_cast<JSObject>(App_WIN_property); \
  JSValue NAME##_property = App_WIN.GetProperty(#NAME); \
  TITANIUM_ASSERT(NAME##_property.IsObject()); \
  JSObject NAME = static_cast<JSObject>(NAME##_property); \
  auto NAME##_obj = NAME.CallAsConstructor(parameters); \
  applyProperties(parameters, NAME##_obj); \
  return NAME##_obj;

namespace TitaniumWindows
{
	namespace App
	{
		using namespace ::Windows::UI::Xaml;

		WindowsModule::WindowsModule(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Module(js_context)
		{
			TITANIUM_LOG_DEBUG("App::WindowsModule::ctor Initialize");
		}

		void WindowsModule::JSExportInitialize() 
		{
			JSExport<WindowsModule>::SetClassVersion(1);
			JSExport<WindowsModule>::SetParent(JSExport<Titanium::Module>::Class());
			TITANIUM_ADD_CONSTANT_PROPERTY(WindowsModule, BackgroundService);
		}

		TITANIUM_PROPERTY_GETTER(WindowsModule, BackgroundService)
		{
			return get_context().CreateObject(JSExport<TitaniumWindows::App::WindowsXaml::BackgroundService>::Class());
		}

	}  // namespace UI
}  // namespace TitaniumWindows
