#include "functions.hpp"
#include <glut.h>

void tick(int null) {
    glutPostRedisplay();
    glutTimerFunc(40, tick, 0);
}