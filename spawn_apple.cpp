#include "functions.hpp"
#include "apple.hpp"
#include "table.hpp"
#include <random>

point gen_apple() {
    return { 
        rand()%table_width,
        rand()%table_height
    };
}

void spawn_apple() {
    point apple;
    do {
        apple = gen_apple();
    } while (apple>>table != emptiness);
    apple>>table = GameObjects::apple;
    was_apple_eaten = false;
}