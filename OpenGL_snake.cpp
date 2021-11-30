#include <glut.h>
#include <vector>


struct point {
    float x, y;
};
struct Color {
    GLubyte r,g,b,a;
    void set_to_env() {
        glColor4ub(r, g, b, a);
    }
    Color(GLubyte r_, GLubyte g_, GLubyte b_, GLubyte a);
    Color(GLubyte r_, GLubyte g_, GLubyte b_):Color(r_, g_, b_, 255) {}
};
class Drawable {
protected:
    Color color;
public:
    virtual void draw() = 0;
};
class Rectangle :public Drawable {
protected:
    point c, r;
public:
    Rectangle(point c_, point r_, Color color_){
        c = c_; r = r_; color = color_;
    }
    void draw() {
        glBegin(GL_POLYGON);
        color.set_to_env();
        glVertex2f(c.x - r.x, c.y - r.y);
        glVertex2f(c.x - r.x, c.y + r.y);
        glVertex2f(c.x + r.x, c.y + r.y);
        glVertex2f(c.x + r.x, c.y - r.y);
        glEnd();
    }
};
class Square : public Rectangle {
public:
    Square(point c_, float r_, Color color_) :Rectangle(c_, { r_,r_ }, color_) {};
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