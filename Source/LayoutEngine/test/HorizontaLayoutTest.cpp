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

TEST(HorizontalLayout, measure_horizontal_node) {
  struct Ti::Layout::LayoutProperties layoutProperties;
  Ti::Layout::layoutPropertiesInitialize(&layoutProperties);
  struct Ti::Layout::Element* element = new Ti::Layout::Element();
  Ti::Layout::elementInitialize(element, Ti::Layout::Horizontal);
  layoutProperties.width.value = 50;
  layoutProperties.width.valueType = Ti::Layout::Fixed;
  layoutProperties.height.value = 20;
  layoutProperties.height.valueType = Ti::Layout::Fixed;
  measureNodeForHorizontalLayout(layoutProperties, element);

  // top left rule
  EXPECT_EQ(0.0, (*element).layoutCoefficients.top.x1);
  EXPECT_EQ(0.5, (*element).layoutCoefficients.top.x2);
  EXPECT_EQ(-0.5, (*element).layoutCoefficients.top.x3);
  EXPECT_EQ(0.0, (*element).layoutCoefficients.top.x4);
}

TEST(HorizontalLayout, horizontal_layout) {
  struct  Ti::Layout::LayoutProperties layoutProperties;
  Ti::Layout::layoutPropertiesInitialize(&layoutProperties);
  struct  Ti::Layout::Element* e1 = new  Ti::Layout::Element();
  Ti::Layout::elementInitialize(e1, Ti::Layout::Horizontal); // Device - top level window
  // e2
  layoutProperties.width.value = 50;
  layoutProperties.width.valueType = Ti::Layout::Fixed;
  layoutProperties.height.value = 20;
  layoutProperties.height.valueType = Ti::Layout::Fixed;
  struct Ti::Layout::Element* e2 = new Ti::Layout::Element();
  Ti::Layout::elementInitialize(e2, Ti::Layout::Composite);
  Ti::Layout::measureNodeForHorizontalLayout(layoutProperties, e2);
  // e3
  layoutProperties.width.value = 50;
  layoutProperties.width.valueType = Ti::Layout::Fixed; 
  layoutProperties.height.value = 40;
  layoutProperties.height.valueType = Ti::Layout::Fixed;
  struct Ti::Layout::Element* e3 = new Ti::Layout::Element();
  Ti::Layout::elementInitialize(e3, Ti::Layout::Composite);
  Ti::Layout::measureNodeForHorizontalLayout(layoutProperties, e3);
  Ti::Layout::addChildElement(e1, e2);
  Ti::Layout::addChildElement(e1, e3);
  Ti::Layout::doHorizontalLayout((*e1).children, 100, 100, false, false);

  EXPECT_EQ(10.0, (*e2).measuredTop, 10.0);
  EXPECT_EQ(0.0, (*e2).measuredLeft, 0.0);
  EXPECT_EQ(50.0, (*e2).measuredWidth, 50.0);
  EXPECT_EQ(20.0, (*e2).measuredHeight, 20.0);
  EXPECT_EQ(0.0, (*e3).measuredTop, 0.0);
  EXPECT_EQ(50.0, (*e3).measuredLeft, 50.0);
  EXPECT_EQ(50.0, (*e3).measuredWidth, 50.0);
  EXPECT_EQ(40.0, (*e3).measuredHeight, 40.0);
}
