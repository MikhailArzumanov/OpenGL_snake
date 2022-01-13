#include "functions.hpp"
#include "snake.hpp"
#include "table.hpp"

point gen_snake_start_point() {
    //...
    return {0,0};
}

void init_snake() {
    init_shifts();
    last_direction = cur_direction = right;
    point start_point = gen_snake_start_point();
    snake_body.push(start_point);
    start_point>>table = snake;
}