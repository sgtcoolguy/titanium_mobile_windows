/**
 * TitaniumKit Titanium.UI.TabGroup
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/TabGroup.hpp"
#include "Titanium/detail/TiImpl.hpp"
#include "Titanium/UI/Tab.hpp"

namespace Titanium
{
	namespace UI
	{
		TabGroup::TabGroup(const JSContext& js_context) TITANIUM_NOEXCEPT
			: View(js_context)
			, activity__(js_context.CreateUndefined())
		{
		}

		TITANIUM_PROPERTY_READWRITE(TabGroup, std::shared_ptr<Tab>, activeTab)
		TITANIUM_PROPERTY_READ(TabGroup, JSValue, activity)
		TITANIUM_PROPERTY_READWRITE(TabGroup, bool, allowUserCustomization)
		TITANIUM_PROPERTY_READWRITE(TabGroup, std::string, barColor)
		TITANIUM_PROPERTY_READWRITE(TabGroup, bool, translucent)
		TITANIUM_PROPERTY_READWRITE(TabGroup, TitleAttributesParams, titleAttributes)
		TITANIUM_PROPERTY_READWRITE(TabGroup, std::string, navTintColor)
		TITANIUM_PROPERTY_READWRITE(TabGroup, std::string, editButtonTitle)
		TITANIUM_PROPERTY_READWRITE(TabGroup, bool, exitOnClose)
		TITANIUM_PROPERTY_READWRITE(TabGroup, bool, navBarHidden)
		TITANIUM_PROPERTY_READWRITE(TabGroup, bool, swipeable)
		TITANIUM_PROPERTY_READWRITE(TabGroup, bool, smoothScrollOnTabClick)
		TITANIUM_PROPERTY_READWRITE(TabGroup, std::vector<std::shared_ptr<Tab>>, tabs)
		TITANIUM_PROPERTY_READWRITE(TabGroup, double, windowSoftInputMode)
		TITANIUM_PROPERTY_READWRITE(TabGroup, std::string, tabsBackgroundColor)
		TITANIUM_PROPERTY_READWRITE(TabGroup, std::string, tabsTintColor)
		TITANIUM_PROPERTY_READWRITE(TabGroup, std::string, title)
		TITANIUM_PROPERTY_READWRITE(TabGroup, std::string, tabsBackgroundImage)
		TITANIUM_PROPERTY_READWRITE(TabGroup, std::string, shadowImage)
		TITANIUM_PROPERTY_READWRITE(TabGroup, std::string, activeTabIconTint)
		TITANIUM_PROPERTY_READWRITE(TabGroup, std::string, tabsBackgroundDisabledColor)
		TITANIUM_PROPERTY_READWRITE(TabGroup, std::string, tabsBackgroundDisabledImage)
		TITANIUM_PROPERTY_READWRITE(TabGroup, std::string, tabsBackgroundFocusedColor)
		TITANIUM_PROPERTY_READWRITE(TabGroup, std::string, tabsBackgroundFocusedImage)
		TITANIUM_PROPERTY_READWRITE(TabGroup, std::string, tabsBackgroundSelectedColor)
		TITANIUM_PROPERTY_READWRITE(TabGroup, std::string, tabsBackgroundSelectedImage)
		TITANIUM_PROPERTY_READWRITE(TabGroup, std::string, activeTabBackgroundColor)
		TITANIUM_PROPERTY_READWRITE(TabGroup, std::string, activeTabBackgroundImage)
		TITANIUM_PROPERTY_READWRITE(TabGroup, std::string, activeTabBackgroundDisabledColor)
		TITANIUM_PROPERTY_READWRITE(TabGroup, std::string, activeTabBackgroundDisabledImage)
		TITANIUM_PROPERTY_READWRITE(TabGroup, std::string, activeTabBackgroundFocusedColor)
		TITANIUM_PROPERTY_READWRITE(TabGroup, std::string, activeTabBackgroundFocusedImage)
		TITANIUM_PROPERTY_READWRITE(TabGroup, std::string, activeTabBackgroundSelectedColor)
		TITANIUM_PROPERTY_READWRITE(TabGroup, std::string, activeTabBackgroundSelectedImage)
		TITANIUM_PROPERTY_READWRITE(TabGroup, std::string, tabDividerColor)
		TITANIUM_PROPERTY_READWRITE(TabGroup, std::string, tabDividerWidth)
		TITANIUM_PROPERTY_READWRITE(TabGroup, std::string, tabHeight)
		TITANIUM_PROPERTY_READWRITE(TabGroup, bool, tabsAtBottom)

		void TabGroup::addTab(const std::shared_ptr<Tab>& tab) TITANIUM_NOEXCEPT
		{
			tabs__.push_back(tab);
		}

		void TabGroup::close() TITANIUM_NOEXCEPT
		{
			if (activeTab__) {
				activeTab__->close();
				activeTab__ = nullptr;
			} else {
				TITANIUM_LOG_WARN("TabGroup::close() failed: no active window");
			}
		}

		void TabGroup::disableTabNavigation(const bool& disable) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TabGroup::disableTabNavigation: Unimplemented");
		}

		void TabGroup::open() TITANIUM_NOEXCEPT
		{
			if (tabs__.size() > 0 && activeTab__ == nullptr) {
				activeTab__ = tabs__.at(0);
			}
			if (activeTab__) {
				activeTab__->open();
			} else {
				TITANIUM_LOG_WARN("TabGroup::open() failed: no window attached");
			}
		}

		void TabGroup::removeTab(const std::shared_ptr<Tab>& tab) TITANIUM_NOEXCEPT
		{
			tabs__.erase(find(tabs__.begin(), tabs__.end(), tab));
		}

		void TabGroup::JSExportInitialize() 
		{
			JSExport<TabGroup>::SetClassVersion(1);
			JSExport<TabGroup>::SetParent(JSExport<View>::Class());

			TITANIUM_ADD_PROPERTY(TabGroup, activeTab);
			TITANIUM_ADD_PROPERTY_READONLY(TabGroup, activity);
			TITANIUM_ADD_PROPERTY(TabGroup, allowUserCustomization);
			TITANIUM_ADD_PROPERTY(TabGroup, barColor);
			TITANIUM_ADD_PROPERTY(TabGroup, translucent);
			TITANIUM_ADD_PROPERTY(TabGroup, titleAttributes);
			TITANIUM_ADD_PROPERTY(TabGroup, navTintColor);
			TITANIUM_ADD_PROPERTY(TabGroup, editButtonTitle);
			TITANIUM_ADD_PROPERTY(TabGroup, exitOnClose);
			TITANIUM_ADD_PROPERTY(TabGroup, navBarHidden);
			TITANIUM_ADD_PROPERTY(TabGroup, swipeable);
			TITANIUM_ADD_PROPERTY(TabGroup, smoothScrollOnTabClick);
			TITANIUM_ADD_PROPERTY(TabGroup, tabs);
			TITANIUM_ADD_PROPERTY(TabGroup, windowSoftInputMode);
			TITANIUM_ADD_PROPERTY(TabGroup, tabsBackgroundColor);
			TITANIUM_ADD_PROPERTY(TabGroup, tabsTintColor);
			TITANIUM_ADD_PROPERTY(TabGroup, title);
			TITANIUM_ADD_PROPERTY(TabGroup, tabsBackgroundImage);
			TITANIUM_ADD_PROPERTY(TabGroup, shadowImage);
			TITANIUM_ADD_PROPERTY(TabGroup, activeTabIconTint);
			TITANIUM_ADD_PROPERTY(TabGroup, tabsBackgroundDisabledColor);
			TITANIUM_ADD_PROPERTY(TabGroup, tabsBackgroundDisabledImage);
			TITANIUM_ADD_PROPERTY(TabGroup, tabsBackgroundFocusedColor);
			TITANIUM_ADD_PROPERTY(TabGroup, tabsBackgroundFocusedImage);
			TITANIUM_ADD_PROPERTY(TabGroup, tabsBackgroundSelectedColor);
			TITANIUM_ADD_PROPERTY(TabGroup, tabsBackgroundSelectedImage);
			TITANIUM_ADD_PROPERTY(TabGroup, activeTabBackgroundColor);
			TITANIUM_ADD_PROPERTY(TabGroup, activeTabBackgroundImage);
			TITANIUM_ADD_PROPERTY(TabGroup, activeTabBackgroundDisabledColor);
			TITANIUM_ADD_PROPERTY(TabGroup, activeTabBackgroundDisabledImage);
			TITANIUM_ADD_PROPERTY(TabGroup, activeTabBackgroundFocusedColor);
			TITANIUM_ADD_PROPERTY(TabGroup, activeTabBackgroundFocusedImage);
			TITANIUM_ADD_PROPERTY(TabGroup, activeTabBackgroundSelectedColor);
			TITANIUM_ADD_PROPERTY(TabGroup, activeTabBackgroundSelectedImage);
			TITANIUM_ADD_PROPERTY(TabGroup, tabDividerColor);
			TITANIUM_ADD_PROPERTY(TabGroup, tabDividerWidth);
			TITANIUM_ADD_PROPERTY(TabGroup, tabHeight);
			TITANIUM_ADD_PROPERTY(TabGroup, tabsAtBottom);

			TITANIUM_ADD_FUNCTION(TabGroup, addTab);
			TITANIUM_ADD_FUNCTION(TabGroup, close);
			TITANIUM_ADD_FUNCTION(TabGroup, disableTabNavigation);
			TITANIUM_ADD_FUNCTION(TabGroup, open);
			TITANIUM_ADD_FUNCTION(TabGroup, removeTab);
			TITANIUM_ADD_FUNCTION(TabGroup, getActiveTab);
			TITANIUM_ADD_FUNCTION(TabGroup, setActiveTab);
			TITANIUM_ADD_FUNCTION(TabGroup, getActivity);
			TITANIUM_ADD_FUNCTION(TabGroup, getAllowUserCustomization);
			TITANIUM_ADD_FUNCTION(TabGroup, setAllowUserCustomization);
			TITANIUM_ADD_FUNCTION(TabGroup, getBarColor);
			TITANIUM_ADD_FUNCTION(TabGroup, setBarColor);
			TITANIUM_ADD_FUNCTION(TabGroup, getTranslucent);
			TITANIUM_ADD_FUNCTION(TabGroup, setTranslucent);
			TITANIUM_ADD_FUNCTION(TabGroup, getTitleAttributes);
			TITANIUM_ADD_FUNCTION(TabGroup, setTitleAttributes);
			TITANIUM_ADD_FUNCTION(TabGroup, getNavTintColor);
			TITANIUM_ADD_FUNCTION(TabGroup, setNavTintColor);
			TITANIUM_ADD_FUNCTION(TabGroup, getEditButtonTitle);
			TITANIUM_ADD_FUNCTION(TabGroup, setEditButtonTitle);
			TITANIUM_ADD_FUNCTION(TabGroup, getExitOnClose);
			TITANIUM_ADD_FUNCTION(TabGroup, setExitOnClose);
			TITANIUM_ADD_FUNCTION(TabGroup, getNavBarHidden);
			TITANIUM_ADD_FUNCTION(TabGroup, setNavBarHidden);
			TITANIUM_ADD_FUNCTION(TabGroup, getSwipeable);
			TITANIUM_ADD_FUNCTION(TabGroup, setSwipeable);
			TITANIUM_ADD_FUNCTION(TabGroup, getSmoothScrollOnTabClick);
			TITANIUM_ADD_FUNCTION(TabGroup, setSmoothScrollOnTabClick);
			TITANIUM_ADD_FUNCTION(TabGroup, getTabs);
			TITANIUM_ADD_FUNCTION(TabGroup, setTabs);
			TITANIUM_ADD_FUNCTION(TabGroup, getWindowSoftInputMode);
			TITANIUM_ADD_FUNCTION(TabGroup, setWindowSoftInputMode);
			TITANIUM_ADD_FUNCTION(TabGroup, getTabsBackgroundColor);
			TITANIUM_ADD_FUNCTION(TabGroup, setTabsBackgroundColor);
			TITANIUM_ADD_FUNCTION(TabGroup, getTabsTintColor);
			TITANIUM_ADD_FUNCTION(TabGroup, setTabsTintColor);
			TITANIUM_ADD_FUNCTION(TabGroup, getTitle);
			TITANIUM_ADD_FUNCTION(TabGroup, setTitle);
			TITANIUM_ADD_FUNCTION(TabGroup, getTabsBackgroundImage);
			TITANIUM_ADD_FUNCTION(TabGroup, setTabsBackgroundImage);
			TITANIUM_ADD_FUNCTION(TabGroup, getShadowImage);
			TITANIUM_ADD_FUNCTION(TabGroup, setShadowImage);
			TITANIUM_ADD_FUNCTION(TabGroup, getActiveTabIconTint);
			TITANIUM_ADD_FUNCTION(TabGroup, setActiveTabIconTint);
			TITANIUM_ADD_FUNCTION(TabGroup, getTabsBackgroundDisabledColor);
			TITANIUM_ADD_FUNCTION(TabGroup, setTabsBackgroundDisabledColor);
			TITANIUM_ADD_FUNCTION(TabGroup, getTabsBackgroundDisabledImage);
			TITANIUM_ADD_FUNCTION(TabGroup, setTabsBackgroundDisabledImage);
			TITANIUM_ADD_FUNCTION(TabGroup, getTabsBackgroundFocusedColor);
			TITANIUM_ADD_FUNCTION(TabGroup, setTabsBackgroundFocusedColor);
			TITANIUM_ADD_FUNCTION(TabGroup, getTabsBackgroundFocusedImage);
			TITANIUM_ADD_FUNCTION(TabGroup, setTabsBackgroundFocusedImage);
			TITANIUM_ADD_FUNCTION(TabGroup, getTabsBackgroundSelectedColor);
			TITANIUM_ADD_FUNCTION(TabGroup, setTabsBackgroundSelectedColor);
			TITANIUM_ADD_FUNCTION(TabGroup, getTabsBackgroundSelectedImage);
			TITANIUM_ADD_FUNCTION(TabGroup, setTabsBackgroundSelectedImage);
			TITANIUM_ADD_FUNCTION(TabGroup, getActiveTabBackgroundColor);
			TITANIUM_ADD_FUNCTION(TabGroup, setActiveTabBackgroundColor);
			TITANIUM_ADD_FUNCTION(TabGroup, getActiveTabBackgroundImage);
			TITANIUM_ADD_FUNCTION(TabGroup, setActiveTabBackgroundImage);
			TITANIUM_ADD_FUNCTION(TabGroup, getActiveTabBackgroundDisabledColor);
			TITANIUM_ADD_FUNCTION(TabGroup, setActiveTabBackgroundDisabledColor);
			TITANIUM_ADD_FUNCTION(TabGroup, getActiveTabBackgroundDisabledImage);
			TITANIUM_ADD_FUNCTION(TabGroup, setActiveTabBackgroundDisabledImage);
			TITANIUM_ADD_FUNCTION(TabGroup, getActiveTabBackgroundFocusedColor);
			TITANIUM_ADD_FUNCTION(TabGroup, setActiveTabBackgroundFocusedColor);
			TITANIUM_ADD_FUNCTION(TabGroup, getActiveTabBackgroundFocusedImage);
			TITANIUM_ADD_FUNCTION(TabGroup, setActiveTabBackgroundFocusedImage);
			TITANIUM_ADD_FUNCTION(TabGroup, getActiveTabBackgroundSelectedColor);
			TITANIUM_ADD_FUNCTION(TabGroup, setActiveTabBackgroundSelectedColor);
			TITANIUM_ADD_FUNCTION(TabGroup, getActiveTabBackgroundSelectedImage);
			TITANIUM_ADD_FUNCTION(TabGroup, setActiveTabBackgroundSelectedImage);
			TITANIUM_ADD_FUNCTION(TabGroup, getTabDividerColor);
			TITANIUM_ADD_FUNCTION(TabGroup, setTabDividerColor);
			TITANIUM_ADD_FUNCTION(TabGroup, getTabDividerWidth);
			TITANIUM_ADD_FUNCTION(TabGroup, setTabDividerWidth);
			TITANIUM_ADD_FUNCTION(TabGroup, getTabHeight);
			TITANIUM_ADD_FUNCTION(TabGroup, setTabHeight);
			TITANIUM_ADD_FUNCTION(TabGroup, getTabsAtBottom);
			TITANIUM_ADD_FUNCTION(TabGroup, setTabsAtBottom);
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, activeTab)
		{
			if (activeTab__ != nullptr) {
				return activeTab__->get_object();
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, activeTab)
		{
			TITANIUM_ASSERT(argument.IsObject());
			set_activeTab(static_cast<JSObject>(argument).GetPrivate<Tab>());
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, activity)
		{
			return activity__;
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, allowUserCustomization)
		{
			return get_context().CreateBoolean(get_allowUserCustomization());
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, allowUserCustomization)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_allowUserCustomization(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, barColor)
		{
			return get_context().CreateString(get_barColor());
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, barColor)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_barColor(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, translucent)
		{
			return get_context().CreateBoolean(get_translucent());
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, translucent)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_translucent(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, titleAttributes)
		{
			return TitleAttributesParams_to_js(get_context(), titleAttributes__);
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, titleAttributes)
		{
			TITANIUM_ASSERT(argument.IsObject());
			js_to_TitleAttributesParams(static_cast<JSObject>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, navTintColor)
		{
			return get_context().CreateString(get_navTintColor());
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, navTintColor)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_navTintColor(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, editButtonTitle)
		{
			return get_context().CreateString(get_editButtonTitle());
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, editButtonTitle)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_editButtonTitle(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, exitOnClose)
		{
			return get_context().CreateBoolean(get_exitOnClose());
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, exitOnClose)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_exitOnClose(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, navBarHidden)
		{
			return get_context().CreateBoolean(get_navBarHidden());
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, navBarHidden)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_navBarHidden(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, swipeable)
		{
			return get_context().CreateBoolean(get_swipeable());
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, swipeable)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_swipeable(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, smoothScrollOnTabClick)
		{
			return get_context().CreateBoolean(get_smoothScrollOnTabClick());
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, smoothScrollOnTabClick)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_smoothScrollOnTabClick(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER_OBJECT_ARRAY(TabGroup, tabs);
		TITANIUM_PROPERTY_SETTER_OBJECT_ARRAY(TabGroup, tabs, Titanium::UI::Tab);

		TITANIUM_PROPERTY_GETTER(TabGroup, windowSoftInputMode)
		{
			return get_context().CreateNumber(get_windowSoftInputMode());
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, windowSoftInputMode)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_windowSoftInputMode(static_cast<double>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, tabsBackgroundColor)
		{
			return get_context().CreateString(get_tabsBackgroundColor());
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, tabsBackgroundColor)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_tabsBackgroundColor(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, tabsTintColor)
		{
			return get_context().CreateString(get_tabsTintColor());
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, tabsTintColor)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_tabsTintColor(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, title)
		{
			return get_context().CreateString(get_title());
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, title)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_title(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, tabsBackgroundImage)
		{
			return get_context().CreateString(get_tabsBackgroundImage());
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, tabsBackgroundImage)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_tabsBackgroundImage(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, shadowImage)
		{
			return get_context().CreateString(get_shadowImage());
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, shadowImage)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_shadowImage(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, activeTabIconTint)
		{
			return get_context().CreateString(get_activeTabIconTint());
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, activeTabIconTint)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_activeTabIconTint(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, tabsBackgroundDisabledColor)
		{
			return get_context().CreateString(get_tabsBackgroundDisabledColor());
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, tabsBackgroundDisabledColor)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_tabsBackgroundDisabledColor(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, tabsBackgroundDisabledImage)
		{
			return get_context().CreateString(get_tabsBackgroundDisabledImage());
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, tabsBackgroundDisabledImage)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_tabsBackgroundDisabledImage(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, tabsBackgroundFocusedColor)
		{
			return get_context().CreateString(get_tabsBackgroundFocusedColor());
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, tabsBackgroundFocusedColor)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_tabsBackgroundFocusedColor(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, tabsBackgroundFocusedImage)
		{
			return get_context().CreateString(get_tabsBackgroundFocusedImage());
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, tabsBackgroundFocusedImage)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_tabsBackgroundFocusedImage(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, tabsBackgroundSelectedColor)
		{
			return get_context().CreateString(get_tabsBackgroundSelectedColor());
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, tabsBackgroundSelectedColor)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_tabsBackgroundSelectedColor(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, tabsBackgroundSelectedImage)
		{
			return get_context().CreateString(get_tabsBackgroundSelectedImage());
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, tabsBackgroundSelectedImage)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_tabsBackgroundSelectedImage(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, activeTabBackgroundColor)
		{
			return get_context().CreateString(get_activeTabBackgroundColor());
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, activeTabBackgroundColor)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_activeTabBackgroundColor(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, activeTabBackgroundImage)
		{
			return get_context().CreateString(get_activeTabBackgroundImage());
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, activeTabBackgroundImage)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_activeTabBackgroundImage(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, activeTabBackgroundDisabledColor)
		{
			return get_context().CreateString(get_activeTabBackgroundDisabledColor());
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, activeTabBackgroundDisabledColor)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_activeTabBackgroundDisabledColor(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, activeTabBackgroundDisabledImage)
		{
			return get_context().CreateString(get_activeTabBackgroundDisabledImage());
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, activeTabBackgroundDisabledImage)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_activeTabBackgroundDisabledImage(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, activeTabBackgroundFocusedColor)
		{
			return get_context().CreateString(get_activeTabBackgroundFocusedColor());
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, activeTabBackgroundFocusedColor)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_activeTabBackgroundFocusedColor(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, activeTabBackgroundFocusedImage)
		{
			return get_context().CreateString(get_activeTabBackgroundFocusedImage());
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, activeTabBackgroundFocusedImage)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_activeTabBackgroundFocusedImage(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, activeTabBackgroundSelectedColor)
		{
			return get_context().CreateString(get_activeTabBackgroundSelectedColor());
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, activeTabBackgroundSelectedColor)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_activeTabBackgroundSelectedColor(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, activeTabBackgroundSelectedImage)
		{
			return get_context().CreateString(get_activeTabBackgroundSelectedImage());
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, activeTabBackgroundSelectedImage)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_activeTabBackgroundSelectedImage(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TabGroup, tabDividerColor)
		{
			return get_context().CreateString(get_tabDividerColor());
		}

		TITANIUM_PROPERTY_SETTER(TabGroup, tabDividerColor)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_tabDividerColor(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER_STRING(TabGroup, tabDividerWidth);
		TITANIUM_PROPERTY_SETTER_STRING(TabGroup, tabDividerWidth);

		TITANIUM_PROPERTY_GETTER_STRING(TabGroup, tabHeight);
		TITANIUM_PROPERTY_SETTER_STRING(TabGroup, tabHeight);

		TITANIUM_PROPERTY_GETTER_BOOL(TabGroup, tabsAtBottom);
		TITANIUM_PROPERTY_SETTER_BOOL(TabGroup, tabsAtBottom);

		TITANIUM_FUNCTION(TabGroup, addTab)
		{
			ENSURE_OBJECT_AT_INDEX(tab, 0);
			addTab(tab.GetPrivate<Tab>());
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TabGroup, close)
		{
			close();
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TabGroup, disableTabNavigation)
		{
			ENSURE_BOOL_AT_INDEX(disable, 0);
			disableTabNavigation(disable);
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TabGroup, open)
		{
			open();
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TabGroup, removeTab)
		{
			ENSURE_OBJECT_AT_INDEX(tab, 0);
			removeTab(tab.GetPrivate<Tab>());
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getActiveTab, activeTab)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setActiveTab, activeTab)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getActivity, activity)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getAllowUserCustomization, allowUserCustomization)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setAllowUserCustomization, allowUserCustomization)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getBarColor, barColor)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setBarColor, barColor)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getTranslucent, translucent)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setTranslucent, translucent)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getTitleAttributes, titleAttributes)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setTitleAttributes, titleAttributes)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getNavTintColor, navTintColor)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setNavTintColor, navTintColor)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getEditButtonTitle, editButtonTitle)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setEditButtonTitle, editButtonTitle)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getExitOnClose, exitOnClose)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setExitOnClose, exitOnClose)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getNavBarHidden, navBarHidden)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setNavBarHidden, navBarHidden)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getSwipeable, swipeable)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setSwipeable, swipeable)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getSmoothScrollOnTabClick, smoothScrollOnTabClick)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setSmoothScrollOnTabClick, smoothScrollOnTabClick)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getTabs, tabs)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setTabs, tabs)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getWindowSoftInputMode, windowSoftInputMode)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setWindowSoftInputMode, windowSoftInputMode)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getTabsBackgroundColor, tabsBackgroundColor)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setTabsBackgroundColor, tabsBackgroundColor)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getTabsTintColor, tabsTintColor)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setTabsTintColor, tabsTintColor)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getTitle, title)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setTitle, title)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getTabsBackgroundImage, tabsBackgroundImage)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setTabsBackgroundImage, tabsBackgroundImage)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getShadowImage, shadowImage)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setShadowImage, shadowImage)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getActiveTabIconTint, activeTabIconTint)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setActiveTabIconTint, activeTabIconTint)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getTabsBackgroundDisabledColor, tabsBackgroundDisabledColor)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setTabsBackgroundDisabledColor, tabsBackgroundDisabledColor)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getTabsBackgroundDisabledImage, tabsBackgroundDisabledImage)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setTabsBackgroundDisabledImage, tabsBackgroundDisabledImage)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getTabsBackgroundFocusedColor, tabsBackgroundFocusedColor)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setTabsBackgroundFocusedColor, tabsBackgroundFocusedColor)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getTabsBackgroundFocusedImage, tabsBackgroundFocusedImage)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setTabsBackgroundFocusedImage, tabsBackgroundFocusedImage)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getTabsBackgroundSelectedColor, tabsBackgroundSelectedColor)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setTabsBackgroundSelectedColor, tabsBackgroundSelectedColor)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getTabsBackgroundSelectedImage, tabsBackgroundSelectedImage)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setTabsBackgroundSelectedImage, tabsBackgroundSelectedImage)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getActiveTabBackgroundColor, activeTabBackgroundColor)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setActiveTabBackgroundColor, activeTabBackgroundColor)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getActiveTabBackgroundImage, activeTabBackgroundImage)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setActiveTabBackgroundImage, activeTabBackgroundImage)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getActiveTabBackgroundDisabledColor, activeTabBackgroundDisabledColor)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setActiveTabBackgroundDisabledColor, activeTabBackgroundDisabledColor)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getActiveTabBackgroundDisabledImage, activeTabBackgroundDisabledImage)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setActiveTabBackgroundDisabledImage, activeTabBackgroundDisabledImage)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getActiveTabBackgroundFocusedColor, activeTabBackgroundFocusedColor)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setActiveTabBackgroundFocusedColor, activeTabBackgroundFocusedColor)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getActiveTabBackgroundFocusedImage, activeTabBackgroundFocusedImage)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setActiveTabBackgroundFocusedImage, activeTabBackgroundFocusedImage)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getActiveTabBackgroundSelectedColor, activeTabBackgroundSelectedColor)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setActiveTabBackgroundSelectedColor, activeTabBackgroundSelectedColor)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getActiveTabBackgroundSelectedImage, activeTabBackgroundSelectedImage)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setActiveTabBackgroundSelectedImage, activeTabBackgroundSelectedImage)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getTabDividerColor, tabDividerColor)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setTabDividerColor, tabDividerColor)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getTabDividerWidth, tabDividerWidth)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setTabDividerWidth, tabDividerWidth)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getTabHeight, tabHeight)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setTabHeight, tabHeight)
		TITANIUM_FUNCTION_AS_GETTER(TabGroup, getTabsAtBottom, tabsAtBottom)
		TITANIUM_FUNCTION_AS_SETTER(TabGroup, setTabsAtBottom, tabsAtBottom)

	} // namespace UI
} // namespace Titanium