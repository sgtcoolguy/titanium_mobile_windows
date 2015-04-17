/**
 * Windows Native Wrapper for Windows.UI.Xaml.Media.CacheMode
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _WINDOWS_UI_XAML_MEDIA_CACHEMODE_HPP_
#define _WINDOWS_UI_XAML_MEDIA_CACHEMODE_HPP_

#include "Windows.UI.Xaml.DependencyObject.hpp"

namespace Windows
{
	namespace UI
	{
		namespace Xaml
		{
			namespace Media
			{


		using namespace HAL;

		class TITANIUMKIT_EXPORT CacheMode : public Windows::UI::Xaml::DependencyObject, public JSExport<CacheMode>
		{

		public:


			CacheMode(const JSContext&, const std::vector<JSValue>& arguments = {}) TITANIUM_NOEXCEPT;

			virtual ~CacheMode() = default;
			CacheMode(const CacheMode&) = default;
			CacheMode& operator=(const CacheMode&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			CacheMode(CacheMode&&)                 = default;
			CacheMode& operator=(CacheMode&&)      = default;
#endif

			static void JSExportInitialize();

			Windows::UI::Xaml::Media::CacheMode^ unwrapWindows_UI_Xaml_Media_CacheMode();
			void wrap(Windows::UI::Xaml::Media::CacheMode^ object);
		};

			} // namespace Media
		} // namespace Xaml
	} // namespace UI
} // namespace Windows
#endif // _WINDOWS_UI_XAML_MEDIA_CACHEMODE_HPP_
