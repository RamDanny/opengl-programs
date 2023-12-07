# include <GLUT/glut.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
float *transform(float a[4][4], float b[4], int alen=4, int blen=4)
{
    float *res = (float *)malloc(blen * sizeof(float));
    for (int i = 0; i < blen; i++) {
        res[i] = 0;
        for (int j = 0; j < blen; j++) {
            res[i] += a[i][j] * b[j];
        }
    }
    return res;
}
void myInit() {
   glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
   glClearDepth(1.0f);
   glEnable(GL_DEPTH_TEST);
   glDepthFunc(GL_LEQUAL);
   glShadeModel(GL_SMOOTH);
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}
void translate() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -250.0f);
    glPointSize(4);
    
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex3f(0,-240, -50);
    glVertex3f(0,240, -50);
    glVertex3f(-320,0, -50);
    glVertex3f(320,0, -50);
    glEnd();
    
    glPointSize(4);
    float x[8] = {50.0f, 75.0f, 100.0f, 100.0f, 100.0f, 75.0f, 50.0f, 50.0f};
    float y[8] = {50.0f, 50.0f, 50.0f, 75.0f, 100.0f, 100.0f, 100.0f, 75.0f};
    float z[8] = {-50.0f, -75.0f, -50.0f, -50.0f, -50.0f, -75.0f, -50.0f, -50.0f};
    
    for (int i = 0; i < 8; i++) {
        glRasterPos3f(x[i], y[i]-15, z[i]);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 97+i);
    }
    
    glBegin(GL_POINTS);
    float *point[8], coord[4], mat[4][4];
    int tx, ty, tz;
    printf("Enter tx, ty, tz: ");
    scanf("%d %d %d", &tx, &ty, &tz);
    for (int i = 0; i < 8; i++) {
        glVertex3f(x[i], y[i], z[i]);
        coord[0] = x[i];
        coord[1] = y[i];
        coord[2] = z[i];
        coord[3] = 1;
        mat[0][0] = 1;
        mat[0][1] = 0;
        mat[0][2] = 0;
        mat[0][3] = tx;
        mat[1][0] = 0;
        mat[1][1] = 1;
        mat[1][2] = 0;
        mat[1][3] = ty;
        mat[2][0] = 0;
        mat[2][1] = 0;
        mat[2][2] = 1;
        mat[2][3] = tz;
        mat[3][0] = 0;
        mat[3][1] = 0;
        mat[3][2] = 0;
        mat[3][3] = 1;
        point[i] = transform(mat, coord);
        glVertex3f(point[i][0], point[i][1], point[i][2]);
    }
    glEnd();
    
    for (int i = 0; i < 8; i++) {
        glRasterPos3f(point[i][0], point[i][1]-15, point[i][2]);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 65+i);
    }
    
    glutSwapBuffers();
}
void rotate() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -250.0f);
    glPointSize(4);
    
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex3f(0,-240, -50);
    glVertex3f(0,240, -50);
    glVertex3f(-320,0, -50);
    glVertex3f(320,0, -50);
    glEnd();
    
    glPointSize(4);
    float x[8] = {50.0f, 75.0f, 100.0f, 100.0f, 100.0f, 75.0f, 50.0f, 50.0f};
    float y[8] = {50.0f, 50.0f, 50.0f, 75.0f, 100.0f, 100.0f, 100.0f, 75.0f};
    float z[8] = {-50.0f, -75.0f, -50.0f, -50.0f, -50.0f, -75.0f, -50.0f, -50.0f};
    
    for (int i = 0; i < 8; i++) {
        glRasterPos3f(x[i], y[i]-15, z[i]);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 97+i);
    }
    
    glBegin(GL_POINTS);
    float *point[8], coord[4], mat[4][4];
    int theta;
    printf("Enter theta: ");
    scanf("%d", &theta);
    for (int i = 0; i < 8; i++) {
        glVertex3f(x[i], y[i], z[i]);
        coord[0] = x[i];
        coord[1] = y[i];
        coord[2] = z[i];
        coord[3] = 1;
        mat[0][0] = cos(theta * 3.14 / 180);
        mat[0][1] = -sin(theta * 3.14 / 180);
        mat[0][2] = 0;
        mat[0][3] = 0;
        mat[1][0] = sin(theta * 3.14 / 180);
        mat[1][1] = cos(theta * 3.14 / 180);
        mat[1][2] = 0;
        mat[1][3] = 0;
        mat[2][0] = 0;
        mat[2][1] = 0;
        mat[2][2] = 1;
        mat[2][3] = 0;
        mat[3][0] = 0;
        mat[3][1] = 0;
        mat[3][2] = 0;
        mat[3][3] = 1;
        point[i] = transform(mat, coord);
        glVertex3f(point[i][0], point[i][1], point[i][2]);
    }
    glEnd();
    
    for (int i = 0; i < 8; i++) {
        glRasterPos3f(point[i][0], point[i][1]-15, point[i][2]);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 65+i);
    }
    
    glutSwapBuffers();
}
void scale() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -250.0f);
    glPointSize(4);
    
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex3f(0,-240, -50);
    glVertex3f(0,240, -50);
    glVertex3f(-320,0, -50);
    glVertex3f(320,0, -50);
    glEnd();
    
    glPointSize(4);
    float x[8] = {50.0f, 75.0f, 100.0f, 100.0f, 100.0f, 75.0f, 50.0f, 50.0f};
    float y[8] = {50.0f, 50.0f, 50.0f, 75.0f, 100.0f, 100.0f, 100.0f, 75.0f};
    float z[8] = {-50.0f, -75.0f, -50.0f, -50.0f, -50.0f, -75.0f, -50.0f, -50.0f};
    
    for (int i = 0; i < 8; i++) {
        glRasterPos3f(x[i], y[i]-15, z[i]);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 97+i);
    }
    
    glBegin(GL_POINTS);
    float *point[8], coord[4], mat[4][4];
    float sx, sy, sz;
    printf("Enter sx, sy, sz: ");
    scanf("%f %f %f", &sx, &sy, &sz);
    for (int i = 0; i < 8; i++) {
        glVertex3f(x[i], y[i], z[i]);
        coord[0] = x[i];
        coord[1] = y[i];
        coord[2] = z[i];
        coord[3] = 1;
        mat[0][0] = sx;
        mat[0][1] = 0;
        mat[0][2] = 0;
        mat[0][3] = 0;
        mat[1][0] = 0;
        mat[1][1] = sy;
        mat[1][2] = 0;
        mat[1][3] = 0;
        mat[2][0] = 0;
        mat[2][1] = 0;
        mat[2][2] = sz;
        mat[2][3] = 0;
        mat[3][0] = 0;
        mat[3][1] = 0;
        mat[3][2] = 0;
        mat[3][3] = 1;
        point[i] = transform(mat, coord);
        glVertex3f(point[i][0], point[i][1], point[i][2]);
    }
    glEnd();
    
    for (int i = 0; i < 8; i++) {
        glRasterPos3f(point[i][0], point[i][1]-7, point[i][2]);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 65+i);
    }
    
    glutSwapBuffers();
}
void reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 10.0f, 500.0f);
}
int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE);
   glutInitWindowSize(640, 480);
   glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-640)/2, (glutGet(GLUT_SCREEN_HEIGHT)-480)/2);
   glutCreateWindow("Lab Exercise 8");
   glutDisplayFunc(scale);
   glutReshapeFunc(reshape);
   myInit();
   glutMainLoop();
   return 0;
}
