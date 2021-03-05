#ifndef INC_2D_SHOOTER_V2_ENGINE_H
#define INC_2D_SHOOTER_V2_ENGINE_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include "Player.h"

class Engine {
private:
    sf::RenderWindow* window;
    std::vector<Player*> *players;
    float *delta_time;
    sf::Vector2f vec_gravity = sf::Vector2f(0,98.1);
    float air_resistance = 0.001;
    sf::Font font;
public:
    sf::Vector2u world_dimensions;

    Engine(sf::RenderWindow *window, std::vector<Player*> *players, float &delta_time, sf::Vector2u world_dimensions, sf::Font font);
    void handleInput();
    int checkColisionWithWorld(Player p);
    void applyPhysics();
    void updatePositions();
    void tick();

    void drawPlayers();

    sf::Text p1;
    sf::Text p2;
};


#endif //INC_2D_SHOOTER_V2_ENGINE_H
