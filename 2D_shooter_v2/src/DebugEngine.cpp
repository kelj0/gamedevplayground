#include "DebugEngine.h"

DebugEngine::DebugEngine(sf::RenderWindow &window, std::vector<Player*> players, sf::Font font) {
    this->_window = &window;
    this->_font = font;
    this->_players = players;
}

void DebugEngine::updateData(){
    sf::Text t;
    t.setFont(_font);
    std::string b = "";
    for (Player *p: _players) {
        b += p->name + ": " + std::to_string(p->x) + ", " + std::to_string(p->y) + "\n";
        b += "m_vector: " + std::to_string(p->vec_movement.x) + ", " + std::to_string(p->vec_movement.y) + "\n";
        b += "speed: " + std::to_string(p->getSpeed()) + "\n";
        b += "col: " + p->last_colision + "\n";
    }
    t.setString(b);
    t.setCharacterSize(20);
    t.setFillColor(sf::Color::Red);
    this->_window->draw(t);
}


void DebugEngine::tick() {
    this->_window->clear();
    updateData();
    this->_window->display();
}
