/**
* Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*
*/

#include <stdio.h>
#include <math.h>
#include "CppUnitTest.h"
#include "Titanium/UI/Layout/ParseProperty.h"
#include "Titanium/UI/Layout/Element.h"
#include "Titanium/UI/Layout/Common.h"
#include "Titanium/UI/Layout/Composite.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace titaniun_unittest
{
	TEST_CLASS(composite_layout_tests)
	{
	public:
		TEST_METHOD(measure_composite_node_fill_properties)
		{
			struct LayoutProperties layoutProperties;
			layoutPropertiesInitialize(&layoutProperties);
			struct Element* element = new Element();
			elementInitialize(element, Composite);
			layoutProperties.width.valueType = Fill;
			layoutProperties.width.value = NAN;
			layoutProperties.height.valueType = Fill;
			layoutProperties.height.value = NAN;
			measureNodeForCompositeLayout(layoutProperties, element);
			// width height rule
			Assert::AreEqual((*element)._layoutCoefficients.width.x1, 1.0);
			Assert::AreEqual((*element)._layoutCoefficients.width.x2, 0.0);
			Assert::AreEqual((*element)._layoutCoefficients.height.x1, 1.0);
			Assert::AreEqual((*element)._layoutCoefficients.height.x2, 0.0);
			// min-width min-height rule
			Assert::AreEqual(isNaN((*element)._layoutCoefficients.minWidth.x1), true);
			Assert::AreEqual(isNaN((*element)._layoutCoefficients.minWidth.x2), true);
			Assert::AreEqual(isNaN((*element)._layoutCoefficients.minWidth.x3), true);
			Assert::AreEqual(isNaN((*element)._layoutCoefficients.minHeight.x1), true);
			Assert::AreEqual(isNaN((*element)._layoutCoefficients.minHeight.x2), true);
			Assert::AreEqual(isNaN((*element)._layoutCoefficients.minHeight.x3), true);
			// top left rule
			Assert::AreEqual((*element)._layoutCoefficients.top.x1, 0.5);
			Assert::AreEqual((*element)._layoutCoefficients.top.x2, -0.5);
			Assert::AreEqual((*element)._layoutCoefficients.left.x1, 0.5);
			Assert::AreEqual((*element)._layoutCoefficients.left.x2, -0.5);		
		}

		TEST_METHOD(measure_composite_node)
		{
			struct LayoutProperties layoutProperties;
			layoutPropertiesInitialize(&layoutProperties);
			struct Element* element = new Element();
			elementInitialize(element, Composite);
			layoutProperties.width = { Fixed, 100 };
			layoutProperties.height = { Fixed, 100 };
			measureNodeForCompositeLayout(layoutProperties, element);
			// width height rule
			Assert::AreEqual((*element)._layoutCoefficients.width.x1, 0.0);
			Assert::AreEqual((*element)._layoutCoefficients.width.x2, 100.0);
			Assert::AreEqual((*element)._layoutCoefficients.height.x1, 0.0);
			Assert::AreEqual((*element)._layoutCoefficients.height.x2, 100.0);
			// min-width min-height rule
			Assert::AreEqual(isNaN((*element)._layoutCoefficients.minWidth.x1), true);
			Assert::AreEqual(isNaN((*element)._layoutCoefficients.minWidth.x2), true);
			Assert::AreEqual(isNaN((*element)._layoutCoefficients.minWidth.x3), true);
			Assert::AreEqual(isNaN((*element)._layoutCoefficients.minHeight.x1), true);
			Assert::AreEqual(isNaN((*element)._layoutCoefficients.minHeight.x2), true);
			Assert::AreEqual(isNaN((*element)._layoutCoefficients.minHeight.x3), true);
			// top left rule
			Assert::AreEqual((*element)._layoutCoefficients.top.x1, 0.5);
			Assert::AreEqual((*element)._layoutCoefficients.top.x2, -0.5);
			Assert::AreEqual((*element)._layoutCoefficients.left.x1, 0.5);
			Assert::AreEqual((*element)._layoutCoefficients.left.x2, -0.5);
		}
	};
}

