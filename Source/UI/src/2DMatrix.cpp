/**
 * Titanium.UI.2DMatrix for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/UI/2DMatrix.hpp"
#include "Titanium/detail/TiBase.hpp"

namespace TitaniumWindows
{
	namespace UI
	{

		2DMatrix::2DMatrix(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
			: Titanium::UI::2DMatrix(js_context, arguments)
		{
			TITANIUM_LOG_DEBUG("2DMatrix::ctor Initialize");
		}

		void 2DMatrix::JSExportInitialize() {
			JSExport<2DMatrix>::SetClassVersion(1);
			JSExport<2DMatrix>::SetParent(JSExport<Titanium::UI::2DMatrix>::Class());
		}

		JSValue 2DMatrix::invert() TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("2DMatrix.invert is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue 2DMatrix::multiply(JSValue t2) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("2DMatrix.multiply is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue 2DMatrix::rotate(const double& angle, const double& toAngle) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("2DMatrix.rotate is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue 2DMatrix::scale(const double& sx, const double& sy, const double& toSx, const double& toSy) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("2DMatrix.scale is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue 2DMatrix::translate(const double& tx, const double& ty) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("2DMatrix.translate is not implemented yet");
			return get_context().CreateUndefined();
		}

	}  // namespace UI
}  // namespace TitaniumWindows