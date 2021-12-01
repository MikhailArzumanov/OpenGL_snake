#include "functions.hpp"
#include "apple.hpp"
#include "table.hpp"
#include <random>

void spawn_apple() {
    point apple;
    do {
        apple = { rand() % table_width,rand() % table_height };
    } while (table[apple.y][apple.x] != emptiness);
    table[apple.y][apple.x] = GameObjects::apple;
    was_apple_eaten = false;
}