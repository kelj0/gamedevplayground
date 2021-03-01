#ifndef INC_2D_SHOOTER_ENGINE_H
#define INC_2D_SHOOTER_ENGINE_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "Player.h"
#include "Position.h"

class Engine {
private:
    float MAX_PLAYER_SPEED = 1;
    std::vector<Player*>* _players;
    sf::RenderWindow* _window;
    sf::Vector2u _world_dimensions;
    float delta_time;
    void drawPlayers();
public:
    Engine(sf::RenderWindow* window, std::vector<Player*>* players, float &delta_time);
    void tick();
    void movePlayer(Player &p, Position new_position, bool gravity);

    void applyPhysics();

};


#endif //INC_2D_SHOOTER_ENGINE_H
