#pragma once

#include <utility>

namespace Shapes2D {

	class XY {
	public:
		double x = 0.0;
		double y = 0.0;

		XY() {}
		XY(double x_p, double y_p) : x(x_p), y(y_p) {}
		XY(const XY& src) { x = src.x; y = src.y; }

		XY operator+(const XY& other) const;
		XY operator-(const XY& other) const;
		XY operator-(const double difference) const;
		XY operator-() const;
		XY operator*(const XY& other) const;
		XY operator*(const double scalar) const;
		XY operator/(const double divisor) const;
		void operator-=(const XY& other);
		void operator+=(const XY& other);
		void operator=(const XY& src);
		bool operator>(const XY& other) const;
		bool operator<(const XY& other) const;
		bool operator==(const XY& other) const;
		bool operator<=(const XY& other) const;
		bool operator>=(const XY& other) const;

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
		double GetRelativeDistance(Point pt);
		double GetAbsoluteDistance(Point pt);
		std::pair<double, double> GetAsPair();

		XY operator-(const Point& other) const;
		Point operator+(const Point& other) const;
	};
}
