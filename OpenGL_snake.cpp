#include <glut.h>
#include <vector>

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("User_Name");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}