#include <Windows.h>
#include <gl/GL.h>
#include <gl/glut.h>
#include <math.h>

bool bPers = true;
// parameters for camera lens
float aspRatio = 1.0;

//light parameters
GLfloat lit_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };//빛 색
GLfloat lit_specular[] = { 1.0, 1.0, 1.0, 1.0 };//하이라이트 색
GLfloat lit_ambient0[] = { 1.0, 0.0, 0.0, 1.0 };//?
GLfloat lit_ambient1[] = { 0.0, 0.0, 1.0, 1.0 };
GLfloat lit_ambient2[] = { 0.0, 1.0, 0.0, 1.0 };
GLfloat lit_position0[] = { 5, 5, 0, 1 };
GLfloat lit_position1[] = { 5, 5, 0, 1 };
GLfloat lit_position2[] = { 5, 5, 0, 1 };


// material parameters
GLfloat mat_diffuse[] = { 0.0, 0.3, 0.3, 1.0 };
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_ambient[] = { 0.0, 0.03, 0.0, 1.0 };

void SetLighting(void) {
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glLightfv(GL_LIGHT0, GL_AMBIENT, lit_ambient0);
	glLightfv(GL_LIGHT1, GL_AMBIENT, lit_ambient1);
	glLightfv(GL_LIGHT2, GL_AMBIENT, lit_ambient2);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lit_diffuse);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lit_diffuse);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, lit_diffuse);


	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 90);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lit_specular);
	glLightfv(GL_LIGHT1, GL_SPECULAR, lit_specular);
	glLightfv(GL_LIGHT2, GL_SPECULAR, lit_specular);
}

void SetLightPosition(void) {
	glLightfv(GL_LIGHT0, GL_POSITION, lit_position0);
	glLightfv(GL_LIGHT1, GL_POSITION, lit_position1);
	glLightfv(GL_LIGHT2, GL_POSITION, lit_position2);
}


void SetCamera() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	bPers ? gluPerspective(60, aspRatio, 0.1, 1000) : glOrtho(-10, 10, -10, 10, -100, 100);
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

void drawPlane(float width, float interval) {
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_LINES);
	for (float i = -width; i <= width; i += interval) {
		glVertex3f(i, 0, -width);
		glVertex3f(i, 0, width);
		glVertex3f(width, 0, i);
		glVertex3f(-width, 0, i);
	}
	glEnd();
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

	gluLookAt(2, 2, 2, 0, 0, 0, 0, 1, 0);

	static float angle = 0;
	angle += 0.01;
	lit_position0[0] = 5.0*cos(angle);
	lit_position0[1] = 0.0;
	lit_position0[2] = 5.0*sin(angle);
	lit_position1[0] = 5.0*cos(-angle);
	lit_position1[1] = 5.0*sin(-angle);
	lit_position1[2] = 0.0;
	lit_position2[0] = 0.0;
	lit_position2[1] = 5.0*sin(angle);
	lit_position2[2] = 5.0*cos(angle);

	SetLightPosition();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glLineWidth(1);
	//draw axes
	drawAxes(1.0);

	// draw plane
	drawPlane(20, 0.5);

	glEnable(GL_LIGHTING);
	// draw Teapot
	//glutSolidTeapot(1.0);
	glutSolidSphere(1.0, 256, 256);

	glDisable(GL_LIGHTING);

	glutSwapBuffers();

}


void init(void) {
	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);

	// light enable
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	SetLighting();
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