#pragma once
#include <glut.h>

struct Color {
    GLubyte r, g, b, a;
    void set_to_env();
    Color();
    Color(GLubyte r_, GLubyte g_, GLubyte b_, GLubyte a_);
    Color(GLubyte r_, GLubyte g_, GLubyte b_);
};