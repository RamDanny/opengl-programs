# include <GLUT/glut.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>


void myInit() {
     glClearColor(1.0,1.0,1.0,0.0);
     glColor3f(0.0f,0.0f,0.0f);
     glPointSize(4);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(-320.0,320.0,-240.0,240.0);
}

int region(double x, double y, int xwmin, int xwmax, int ywmin, int ywmax) {
    if (x >= xwmin && x <= xwmax && y >= ywmin && y <= ywmax)
        return 0;
    else if (x >= xwmin && x <= xwmax && y > ywmax)
        return 8;
    else if (x >= xwmin && x <= xwmax && y < ywmin)
        return 4;
    else if (x > xwmax && y >= ywmin && y <= ywmax)
        return 2;
    else if (x < xwmin && y >= ywmin && y <= ywmax)
        return 1;
    else if (x < xwmin && y > ywmax)
        return 9;
    else if (x > xwmax && y > ywmax)
        return 10;
    else if (x > xwmax && y < ywmax)
        return 6;
    else return 5;
}

void lineclip() {
    glClear(GL_COLOR_BUFFER_BIT);
    int x[6] = {0, 0, 0, 0, 0, 0}, y[6] = {0, 0, 0, 0, 0, 0}, fp = 0, bp = 5;
    int xwmin, xwmax, ywmin, ywmax;
    printf("Enter xwmin, xwmax, ywmin, ywmax: ");
    scanf("%d %d %d %d", &xwmin, &xwmax, &ywmin, &ywmax);
    printf("Enter x1, y1, x2, y2: ");
    scanf("%d %d %d %d", &(x[0]), &(y[0]), &(x[5]), &(y[5]));
    /*for (int i = 0; i < 8; i++) {
        glRasterPos2d(x[i], y[i]-15);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 97+i);
    }*/
    glBegin(GL_LINES);
    glVertex2d(0,-240);
    glVertex2d(0,240);
    glVertex2d(-320,0);
    glVertex2d(320,0);
    glVertex2d(x[0],y[0]);
    glVertex2d(x[5],y[5]);
    glEnd();
    
    glColor3d(1, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2d(xwmin,ywmin);
    glVertex2d(xwmax,ywmin);
    glVertex2d(xwmax,ywmax);
    glVertex2d(xwmin,ywmax);
    glEnd();
    
    glColor3d(1, 0, 1);
    glBegin(GL_POINTS);
    glVertex2d(x[fp],y[fp]);
    glVertex2d(x[bp],y[bp]);
    int finish = 0;
    double m = (double)(y[5]-y[0])/(x[5]-x[0]);
    
    while (finish == 0) {
        if ((region(x[fp], y[fp], xwmin, xwmax, ywmin, ywmax) | region(x[bp], y[bp], xwmin, xwmax, ywmin, ywmax)) == 0) {
            printf("%d, %d,, %d, %d ta\n", x[fp], y[fp], x[bp], y[bp]);
            finish = 1;
            break;
        }
        else if ((region(x[fp], y[fp], xwmin, xwmax, ywmin, ywmax) & region(x[bp], y[bp], xwmin, xwmax, ywmin, ywmax)) != 0) {
            printf("%d, %d,, %d, %d tr\n", x[fp], y[fp], x[bp], y[bp]);
            finish = 1;
            break;
        }
        else {
            if ((region(x[fp], y[fp], xwmin, xwmax, ywmin, ywmax) & 8) == 8) {
                fp++;
                y[fp] = ywmax;
                x[fp] = x[0] + ((y[fp] - y[0])/m);
                glVertex2d(x[fp],y[fp]);
            }
            else if ((region(x[fp], y[fp], xwmin, xwmax, ywmin, ywmax) & 4) == 4) {
                fp++;
                y[fp] = ywmin;
                x[fp] = x[0] + ((y[fp] - y[0])/m);
                glVertex2d(x[fp],y[fp]);
            }
            else if ((region(x[fp], y[fp], xwmin, xwmax, ywmin, ywmax) & 2) == 2) {
                fp++;
                x[fp] = xwmax;
                y[fp] = y[0] + ((x[fp] - x[0])*m);
                glVertex2d(x[fp],y[fp]);
            }
            else if ((region(x[fp], y[fp], xwmin, xwmax, ywmin, ywmax) & 1) == 1) {
                fp++;
                x[fp] = xwmin;
                y[fp] = y[0] + ((x[fp] - x[0])*m);
                glVertex2d(x[fp],y[fp]);
            }
            
            
            if ((region(x[bp], y[bp], xwmin, xwmax, ywmin, ywmax) & 8) == 8) {
                bp--;
                y[bp] = ywmax;
                x[bp] = x[0] + ((y[bp] - y[0])/m);
                glVertex2d(x[bp],y[bp]);
            }
            else if ((region(x[bp], y[bp], xwmin, xwmax, ywmin, ywmax) & 4) == 4) {
                bp--;
                y[bp] = ywmin;
                x[bp] = x[0] + ((y[bp] - y[0])/m);
                glVertex2d(x[bp],y[bp]);
            }
            else if ((region(x[bp], y[bp], xwmin, xwmax, ywmin, ywmax) & 2) == 2) {
                bp--;
                x[bp] = xwmax;
                y[bp] = y[0] + ((x[bp] - x[0])*m);
                glVertex2d(x[bp],y[bp]);
            }
            else if ((region(x[bp], y[bp], xwmin, xwmax, ywmin, ywmax) & 1) == 1) {
                bp--;
                x[fp] = xwmin;
                y[fp] = y[0] + ((x[fp] - x[0])*m);
                glVertex2d(x[bp],y[bp]);
            }
            printf("%d, %d,, %d, %d\n", x[fp], y[fp], x[bp], y[bp]);
        }
    }
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(x[fp], y[fp]);
    glVertex2d(x[bp],y[bp]);
    glEnd();
    
    glFlush();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Lab Exercise 7");
    glutDisplayFunc(lineclip);
    myInit();
    glutMainLoop();
    return 0;
}
