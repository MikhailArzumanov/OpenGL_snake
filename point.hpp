#pragma once
#include "game_objects.hpp"
struct point {
    int x, y;
    point operator+(point another);
    GameObjects& operator>>(GameObjects** table);
};