#pragma once
#include "point.hpp"

void init_obj_colors();
void init_keyboard();
void init_shifts();
void init_table();
void init_snake();
void init();
void init_glut_window();
void init_glut_functions();
void init_glut(int& argc, char** argv);

void display();
void draw_scene();
void move_snake();
void handle_keys();
void tick(int null);
void snake_tick(int null);

void game_over();
void spawn_apple();
void check_head(point head);