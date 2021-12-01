#include "functions.hpp"
#include "snake.hpp"

void init_shifts() {
	shifts = new point[DirsCount]{{1,0},{0,1},{-1,0},{0,-1}};
}