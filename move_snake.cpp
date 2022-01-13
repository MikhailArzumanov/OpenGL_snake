#include "functions.hpp"
#include "table.hpp"
#include "snake.hpp"
#include "apple.hpp"

int mod(int x, int m) {
    while (x < 0)x += m;
    return x % m;
}

void handle_apple(point tail) {
    if (!was_apple_eaten) {
        tail >> table = emptiness;
        snake_body.pop();
    }
    else spawn_apple();
}

void move_snake_head(point& head) {
    head = head + shifts[cur_direction];
    head.x = mod(head.x, table_width);
    head.y = mod(head.y, table_height);
}

void apply_snake_head_to_env(point head) {
    head >> table = snake;
    snake_body.push(head);
}

void move_snake() {
    point tail = snake_body.front();
    point head = snake_body.back();
    
    handle_apple(tail);

    move_snake_head(head);
    check_head(head);

    apply_snake_head_to_env(head);

    last_direction = cur_direction;
}