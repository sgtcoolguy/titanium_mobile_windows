/**
* Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*
*/

#ifndef HORIZONTAL_H_
#define HORIZONTAL_H_

#include "Common.h"
#include "ParseProperty.h"

__declspec(dllexport) struct ComputedSize doHorizontalLayout(std::vector<struct Element*>, double, double, bool, bool);
__declspec(dllexport) void measureNodeForHorizontalLayout(struct LayoutProperties, struct Element*);

#endif /* HORIZONTAL_H_ */
