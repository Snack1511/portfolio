#include "OpenGLHeaders.h"
#include "LightMgr.h"
#include "CameraMgr.h"
#include "BackgroundMgr.h"
#include "Ball.h"
#include "AI.h"

#include <stdio.h>

void reshape(int w, int h) {
	UpdateAspectRatio(float(w) / h);
	SetCamera();
	glViewport(0, 0, w, h);
}

void keyboard(unsigned char c, int, int) {
	switch (c) {
	case 'w':
		
		break;
	case 'a':
		break;
	case 's':
		break;
	case 'd':
		break;
	case 27: exit(0);
	}
}

void motion(int x, int y) {
	printf("%d, %d\n", x, y);
}


void display() {

	// world
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 1.5, 0, 0, 0, 0, 1, 0);

	SetLightPosition();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	EnemyDraw();
	glLineWidth(1);

	drawAxes(1.0);
	drawPlane(20, 0.5);

	glutWireCube(1.0);

	glEnable(GL_LIGHTING);

	BallMove();
	BallDraw();

	glDisable(GL_LIGHTING);

	glutSwapBuffers();


}


void init(void) {
	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);

	// light enable
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	SetLighting();

	BallSet(0, 0, 0, 1, 1, 1);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1024, 768);
	glutCreateWindow("Game");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(reshape);
	glutMotionFunc(motion);
	glutKeyboardFunc(keyboard);

	init();

	glutMainLoop();
	return 1;
}