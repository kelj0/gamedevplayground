#ifndef INC_2D_SHOOTER_ENGINE_H
#define INC_2D_SHOOTER_ENGINE_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "Player.h"
#include "Position.h"

class Engine {
private:
    std::vector<Player*>* _players;
    sf::RenderWindow* _window;
    sf::Vector2u _world_dimensions;
    void drawPlayers();
public:
    Engine(sf::RenderWindow* window, std::vector<Player*>* players);
    void tick();
    void movePlayer(Player &p, Position new_position);

    void applyPhysics();
};


#endif //INC_2D_SHOOTER_ENGINE_H
