#include "functions.hpp"
#include "obj_colors.hpp"
#include "game_objects.hpp"

void init_obj_colors() {
    obj_colors = new Color[ObjCount];
    obj_colors[emptiness] = Color();

    obj_colors[apple] = Color(0, 0, 255);
    obj_colors[snake] = Color(0, 255, 0);
    obj_colors[wall] = Color(255, 0, 0);
}