#include "DebugEngine.h"

DebugEngine::DebugEngine(sf::RenderWindow *window, std::vector<Player *> *players, sf::Font font) {
    this->_window = window;
    this->_font = font;
    this->_players = players;
}

void DebugEngine::updateData(){
    sf::Text t;
    t.setFont(_font);
    std::string b = "";
    for (Player* p: *_players) {
        b += p->getName() + ": " + std::to_string(p->getPosition().getX()) + ", " + std::to_string(p->getPosition().getY()) + "\n";
        b += "speed: " + std::to_string(p->getSpeed()) + "\n";
        b += "m_vector: " + std::to_string(p->movement_vector.x) + ", " + std::to_string(p->movement_vector.y) + "\n";
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
