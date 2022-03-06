#pragma once

#include "Square.h"
#include "Line.h"

namespace Shapes2D {
	inline bool AreParallel(Line line1, Line line2) {
		return line1.rise == line2.rise && line1.run == line2.run;
	}

	inline Line CreateLine(double x0, double y0, double x1, double y1) {
		return Line(x0, y0, x1, y1);
	}

	inline Square CreateEquilateralSquare(Line line) {
		return Square(line);
	}

	inline Square CreateSquareTB(Line l1, Line l2) {
		Square square;
		square.SetTwoEqualSidesTB(l1, l2);
		return square;
	}

	inline Square CreateSquareLR(Line l1, Line l2) {
		Square square;
		square.SetTwoEqualSidesLR(l1, l2);
		return square;
	}

	inline double GetRelativeDistance(Point a, Point b) {
		double xdiff = a.x - b.x;
		double ydiff = a.y - b.y;
		return (xdiff * xdiff) + (ydiff * ydiff);
	}

	inline double GetAbsoluteDistance(Point a, Point b) {
		double xdiff = a.x - b.x;
		double ydiff = a.y - b.y;
		return sqrt((xdiff * xdiff) + (ydiff * ydiff));
	}

	inline double DotProduct(XY a, XY b) {
		return (a.x * b.x) + (a.y * b.y);
	}
}
