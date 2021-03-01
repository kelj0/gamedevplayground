#include <SFML/Graphics.hpp>
#include "src/Engine.h"
#include "src/Player.h"
#include "src/Position.h"
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "2D_shooter");
    Player p1("player1", Position(175, 75),200, 200, 100, 0);
    Player p2("player2", Position(400, 75),200, 200, 100, 1);
    std::vector<Player*> players {&p1, &p2};
    float delta_time = 0.f;
    sf::Clock clock;
    Engine engine(&window, &players, delta_time);
    float user_input_move = 0.2;
    while (window.isOpen())
    {
        delta_time = clock.restart().asSeconds();
        if (delta_time > 1.f / 20.f)
            delta_time = 1.f / 20.f;

        sf::Event event;
        while (window.pollEvent(event))
        {
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
                    break;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            engine.movePlayer(p1, p1.getPosition(0,-user_input_move), false);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
            engine.movePlayer(p1, p1.getPosition(user_input_move, 0), false);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) 
            engine.movePlayer(p1, p1.getPosition(0, user_input_move), false);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
            engine.movePlayer(p1, p1.getPosition(-user_input_move, 0), false);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            engine.movePlayer(p2, p2.getPosition(0, -user_input_move), false);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
            engine.movePlayer(p2, p2.getPosition(user_input_move, 0), false);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) 
            engine.movePlayer(p2, p2.getPosition(0, user_input_move), false);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
            engine.movePlayer(p2, p2.getPosition(-user_input_move, 0), false);
        
        engine.tick();
    }

    return 0;
}