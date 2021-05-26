#include <Windows.h>
#include <gl/GL.h>
#include <gl/glut.h>
#include <math.h>

// parameters for camera lens
float aspRatio = 1.0;
float angle = 60;
int sight = 1;
void SetCamera() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluPerspective(angle, aspRatio, 0.1, 1000);
	glOrtho(-1 *sight, 1 * 2 /sight, -1, 1, -1, 1);
}

void reshape(int w, int h) {
	aspRatio = float(w) / h;
	SetCamera();
	glViewport(0, 0, w, h);
}

void keyboard(unsigned char c, int, int) {
	/*if (c == 'w' && angle != 0) angle -= 30;
	if (c == 's' && angle != 180) angle += 30;*/
	if (c == 'w') sight += 2;
	if (c == 's') sight -= 2;
	SetCamera();
	glutPostRedisplay();
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

void drawTeapot(float size) {
	glutWireTeapot(size);
	glLineWidth(4);
	drawAxes(size);
	glLineWidth(1);
}

void display() {

	// world
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluLookAt(2, 2, 4, 0, 0, 0, 0, 1, 0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	//draw axes
	drawAxes(1.0);


	//draw sphere
	glColor3f(1, 0, 0);
	drawTeapot(0.5);

	static float angle = 0;
	angle += 0.5;

	glRotatef(angle, 0, 1, 0);
	glTranslatef(2, 0, 0);
	glPushMatrix();
	glRotatef(angle * 6, 1, 0, 0);
	drawTeapot(0.3);
	glPopMatrix();

	glRotatef(angle * 10, 0, 1, 0);
	glTranslatef(0.5, 0, 0);
	drawTeapot(0.2);


	glutSwapBuffers();

}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Xform");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);

	glutMainLoop();
	return 1;
}