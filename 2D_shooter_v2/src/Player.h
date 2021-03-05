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
    float MAX_PLAYER_SPEED = 500;
    Player(std::string name, float x, float y, float width, float height, float fspeed);

    bool checkColisionWithPlayer(Player other);
    void updateMovementVector(sf::Vector2f new_force, float delta_time);
    void applyVectorForce(float delta_time);

    float getSpeed();

    void applyDrag(float d);
};


#endif //INC_2D_SHOOTER_V2_PLAYER_H
