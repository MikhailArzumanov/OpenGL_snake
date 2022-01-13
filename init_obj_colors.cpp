#include "functions.hpp"
#include "obj_colors.hpp"
#include "game_objects.hpp"

const Color WHITE = Color();
const Color BLUE  = Color(0, 0, 255);
const Color GREEN = Color(0, 255, 0);
const Color RED   = Color(255, 0, 0);

void init_obj_colors() {
    obj_colors = new Color[ObjCount];
    
    obj_colors[emptiness] = WHITE;
    obj_colors[apple] = BLUE;
    obj_colors[snake] = GREEN;
    obj_colors[wall]  = RED;
}