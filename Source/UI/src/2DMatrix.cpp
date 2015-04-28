/**
 * Titanium.UI.2DMatrix for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/UI/2DMatrix.hpp"
#include "Titanium/detail/TiBase.hpp"

// For implementing the bridge getter function for a value property (cpp)
#define CREATE_MATRIX(MATRIX_NAME) \
JSValue Titanium_property = get_context().get_global_object().GetProperty("Titanium"); \
TITANIUM_ASSERT(Titanium_property.IsObject()); \
JSObject Titanium = static_cast<JSObject>(Titanium_property); \
\
JSValue UI_property = Titanium.GetProperty("UI"); \
TITANIUM_ASSERT(UI_property.IsObject()); \
JSObject UI = static_cast<JSObject>(UI_property); \
\
JSValue TwoDMatrix_property = UI.GetProperty("2DMatrix"); \
TITANIUM_ASSERT(TwoDMatrix_property.IsObject()); \
JSObject TwoDMatrix_Class = static_cast<JSObject>(TwoDMatrix_property); \
\
auto MATRIX_NAME = TwoDMatrix_Class.CallAsConstructor()

namespace TitaniumWindows
{
	namespace UI
	{

		TwoDMatrix::TwoDMatrix(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::UI::TwoDMatrix(js_context)
		{
			TITANIUM_LOG_DEBUG("2DMatrix::ctor Initialize");
		}

		void TwoDMatrix::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{
			transform__ = ref new Windows::UI::Xaml::Media::TransformGroup();
			Titanium::UI::TwoDMatrix::postCallAsConstructor(js_context, arguments);
		}

		void TwoDMatrix::JSExportInitialize()
		{
			JSExport<TwoDMatrix>::SetClassVersion(1);
			JSExport<TwoDMatrix>::SetParent(JSExport<Titanium::UI::TwoDMatrix>::Class());
		}

		double TwoDMatrix::get_a() const
		{
			return transform__->Value.M11;
		}

		void TwoDMatrix::set_a(const double& a)
		{
			Titanium::UI::TwoDMatrix::set_a(a);

			auto m = transform__->Value;
			m.M11 = a;
		}

		double TwoDMatrix::get_b() const
		{
			return transform__->Value.M12;
		}

		void TwoDMatrix::set_b(const double& b)
		{
			Titanium::UI::TwoDMatrix::set_b(b);

			auto m = transform__->Value;
			m.M12 = b;
		}

		double TwoDMatrix::get_c() const
		{
			return transform__->Value.M21;
		}

		void TwoDMatrix::set_c(const double& c)
		{
			Titanium::UI::TwoDMatrix::set_c(c);

			auto m = transform__->Value;
			m.M21 = c;
		}

		double TwoDMatrix::get_d() const
		{
			return transform__->Value.M22;
		}

		void TwoDMatrix::set_d(const double& d)
		{
			Titanium::UI::TwoDMatrix::set_d(d);

			auto m = transform__->Value;
			m.M22 = d;
		}

		double TwoDMatrix::get_tx() const
		{
			return transform__->Value.OffsetX;
		}

		void TwoDMatrix::set_tx(const double& tx)
		{
			Titanium::UI::TwoDMatrix::set_tx(tx);

			auto m = transform__->Value;
			m.OffsetX = tx;
		}

		double TwoDMatrix::get_ty() const
		{
			return transform__->Value.OffsetY;
		}

		void TwoDMatrix::set_ty(const double& ty)
		{
			Titanium::UI::TwoDMatrix::set_ty(ty);

			auto m = transform__->Value;
			m.OffsetY = ty;
		}

		std::shared_ptr<Titanium::UI::TwoDMatrix> TwoDMatrix::invert() TITANIUM_NOEXCEPT
		{
			const auto inverse = dynamic_cast<::Windows::UI::Xaml::Media::TransformGroup^>(transform__->Inverse);

			CREATE_MATRIX(matrix);

			auto unwrapped = matrix.GetPrivate<TitaniumWindows::UI::TwoDMatrix>();
			unwrapped->transform__ = inverse;

			return unwrapped;
		}

		std::shared_ptr<Titanium::UI::TwoDMatrix> TwoDMatrix::multiply(const std::shared_ptr<Titanium::UI::TwoDMatrix> t2) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("2DMatrix.multiply is not implemented yet");

			// TODO I don't think there are any transforms equating to this...
			return get_shared_ptr_for_module<Titanium::UI::TwoDMatrix>();
		}

		std::shared_ptr<Titanium::UI::TwoDMatrix> TwoDMatrix::rotate(const double& angle, const double& toAngle) TITANIUM_NOEXCEPT
		{
			auto rotate = ref new Windows::UI::Xaml::Media::RotateTransform();
			rotate->Angle = angle;
			
			CREATE_MATRIX(matrix);

			auto new_matrix = matrix.GetPrivate<TitaniumWindows::UI::TwoDMatrix>();
			new_matrix->transform__->Children->Append(transform__);
			new_matrix->transform__->Children->Append(rotate);
			return new_matrix;
		}

		std::shared_ptr<Titanium::UI::TwoDMatrix> TwoDMatrix::scale(const double& sx, const double& sy, const double& toSx, const double& toSy) TITANIUM_NOEXCEPT
		{
			auto scale = ref new Windows::UI::Xaml::Media::ScaleTransform();
			scale->ScaleX = sx;
			scale->ScaleY = sy;
			// TODO Handle toSx and toSy

			CREATE_MATRIX(matrix);

			auto new_matrix = matrix.GetPrivate<TitaniumWindows::UI::TwoDMatrix>();
			new_matrix->transform__->Children->Append(transform__);
			new_matrix->transform__->Children->Append(scale);
			return new_matrix;
		}

		std::shared_ptr<Titanium::UI::TwoDMatrix> TwoDMatrix::translate(const double& tx, const double& ty) TITANIUM_NOEXCEPT
		{
			auto translate = ref new Windows::UI::Xaml::Media::TranslateTransform();
			translate->X = tx;
			translate->Y = ty;

			CREATE_MATRIX(matrix);

			auto new_matrix = matrix.GetPrivate<TitaniumWindows::UI::TwoDMatrix>();
			new_matrix->transform__->Children->Append(transform__);
			new_matrix->transform__->Children->Append(translate);
			return new_matrix;
		}

	}  // namespace UI
}  // namespace TitaniumWindows