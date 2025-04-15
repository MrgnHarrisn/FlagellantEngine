#pragma once

#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

namespace Flag {
    class Time {
    public:
        // Delete copy/move operations
        Time(const Time&) = delete;
        Time& operator=(const Time&) = delete;

        // Meyers' Singleton (returns reference)
        static Time& getInstance() {
            static Time instance;
            return instance;
        }

        // Static interface (forward to instance)
        static void update() { getInstance().i_update(); }
        static float getDeltaTime() { return getInstance().deltaTime; }
        static float getElapsedTime() { return getInstance().elapsedTime; }

    private:
        // Private constructor/destructor
        Time() : deltaTime(0.0f), elapsedTime(0.0f) {}
        ~Time() = default;

        // Instance update logic
        void i_update() {
            deltaTime = deltaClock.restart().asSeconds();
            elapsedTime += deltaTime;
        }

        // Member variables
        float deltaTime;
        float elapsedTime;
        sf::Clock deltaClock;
    };
}