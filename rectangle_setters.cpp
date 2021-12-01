#include "rectangle.hpp"

void Rectangle::set_color(Color color_) { color = color_; }
void Rectangle::set_c(point c_) { c = c_; }
void Rectangle::set_lu_corner(point corner){c = corner+r;}