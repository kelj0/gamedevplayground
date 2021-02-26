#include <SFML/Graphics.hpp>
#include "src/Engine.h"
#include "src/Player.h"
#include "src/Position.h"
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "2D_shooter");
    Player p1("player1", Position(175, 180),20, 40, 100, 0);
    Player p2("player2", Position(200, 180),20, 40, 100, 1);
    std::vector<Player*> players {&p1, &p2};
    Engine engine(&window,&players);
    float user_input_move = 0.2;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            engine.movePlayer(p1, p1.getPosition(0,-user_input_move));
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
            engine.movePlayer(p1, p1.getPosition(user_input_move, 0));
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) 
            engine.movePlayer(p1, p1.getPosition(0, user_input_move));
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
            engine.movePlayer(p1, p1.getPosition(-user_input_move, 0));
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            engine.movePlayer(p2, p2.getPosition(0, -user_input_move));
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
            engine.movePlayer(p2, p2.getPosition(user_input_move, 0));
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) 
            engine.movePlayer(p2, p2.getPosition(0, user_input_move));
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
            engine.movePlayer(p2, p2.getPosition(-user_input_move, 0));
        
        engine.tick();
    }

    return 0;
}