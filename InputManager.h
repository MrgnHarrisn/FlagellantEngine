#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <unordered_map>
#include <string>
#include <optional>

namespace Flag {
    class Input {
    public:
        // Delete copy/move operations
        Input(const Input&) = delete;
        Input& operator=(const Input&) = delete;

        // Meyers' Singleton
        static Input& getInstance() {
            static Input instance;
            return instance;
        }

        // Static interface ==============================================
        static void ProcessEvent(sf::Window& window) {
            getInstance().i_process_event(window);
        }

        static bool IsKeyPressed(sf::Keyboard::Key key) {
            return getInstance().i_is_key_pressed(key);
        }

        static void ResetInputs() {
            getInstance().i_reset_inputs();
        }

    private:
        // Instance implementation =======================================
        Input() = default;
        ~Input() = default;

        void i_process_event(sf::Window& window) {
            
            while (auto event = window.pollEvent())
            {
                if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
                {
                    button_inputs[keyPressed->code] = true;
                }
                else if (const auto* keyPressed = event->getIf<sf::Event::KeyReleased>())
                {
                    button_inputs[keyPressed->code] = false;
                }
            }
        }

        bool i_is_key_pressed(sf::Keyboard::Key key) {
            return button_inputs.count(key) ? button_inputs[key] : false;
        }

        void i_reset_inputs() {
            for (auto& pair : button_inputs)
                pair.second = false;
        }

        // Instance state ================================================
        std::unordered_map<sf::Keyboard::Key, bool> button_inputs;
        bool m_window_closed = false;
    };
}