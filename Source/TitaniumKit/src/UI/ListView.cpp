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

			JSExport<ListView>::AddValueProperty("sections", std::mem_fn(&ListView::js_get_sections),       std::mem_fn(&ListView::js_set_sections));
			JSExport<ListView>::AddValueProperty("footerTitle", std::mem_fn(&ListView::js_get_footerTitle), std::mem_fn(&ListView::js_set_footerTitle));
			JSExport<ListView>::AddValueProperty("headerTitle", std::mem_fn(&ListView::js_get_headerTitle), std::mem_fn(&ListView::js_set_headerTitle));
			JSExport<ListView>::AddValueProperty("searchText", std::mem_fn(&ListView::js_get_searchText),   std::mem_fn(&ListView::js_set_searchText));
			
			JSExport<ListView>::AddValueProperty("footerView", std::mem_fn(&ListView::js_get_footerView), std::mem_fn(&ListView::js_set_footerView));
			JSExport<ListView>::AddValueProperty("headerView", std::mem_fn(&ListView::js_get_headerView), std::mem_fn(&ListView::js_set_headerView));
			JSExport<ListView>::AddValueProperty("searchView", std::mem_fn(&ListView::js_get_searchView),   std::mem_fn(&ListView::js_set_searchView));

			JSExport<ListView>::AddValueProperty("caseInsensitiveSearch", std::mem_fn(&ListView::js_get_caseInsensitiveSearch), std::mem_fn(&ListView::js_set_caseInsensitiveSearch));
			JSExport<ListView>::AddValueProperty("sectionCount", std::mem_fn(&ListView::js_get_sectionCount));
			JSExport<ListView>::AddValueProperty("showVerticalScrollIndicator", std::mem_fn(&ListView::js_get_showVerticalScrollIndicator), std::mem_fn(&ListView::js_set_showVerticalScrollIndicator));
			JSExport<ListView>::AddValueProperty("separatorColor", std::mem_fn(&ListView::js_get_separatorColor), std::mem_fn(&ListView::js_set_separatorColor));
			JSExport<ListView>::AddValueProperty("defaultItemTemplate", std::mem_fn(&ListView::js_get_defaultItemTemplate), std::mem_fn(&ListView::js_set_defaultItemTemplate));

			JSExport<ListView>::AddFunctionProperty("scrollToItem", std::mem_fn(&ListView::js_scrollToItem));
			JSExport<ListView>::AddFunctionProperty("appendSection", std::mem_fn(&ListView::js_appendSection));
			JSExport<ListView>::AddFunctionProperty("deleteSectionAt", std::mem_fn(&ListView::js_deleteSectionAt));
			JSExport<ListView>::AddFunctionProperty("insertSectionAt", std::mem_fn(&ListView::js_insertSectionAt));
			JSExport<ListView>::AddFunctionProperty("replaceSectionAt", std::mem_fn(&ListView::js_replaceSectionAt));
			JSExport<ListView>::AddFunctionProperty("setMarker", std::mem_fn(&ListView::js_setMarker));
			JSExport<ListView>::AddFunctionProperty("getTemplates", std::mem_fn(&ListView::js_getTemplates));
			JSExport<ListView>::AddFunctionProperty("setTemplates", std::mem_fn(&ListView::js_setTemplates));
			JSExport<ListView>::AddFunctionProperty("getSections", std::mem_fn(&ListView::js_getSections));
			JSExport<ListView>::AddFunctionProperty("setSections", std::mem_fn(&ListView::js_setSections));
			JSExport<ListView>::AddFunctionProperty("getFooterTitle", std::mem_fn(&ListView::js_getFooterTitle));
			JSExport<ListView>::AddFunctionProperty("setFooterTitle", std::mem_fn(&ListView::js_setFooterTitle));
			JSExport<ListView>::AddFunctionProperty("getFooterView", std::mem_fn(&ListView::js_getFooterView));
			JSExport<ListView>::AddFunctionProperty("setFooterView", std::mem_fn(&ListView::js_setFooterView));
			JSExport<ListView>::AddFunctionProperty("getHeaderTitle", std::mem_fn(&ListView::js_getHeaderTitle));
			JSExport<ListView>::AddFunctionProperty("setHeaderTitle", std::mem_fn(&ListView::js_setHeaderTitle));
			JSExport<ListView>::AddFunctionProperty("getHeaderView", std::mem_fn(&ListView::js_getHeaderView));
			JSExport<ListView>::AddFunctionProperty("setHeaderView", std::mem_fn(&ListView::js_setHeaderView));
			JSExport<ListView>::AddFunctionProperty("getSearchView", std::mem_fn(&ListView::js_getSearchView));
			JSExport<ListView>::AddFunctionProperty("setSearchView", std::mem_fn(&ListView::js_setSearchView));
			JSExport<ListView>::AddFunctionProperty("getSearchText", std::mem_fn(&ListView::js_getSearchText));
			JSExport<ListView>::AddFunctionProperty("setSearchText", std::mem_fn(&ListView::js_setSearchText));
			JSExport<ListView>::AddFunctionProperty("getCaseInsensitiveSearch", std::mem_fn(&ListView::js_getCaseInsensitiveSearch));
			JSExport<ListView>::AddFunctionProperty("setCaseInsensitiveSearch", std::mem_fn(&ListView::js_setCaseInsensitiveSearch));
			JSExport<ListView>::AddFunctionProperty("getSectionCount", std::mem_fn(&ListView::js_getSectionCount));
			JSExport<ListView>::AddFunctionProperty("getShowVerticalScrollIndicator", std::mem_fn(&ListView::js_getShowVerticalScrollIndicator));
			JSExport<ListView>::AddFunctionProperty("setShowVerticalScrollIndicator", std::mem_fn(&ListView::js_setShowVerticalScrollIndicator));
			JSExport<ListView>::AddFunctionProperty("getSeparatorColor", std::mem_fn(&ListView::js_getSeparatorColor));
			JSExport<ListView>::AddFunctionProperty("setSeparatorColor", std::mem_fn(&ListView::js_setSeparatorColor));
			JSExport<ListView>::AddFunctionProperty("getDefaultItemTemplate", std::mem_fn(&ListView::js_getDefaultItemTemplate));
			JSExport<ListView>::AddFunctionProperty("setDefaultItemTemplate", std::mem_fn(&ListView::js_setDefaultItemTemplate));
		}

		JSValue ListView::js_get_sections() const TITANIUM_NOEXCEPT
		{
			std::vector<JSValue> js_sections;
			const auto sections = get_sections();
			for (auto section : sections) {
				js_sections.push_back(section->get_object());
			}
			return get_context().CreateArray(js_sections);
		}

		bool ListView::js_set_sections(const JSValue& argument) TITANIUM_NOEXCEPT
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

		JSValue ListView::js_get_sectionCount() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(static_cast<uint32_t>(get_sectionCount()));
		}

		JSValue ListView::js_get_footerTitle() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(get_footerTitle());
		}

		bool ListView::js_set_footerTitle(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsString());
			set_footerTitle(static_cast<std::string>(argument));
			return true;
		}

		JSValue ListView::js_get_headerTitle() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(get_headerTitle());
		}

		bool ListView::js_set_headerTitle(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsString());
			set_headerTitle(static_cast<std::string>(argument));
			return true;
		}
		
		JSValue ListView::js_get_footerView() const TITANIUM_NOEXCEPT
		{
			auto view = get_footerView();
			if (view) {
				return view->get_object();
			}  else {
				return get_context().CreateNull();	
			}
		}
		
		bool ListView::js_set_footerView(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsObject());
			set_footerView(static_cast<JSObject>(argument).GetPrivate<View>());
			return true;
		}
		
		JSValue ListView::js_get_headerView() const TITANIUM_NOEXCEPT
		{
			auto view = get_headerView();
			if (view) {
				return view->get_object();
			}  else {
				return get_context().CreateNull();	
			}
		}
		
		bool ListView::js_set_headerView(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsObject());
			set_headerView(static_cast<JSObject>(argument).GetPrivate<View>());
			return true;
		}
		
		JSValue ListView::js_get_searchView() const TITANIUM_NOEXCEPT
		{
			auto view = get_searchView();
			if (view) {
				return view->get_object();
			}  else {
				return get_context().CreateNull();	
			}
		}
		
		bool ListView::js_set_searchView(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsObject());
			set_searchView(static_cast<JSObject>(argument).GetPrivate<View>());
			return true;
		}

		JSValue ListView::js_get_searchText() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(get_searchText());
		}

		bool ListView::js_set_searchText(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsString());
			set_searchText(static_cast<std::string>(argument));
			return true;
		}

		JSValue ListView::js_get_caseInsensitiveSearch() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(get_caseInsensitiveSearch());
		}

		bool ListView::js_set_caseInsensitiveSearch(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_caseInsensitiveSearch(static_cast<bool>(argument));
			return true;
		}

		JSValue ListView::js_get_showVerticalScrollIndicator() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(get_showVerticalScrollIndicator());
		}

		bool ListView::js_set_showVerticalScrollIndicator(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_showVerticalScrollIndicator(static_cast<bool>(argument));
			return true;
		}

		JSValue ListView::js_get_separatorColor() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(get_separatorColor());
		}

		bool ListView::js_set_separatorColor(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsString());
			set_separatorColor(static_cast<std::string>(argument));
			return true;
		}

		JSValue ListView::js_get_defaultItemTemplate() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(get_defaultItemTemplate());
		}

		bool ListView::js_set_defaultItemTemplate(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			set_defaultItemTemplate(static_cast<std::string>(argument));
			return true;
		}

		JSValue ListView::js_scrollToItem(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
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

		JSValue ListView::js_appendSection(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
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

		JSValue ListView::js_deleteSectionAt(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
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

		JSValue ListView::js_insertSectionAt(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
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

		JSValue ListView::js_replaceSectionAt(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
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

		JSValue ListView::js_setMarker(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsObject());
				setMarker(js_to_ListViewMarkerProps(static_cast<JSObject>(_0)));
			}
			return this_object.get_context().CreateUndefined();
		}

		JSValue ListView::js_getTemplates(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return this_object.GetProperty("templates");
		}

		JSValue ListView::js_setTemplates(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				this_object.SetProperty("templates", arguments.at(0));
			}
			return this_object.get_context().CreateUndefined();
		}

		JSValue ListView::js_getSections(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_sections();
		}

		JSValue ListView::js_setSections(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				js_set_sections(_0);
			}
			return this_object.get_context().CreateUndefined();
		}

		JSValue ListView::js_getFooterTitle(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_footerTitle();
		}

		JSValue ListView::js_setFooterTitle(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				js_set_footerTitle(_0);
			}
			return this_object.get_context().CreateUndefined();
		}

		JSValue ListView::js_getFooterView(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return this_object.GetProperty("footerView");
		}

		JSValue ListView::js_setFooterView(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				this_object.SetProperty("footerView", arguments.at(0));
			}
			return this_object.get_context().CreateUndefined();
		}

		JSValue ListView::js_getHeaderTitle(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_headerTitle();
		}

		JSValue ListView::js_setHeaderTitle(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				js_set_headerTitle(_0);
			}
			return this_object.get_context().CreateUndefined();
		}

		JSValue ListView::js_getHeaderView(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return this_object.GetProperty("headerView");
		}

		JSValue ListView::js_setHeaderView(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				this_object.SetProperty("headerView", arguments.at(0));
			}
			return this_object.get_context().CreateUndefined();
		}

		JSValue ListView::js_getSearchView(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return this_object.GetProperty("searchView");
		}

		JSValue ListView::js_setSearchView(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				this_object.SetProperty("searchView", arguments.at(0));
			}
			return this_object.get_context().CreateUndefined();
		}

		JSValue ListView::js_getSearchText(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_searchText();
		}

		JSValue ListView::js_setSearchText(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				js_set_searchText(_0);
			}
			return this_object.get_context().CreateUndefined();
		}

		JSValue ListView::js_getCaseInsensitiveSearch(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_caseInsensitiveSearch();
		}

		JSValue ListView::js_setCaseInsensitiveSearch(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				js_set_caseInsensitiveSearch(_0);
			}
			return this_object.get_context().CreateUndefined();
		}

		JSValue ListView::js_getSectionCount(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_sectionCount();
		}

		JSValue ListView::js_getShowVerticalScrollIndicator(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_showVerticalScrollIndicator();
		}

		JSValue ListView::js_setShowVerticalScrollIndicator(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				js_set_showVerticalScrollIndicator(_0);
			}
			return this_object.get_context().CreateUndefined();
		}

		JSValue ListView::js_getSeparatorColor(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_separatorColor();
		}

		JSValue ListView::js_setSeparatorColor(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				js_set_separatorColor(_0);
			}
			return this_object.get_context().CreateUndefined();
		}

		JSValue ListView::js_getDefaultItemTemplate(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_defaultItemTemplate();
		}

		JSValue ListView::js_setDefaultItemTemplate(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				js_set_defaultItemTemplate(_0);
			}
			return this_object.get_context().CreateUndefined();
		}

	} // namespace UI
} // namespace Titanium