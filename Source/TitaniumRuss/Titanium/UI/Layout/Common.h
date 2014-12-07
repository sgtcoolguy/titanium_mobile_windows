/**
* Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*
*/

#ifndef COMMON_H_
#define COMMON_H_

enum LayoutType {Composite = 0, Horizontal, Vertical};
enum ElementAlignment {Start = 0, Center, End};

struct ComputedSize {
	double width;
	double height;
};

struct ThreeCoefficients {
	double x1;
	double x2;
	double x3;
};

struct FourCoefficients {
	double x1;
	double x2;
	double x3;
	double x4;
};

struct LayoutCoefficients {
	struct ThreeCoefficients width;
	struct ThreeCoefficients minWidth;
	struct ThreeCoefficients sandboxWidth;
	struct ThreeCoefficients height;
	struct ThreeCoefficients minHeight;
	struct ThreeCoefficients sandboxHeight;
	struct ThreeCoefficients left;
	struct FourCoefficients top;
};

__declspec(dllexport) bool isNaN(float);
ComputedSize layoutNode(struct Element*, double, double, bool, bool);
void measureNode(enum LayoutType type, struct LayoutProperties* properties, struct Element* element);

#endif /* COMMON_H_ */
