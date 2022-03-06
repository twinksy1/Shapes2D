#pragma once

#include <memory>
#include <vector>
#include <string>
#include "Point.h"

namespace Shapes2D {
	class Shape;
	class CollisionInfo {
	public:
		Shape* collider = NULL;
		XY collisionNormal;
		XY penetrationDepth;
		bool collided = false;

		CollisionInfo();
		~CollisionInfo() {}

		void Clear();
	};
}

