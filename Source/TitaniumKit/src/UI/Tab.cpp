/**
 * TitaniumKit Titanium.UI.Tab
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/Tab.hpp"
#include "Titanium/detail/TiImpl.hpp"
#include "Titanium/UI/Window.hpp"
#include "Titanium/UI/OpenWindowParams.hpp"
#include "Titanium/UI/CloseWindowParams.hpp"

namespace Titanium
{
	namespace UI
	{
		Tab::Tab(const JSContext& js_context) TITANIUM_NOEXCEPT
			: View(js_context)
		{
		}

		TITANIUM_PROPERTY_READWRITE(Tab, std::string, backgroundDisabledColor)
		TITANIUM_PROPERTY_READWRITE(Tab, std::string, backgroundDisabledImage)
		TITANIUM_PROPERTY_READWRITE(Tab, std::string, backgroundFocusedColor)
		TITANIUM_PROPERTY_READWRITE(Tab, std::string, backgroundFocusedImage)
		TITANIUM_PROPERTY_READWRITE(Tab, std::string, backgroundImage)
		TITANIUM_PROPERTY_READWRITE(Tab, std::string, backgroundSelectedImage)
		TITANIUM_PROPERTY_READWRITE(Tab, bool, touchEnabled)
		TITANIUM_PROPERTY_READWRITE(Tab, std::string, backgroundColor)
		TITANIUM_PROPERTY_READWRITE(Tab, bool, active)
		TITANIUM_PROPERTY_READWRITE(Tab, std::string, activeIcon)
		TITANIUM_PROPERTY_READWRITE(Tab, std::string, badge)
		TITANIUM_PROPERTY_READWRITE(Tab, std::string, icon)
		TITANIUM_PROPERTY_READWRITE(Tab, bool, iconIsMask)
		TITANIUM_PROPERTY_READWRITE(Tab, bool, activeIconIsMask)
		TITANIUM_PROPERTY_READWRITE(Tab, std::string, title)
		TITANIUM_PROPERTY_READWRITE(Tab, std::string, titleid)
		TITANIUM_PROPERTY_READWRITE(Tab, std::shared_ptr<Window>, window)

		void Tab::open(const std::shared_ptr<OpenWindowParams>& options) TITANIUM_NOEXCEPT
		{
			if (window__) {
				window__->open(options);
			} else {
				TITANIUM_LOG_WARN("Tab::open() failed: no window is attached");
			}
		}

		void Tab::open(const std::shared_ptr<Window>& window, const std::shared_ptr<OpenWindowParams>& options) TITANIUM_NOEXCEPT
		{
			set_window(window);
			open(options);
		}

		void Tab::close(const std::shared_ptr<CloseWindowParams>& options) TITANIUM_NOEXCEPT
		{
			if (window__) {
				window__->close(options);
			} else {
				TITANIUM_LOG_WARN("Tab::close() failed: no window is attached");
			}
		}

		void Tab::close(const std::shared_ptr<Window>& window, const std::shared_ptr<CloseWindowParams>& options) TITANIUM_NOEXCEPT
		{
			set_window(window);
			close(options);
		}

		void Tab::JSExportInitialize() 
		{
			JSExport<Tab>::SetClassVersion(1);
			JSExport<Tab>::SetParent(JSExport<View>::Class());

			TITANIUM_ADD_PROPERTY(Tab, backgroundDisabledColor);
			TITANIUM_ADD_PROPERTY(Tab, backgroundDisabledImage);
			TITANIUM_ADD_PROPERTY(Tab, backgroundFocusedColor);
			TITANIUM_ADD_PROPERTY(Tab, backgroundFocusedImage);
			TITANIUM_ADD_PROPERTY(Tab, backgroundImage);
			TITANIUM_ADD_PROPERTY(Tab, backgroundSelectedImage);
			TITANIUM_ADD_PROPERTY(Tab, touchEnabled);
			TITANIUM_ADD_PROPERTY(Tab, backgroundColor);
			TITANIUM_ADD_PROPERTY(Tab, active);
			TITANIUM_ADD_PROPERTY(Tab, activeIcon);
			TITANIUM_ADD_PROPERTY(Tab, badge);
			TITANIUM_ADD_PROPERTY(Tab, icon);
			TITANIUM_ADD_PROPERTY(Tab, iconIsMask);
			TITANIUM_ADD_PROPERTY(Tab, activeIconIsMask);
			TITANIUM_ADD_PROPERTY(Tab, title);
			TITANIUM_ADD_PROPERTY(Tab, titleid);
			TITANIUM_ADD_PROPERTY(Tab, window);

			TITANIUM_ADD_FUNCTION(Tab, open);
			TITANIUM_ADD_FUNCTION(Tab, close);
			TITANIUM_ADD_FUNCTION(Tab, getBackgroundDisabledColor);
			TITANIUM_ADD_FUNCTION(Tab, setBackgroundDisabledColor);
			TITANIUM_ADD_FUNCTION(Tab, getBackgroundDisabledImage);
			TITANIUM_ADD_FUNCTION(Tab, setBackgroundDisabledImage);
			TITANIUM_ADD_FUNCTION(Tab, getBackgroundFocusedColor);
			TITANIUM_ADD_FUNCTION(Tab, setBackgroundFocusedColor);
			TITANIUM_ADD_FUNCTION(Tab, getBackgroundFocusedImage);
			TITANIUM_ADD_FUNCTION(Tab, setBackgroundFocusedImage);
			TITANIUM_ADD_FUNCTION(Tab, getBackgroundImage);
			TITANIUM_ADD_FUNCTION(Tab, setBackgroundImage);
			TITANIUM_ADD_FUNCTION(Tab, getBackgroundSelectedImage);
			TITANIUM_ADD_FUNCTION(Tab, setBackgroundSelectedImage);
			TITANIUM_ADD_FUNCTION(Tab, getTouchEnabled);
			TITANIUM_ADD_FUNCTION(Tab, setTouchEnabled);
			TITANIUM_ADD_FUNCTION(Tab, getBackgroundColor);
			TITANIUM_ADD_FUNCTION(Tab, setBackgroundColor);
			TITANIUM_ADD_FUNCTION(Tab, getActive);
			TITANIUM_ADD_FUNCTION(Tab, setActive);
			TITANIUM_ADD_FUNCTION(Tab, getActiveIcon);
			TITANIUM_ADD_FUNCTION(Tab, setActiveIcon);
			TITANIUM_ADD_FUNCTION(Tab, getBadge);
			TITANIUM_ADD_FUNCTION(Tab, setBadge);
			TITANIUM_ADD_FUNCTION(Tab, getIcon);
			TITANIUM_ADD_FUNCTION(Tab, setIcon);
			TITANIUM_ADD_FUNCTION(Tab, getIconIsMask);
			TITANIUM_ADD_FUNCTION(Tab, setIconIsMask);
			TITANIUM_ADD_FUNCTION(Tab, getActiveIconIsMask);
			TITANIUM_ADD_FUNCTION(Tab, setActiveIconIsMask);
			TITANIUM_ADD_FUNCTION(Tab, getTitle);
			TITANIUM_ADD_FUNCTION(Tab, setTitle);
			TITANIUM_ADD_FUNCTION(Tab, getTitleid);
			TITANIUM_ADD_FUNCTION(Tab, setTitleid);
			TITANIUM_ADD_FUNCTION(Tab, getWindow);
			TITANIUM_ADD_FUNCTION(Tab, setWindow);
		}

		TITANIUM_PROPERTY_GETTER(Tab, backgroundDisabledColor)
		{
			return get_context().CreateString(get_backgroundDisabledColor());
		}

		TITANIUM_PROPERTY_SETTER(Tab, backgroundDisabledColor)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_backgroundDisabledColor(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Tab, backgroundDisabledImage)
		{
			return get_context().CreateString(get_backgroundDisabledImage());
		}

		TITANIUM_PROPERTY_SETTER(Tab, backgroundDisabledImage)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_backgroundDisabledImage(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Tab, backgroundFocusedColor)
		{
			return get_context().CreateString(get_backgroundFocusedColor());
		}

		TITANIUM_PROPERTY_SETTER(Tab, backgroundFocusedColor)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_backgroundFocusedColor(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Tab, backgroundFocusedImage)
		{
			return get_context().CreateString(get_backgroundFocusedImage());
		}

		TITANIUM_PROPERTY_SETTER(Tab, backgroundFocusedImage)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_backgroundFocusedImage(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Tab, backgroundImage)
		{
			return get_context().CreateString(get_backgroundImage());
		}

		TITANIUM_PROPERTY_SETTER(Tab, backgroundImage)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_backgroundImage(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Tab, backgroundSelectedImage)
		{
			return get_context().CreateString(get_backgroundSelectedImage());
		}

		TITANIUM_PROPERTY_SETTER(Tab, backgroundSelectedImage)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_backgroundSelectedImage(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Tab, touchEnabled)
		{
			return get_context().CreateBoolean(get_touchEnabled());
		}

		TITANIUM_PROPERTY_SETTER(Tab, touchEnabled)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_touchEnabled(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Tab, backgroundColor)
		{
			return get_context().CreateString(get_backgroundColor());
		}

		TITANIUM_PROPERTY_SETTER(Tab, backgroundColor)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_backgroundColor(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Tab, active)
		{
			return get_context().CreateBoolean(get_active());
		}

		TITANIUM_PROPERTY_SETTER(Tab, active)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_active(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Tab, activeIcon)
		{
			return get_context().CreateString(get_activeIcon());
		}

		TITANIUM_PROPERTY_SETTER(Tab, activeIcon)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_activeIcon(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Tab, badge)
		{
			return get_context().CreateString(get_badge());
		}

		TITANIUM_PROPERTY_SETTER(Tab, badge)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_badge(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Tab, icon)
		{
			return get_context().CreateString(get_icon());
		}

		TITANIUM_PROPERTY_SETTER(Tab, icon)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_icon(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Tab, iconIsMask)
		{
			return get_context().CreateBoolean(get_iconIsMask());
		}

		TITANIUM_PROPERTY_SETTER(Tab, iconIsMask)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_iconIsMask(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Tab, activeIconIsMask)
		{
			return get_context().CreateBoolean(get_activeIconIsMask());
		}

		TITANIUM_PROPERTY_SETTER(Tab, activeIconIsMask)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_activeIconIsMask(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Tab, title)
		{
			return get_context().CreateString(get_title());
		}

		TITANIUM_PROPERTY_SETTER(Tab, title)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_title(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Tab, titleid)
		{
			return get_context().CreateString(get_titleid());
		}

		TITANIUM_PROPERTY_SETTER(Tab, titleid)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_titleid(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Tab, window)
		{
			const auto window = get_window();
			if (window) {
				return window->get_object();
			} else {
				return get_context().CreateNull();
			}
		}

		TITANIUM_PROPERTY_SETTER(Tab, window)
		{
			TITANIUM_ASSERT(argument.IsObject());
			set_window(static_cast<JSObject>(argument).GetPrivate<Window>());
			return true;
		}

		TITANIUM_FUNCTION(Tab, open)
		{
			ENSURE_OBJECT_AT_INDEX(window, 0);
			ENSURE_OPTIONAL_OBJECT_AT_INDEX(options, 1);

			open(window.GetPrivate<Window>(), options.GetPrivate<OpenWindowParams>());

			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Tab, close)
		{
			ENSURE_OBJECT_AT_INDEX(window, 0);
			ENSURE_OPTIONAL_OBJECT_AT_INDEX(options, 1);

			close(window.GetPrivate<Window>(), options.GetPrivate<CloseWindowParams>());

			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION_AS_GETTER(Tab, getBackgroundDisabledColor, backgroundDisabledColor)
		TITANIUM_FUNCTION_AS_SETTER(Tab, setBackgroundDisabledColor, backgroundDisabledColor)
		TITANIUM_FUNCTION_AS_GETTER(Tab, getBackgroundDisabledImage, backgroundDisabledImage)
		TITANIUM_FUNCTION_AS_SETTER(Tab, setBackgroundDisabledImage, backgroundDisabledImage)
		TITANIUM_FUNCTION_AS_GETTER(Tab, getBackgroundFocusedColor, backgroundFocusedColor)
		TITANIUM_FUNCTION_AS_SETTER(Tab, setBackgroundFocusedColor, backgroundFocusedColor)
		TITANIUM_FUNCTION_AS_GETTER(Tab, getBackgroundFocusedImage, backgroundFocusedImage)
		TITANIUM_FUNCTION_AS_SETTER(Tab, setBackgroundFocusedImage, backgroundFocusedImage)
		TITANIUM_FUNCTION_AS_GETTER(Tab, getBackgroundImage, backgroundImage)
		TITANIUM_FUNCTION_AS_SETTER(Tab, setBackgroundImage, backgroundImage)
		TITANIUM_FUNCTION_AS_GETTER(Tab, getBackgroundSelectedImage, backgroundSelectedImage)
		TITANIUM_FUNCTION_AS_SETTER(Tab, setBackgroundSelectedImage, backgroundSelectedImage)
		TITANIUM_FUNCTION_AS_GETTER(Tab, getTouchEnabled, touchEnabled)
		TITANIUM_FUNCTION_AS_SETTER(Tab, setTouchEnabled, touchEnabled)
		TITANIUM_FUNCTION_AS_GETTER(Tab, getBackgroundColor, backgroundColor)
		TITANIUM_FUNCTION_AS_SETTER(Tab, setBackgroundColor, backgroundColor)
		TITANIUM_FUNCTION_AS_GETTER(Tab, getActive, active)
		TITANIUM_FUNCTION_AS_SETTER(Tab, setActive, active)
		TITANIUM_FUNCTION_AS_GETTER(Tab, getActiveIcon, activeIcon)
		TITANIUM_FUNCTION_AS_SETTER(Tab, setActiveIcon, activeIcon)
		TITANIUM_FUNCTION_AS_GETTER(Tab, getBadge, badge)
		TITANIUM_FUNCTION_AS_SETTER(Tab, setBadge, badge)
		TITANIUM_FUNCTION_AS_GETTER(Tab, getIcon, icon)
		TITANIUM_FUNCTION_AS_SETTER(Tab, setIcon, icon)
		TITANIUM_FUNCTION_AS_GETTER(Tab, getIconIsMask, iconIsMask)
		TITANIUM_FUNCTION_AS_SETTER(Tab, setIconIsMask, iconIsMask)
		TITANIUM_FUNCTION_AS_GETTER(Tab, getActiveIconIsMask, activeIconIsMask)
		TITANIUM_FUNCTION_AS_SETTER(Tab, setActiveIconIsMask, activeIconIsMask)
		TITANIUM_FUNCTION_AS_GETTER(Tab, getTitle, title)
		TITANIUM_FUNCTION_AS_SETTER(Tab, setTitle, title)
		TITANIUM_FUNCTION_AS_GETTER(Tab, getTitleid, titleid)
		TITANIUM_FUNCTION_AS_SETTER(Tab, setTitleid, titleid)
		TITANIUM_FUNCTION_AS_GETTER(Tab, getWindow, window)
		TITANIUM_FUNCTION_AS_SETTER(Tab, setWindow, window)

	} // namespace UI
} // namespace Titanium