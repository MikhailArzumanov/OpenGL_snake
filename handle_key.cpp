#include "functions.hpp"
#include "keyboard.hpp"
#include "snake.hpp"

void handle_horizontal_keys() {
    if (keyboard['a'] || keyboard['A'])
        cur_direction = left;
    else if (keyboard['d'] || keyboard['D'])
        cur_direction = right;
}

void handle_vertical_keys() {
    if (keyboard['w'] || keyboard['W'])
        cur_direction = up;
    else if (keyboard['s'] || keyboard['S'])
        cur_direction = down;
}

void handle_keys() {
    switch (last_direction) {
    case up:
    case down:
        handle_horizontal_keys();
        break;
    case left:
    case right:
        handle_vertical_keys();
        break;
    }
}