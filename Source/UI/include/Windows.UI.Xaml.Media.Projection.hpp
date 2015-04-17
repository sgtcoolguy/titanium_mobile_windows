/**
 * Windows Native Wrapper for Windows.UI.Xaml.Media.Projection
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _WINDOWS_UI_XAML_MEDIA_PROJECTION_HPP_
#define _WINDOWS_UI_XAML_MEDIA_PROJECTION_HPP_

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

		class TITANIUMKIT_EXPORT Projection : public Windows::UI::Xaml::DependencyObject, public JSExport<Projection>
		{

		public:


			Projection(const JSContext&, const std::vector<JSValue>& arguments = {}) TITANIUM_NOEXCEPT;

			virtual ~Projection() = default;
			Projection(const Projection&) = default;
			Projection& operator=(const Projection&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			Projection(Projection&&)                 = default;
			Projection& operator=(Projection&&)      = default;
#endif

			static void JSExportInitialize();

			Windows::UI::Xaml::Media::Projection^ unwrapWindows_UI_Xaml_Media_Projection();
			void wrap(Windows::UI::Xaml::Media::Projection^ object);
		};

			} // namespace Media
		} // namespace Xaml
	} // namespace UI
} // namespace Windows
#endif // _WINDOWS_UI_XAML_MEDIA_PROJECTION_HPP_
