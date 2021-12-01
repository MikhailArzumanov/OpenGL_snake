#pragma once
#include "color.hpp"

struct Drawable {
public:
    virtual void draw() = 0;
};