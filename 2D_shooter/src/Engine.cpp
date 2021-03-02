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
        if (!p->is_moving) {
            if (p->getPosition().getY() + p->getHeight() < _world_dimensions.y-1) {
                movePlayer(*p, sf::Vector2f(0, p->getSpeed()), true);
                if (p->getSpeed() < MAX_PLAYER_SPEED) {
                    p->setSpeed(p->getSpeed() + *delta_time*981);
                }
            } else if (p->getPosition().getY() < _world_dimensions.y) {
                p->setPosition(Position(p->getPosition().getX(), _world_dimensions.y - p->getHeight()-0.1));
                p->setSpeed(0.f);
                p->movement_vector = sf::Vector2f(0, 0);
            }
        }
    }
}

void Engine::tick() {
    _window->clear();
    applyPhysics();
    drawPlayers();
    _window->display();
}

