#pragma once

#include "Shape.h"

namespace Shapes2D {
	enum class SquareSides {
		LEFT = 0, RIGHT, TOP, BOTTOM, NUM_SQUARE_SIDES
	};

	class Square : public Shape {
	protected:
		double Area() override;
	public:
		Square() : Shape() { lines = { Line(), Line(), Line(), Line() }; mass = Area(); }
		Square(Line line);
		Square(Line line1, Line line2, bool LR = true);
		Square(Square& src);
		~Square() {}

		void CheckCollision(Square* square);
		void SetAllEqualSides(Line line, SquareSides side);
		void SetTwoEqualSidesLR(Line line1, Line line2);	//	left & right sides have equal length
		void SetTwoEqualSidesTB(Line line1, Line line2);	// top & bottom sides have equal length
		void IncDecSquarePoints(std::pair<double, double> incDec);
		void Translate(std::pair<double, double> incDec);
		std::shared_ptr<XY> PointInSquare(Point pt);

		Line GetLine(SquareSides side) { return lines[(int)side]; }
		std::pair<double, double> GetDimmensions();
		Point GetUpperLeftPoint() { return lines[(int)SquareSides::TOP].GetPt1(); }
		Point GetUpperRightPoint() { return lines[(int)SquareSides::TOP].GetPt2(); }
		Point GetLowerLeftPoint() { return lines[(int)SquareSides::BOTTOM].GetPt1(); }
		Point GetLowerRightPoint() { return lines[(int)SquareSides::BOTTOM].GetPt2(); }
		std::wstring GetShapeName() override { return L"Square"; }
		double GetHeight() { return abs(lines[(int)SquareSides::LEFT].rise) + abs(lines[(int)SquareSides::LEFT].run); }
		double GetWidth() { return abs(lines[(int)SquareSides::TOP].rise) + abs(lines[(int)SquareSides::TOP].run); }
	};
}

