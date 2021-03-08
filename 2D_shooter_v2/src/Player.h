#ifndef INC_2D_SHOOTER_V2_PLAYER_H
#define INC_2D_SHOOTER_V2_PLAYER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <string>
#include <SFML/Graphics/RectangleShape.hpp>

class Player {
public:
    std::string name;
    float x, y, width, height, restitution, last_x, last_y;
    float player_input_power;
    float current_speed = 0;
    sf::Vector2f vec_movement;
    sf::RectangleShape player_sprite;
    bool is_moving = false;
    bool on_floor = false;
    float mass;
    bool can_jump = false;
    bool ducking = false;
    float MAX_PLAYER_SPEED = 500;
    Player(std::string name, float x, float y, float width, float height, float player_input_power,
           float mass, float restitution);

    int checkColisionWithPlayer(Player &other);
    void updateMovementVector(sf::Vector2f new_force, float delta_time);
    void applyVectorForce(float delta_time);

    float getSpeed();
    float getPlayerInputPower();
    void applyDrag(float d);

    void jump(float jump_power);
    void duck();
    void standUp();

    // math stuff
    float dotProduct(sf::Vector2f other);
    sf::Vector2f normalizedVector();
    float vecLength(sf::Vector2f v);

    std::string last_colision = "none";

};


#endif //INC_2D_SHOOTER_V2_PLAYER_H
