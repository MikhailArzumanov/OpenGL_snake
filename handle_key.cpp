#include "functions.hpp"
#include "keyboard.hpp"
#include "snake.hpp"

void handle_keys() {
    switch (last_direction) {
    case up:
    case down:
        if (keyboard['a'] || keyboard['A'])
            cur_direction = left;
        else if (keyboard['d'] || keyboard['D'])
            cur_direction = right;
        break;
    case left:
    case right:
        if (keyboard['w'] || keyboard['W'])
            cur_direction = up;
        else if (keyboard['s'] || keyboard['S'])
            cur_direction = down;
        break;
    }
}