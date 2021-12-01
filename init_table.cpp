#include "functions.hpp"
#include "table.hpp"

void init_table() {
    rect = new Rectangle({ 0,0 }, { 19,19 }, Color());

    table = new GameObjects*[table_height];
    for (int i = 0; i < table_height; i++)
        table[i] = new GameObjects[table_width]{ emptiness };
}