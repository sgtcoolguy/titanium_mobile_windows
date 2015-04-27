/**
 * Titanium.UI.2DMatrix for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_2DMATRIX_HPP_
#define _TITANIUMWINDOWS_2DMATRIX_HPP_

#include "TitaniumWindows/UI/detail/UIBase.hpp"

namespace TitaniumWindows
{
	namespace UI
	{

		using namespace HAL;

		/*!
		  @class

		  @discussion This is the Titanium.UI.2DMatrix implementation for Windows.
		*/
		class TITANIUMWINDOWS_UI_EXPORT 2DMatrix final : public Titanium::UI::2DMatrix, public JSExport<2DMatrix>
		{

		public:
			2DMatrix(const JSContext&, const std::vector<JSValue>& arguments = {}) TITANIUM_NOEXCEPT;

			virtual ~2DMatrix()                  = default;
			2DMatrix(const 2DMatrix&)            = default;
			2DMatrix& operator=(const 2DMatrix&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			2DMatrix(2DMatrix&&)                 = default;
			2DMatrix& operator=(2DMatrix&&)      = default;
#endif

			static void JSExportInitialize();

		private:


			virtual JSValue invert() TITANIUM_NOEXCEPT;
			virtual JSValue multiply(JSValue t2) TITANIUM_NOEXCEPT;
			virtual JSValue rotate(const double& angle, const double& toAngle) TITANIUM_NOEXCEPT;
			virtual JSValue scale(const double& sx, const double& sy, const double& toSx, const double& toSy) TITANIUM_NOEXCEPT;
			virtual JSValue translate(const double& tx, const double& ty) TITANIUM_NOEXCEPT;

		};
	}  // namespace UI
}  // namespace TitaniumWindows
#endif // _TITANIUMWINDOWS_2DMATRIX_HPP_