#include "LevelDesigner.h"

LevelDesigner::LevelDesigner(sf::RenderWindow *window, int pixels_per_sprite) {
    this->window = window;
    this->pixels_per_sprite = pixels_per_sprite;
    this->window_dimensions = window->getSize();
    if (window->getSize().y % pixels_per_sprite != 0) {
        window->close();
        exit(-1);
    }
    sf::RectangleShape r(sf::Vector2f(pixels_per_sprite,pixels_per_sprite));
    r.setFillColor(sf::Color::Black);
    r.setOutlineThickness(0.7);
    r.setOutlineColor(sf::Color::White);
    this->grid = std::vector<sf::RectangleShape>(
            (this->window_dimensions.x/this->pixels_per_sprite)*
            (this->window_dimensions.y/this->pixels_per_sprite),r);
}

void LevelDesigner::handleInput() {
    pressed_location = sf::Mouse::getPosition(*this->window);
    if (pressed_location.x >= 0 && pressed_location.x <= this->window_dimensions.x &&
            pressed_location.y >= 0 && pressed_location.y <= this->window_dimensions.y) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            pressed_location = sf::Mouse::getPosition(*this->window);
            addGridItem(pressed_location, GROUND);//this->active_sprite);
        } else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
            sf::Vector2i pressed_location = sf::Mouse::getPosition(*this->window);
            deleteGridItem(pressed_location);
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
    int window_width = this->window_dimensions.x;
    for (sf::RectangleShape rect : this->grid) {
        if (x == window_width) {
            x = 0;
            y += this->pixels_per_sprite;
        }
        rect.setPosition(x, y);
        window->draw(rect);
        x += this->pixels_per_sprite;
    }
}

void LevelDesigner::addGridItem(sf::Vector2i pos, LevelDesigner::availableSprites sprite) {
    switch (sprite) {
        case EMPTY:
            this->grid[
                    ((this->window_dimensions.y/this->pixels_per_sprite) * (pos.y/this->pixels_per_sprite)) +
                    (pos.x/this->pixels_per_sprite)].setFillColor(sf::Color::Black);
            break;
        case GROUND:
            this->grid[
                    ((this->window_dimensions.y/this->pixels_per_sprite) * (pos.y/this->pixels_per_sprite)) +
                    (pos.x/this->pixels_per_sprite)].setFillColor(sf::Color::Green);
            break;
    }
}

void LevelDesigner::deleteGridItem(sf::Vector2i pos) {
    addGridItem(pos, EMPTY);
}

void LevelDesigner::tick() {
    window->clear();
    handleInput();
    this->drawGrid();
    window->display();
}