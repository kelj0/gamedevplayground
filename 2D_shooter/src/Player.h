#ifndef INC_2D_SHOOTER_PLAYER_H
#define INC_2D_SHOOTER_PLAYER_H

#include <string>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Position.h"

class Player {
private:
    Position _pos = Position(0, 0);
    float _width, _height;
    float _moving_speed = 100;
    int _hp;
    std::string _name;
public:
    bool is_moving = false;
    sf::Vector2f movement_vector;

    sf::RectangleShape Sprite;

    Player(std::string name, Position pos, float width, float height, int hp, int color);

    Position getPosition();

    Position getPosition(float relative_x, float relative_y);

    float getSpeed();

    float getWidth();

    float getHeight();

    int getHp();

    std::string getName();

    void setPosition(Position pos);

    void setRelativePosition(float relative_x, float relative_y);

    void setSpeed(float new_speed);

    bool checkColision(Player p, sf::Vector2u vector2);
};


#endif //INC_2D_SHOOTER_PLAYER_H
