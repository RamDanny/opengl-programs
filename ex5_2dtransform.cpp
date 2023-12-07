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

void translate() {
    glClear(GL_COLOR_BUFFER_BIT);
    int x[8] = {50, 75, 100, 100, 100, 75, 50, 50};
    int y[8] = {50, 50, 50, 75, 100, 100, 100, 75};
    double *point[8], coord[3], mat[3][3];
    int tx, ty;
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
    
    printf("Enter tx, ty: ");
    scanf("%d %d", &tx, &ty);
    for (int i = 0; i < 8; i++) {
        glVertex2d(x[i], y[i]);
        coord[0] = x[i];
        coord[1] = y[i];
        coord[2] = 1;
        
        mat[0][0] = 1;
        mat[0][1] = 0;
        mat[0][2] = tx;
        mat[1][0] = 0;
        mat[1][1] = 1;
        mat[1][2] = ty;
        mat[2][0] = 0;
        mat[2][1] = 0;
        mat[2][2] = 1;
        
        point[i] = transform(mat, coord);
        glVertex2d(point[i][0], point[i][1]);
    }
    
    glEnd();
    
    for (int i = 0; i < 8; i++) {
        glRasterPos2d(point[i][0], point[i][1]-15);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 65+i);
    }
    
    glFlush();
}

void rotate1() {
    glClear(GL_COLOR_BUFFER_BIT);
    int x[8] = {50, 75, 100, 100, 100, 75, 50, 50};
    int y[8] = {50, 50, 50, 75, 100, 100, 100, 75};
    double *point[8], coord[3], mat[3][3];
    int theta;
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
    
    printf("Enter theta: ");
    scanf("%d", &theta);
    for (int i = 0; i < 8; i++) {
        glVertex2d(x[i], y[i]);
        coord[0] = x[i];
        coord[1] = y[i];
        coord[2] = 1;
        
        mat[0][0] = cos(theta * 3.14 / 180);
        mat[0][1] = -sin(theta * 3.14 / 180);
        mat[0][2] = 0;
        mat[1][0] = sin(theta * 3.14 / 180);
        mat[1][1] = cos(theta * 3.14 / 180);
        mat[1][2] = 0;
        mat[2][0] = 0;
        mat[2][1] = 0;
        mat[2][2] = 1;
        
        point[i] = transform(mat, coord);
        glVertex2d(point[i][0], point[i][1]);
    }
    
    glEnd();
    
    for (int i = 0; i < 8; i++) {
        glRasterPos2d(point[i][0], point[i][1]-15);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 65+i);
    }
    
    glFlush();
}

void rotate2() {
    glClear(GL_COLOR_BUFFER_BIT);
    int x[8] = {50, 75, 100, 100, 100, 75, 50, 50};
    int y[8] = {50, 50, 50, 75, 100, 100, 100, 75};
    double *point[8], coord[3], mat[3][3];
    int theta, xr, yr;
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
    
    printf("Enter theta: ");
    scanf("%d", &theta);
    printf("Enter xr, yr: ");
    scanf("%d %d", &xr, &yr);
    for (int i = 0; i < 8; i++) {
        glVertex2d(x[i], y[i]);
        coord[0] = x[i];
        coord[1] = y[i];
        coord[2] = 1;
        
        mat[0][0] = cos(theta * 3.14 / 180);
        mat[0][1] = -sin(theta * 3.14 / 180);
        mat[0][2] = (xr * (1 - cos(theta))) + (yr * sin(theta));
        mat[1][0] = sin(theta * 3.14 / 180);
        mat[1][1] = cos(theta * 3.14 / 180);
        mat[1][2] = (yr * (1 - cos(theta))) - (xr * sin(theta));
        mat[2][0] = 0;
        mat[2][1] = 0;
        mat[2][2] = 1;
        
        point[i] = transform(mat, coord);
        glVertex2d(point[i][0], point[i][1]);
    }
    
    glEnd();
    
    for (int i = 0; i < 8; i++) {
        glRasterPos2d(point[i][0], point[i][1]-15);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 65+i);
    }
    
    glFlush();
}

