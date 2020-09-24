#pragma once
#include "glm\ext.hpp"

///
///The various shapes that can be used to detect collisions
///
enum ShapeType
{
	PLANE = 0,
	SPHERE,
	SHAPE_COUNT
};

///
///A class to form the basis of physicsobjects
///
class PhysicsObject
{
	protected:
		PhysicsObject(ShapeType shapeID) : m_shapeID(shapeID) {}

	public:
///
///A virtual fixed update to be overridden.
///
		virtual void fixedUpdate(glm::vec2 gravity, float timeStep) = 0;
		///
///A virtual debug function to be overridden.
///
		virtual void debug() = 0;
		///
///A virtual makeGizmo function to be overridden.
///
		virtual void makeGizmo() = 0;
		///
///A virtual reset position function to be overridden.
///
		virtual void resetPosition() {};
		///
///Returns the shapeID which is used for detecting collisions
///
		ShapeType getShapeID() { return m_shapeID; }

	protected:
		///
///The ShapeID
///

		ShapeType m_shapeID;
};