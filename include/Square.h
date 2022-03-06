#pragma once

#include "Polygon.h"
#include "Line.h"

namespace Shapes2D {
	enum class SquareSides {
		TOP = 0, RIGHT, BOTTOM, LEFT, NUM_SQUARE_SIDES
	};

	class Square : public Polygon {
	protected:
		double Area() override;
	public:
		Square();
		Square(std::vector<std::shared_ptr<Point>> srcPoints);
		Square(Line line);
		Square(Line line1, Line line2, bool LR = true);
		Square(Line top, Line right, Line bottom, Line left);
		Square(const Square& src);
		~Square() {}

		void* CheckCollision(Square& object, std::vector<void*> collisionArgs = std::vector<void*>());
		void SetAllEqualSides(Line line, SquareSides side);
		void SetTwoEqualSidesLR(Line line1, Line line2);	//	left & right sides have equal length
		void SetTwoEqualSidesTB(Line line1, Line line2);	// top & bottom sides have equal length
		//std::shared_ptr<XY> PointInSquare(Point pt);
		std::pair<double, double> GetDimmensions();
		bool IsPointInSquare(Point pt);

		inline Line& GetLine(SquareSides side) { return lines[(int)side]; }
		inline std::shared_ptr<Point> GetUpperLeftPoint() { return lines[(int)SquareSides::TOP].GetPt1(); }
		inline std::shared_ptr<Point> GetUpperRightPoint() { return lines[(int)SquareSides::TOP].GetPt2(); }
		inline std::shared_ptr<Point> GetLowerLeftPoint() { return lines[(int)SquareSides::BOTTOM].GetPt2(); }
		inline std::shared_ptr<Point> GetLowerRightPoint() { return lines[(int)SquareSides::BOTTOM].GetPt1(); }
		inline std::wstring GetShapeName() override { return L"Square"; }
		inline double GetHeight() { return abs(lines[(int)SquareSides::LEFT].rise) + abs(lines[(int)SquareSides::LEFT].run); }
		inline double GetWidth() { return abs(lines[(int)SquareSides::TOP].rise) + abs(lines[(int)SquareSides::TOP].run); }
	};
}

