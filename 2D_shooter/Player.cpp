#include "Player.h"


Player::Player(std::string name, float x, float y, float width, float height, int hp, int color){
    this->_name = name;
    setXY(x,y);
    this->_width = width;
    this->_height = height;
    this->_hp = hp;
    Sprite = sf::RectangleShape(sf::Vector2f(width, height));
    switch (color) {
        case 0:
            Sprite.setFillColor(sf::Color::Green);
            break;
        case 1:
            Sprite.setFillColor(sf::Color::Blue);
            break;
        default:
            Sprite.setFillColor(sf::Color::Green);
            break;
    }
    Sprite.setPosition(x, y);
}

float Player::getX() {
    return this->_x;
}

float Player::getY() {
    return this->_y;
}

int Player::getHp(){
    return this->_hp;
}

bool Player::checkColision(Player p, sf::Vector2u world_dimensions) {

    if ( this->getX() < 0 ||
         this->getY() < 0 ||
         this->getX() + this->getWidth() > world_dimensions.x ||
         this->getY() + this->getHeight() > world_dimensions.y
        ) {
        return true;
    } else if ( this->getName() != p.getName() &&
                this->getY() < p.getY() + p.getHeight() &&
                this->getY() + this->getHeight() > p.getY() &&
                this->getX() < p.getX() + p.getWidth() &&
                this->getX() + this->getWidth() > p.getX()
            ) {
        return true;
    }
    return false;
}

float Player::getWidth() {
    return this->_width;
}

float Player::getHeight() {
    return this->_height;
}

std::string Player::getName() {
    return this->_name;
}

void Player::setXY(float x, float y) {
    this->_x = x;
    this->_y = y;
    Sprite.setPosition(x,y);
}
