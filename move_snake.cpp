#include "functions.hpp"
#include "table.hpp"
#include "snake.hpp"
#include "apple.hpp"

int mod(int x, int m) {
    while (x < 0)x += m;
    return x % m;
}

void move_snake() {
    point tail = snake_body.front();
    point head = snake_body.back();
    if (!was_apple_eaten) {
        table[tail.y][tail.x] = emptiness;
        snake_body.pop();
    }
    else spawn_apple();

    head = head + shifts[cur_direction];
    head.x = mod(head.x, table_width);
    head.y = mod(head.y, table_height);
    check_head(head);

    table[head.y][head.x] = snake;
    snake_body.push(head);

    last_direction = cur_direction;
}