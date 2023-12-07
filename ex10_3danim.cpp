# include <GLUT/glut.h>
//# include <GL/glut.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

void myInit() {
	glClearColor(1, 1, 1, 0);
	glClearDepth(1.0);
	glColor3f(0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

int x = 0;

void timer(int v) {
	x += 5;
	if (x > 360) x = 0;
	glutPostRedisplay();
	glutTimerFunc(10, timer, 10);
}

void fn() {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluPerspective(45, 1.33, 10, 500);
	glOrtho(-320, 320, -320, 320, -500, 500);
	glTranslatef(0, 0, -250);

	GLfloat pos[] = {100, 0, 100, 1};
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	GLfloat dif[] = {1, 0, 0, 1};
	GLfloat amb[] = {0, 0, 0, 1};
	GLfloat shi[] = {20};
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, dif);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shi);
  glPushMatrix();
	glRotatef(x, 0, 1, 0);
	glutSolidTorus(20, 50, 20, 20);
	glPopMatrix();
	glPopAttrib();

	glutSwapBuffers();
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Blah");
	glutDisplayFunc(fn);
	glutTimerFunc(10, timer, 10);
	glutPostRedisplay();
	myInit();
	glutMainLoop();
	return 0;
}
