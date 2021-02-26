#include "Engine.h"

Engine::Engine(sf::RenderWindow* window, std::vector <Player*> *players) {
    this->_window = window;
    this->_players = players;
    this->_world_dimensions = window->getSize();
}

void Engine::movePlayer(Player &p, Position new_position) {
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
        if (p->getPosition().getY() + p->getHeight() < _world_dimensions.y && p->getPosition().getY() > 0) {
            movePlayer(*p, Position(p->getPosition().getX(),p->getPosition().getY() + p->getSpeed()));
        } else {
            p->setSpeed(-p->getSpeed());
            p->setRelativePosition(0, p->getSpeed());
        }
    }
}

void Engine::tick() {
    _window->clear();
    applyPhysics();
    drawPlayers();
    _window->display();
}

