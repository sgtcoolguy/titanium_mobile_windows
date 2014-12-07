/**
* Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*
*/

#ifndef ELEMENT_H_
#define ELEMENT_H_

#include <string>
#include <vector>
#include "Common.h"

struct Element {
    std::vector<struct Element*> _children;
    struct LayoutCoefficients _layoutCoefficients;
    struct ComputedSize _computedSize;
    double _measuredSandboxWidth;
    double _measuredSandboxHeight;
    double _measuredWidth;
    double _measuredHeight;
    double _measuredLeft;
    double _measuredTop;
    double _borderRightWidth;
    double _borderTopWidth;
    double _borderBottomWidth;
    double _borderLeftWidth;
    enum LayoutType _layoutType;
    enum ElementAlignment _defaultRowAlignment;
    enum ElementAlignment _defaultHorizontalAlignment;
    enum ElementAlignment _defaultVerticalAlignment;
    double _measuredRunningHeight;
    double _measuredRunningWidth;
    double _measuredRowHeight;
    bool _childrenLaidOut;
};

__declspec(dllexport) void elementInitialize(struct Element* element, enum LayoutType);
__declspec(dllexport) void addChildElement(struct Element* parent, struct Element* child);
void removeChildElement(struct Element* parent, struct Element* child);

#endif /* ELEMENT_H_ */
