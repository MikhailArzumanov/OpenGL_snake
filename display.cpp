#include "functions.hpp"
#include <glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    draw_scene();
    glFlush();
}