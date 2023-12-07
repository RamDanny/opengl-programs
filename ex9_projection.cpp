# include <GLUT/glut.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>


float cameraX = 0.0f;
float cameraY = 0.0f;
float cameraZ = -250.0f;
float cameraRotation = 0.0f;

void myInit() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}


void projection() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(cameraX, cameraY, cameraZ);
    glRotatef(cameraRotation, 0, 1, 0);
    
    glPointSize(4);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex3f(0,-240, -50);
    glVertex3f(0,240, -50);
    glVertex3f(-320,0, -50);
    glVertex3f(320,0, -50);
    glVertex3f(0,0, -240);
    glVertex3f(0,0, 240);
    glEnd();
    
    glPointSize(4);
    const int points = 24;
    float x[points] = {50.0f, 100.0f, 100.0f, 50.0f, 50.0f, 100.0f, 100.0f, 50.0f, 50.0f, 50.0f, 100.0f, 100.0f, 50.0f, 50.0f, 100.0f, 100.0f, 50.0f, 50.0f, 50.0f, 50.0f, 100.0f, 100.0f, 100.0f, 100.0f};
    float y[points] = {50.0f, 50.0f, 100.0f, 100.0f, 50.0f, 50.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 50.0f, 50.0f, 50.0f, 50.0f, 100.0f, 50.0f, 100.0f, 50.0f, 100.0f, 50.0f, 100.0f, 50.0f};
    float z[points] = {-50.0f, -50.0f, -50.0f, -50.0f, 0, 0, 0, 0, 0, -50.0f, 0, -50.0f, 0, -50.0f, 0, -50.0f, -50.0f, -50.0f, 0, 0, -50.0f, -50.0f, 0, 0};
    
    for (int i = 0; i < 8; i++) {
        glRasterPos3f(x[i], y[i]-5, z[i]);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 97+i);
    }
    
    glBegin(GL_LINES);
    for (int i = 0; i < points; i++) {
        glVertex3f(x[i], y[i], z[i]);
    }
    glEnd();
    glutSwapBuffers();
}

void handleKeypress(unsigned char key, int x, int y) {
    if (key == 'w') {
        cameraZ += 10.0f;
    }
    else if (key == 's') {
        cameraZ -= 10.0f;
    }
    else if (key == 'a') {
        cameraX -= 10.0f;
    }
    else if (key == 'd') {
        cameraX += 10.0f;
    }
    else if (key == 'q') {
        cameraRotation += 5.0f;
    }
    else if (key == 'e') {
        cameraRotation -= 5.0f;
    }
    glutPostRedisplay();
}

void reshape1(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 10.0f, 500.0f);
}

void reshape2(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-320, 320, -240, 240, -500, 500);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-640)/2, (glutGet(GLUT_SCREEN_HEIGHT)-480)/2);
    glutCreateWindow("Lab Exercise 9");
    glutDisplayFunc(projection);
    
    int ch;
    printf("Choose 1) Perspective\t2) Orthographic: ");
    scanf("%d", &ch);
    
    if (ch == 1) {
		glutReshapeFunc(reshape1);
    }
    else if (ch == 2) {
    	glutReshapeFunc(reshape2);
    }
    myInit();
    glutKeyboardFunc(handleKeypress);
    glutMainLoop();
    return 0;
}
