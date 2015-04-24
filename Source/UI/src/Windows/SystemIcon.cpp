/**
* Windows module
*
* Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/
#include "TitaniumWindows/UI/Windows/SystemIcon.hpp"
#include "TitaniumWindows/UI/Windows/CommandBar.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		namespace WindowsXaml
		{
			using namespace Windows::UI::Xaml;

			SystemIcon::SystemIcon(const JSContext& js_context) TITANIUM_NOEXCEPT
				: Titanium::Module(js_context)
				, cancel__(js_context.CreateNumber(static_cast<std::uint32_t>(Controls::Symbol::Cancel)))
				, accept__(js_context.CreateNumber(static_cast<std::uint32_t>(Controls::Symbol::Accept))) 
				, back__(js_context.CreateNumber(static_cast<std::uint32_t>(Controls::Symbol::Back)))
				, forward__(js_context.CreateNumber(static_cast<std::uint32_t>(Controls::Symbol::Forward)))
			{
				TITANIUM_LOG_DEBUG("SystemIcon::ctor Initialize");
			}

			void SystemIcon::postInitialize(JSObject& js_object) 
			{
				TITANIUM_LOG_DEBUG("SystemIcon::postInitialize");
			}

			void SystemIcon::JSExportInitialize() 
			{
				JSExport<SystemIcon>::SetClassVersion(1);
				JSExport<SystemIcon>::SetParent(JSExport<Titanium::Module>::Class());
				TITANIUM_ADD_PROPERTY_READONLY(SystemIcon, CANCEL);
				TITANIUM_ADD_PROPERTY_READONLY(SystemIcon, ACCEPT);
				TITANIUM_ADD_PROPERTY_READONLY(SystemIcon, BACK);
				TITANIUM_ADD_PROPERTY_READONLY(SystemIcon, FORWARD);
			}

			TITANIUM_PROPERTY_GETTER(SystemIcon, CANCEL)
			{
				return cancel__;
			}

			TITANIUM_PROPERTY_GETTER(SystemIcon, ACCEPT)
			{
				return accept__;
			}

			TITANIUM_PROPERTY_GETTER(SystemIcon, BACK)
			{
				return back__;
			}

			TITANIUM_PROPERTY_GETTER(SystemIcon, FORWARD)
			{
				return forward__;
			}

		}  // namespace WindowsXaml
	}  // namespace UI
}  // namespace TitaniumWindows
