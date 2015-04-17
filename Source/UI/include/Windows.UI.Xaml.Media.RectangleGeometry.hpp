/**
 * Windows Native Wrapper for Windows.UI.Xaml.Media.RectangleGeometry
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _WINDOWS_UI_XAML_MEDIA_RECTANGLEGEOMETRY_HPP_
#define _WINDOWS_UI_XAML_MEDIA_RECTANGLEGEOMETRY_HPP_

#include "Windows.UI.Xaml.Media.Geometry.hpp"

namespace Windows
{
	namespace UI
	{
		namespace Xaml
		{
			namespace Media
			{


		using namespace HAL;

		class TITANIUMKIT_EXPORT RectangleGeometry : public Windows::UI::Xaml::Media::Geometry, public JSExport<RectangleGeometry>
		{

		public:
			TITANIUM_PROPERTY_DEF(Rect);
			TITANIUM_PROPERTY_READONLY_DEF(RectProperty);


			RectangleGeometry(const JSContext&, const std::vector<JSValue>& arguments = {}) TITANIUM_NOEXCEPT;

			virtual ~RectangleGeometry() = default;
			RectangleGeometry(const RectangleGeometry&) = default;
			RectangleGeometry& operator=(const RectangleGeometry&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			RectangleGeometry(RectangleGeometry&&)                 = default;
			RectangleGeometry& operator=(RectangleGeometry&&)      = default;
#endif

			static void JSExportInitialize();

			Windows::UI::Xaml::Media::RectangleGeometry^ unwrapWindows_UI_Xaml_Media_RectangleGeometry();
			void wrap(Windows::UI::Xaml::Media::RectangleGeometry^ object);
		};

			} // namespace Media
		} // namespace Xaml
	} // namespace UI
} // namespace Windows
#endif // _WINDOWS_UI_XAML_MEDIA_RECTANGLEGEOMETRY_HPP_
