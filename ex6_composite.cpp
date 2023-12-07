# include <GLUT/glut.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>


double *transform(double a[3][3], double b[3], int alen=3, int blen=3) {
    double *res = (double *)malloc(blen * sizeof(double));
    for (int i = 0; i < blen; i++) {
        res[i] = 0;
        for (int j = 0; j < blen; j++) {
            res[i] += a[i][j] * b[j];
        }
    }
    return res;
}

void myInit() {
     glClearColor(1.0,1.0,1.0,0.0);
     glColor3f(0.0f,0.0f,0.0f);
     glPointSize(4);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(-320.0,320.0,-240.0,240.0);
}

void composite() {
    glClear(GL_COLOR_BUFFER_BIT);
    int x[8] = {50, 75, 100, 100, 100, 75, 50, 50};
    int y[8] = {50, 50, 50, 75, 100, 100, 100, 75};
    double *point[8], *point2[8], coord[3], mat[3][3];
    for (int i = 0; i < 8; i++) {
        glRasterPos2d(x[i], y[i]-15);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 97+i);
    }
    glBegin(GL_LINES);
    glVertex2d(0,-240);
    glVertex2d(0,240);
    glVertex2d(-320,0);
    glVertex2d(320,0);
    glEnd();
    glBegin(GL_POINTS);
    
    int tx, ty, theta;
    double xs, ys, xh;
    int ch;
    for (int i = 0; i < 2; i++) {
        printf("Transform %d:\n", i+1);
        printf("1) Translate\t2) Rotate\t3) Scale\n");
        printf("4) Reflect\t5) Shear\n");
        printf("Choice: ");
        scanf("%d", &ch);
        if (ch == 1) {
            printf("Enter tx, ty: ");
            scanf("%d %d", &tx, &ty);
            mat[0][0] = 1;
            mat[0][1] = 0;
            mat[0][2] = tx;
            mat[1][0] = 0;
            mat[1][1] = 1;
            mat[1][2] = ty;
            mat[2][0] = 0;
            mat[2][1] = 0;
            mat[2][2] = 1;
            
            if (i == 0) {
                for (int j = 0; j < 8; j++) {
                    coord[0] = x[j];
                    coord[1] = y[j];
                    coord[2] = 1;
                    
                    point[j] = transform(mat, coord);
                }
            }
            else if (i == 1) {
                for (int j = 0; j < 8; j++) {
                    coord[0] = point[j][0];
                    coord[1] = point[j][1];
                    coord[2] = 1;
                    
                    point2[j] = transform(mat, coord);
                }
            }
        }
        else if (ch == 2) {
            int theta;
            printf("Enter theta: ");
            scanf("%d", &theta);
            mat[0][0] = cos(theta * 3.14 / 180);
            mat[0][1] = -sin(theta * 3.14 / 180);
            mat[0][2] = 0;
            mat[1][0] = sin(theta * 3.14 / 180);
            mat[1][1] = cos(theta * 3.14 / 180);
            mat[1][2] = 0;
            mat[2][0] = 0;
            mat[2][1] = 0;
            mat[2][2] = 1;
            
            if (i == 0) {
                for (int j = 0; j < 8; j++) {
                    coord[0] = x[j];
                    coord[1] = y[j];
                    coord[2] = 1;
                    
                    point[j] = transform(mat, coord);
                }
            }
            else if (i == 1) {
                for (int j = 0; j < 8; j++) {
                    coord[0] = point[j][0];
                    coord[1] = point[j][1];
                    coord[2] = 1;
                    
                    point2[j] = transform(mat, coord);
                }
            }
        }
        else if (ch == 3) {
            printf("Enter xs, ys: ");
            scanf("%lf %lf", &xs, &ys);
            mat[0][0] = xs;
            mat[0][1] = 0;
            mat[0][2] = 0;
            mat[1][0] = 0;
            mat[1][1] = ys;
            mat[1][2] = 0;
            mat[2][0] = 0;
            mat[2][1] = 0;
            mat[2][2] = 1;
            
            if (i == 0) {
                for (int j = 0; j < 8; j++) {
                    coord[0] = x[j];
                    coord[1] = y[j];
                    coord[2] = 1;
                    
                    point[j] = transform(mat, coord);
                }
            }
            else if (i == 1) {
                for (int j = 0; j < 8; j++) {
                    coord[0] = point[j][0];
                    coord[1] = point[j][1];
                    coord[2] = 1;
                    
                    point2[j] = transform(mat, coord);
                }
            }
        }
        else if (ch == 4) {
            mat[0][0] = -1;
            mat[0][1] = 0;
            mat[0][2] = 0;
            mat[1][0] = 0;
            mat[1][1] = -1;
            mat[1][2] = 0;
            mat[2][0] = 0;
            mat[2][1] = 0;
            mat[2][2] = 1;
            
            if (i == 0) {
                for (int j = 0; j < 8; j++) {
                    coord[0] = x[j];
                    coord[1] = y[j];
                    coord[2] = 1;
                    
                    point[j] = transform(mat, coord);
                }
            }
            else if (i == 1) {
                for (int j = 0; j < 8; j++) {
                    coord[0] = point[j][0];
                    coord[1] = point[j][1];
                    coord[2] = 1;
                    
                    point2[j] = transform(mat, coord);
                }
            }
        }
        else if (ch == 5) {
            printf("Enter xh: ");
            scanf("%lf", &xh);
            mat[0][0] = 1;
            mat[0][1] = xh;
            mat[0][2] = 0;
            mat[1][0] = 0;
            mat[1][1] = 1;
            mat[1][2] = 0;
            mat[2][0] = 0;
            mat[2][1] = 0;
            mat[2][2] = 1;
            
            if (i == 0) {
                for (int j = 0; j < 8; j++) {
                    coord[0] = x[j];
                    coord[1] = y[j];
                    coord[2] = 1;
                    
                    point[j] = transform(mat, coord);
                }
            }
            else if (i == 1) {
                for (int j = 0; j < 8; j++) {
                    coord[0] = point[j][0];
                    coord[1] = point[j][1];
                    coord[2] = 1;
                    
                    point2[j] = transform(mat, coord);
                }
            }
        }
    }
    
    for (int i = 0; i < 8; i++) {
        glVertex2d(point2[i][0], point2[i][1]);
    }
    
    glEnd();
    
    for (int i = 0; i < 8; i++) {
        glRasterPos2d(point2[i][0], point2[i][1]-15);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 65+i);
    }
    
    glFlush();
}

