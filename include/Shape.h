#pragma once

#include "Point.h"
#include "CollisionHandler.h"
#include "Line.h"
#include <string>
#include <vector>
#include <functional>

namespace Shapes2D {
	class Shape {
	protected:
		XY velocity;
		XY acceleration;
		double mass = 0.0;
		double constantGravity = 0.1;
		Point center;
		std::function<bool(Shape*)> onCollisionShapeCB;
		std::function<bool(Line*)> onCollisionLineCB;
		virtual bool OnCollision(Shape* shape);
		virtual bool OnCollision(Line* line);
		inline virtual double Area() { return 0.0; }
	public:
		CollisionHandler collisionHandler;
		bool immovable = false;
		std::vector<Line> lines;
		bool xAxisCollision = false;
		bool yAxisCollision = false;
		bool grounded = false;
		bool falling = true;
		double friction = 0.001;

		Shape();
		Shape(const Shape& src);
		virtual ~Shape() {}

		virtual bool CheckCollision(Line line);
		virtual void CheckCollision(Shape* shape);
		void Rotate(double angle);
		void CalculateCenter();
		void MoveX();
		void MoveY();
		void OnHorizontalCollision(Shape* shape);
		void OnVerticalCollision(Shape* shape);

		void SetAcceleration(std::pair<double, double> acceleration_p);
		void SetAcceleration(XY acceleration_p) { acceleration = acceleration_p; }
		void SetAcceleration(double ddx, double ddy);
		void SetAccelerationX(double ddx);
		void SetAccelerationY(double ddy);

		void AccelerateX();
		void AccelerateY();
		void DeaccelerateX();
		void DeaccelerateY();

		double GetDistToSide();
		void operator=(const Shape& src);
		void Move();

		inline virtual std::wstring GetShapeName() { return L"Shape"; }
		inline double GetMass() { return mass; }
		inline XY GetVelocity() { return velocity; }
		inline XY GetAcceleration() { return acceleration; }
		inline void SetOnCollisionCB(std::function<bool(Shape*)> cbFunc) { onCollisionShapeCB = cbFunc; }
		inline void SetVelocity(std::pair<double, double> velocity_p) { velocity = XY(velocity_p.first, velocity_p.second); }
		inline void SetVelocity(XY velocity_p) { velocity = velocity_p; }
		inline void SetVelocity(double dx, double dy) { velocity = XY(dx, dy); }
		inline void SetVelocityX(double dx) { velocity.x = dx; }
		inline void SetVelocityY(double dy) { velocity.x = dy; }
		inline void SetConstantGravity(double val) { if (val > 1.0 || val < 0.0) { constantGravity = 0.0; } else { constantGravity = val; } }
		inline double GetFriction() { return friction; }
		inline void SetMass() { mass = Area(); }
	};
}

