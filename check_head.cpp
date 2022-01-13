#include "functions.hpp"
#include "table.hpp"
#include "apple.hpp"

void check_head(point head) {
    switch (head>>table) {
    case apple:
        was_apple_eaten = true;
        break;
    case wall:
    case snake:
        game_over();
        break;
    }
}