void scale1() {
    glClear(GL_COLOR_BUFFER_BIT);
    int x[8] = {50, 75, 100, 100, 100, 75, 50, 50};
    int y[8] = {50, 50, 50, 75, 100, 100, 100, 75};
    double *point[8], coord[3], mat[3][3];
    double xs, ys;
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
    
    printf("Enter xs, ys: ");
    scanf("%lf %lf", &xs, &ys);
    for (int i = 0; i < 8; i++) {
        glVertex2d(x[i], y[i]);
        coord[0] = x[i];
        coord[1] = y[i];
        coord[2] = 1;
        
        mat[0][0] = xs;
        mat[0][1] = 0;
        mat[0][2] = 0;
        mat[1][0] = 0;
        mat[1][1] = ys;
        mat[1][2] = 0;
        mat[2][0] = 0;
        mat[2][1] = 0;
        mat[2][2] = 1;
        
        point[i] = transform(mat, coord);
        glVertex2d(point[i][0], point[i][1]);
    }
    
    glEnd();
    
    for (int i = 0; i < 8; i++) {
        glRasterPos2d(point[i][0], point[i][1]-15);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 65+i);
    }
    
    glFlush();
}

void scale2() {
    glClear(GL_COLOR_BUFFER_BIT);
    int x[8] = {50, 75, 100, 100, 100, 75, 50, 50};
    int y[8] = {50, 50, 50, 75, 100, 100, 100, 75};
    double *point[8], coord[3], mat[3][3];
    double xs, ys;
    int xf, yf;
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
    
    printf("Enter xs, ys: ");
    scanf("%lf %lf", &xs, &ys);
    printf("Enter xf, yf: ");
    scanf("%d %d", &xf, &yf);
    for (int i = 0; i < 8; i++) {
        glVertex2d(x[i], y[i]);
        coord[0] = x[i];
        coord[1] = y[i];
        coord[2] = 1;
        
        mat[0][0] = xs;
        mat[0][1] = 0;
        mat[0][2] = xf * (1 - xs);
        mat[1][0] = 0;
        mat[1][1] = ys;
        mat[1][2] = yf * (1 - ys);
        mat[2][0] = 0;
        mat[2][1] = 0;
        mat[2][2] = 1;
        
        point[i] = transform(mat, coord);
        glVertex2d(point[i][0], point[i][1]);
    }
    
    glEnd();
    
    for (int i = 0; i < 8; i++) {
        glRasterPos2d(point[i][0], point[i][1]-15);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 65+i);
    }
    
    glFlush();
}

void reflect1() {
    glClear(GL_COLOR_BUFFER_BIT);
    int x[8] = {50, 75, 100, 100, 100, 75, 50, 50};
    int y[8] = {50, 50, 50, 75, 100, 100, 100, 75};
    double *point[8], coord[3], mat[3][3];
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
    
    for (int i = 0; i < 8; i++) {
        glVertex2d(x[i], y[i]);
        coord[0] = x[i];
        coord[1] = y[i];
        coord[2] = 1;
        
        mat[0][0] = 1;
        mat[0][1] = 0;
        mat[0][2] = 0;
        mat[1][0] = 0;
        mat[1][1] = -1;
        mat[1][2] = 0;
        mat[2][0] = 0;
        mat[2][1] = 0;
        mat[2][2] = 1;
        
        point[i] = transform(mat, coord);
        glVertex2d(point[i][0], point[i][1]);
    }
    
    glEnd();
    
    for (int i = 0; i < 8; i++) {
        glRasterPos2d(point[i][0], point[i][1]-15);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 65+i);
    }
    
    glFlush();
}

void reflect2() {
    glClear(GL_COLOR_BUFFER_BIT);
    int x[8] = {50, 75, 100, 100, 100, 75, 50, 50};
    int y[8] = {50, 50, 50, 75, 100, 100, 100, 75};
    double *point[8], coord[3], mat[3][3];
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
    
    for (int i = 0; i < 8; i++) {
        glVertex2d(x[i], y[i]);
        coord[0] = x[i];
        coord[1] = y[i];
        coord[2] = 1;
        
        mat[0][0] = -1;
        mat[0][1] = 0;
        mat[0][2] = 0;
        mat[1][0] = 0;
        mat[1][1] = 1;
        mat[1][2] = 0;
        mat[2][0] = 0;
        mat[2][1] = 0;
        mat[2][2] = 1;
        
        point[i] = transform(mat, coord);
        glVertex2d(point[i][0], point[i][1]);
    }
    
    glEnd();
    
    for (int i = 0; i < 8; i++) {
        glRasterPos2d(point[i][0], point[i][1]-15);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 65+i);
    }
    
    glFlush();
}

