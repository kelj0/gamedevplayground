#ifndef INC_2D_SHOOTER_DEBUGENGINE_H
#define INC_2D_SHOOTER_DEBUGENGINE_H

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Player.h"

class DebugEngine {
private:

    std::vector<Player*> _players;
    sf::RenderWindow* _window;
    sf::Font _font;
public:
    DebugEngine(sf::RenderWindow &window, std::vector<Player*> players, sf::Font font);
    void updateData();
    void tick();
};


#endif //INC_2D_SHOOTER_DEBUGENGINE_H
