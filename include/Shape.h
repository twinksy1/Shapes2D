#pragma once

#include "Point.h"
#include "CollisionHandler.h"
#include "Point.h"
#include <string>
#include <vector>
#include <functional>

namespace Shapes2D {
	struct PhysicalProperties {
		double mass = 0.0;
		double inverseMass = 0.0;
		XY velocity;
		XY acceleration;
		double gravityConstant = 0.001;
		double friction = 0.0;
		double restitution = 50;		// bounciness

		void operator=(const PhysicalProperties& src) {
			mass = src.mass;
			if (mass == 0.0) {
				inverseMass = 0.0;
			}
			else {
				inverseMass = 1.0 / mass;
			}
			velocity = src.velocity;
			acceleration = src.acceleration;
			gravityConstant = src.gravityConstant;
			friction = src.friction;
			restitution = src.restitution;
		}
	};

	class Shape {
	protected:
		PhysicalProperties physicalProps;
		Point center;
		inline virtual double Area() { return 0.0; }
		bool immovable = true;
		CollisionHandler collisionHandler;
	public:
		std::vector<std::shared_ptr<Point>> points;
		bool falling = true;

		Shape();
		Shape(const Shape& src);
		virtual ~Shape() {}

		virtual void CheckCollision(Shape* shape);
		void Rotate(double angle);
		void CalculateCenter();

		void SetAcceleration(std::pair<double, double> acceleration_p);
		void SetAcceleration(double ddx, double ddy);
		void SetAccelerationX(double ddx);
		void SetAccelerationY(double ddy);

		void AccelerateX();
		void AccelerateY();
		void DeaccelerateX();
		void DeaccelerateY();

		void Translate(double dx, double dy);
		void Translate(XY xy);

		double GetDistToSide();
		void operator=(const Shape& src);
		virtual void Move();
		bool IsInDirection(Shape* shape);

		inline void SetAcceleration(XY acceleration_p) { physicalProps.acceleration = acceleration_p; }
		inline virtual std::wstring GetShapeName() { return L"Shape"; }
		inline bool Collided() { return collisionHandler.collided; }
		inline double GetMass() { return physicalProps.mass; }
		inline double GetInverseMass() { return physicalProps.inverseMass; }
		inline double GetRestitution() { return physicalProps.restitution; }
		inline XY GetVelocity() { return physicalProps.velocity; }
		inline XY GetAcceleration() { return physicalProps.acceleration; }
		inline void SetVelocity(std::pair<double, double> velocity_p) { physicalProps.velocity = XY(velocity_p.first, velocity_p.second); }
		inline void SetVelocity(XY velocity_p) { physicalProps.velocity = velocity_p; }
		inline void SetVelocity(double dx, double dy) { physicalProps.velocity = XY(dx, dy); }
		inline void SetVelocityX(double dx) { physicalProps.velocity.x = dx; }
		inline void SetVelocityY(double dy) { physicalProps.velocity.x = dy; }
		inline bool IsImmovable() { return immovable; }
		inline void SetImmovable() { immovable = true; }
		inline void SetMovable() { immovable = false; }
		inline void SetConstantGravity(double val) { if (val > 1.0 || val < 0.0) { physicalProps.gravityConstant = 0.0; } else { physicalProps.gravityConstant = val; } }
		inline double GetFriction() { return physicalProps.friction; }
	};
}

