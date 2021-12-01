#pragma once
#include <queue>
#include "point.hpp"
#include "direction.hpp"

extern std::queue<point> snake_body;
extern Direction last_direction, cur_direction;
extern point* shifts;