#include "functions.hpp"
#include <glut.h>

void init_glut_window() {
    glutInitWindowSize(900, 500);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("OpenGL Snake");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 900.0, 0.0, 500.0);
}