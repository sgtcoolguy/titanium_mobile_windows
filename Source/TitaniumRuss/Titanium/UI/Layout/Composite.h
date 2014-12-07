/**
* Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*
*/

#ifndef COMPOSITE_H_
#define COMPOSITE_H_

#include "Common.h"
#include "ParseProperty.h"

__declspec(dllexport) struct ComputedSize doCompositeLayout(std::vector<struct Element*>, double, double, bool, bool);
__declspec(dllexport) void measureNodeForCompositeLayout(struct LayoutProperties, struct Element*);

#endif /* COMPOSITE_H_ */
