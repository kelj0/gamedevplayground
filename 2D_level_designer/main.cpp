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


    // initial draw of everything
    level_designer.drawGrid();
    window.display();
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
        if (fps_clock > 0.2) {
            level_designer.resetUserLock();
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        level_designer.tick();
    }
    return 0;
}