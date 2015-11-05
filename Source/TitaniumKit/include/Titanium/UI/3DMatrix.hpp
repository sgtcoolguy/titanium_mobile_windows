/**
 * TitaniumKit Titanium.UI.3DMatrix
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_3DMATRIX_HPP_
#define _TITANIUM_3DMATRIX_HPP_

#include "Titanium/Module.hpp"

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		/*!
		  @class
		  @discussion This is the Titanium 3DMatrix Module.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.UI.3DMatrix
		*/
		class TITANIUMKIT_EXPORT ThreeDMatrix : public Module, public JSExport<ThreeDMatrix>
		{

		public:

			/*!
			  @property
			  @abstract m11
			  @discussion The entry at position [1,1] in the matrix.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(double, m11);

			/*!
			  @property
			  @abstract m12
			  @discussion The entry at position [1,2] in the matrix.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(double, m12);

			/*!
			  @property
			  @abstract m13
			  @discussion The entry at position [1,3] in the matrix.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(double, m13);

			/*!
			  @property
			  @abstract m14
			  @discussion The entry at position [1,4] in the matrix.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(double, m14);

			/*!
			  @property
			  @abstract m21
			  @discussion The entry at position [2,1] in the matrix.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(double, m21);

			/*!
			  @property
			  @abstract m22
			  @discussion The entry at position [2,2] in the matrix.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(double, m22);

			/*!
			  @property
			  @abstract m23
			  @discussion The entry at position [2,3] in the matrix.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(double, m23);

			/*!
			  @property
			  @abstract m24
			  @discussion The entry at position [2,4] in the matrix.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(double, m24);

			/*!
			  @property
			  @abstract m31
			  @discussion The entry at position [3,1] in the matrix.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(double, m31);

			/*!
			  @property
			  @abstract m32
			  @discussion The entry at position [3,2] in the matrix.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(double, m32);

			/*!
			  @property
			  @abstract m33
			  @discussion The entry at position [3,3] in the matrix.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(double, m33);

			/*!
			  @property
			  @abstract m34
			  @discussion The entry at position [3,4] in the matrix.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(double, m34);

			/*!
			  @property
			  @abstract m41
			  @discussion The entry at position [4,1] in the matrix.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(double, m41);

			/*!
			  @property
			  @abstract m42
			  @discussion The entry at position [4,2] in the matrix.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(double, m42);

			/*!
			  @property
			  @abstract m43
			  @discussion The entry at position [4,3] in the matrix.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(double, m43);

			/*!
			  @property
			  @abstract m44
			  @discussion The entry at position [4,4] in the matrix.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(double, m44);

			/*!
			  @method
			  @abstract invert
			  @discussion Returns a matrix constructed by inverting this matrix.
			*/
			virtual std::shared_ptr<ThreeDMatrix> invert() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract multiply
			  @discussion Returns a matrix constructed by combining two existing matrix.
			*/
			virtual std::shared_ptr<ThreeDMatrix> multiply(std::shared_ptr<ThreeDMatrix> t2) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract rotate
			  @discussion Returns a matrix constructed by rotating this matrix.
			*/
			virtual std::shared_ptr<ThreeDMatrix> rotate(const double& angle, const double& x, const double& y, const double& z) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract scale
			  @discussion Returns a matrix constructed by scaling this matrix.
			*/
			virtual std::shared_ptr<ThreeDMatrix> scale(const double& sx, const double& sy, const double& sz) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract translate
			  @discussion Returns a matrix constructed by translating an existing matrix.
			*/
			virtual std::shared_ptr<ThreeDMatrix> translate(const double& tx, const double& ty, const double& tz) TITANIUM_NOEXCEPT;

			ThreeDMatrix(const JSContext&) TITANIUM_NOEXCEPT;
			virtual ~ThreeDMatrix()                  = default;
			ThreeDMatrix(const ThreeDMatrix&)            = default;
			ThreeDMatrix& operator=(const ThreeDMatrix&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			ThreeDMatrix(ThreeDMatrix&&)                 = default;
			ThreeDMatrix& operator=(ThreeDMatrix&&)      = default;
#endif

			static void JSExportInitialize();

			TITANIUM_PROPERTY_DEF(m11);
			TITANIUM_PROPERTY_DEF(m12);
			TITANIUM_PROPERTY_DEF(m13);
			TITANIUM_PROPERTY_DEF(m14);
			TITANIUM_PROPERTY_DEF(m21);
			TITANIUM_PROPERTY_DEF(m22);
			TITANIUM_PROPERTY_DEF(m23);
			TITANIUM_PROPERTY_DEF(m24);
			TITANIUM_PROPERTY_DEF(m31);
			TITANIUM_PROPERTY_DEF(m32);
			TITANIUM_PROPERTY_DEF(m33);
			TITANIUM_PROPERTY_DEF(m34);
			TITANIUM_PROPERTY_DEF(m41);
			TITANIUM_PROPERTY_DEF(m42);
			TITANIUM_PROPERTY_DEF(m43);
			TITANIUM_PROPERTY_DEF(m44);

			TITANIUM_FUNCTION_DEF(invert);
			TITANIUM_FUNCTION_DEF(multiply);
			TITANIUM_FUNCTION_DEF(rotate);
			TITANIUM_FUNCTION_DEF(scale);
			TITANIUM_FUNCTION_DEF(translate);
			TITANIUM_FUNCTION_DEF(getM11);
			TITANIUM_FUNCTION_DEF(setM11);
			TITANIUM_FUNCTION_DEF(getM12);
			TITANIUM_FUNCTION_DEF(setM12);
			TITANIUM_FUNCTION_DEF(getM13);
			TITANIUM_FUNCTION_DEF(setM13);
			TITANIUM_FUNCTION_DEF(getM14);
			TITANIUM_FUNCTION_DEF(setM14);
			TITANIUM_FUNCTION_DEF(getM21);
			TITANIUM_FUNCTION_DEF(setM21);
			TITANIUM_FUNCTION_DEF(getM22);
			TITANIUM_FUNCTION_DEF(setM22);
			TITANIUM_FUNCTION_DEF(getM23);
			TITANIUM_FUNCTION_DEF(setM23);
			TITANIUM_FUNCTION_DEF(getM24);
			TITANIUM_FUNCTION_DEF(setM24);
			TITANIUM_FUNCTION_DEF(getM31);
			TITANIUM_FUNCTION_DEF(setM31);
			TITANIUM_FUNCTION_DEF(getM32);
			TITANIUM_FUNCTION_DEF(setM32);
			TITANIUM_FUNCTION_DEF(getM33);
			TITANIUM_FUNCTION_DEF(setM33);
			TITANIUM_FUNCTION_DEF(getM34);
			TITANIUM_FUNCTION_DEF(setM34);
			TITANIUM_FUNCTION_DEF(getM41);
			TITANIUM_FUNCTION_DEF(setM41);
			TITANIUM_FUNCTION_DEF(getM42);
			TITANIUM_FUNCTION_DEF(setM42);
			TITANIUM_FUNCTION_DEF(getM43);
			TITANIUM_FUNCTION_DEF(setM43);
			TITANIUM_FUNCTION_DEF(getM44);
			TITANIUM_FUNCTION_DEF(setM44);

		protected:
#pragma warning(push)
#pragma warning(disable : 4251)
			double m11__;
			double m12__;
			double m13__;
			double m14__;
			double m21__;
			double m22__;
			double m23__;
			double m24__;
			double m31__;
			double m32__;
			double m33__;
			double m34__;
			double m41__;
			double m42__;
			double m43__;
			double m44__;
#pragma warning(pop)
		};

	} // namespace UI
} // namespace Titanium
#endif // _TITANIUM_3DMATRIX_HPP_