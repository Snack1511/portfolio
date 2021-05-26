#include <Windows.h>
#include <gl/GL.h>
#include <gl/glut.h>
#include <math.h>

bool bPers = true;

// parameters for camera lens
float aspRatio = 1.0;
float angle = 0;
float lightPosX = 0, lightPosY = 0;
//light parameters


GLfloat lit_specular[] = { 1.0, 1.0, 1.0, 1.0 };//하이라이트 색상
GLfloat lit_ambient[] = { 0.0, 0.0, 0.0, 1.0 };

//material parameters

GLfloat mat_specular[] = { 0.0, 1.0, 1.0, 1.0 };
GLfloat mat_ambient[] = { 1.0, 1.0, 0.0, 1.0 };
GLfloat mat_shininess[] = { 100.0 };

void SetLighting() {
	GLfloat lit_diffuse[] = { 1.0, 0.0 + 20 * angle, 1.0 - 20 * angle, 1.0 };
	GLfloat mat_diffuse[] = { 1.0, 0.0+20*angle, 1.0-20*angle, 1.0 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lit_diffuse);

	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lit_specular);
}

void SetLightPosition() {
	GLfloat lit_position[] = { 12*cos(angle), 0, 12 * sin(angle), 1 };
	glLightfv(GL_LIGHT0, GL_POSITION, lit_position);
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

void sphere_make() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			glPushMatrix();
			glColor3f(1.0, 0.0 + 20 * angle, 1.0 - 20 * angle);
			glTranslated(-6+j*2.5, -6+i*2.5, 0);
			glutSolidSphere(1, 100, 100);
			glPopMatrix();
		}
	}
}

void display() {


	// world
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 20, 0, 0, 0, 0, 1, 0);
	angle += 0.01;

	SetLightPosition();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glLineWidth(1);
	//draw axes
	drawAxes(1.0);

	// draw plane
	drawPlane(20, 0.5);
	
	glEnable(GL_LIGHTING);
	//drawteapot
	//glutSolidTeapot(1.0);
	sphere_make();
	glDisable(GL_LIGHTING);

	glutSwapBuffers();

}

void init() {
	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);

	//light enable
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	SetLighting();
}//init = (initialization)초기화

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