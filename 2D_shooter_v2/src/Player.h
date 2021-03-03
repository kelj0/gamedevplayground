#ifndef INC_2D_SHOOTER_V2_PLAYER_H
#define INC_2D_SHOOTER_V2_PLAYER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <string>
#include <SFML/Graphics/RectangleShape.hpp>

class Player {
public:
    std::string name;
    float x, y, width, height, fspeed;
    sf::Vector2f vec_movement;
    sf::RectangleShape player_sprite;
    bool is_moving = false;
    Player(std::string name, float x, float y, float width, float height, float fspeed);

    bool checkColisionWithPlayer(Player other);
    void updateMovementVector(sf::Vector2f new_force);
    void applyVectorForce(float delta_time);
};


#endif //INC_2D_SHOOTER_V2_PLAYER_H
