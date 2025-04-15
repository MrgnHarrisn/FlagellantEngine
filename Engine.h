#pragma once

#include <SFML/Graphics.hpp>
#include "InputManager.h"
#include "PhysicsSystem.h"
#include "Renderer.h"
#include "EntityManager.h"
#include "Time.h"

namespace Flag
{
    class Engine {
    public:
        Engine();
        void run();

    private:
        void processInput();
        void update();
        void render();

    private:
        sf::RenderWindow m_window;
        // PhysicsSystem m_physics;
        // Renderer m_renderer;
        // EntityManager m_entityManager;
        // World m_world;
        // Player m_player;
    };
}

