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

int Player::checkColisionWithPlayer(Player &other) {
    /// summary
    /// returns value from 0 to 4 depending on where it hit the world
    /// 0 no colision
    /// 1 colision on top
    /// 2 colision on right
    /// 3 colision on bottom
    /// 4 colision on left
    /// summary
    if (this->player_sprite.getGlobalBounds().intersects(other.player_sprite.getGlobalBounds())) {
        /*
         *
         *                |    |*******
         *                |    |*other*
         *                |    |*******
         *      ----------|----|-----------
         *              yD|    |
         *      ----------|----|----------
         *        ********| xD |
         *        * this *|    |
         *        ********|    |
         *                |
         */
        float xD = other.last_x - this->last_x + this->width;
        float yD = this->last_y - other.last_y+other.height;
        if (this->last_y < other.last_y + other.height && this->last_y + this->height > other.last_y) {
            if (xD >= 0) {
                this->last_colision = "R";
                other.last_colision = "L";
                return 2;
            } else {
                this->last_colision = "L";
                other.last_colision = "R";
                return 4;
            }
        } else {
            if (yD >= 0) {
                this->last_colision = "U";
                other.last_colision = "D";
                return 1;
            } else {
                this->last_colision = "D";
                other.last_colision = "U";
                return 3;
            }
        }
        return 0;
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
    if (!this->is_moving) {
        if (this->vec_movement.x != 0 && this->vec_movement.x < MAX_PLAYER_SPEED) {
            if (std::abs(this->vec_movement.x) - d < 0) {
                this->vec_movement.x = 0;   
            } else {
                this->vec_movement.x -= this->vec_movement.x * d;
            }
        }

        if (this->vec_movement.y != 0 && this->vec_movement.y < MAX_PLAYER_SPEED) {
            if (std::abs(this->vec_movement.y) - d < 0) {
                this->vec_movement.y = 0;
            } else {
                this->vec_movement.y -= this->vec_movement.y * d;
            }
        }
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
