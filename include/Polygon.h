#pragma once

#include "Shape.h"

namespace Shapes2D {
	class Line;
	typedef std::function<void* (std::vector<void*>)> CollisionCB;

	// Polygon will have at least 3 points
	// Lines will connect clockwise
	class Polygon : public Shape {
	protected:
		std::vector<Line> lines;
		CollisionCB onCollision;
		virtual double Area() { return 0.0; }
	public:
		Polygon();
		Polygon(std::vector<std::shared_ptr<Point>> points_p);
		Polygon(std::vector<Line> lines);
		Polygon(const Polygon& src);
		~Polygon() {}

		void operator=(const Polygon& src);
		void* CheckCollision(Polygon& object, std::vector<void*> collisionArgs = std::vector<void*>());
		void InitPhysics(PhysicalProperties physicalProps_p);
		void FormLinesFromPoints();
		void FormPointsFromLines();
		void Move() override;
		void SetMass(double mass_p);
	};
}
