#include "point.hpp"

point point::operator+(point another){return {x+another.x, y+another.y};}

GameObjects& point::operator>>(GameObjects** table) {
	return table[y][x];
}