#include<GLUT/glut.h>
void myInit() {
     glClearColor(1.0,1.0,1.0,0.0);
     glColor3f(0.0f,0.0f,0.0f);
     glPointSize(10);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0,640.0,0.0,480.0);
}
void a1() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    glVertex2d(50,100);
    glVertex2d(100,100);
    glVertex2d(100,50);
    glVertex2d(50,50);
    glEnd();
    glFlush();
}
void a2() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glVertex2d(50,100);
    glVertex2d(100,100);
    glVertex2d(100,50);
    glVertex2d(50,50);
    glEnd();
    glFlush();
}
void a3() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_STRIP);
    glVertex2d(50,100);
    glVertex2d(100,100);
    glVertex2d(100,50);
    glVertex2d(50,50);
    glEnd();
    glFlush();
}
void a4() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    glVertex2d(50,100);
    glVertex2d(100,100);
    glVertex2d(100,50);
    glVertex2d(50,50);
    glEnd();
    glFlush();
}
void a5() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glVertex2d(50,100);
    glVertex2d(100,100);
    glVertex2d(100,50);
    glEnd();
    glFlush();
}
void a6() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glVertex2d(50,100);
    glVertex2d(100,100);
    glVertex2d(100,50);
    glVertex2d(50,50);
    glEnd();
    glFlush();
}
void a7() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUAD_STRIP);
    glVertex2d(50,50);
    glVertex2d(50,100);
    glVertex2d(100,50);
    glVertex2d(100,100);
    glVertex2d(150,50);
    glVertex2d(150,100);
    glEnd();
    glFlush();
}
void a8() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex2d(150,150);
    glVertex2d(175,100);
    glVertex2d(150,50);
    glVertex2d(100,50);
    glVertex2d(75,100);
    glVertex2d(100,150);
    glEnd();
    glFlush();
}
void b1() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_LINES);
    for (int i = 0; i < 9; i++) {
        glVertex2d(100, 100 + (25 * i));
        glVertex2d(300, 100 + (25 * i));
        
        glVertex2d(100 + (25 * i), 100);
        glVertex2d(100 + (25 * i), 300);
    }
    glEnd();
    int k = 1;
    for (int i = 0; i < 8; i++) {
        k = (k+1) % 2;
        for (int j = 0; j < 8; j++) {
            if (k == 0) {
                glBegin(GL_QUADS);
                glVertex2d(100+(25*j),125+(25*i));
                glVertex2d(125+(25*j),125+(25*i));
                glVertex2d(125+(25*j),100+(25*i));
                glVertex2d(100+(25*j),100+(25*i));
                glEnd();
            }
            k = (k+1) % 2;
        }
    }
    
    glFlush();
}
void c1() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    glVertex2d(100,200);
    glVertex2d(200,200);
    glVertex2d(200,100);
    glVertex2d(100,100);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2d(150,250);
    glVertex2d(200,200);
    glVertex2d(100,200);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2d(125,100);
    glVertex2d(125,150);
    glVertex2d(175,150);
    glVertex2d(175,100);
    glEnd();
    glFlush();
}
int main(int argc,char* argv[]) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutCreateWindow("Lab Exercise 1");
    glutDisplayFunc(c1);
    myInit();
    glutMainLoop();
    return 1;
}
