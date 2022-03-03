#pragma once

#include <utility>

namespace Shapes2D {

	struct XY {
		double x = 0.0;
		double y = 0.0;

		XY() {}
		XY(double x_p, double y_p) : x(x_p), y(y_p) {}
		XY(const XY& src) { x = src.x; y = src.y; }
	};

	class Point {
	public:
		double x = 0.0;
		double y = 0.0;

		Point() {}
		Point(double x_p, double y_p);
		Point(const Point& src);
		void Rotate(double angle, Point center = Point(0.0, 0.0));
		void Translate(double dx, double dy);
		void Translate(XY xy);
		std::pair<double, double> GetAsPair();
	};
}
