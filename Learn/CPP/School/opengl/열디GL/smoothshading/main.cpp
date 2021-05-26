#include <Windows.h>
#include <gl/GL.h>
#include <gl/glut.h>
#include <math.h>
#include <stdio.h>
#include "mesh.h"

CMesh mesh1, mesh2;




float aspRatio = 1.0;

//light parameters
GLfloat lit_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat lit_position[] = { 1, 1, 1, 0 };
// material parameters
GLfloat mat_diffuse[] = { 1.0, 1.0, 0.5, 1.0 };

void SetLighting(void) {
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lit_diffuse);

}

void SetLightPosition(void) {
	glLightfv(GL_LIGHT0, GL_POSITION, lit_position);
}


void SetCamera() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, aspRatio, 0.1, 1000);
}

void reshape(int w, int h) {
	aspRatio = float(w) / h;
	SetCamera();
	glViewport(0, 0, w, h);
}

void keyboard(unsigned char c, int, int) {
	switch (c) {
	case 27: exit(0);
	}
}

void drawAxes(float size) {
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0); glVertex3f(size, 0, 0);
	glColor3f(0, 1, 0);
	glVertex3f(0, 0, 0); glVertex3f(0, size, 0);
	glColor3f(0, 0, 1);
	glVertex3f(0, 0, 0); glVertex3f(0, 0, size);
	glEnd();
}



void display() {


	// world
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	static float angle = 0;
	gluLookAt(70.0*cos(angle), 50, 70.0*sin(angle), 0, 50, 0, 0, 1, 0);
	angle += 0.01;

	SetLightPosition();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glLineWidth(1);
	//draw axes
	drawAxes(1.0);

	glEnable(GL_LIGHTING);

	// draw mesh
	glColor3f(1, 1, 0);  mesh1.show();
	glColor3f(0, 0, 1);  mesh2.show();

	glDisable(GL_LIGHTING);

	glutSwapBuffers();

}


void init(void) {
	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);

	// light enable
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	SetLighting();

	mesh1.read("complex.sms");
	mesh2.read("cloth.sms");

}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Light");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	init();


	glutMainLoop();

	return 1;
}