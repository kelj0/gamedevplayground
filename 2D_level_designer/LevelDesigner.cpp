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
            //TODO: for each sprite check if mouse in, if in change this->active sprite to it
            if (this->active_sprite == GROUND) {
                changeActiveSprite(WATER);
            } else {
                changeActiveSprite(GROUND);
            }
        }
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
    sf::Color col;
    switch (sprite) {
        case EMPTY:
            col = sf::Color::Black;
            break;
        case GROUND:
            col = sf::Color::Green;
            break;
        case WATER:
            col = sf::Color::Blue;
            break;
    }
    this->grid[
            ((this->main_window_dimensions.y / this->pixels_per_sprite) * (pos.y / this->pixels_per_sprite)) +
            (pos.x/this->pixels_per_sprite)].setFillColor(col);
}

void LevelDesigner::deleteGridItem(sf::Vector2i pos) {
    addGridItem(pos, EMPTY);
}


void LevelDesigner::drawMenuSprites() {

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

