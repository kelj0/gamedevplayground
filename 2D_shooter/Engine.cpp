#include "Engine.h"

Engine::Engine(sf::RenderWindow* window, std::vector <Player*> *players) {
    this->_window = window;
    this->_players = players;
    this->_world_dimensions = window->getSize();
}

void Engine::movePlayer(Player &p, float new_x, float new_y) {
    float old_x = p.getX();
    float old_y = p.getY();
    p.setXY(new_x, new_y);
    int c = 0;
    for (Player* player: *_players) {
        if(player->getName() == p.getName()) {
            _players->at(c) = &p;
        }
        if (p.checkColision(*player, _world_dimensions)) {
            p.setXY(old_x, old_y);
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

void Engine::tick() {
    _window->clear();
    drawPlayers();
    _window->display();
}
