#include <glut.h>

using namespace std;


struct Color {
    GLubyte r,g,b,a;
    Color(GLubyte r_, GLubyte g_, GLubyte b_, GLubyte a);
    Color(GLubyte r_, GLubyte g_, GLubyte b_):Color(r_, g_, b_, 255) {}
};
class IDrawable {
protected:
    Color color;
public:
    virtual void draw() = 0;
};

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