#ifndef INC_2D_SHOOTER_POSITION_H
#define INC_2D_SHOOTER_POSITION_H

#include <string>

class Position {
private:
    float _x, _y;
public:
    Position(float x, float y);

    float getX();

    float getY();

    void setXY(float x, float y);
};


#endif //INC_2D_SHOOTER_POSITION_H
