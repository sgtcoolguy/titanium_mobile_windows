/**
 * TitaniumKit Titanium.UI.ListView
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/ListView.hpp"
#include "Titanium/UI/listview_js.hpp"

namespace Titanium
{
	namespace UI
	{
		ListView::ListView(const JSContext& js_context) TITANIUM_NOEXCEPT
			: View(js_context),
			listviewAnimationProperties_ctor__(js_context.CreateObject(JSExport<Titanium::UI::ListViewAnimationProperties>::Class())),
			footerTitle__(""),
			headerTitle__(""),
			searchText__(""),
			caseInsensitiveSearch__(true),
			showVerticalScrollIndicator__(true),
			separatorColor__(""),
			ti_listview_exports__(js_context.CreateObject()),
			sectionViewCreateFunction__(js_context.CreateObject())
		{
		}

		std::vector<ListSection_shared_ptr_t> ListView::get_sections() const TITANIUM_NOEXCEPT
		{
			return sections__;
		}

		void ListView::set_sections(const std::vector<ListSection_shared_ptr_t>& sections) TITANIUM_NOEXCEPT
		{
			sections__ = sections;
		}

		void ListView::loadJS()
		{
			if (sectionViewCreateFunction__.IsFunction()) {
				return;
			}

			auto context = get_context();
			auto export_object = context.CreateObject();
			export_object.SetProperty("global", context.get_global_object());

			context.JSEvaluateScript(listview_js, export_object);

			TITANIUM_ASSERT(export_object.HasProperty("exports"));
			ti_listview_exports__ = static_cast<JSObject>(export_object.GetProperty("exports"));

			auto func = ti_listview_exports__.GetProperty("createSectionView");
			TITANIUM_ASSERT(func.IsObject());
			sectionViewCreateFunction__ = static_cast<JSObject>(func);
			TITANIUM_ASSERT(sectionViewCreateFunction__.IsFunction());
		}

		std::string ListView::get_footerTitle() const TITANIUM_NOEXCEPT
		{
			return footerTitle__;
		}

		void ListView::set_footerTitle(const std::string& footerTitle) TITANIUM_NOEXCEPT
		{
			footerTitle__ = footerTitle;
		}

		std::string ListView::get_headerTitle() const TITANIUM_NOEXCEPT
		{
			return headerTitle__;
		}

		void ListView::set_headerTitle(const std::string& headerTitle) TITANIUM_NOEXCEPT
		{
			headerTitle__ = headerTitle;
		}

		View_shared_ptr_t ListView::get_footerView() const TITANIUM_NOEXCEPT
		{
			return footerView__;
		}
		
		void ListView::set_footerView(const View_shared_ptr_t& value) TITANIUM_NOEXCEPT
		{
			footerView__ = value;
		}
		
		View_shared_ptr_t ListView::get_headerView() const TITANIUM_NOEXCEPT
		{
			return headerView__;
		}
		
		void ListView::set_headerView(const View_shared_ptr_t& value) TITANIUM_NOEXCEPT
		{
			headerView__ = value;
		}

		View_shared_ptr_t ListView::get_searchView() const TITANIUM_NOEXCEPT
		{
			return searchView__;
		}
		
		void ListView::set_searchView(const View_shared_ptr_t& value) TITANIUM_NOEXCEPT
		{
			searchView__ = value;
		}
		
		std::string ListView::get_searchText() const TITANIUM_NOEXCEPT
		{
			return searchText__;
		}

		void ListView::set_searchText(const std::string& searchText) TITANIUM_NOEXCEPT
		{
			searchText__ = searchText;
		}

		bool ListView::get_caseInsensitiveSearch() const TITANIUM_NOEXCEPT
		{
			return caseInsensitiveSearch__;
		}

		void ListView::set_caseInsensitiveSearch(bool value) TITANIUM_NOEXCEPT
		{
			caseInsensitiveSearch__ = value;
		}

		uint32_t ListView::get_sectionCount() const TITANIUM_NOEXCEPT
		{
			return static_cast<uint32_t>(sections__.size());
		}

		bool ListView::get_showVerticalScrollIndicator() const TITANIUM_NOEXCEPT
		{
			return showVerticalScrollIndicator__;
		}

		void ListView::set_showVerticalScrollIndicator(bool value) TITANIUM_NOEXCEPT
		{
			showVerticalScrollIndicator__ = value;
		}

		std::string ListView::get_separatorColor() const TITANIUM_NOEXCEPT
		{
			return separatorColor__;
		}

		void ListView::set_separatorColor(std::string value) TITANIUM_NOEXCEPT
		{
			separatorColor__ = value;
		}

		std::string ListView::get_defaultItemTemplate() const TITANIUM_NOEXCEPT
		{
			return defaultItemTemplate__;
		}
		
		void ListView::set_defaultItemTemplate(std::string value) TITANIUM_NOEXCEPT
		{
			defaultItemTemplate__ = value;
		}

		void ListView::scrollToItem(uint32_t sectionIndex, uint32_t itemIndex, const std::shared_ptr<ListViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("ListView::scrollToItem: Unimplemented");
		}

		void ListView::appendSection(const std::vector<ListSection_shared_ptr_t>& sections, const std::shared_ptr<ListViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			for (const auto section : sections) {
				sections__.push_back(section);
			}
			set_sections(sections__);
		}

		void ListView::deleteSectionAt(uint32_t index, const std::shared_ptr<ListViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			sections__.erase(sections__.begin()+index);
			set_sections(sections__);
		}

		void ListView::insertSectionAt(uint32_t index, const std::vector<ListSection_shared_ptr_t>& section, const std::shared_ptr<ListViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			sections__.insert(sections__.begin() + index, section.begin(), section.end());
			set_sections(sections__);
		}

		void ListView::replaceSectionAt(uint32_t index, const std::vector<ListSection_shared_ptr_t>& sections, const std::shared_ptr<ListViewAnimationProperties>& animationn) TITANIUM_NOEXCEPT
		{
			sections__.erase (sections__.begin() + index, sections__.begin() + index + sections.size());
			sections__.insert(sections__.begin() + index, sections.begin(), sections.end());
			set_sections(sections__);
		}

		void ListView::setMarker(const ListViewMarkerProps& marker) TITANIUM_NOEXCEPT
		{
			marker__ = marker;
		}

		void ListView::JSExportInitialize() {
			JSExport<ListView>::SetClassVersion(1);
			JSExport<ListView>::SetParent(JSExport<View>::Class());

			TITANIUM_ADD_PROPERTY(ListView, sections);
			TITANIUM_ADD_PROPERTY(ListView, footerTitle);
			TITANIUM_ADD_PROPERTY(ListView, headerTitle);
			TITANIUM_ADD_PROPERTY(ListView, searchText);
			
			TITANIUM_ADD_PROPERTY(ListView, footerView);
			TITANIUM_ADD_PROPERTY(ListView, headerView);
			TITANIUM_ADD_PROPERTY(ListView, searchView);

			TITANIUM_ADD_PROPERTY(ListView, caseInsensitiveSearch);
			TITANIUM_ADD_PROPERTY_READONLY(ListView, sectionCount);
			TITANIUM_ADD_PROPERTY(ListView, showVerticalScrollIndicator);
			TITANIUM_ADD_PROPERTY(ListView, separatorColor);
			TITANIUM_ADD_PROPERTY(ListView, defaultItemTemplate);

			TITANIUM_ADD_FUNCTION(ListView, scrollToItem);
			TITANIUM_ADD_FUNCTION(ListView, appendSection);
			TITANIUM_ADD_FUNCTION(ListView, deleteSectionAt);
			TITANIUM_ADD_FUNCTION(ListView, insertSectionAt);
			TITANIUM_ADD_FUNCTION(ListView, replaceSectionAt);
			TITANIUM_ADD_FUNCTION(ListView, setMarker);
			TITANIUM_ADD_FUNCTION(ListView, getTemplates);
			TITANIUM_ADD_FUNCTION(ListView, setTemplates);
			TITANIUM_ADD_FUNCTION(ListView, getSections);
			TITANIUM_ADD_FUNCTION(ListView, setSections);
			TITANIUM_ADD_FUNCTION(ListView, getFooterTitle);
			TITANIUM_ADD_FUNCTION(ListView, setFooterTitle);
			TITANIUM_ADD_FUNCTION(ListView, getFooterView);
			TITANIUM_ADD_FUNCTION(ListView, setFooterView);
			TITANIUM_ADD_FUNCTION(ListView, getHeaderTitle);
			TITANIUM_ADD_FUNCTION(ListView, setHeaderTitle);
			TITANIUM_ADD_FUNCTION(ListView, getHeaderView);
			TITANIUM_ADD_FUNCTION(ListView, setHeaderView);
			TITANIUM_ADD_FUNCTION(ListView, getSearchView);
			TITANIUM_ADD_FUNCTION(ListView, setSearchView);
			TITANIUM_ADD_FUNCTION(ListView, getSearchText);
			TITANIUM_ADD_FUNCTION(ListView, setSearchText);
			TITANIUM_ADD_FUNCTION(ListView, getCaseInsensitiveSearch);
			TITANIUM_ADD_FUNCTION(ListView, setCaseInsensitiveSearch);
			TITANIUM_ADD_FUNCTION(ListView, getSectionCount);
			TITANIUM_ADD_FUNCTION(ListView, getShowVerticalScrollIndicator);
			TITANIUM_ADD_FUNCTION(ListView, setShowVerticalScrollIndicator);
			TITANIUM_ADD_FUNCTION(ListView, getSeparatorColor);
			TITANIUM_ADD_FUNCTION(ListView, setSeparatorColor);
			TITANIUM_ADD_FUNCTION(ListView, getDefaultItemTemplate);
			TITANIUM_ADD_FUNCTION(ListView, setDefaultItemTemplate);
		}

		TITANIUM_PROPERTY_GETTER(ListView, sections)
		{
			std::vector<JSValue> js_sections;
			const auto sections = get_sections();
			for (auto section : sections) {
				js_sections.push_back(section->get_object());
			}
			return get_context().CreateArray(js_sections);
		}

		TITANIUM_PROPERTY_SETTER(ListView, sections)
		{
			if (!argument.IsObject()) {
				return false;
			}
			const auto sections = static_cast<JSObject>(argument);
			if (!sections.IsArray()) {
				return false;
			}
			set_sections(static_cast<JSArray>(sections).GetPrivateItems<ListSection>());
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ListView, sectionCount)
		{
			return get_context().CreateNumber(static_cast<uint32_t>(get_sectionCount()));
		}

		TITANIUM_PROPERTY_GETTER(ListView, footerTitle)
		{
			return get_context().CreateString(get_footerTitle());
		}

		TITANIUM_PROPERTY_SETTER(ListView, footerTitle)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_footerTitle(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ListView, headerTitle)
		{
			return get_context().CreateString(get_headerTitle());
		}

		TITANIUM_PROPERTY_SETTER(ListView, headerTitle)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_headerTitle(static_cast<std::string>(argument));
			return true;
		}
		
		TITANIUM_PROPERTY_GETTER(ListView, footerView)
		{
			auto view = get_footerView();
			if (view) {
				return view->get_object();
			}  else {
				return get_context().CreateNull();	
			}
		}
		
		TITANIUM_PROPERTY_SETTER(ListView, footerView)
		{
			TITANIUM_ASSERT(argument.IsObject());
			set_footerView(static_cast<JSObject>(argument).GetPrivate<View>());
			return true;
		}
		
		TITANIUM_PROPERTY_GETTER(ListView, headerView)
		{
			auto view = get_headerView();
			if (view) {
				return view->get_object();
			}  else {
				return get_context().CreateNull();	
			}
		}
		
		TITANIUM_PROPERTY_SETTER(ListView, headerView)
		{
			TITANIUM_ASSERT(argument.IsObject());
			set_headerView(static_cast<JSObject>(argument).GetPrivate<View>());
			return true;
		}
		
		TITANIUM_PROPERTY_GETTER(ListView, searchView)
		{
			auto view = get_searchView();
			if (view) {
				return view->get_object();
			}  else {
				return get_context().CreateNull();	
			}
		}
		
		TITANIUM_PROPERTY_SETTER(ListView, searchView)
		{
			TITANIUM_ASSERT(argument.IsObject());
			set_searchView(static_cast<JSObject>(argument).GetPrivate<View>());
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ListView, searchText)
		{
			return get_context().CreateString(get_searchText());
		}

		TITANIUM_PROPERTY_SETTER(ListView, searchText)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_searchText(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ListView, caseInsensitiveSearch)
		{
			return get_context().CreateBoolean(get_caseInsensitiveSearch());
		}

		TITANIUM_PROPERTY_SETTER(ListView, caseInsensitiveSearch)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_caseInsensitiveSearch(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ListView, showVerticalScrollIndicator)
		{
			return get_context().CreateBoolean(get_showVerticalScrollIndicator());
		}

		TITANIUM_PROPERTY_SETTER(ListView, showVerticalScrollIndicator)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_showVerticalScrollIndicator(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ListView, separatorColor)
		{
			return get_context().CreateString(get_separatorColor());
		}

		TITANIUM_PROPERTY_SETTER(ListView, separatorColor)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_separatorColor(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ListView, defaultItemTemplate)
		{
			return get_context().CreateString(get_defaultItemTemplate());
		}

		TITANIUM_PROPERTY_SETTER(ListView, defaultItemTemplate)
		{
			set_defaultItemTemplate(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_FUNCTION(ListView, scrollToItem)
		{
			const auto js_context = this_object.get_context();
			if (arguments.size() >= 2) {
				JSObject animation = js_context.CreateObject();

				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto _1 = arguments.at(1);
				TITANIUM_ASSERT(_1.IsNumber());

				const auto sectionIndex = static_cast<uint32_t>(_0);
				const auto itemIndex    = static_cast<uint32_t>(_1);

				if (arguments.size() >= 3) {
					const auto _3 = arguments.at(2);
					if (_3.IsObject()) {
						animation = listviewAnimationProperties_ctor__.CallAsConstructor({_3});
					}
				}

				scrollToItem(sectionIndex, itemIndex, animation.GetPrivate<ListViewAnimationProperties>());
			}

			return this_object.get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ListView, appendSection)
		{
			const auto js_context = this_object.get_context();
			if (arguments.size() >= 1) {
				JSObject animation = js_context.CreateObject();
				std::vector<ListSection_shared_ptr_t> sections;

				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsObject());
				const auto js_sections = static_cast<JSObject>(_0);

				if (js_sections.IsArray()) {
					sections = static_cast<JSArray>(js_sections).GetPrivateItems<ListSection>();
				} else {
					sections.push_back(js_sections.GetPrivate<ListSection>());
				}

				if (arguments.size() >= 2) {
					const auto _1 = arguments.at(1);
					if (_1.IsObject()) {
						animation = listviewAnimationProperties_ctor__.CallAsConstructor({_1});
					}
				}

				appendSection(sections, animation.GetPrivate<ListViewAnimationProperties>());
			}
			return this_object.get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ListView, deleteSectionAt)
		{
			const auto js_context = this_object.get_context();
			if (arguments.size() >= 1) {
				JSObject animation = js_context.CreateObject();

				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());

				const auto sectionIndex = static_cast<uint32_t>(_0);

				if (arguments.size() >= 2) {
					const auto _1 = arguments.at(1);
					if (_1.IsObject()) {
						animation = listviewAnimationProperties_ctor__.CallAsConstructor({_1});
					}
				}
				deleteSectionAt(sectionIndex, animation.GetPrivate<ListViewAnimationProperties>());
			}
			return this_object.get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ListView, insertSectionAt)
		{
			const auto js_context = this_object.get_context();
			if (arguments.size() >= 2) {
				JSObject animation = js_context.CreateObject();
				std::vector<ListSection_shared_ptr_t> sections;

				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto sectionIndex = static_cast<uint32_t>(_0);

				const auto _1 = arguments.at(0);
				TITANIUM_ASSERT(_1.IsObject());
				const auto js_sections = static_cast<JSObject>(_1);

				if (js_sections.IsArray()) {
					sections = static_cast<JSArray>(js_sections).GetPrivateItems<ListSection>();
				} else {
					sections.push_back(js_sections.GetPrivate<ListSection>());
				}

				if (arguments.size() >= 3) {
					const auto _2 = arguments.at(2);
					if (_2.IsObject()) {
						animation = listviewAnimationProperties_ctor__.CallAsConstructor({_2});
					}
				}

				insertSectionAt(sectionIndex, sections, animation.GetPrivate<ListViewAnimationProperties>());
			}
			return this_object.get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ListView, replaceSectionAt)
		{
			const auto js_context = this_object.get_context();
			if (arguments.size() >= 2) {
				JSObject animation = js_context.CreateObject();
				std::vector<ListSection_shared_ptr_t> sections;

				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto sectionIndex = static_cast<uint32_t>(_0);

				const auto _1 = arguments.at(0);
				TITANIUM_ASSERT(_1.IsObject());
				const auto js_sections = static_cast<JSObject>(_1);

				if (js_sections.IsArray()) {
					sections = static_cast<JSArray>(js_sections).GetPrivateItems<ListSection>();
				} else {
					sections.push_back(js_sections.GetPrivate<ListSection>());
				}

				if (arguments.size() >= 3) {
					const auto _2 = arguments.at(2);
					if (_2.IsObject()) {
						animation = listviewAnimationProperties_ctor__.CallAsConstructor({_2});
					}
				}

				replaceSectionAt(sectionIndex, sections, animation.GetPrivate<ListViewAnimationProperties>());
			}
			return this_object.get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ListView, setMarker)
		{
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsObject());
				setMarker(js_to_ListViewMarkerProps(static_cast<JSObject>(_0)));
			}
			return this_object.get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ListView, getTemplates)
		{
			return this_object.GetProperty("templates");
		}

		TITANIUM_FUNCTION(ListView, setTemplates)
		{
			if (arguments.size() >= 1) {
				this_object.SetProperty("templates", arguments.at(0));
			}
			return this_object.get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ListView, getSections)
		{
			return js_get_sections();
		}

		TITANIUM_FUNCTION(ListView, setSections)
		{
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				js_set_sections(_0);
			}
			return this_object.get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ListView, getFooterTitle)
		{
			return js_get_footerTitle();
		}

		TITANIUM_FUNCTION(ListView, setFooterTitle)
		{
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				js_set_footerTitle(_0);
			}
			return this_object.get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ListView, getFooterView)
		{
			return this_object.GetProperty("footerView");
		}

		TITANIUM_FUNCTION(ListView, setFooterView)
		{
			if (arguments.size() >= 1) {
				this_object.SetProperty("footerView", arguments.at(0));
			}
			return this_object.get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ListView, getHeaderTitle)
		{
			return js_get_headerTitle();
		}

		TITANIUM_FUNCTION(ListView, setHeaderTitle)
		{
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				js_set_headerTitle(_0);
			}
			return this_object.get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ListView, getHeaderView)
		{
			return this_object.GetProperty("headerView");
		}

		TITANIUM_FUNCTION(ListView, setHeaderView)
		{
			if (arguments.size() >= 1) {
				this_object.SetProperty("headerView", arguments.at(0));
			}
			return this_object.get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ListView, getSearchView)
		{
			return this_object.GetProperty("searchView");
		}

		TITANIUM_FUNCTION(ListView, setSearchView)
		{
			if (arguments.size() >= 1) {
				this_object.SetProperty("searchView", arguments.at(0));
			}
			return this_object.get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ListView, getSearchText)
		{
			return js_get_searchText();
		}

		TITANIUM_FUNCTION(ListView, setSearchText)
		{
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				js_set_searchText(_0);
			}
			return this_object.get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ListView, getCaseInsensitiveSearch)
		{
			return js_get_caseInsensitiveSearch();
		}

		TITANIUM_FUNCTION(ListView, setCaseInsensitiveSearch)
		{
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				js_set_caseInsensitiveSearch(_0);
			}
			return this_object.get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ListView, getSectionCount)
		{
			return js_get_sectionCount();
		}

		TITANIUM_FUNCTION(ListView, getShowVerticalScrollIndicator)
		{
			return js_get_showVerticalScrollIndicator();
		}

		TITANIUM_FUNCTION(ListView, setShowVerticalScrollIndicator)
		{
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				js_set_showVerticalScrollIndicator(_0);
			}
			return this_object.get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ListView, getSeparatorColor)
		{
			return js_get_separatorColor();
		}

		TITANIUM_FUNCTION(ListView, setSeparatorColor)
		{
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				js_set_separatorColor(_0);
			}
			return this_object.get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(ListView, getDefaultItemTemplate)
		{
			return js_get_defaultItemTemplate();
		}

		TITANIUM_FUNCTION(ListView, setDefaultItemTemplate)
		{
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				js_set_defaultItemTemplate(_0);
			}
			return this_object.get_context().CreateUndefined();
		}

	} // namespace UI
} // namespace Titanium