/**
* Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*
*/

#include "Element.h"
#include "Composite.h"
#include "Horizontal.h"
#include "Vertical.h"

__declspec(dllexport) bool isNaN(float value) {
  if (value != value)
    return true;
  else
    return false;
}

ComputedSize layoutNode(struct Element* element, double width, double height, bool isWidthSize, bool isHeightSize) {
  ComputedSize computedSize;

  switch ((*element)._layoutType) {
    case Composite:
      computedSize = doCompositeLayout((*element)._children, width, height, isWidthSize, isHeightSize);
      break;
    case Horizontal:
      computedSize = doHorizontalLayout((*element)._children, width, height, isWidthSize, isHeightSize);
      break;
    case Vertical:
      computedSize = doVerticalLayout((*element)._children, width, height, isWidthSize, isHeightSize);
      break;
  }

  return computedSize;
}

void measureNode(enum LayoutType type, struct LayoutProperties* properties, struct Element* element) {
  switch (type) {
    case Composite:
      measureNodeForCompositeLayout(*properties, element);
      break;
    case Horizontal:
      measureNodeForHorizontalLayout(*properties, element);
      break;
    case Vertical:
      measureNodeForVerticalLayout(*properties, element);
      break;
  }
}

