#include "functions.hpp"
#include "snake.hpp"

const point RIGHT_SHIFT = { 1,0 };
const point UP_SHIFT	= { 0,1 };
const point LEFT_SHIFT	= { -1,0 };
const point DOWN_SHIFT	= { 0,-1 };

void init_shifts() {
	shifts = new point[DirsCount]{
		RIGHT_SHIFT,
		UP_SHIFT,
		LEFT_SHIFT,
		DOWN_SHIFT 
	};
}