#include "functions.hpp"
#include "keyboard.hpp"
#include <glut.h>

void key_down(unsigned char key, int x, int y) {
    keyboard[key] = true;
}

void key_up(unsigned char key, int x, int y) {
    keyboard[key] = false;
}

void init_glut_functions() {
    glutKeyboardFunc(key_down);
    glutKeyboardUpFunc(key_up);
    glutDisplayFunc(display);
    glutTimerFunc(40, tick, 0);
    glutTimerFunc(380, snake_tick, 1);
}