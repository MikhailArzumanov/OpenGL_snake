#pragma once
struct point {
    int x, y;
    point operator+(point another);
};