void reflect3() {
    glClear(GL_COLOR_BUFFER_BIT);
    int x[8] = {50, 75, 100, 100, 100, 75, 50, 50};
    int y[8] = {50, 50, 50, 75, 100, 100, 100, 75};
    double *point[8], coord[3], mat[3][3];
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
    
    for (int i = 0; i < 8; i++) {
        glVertex2d(x[i], y[i]);
        coord[0] = x[i];
        coord[1] = y[i];
        coord[2] = 1;
        
        mat[0][0] = -1;
        mat[0][1] = 0;
        mat[0][2] = 0;
        mat[1][0] = 0;
        mat[1][1] = -1;
        mat[1][2] = 0;
        mat[2][0] = 0;
        mat[2][1] = 0;
        mat[2][2] = 1;
        
        point[i] = transform(mat, coord);
        glVertex2d(point[i][0], point[i][1]);
    }
    
    glEnd();
    
    for (int i = 0; i < 8; i++) {
        glRasterPos2d(point[i][0], point[i][1]-15);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 65+i);
    }
    
    glFlush();
}

void reflect4() {
    glClear(GL_COLOR_BUFFER_BIT);
    int x[8] = {50, 75, 100, 100, 100, 75, 50, 50};
    int y[8] = {150, 150, 150, 170, 190, 190, 190, 170};
    double *point[8], coord[3], mat[3][3];
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
    
    for (int i = 0; i < 8; i++) {
        glVertex2d(x[i], y[i]);
        coord[0] = x[i];
        coord[1] = y[i];
        coord[2] = 1;
        
        mat[0][0] = 0;
        mat[0][1] = 1;
        mat[0][2] = 0;
        mat[1][0] = 1;
        mat[1][1] = 0;
        mat[1][2] = 0;
        mat[2][0] = 0;
        mat[2][1] = 0;
        mat[2][2] = 1;
        
        point[i] = transform(mat, coord);
        glVertex2d(point[i][0], point[i][1]);
    }
    
    glEnd();
    
    for (int i = 0; i < 8; i++) {
        glRasterPos2d(point[i][0], point[i][1]-15);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 65+i);
    }
    
    glFlush();
}

void shear1() {
    glClear(GL_COLOR_BUFFER_BIT);
    int x[8] = {0, 25, 50, 50, 50, 25, 0, 0};
    int y[8] = {0, 0, 0, 25, 50, 50, 50, 25};
    double *point[8], coord[3], mat[3][3];
    double xh;
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
    
    printf("Enter xh: ");
    scanf("%lf", &xh);
    for (int i = 0; i < 8; i++) {
        glVertex2d(x[i], y[i]);
        coord[0] = x[i];
        coord[1] = y[i];
        coord[2] = 1;
        
        mat[0][0] = 1;
        mat[0][1] = xh;
        mat[0][2] = 0;
        mat[1][0] = 0;
        mat[1][1] = 1;
        mat[1][2] = 0;
        mat[2][0] = 0;
        mat[2][1] = 0;
        mat[2][2] = 1;
        
        point[i] = transform(mat, coord);
        glVertex2d(point[i][0], point[i][1]);
    }
    
    glEnd();
    
    for (int i = 0; i < 8; i++) {
        glRasterPos2d(point[i][0], point[i][1]-15);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 65+i);
    }
    
    glFlush();
}

void shear2() {
    glClear(GL_COLOR_BUFFER_BIT);
    int x[8] = {0, 25, 50, 50, 50, 25, 0, 0};
    int y[8] = {0, 0, 0, 25, 50, 50, 50, 25};
    double *point[8], coord[3], mat[3][3];
    double yh;
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
    
    printf("Enter yh: ");
    scanf("%lf", &yh);
    for (int i = 0; i < 8; i++) {
        glVertex2d(x[i], y[i]);
        coord[0] = x[i];
        coord[1] = y[i];
        coord[2] = 1;
        
        mat[0][0] = 1;
        mat[0][1] = 0;
        mat[0][2] = 0;
        mat[1][0] = yh;
        mat[1][1] = 1;
        mat[1][2] = 0;
        mat[2][0] = 0;
        mat[2][1] = 0;
        mat[2][2] = 1;
        
        point[i] = transform(mat, coord);
        glVertex2d(point[i][0], point[i][1]);
    }
    
    glEnd();
    
    for (int i = 0; i < 8; i++) {
        glRasterPos2d(point[i][0], point[i][1]-15);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 65+i);
    }
    
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Lab Exercise 5");
    glutDisplayFunc(shear2);
    myInit();
    glutMainLoop();
    return 0;
}
