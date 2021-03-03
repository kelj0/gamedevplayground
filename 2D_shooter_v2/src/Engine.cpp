#include <SFML/Window/Keyboard.hpp>
#include "Engine.h"

Engine::Engine(sf::RenderWindow* window, std::vector<Player*> *players, float &delta_time) {
    this->window = window;
    this->players = players;
    this->delta_time = &delta_time;
}

void Engine::handleInput() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        (*players)[0]->updateMovementVector(sf::Vector2f(0, -1));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        (*players)[0]->updateMovementVector(sf::Vector2f(1, 0));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        (*players)[0]->updateMovementVector(sf::Vector2f(0, 1));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        (*players)[0]->updateMovementVector(sf::Vector2f(-1, 0));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        (*players)[1]->updateMovementVector(sf::Vector2f(0, -1));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        (*players)[1]->updateMovementVector(sf::Vector2f(1, 0));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        (*players)[1]->updateMovementVector(sf::Vector2f(0, 1));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        (*players)[1]->updateMovementVector(sf::Vector2f(-1,  0));
}

void Engine::applyPhysics() {
    for (Player *p: *players) {
        p->updateMovementVector(this->vec_gravity*(*delta_time));
    }
}

void Engine::updatePositions() {
    for (Player *p: *players) {
        for (Player *p_check: *players) {
            if (p->name == p_check->name)
                continue;
            if (p->checkColisionWithPlayer(*p_check)) {
                goto skip_vector_force;
            }
        }
        p->applyVectorForce(*delta_time);
        continue;
        skip_vector_force:
            continue;
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

