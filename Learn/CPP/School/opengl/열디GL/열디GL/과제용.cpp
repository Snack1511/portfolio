#include <Windows.h>
#include <gl/GL.h>
#include <gl/glut.h>
#include <math.h>

// parameters for camera lens

float aspRatio = 1.0;

void SetCamera() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-aspRatio * range + dX, aspRatio * range + dX, -range, range, -2, 2);
	gluPerspective(60, aspRatio, 0.1, 1000);
}

void reshape(int w, int h) {
	aspRatio = float(w) / h;
	SetCamera();
	glViewport(0, 0, w, h);
}

void keyboard(unsigned char c, int, int) {

	SetCamera();
	glutPostRedisplay();
}


void drawCircle(
	float radius, float dx, float dy, int nPoints = 100) {
	float angle = 0.0;
	float twopi = 3.14*2.0;
	float angleStep = twopi / nPoints;

	glBegin(GL_POLYGON);
	// vertices
	for (int i = 0; i < nPoints; i++) {
		glVertex3f(radius*cos(angle) + dx, radius*sin(angle) + dy, 0);
		angle += angleStep;
	}
	glEnd();
}

void drawAxes(float size) {
	//glLineWidth(10);
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
	drawAxes(size + 1);
}

void drawCube(double size) {
	glutWireCube(size);
	//drawAxes(size + 0.5);
}

void drawplanet(float size) {
	glutWireSphere(size, 30, 30);
	drawAxes(size + 1);
}

void AutoRotate(float angle, float m, float a) {
	glRotatef(angle*m, 0, 1, 0);
	glTranslatef(a, 0.0, 0.0);
	glRotatef(angle*m, 0, 1, 0);
}

void plat(float size) {
	//drawAxes(size);
	glBegin(GL_LINES);
	glColor3f(1, 0, 1);
	for (int i = 0; i < size; i++)
	{
		
		glVertex3f(i*0.5, 0, size); glVertex3f(i*0.5, 0, -size);
		glVertex3f(-i*0.5, 0, size); glVertex3f(-i*0.5, 0, -size);
		glVertex3f(size, 0, i*0.5); glVertex3f(-size, 0, i*0.5);
		glVertex3f(size, 0, -i*0.5); glVertex3f(-size, 0, -i*0.5);
	}
	glEnd();
}

void drawbox(float x, float y, float z) {
	glPushMatrix();
	glScalef(x, y, z);
	glutWireCube(1.0);
	glPopMatrix();
}

void display() {

	// world
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(6, 0, 0, 0, 0, 0, 0, 1, 0);


	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLineWidth(3);

	drawAxes(1.0);
	plat(20.0);
	/*glBegin(GL_LINES);

	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0); glVertex3f(1, 0, 0);

	glColor3f(0, 1, 0);
	glVertex3f(0, 0, 0); glVertex3f(0, 1, 0);

	glColor3f(0, 0, 1);
	glVertex3f(0, 0, 0); glVertex3f(0, 0, 1);

	glEnd();*/

	
	glColor3f(1, 0, 0);
	glTranslatef(0.0, 0.25, 0.0);
	drawbox(3.0, 0.5, 3.0);

	glColor3f(1, 1, 0);
	glTranslatef(0.0, 1.75, 0.0);
	drawbox(0.5, 3.0, 0.5);
	
	//drawplanet(1.0);
	
	//drawTeapot(0.7);

	/*glColor3f(0, 1, 0);
	glRotatef(90, 0, 0, 1);
	glTranslatef(0.0, -1.0, 0.0);//(1, 0, 0)으로 이동 => 기본 드로우 위치를 변경
	//glRotatef(90, 0, 0, 1);
	drawTeapot(0.5);

	glColor3f(0, 0, 1);
	glRotatef(90, 0, 0, 1);
	glTranslatef(0.0, -1.0, 0.0);//(1, 0, 0)으로 이동된 상태에서 다시 변경
	drawTeapot(0.5);*/
	/*
	static float angle = 0;
	angle += 0.5;
	glPushMatrix();
	glColor3f(0, 0, 1);
	AutoRotate(angle, 0.5, 1.5);
	drawplanet(0.2);
	glPopMatrix();
	*/
	/*
	glPushMatrix();
	glColor3f(1, 0, 1);
	glRotatef(angle*1.0, 0, 1, 0);
	glTranslatef(0.0, 0.0, 2.0);//떨어진 거리
	glRotatef(angle * 2, 0, 1.0, 0);
	drawTeapot(0.2);//지구
	glPushMatrix();
	glRotatef(angle*2.0, 0, 1, 0);
	glTranslatef(0.5, 0.0, 0.0);
	drawTeapot(0.1);//달
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 1, 1);
	glRotatef(angle*-2.0, 1, 1, 0);
	glTranslatef(0.0, 0.0, 1.5);//떨어진 거리
	glRotatef(angle * -20, 0, 1.0, 0);
	drawTeapot(0.2);//지구
	glPushMatrix();
	glRotatef(angle*10.0, 0, 1, 0);
	glTranslatef(0.5, 0.0, 0.0);
	glRotatef(angle*10.0, 0, 1, 0);
	drawTeapot(0.1);//달
	glPopMatrix();
	glPopMatrix();
	*/
	glutSwapBuffers();

}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1000, 500);
	glutCreateWindow("I Love Graphics");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glClearColor(0, 0, 0, 0);

	glutMainLoop();
	return 1;
}