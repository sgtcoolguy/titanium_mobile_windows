/**
 * LayoutEngine
 * Author: Russell W. McMahon
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "LayoutEngine/TiLayout.h"

#include "gtest/gtest.h"


TEST(ParserProperties, layout_initialization) {
  struct Ti::Layout::LayoutProperties layoutProperties;
  Ti::Layout::layoutPropertiesInitialize(&layoutProperties);

  EXPECT_EQ((int)Ti::Layout::None, (int)layoutProperties.top.valueType);
}

TEST(ParserProperties, populate_layout) {
  struct Ti::Layout::LayoutProperties layoutProperties;
  struct Ti::Layout::InputProperty inputProperty;
  inputProperty.name = Ti::Layout::Top;
  inputProperty.value = "99px";
  // 96 is the ppi
  Ti::Layout::populateLayoutPoperties(inputProperty, &layoutProperties, 96);
  EXPECT_EQ(layoutProperties.top.value, (float)99.0);
}