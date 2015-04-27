/**
 * Windows Native Wrapper for Windows.UI.Xaml.Documents.Inline
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.Documents.Inline.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{
				namespace Documents
				{

		Inline::Inline(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::Documents::TextElement(js_context)
		{
		}

		void Inline::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::Documents::Inline^ Inline::unwrapWindows_UI_Xaml_Documents_Inline() const
		{
			return dynamic_cast<::Windows::UI::Xaml::Documents::Inline^>(wrapped__);
		}

		::Windows::UI::Xaml::Documents::Inline^ Inline::unwrap() const
		{
			return unwrapWindows_UI_Xaml_Documents_Inline();
		}

		void Inline::wrap(::Windows::UI::Xaml::Documents::Inline^ object)
		{
			wrapped__ = object;
		}

		void Inline::JSExportInitialize()
		{
			JSExport<Inline>::SetClassVersion(1);
			JSExport<Inline>::SetParent(JSExport<Windows::UI::Xaml::Documents::TextElement>::Class());

		}

				} // namespace Documents
			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
