# include <GLUT/glut.h>
# include <stdio.h>
# include <math.h>
void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}
void myInit() {
     glClearColor(1.0,1.0,1.0,0.0);
     glColor3f(0.0f,0.0f,0.0f);
     glPointSize(4);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(-320.0,320.0,-240.0,240.0);
}
 
void circle()
{
    glClear(GL_COLOR_BUFFER_BIT);
    int xc, yc, r;
    int x, y, p;
    printf("Enter xc, yc, r: ");
    scanf("%d %d %d", &xc, &yc, &r);
    glRasterPos2d(xc, yc-15);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, int('C'));
    glBegin(GL_LINES);
    glVertex2d(0,-240);
    glVertex2d(0,240);
    glVertex2d(-320,0);
    glVertex2d(320,0);
    glEnd();
    glBegin(GL_POINTS);
    
    x = 0;
    y = r;
    glVertex2d(x + xc, y + yc);
    if (r > 0) {
        glVertex2d(x + xc, -y + yc);
        glVertex2d(y + xc, x + yc);
        glVertex2d(-y + xc, x + yc);
        p = 1 - r;
        while (y > x) {
            x++;
            if (p <= 0) {
                p = p + (2 * x) + 1;
            }
            else {
                y--;
                p = p + (2 * x) - (2 * y) + 1;
            }
            if (x > y) break;
            glVertex2d(x + xc, y + yc);
            glVertex2d(x + xc, -y + yc);
            glVertex2d(-x + xc, y + yc);
            glVertex2d(-x + xc, -y + yc);
            glVertex2d(y + xc, x + yc);
            glVertex2d(y + xc, -x + yc);
            glVertex2d(-y + xc, x + yc);
            glVertex2d(-y + xc, -x + yc);
        }
    }
    
    glEnd();
    glFlush();
}
void pattern() {
    glClear(GL_COLOR_BUFFER_BIT);
    int xc, yc, r = 50;
    int x, y, p;
    int xcen[] = {50, 150, 250, 100, 200};
    int ycen[] = {100, 100, 100, 50, 50};
    for (int k = 0; k < 5; k++) {
        xc = xcen[k];
        yc = ycen[k];
        glBegin(GL_LINES);
        glVertex2d(0,-240);
        glVertex2d(0,240);
        glVertex2d(-320,0);
        glVertex2d(320,0);
        glEnd();
        glBegin(GL_POINTS);
        
        x = 0;
        y = r;
        glVertex2d(x + xc, y + yc);
        if (r > 0) {
            glVertex2d(x + xc, -y + yc);
            glVertex2d(y + xc, x + yc);
            glVertex2d(-y + xc, x + yc);
            p = 1 - r;
            while (y > x) {
                x++;
                if (p <= 0) {
                    p = p + (2 * x) + 1;
                }
                else {
                    y--;
                    p = p + (2 * x) - (2 * y) + 1;
                }
                if (x > y) break;
                glVertex2d(x + xc, y + yc);
                glVertex2d(x + xc, -y + yc);
                glVertex2d(-x + xc, y + yc);
                glVertex2d(-x + xc, -y + yc);
                glVertex2d(y + xc, x + yc);
                glVertex2d(y + xc, -x + yc);
                glVertex2d(-y + xc, x + yc);
                glVertex2d(-y + xc, -x + yc);
            }
        }
    }
    glEnd();
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Lab Exercise 4");
    glutDisplayFunc(circle);
    myInit();
    glutMainLoop();
    return 0;
}
