#include <SFML/Window/Keyboard.hpp>
#include "Engine.h"

Engine::Engine(sf::RenderWindow* window, std::vector<Player*> *players, float &delta_time, sf::Vector2u world_dimensions) {
    this->window = window;
    this->players = players;
    this->delta_time = &delta_time;
    this->world_dimensions = world_dimensions;
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
            (*players)[0]->updateMovementVector(sf::Vector2f(0, -(*players)[0]->getSpeed()), *delta_time);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            (*players)[0]->updateMovementVector(sf::Vector2f((*players)[0]->getSpeed(), 0), *delta_time);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            (*players)[0]->updateMovementVector(sf::Vector2f(0, (*players)[0]->getSpeed()), *delta_time);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            (*players)[0]->updateMovementVector(sf::Vector2f(-(*players)[0]->getSpeed(), 0), *delta_time);
    }
    if (    !sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        (*players)[1]->is_moving = false;
    } else {
        (*players)[1]->is_moving = true;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            (*players)[1]->updateMovementVector(sf::Vector2f(0, -(*players)[1]->getSpeed()), *delta_time);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            (*players)[1]->updateMovementVector(sf::Vector2f((*players)[1]->getSpeed(), 0), *delta_time);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            (*players)[1]->updateMovementVector(sf::Vector2f(0, (*players)[1]->getSpeed()), *delta_time);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            (*players)[1]->updateMovementVector(sf::Vector2f(-(*players)[1]->getSpeed(), 0), *delta_time);
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
        bool colided = false;
        Player *colider = nullptr;
        for (Player* p_check: *this->players) {
            if (p->name == p_check->name) {
                continue;
            }
            if (p->checkColisionWithPlayer(*p_check)) {
                //colided = true;
                colider = p_check;
            }
        }
        switch (checkColisionWithWorld(*p)) {
            case 0:
                break;
            case 1:
                p->vec_movement.y = -(p->vec_movement.y)/2.f;
                p->y = 0.01;
                p->player_sprite.setPosition(p->x, p->y);
                break;
            case 2:
                p->vec_movement.x = -(p->vec_movement.x)/2.f;
                p->x = world_dimensions.x - p->width - 0.01;
                p->player_sprite.setPosition(p->x, p->y);
                break;
            case 3:
                p->vec_movement.y = -(p->vec_movement.y)/2.f;
                p->y = world_dimensions.y - p->height - 0.01;
                p->player_sprite.setPosition(p->x, p->y);
                break;
            case 4:
                p->vec_movement.x = -(p->vec_movement.x)/2.f;
                p->x = 0.01;
                p->player_sprite.setPosition(p->x, p->y);
                break;
        }

        if (!colided) {
            p->applyVectorForce(*delta_time);
        }
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
    for (Player *p: *players) {
        window->draw(p->player_sprite);
    }
}

