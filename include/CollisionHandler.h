#pragma once

#include <memory>
#include <vector>
#include <string>
#include "Point.h"
//#include "Shape.h"

namespace Shapes2D {
	class Shape;
	class CollisionHandler {
	public:
		std::wstring shapeType;
		std::vector<int> collidingLines;
		std::vector<Point> shapePoints;
		std::vector<Shape*> colliders;
		std::vector<std::shared_ptr<Point>> pointsOfIntersection;
		bool collided = false;

		CollisionHandler();
		~CollisionHandler() {}

		void Clear();
		int GetClosestPOI(Point pt);
	};
}

