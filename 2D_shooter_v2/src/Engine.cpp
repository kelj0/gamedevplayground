#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Engine.h"

Engine::Engine(sf::RenderWindow* window, std::vector<Player*> *players, float &delta_time, sf::Vector2u world_dimensions, sf::Font font) {
    this->window = window;
    this->players = players;
    this->delta_time = &delta_time;
    this->world_dimensions = world_dimensions;
    this->font = font;
}

void Engine::handleInput() {
    if (    !sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        (*players)[0]->is_moving = false;
    } else {
        (*players)[0]->is_moving = true;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            (*players)[0]->updateMovementVector(sf::Vector2f(0, -(*players)[0]->getPlayerInputPower()), *delta_time);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            (*players)[0]->updateMovementVector(sf::Vector2f((*players)[0]->getPlayerInputPower(), 0), *delta_time);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            (*players)[0]->updateMovementVector(sf::Vector2f(0, (*players)[0]->getPlayerInputPower()), *delta_time);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            (*players)[0]->updateMovementVector(sf::Vector2f(-(*players)[0]->getPlayerInputPower(), 0), *delta_time);
    }
    if (    !sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        (*players)[1]->is_moving = false;
    } else {
        (*players)[1]->is_moving = true;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            (*players)[1]->updateMovementVector(sf::Vector2f(0, -(*players)[1]->getPlayerInputPower()), *delta_time);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            (*players)[1]->updateMovementVector(sf::Vector2f((*players)[1]->getPlayerInputPower(), 0), *delta_time);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            (*players)[1]->updateMovementVector(sf::Vector2f(0, (*players)[1]->getPlayerInputPower()), *delta_time);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            (*players)[1]->updateMovementVector(sf::Vector2f(-(*players)[1]->getPlayerInputPower(), 0), *delta_time);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        (*players)[0]->vec_movement *= 0.f;
        (*players)[1]->vec_movement *= 0.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
        (*players)[0]->last_colision = ".";
        (*players)[1]->last_colision = ".";
    }
}

int Engine::checkColisionWithWorld(Player p) {
    /// summary
    /// returns value from 0 to 4 depending on where it hit the world
    /// 0 no colision
    /// 1 colision on top
    /// 2 colision on right
    /// 3 colision on bottom
    /// 4 colision on left
    /// summary
    if (p.y < 0) {
        return 1;
    } else if (p.x + p.width > world_dimensions.x) {
        return 2;
    } else if (p.y + p.height > world_dimensions.y) {
        return 3;
    } else if (p.x < 0) {
        return 4;
    } else {
        return 0;
    }
}

void Engine::applyPhysics() {
    for (Player *p: *players) {
        p->updateMovementVector(this->vec_gravity, *delta_time);
    }
}