double mapX(int x, int xmin, int xmax, int xvmin, int xvmax) {
    return xvmin + ((x - xmin) * (double)(xvmax - xvmin) / (xmax - xmin));
}

double mapY(int y, int ymin, int ymax, int yvmin, int yvmax) {
    return yvmin + ((y - ymin) * (double)(yvmax - yvmin) / (ymax - ymin));
}

void viewport() {
    glClear(GL_COLOR_BUFFER_BIT);
    int x[8] = {50, 100, 150, 150, 150, 100, 50, 50};
    int y[8] = {50, 50, 50, 100, 150, 150, 150, 100};
    double xv[8] = {0, 0, 0, 0, 0, 0, 0, 0}, yv[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int xmin = -320, xmax = 320, ymin = -240, ymax = 240;
    int xvmin, xvmax, yvmin, yvmax;
    printf("Enter xvmin, xvmax, yvmin, yvmax: ");
    scanf("%d %d %d %d", &xvmin, &xvmax, &yvmin, &yvmax);
    for (int i = 0; i < 8; i++) {
        glRasterPos2d(x[i], y[i]-15);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 97+i);
    }
    glBegin(GL_LINES);
    glVertex2d(0,ymin);
    glVertex2d(0,ymax);
    glVertex2d(xmin,0);
    glVertex2d(xmax,0);
    glEnd();
    
    glColor3d(1, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2d(xvmin,yvmin);
    glVertex2d(xvmax,yvmin);
    glVertex2d(xvmax,yvmax);
    glVertex2d(xvmin,yvmax);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex2d(mapX(0, xmin, xmax, xvmin, xvmax), mapY(ymin, ymin, ymax, yvmin, yvmax));
    glVertex2d(mapX(0, xmin, xmax, xvmin, xvmax), mapY(ymax, ymin, ymax, yvmin, yvmax));
    glVertex2d(mapX(xmin, xmin, xmax, xvmin, xvmax), mapY(0, ymin, ymax, yvmin, yvmax));
    glVertex2d(mapX(xmax, xmin, xmax, xvmin, xvmax), mapY(0, ymin, ymax, yvmin, yvmax));
    glEnd();
    
    glBegin(GL_POINTS);
    for (int i = 0; i < 8; i++) {
        glColor3d(0, 0, 0);
        glVertex2d(x[i], y[i]);
        glColor3d(1, 0, 0);
        xv[i] = mapX(x[i], xmin, xmax, xvmin, xvmax);
        yv[i] = mapY(y[i], ymin, ymax, yvmin, yvmax);
        glVertex2d(xv[i], yv[i]);
    }
    glEnd();
    
    for (int i = 0; i < 8; i++) {
        glRasterPos2d(xv[i], yv[i]-15);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, 65+i);
    }
    
    glFlush();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Lab Exercise 6");
    glutDisplayFunc(viewport);
    myInit();
    glutMainLoop();
    return 0;
}
