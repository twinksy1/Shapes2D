#pragma once

#include "Point.h"
#include <memory>

namespace Shapes2D {
	class Line {
		Point p1;
		Point p2;
		Point midpoint;
	public:
		double run = 0.0;
		double rise = 0.0;

		Line() {}
		Line(double p1X, double p1Y, double p2X, double p2Y);
		Line(Point p1_p, Point p2_p);
		Line(const Line& src);
		~Line() {}

		std::shared_ptr<Point> CheckLineIntersection(Point ptStart, Point ptEnd);
		std::shared_ptr<Point> CheckLineIntersection(Line& line);

		double GetSlope();
		double GetLength();
		void Rotate(double angle, std::shared_ptr<Point> center = NULL);
		void Translate(double dx, double dy);
		void Translate(XY xy);
		void IncDecPt1(std::pair<double, double> incDec);
		void IncDecPt2(std::pair<double, double> incDec);

		void operator=(Line src);

		inline void SetP1(Point p1_p) { p1 = p1_p; }
		inline void SetP2(Point p2_p) { p2 = p2_p; }
		inline void SetP1(double x, double y) { SetP1(Point(x, y)); }
		inline void SetP2(double x, double y) { SetP2(Point(x, y)); }
		inline Point& GetPt1() { return p1; }
		inline Point& GetPt2() { return p2; }
	};
}


