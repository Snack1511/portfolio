#include "OpenGLHeaders.h"
#include "LightMgr.h"
#include "CameraMgr.h"
#include "BackgroundMgr.h"
#include "ball.h"
#include "myPannel.h"


#include <stdio.h>
#include <math.h>

//mouse
int px, py;
int cx, cy;
bool bMouseCheck = false;

void reshape(int w, int h) {
	UpdateAspectRatio(float(w) / h);
	SetCamera();
	glViewport(0, 0, w, h);
}

void keyboard(unsigned char c, int, int) {
	switch (c) {
	case 27: exit(0);
	}
}

void mouse(int button, int state, int x, int y) {
	printf("%d button %d-ed at %d %d\n", button, state, x, y);
	if (button == 0 && state == 0) {
		px = x;
		py = y;
		bMouseCheck = true;
	}
	else bMouseCheck = false;
}

void motion(int x, int y) {
	printf("%d, %d\n", x, y);
	if (!bMouseCheck) return;
	cx = x; cy = y;
	float dx = cx - px;
	float dy = cy - py;
	PannelMove(dx*0.01, -dy*0.01);
	px = cx; py = cy;
}


void display() {

	// world
	glMatrixMode(GL_MODELVIEW);
	static float angle = 0;
	glLoadIdentity();
	gluLookAt(0, 0, 3.0, 0, 0, 0, 0, 1, 0);
	angle += 0.01;

	SetLightPosition();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glLineWidth(1);

	drawAxes(1.0);
	drawPlane(20, 0.5);

	glutWireCube(2.0);
	
	glEnable(GL_LIGHTING);
	
	BallMove();
	BallDraw();
	
	PannelDraw();

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

	BallSet(0, 0, 0, 1, 0.5, 0.5);
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
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);

	init();

	glutMainLoop();
	return 1;
}