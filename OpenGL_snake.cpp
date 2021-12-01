#include <glut.h>
#include <vector>
#include <queue>
#include <iostream>

#include "drawable.hpp"
#include "rectangle.hpp"
#include "square.hpp"

#define let auto
#define of :

int mod(int x, int m) {
    while (x < 0)x += m;
    return x % m;
}

enum GameObjects {
    emptiness   ,
    apple       ,
    snake       ,
    wall        ,
    ObjCount    ,
};
Color* obj_colors;
void init_obj_colors() {
    obj_colors = new Color[ObjCount];
    obj_colors[emptiness] = Color();

    obj_colors[apple] = Color(0,0,255);
    obj_colors[snake] = Color(0,255,0);
    obj_colors[wall]  = Color(255,0,0);
}

bool* keyboard;
void init_keyboard() {
    keyboard = new bool[256]{ false };
}

const int table_width  = 23;
const int table_height = 12;

GameObjects** table;
Rectangle* rect;
void init_table() {
    rect = new Rectangle({0,0},{19,19},Color());

    table = new GameObjects*[table_height];
    for (int i = 0; i < table_height; i++)
        table[i] = new GameObjects[table_width]{emptiness};
}

enum Direction {
    right,
    up,
    left,
    down,
    DirsCount
};
point shifts[DirsCount] = {{1,0},{0,1},{-1,0},{0,-1}};

Direction last_direction, cur_direction;
bool was_apple_eaten = false;


std::queue<point> snake_body;
void init_snake() {
    last_direction = cur_direction = right;
    snake_body.push({0,0});
    table[0][0] = snake;
}


const int tile_width  = 38;
const int tile_height = 38;
void draw_scene() {
    for (int line = 0; line < table_height; line++) {
        for (int cell = 0; cell < table_width; cell++) {
            rect->set_lu_corner({cell*tile_width,line*tile_height});
            rect->set_color(obj_colors[table[line][cell]]);
            rect->draw();
        }
    }
}

void spawn_apple() {
    point apple;
    do {
        apple = { rand() % table_width,rand() % table_height };
    } while (table[apple.y][apple.x] != emptiness);
    table[apple.y][apple.x] = GameObjects::apple;
    was_apple_eaten = false;
}

void init() {
    srand(time(0));
    init_keyboard();
    init_obj_colors();
    init_table();
    init_snake();
    spawn_apple();
}

void game_over() {
    //...
}

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


void move_snake() {
    point tail = snake_body.front();
    point head = snake_body.back();
    if (!was_apple_eaten) {
        table[tail.y][tail.x] = emptiness;
        snake_body.pop();
    }
    else spawn_apple();

    head = head+shifts[cur_direction];
    head.x = mod(head.x,table_width);
    head.y = mod(head.y,table_height);
    check_head(head);

    table[head.y][head.x] = snake;
    snake_body.push(head);

    last_direction = cur_direction;
}

void handle_keys() {
    switch (last_direction) {
    case up:
    case down:
        if (keyboard['a'] || keyboard['A'])
            cur_direction = left;
        else if(keyboard['d']||keyboard['D'])
            cur_direction = right;
        break;
    case left:
    case right:
        if (keyboard['w'] || keyboard['W'])
            cur_direction = up;
        else if (keyboard['s'] || keyboard['S'])
            cur_direction = down;
        break;
    }
}

void snake_tick(int null) {
    handle_keys();
    move_snake();
    glutTimerFunc(230, snake_tick, 1);
}

void tick(int null) {
    glutPostRedisplay();
    glutTimerFunc(40, tick, 0);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    draw_scene();
    glFlush();
}

void key_down(unsigned char key, int x, int y) {
    keyboard[key] = true;
}

void key_up(unsigned char key, int x, int y) {
    keyboard[key] = false;
}



int main(int argc, char** argv)
{
    init();
    glutInit(&argc, argv);
    glutInitWindowSize(900, 500);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("User_Name");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 900.0, 0.0, 500.0);
    glutKeyboardFunc(key_down);
    glutKeyboardUpFunc(key_up);
    glutDisplayFunc(display);
    glutTimerFunc(40, tick, 0);
    glutTimerFunc(380, snake_tick, 1);
    glutMainLoop();
    return 0;
}