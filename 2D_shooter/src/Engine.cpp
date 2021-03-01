#include "Engine.h"

Engine::Engine(sf::RenderWindow *window, std::vector<Player *> *players, float &delta_time) {
    this->_window = window;
    this->_players = players;
    this->_world_dimensions = window->getSize();
    this->delta_time = delta_time;
}

void Engine::movePlayer(Player &p, Position new_position, bool gravity) {
    if (!gravity)
        p.is_moving = true;

    Position old_pos = p.getPosition();
    p.setPosition(new_position);
    int c = 0;
    for (Player* player: *_players) {
        if(player->getName() == p.getName()) {
            _players->at(c) = &p;
        }
        if (p.checkColision(*player, _world_dimensions)) {
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
                movePlayer(*p, Position(p->getPosition().getX(), p->getPosition().getY() + p->getSpeed()), true);
                if (p->getSpeed() < MAX_PLAYER_SPEED) {
                    p->setSpeed(p->getSpeed() + 0.001);
                }
            } else if (p->getPosition().getY() <= _world_dimensions.y) {
                p->setPosition(Position(p->getPosition().getX(), _world_dimensions.y - p->getHeight()));
                p->setSpeed(0.f);
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

