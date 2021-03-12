#include <SFML/Window.hpp>
#include "LevelDesigner.h"

int main()
{
    sf::RenderWindow main_window(sf::VideoMode(800, 800), "Level designer");
    sf::RenderWindow menu_window(sf::VideoMode(200, 800), "Sprite chooser");

    LevelDesigner level_designer(&main_window, &menu_window, 80);
    // for fps
    float fps_counter = 0.f;
    float fps_clock = 0.f;
    sf::Clock clock;
    while (main_window.isOpen())
    {
        if (fps_clock >= 1) {
            main_window.setTitle("Level designer [" + std::to_string(int(fps_counter)) + "]");
            fps_counter = 0;
            fps_clock = 0;
        } else {
            fps_counter += 1;
            fps_clock += clock.restart().asSeconds();
        }

        sf::Event event;
        bool clicked_outside = false;
        while (main_window.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    main_window.close();
                    break;
                case sf::Event::GainedFocus:
                    clicked_outside = false;
                    break;
                default:
                    clicked_outside = true;
                    break;
            }
        }
        if (!clicked_outside) {
            level_designer.tick();
        }
        // set menu main_window left of our main main_window
        menu_window.setPosition(main_window.getPosition() - sf::Vector2i(menu_window.getSize().x,0));
    }
    return 0;
}