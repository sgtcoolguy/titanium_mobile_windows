/**
 * Titanium.UI.TableViewSection for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/UI/TableViewSection.hpp"
#include "Titanium/detail/TiBase.hpp"

namespace TitaniumWindows
{
	namespace UI
	{

		TableViewSection::TableViewSection(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
			: Titanium::UI::TableViewSection(js_context, arguments)
		{
			TITANIUM_LOG_DEBUG("TableViewSection::ctor Initialize");
		}

		void TableViewSection::JSExportInitialize() {
			JSExport<TableViewSection>::SetClassVersion(1);
			JSExport<TableViewSection>::SetParent(JSExport<Titanium::UI::TableViewSection>::Class());
		}

		std::string TableViewSection::footerTitle() const TITANIUM_NOEXCEPT
		{
			return footerTitle__;
		}

		JSValue TableViewSection::footerView() const TITANIUM_NOEXCEPT
		{
			const auto script = "";
			return get_context().JSEvaluateScript(script);
		}

		std::string TableViewSection::headerTitle() const TITANIUM_NOEXCEPT
		{
			return headerTitle__;
		}

		JSValue TableViewSection::headerView() const TITANIUM_NOEXCEPT
		{
			const auto script = "";
			return get_context().JSEvaluateScript(script);
		}

		JSValue TableViewSection::rowCount() const TITANIUM_NOEXCEPT
		{
			const auto script = "";
			return get_context().JSEvaluateScript(script);
		}

		JSValue TableViewSection::rows() const TITANIUM_NOEXCEPT
		{
			const auto script = "";
			return get_context().JSEvaluateScript(script);
		}

		JSValue TableViewSection::add(JSValue row) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewSection.add is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue TableViewSection::remove(JSValue row) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewSection.remove is not implemented yet");
			return get_context().CreateUndefined();
		}

	}  // namespace UI
}  // namespace TitaniumWindows