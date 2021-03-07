#include <SFML/Graphics.hpp>
#include "src/Player.h"
#include "src/DebugEngine.h"
#include "src/Engine.h"
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 1600), "2D_shooter");
    sf::RenderWindow debug_window(sf::VideoMode(400, 200), "dev");
    debug_window.setPosition(sf::Vector2<int>(400,200));
    window.setPosition(sf::Vector2<int>(800, 200));
    Player p1("player1", 175, 75, 200, 300, 500, 50, 1);
    Player p2("player2", 1000, 75, 100, 150, 500, 50, 2);
    std::vector<Player*> players {&p1, &p2};
    float delta_time = 0.f;
    sf::Clock clock;

    sf::Font font;
    if (!font.loadFromFile("/home/kelj0/github/gamedevplayground/Square.ttf"))
        return 0;

    DebugEngine dengine(debug_window, players, font);
    Engine engine(&window, &players, delta_time, window.getSize(), font);
    while (window.isOpen()) {
        delta_time = clock.restart().asSeconds();
        if (delta_time > 1.f / 20.f)
            delta_time = 1.f / 20.f;

        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::LostFocus:
                    players[0]->is_moving = false;
                    players[1]->is_moving = false; //TODO add multiplayer support
                default:
                    ;
                    //break;
            }
        }
        while (debug_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                debug_window.close();
            }
        }


        dengine.tick();
        engine.tick();
    }

    return 0;
}
