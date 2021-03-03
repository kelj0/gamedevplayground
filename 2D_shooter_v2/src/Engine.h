#ifndef INC_2D_SHOOTER_V2_ENGINE_H
#define INC_2D_SHOOTER_V2_ENGINE_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "Player.h"

class Engine {
private:
    sf::RenderWindow* window;
    std::vector<Player*> *players;
    float *delta_time;
    sf::Vector2f vec_gravity = sf::Vector2f(0,9.81);

public:
    Engine(sf::RenderWindow *window, std::vector<Player*> *players, float &delta_time);
    void handleInput();
    void applyPhysics();
    void updatePositions();
    void tick();

    void drawPlayers();
};


#endif //INC_2D_SHOOTER_V2_ENGINE_H
