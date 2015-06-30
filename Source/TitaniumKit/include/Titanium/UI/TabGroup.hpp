/**
 * TitaniumKit Titanium.UI.TabGroup
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_UI_TABGROUP_HPP_
#define _TITANIUM_UI_TABGROUP_HPP_

#include "Titanium/UI/View.hpp"
#include "Titanium/UI/TitleAttributesParams.hpp"

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		class Tab;

		/*!
		  @class
		  @discussion This is the Titanium TabGroup Module.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.UI.TabGroup
		*/
		class TITANIUMKIT_EXPORT TabGroup : public View, public JSExport<TabGroup>
		{

		public:

			/*!
			  @property
			  @abstract activeTab
			  @discussion Active tab.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::shared_ptr<Tab>, activeTab);

			/*!
			  @property
			  @abstract activity
			  @discussion Reference to the Android Activity object associated with this tab group.
			*/
			TITANIUM_PROPERTY_IMPL_READONLY_DEF(JSValue, activity);

			/*!
			  @property
			  @abstract allowUserCustomization
			  @discussion Allow the user to reorder tabs in the tab group using the **Edit** button on the **More** tab.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, allowUserCustomization);

			/*!
			  @property
			  @abstract barColor
			  @discussion Default navigation bar color (typically for the **More** tab), as a color name or hex triplet.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, barColor);

			/*!
			  @property
			  @abstract translucent
			  @discussion Boolean value indicating if the nav bar (typically for the **More** tab), is translucent.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, translucent);

			/*!
			  @property
			  @abstract titleAttributes
			  @discussion Title text attributes of the window to be applied on the **More** tab.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(TitleAttributesParams, titleAttributes);

			/*!
			  @property
			  @abstract navTintColor
			  @discussion The tintColor to apply to the navigation bar (typically for the **More** tab). This property is applicable on iOS 7 and greater.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, navTintColor);

			/*!
			  @property
			  @abstract editButtonTitle
			  @discussion Title for the edit button on the **More** tab.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, editButtonTitle);

			/*!
			  @property
			  @abstract exitOnClose
			  @discussion Boolean value indicating if the application should exit when closing the tab group, whether via Androidback button or the [close](Titanium.UI.TabGroup.close) method.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, exitOnClose);

			/*!
			  @property
			  @abstract navBarHidden
			  @discussion Hide the nav bar (`true`) or show the nav bar (`false`) for this tab group.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, navBarHidden);

			/*!
			  @property
			  @abstract swipeable
			  @discussion Boolean value indicating if tab navigation can be done by swipes, in addition to tab clicks.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, swipeable);

			/*!
			  @property
			  @abstract smoothScrollOnTabClick
			  @discussion Boolean value indicating if changing pages by tab clicks is animated.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, smoothScrollOnTabClick);

			/*!
			  @property
			  @abstract tabs
			  @discussion Tabs managed by the tab group.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::vector<std::shared_ptr<Tab>>, tabs);

			/*!
			  @property
			  @abstract windowSoftInputMode
			  @discussion Determines how the tab group is treated when a soft input method (such as a virtual keyboard) is displayed.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(double, windowSoftInputMode);

			/*!
			  @property
			  @abstract tabsBackgroundColor
			  @discussion Default background color for inactive tabs, as a color name or hex triplet.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, tabsBackgroundColor);

			/*!
			  @property
			  @abstract tabsTintColor
			  @discussion The tintColor to apply to the tabs. This property is applicable on iOS 7 and greater.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, tabsTintColor);

			/*!
			  @property
			  @abstract title
			  @discussion Title for this tabGroup.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, title);

			/*!
			  @property
			  @abstract tabsBackgroundImage
			  @discussion Default background image for tabs.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, tabsBackgroundImage);

			/*!
			  @property
			  @abstract shadowImage
			  @discussion Image of the shadow placed between the tab bar and the content area.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, shadowImage);

			/*!
			  @property
			  @abstract activeTabIconTint
			  @discussion Color applied to active tabs icons, as a color name or hex triplet, where the tab's activeIcon was not defined.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, activeTabIconTint);

			/*!
			  @property
			  @abstract tabsBackgroundDisabledColor
			  @discussion Default background disabled color for tabs, as a color name or hex triplet.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, tabsBackgroundDisabledColor);

			/*!
			  @property
			  @abstract tabsBackgroundDisabledImage
			  @discussion Default background disabled image for tabs.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, tabsBackgroundDisabledImage);

			/*!
			  @property
			  @abstract tabsBackgroundFocusedColor
			  @discussion Default background focused color for tabs, as a color name or hex triplet.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, tabsBackgroundFocusedColor);

			/*!
			  @property
			  @abstract tabsBackgroundFocusedImage
			  @discussion Default background focused image for tabs.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, tabsBackgroundFocusedImage);

			/*!
			  @property
			  @abstract tabsBackgroundSelectedColor
			  @discussion Default background selected color for tabs, as a color name or hex triplet.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, tabsBackgroundSelectedColor);

			/*!
			  @property
			  @abstract tabsBackgroundSelectedImage
			  @discussion Default background selected image for tabs.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, tabsBackgroundSelectedImage);

			/*!
			  @property
			  @abstract activeTabBackgroundColor
			  @discussion Default background color for the active tab, as a color name or hex triplet.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, activeTabBackgroundColor);

			/*!
			  @property
			  @abstract activeTabBackgroundImage
			  @discussion Default background image for the active tab.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, activeTabBackgroundImage);

			/*!
			  @property
			  @abstract activeTabBackgroundDisabledColor
			  @discussion Default background disabled color for the active tab, as a color name or hex triplet.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, activeTabBackgroundDisabledColor);

			/*!
			  @property
			  @abstract activeTabBackgroundDisabledImage
			  @discussion Default background disabled image for the active tab.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, activeTabBackgroundDisabledImage);

			/*!
			  @property
			  @abstract activeTabBackgroundFocusedColor
			  @discussion Default background focused color for the active tab, as a color name or hex triplet.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, activeTabBackgroundFocusedColor);

			/*!
			  @property
			  @abstract activeTabBackgroundFocusedImage
			  @discussion Default background focused image for the active tab.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, activeTabBackgroundFocusedImage);

			/*!
			  @property
			  @abstract activeTabBackgroundSelectedColor
			  @discussion Default background selected color for the active tab, as a color name or hex triplet.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, activeTabBackgroundSelectedColor);

			/*!
			  @property
			  @abstract activeTabBackgroundSelectedImage
			  @discussion Default background selected image for the active tab.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, activeTabBackgroundSelectedImage);

			/*!
			  @property
			  @abstract tabDividerColor
			  @discussion Color of the divider between tabs, as a color name or hex triplet.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, tabDividerColor);

			/*!
			  @property
			  @abstract tabDividerWidth
			  @discussion Width of the divider between tabs.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, tabDividerWidth);

			/*!
			  @property
			  @abstract tabHeight
			  @discussion Height of the tabs.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, tabHeight);

			/*!
			  @property
			  @abstract tabsAtBottom
			  @discussion Determines whether the tabs should be positioned at the top rather than the bottom of the screen.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, tabsAtBottom);

			/*!
			  @method
			  @abstract addTab
			  @discussion Adds a tab to the tab group.
			*/
			virtual void addTab(const std::shared_ptr<Tab>& tab) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract close
			  @discussion Closes the tab group and removes it from the UI.
			*/
			virtual void close() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract disableTabNavigation
			  @discussion Disable (or re-enable) tab navigation. If tab navigation is disabled, the tabs are hidden andthe last selected tab window is shown.
			*/
			virtual void disableTabNavigation(const bool& disable) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract open
			  @discussion Opens the tab group and makes it visible.
			*/
			virtual void open() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract removeTab
			  @discussion Removes a tab from the tab group.
			*/
			virtual void removeTab(const std::shared_ptr<Tab>& tab) TITANIUM_NOEXCEPT;

			TabGroup(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~TabGroup() = default;
			TabGroup(const TabGroup&) = default;
			TabGroup& operator=(const TabGroup&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			TabGroup(TabGroup&&)                 = default;
			TabGroup& operator=(TabGroup&&)      = default;
#endif

			static void JSExportInitialize();

			TITANIUM_PROPERTY_DEF(activeTab);
			TITANIUM_PROPERTY_READONLY_DEF(activity);
			TITANIUM_PROPERTY_DEF(allowUserCustomization);
			TITANIUM_PROPERTY_DEF(barColor);
			TITANIUM_PROPERTY_DEF(translucent);
			TITANIUM_PROPERTY_DEF(titleAttributes);
			TITANIUM_PROPERTY_DEF(navTintColor);
			TITANIUM_PROPERTY_DEF(editButtonTitle);
			TITANIUM_PROPERTY_DEF(exitOnClose);
			TITANIUM_PROPERTY_DEF(navBarHidden);
			TITANIUM_PROPERTY_DEF(swipeable);
			TITANIUM_PROPERTY_DEF(smoothScrollOnTabClick);
			TITANIUM_PROPERTY_DEF(tabs);
			TITANIUM_PROPERTY_DEF(windowSoftInputMode);
			TITANIUM_PROPERTY_DEF(tabsBackgroundColor);
			TITANIUM_PROPERTY_DEF(tabsTintColor);
			TITANIUM_PROPERTY_DEF(title);
			TITANIUM_PROPERTY_DEF(tabsBackgroundImage);
			TITANIUM_PROPERTY_DEF(shadowImage);
			TITANIUM_PROPERTY_DEF(activeTabIconTint);
			TITANIUM_PROPERTY_DEF(tabsBackgroundDisabledColor);
			TITANIUM_PROPERTY_DEF(tabsBackgroundDisabledImage);
			TITANIUM_PROPERTY_DEF(tabsBackgroundFocusedColor);
			TITANIUM_PROPERTY_DEF(tabsBackgroundFocusedImage);
			TITANIUM_PROPERTY_DEF(tabsBackgroundSelectedColor);
			TITANIUM_PROPERTY_DEF(tabsBackgroundSelectedImage);
			TITANIUM_PROPERTY_DEF(activeTabBackgroundColor);
			TITANIUM_PROPERTY_DEF(activeTabBackgroundImage);
			TITANIUM_PROPERTY_DEF(activeTabBackgroundDisabledColor);
			TITANIUM_PROPERTY_DEF(activeTabBackgroundDisabledImage);
			TITANIUM_PROPERTY_DEF(activeTabBackgroundFocusedColor);
			TITANIUM_PROPERTY_DEF(activeTabBackgroundFocusedImage);
			TITANIUM_PROPERTY_DEF(activeTabBackgroundSelectedColor);
			TITANIUM_PROPERTY_DEF(activeTabBackgroundSelectedImage);
			TITANIUM_PROPERTY_DEF(tabDividerColor);
			TITANIUM_PROPERTY_DEF(tabDividerWidth);
			TITANIUM_PROPERTY_DEF(tabHeight);
			TITANIUM_PROPERTY_DEF(tabsAtBottom);

			TITANIUM_FUNCTION_DEF(addTab);
			TITANIUM_FUNCTION_DEF(close);
			TITANIUM_FUNCTION_DEF(disableTabNavigation);
			TITANIUM_FUNCTION_DEF(open);
			TITANIUM_FUNCTION_DEF(removeTab);
			TITANIUM_FUNCTION_DEF(getActiveTab);
			TITANIUM_FUNCTION_DEF(setActiveTab);
			TITANIUM_FUNCTION_DEF(getActivity);
			TITANIUM_FUNCTION_DEF(getAllowUserCustomization);
			TITANIUM_FUNCTION_DEF(setAllowUserCustomization);
			TITANIUM_FUNCTION_DEF(getBarColor);
			TITANIUM_FUNCTION_DEF(setBarColor);
			TITANIUM_FUNCTION_DEF(getTranslucent);
			TITANIUM_FUNCTION_DEF(setTranslucent);
			TITANIUM_FUNCTION_DEF(getTitleAttributes);
			TITANIUM_FUNCTION_DEF(setTitleAttributes);
			TITANIUM_FUNCTION_DEF(getNavTintColor);
			TITANIUM_FUNCTION_DEF(setNavTintColor);
			TITANIUM_FUNCTION_DEF(getEditButtonTitle);
			TITANIUM_FUNCTION_DEF(setEditButtonTitle);
			TITANIUM_FUNCTION_DEF(getExitOnClose);
			TITANIUM_FUNCTION_DEF(setExitOnClose);
			TITANIUM_FUNCTION_DEF(getNavBarHidden);
			TITANIUM_FUNCTION_DEF(setNavBarHidden);
			TITANIUM_FUNCTION_DEF(getSwipeable);
			TITANIUM_FUNCTION_DEF(setSwipeable);
			TITANIUM_FUNCTION_DEF(getSmoothScrollOnTabClick);
			TITANIUM_FUNCTION_DEF(setSmoothScrollOnTabClick);
			TITANIUM_FUNCTION_DEF(getTabs);
			TITANIUM_FUNCTION_DEF(setTabs);
			TITANIUM_FUNCTION_DEF(getWindowSoftInputMode);
			TITANIUM_FUNCTION_DEF(setWindowSoftInputMode);
			TITANIUM_FUNCTION_DEF(getTabsBackgroundColor);
			TITANIUM_FUNCTION_DEF(setTabsBackgroundColor);
			TITANIUM_FUNCTION_DEF(getTabsTintColor);
			TITANIUM_FUNCTION_DEF(setTabsTintColor);
			TITANIUM_FUNCTION_DEF(getTitle);
			TITANIUM_FUNCTION_DEF(setTitle);
			TITANIUM_FUNCTION_DEF(getTabsBackgroundImage);
			TITANIUM_FUNCTION_DEF(setTabsBackgroundImage);
			TITANIUM_FUNCTION_DEF(getShadowImage);
			TITANIUM_FUNCTION_DEF(setShadowImage);
			TITANIUM_FUNCTION_DEF(getActiveTabIconTint);
			TITANIUM_FUNCTION_DEF(setActiveTabIconTint);
			TITANIUM_FUNCTION_DEF(getTabsBackgroundDisabledColor);
			TITANIUM_FUNCTION_DEF(setTabsBackgroundDisabledColor);
			TITANIUM_FUNCTION_DEF(getTabsBackgroundDisabledImage);
			TITANIUM_FUNCTION_DEF(setTabsBackgroundDisabledImage);
			TITANIUM_FUNCTION_DEF(getTabsBackgroundFocusedColor);
			TITANIUM_FUNCTION_DEF(setTabsBackgroundFocusedColor);
			TITANIUM_FUNCTION_DEF(getTabsBackgroundFocusedImage);
			TITANIUM_FUNCTION_DEF(setTabsBackgroundFocusedImage);
			TITANIUM_FUNCTION_DEF(getTabsBackgroundSelectedColor);
			TITANIUM_FUNCTION_DEF(setTabsBackgroundSelectedColor);
			TITANIUM_FUNCTION_DEF(getTabsBackgroundSelectedImage);
			TITANIUM_FUNCTION_DEF(setTabsBackgroundSelectedImage);
			TITANIUM_FUNCTION_DEF(getActiveTabBackgroundColor);
			TITANIUM_FUNCTION_DEF(setActiveTabBackgroundColor);
			TITANIUM_FUNCTION_DEF(getActiveTabBackgroundImage);
			TITANIUM_FUNCTION_DEF(setActiveTabBackgroundImage);
			TITANIUM_FUNCTION_DEF(getActiveTabBackgroundDisabledColor);
			TITANIUM_FUNCTION_DEF(setActiveTabBackgroundDisabledColor);
			TITANIUM_FUNCTION_DEF(getActiveTabBackgroundDisabledImage);
			TITANIUM_FUNCTION_DEF(setActiveTabBackgroundDisabledImage);
			TITANIUM_FUNCTION_DEF(getActiveTabBackgroundFocusedColor);
			TITANIUM_FUNCTION_DEF(setActiveTabBackgroundFocusedColor);
			TITANIUM_FUNCTION_DEF(getActiveTabBackgroundFocusedImage);
			TITANIUM_FUNCTION_DEF(setActiveTabBackgroundFocusedImage);
			TITANIUM_FUNCTION_DEF(getActiveTabBackgroundSelectedColor);
			TITANIUM_FUNCTION_DEF(setActiveTabBackgroundSelectedColor);
			TITANIUM_FUNCTION_DEF(getActiveTabBackgroundSelectedImage);
			TITANIUM_FUNCTION_DEF(setActiveTabBackgroundSelectedImage);
			TITANIUM_FUNCTION_DEF(getTabDividerColor);
			TITANIUM_FUNCTION_DEF(setTabDividerColor);
			TITANIUM_FUNCTION_DEF(getTabDividerWidth);
			TITANIUM_FUNCTION_DEF(setTabDividerWidth);
			TITANIUM_FUNCTION_DEF(getTabHeight);
			TITANIUM_FUNCTION_DEF(setTabHeight);
			TITANIUM_FUNCTION_DEF(getTabsAtBottom);
			TITANIUM_FUNCTION_DEF(setTabsAtBottom);

		protected:
#pragma warning(push)
#pragma warning(disable : 4251)
			std::shared_ptr<Tab> activeTab__;
			JSValue activity__;
			bool allowUserCustomization__;
			std::string barColor__;
			bool translucent__;
			TitleAttributesParams titleAttributes__;
			std::string navTintColor__;
			std::string editButtonTitle__;
			bool exitOnClose__;
			bool navBarHidden__;
			bool swipeable__;
			bool smoothScrollOnTabClick__;
			std::vector<std::shared_ptr<Tab>> tabs__;
			double windowSoftInputMode__;
			std::string tabsBackgroundColor__;
			std::string tabsTintColor__;
			std::string title__;
			std::string tabsBackgroundImage__;
			std::string shadowImage__;
			std::string activeTabIconTint__;
			std::string tabsBackgroundDisabledColor__;
			std::string tabsBackgroundDisabledImage__;
			std::string tabsBackgroundFocusedColor__;
			std::string tabsBackgroundFocusedImage__;
			std::string tabsBackgroundSelectedColor__;
			std::string tabsBackgroundSelectedImage__;
			std::string activeTabBackgroundColor__;
			std::string activeTabBackgroundImage__;
			std::string activeTabBackgroundDisabledColor__;
			std::string activeTabBackgroundDisabledImage__;
			std::string activeTabBackgroundFocusedColor__;
			std::string activeTabBackgroundFocusedImage__;
			std::string activeTabBackgroundSelectedColor__;
			std::string activeTabBackgroundSelectedImage__;
			std::string tabDividerColor__;
			std::string tabDividerWidth__;
			std::string tabHeight__;
			bool tabsAtBottom__;
#pragma warning(pop)

		};
	} // namespace UI
} // namespace Titanium
#endif // _TITANIUM_UI_TABGROUP_HPP_