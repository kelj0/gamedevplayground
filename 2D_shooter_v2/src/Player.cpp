#include <cmath>
#include "Player.h"

Player::Player(std::string name, float x, float y, float width, float height, float player_input_power, float mass, float restitution) {
    this->name = name;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->player_input_power = player_input_power;
    this->mass = mass;
    this->restitution = restitution;
    player_sprite = sf::RectangleShape(sf::Vector2f(width, height));
    if (name == "player1") {
        player_sprite.setFillColor(sf::Color::Yellow);
    } else {
        player_sprite.setFillColor(sf::Color::White);
    }
    player_sprite.setPosition(x, y);
}

int Player::checkColisionWithPlayer(Player other) {
    /// summary
    /// returns value from 0 to 4 depending on where it hit the world
    /// 0 no colision
    /// 1 colision on top
    /// 2 colision on right
    /// 3 colision on bottom
    /// 4 colision on left
    /// summary
    if (this->player_sprite.getGlobalBounds().intersects(other.player_sprite.getGlobalBounds())) {
        if (this->y + this->height < other.y+other.height && this->y < other.y + other.height) {
            this->last_colision = "U";
            return 1;
        } else if (this->x + this->width < other.x && this->x > other.x) {
            this->last_colision = "R";
            return 2;
        } else if (other.y > this->y && other.y < this->x + this->height) {
            this->last_colision = "D";
            return 3;
        } else {
            this->last_colision = "L";
            return 4;
        }
    } else {
        return 0;
    }
}

void Player::updateMovementVector(sf::Vector2f new_force, float delta_time) {
    sf::Vector2f next_vec_movement = (this->vec_movement+new_force*delta_time);
    float next_speed = vecLength(next_vec_movement);
    if (next_speed > MAX_PLAYER_SPEED) {
        this->current_speed = MAX_PLAYER_SPEED;
    } else {
        this->vec_movement = next_vec_movement;
        this->current_speed = next_speed;
    }
}

void Player::applyVectorForce(float delta_time) {
    this->x += vec_movement.x * delta_time;
    this->y += vec_movement.y * delta_time;
    this->player_sprite.setPosition(this->x, this->y);
}

float Player::getSpeed() {
    return this->current_speed;
}

float Player::getPlayerInputPower() {
    return this->player_input_power;
}

void Player::applyDrag(float d) {
    if (this->current_speed > MAX_PLAYER_SPEED / 2) {
        this->vec_movement += -this->vec_movement * d;
    }
}

float Player::dotProduct(sf::Vector2f other) {
    return this->x*other.x + this->y*other.y;
}

sf::Vector2f Player::normalizedVector() {
    return (this->vec_movement / vecLength(vec_movement));
}

float Player::vecLength(sf::Vector2f v) {
    return std::sqrt(v.x*v.x + v.y*v.y);
}
