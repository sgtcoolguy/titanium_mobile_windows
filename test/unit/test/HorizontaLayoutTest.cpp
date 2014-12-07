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
#include "Titanium/UI/Layout/Horizontal.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace titaniun_unittest
{
	TEST_CLASS(horizontal_layout_tests)
	{
	public:
		TEST_METHOD(measure_horizontal_node)
		{
			struct LayoutProperties layoutProperties;
			layoutPropertiesInitialize(&layoutProperties);
			struct Element* element = new Element();
			elementInitialize(element, Horizontal);
			layoutProperties.width = { Fixed, 50 };
			layoutProperties.height = { Fixed, 20 };
			measureNodeForHorizontalLayout(layoutProperties, element);
			// top left rule
			Assert::AreEqual((*element)._layoutCoefficients.top.x1, 0.0);
			Assert::AreEqual((*element)._layoutCoefficients.top.x2, 0.5);
			Assert::AreEqual((*element)._layoutCoefficients.top.x3, -0.5);
			Assert::AreEqual((*element)._layoutCoefficients.top.x4, 0.0);
		}

		TEST_METHOD(horizontal_layout)
		{
			struct LayoutProperties layoutProperties;
			layoutPropertiesInitialize(&layoutProperties);
			struct Element* e1 = new Element();
			elementInitialize(e1, Horizontal); // Device - top level window
			// e2
			layoutProperties.width = { Fixed, 50 };
			layoutProperties.height = { Fixed, 20 };
			struct Element* e2 = new Element();
			elementInitialize(e2, Composite);
			measureNodeForHorizontalLayout(layoutProperties, e2);
			// e3
			layoutProperties.width = { Fixed, 50 };
			layoutProperties.height = { Fixed, 40 };
			struct Element* e3 = new Element();
			elementInitialize(e3, Composite);
			measureNodeForHorizontalLayout(layoutProperties, e3);
			addChildElement(e1, e2);
			addChildElement(e1, e3);
			doHorizontalLayout((*e1)._children, 100, 100, false, false);
			Assert::AreEqual((*e2)._measuredTop, 10.0);
			Assert::AreEqual((*e2)._measuredLeft, 0.0);
			Assert::AreEqual((*e2)._measuredWidth, 50.0);
			Assert::AreEqual((*e2)._measuredHeight, 20.0);
			Assert::AreEqual((*e3)._measuredTop, 0.0);
			Assert::AreEqual((*e3)._measuredLeft, 50.0);
			Assert::AreEqual((*e3)._measuredWidth, 50.0);
			Assert::AreEqual((*e3)._measuredHeight, 40.0);
		}
	};
}
