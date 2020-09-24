#pragma once
#include "PhysicsObject.h"
#include "RigidBody.h"

///
///A static object that interacts with other physicsObjects
///
class Plane : public PhysicsObject
{
	public:
		Plane();
		Plane(glm::vec2 normal, float distanceToOrigin);
		~Plane() {}

///
///The update function for the plane
///
		virtual void fixedUpdate(glm::vec2 gravity, float timeStep) {}
		virtual void debug() {}
///
///Draws the plane
///
		virtual void makeGizmo();
///
///Resolves collisions between two physics objects
///
		void resolveCollision(RigidBody* other, glm::vec2 contact);

///
///Returns a normalized vector2
///
		glm::vec2 getNormal() { return m_normal; }
///
///Gets the distance from the points origin
///
		float getDistance() { return m_distanceToOrigin; }

	protected:
		glm::vec2 m_normal;
		float m_distanceToOrigin;
};