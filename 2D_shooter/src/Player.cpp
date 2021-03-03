#include "Player.h"


Player::Player(std::string name, Position pos, float width, float height, int hp, int color){
    this->_name = name;
    _pos = pos;
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
    Sprite.setPosition(_pos.getX(), _pos.getY());
}

int Player::getHp(){
    return this->_hp;
}

bool Player::checkColision(Player p, sf::Vector2u world_dimensions) {

    if ( this->_pos.getX() < 0 ||
         this->_pos.getY() < 0 ||
         this->_pos.getX() + this->getWidth() > world_dimensions.x ||
         this->_pos.getY() + this->getHeight() > world_dimensions.y
        ) {
        return true;
    } else if ( this->getName() != p.getName() &&
                this->_pos.getY() < p.getPosition().getY() + p.getHeight() &&
                this->_pos.getY() + this->getHeight() > p.getPosition().getY() &&
                this->_pos.getX() < p.getPosition().getX() + p.getWidth() &&
                this->_pos.getX() + this->getWidth() > p.getPosition().getX()
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

Position Player::getPosition() {
    return _pos;
}

Position Player::getPosition(float relative_x = 0, float relative_y = 0) {
    return Position(_pos.getX()+relative_x, _pos.getY()+relative_y);
}

void Player::setPosition(Position pos) {
    _pos = pos;
    Sprite.setPosition(_pos.getX(), _pos.getY());
}

void Player::setRelativePosition(float relative_x, float relative_y) {
    _pos = Position(_pos.getX()+relative_x, _pos.getY()+relative_y);
    Sprite.setPosition(_pos.getX(), _pos.getY());
}

float Player::getSpeed() {
    return _moving_speed;
}

void Player::setSpeed(float new_speed) {
    this->_moving_speed = new_speed;
}

void Player::jump(sf::Vector2f jump_vector, float delta_t) {
    if (jumping)
        return;
    jumping = true;
    on_floor = false;
    this->movement_vector += jump_vector*delta_t;
}

void Player::resetJump() {
    this->jumping = false;
}

float Player::getBaseSpeed() {
    return _base_speed;
}
