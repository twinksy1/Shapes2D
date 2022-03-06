#pragma once

#include "Shape.h"
#include <memory>

namespace Shapes2D {
	class Line : Shape {
	public:
		double run = 0.0;
		double rise = 0.0;

		Line() { points = { std::make_shared<Point>(), std::make_shared<Point>() }; }
		Line(double p1X, double p1Y, double p2X, double p2Y);
		Line(std::shared_ptr<Point> p1_p, std::shared_ptr<Point> p2_p);
		Line(const Line& src);
		~Line() {}

		std::shared_ptr<Point> CheckLineIntersection(Point ptStart, Point ptEnd);
		std::shared_ptr<Point> CheckLineIntersection(Line& line);
		std::shared_ptr<Point> GetPt1() { return points[0]; }
		std::shared_ptr<Point> GetPt2() { return points[1]; }

		double GetSlope();
		double GetLength();
		void operator=(Line src);
	};
}


