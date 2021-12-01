#include "functions.hpp"
#include "table.hpp"
#include "apple.hpp"

void check_head(point head) {
    switch (table[head.y][head.x]) {
    case apple:
        was_apple_eaten = true;
        break;
    case wall:
    case snake:
        game_over();
        break;
    }
}