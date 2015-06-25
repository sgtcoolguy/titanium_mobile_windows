/**
 * TitaniumKit Titanium.UI.ListView
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_UI_LISTVIEW_HPP_
#define _TITANIUM_UI_LISTVIEW_HPP_

#include "Titanium/UI/View.hpp"
#include "Titanium/UI/ListSection.hpp"
#include "Titanium/UI/ListViewMarkerProps.hpp"
#include "Titanium/detail/TiImpl.hpp"
#include <vector>
#include <unordered_map>

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		class ListViewAnimationProperties;

		using ListSection_shared_ptr_t = std::shared_ptr<ListSection>;
		using View_shared_ptr_t = std::shared_ptr<View>;
		
		/*!
		  @class
		  @discussion This is the Titanium.UI.ListView Module.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.UI.ListView
		*/
		class TITANIUMKIT_EXPORT ListView : public View, public JSExport<ListView>
		{

		public:

			/*!
			  @property
			  @abstract sections
			  @discussion Sections of this list.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::vector<ListSection_shared_ptr_t>, sections);

			template<typename T>
			std::vector<std::shared_ptr<T>> createSectionViewAt(uint32_t index)
			{
				// lazy loading
				loadJS();
				
				std::vector<std::shared_ptr<T>> items;
				const std::vector<JSValue> args { get_object(), sections__.at(index)->get_object() };
				JSValue result = sectionViewCreateFunction__(args, ti_listview_exports__);
				TITANIUM_ASSERT(result.IsObject());
				auto js_items = static_cast<JSObject>(result);
				TITANIUM_ASSERT(js_items.IsArray());
				
				const auto length = static_cast<uint32_t>(js_items.GetProperty("length"));
				for (uint32_t i = 0; i < length; i++) {
					items.push_back(static_cast<JSObject>(js_items.GetProperty(i)).GetPrivate<T>());
				}
				
				return items;
			}

			/*!
			  @property
			  @abstract footerTitle
			  @discussion List view footer title.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, footerTitle);

			/*!
			  @property
			  @abstract headerTitle
			  @discussion List view header title.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, headerTitle);
			
			/*!
			 @property
			 @abstract footerView
			 @discussion List view footer as a view that will be rendered instead of a label.
			 */
			TITANIUM_PROPERTY_IMPL_DEF(View_shared_ptr_t, footerView);
			
			/*!
			 @property
			 @abstract headerView
			 @discussion List view header as a view that will be rendered instead of a label.
			 */
			TITANIUM_PROPERTY_IMPL_DEF(View_shared_ptr_t, headerView);
			
			/*!
			 @property
			 @abstract searchView
			 @discussion Search field to use for the list view.
			 */
			TITANIUM_PROPERTY_IMPL_DEF(View_shared_ptr_t, searchView);

			/*!
			  @property
			  @abstract searchText
			  @discussion The string to use as the search parameter.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, searchText);

			/*!
			  @property
			  @abstract caseInsensitiveSearch
			  @discussion Determines if the search performed is case insensitive.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, caseInsensitiveSearch);

			/*!
			  @property
			  @abstract sectionCount
			  @discussion Number of sections in this list view.
			*/
			TITANIUM_PROPERTY_IMPL_READONLY_DEF(uint32_t, sectionCount);

			/*!
			  @property
			  @abstract showVerticalScrollIndicator
			  @discussion Determines whether this list view displays a vertical scroll indicator.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, showVerticalScrollIndicator);

			/*!
			  @property
			  @abstract separatorColor
			  @discussion Separator line color between rows, as a color name or hex triplet.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, separatorColor);

			/*!
			  @property
			  @abstract defaultItemTemplate
			  @discussion Sets the default template for list data items that do not specify the `template` property.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, defaultItemTemplate);

			/*!
			  @method
			  @abstract scrollToItem
			  @discussion Scrolls to a specific item.
			*/
			virtual void scrollToItem(uint32_t sectionIndex, uint32_t itemIndex, const std::shared_ptr<ListViewAnimationProperties>& animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract appendSection
			  @discussion Appends a single section or an array of sections to the end of the list.
			*/
			virtual void appendSection(const std::vector<ListSection_shared_ptr_t>& section, const std::shared_ptr<ListViewAnimationProperties>& animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract deleteSectionAt
			  @discussion Deletes an existing section.
			*/
			virtual void deleteSectionAt(uint32_t sectionIndex, const std::shared_ptr<ListViewAnimationProperties>& animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract insertSectionAt
			  @discussion Inserts a section or an array of sections at a specific index.
			*/
			virtual void insertSectionAt(uint32_t sectionIndex, const std::vector<ListSection_shared_ptr_t>& section, const std::shared_ptr<ListViewAnimationProperties>& animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract replaceSectionAt
			  @discussion Replaces an existing section.
			*/
			virtual void replaceSectionAt(uint32_t sectionIndex, const std::vector<ListSection_shared_ptr_t>& section, const std::shared_ptr<ListViewAnimationProperties>& animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract setMarker
			  @discussion Sets a reference item in the list view.
			*/
			virtual void setMarker(const ListViewMarkerProps& marker) TITANIUM_NOEXCEPT;

			ListView(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~ListView() = default;
			ListView(const ListView&) = default;
			ListView& operator=(const ListView&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			ListView(ListView&&)                 = default;
			ListView& operator=(ListView&&)      = default;
#endif

			static void JSExportInitialize();

			TITANIUM_PROPERTY_DEF(sections);
			TITANIUM_PROPERTY_DEF(footerTitle);
			TITANIUM_PROPERTY_DEF(headerTitle);
			TITANIUM_PROPERTY_DEF(searchText);
			TITANIUM_PROPERTY_DEF(footerView);
			TITANIUM_PROPERTY_DEF(headerView);
			TITANIUM_PROPERTY_DEF(searchView);
			TITANIUM_PROPERTY_DEF(caseInsensitiveSearch);
			TITANIUM_PROPERTY_READONLY_DEF(sectionCount);
			TITANIUM_PROPERTY_DEF(showVerticalScrollIndicator);
			TITANIUM_PROPERTY_DEF(separatorColor);
			TITANIUM_PROPERTY_DEF(defaultItemTemplate);

			TITANIUM_FUNCTION_DEF(scrollToItem);
			TITANIUM_FUNCTION_DEF(appendSection);
			TITANIUM_FUNCTION_DEF(deleteSectionAt);
			TITANIUM_FUNCTION_DEF(insertSectionAt);
			TITANIUM_FUNCTION_DEF(replaceSectionAt);
			TITANIUM_FUNCTION_DEF(setMarker);
			TITANIUM_FUNCTION_DEF(getTemplates);
			TITANIUM_FUNCTION_DEF(setTemplates);
			TITANIUM_FUNCTION_DEF(getSections);
			TITANIUM_FUNCTION_DEF(setSections);
			TITANIUM_FUNCTION_DEF(getFooterTitle);
			TITANIUM_FUNCTION_DEF(setFooterTitle);
			TITANIUM_FUNCTION_DEF(getFooterView);
			TITANIUM_FUNCTION_DEF(setFooterView);
			TITANIUM_FUNCTION_DEF(getHeaderTitle);
			TITANIUM_FUNCTION_DEF(setHeaderTitle);
			TITANIUM_FUNCTION_DEF(getHeaderView);
			TITANIUM_FUNCTION_DEF(setHeaderView);
			TITANIUM_FUNCTION_DEF(getSearchView);
			TITANIUM_FUNCTION_DEF(setSearchView);
			TITANIUM_FUNCTION_DEF(getSearchText);
			TITANIUM_FUNCTION_DEF(setSearchText);
			TITANIUM_FUNCTION_DEF(getCaseInsensitiveSearch);
			TITANIUM_FUNCTION_DEF(setCaseInsensitiveSearch);
			TITANIUM_FUNCTION_DEF(getSectionCount);
			TITANIUM_FUNCTION_DEF(getShowVerticalScrollIndicator);
			TITANIUM_FUNCTION_DEF(setShowVerticalScrollIndicator);
			TITANIUM_FUNCTION_DEF(getSeparatorColor);
			TITANIUM_FUNCTION_DEF(setSeparatorColor);
			TITANIUM_FUNCTION_DEF(getDefaultItemTemplate);
			TITANIUM_FUNCTION_DEF(setDefaultItemTemplate);

			void loadJS();

		protected:
#pragma warning(push)
#pragma warning(disable : 4251)
			std::vector<ListSection_shared_ptr_t> sections__;
			std::string footerTitle__;
			std::string headerTitle__;
			View_shared_ptr_t footerView__;
			View_shared_ptr_t headerView__;
			View_shared_ptr_t searchView__;
			std::string searchText__;
			bool caseInsensitiveSearch__ { false };
			bool showVerticalScrollIndicator__;
			std::string separatorColor__;
			std::string defaultItemTemplate__;
			ListViewMarkerProps marker__;

			JSObject ti_listview_exports__;
			JSObject sectionViewCreateFunction__;
			JSObject listviewAnimationProperties_ctor__;
#pragma warning(pop)
		};
	} // namespace UI
} // namespace Titanium
#endif // _TITANIUM_UI_LISTVIEW_HPP_