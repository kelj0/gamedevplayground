#ifndef INC_2D_SHOOTER_PLAYER_H
#define INC_2D_SHOOTER_PLAYER_H

#include <string>
#include <SFML/Graphics/RectangleShape.hpp>

class Player {
private:
    float _x, _y, _width, _height;
    int _hp;
    std::string _name;
public:
    sf::RectangleShape Sprite;

    Player(std::string name, float x, float y, float width, float height, int hp, int color);

    float getX();

    float getY();

    float getWidth();

    float getHeight();

    int getHp();

    std::string getName();

    void setXY(float x, float y);

    bool checkColision(Player p, sf::Vector2u vector2);

};


#endif //INC_2D_SHOOTER_PLAYER_H
