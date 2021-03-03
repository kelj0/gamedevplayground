#include "Player.h"

Player::Player(std::string name, float x, float y, float width, float height, float fspeed) {
    this->name = name;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->fspeed = fspeed;
    player_sprite = sf::RectangleShape(sf::Vector2f(width, height));
    if (name == "player1") {
        player_sprite.setFillColor(sf::Color::Green);
    } else {
        player_sprite.setFillColor(sf::Color::White);
    }
    player_sprite.setPosition(x, y);
}

bool Player::checkColisionWithPlayer(Player other) {
    if (other.x + other.width > this->x &&
            other.x < this->x + this->width &&
            other.y + other.height > this->y &&
            other.y < this->y + this->height ) {
        return true;
    }
    return false;
}

void Player::updateMovementVector(sf::Vector2f new_force) {
    this->vec_movement += new_force;
}

void Player::applyVectorForce(float delta_time) {
    this->x += vec_movement.x * delta_time;
    this->y += vec_movement.y * delta_time;
    this->player_sprite.setPosition(this->x, this->y);
}