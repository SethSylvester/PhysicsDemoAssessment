#pragma once
#include "RigidBody.h"

///
///A circular ball that can bounce around
///
class Sphere : public RigidBody
{
	public:
		Sphere(glm::vec2 position, glm::vec2 velocity,
			float mass, float radius, glm::vec4 color, float elasticity, bool isStatic = false);
		~Sphere() {}

		///
///Draws the ball
///
		virtual void makeGizmo();
		///
///Checks to see if there are any collisions between the sphere and another physicsobject
///
		virtual bool checkCollision(PhysicsObject* other);
		///
///Gets the spheres radius
///
		float getRadius() { return m_radius; }
		///
///Returns the spheres color
///
		glm::vec4 getColor() { return m_color; }

	protected:
		///
///The spheres radius/size
///
		float m_radius;
		///
///The spheres color variable
///
		glm::vec4 m_color;
};