#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>

#include "Camera.h"
#include "LightEx.h"

#include <math.h>
#include <stdlib.h>

GLfloat lightPos[] = { 0, 1, 0, 1 };
bool bSpot = false;

void keyboard(unsigned char c, int x, int y) {
	switch (c) {
	case 27: exit(0);
	case 'a': lightPos[0] -= 0.05; SetSpot(bSpot, 20.0);  break;
	case 'd': lightPos[0] += 0.05; SetSpot(bSpot, 20.0);  break;
	case 's': bSpot = bSpot ? false : true;
		SetSpot(bSpot, 20.0); break;
	}
	glutPostRedisplay();
}

void reshape(int w, int h) {
	float asp = float(w) / h;
	setCameraLens(60, asp);
	glViewport(0, 0, w, h);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	setCameraPosition(1.5, 1.5, 1.5);

	SetLightPosition(lightPos);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	srand(0);
	for (float x = -1.0; x <= 1.0; x += 0.1) {
		for (float z = -1.0; z <= 1.0; z += 0.1) {
			glColor3f((rand() % 1001) / 1000.0,
				(rand() % 1001) / 1000.0,
				(rand() % 1001) / 1000.0);
			glPushMatrix();
			glTranslatef(x, 0, z);
			glutSolidTeapot(0.1);
			glPopMatrix();
		}
	}

	glutSwapBuffers();
}

void init() {
	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	SetMaterial(1.0, 1.0, 0.0);
	SetLight(1.0, 1.0, 1.0);
}

int main(int argc, char **argv) {
	// glut initialization
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Lighting Test");

	// initialization
	init();

	// callback registration
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(display);

	// enter mainloop
	glutMainLoop();
}