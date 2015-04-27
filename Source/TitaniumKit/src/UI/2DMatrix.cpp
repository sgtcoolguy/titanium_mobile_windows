/**
 * TitaniumKit Titanium.UI.2DMatrix
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/2DMatrix.hpp"

namespace Titanium
{
	namespace UI
	{


		2DMatrix::2DMatrix(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
			: Module(js_context, arguments),
			a__(0),
			b__(0),
			c__(0),
			d__(0),
			tx__(0),
			ty__(0)
		{
		}

		TITANIUM_PROPERTY_READWRITE(2DMatrix, double, a)

		TITANIUM_PROPERTY_READWRITE(2DMatrix, double, b)

		TITANIUM_PROPERTY_READWRITE(2DMatrix, double, c)

		TITANIUM_PROPERTY_READWRITE(2DMatrix, double, d)

		TITANIUM_PROPERTY_READWRITE(2DMatrix, double, tx)

		TITANIUM_PROPERTY_READWRITE(2DMatrix, double, ty)

		JSValue 2DMatrix::invert() TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("2DMatrix::invert: Unimplemented");
			return get_context().CreateUndefined();
		}

		JSValue 2DMatrix::multiply(JSValue t2) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("2DMatrix::multiply: Unimplemented");
			return get_context().CreateUndefined();
		}

		JSValue 2DMatrix::rotate(const double& angle, const double& toAngle) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("2DMatrix::rotate: Unimplemented");
			return get_context().CreateUndefined();
		}

		JSValue 2DMatrix::scale(const double& sx, const double& sy, const double& toSx, const double& toSy) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("2DMatrix::scale: Unimplemented");
			return get_context().CreateUndefined();
		}

		JSValue 2DMatrix::translate(const double& tx, const double& ty) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("2DMatrix::translate: Unimplemented");
			return get_context().CreateUndefined();
		}

		void 2DMatrix::JSExportInitialize() {
			JSExport<2DMatrix>::SetClassVersion(1);
			JSExport<2DMatrix>::SetParent(JSExport<Module>::Class());

			TITANIUM_ADD_PROPERTY(2DMatrix, a);
			TITANIUM_ADD_PROPERTY(2DMatrix, b);
			TITANIUM_ADD_PROPERTY(2DMatrix, c);
			TITANIUM_ADD_PROPERTY(2DMatrix, d);
			TITANIUM_ADD_PROPERTY(2DMatrix, tx);
			TITANIUM_ADD_PROPERTY(2DMatrix, ty);

			TITANIUM_ADD_FUNCTION(2DMatrix, invert);
			TITANIUM_ADD_FUNCTION(2DMatrix, multiply);
			TITANIUM_ADD_FUNCTION(2DMatrix, rotate);
			TITANIUM_ADD_FUNCTION(2DMatrix, scale);
			TITANIUM_ADD_FUNCTION(2DMatrix, translate);
			TITANIUM_ADD_FUNCTION(2DMatrix, getA);
			TITANIUM_ADD_FUNCTION(2DMatrix, setA);
			TITANIUM_ADD_FUNCTION(2DMatrix, getB);
			TITANIUM_ADD_FUNCTION(2DMatrix, setB);
			TITANIUM_ADD_FUNCTION(2DMatrix, getC);
			TITANIUM_ADD_FUNCTION(2DMatrix, setC);
			TITANIUM_ADD_FUNCTION(2DMatrix, getD);
			TITANIUM_ADD_FUNCTION(2DMatrix, setD);
			TITANIUM_ADD_FUNCTION(2DMatrix, getTx);
			TITANIUM_ADD_FUNCTION(2DMatrix, setTx);
			TITANIUM_ADD_FUNCTION(2DMatrix, getTy);
			TITANIUM_ADD_FUNCTION(2DMatrix, setTy);
		}

		TITANIUM_PROPERTY_GETTER(2DMatrix, a)
		{
			return get_context().CreateNumber(get_a());
		}

		TITANIUM_PROPERTY_SETTER(2DMatrix, a)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_a(static_cast<double>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(2DMatrix, b)
		{
			return get_context().CreateNumber(get_b());
		}

		TITANIUM_PROPERTY_SETTER(2DMatrix, b)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_b(static_cast<double>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(2DMatrix, c)
		{
			return get_context().CreateNumber(get_c());
		}

		TITANIUM_PROPERTY_SETTER(2DMatrix, c)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_c(static_cast<double>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(2DMatrix, d)
		{
			return get_context().CreateNumber(get_d());
		}

		TITANIUM_PROPERTY_SETTER(2DMatrix, d)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_d(static_cast<double>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(2DMatrix, tx)
		{
			return get_context().CreateNumber(get_tx());
		}

		TITANIUM_PROPERTY_SETTER(2DMatrix, tx)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_tx(static_cast<double>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(2DMatrix, ty)
		{
			return get_context().CreateNumber(get_ty());
		}

		TITANIUM_PROPERTY_SETTER(2DMatrix, ty)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_ty(static_cast<double>(argument));
			return true;
		}

		TITANIUM_FUNCTION(2DMatrix, invert)
		{
			TITANIUM_LOG_WARN("2DMatrix.invert is not implemented yet");

			// FIXME handle return value!
			invert();
			return get_context().CreateUndefined();
		}
		TITANIUM_FUNCTION(2DMatrix, multiply)
		{
			TITANIUM_LOG_WARN("2DMatrix.multiply is not implemented yet");

			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}

			ENSURE_OBJECT_AT_INDEX(t2, 0,);
			// TODO handle return value!
			multiply(t2);
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(2DMatrix, rotate)
		{
			TITANIUM_LOG_WARN("2DMatrix.rotate is not implemented yet");

			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}

			ENSURE_DOUBLE_AT_INDEX(angle, 0, 0);
			ENSURE_OPTIONAL_DOUBLE_AT_INDEX(toAngle, 1, 0);
			// TODO handle return value!
			rotate(angle, toAngle);
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(2DMatrix, scale)
		{
			TITANIUM_LOG_WARN("2DMatrix.scale is not implemented yet");

			if (arguments.size() < 2) {
				return get_context().CreateUndefined();
			}

			ENSURE_DOUBLE_AT_INDEX(sx, 0, 0);
			ENSURE_DOUBLE_AT_INDEX(sy, 1, 0);
			ENSURE_OPTIONAL_DOUBLE_AT_INDEX(toSx, 2, 0);
			ENSURE_OPTIONAL_DOUBLE_AT_INDEX(toSy, 3, 0);
			// TODO handle return value!
			scale(sx, sy, toSx, toSy);
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(2DMatrix, translate)
		{
			TITANIUM_LOG_WARN("2DMatrix.translate is not implemented yet");

			if (arguments.size() < 2) {
				return get_context().CreateUndefined();
			}

			ENSURE_DOUBLE_AT_INDEX(tx, 0, 0);
			ENSURE_DOUBLE_AT_INDEX(ty, 1, 0);
			// TODO handle return value!
			translate(tx, ty);
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION_AS_GETTER(2DMatrix, getA, a)

		TITANIUM_FUNCTION_AS_SETTER(2DMatrix, setA, a)

		TITANIUM_FUNCTION_AS_GETTER(2DMatrix, getB, b)

		TITANIUM_FUNCTION_AS_SETTER(2DMatrix, setB, b)

		TITANIUM_FUNCTION_AS_GETTER(2DMatrix, getC, c)

		TITANIUM_FUNCTION_AS_SETTER(2DMatrix, setC, c)

		TITANIUM_FUNCTION_AS_GETTER(2DMatrix, getD, d)

		TITANIUM_FUNCTION_AS_SETTER(2DMatrix, setD, d)

		TITANIUM_FUNCTION_AS_GETTER(2DMatrix, getTx, tx)

		TITANIUM_FUNCTION_AS_SETTER(2DMatrix, setTx, tx)

		TITANIUM_FUNCTION_AS_GETTER(2DMatrix, getTy, ty)

		TITANIUM_FUNCTION_AS_SETTER(2DMatrix, setTy, ty)

	} // namespace UI
} // namespace Titanium