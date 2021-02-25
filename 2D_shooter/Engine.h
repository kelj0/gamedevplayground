//
// Created by kelj0 on 2/25/21.
//

#ifndef INC_2D_SHOOTER_ENGINE_H
#define INC_2D_SHOOTER_ENGINE_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "Player.h"

class Engine {
private:
    std::vector<Player*>* _players;
    sf::RenderWindow* _window;
    sf::Vector2u _world_dimensions;
    void drawPlayers();
public:
    Engine(sf::RenderWindow* window, std::vector<Player*>* players);
    void tick();
    void movePlayer(Player &p, float new_x, float new_y);
};


#endif //INC_2D_SHOOTER_ENGINE_H
