#pragma once

#include "Point.h"
#include <memory>
#include <vector>
#include <string>

namespace Shapes2D {
	class CollisionHandler {
	public:
		std::wstring shapeType;
		std::vector<int> collidingLines;
		std::vector<Point> shapePoints;
		std::vector<std::shared_ptr<Point>> pointsOfIntersection;

		CollisionHandler();
		~CollisionHandler() {}

		void Clear();
		int GetClosestPOI(Point pt);
	};
}

