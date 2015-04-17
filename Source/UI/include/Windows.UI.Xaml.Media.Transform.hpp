/**
 * Windows Native Wrapper for Windows.UI.Xaml.Media.Transform
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _WINDOWS_UI_XAML_MEDIA_TRANSFORM_HPP_
#define _WINDOWS_UI_XAML_MEDIA_TRANSFORM_HPP_

#include "Windows.UI.Xaml.Media.GeneralTransform.hpp"

namespace Windows
{
	namespace UI
	{
		namespace Xaml
		{
			namespace Media
			{


		using namespace HAL;

		class TITANIUMKIT_EXPORT Transform : public Windows::UI::Xaml::Media::GeneralTransform, public JSExport<Transform>
		{

		public:


			Transform(const JSContext&, const std::vector<JSValue>& arguments = {}) TITANIUM_NOEXCEPT;

			virtual ~Transform() = default;
			Transform(const Transform&) = default;
			Transform& operator=(const Transform&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			Transform(Transform&&)                 = default;
			Transform& operator=(Transform&&)      = default;
#endif

			static void JSExportInitialize();

			Windows::UI::Xaml::Media::Transform^ unwrapWindows_UI_Xaml_Media_Transform();
			void wrap(Windows::UI::Xaml::Media::Transform^ object);
		};

			} // namespace Media
		} // namespace Xaml
	} // namespace UI
} // namespace Windows
#endif // _WINDOWS_UI_XAML_MEDIA_TRANSFORM_HPP_
