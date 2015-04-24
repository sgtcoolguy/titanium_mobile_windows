/**
* Windows.SystemIcon module
*
* Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/
#ifndef _TITANIUMWINDOWS_WINDOWS_SYSTEMICON_HPP_
#define _TITANIUMWINDOWS_WINDOWS_SYSTEMICON_HPP_

#include "Titanium/Module.hpp"
#include "TitaniumWindows/UI/detail/UIBase.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		namespace WindowsXaml 
		{
			using namespace HAL;

			/*!
			  @class

			  @discussion This is the Titanium.UI.Windows implementation
			*/
			class TITANIUMWINDOWS_UI_EXPORT SystemIcon final : public Titanium::Module, public JSExport<SystemIcon>
			{

			public:
				SystemIcon(const JSContext&) TITANIUM_NOEXCEPT;

				virtual ~SystemIcon()                    = default;
				SystemIcon(const SystemIcon&)            = default;
				SystemIcon& operator=(const SystemIcon&) = default;
	#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
				SystemIcon(SystemIcon&&)                 = default;
				SystemIcon& operator=(SystemIcon&&)      = default;
	#endif

				static void JSExportInitialize();

				virtual void postInitialize(JSObject& js_object) override;

				TITANIUM_PROPERTY_READONLY_DEF(CANCEL);
				TITANIUM_PROPERTY_READONLY_DEF(ACCEPT);
				TITANIUM_PROPERTY_READONLY_DEF(BACK);
				TITANIUM_PROPERTY_READONLY_DEF(FORWARD);

			private:
				JSValue cancel__;
				JSValue accept__;
				JSValue back__;
				JSValue forward__;
			};
		} // namespace WindowsXaml
	}  // namespace UI
}  // namespace TitaniumWindows
#endif // _TITANIUMWINDOWS_WINDOWS_SYSTEMICON_HPP_