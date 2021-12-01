#pragma once
#include "point.hpp"
#include "drawable.hpp"

class Rectangle: public Drawable {
protected:
    point c, r;
    Color color;
public:
    Rectangle(point c_, point r_, Color color_);
    void draw();
};