void Engine::updatePositions() {
    for (Player* p: *this->players) {
        int collider_i = 0;
        bool colided_with_player = false;
        int colide_type = 0;
        for (Player* p_check: *this->players) {
            if (p->name == p_check->name) {
                continue;
            }
            colide_type = p->checkColisionWithPlayer(*p_check);
            if (colide_type) {
                colided_with_player = true;
                break;
            }
            ++collider_i;
        }
        if (colided_with_player) {
           /* switch (colide_type) {
                case 1:
                    if (p->y + p->height + 0.001 < world_dimensions.y) {
                        p->y += 0.01;
                    } else {
                        (*players)[collider_i]->y -= 0.01;
                    }
                    break;
                case 2:
                    if (p->x - 0.01 > 0) {
                        p->x -= 0.01;
                    } else {
                        (*players)[collider_i]->x += 0.01;
                    }
                    break;
                case 3:
                    if (p->y - 0.01 > 0) {
                        p->vec_movement.y += ((*players)[collider_i]->vec_movement.y * (*players)[collider_i]->mass) / p->mass;
                        p->y -= 0.01;
                    } else {
                        (*players)[collider_i]->y += 0.01;
                    }
                    break;
                case 4:
                    if (p->x + p->width + 0.01 < world_dimensions.x) {
                        p->x += 0.01;
                    } else {
                        (*players)[collider_i]->x -= 0.01;
                    }
                    break;
            }*/

          /*sf::Vector2f impact = p->vec_movement*p->mass - (*players)[collider_i]->vec_movement*(*players)[collider_i]->mass;
            p->vec_movement += impact/2000.f;
            (*players)[collider_i]->vec_movement += impact/2.f;*/
            float p_new_y; //====you dont know physics====.
            float p_new_x;
            float other_new_y;
            float other_new_x;
            switch (colide_type) {
                case 1:
                    p_new_y =
                            -p->vec_movement.y +
                            ((*players)[collider_i]->vec_movement.y * (*players)[collider_i]->mass)/
                            p->mass;
                    other_new_y = -(*players)[collider_i]->vec_movement.y -
                            (p->vec_movement.y*p->mass)/
                            (*players)[collider_i]->mass;
                    p->vec_movement.y = p_new_y;
                    (*players)[collider_i]->vec_movement.y = other_new_y;
                    if (p->y + p->height + 0.01 < world_dimensions.y) {
                        p->y += 0.01;
                    } else {
                        (*players)[collider_i]->y = p->y-(*players)[collider_i]->height-0.01;
                    }
                    break;
                case 2:
                    p_new_x =
                            -p->vec_movement.x +
                            ((*players)[collider_i]->vec_movement.x * (*players)[collider_i]->mass)/
                            p->mass;
                    other_new_x = -(*players)[collider_i]->vec_movement.x -
                                  (p->vec_movement.x*p->mass)/
                                  (*players)[collider_i]->mass;
                    p->vec_movement.x = p_new_x;
                    (*players)[collider_i]->vec_movement.x = other_new_x;
                    if (p->x - 0.01 > 0) {
                        p->x -= 0.01;
                    } else {
                        (*players)[collider_i]->x = p->x+p->width+0.01;
                    }
                    break;
                case 3:
                    p_new_y =
                            -p->vec_movement.y +
                            ((*players)[collider_i]->vec_movement.y * (*players)[collider_i]->mass)/
                            p->mass;
                    other_new_y = -(*players)[collider_i]->vec_movement.y -
                                  (p->vec_movement.y*p->mass)/
                                  (*players)[collider_i]->mass;
                    p->vec_movement.y = p_new_y;
                    (*players)[collider_i]->vec_movement.y = other_new_y;
                    if (p->y - 0.01 > 0) {
                        p->y -= 0.01;
                    } else {
                        (*players)[collider_i]->y = p->y+p->height+0.01;
                    }
                    break;
                case 4:
                    p_new_x =
                            -p->vec_movement.x +
                            ((*players)[collider_i]->vec_movement.x * (*players)[collider_i]->mass)/
                            p->mass;
                    other_new_x = -(*players)[collider_i]->vec_movement.x -
                                  (p->vec_movement.x*p->mass)/
                                  (*players)[collider_i]->mass;
                    p->vec_movement.x = p_new_x;
                    (*players)[collider_i]->vec_movement.x = other_new_x;
                    if (p->x + p->width + 0.01 < world_dimensions.x) {
                        p->x += 0.01;
                    } else {
                        (*players)[collider_i]->x = p->x-(*players)[collider_i]->width - 0.01;
                    }
                    break;
            }
        }

        switch (checkColisionWithWorld(*p)) {
            case 0:
                break;
            case 1:
                p->vec_movement.y = -(p->vec_movement.y)/2.f;
                p->y = 0.01;
                break;
            case 2:
                p->vec_movement.x = -(p->vec_movement.x)/2.f;
                p->x = world_dimensions.x - p->width - 0.01;
                break;
            case 3:
                p->vec_movement.y = -(p->vec_movement.y)/2.f;
                p->y = world_dimensions.y - p->height - 0.01;
                break;
            case 4:
                p->vec_movement.x = -(p->vec_movement.x)/2.f;
                p->x = 0.01;
                break;
        }
    //    p->applyDrag(this->air_resistance);
        p->applyVectorForce(*delta_time);
        p->player_sprite.setPosition(p->x, p->y);
    }
}

void Engine::tick() {
    this->window->clear();
    this->handleInput();
    this->applyPhysics();
    this->updatePositions();
    this->drawPlayers();
    this->window->display();
}

void Engine::drawPlayers() {
    sf::Text t;
    t.setFont(font);
    t.setString("p1");
    t.setCharacterSize(20);
    t.setFillColor(sf::Color::Green);

    sf::Text t2;
    t2.setFont(font);
    t2.setString("p2");
    t2.setCharacterSize(20);
    t2.setFillColor(sf::Color::Red);
    for (Player *p: *players) {
        if (p->name == "player1") {
            t.setPosition(p->x, p->y - 23);
            window->draw(t);
        } else {
            t2.setPosition(p->x, p->y - 23);
            window->draw(t2);
        }
        window->draw(p->player_sprite);

    }
}

