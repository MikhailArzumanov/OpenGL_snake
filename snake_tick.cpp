#include "functions.hpp"
#include <glut.h>

void snake_tick(int null) {
    handle_keys();
    move_snake();
    glutTimerFunc(230, snake_tick, 1);
}