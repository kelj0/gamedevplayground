#include <SFML/Window/Keyboard.hpp>
#include "Engine.h"

Engine::Engine(sf::RenderWindow *window, std::vector<Player *> *players, float* delta_time) {
    this->_window = window;
    this->_players = players;
    this->_world_dimensions = window->getSize();
    this->delta_time = delta_time;
}

void Engine::movePlayer(Player &p, sf::Vector2f new_vector, bool gravity) {
    if (!gravity)
        p.is_moving = true;


    Position old_pos = p.getPosition();
    sf::Vector2f old_vector = p.movement_vector;
    p.movement_vector = *delta_time*new_vector;
    p.setPosition(Position(old_pos.getX() + p.movement_vector.x, old_pos.getY() + p.movement_vector.y));
    int c = 0;
    for (Player* player: *_players) {
        if(player->getName() == p.getName()) {
            _players->at(c) = &p;
        }
        if (p.checkColision(*player, _world_dimensions)) {
            p.movement_vector = old_vector;
            if (p.getPosition().getY() + p.getHeight() > _world_dimensions.y)
                old_pos = Position(old_pos.getX(), _world_dimensions.y-p.getHeight());
            p.setPosition(old_pos);
            return;
        }
        ++c;
    }
}

void Engine::drawPlayers() {
    for (Player* p: *_players) {
        _window->draw(p->Sprite);
    }
}

void Engine::applyPhysics() {
    for (Player* p: *_players) {
        if (!p->is_flying && !p->on_floor) {
            if (p->getPosition().getY() + p->getHeight() == _world_dimensions.y && !p->jumping) {
                p->setSpeed(p->getBaseSpeed());
                p->on_floor = true;
                p->movement_vector = sf::Vector2f(p->movement_vector.x, 0);
                //p->setPosition(Position(p->getPosition().getX(), _world_dimensions.y));
                p->resetJump();
            } else {
                this->movePlayer(*p, this->gravity_vector, true);
                if (p->getSpeed() < MAX_PLAYER_SPEED) {
                    p->setSpeed(p->getSpeed() + *delta_time*this->gravity_vector.y);
                } else {
                    p->setSpeed(MAX_PLAYER_SPEED);
                }
            }
        }
    }
}

void Engine::tick() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        this->movePlayer((*(*_players)[0]), sf::Vector2f(0,-(*(*_players)[0]).getSpeed()), false);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        this->movePlayer((*(*_players)[0]), sf::Vector2f((*(*_players)[0]).getSpeed(), 0), false);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        this->movePlayer((*(*_players)[0]), sf::Vector2f(0, (*(*_players)[0]).getSpeed()), false);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        this->movePlayer((*(*_players)[0]), sf::Vector2f(-(*(*_players)[0]).getSpeed(), 0), false);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->movePlayer((*(*_players)[1]), sf::Vector2f(0, -(*(*_players)[1]).getSpeed()), false);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->movePlayer((*(*_players)[1]), sf::Vector2f((*(*_players)[1]).getSpeed(), 0), false);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->movePlayer((*(*_players)[1]), sf::Vector2f(0, (*(*_players)[1]).getSpeed()), false);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->movePlayer((*(*_players)[1]), sf::Vector2f(-(*(*_players)[1]).getSpeed(), 0), false);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        (*(*_players)[0]).jump(jump_vector, *delta_time);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && fly_cooldown > 0.5) {
        fly_cooldown = 0;
        (*(*_players)[0]).is_flying = !(*(*_players)[0]).is_flying;
    } else {
        fly_cooldown += *delta_time;
    }

    this->_window->clear();
    applyPhysics();
    drawPlayers();
    this->_window->display();
}

