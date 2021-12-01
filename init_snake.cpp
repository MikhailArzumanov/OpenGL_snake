#include "functions.hpp"
#include "snake.hpp"
#include "table.hpp"

void init_snake() {
    init_shifts();
    last_direction = cur_direction = right;
    snake_body.push({ 0,0 });
    table[0][0] = snake;
}