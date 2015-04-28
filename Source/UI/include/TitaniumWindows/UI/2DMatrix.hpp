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
		class TITANIUMWINDOWS_UI_EXPORT TwoDMatrix final : public Titanium::UI::TwoDMatrix, public JSExport<TwoDMatrix>
		{

		public:
			TwoDMatrix(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~TwoDMatrix()                  = default;
			TwoDMatrix(const TwoDMatrix&)            = default;
			TwoDMatrix& operator=(const TwoDMatrix&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			TwoDMatrix(TwoDMatrix&&)                 = default;
			TwoDMatrix& operator=(TwoDMatrix&&)      = default;
#endif

			static void JSExportInitialize();

			virtual void postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) override;

			// properties
			virtual double get_a() const TITANIUM_NOEXCEPT override final;
			virtual void set_a(const double& a) TITANIUM_NOEXCEPT override final;
			virtual double get_b() const TITANIUM_NOEXCEPT override final;
			virtual void set_b(const double& b) TITANIUM_NOEXCEPT override final;
			virtual double get_c() const TITANIUM_NOEXCEPT override final;
			virtual void set_c(const double& c) TITANIUM_NOEXCEPT override final;
			virtual double get_d() const TITANIUM_NOEXCEPT override final;
			virtual void set_d(const double& d) TITANIUM_NOEXCEPT override final;
			virtual double get_tx() const TITANIUM_NOEXCEPT override final;
			virtual void set_tx(const double& tx) TITANIUM_NOEXCEPT override final;
			virtual double get_ty() const TITANIUM_NOEXCEPT override final;
			virtual void set_ty(const double& ty) TITANIUM_NOEXCEPT override final;

			virtual std::shared_ptr<Titanium::UI::TwoDMatrix> invert() TITANIUM_NOEXCEPT;
			virtual std::shared_ptr<Titanium::UI::TwoDMatrix> multiply(const std::shared_ptr<Titanium::UI::TwoDMatrix> t2) TITANIUM_NOEXCEPT;
			virtual std::shared_ptr<Titanium::UI::TwoDMatrix> rotate(const double& angle, const double& toAngle) TITANIUM_NOEXCEPT;
			virtual std::shared_ptr<Titanium::UI::TwoDMatrix> scale(const double& sx, const double& sy, const double& toSx, const double& toSy) TITANIUM_NOEXCEPT;
			virtual std::shared_ptr<Titanium::UI::TwoDMatrix> translate(const double& tx, const double& ty) TITANIUM_NOEXCEPT;

		private:
			Windows::UI::Xaml::Media::TransformGroup^ transform__;

		};
	}  // namespace UI
}  // namespace TitaniumWindows
#endif // _TITANIUMWINDOWS_2DMATRIX_HPP_