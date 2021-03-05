#include <cmath>
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
    if (this->player_sprite.getGlobalBounds().intersects(other.player_sprite.getGlobalBounds())) {
        return true;
    }
    return false;
}

void Player::updateMovementVector(sf::Vector2f new_force, float delta_time) {
    sf::Vector2f next_vec_movement = (this->vec_movement+new_force*delta_time);
    float next_speed = std::sqrt(next_vec_movement.x*next_vec_movement.x + next_vec_movement.y*next_vec_movement.y);
    if (next_speed > MAX_PLAYER_SPEED) {
        this->fspeed = MAX_PLAYER_SPEED;
    } else {
        this->vec_movement = next_vec_movement;
        this->fspeed = next_speed;
    }
}

void Player::applyVectorForce(float delta_time) {
    this->x += vec_movement.x * delta_time;
    this->y += vec_movement.y * delta_time;
    this->player_sprite.setPosition(this->x, this->y);
}

float Player::getSpeed() {
    return fspeed;
}

void Player::applyDrag(float d) {
    this->vec_movement += -this->vec_movement*d;
}
