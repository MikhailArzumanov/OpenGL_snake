#include "rectangle.hpp"

void Rectangle::draw() {
    glBegin(GL_POLYGON);
    color.set_to_env();
    glVertex2i(c.x - r.x, c.y - r.y);
    glVertex2i(c.x - r.x, c.y + r.y);
    glVertex2i(c.x + r.x, c.y + r.y);
    glVertex2i(c.x + r.x, c.y - r.y);
    glEnd();
}