#include "LevelDesigner.h"

LevelDesigner::LevelDesigner(sf::RenderWindow *main_window, sf::RenderWindow *menu_window, int pixels_per_sprite) {
    this->main_window = main_window;
    this->menu_window = menu_window;
    this->pixels_per_sprite = pixels_per_sprite;
    this->main_window_dimensions = main_window->getSize();
    this->menu_window_dimensions = menu_window->getSize();
    if (main_window->getSize().y % pixels_per_sprite != 0) {
        main_window->close();
        exit(-1);
    }
    sf::RectangleShape r(sf::Vector2f(pixels_per_sprite,pixels_per_sprite));
    r.setFillColor(sf::Color::Black);
    r.setOutlineThickness(0.7);
    r.setOutlineColor(sf::Color::White);
    this->grid = std::vector<sf::RectangleShape>(
            (this->main_window_dimensions.x / this->pixels_per_sprite) *
            (this->main_window_dimensions.y / this->pixels_per_sprite), r);

    for (int i = 0; i != LAST; ++i) {
        switch (static_cast<availableSprites>(i)) {
            case EMPTY:
                r.setFillColor(sf::Color::Black);
                this->sprite_map[EMPTY] = sf::Color::Black;
                break;
            case GROUND:
                r.setFillColor(sf::Color(87, 65, 47));
                this->sprite_map[GROUND] = sf::Color(87, 65, 47);
                break;
            case WATER:
                r.setFillColor(sf::Color(24, 61, 97));
                this->sprite_map[WATER] = sf::Color(24, 61, 97);
                break;
            case GRASS:
                r.setFillColor(sf::Color::Green);
                this->sprite_map[GRASS] = sf::Color::Green;
                break;
        }
        this->sprites.push_back(r);

    }
}

void LevelDesigner::handleInput() {
    pressed_location = sf::Mouse::getPosition(*this->main_window);
    if (pressed_location.x >= 0 && pressed_location.x <= this->main_window_dimensions.x &&
            pressed_location.y >= 0 && pressed_location.y <= this->main_window_dimensions.y) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            pressed_location = sf::Mouse::getPosition(*this->main_window);
            addGridItem(pressed_location, this->active_sprite);
        } else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
            sf::Vector2i pressed_location = sf::Mouse::getPosition(*this->main_window);
            deleteGridItem(pressed_location);
        }
    } else if ( pressed_location.x < 0 &&
                -pressed_location.x <= this->menu_window_dimensions.x &&
                pressed_location.y >= 0 && pressed_location.y <= this->menu_window_dimensions.y) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            pressed_location = sf::Mouse::getPosition(*this->menu_window);
            //TODO: for each sprite check if mouse in, if in change this->active sprite to it
            for(sf::RectangleShape r : this->sprites) {
                if(r.getLocalBounds().contains(pressed_location.x, pressed_location.y)) {
                    for (std::pair<availableSprites, sf::Color> a : this->sprite_map) {
                        if (a.second == r.getFillColor()) {
                            changeActiveSprite(a.first);
                        }
                    }
                }
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
        changeActiveSprite(EMPTY);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
        changeActiveSprite(GROUND);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
        changeActiveSprite(WATER);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
        changeActiveSprite(GRASS);
    }
}

void LevelDesigner::changeActiveSprite(LevelDesigner::availableSprites s) {
    this->active_sprite = s;
}

void LevelDesigner::exportMap() {
    //todo
}

void LevelDesigner::drawGrid() {
    int x = 0;
    int y = 0;
    int window_width = this->main_window_dimensions.x;
    for (sf::RectangleShape rect : this->grid) {
        if (x == window_width) {
            x = 0;
            y += this->pixels_per_sprite;
        }
        rect.setPosition(x, y);
        main_window->draw(rect);
        x += this->pixels_per_sprite;
    }
}

void LevelDesigner::addGridItem(sf::Vector2i pos, LevelDesigner::availableSprites sprite) {
    int index = ((this->main_window_dimensions.y / this->pixels_per_sprite) * (pos.y / this->pixels_per_sprite)) +
                    (pos.x/this->pixels_per_sprite);
    this->grid[index].setFillColor(this->sprite_map[sprite]);
}

void LevelDesigner::deleteGridItem(sf::Vector2i pos) {
    addGridItem(pos, EMPTY);
}


void LevelDesigner::drawMenuSprites() {
    int x = 15;
    int y = 10;
    for (sf::RectangleShape &s : this->sprites) {
        if (x + this->pixels_per_sprite >= this->menu_window_dimensions.x) {
            x = 15;
            y += this->pixels_per_sprite+10;
        }
        s.setPosition(x, y);
        menu_window->draw(s);
        x += this->pixels_per_sprite+10;
    }
}

void LevelDesigner::tick() {
    main_window->clear();
    menu_window->clear();
    handleInput();
    this->drawGrid();
    this->drawMenuSprites();
    main_window->display();
    menu_window->display();
}

