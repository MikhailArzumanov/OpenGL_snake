#include "color.hpp"

Color::Color() { r = g = b = a = 255; }
Color::Color(GLubyte r_, GLubyte g_, GLubyte b_, GLubyte a_) {
	r = r_; g = g_; b = b_; a = a_;
}
Color::Color(GLubyte r_, GLubyte g_, GLubyte b_) :Color(r_, g_, b_, 255) {}
