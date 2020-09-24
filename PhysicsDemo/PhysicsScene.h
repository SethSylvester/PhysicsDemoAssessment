#pragma once
#include "PhysicsObject.h"
#include "glm\ext.hpp"
#include <vector>

///
///A demo scene for handling collisions
///

class PhysicsScene
{
	public:
		PhysicsScene() : m_timeStep(0.01f), m_gravity(glm::vec2(0.0f, 0.0f)) {}
		~PhysicsScene();

		///
		///A function to add actors to the scene actor
		///
		void addActor(PhysicsObject* actor);

		void removeActor(PhysicsObject* actor);
///
///Updates the main scene
///
		void update(float deltaTime);
///
///Updates all gizmos in the scene
///
		void updateGizmos();
		void debugScene();

///
///Sets the scenes gravity
///
		void setGravity(const glm::vec2 gravity) { m_gravity = gravity; }
///
///Gets the scenes gravity
///
		glm::vec2 getGravity() const { return m_gravity; }
///
///Sets the scenes timestep 
///
		void setTimeStep(const float timeStep) { m_timeStep = timeStep; }
		///
///Gets the scenes timestep
///
		float getTimeStep() const { return m_timeStep; }

		void checkForCollision();

		///
		///Plane to plane collision
		///
		static bool planeToPlane(PhysicsObject*, PhysicsObject*);
		///
		///Plane to plane collision
		///
		static bool planeToSphere(PhysicsObject*, PhysicsObject*);
		///
		///Plane to sphere collision
		///
		static bool sphereToPlane(PhysicsObject*, PhysicsObject*);
		///
		///sphere to sphere collision
		///
		static bool sphereToSphere(PhysicsObject*, PhysicsObject*);

	protected:
		///
		///The variable for gravity
		///
		glm::vec2	m_gravity;
		///
		///The timestep variable
		///
		float		m_timeStep;

		std::vector<PhysicsObject*>	m_actors;
};