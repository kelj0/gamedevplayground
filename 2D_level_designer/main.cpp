#include <SFML/Window.hpp>
#include "LevelDesigner.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "My window");

    LevelDesigner level_designer(&window, 80);
    // for fps
    float fps_counter = 0.f;
    float fps_clock = 0.f;
    sf::Clock clock;
    while (window.isOpen())
    {
        if (fps_clock >= 1) {
            window.setTitle("Level designer [" + std::to_string(int(fps_counter)) + "]");
            fps_counter = 0;
            fps_clock = 0;
        } else {
            fps_counter += 1;
            fps_clock += clock.restart().asSeconds();
        }

        sf::Event event;
        bool clicked_outside = false;
        while (window.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::LostFocus:
                    clicked_outside = true;
                    break;
                case sf::Event::GainedFocus:
                    clicked_outside = false;
                    break;
            }
        }
        if (!clicked_outside) {
            level_designer.tick();
        }
    }
    return 0;
}