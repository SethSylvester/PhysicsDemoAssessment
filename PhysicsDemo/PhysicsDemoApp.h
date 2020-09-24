#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "PhysicsScene.h"

///
///The class responsible for running the scene
///
class PhysicsDemoApp : public aie::Application 
{
	public:
		PhysicsDemoApp();
		virtual ~PhysicsDemoApp();

		///
		///The function to start the scene
		///
		virtual bool startup();
///
///Shuts down the scene
///
		virtual void shutdown();

///
///The update function
///
		virtual void update(float deltaTime);
///
///Handles the drawing after the update
///
		virtual void draw();

///
///Sets up the scene
///
		void setupContinuousDemo(glm::vec2 initialPosition, glm::vec2 initialVelocity, float gravity);

///
///Calculates the velocity of an object
///
		glm::vec2 calculateVelocity(glm::vec2 initialPosition, glm::vec2 finalPosition, float gravity, float time);

	protected:
		aie::Renderer2D* m_2dRenderer;
		aie::Font* m_font;
		PhysicsScene* m_physicsScene;
};