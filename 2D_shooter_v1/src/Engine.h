#ifndef INC_2D_SHOOTER_ENGINE_H
#define INC_2D_SHOOTER_ENGINE_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "Player.h"
#include "Position.h"

class Engine {
private:
    float MAX_PLAYER_SPEED = 1000;
    std::vector<Player*>* _players;
    sf::RenderWindow* _window;
    sf::Vector2u _world_dimensions;
    float* delta_time;
    float fly_cooldown = 0.f;
    sf::Vector2f gravity_vector = sf::Vector2f(0, 98.1);
    sf::Vector2f jump_vector = sf::Vector2f(0,-1000);
    void drawPlayers();
public:
    Engine(sf::RenderWindow* window, std::vector<Player*>* players, float* delta_time);
    void tick();
    void movePlayer(Player &p, sf::Vector2f new_vector, bool gravity);

    void applyPhysics();
};


#endif //INC_2D_SHOOTER_ENGINE_H
