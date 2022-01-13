#include "functions.hpp"
#include "snake.hpp"

void init_shifts() {
	shifts = new point[DirsCount]{
		{1,0}, //right
		{0,1}, //up
		{-1,0},//left
		{0,-1} //down
	};
}