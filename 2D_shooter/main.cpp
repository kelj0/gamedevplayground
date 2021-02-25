#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "Player.h"
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "2D_shooter");
    Player p1("player1", 175, 180 ,20, 40, 100, 0);
    Player p2("player2", 200, 180 ,20, 40, 100, 1);
    std::vector<Player*> players {&p1, &p2};
    Engine engine(&window,&players);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            engine.movePlayer(p1, p1.getX(), p1.getY()-0.5);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
            engine.movePlayer(p1, p1.getX()+0.5, p1.getY());
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) 
            engine.movePlayer(p1, p1.getX(), p1.getY()+0.5);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
            engine.movePlayer(p1, p1.getX()-0.5, p1.getY());
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            engine.movePlayer(p2, p2.getX(), p2.getY()-0.5);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
            engine.movePlayer(p2, p2.getX()+0.5, p2.getY());
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) 
            engine.movePlayer(p2, p2.getX(), p2.getY()+0.5);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
            engine.movePlayer(p2, p2.getX()-0.5, p2.getY());
        
        engine.tick();
    }

    return 0;
}