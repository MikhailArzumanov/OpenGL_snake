#pragma once
#include "point.hpp"
#include "drawable.hpp"

class Rectangle: public Drawable {
protected:
    point c, r;
    Color color;
public:
    Rectangle(point c_, point r_, Color color_);
    void set_color(Color color_);
    void set_c(point c_);
    void set_lu_corner(point corner);
    void draw();
};