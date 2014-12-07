/**
* Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*
*/

#ifndef VERTICAL_H_
#define VERTICAL_H_

#include "Common.h"
#include "ParseProperty.h"

struct ComputedSize doVerticalLayout(std::vector<struct Element*>, double, double, bool, bool);
void measureNodeForVerticalLayout(struct LayoutProperties, struct Element*);

#endif /* VERTICAL_H_ */
