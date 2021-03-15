#ifndef INC_2D_LEVEL_DESIGNER_LEVELDESIGNER_H
#define INC_2D_LEVEL_DESIGNER_LEVELDESIGNER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <map>


class LevelDesigner {
private:
    sf::RenderWindow *main_window;
    sf::RenderWindow *menu_window;
    sf::Vector2u main_window_dimensions;
    sf::Vector2u menu_window_dimensions;
    int pixels_per_sprite;
    std::vector<sf::RectangleShape> grid;
    std::vector<sf::RectangleShape> sprites;
    enum availableSprites {
        EMPTY,
        GROUND, //todo add more sprites
        WATER,
        GRASS,
        LAST
    };
    std::map<availableSprites, sf::Color> sprite_map; // todo: change to texture
    availableSprites active_sprite = EMPTY;
    sf::Vector2i pressed_location;
    sf::RectangleShape export_button;
    sf::Text txt_export_button;
public:
    LevelDesigner(sf::RenderWindow *main_window, sf::RenderWindow *menu_window, int pixels_per_sprite);

    void handleInput();
    void changeActiveSprite (availableSprites s);
    void exportMap();
    void drawGrid();
    void addGridItem(sf::Vector2i pos, availableSprites sprite);
    void deleteGridItem(sf::Vector2i pos);
    void drawMenuSprites();
    void tick();
};


#endif //INC_2D_LEVEL_DESIGNER_LEVELDESIGNER_H
