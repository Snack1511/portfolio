#include <Windows.h>
#include <gl/GL.h>
#include <gl/glut.h>
#include <math.h>

float aspratio = 1.0, sightangle = 60;
float dx = 0.0, dz = 0.0, ArmAngle = 0.0;
float cx = -5, cy = 3, cz = 0;
float angle_W = 0, LeftRight = 0.0, UpDown = 0.0;
int flag = 1;
//static float angle;


void SetCamera() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(sightangle, aspratio, 0.1, 1000);
}//카메라 조정

void reshape(int w, int h) {
	aspratio = float(w) / h;
	SetCamera();
	glViewport(0, 0, w, h);
}

void Keyboard(unsigned char c, int, int) {
	if (c == 'w') { angle_W -= 10; dz -= 1; }
	if (c == 's') { angle_W += 10; dz += 1; }
	if (c == 'd') { LeftRight -= 10; }
	if (c == 'a') { LeftRight += 10; }
	if (c == 'i') { UpDown += 10; }
	if (c == 'k') { UpDown -= 10; }
	if (c == '1') { flag = 1 - flag; }
}

void drawCircle(float r, float ratio, float dx, float dz) {

	float angle = 0.0, double_PI = 3.14*2.0;
	float anglestep = double_PI / ratio;

	glBegin(GL_POLYGON);

	glPointSize(8);

	for (int i = 0; i < ratio; i++) {
		glColor3f(1, 0, 0);
		glVertex3f(r*cos(angle) + dx, r*sin(angle), dz);
		angle += anglestep;
	}
	glEnd();
}//원그리기

void DrawBox(float size, float cr, float cg, float cb) {

	glLineWidth(1);
	glColor3f(1, 1, 1);
	glutWireCube(size);
	glColor3f(cr, cg, cb);
	glutSolidCube(size - 0.2);

}//박스 그리기

void camerachange(int flag) {
	if (flag == 0) { glOrtho(5, -5, 0, 5, -1-dz, 5-dz); }
	if (flag == 1) { gluLookAt(5, 5, 5 + dz, 0, 0, dz, 0, 1, 0); }

}

void drawtank(float angle, float leftright, float updown) {
	glTranslatef(dx, 1, dz);
	glPushMatrix();
	glScalef(2, 1, 2);
	DrawBox(1, 0.1, 1, 0);
	glPopMatrix();
	glRotatef(90, 0, 1, 0);//몸
	
	glPushMatrix();
	glTranslatef(1, -0.5, 1);
	glRotatef(angle, 0, 0, 1);
	drawCircle(0.5, 5, 0, 0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1, -0.5, 1);
	glRotatef(angle, 0, 0, 1);
	drawCircle(0.5, 5, 0, 0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, -0.5, -1);
	glRotatef(angle, 0, 0, 1);
	drawCircle(0.5, 5, 0, 0);
	glPopMatrix();

	
	glPushMatrix();
	glTranslatef(-1, -0.5, -1);
	glRotatef(angle, 0, 0, 1);
	drawCircle(0.5, 5, 0, 0);
	glPopMatrix();//바퀴

	glPushMatrix();
	glRotatef(leftright, 0, 1, 0);
	glPushMatrix();
	glTranslatef(0, 0.5, 0);
	glScalef(3, 0.5, 3);
	DrawBox(0.5, 0, 1, 0);
	glPopMatrix();//포함
	glPushMatrix();
	glRotatef(updown, 0, 0, 1);
	glTranslatef(1, 0.5, 0);
	glScalef(5, 0.5, 0.5);
	DrawBox(0.5, 1, 0, 0);
	glPopMatrix();
	glPopMatrix();
}

void plan(int x, int z) {
	glBegin(GL_LINES);
	glColor3f(0.5, 0.5, 0.5);
	glLineWidth(1);
	for (int i = 0; i < x; i++) {
		glVertex3f(x, 0, i);
		glVertex3f(-x, 0, i);
		glVertex3f(x, 0, -i);
		glVertex3f(-x, 0, -i);
	}
	for (int j = 0; j < z; j++) {
		glVertex3f(j, 0, z);
		glVertex3f(j, 0, -z);
		glVertex3f(-j, 0, z);
		glVertex3f(-j, 0, -z);
	}
	glEnd();
}

void display() {
	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_DEPTH_TEST);

	glLoadIdentity();

	//gluLookAt(-2 + cx + dx, cy, cz + dz, dx, 1, dz, 0, 1, 0);
	camerachange(flag);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	plan(100, 100);

	
	drawtank(angle_W, LeftRight, UpDown);


	glutSwapBuffers();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("최민9제");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(Keyboard);


	glClearColor(0, 0, 0, 1);


	glutMainLoop();
	return 1;
}