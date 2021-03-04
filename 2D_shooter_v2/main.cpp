#include <SFML/Graphics.hpp>
#include "src/Player.h"
#include "src/DebugEngine.h"
#include "src/Engine.h"
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "2D_shooter");
    sf::RenderWindow debug_window(sf::VideoMode(400, 200), "dev");
    debug_window.setPosition(sf::Vector2<int>(400,200));
    window.setPosition(sf::Vector2<int>(800, 200));
    Player p1("player1", 175, 75, 20, 40, 10);
    Player p2("player2", 200, 75, 20, 40, 20);
    std::vector<Player*> players {&p1, &p2};
    float delta_time = 0.f;
    sf::Clock clock;

    sf::Font font;
    if (!font.loadFromFile("/home/kelj0/github/gamedevplayground/Square.ttf"))
        return 0;

    DebugEngine dengine(debug_window, players, font);
    Engine engine(&window, &players, delta_time);
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
                case sf::Event::KeyReleased:
                    if( event.key.code == sf::Keyboard::Up ||
                        event.key.code == sf::Keyboard::Right ||
                        event.key.code == sf::Keyboard::Down ||
                        event.key.code == sf::Keyboard::Left) {

                        p1.is_moving = false;
                    }

                    if (event.key.code == sf::Keyboard::W ||
                        event.key.code == sf::Keyboard::D ||
                        event.key.code == sf::Keyboard::S ||
                        event.key.code == sf::Keyboard::A) {

                        p2.is_moving = false;
                    }
                case sf::Event::LostFocus:
                    p1.is_moving = false;
                    p2.is_moving = false; //TODO add multiplayer support
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