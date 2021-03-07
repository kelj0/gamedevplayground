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

int Engine::checkColisionWithWorld(Player &p) {
    /// summary
    /// returns value from 0 to 4 depending on where it hit the world
    /// 0 no colision
    /// 1 colision on top
    /// 2 colision on right
    /// 3 colision on bottom
    /// 4 colision on left
    /// 5 we are on the floor
    /// summary
    if (p.y < 0) {
        return 1;
    } else if (p.x + p.width > world_dimensions.x) {
        return 2;
    } else if (p.y + p.height > world_dimensions.y) { // this is different from case where p.y+p.h == world.y
        p.on_floor = true;                            // because here, we flew of the screen (we hit the floor and we apply backforce)
        p.y = world_dimensions.y - p.height;          // therefore we return 3 so that we later reverse movement vector
        return 3;
    } else if (p.x < 0) {
        return 4;
    } else if (p.y+p.height == world_dimensions.y && !p.is_moving) { // we are on the floor, we set on floor to true
        p.on_floor = true;                           // and set player to the according position
        p.y = world_dimensions.y - p.height;
        p.vec_movement.y = 0;
        return 5;
    } else { // we are in the middle of screen, we just return 0
        p.on_floor = false;
        return 0;
    }
    // latter check colision with sprites in the world
}

void Engine::applyPhysics() {
    for (Player *p: *players) {
        if (std::abs(p->vec_movement.x) < 0.1) {
            p->vec_movement.x = 0;
        }
        if (std::abs(p->vec_movement.y) < 0.1) {
            p->vec_movement.y = 0;
        }

        if (!p->on_floor && !p->is_moving) {
            p->updateMovementVector(this->vec_gravity, *delta_time);
        }
        if (p->on_floor) {
            p->applyDrag(this->floor_drag * (*delta_time));
        }
    }
}

void Engine::updatePositions() {
    for (Player* &p: *this->players) {
        int collider_i = 0;
        bool colided_with_player = false;
        int colide_type = 0;
        for (Player* p_check: *this->players) {
            if (p->name == p_check->name) {
                ++collider_i;
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
            switch (colide_type) {
                case 1:
                    p->y = ((*players)[collider_i]->y + (*players)[collider_i]->height);
                    // if p is on the floor, we dont apply any force, we rather null y force again
                    // (other squeezed him but this is not physics engine so it doesnt have elastic modulus)
                    if(!p->on_floor) {
                        p->vec_movement.y = ((-(p->vec_movement.y)*(*players)[collider_i]->mass)/p->mass)*0.5;
                    } else {
                        p->vec_movement.y = 0;
                    }
                    //p->current_speed /= 2.f;
                    // dont need check on the floor cause we know other hit p from above, so its impossible to be on the floor
                    (*players)[collider_i]->vec_movement.y += ((-(p->vec_movement.y)*p->mass)/(*players)[collider_i]->mass)*0.5;
                    break;
                case 2:
                    p->x = p->last_x;
                    p->vec_movement.x = ((-p->vec_movement.x * (*players)[collider_i]->mass)/p->mass)*0.5;
                    //p->current_speed /= 2.f;
                    (*players)[collider_i]->vec_movement.x += ((-(p->vec_movement.x)*p->mass)/(*players)[collider_i]->mass)*0.5;
                    break;
                case 3:
                    p->y = (*players)[collider_i]->y - p->height;
                    p->vec_movement.y = ((-(p->vec_movement.y)*(*players)[collider_i]->mass)/p->mass)*0.5;
                    //p->current_speed /= 2.f;
                    // this is case when when p is above other, so p cant be on the floor, and we do the same with other
                    // (cancel y force in the vector cause objects here dont have elastic modulus
                    if(!(*players)[collider_i]->on_floor) {
                        (*players)[collider_i]->vec_movement.y += ((-(p->vec_movement.y)*p->mass)/(*players)[collider_i]->mass)*0.5;
                    } else {
                        (*players)[collider_i]->vec_movement.y = 0;
                    }
                    break;
                case 4:
                    p->x = p->last_x;
                    p->vec_movement.x = ((-p->vec_movement.x * (*players)[collider_i]->mass)/p->mass)*0.5;
                    //p->current_speed /= 2.f;
                    (*players)[collider_i]->vec_movement.x += ((-(p->vec_movement.x)*p->mass)/(*players)[collider_i]->mass)*0.5;
                    break;
            }
            // if they collided, apply friction and power lose (we cant have 100% force input/output)
            (*players)[collider_i]->applyDrag(4 * (*delta_time));
            p->applyDrag(4 * (*delta_time));
        }

        switch (checkColisionWithWorld(*p)) {
            case 0:
                break;
            case 1:
                p->vec_movement.y = -(p->vec_movement.y)/2.f;
                p->y = 0;
                break;
            case 2:
                p->vec_movement.x = -(p->vec_movement.x)/2.f;
                p->x = world_dimensions.x - p->width;
                break;
            case 3:
                p->vec_movement.y = -(p->vec_movement.y)/2.f;
                p->y = world_dimensions.y - p->height;
                break;
            case 4:
                p->vec_movement.x = -(p->vec_movement.x)/2.f;
                p->x = 0;
                break;
        }

        p->last_x = p->x;
        p->last_y = p->y;

        if (std::abs(p->vec_movement.x) < 0.2 && p->on_floor) {
            p->vec_movement.x = 0;
        }
        if (std::abs(p->vec_movement.y) < 0.2 && p->on_floor) {
            p->vec_movement.y = 0;
        }
        if (p->vec_movement == sf::Vector2f {0,0} && p->on_floor) {
            p->current_speed = 0;
        } else {
            p->applyDrag(this->air_resistance * (*delta_time));
            p->applyVectorForce(*delta_time);
        }



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

