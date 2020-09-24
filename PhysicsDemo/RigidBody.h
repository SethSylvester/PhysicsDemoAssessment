#pragma once
#include "PhysicsObject.h"

///
///Handles using gravity and dynamic collision between physicsobjects
///
class RigidBody : public PhysicsObject
{
	public:
		RigidBody(ShapeType shapeID, glm::vec2 position,
			glm::vec2 velocity, float rotation, float mass, float elasticity, bool isStatic);
		~RigidBody() {}

		///
///The rigidbodies fixedupdate function
///
		virtual void fixedUpdate(glm::vec2 gravity, float timeStep);
		virtual void debug() {}

		///
///Applies a force to the rigidbody
///
		void applyForce(glm::vec2 force, glm::vec2 position);
		///
///Virtual check for collision function to be overridden
///
		virtual bool checkCollision(PhysicsObject* other) = 0;
		///
///A resolve collision between this rigidbody and other rigidbodies function
///
		void resolveCollision(RigidBody* other, glm::vec2 contact, glm::vec2* collisionNormal = nullptr);

		///
///Returns the position
///
		glm::vec2 getPosition() { return m_position; }
		///
///Returns the rigidbodies velocity
///
		glm::vec2 getVelocity() { return m_velocity; }
		///
///Returns the rigidbodies mass
///
		float getMass() { return m_mass; }

		///
///Returns the rotation
///
		float getRotation() { return m_rotation; }
		///
///Returns the angular velocity of the rigidbbody
///

		float getAngularVelocity() { return m_angularVelocity; }
		///
///Returns momentum
///
		float getMoment() { return m_moment; }

		///
///Returns linear drag
///
		float getLinearDrag() { return m_linearDrag; }
		///
///Sets lienar drag
///
		void setLinearDrag(float value) { m_linearDrag = value; }
		///
///Returns angular drag
///
		float getAngularDrag() { return m_angularDrag; }
		///
///Sets angular drag
///
		void setAngularDrag(float value) { m_angularDrag = value; }
		///
///Returns elassticity
///
		float getElasticity() { return m_elasticity; }
		///
///Sets the elasticity
///
		void setElasticity(float value) { m_elasticity = value; }

		void setStatic(bool value) { m_isStatic = value; }

	protected:
		///
///The objects position
///
		glm::vec2 m_position;
		///
///The objects velocity
///
		glm::vec2 m_velocity;
		///
///The objects mass
///
		float m_mass;

		///
///The objects rotation
///
		float m_rotation;
		///
///The objects angular velocity
///
		float m_angularVelocity;
		///
///The objects momentum
///
		float m_moment;

		///
///The linear drag
///
		float m_linearDrag = 0.3f;
		///
///The angular drag
///
		float m_angularDrag = 0.3f;
		///
///The objects elasticity
///
		float m_elasticity = 0.5f;

		bool m_isStatic;
};