/**
 * LayoutEngine
 * Author: Russell W. McMahon
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

 #include <stdio.h>

#include "LayoutEngine/LayoutEngine.hpp"

int main(int argc, char **argv) {
  printf("Running main() from a dektop executable to show basic layout engine flow.c\n");
  
  // This sample shows a layout of 3 elements with fixed (not % or fill constants) values. The top level
  // element After processing
  // by the Layout Engine the node (e1, e2, e3) will have in the element->measuredX the actual absolute 
  // postion to be used to postion the element on the display.

  // Element 1 - Top Level element does not need to be measured it acts as the bounds for the system
  // display.
  struct  Ti::Layout::LayoutProperties layoutProperties;
  Ti::Layout::layoutPropertiesInitialize(&layoutProperties);
  struct  Ti::Layout::Element* e1 = new  Ti::Layout::Element();
  Ti::Layout::elementInitialize(e1, Ti::Layout::Horizontal); 

  // Element 2
  layoutProperties.width.value = 50;
  layoutProperties.width.valueType = Ti::Layout::Fixed;
  layoutProperties.height.value = 20;
  layoutProperties.height.valueType = Ti::Layout::Fixed;
  struct Ti::Layout::Element* e2 = new Ti::Layout::Element();
  Ti::Layout::elementInitialize(e2, Ti::Layout::Composite);
  Ti::Layout::measureNodeForHorizontalLayout(layoutProperties, e2);

  // Element 3
  layoutProperties.width.value = 50;
  layoutProperties.width.valueType = Ti::Layout::Fixed; 
  layoutProperties.height.value = 40;
  layoutProperties.height.valueType = Ti::Layout::Fixed;
  struct Ti::Layout::Element* e3 = new Ti::Layout::Element();
  Ti::Layout::elementInitialize(e3, Ti::Layout::Composite);
  Ti::Layout::measureNodeForHorizontalLayout(layoutProperties, e3);


  // Create the display tree. This example has Element 1 with two children but any graph of elements
  // would work as long as the graph has a single root.
  Ti::Layout::addChildElement(e1, e2);
  Ti::Layout::addChildElement(e1, e3);
  
  // Do the calculations based on the Titanium layout rules and return the elements with the measured values
  // returned.
  Ti::Layout::doHorizontalLayout((*e1).children, 100, 100, false, false);

  printf("Element 2 Top is: %d", (int)(*e2)._measuredTop);
  printf("Element 2 Left is: %d", (int)(*e2)._measuredLeft);
  printf("Element 2 Width is: %d", (int)(*e2)._measuredWidth);
  printf("Element 2 Height is: %d", (int)(*e2)._measuredHeight);

  printf("Element 3 Top is: %d", (int)(*e3)._measuredTop);
  printf("Element 3 Left is: %d", (int)(*e3)._measuredLeft);
  printf("Element 3 Width is: %d", (int)(*e3)._measuredWidth);
  printf("Element 3 Height is: %d", (int)(*e3)._measuredHeight);

  return 0;
}
