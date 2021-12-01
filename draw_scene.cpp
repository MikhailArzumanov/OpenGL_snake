#include "functions.hpp"

#include "obj_colors.hpp"
#include "table.hpp"

void draw_scene() {
    for (int line = 0; line < table_height; line++) {
        for (int cell = 0; cell < table_width; cell++) {
            rect->set_lu_corner({ cell * tile_width,line * tile_height });
            rect->set_color(obj_colors[table[line][cell]]);
            rect->draw();
        }
    }
}