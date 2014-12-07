/**
* Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*
*/

#include <stdio.h>
#include "CppUnitTest.h"
#include "Titanium/UI/Layout/ParseProperty.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace titaniun_unittest
{
	TEST_CLASS(property_parser_tests)
	{
	public:

		TEST_METHOD(layout_initialization)
		{
			struct LayoutProperties layoutProperties;
			layoutPropertiesInitialize(&layoutProperties);
			Assert::AreEqual((int)layoutProperties.top.valueType, (int)None);
		}

		TEST_METHOD(populate_layout)
		{
			struct LayoutProperties layoutProperties;
			struct InputProperty inputProperty;
			inputProperty.name = Top;
			inputProperty.value = "99px";
			// 96 is the ppi
			populateLayoutPoperties(inputProperty, &layoutProperties, 96);
			Assert::AreEqual(layoutProperties.top.value, (float)99.0);
		}
	};
}
