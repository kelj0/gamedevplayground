#include "Position.h"


Position::Position(float x, float y){
    setXY(x,y);
}

float Position::getX() {
    return this->_x;
}

float Position::getY() {
    return this->_y;
}

void Position::setXY(float x, float y) {
    this->_x = x;
    this->_y = y;
}