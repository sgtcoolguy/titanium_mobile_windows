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


		TwoDMatrix::TwoDMatrix(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Module(js_context),
			a__(0),
			b__(0),
			c__(0),
			d__(0),
			tx__(0),
			ty__(0)
		{
		}

		void TwoDMatrix::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{
			if (!arguments.empty()) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsObject());
				const auto object = static_cast<JSObject>(_0);
				Titanium::UI::MatrixCreationDict dict = Titanium::UI::js_to_MatrixCreationDict(object);
				JSObject result = get_object();
				auto blah = get_shared_ptr_for_module<Titanium::UI::TwoDMatrix>();
				if (dict.rotate != 0) {
					blah = rotate(dict.rotate, 0);
				}
				if (dict.scale != 1.0) {
					blah = scale(dict.scale, dict.scale, 0, 0);
				}
				result = blah->get_object();
			}
		}

		TITANIUM_PROPERTY_READWRITE(TwoDMatrix, double, a)

		TITANIUM_PROPERTY_READWRITE(TwoDMatrix, double, b)

		TITANIUM_PROPERTY_READWRITE(TwoDMatrix, double, c)

		TITANIUM_PROPERTY_READWRITE(TwoDMatrix, double, d)

		TITANIUM_PROPERTY_READWRITE(TwoDMatrix, double, tx)

		TITANIUM_PROPERTY_READWRITE(TwoDMatrix, double, ty)

		std::shared_ptr<TwoDMatrix> TwoDMatrix::invert() TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("2DMatrix::invert: Unimplemented");
			return nullptr;
		}

		std::shared_ptr<TwoDMatrix> TwoDMatrix::multiply(const std::shared_ptr<TwoDMatrix> t2) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("2DMatrix::multiply: Unimplemented");
			return nullptr;
		}

		std::shared_ptr<TwoDMatrix> TwoDMatrix::rotate(const double& angle, const double& toAngle) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("2DMatrix::rotate: Unimplemented");
			return nullptr;
		}

		std::shared_ptr<TwoDMatrix> TwoDMatrix::scale(const double& sx, const double& sy, const double& toSx, const double& toSy) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("2DMatrix::scale: Unimplemented");
			return nullptr;
		}

		std::shared_ptr<TwoDMatrix> TwoDMatrix::translate(const double& tx, const double& ty) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("2DMatrix::translate: Unimplemented");
			return nullptr;
		}

		void TwoDMatrix::JSExportInitialize() {
			JSExport<TwoDMatrix>::SetClassVersion(1);
			JSExport<TwoDMatrix>::SetParent(JSExport<Module>::Class());

			TITANIUM_ADD_PROPERTY(TwoDMatrix, a);
			TITANIUM_ADD_PROPERTY(TwoDMatrix, b);
			TITANIUM_ADD_PROPERTY(TwoDMatrix, c);
			TITANIUM_ADD_PROPERTY(TwoDMatrix, d);
			TITANIUM_ADD_PROPERTY(TwoDMatrix, tx);
			TITANIUM_ADD_PROPERTY(TwoDMatrix, ty);

			TITANIUM_ADD_FUNCTION(TwoDMatrix, invert);
			TITANIUM_ADD_FUNCTION(TwoDMatrix, multiply);
			TITANIUM_ADD_FUNCTION(TwoDMatrix, rotate);
			TITANIUM_ADD_FUNCTION(TwoDMatrix, scale);
			TITANIUM_ADD_FUNCTION(TwoDMatrix, translate);
			TITANIUM_ADD_FUNCTION(TwoDMatrix, getA);
			TITANIUM_ADD_FUNCTION(TwoDMatrix, setA);
			TITANIUM_ADD_FUNCTION(TwoDMatrix, getB);
			TITANIUM_ADD_FUNCTION(TwoDMatrix, setB);
			TITANIUM_ADD_FUNCTION(TwoDMatrix, getC);
			TITANIUM_ADD_FUNCTION(TwoDMatrix, setC);
			TITANIUM_ADD_FUNCTION(TwoDMatrix, getD);
			TITANIUM_ADD_FUNCTION(TwoDMatrix, setD);
			TITANIUM_ADD_FUNCTION(TwoDMatrix, getTx);
			TITANIUM_ADD_FUNCTION(TwoDMatrix, setTx);
			TITANIUM_ADD_FUNCTION(TwoDMatrix, getTy);
			TITANIUM_ADD_FUNCTION(TwoDMatrix, setTy);
		}

		TITANIUM_PROPERTY_GETTER(TwoDMatrix, a)
		{
			return get_context().CreateNumber(get_a());
		}

		TITANIUM_PROPERTY_SETTER(TwoDMatrix, a)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_a(static_cast<double>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TwoDMatrix, b)
		{
			return get_context().CreateNumber(get_b());
		}

		TITANIUM_PROPERTY_SETTER(TwoDMatrix, b)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_b(static_cast<double>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TwoDMatrix, c)
		{
			return get_context().CreateNumber(get_c());
		}

		TITANIUM_PROPERTY_SETTER(TwoDMatrix, c)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_c(static_cast<double>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TwoDMatrix, d)
		{
			return get_context().CreateNumber(get_d());
		}

		TITANIUM_PROPERTY_SETTER(TwoDMatrix, d)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_d(static_cast<double>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TwoDMatrix, tx)
		{
			return get_context().CreateNumber(get_tx());
		}

		TITANIUM_PROPERTY_SETTER(TwoDMatrix, tx)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_tx(static_cast<double>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TwoDMatrix, ty)
		{
			return get_context().CreateNumber(get_ty());
		}

		TITANIUM_PROPERTY_SETTER(TwoDMatrix, ty)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_ty(static_cast<double>(argument));
			return true;
		}

		TITANIUM_FUNCTION(TwoDMatrix, invert)
		{
			const auto result = invert();
			if (result == nullptr) {
				return get_context().CreateNull();
			}
			return result->get_object();
		}
		TITANIUM_FUNCTION(TwoDMatrix, multiply)
		{
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}

			ENSURE_OBJECT_AT_INDEX(t2, 0,);
			const auto other = t2.GetPrivate<Titanium::UI::TwoDMatrix>();

			const auto result = multiply(other);
			if (result == nullptr) {
				return get_context().CreateNull();
			}
			return result->get_object();
		}

		TITANIUM_FUNCTION(TwoDMatrix, rotate)
		{
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}

			ENSURE_DOUBLE_AT_INDEX(angle, 0);
			ENSURE_OPTIONAL_DOUBLE_AT_INDEX(toAngle, 1, 0);

			const auto result = rotate(angle, toAngle);
			if (result == nullptr) {
				return get_context().CreateNull();
			}
			return result->get_object();
		}

		TITANIUM_FUNCTION(TwoDMatrix, scale)
		{
			if (arguments.size() < 2) {
				return get_context().CreateUndefined();
			}

			ENSURE_DOUBLE_AT_INDEX(sx, 0);
			ENSURE_DOUBLE_AT_INDEX(sy, 1);
			ENSURE_OPTIONAL_DOUBLE_AT_INDEX(toSx, 2, 0);
			ENSURE_OPTIONAL_DOUBLE_AT_INDEX(toSy, 3, 0);

			const auto result = scale(sx, sy, toSx, toSy);
			if (result == nullptr) {
				return get_context().CreateNull();
			}
			return result->get_object();
		}

		TITANIUM_FUNCTION(TwoDMatrix, translate)
		{
			if (arguments.size() < 2) {
				return get_context().CreateUndefined();
			}

			ENSURE_DOUBLE_AT_INDEX(tx, 0);
			ENSURE_DOUBLE_AT_INDEX(ty, 1);

			const auto result = translate(tx, ty);
			if (result == nullptr) {
				return get_context().CreateNull();
			}
			return result->get_object();
		}

		TITANIUM_FUNCTION_AS_GETTER(TwoDMatrix, getA, a)

		TITANIUM_FUNCTION_AS_SETTER(TwoDMatrix, setA, a)

		TITANIUM_FUNCTION_AS_GETTER(TwoDMatrix, getB, b)

		TITANIUM_FUNCTION_AS_SETTER(TwoDMatrix, setB, b)

		TITANIUM_FUNCTION_AS_GETTER(TwoDMatrix, getC, c)

		TITANIUM_FUNCTION_AS_SETTER(TwoDMatrix, setC, c)

		TITANIUM_FUNCTION_AS_GETTER(TwoDMatrix, getD, d)

		TITANIUM_FUNCTION_AS_SETTER(TwoDMatrix, setD, d)

		TITANIUM_FUNCTION_AS_GETTER(TwoDMatrix, getTx, tx)

		TITANIUM_FUNCTION_AS_SETTER(TwoDMatrix, setTx, tx)

		TITANIUM_FUNCTION_AS_GETTER(TwoDMatrix, getTy, ty)

		TITANIUM_FUNCTION_AS_SETTER(TwoDMatrix, setTy, ty)

	} // namespace UI
} // namespace Titanium