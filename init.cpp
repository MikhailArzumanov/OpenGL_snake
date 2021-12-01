#include "functions.hpp"
#include <random>
#include <ctime>

void init() {
    srand(time(0));
    init_keyboard();
    init_obj_colors();
    init_table();
    init_snake();
    spawn_apple();
}