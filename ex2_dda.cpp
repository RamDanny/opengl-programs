#include <GLUT/GLUT.h>
# include <stdio.h>
# include <math.h>
void myInit() {
     glClearColor(1.0,1.0,1.0,0.0);
     glColor3f(0.0f,0.0f,0.0f);
     glPointSize(4);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(-320.0,320.0,-240.0,240.0);
}
 
void dda()
{
    glClear(GL_COLOR_BUFFER_BIT);
    int xa, ya, xb, yb;
    float dx, dy, x, y, step;
    printf("Enter xa, ya, xb, yb: ");
    scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
    glRasterPos2d(xa, ya-15);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, int('A'));
    glRasterPos2d(xb, yb-15);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, int('B'));
    glBegin(GL_LINES);
    glVertex2d(0,-240);
    glVertex2d(0,240);
    glVertex2d(-320,0);
    glVertex2d(320,0);
    glEnd();
    glBegin(GL_POINTS);
    
    dx = (xb - xa);
    dy = (yb - ya);
    if (abs(dx) >= abs(dy))
        step = abs(dx);
    else
        step = abs(dy);
    dx = dx / step;
    dy = dy / step;
    x = xa;
    y = ya;
    int i = 0;
    while (i <= step) {
        glVertex2d(x, y);
        x = x + dx;
        y = y + dy;
        i = i + 1;
    }
    
    
    glEnd();
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Lab Exercise 2");
    glutDisplayFunc(dda);
    myInit();
    glutMainLoop();
    return 0;
}
