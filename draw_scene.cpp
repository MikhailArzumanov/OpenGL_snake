#include "functions.hpp"

#include "obj_colors.hpp"
#include "table.hpp"

void draw_scene() {
    for (int line = 0; line < table_height; line++) {
        for (int cell = 0; cell < table_width; cell++) {
            int x = cell*tile_width;
            int y = line*tile_height;
            rect->set_lu_corner({x,y});
            rect->set_color(obj_colors[table[line][cell]]);
            rect->draw();
        }
    }
}