#include "Engine.h"

Flag::Engine::Engine()
{
	m_window.create(sf::VideoMode({ 800, 800 }), "Engine Window");
}

void Flag::Engine::run()
{
	while (m_window.isOpen())
	{
		// process events
		processInput();

		update(1.0);
		// render the scene
		render();
	}
}

void Flag::Engine::processInput()
{
	Input::ProcessEvent(m_window);

	if (Input::IsKeyPressed(sf::Keyboard::Key::W)) {
		printf("Pressing W\n");
	}

	printf("Elapsed Time: %f\n", Time::getElapsedTime());
	printf("Delta Time: %f\n", Time::getDeltaTime());

}

// this should run every frame of the game so time should always update here
void Flag::Engine::update(float deltaTime)
{
	// do stuff with the inputs and entites etc.
	Time::update();
	Input::ResetInputs();

}

void Flag::Engine::render()
{
	m_window.clear();
	/*
	// renderer.render() will return a single texture for the window to render
	m_window.draw(m_renderer.render());
	*/
	m_window.display();
}
