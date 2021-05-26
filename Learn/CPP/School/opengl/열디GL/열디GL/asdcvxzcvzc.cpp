#include <Windows.h>
#include <gl/GL.h>
#include <gl/glut.h>
#include <math.h>


float aspratio = 1.0, sightangle = 60;
float dx = 0.0, dz = 0.0, ArmAngle = 0.0;
float cx = -5, cy = 3, cz = 0;
//float cx = 10, cy = 10, cz = 10;
float angle_P = 0;
static float angle;

void Keyboard(unsigned char c, int, int) {
	if (c == 'w') { dx += 0.5; angle_P = 0; }
	if (c == 's') { dx -= 0.5; angle_P = 180; }
	if (c == 'd') { dz += 0.5; angle_P = 270; }
	if (c == 'a') { dz -= 0.5; angle_P = 90; }
	if (c == 'i') { ArmAngle += 10; }
	if (c == 'k') { ArmAngle -= 10; }
	if (c == '1') { cx = 10; cy = 10; cz = 10; }
	if (c == '2') { cx = -5; cy = 3; cz = 0; }
	if (c == ',') { angle += 1; }
	if (c == '.') { angle -= 1; }
	//if (c == '2') { cx = 5; cy = 5; cz = 5; }
}

void SetCamera() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(sightangle, aspratio, 0.1, 1000);
}//카메라 조정

void getOrtho(int w, int h) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float asp = float(w) / h;
	glOrtho(-2 * asp, 2 * asp, -2, 2, -2, 2);
	glViewport(0, 0, w, h);
}

void reshape(int w, int h) {
	aspratio = float(w) / h;
	SetCamera();
	glViewport(0, 0, w, h);
}//종횡비 유지

void drawaxix(int Length) {
	glBegin(GL_LINES);
	
	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(Length, 0, 0);

	glColor3f(0, 1, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, Length, 0);

	glColor3f(0, 0, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, Length);
	glEnd();
}
//좌표 그리기
void drawCircle(float r, float ratio, float dx, float dy) {

	float angle = 0.0, double_PI = 3.14*2.0;
	float anglestep = double_PI / ratio;

	glBegin(GL_POLYGON);

	glPointSize(8);

	for (int i = 0; i < ratio; i++) {
		glColor3f(1, 0, 0);
		glVertex3f(r*cos(angle) + dx, r*sin(angle) + dy, 0);
		angle += anglestep;
	}
	glEnd();
}//원그리기

void drawsphere(int r) {
	glLineWidth(1);
	drawaxix(2);
	
	glColor3f(1, 1, 1);

	glutWireSphere(r, 30, 10);

	//glLineWidth(0.1);
}//구 그리기

void DrawBox(float size, float cr, float cg, float cb) {
	
	glLineWidth(1);
	glColor3f(1, 1, 1);
	glutWireCube(size);
	glColor3f(cr, cg, cb);
	glutSolidCube(size-0.2);

}//박스 그리기

void steve(float dx, float dz, float angle_P, float ArmAngle) {
	
	glTranslatef(dx, 0, 0+dz);
	glRotatef(angle_P, 0, 1, 0);
	glPushMatrix();
		glTranslatef(0.05, 0, 0.3);
		glScalef(0.7, 2, 0.3);
		DrawBox(1, 0, 0, 1);//오른쪽다리
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.05, 0, -0.3);
		glScalef(0.7, 2, 0.3);
		DrawBox(1, 0, 0, 1);//왼쪽다리
	glPopMatrix();
	glPushMatrix();//************************
		glTranslatef(0, 1.7, 0);
		glPushMatrix();//--------
			glScalef(1, 2, 1);
			DrawBox(1, 0, 1, 1);
		glPopMatrix();//몸--------
		glPushMatrix();//--------
			glTranslatef(0.25, 0.7, 0.75);
			glRotatef(ArmAngle, 0, 0, 1);
			glTranslatef(0, -0.7, 0);
			glScalef(0.5, 2, 0.5);
			DrawBox(1, 0, 1, 1);
		glPopMatrix();//왼쪽팔--------
		glPushMatrix();//--------
			glTranslatef(0.25, 0.7, -0.75);
			glRotatef(ArmAngle, 0, 0, 1);
			glTranslatef(0, -0.7, 0);
			glScalef(0.5, 2, 0.5);
			DrawBox(1, 0, 1, 1);
		glPopMatrix();//오른쪽팔--------
		glTranslatef(0.125, 1.25, 0);
		DrawBox(1, 0, 0, 0);//머리
	glPopMatrix();//*************************
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
	
	gluLookAt(-2+cx + dx, cy, cz+dz, dx, 1, dz, 0, 1, 0);
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	plan(100, 100);

	glLineWidth(2);
	drawaxix(4);

	
	

	steve(dx, dz, angle_P, ArmAngle);
	
	/*glPushMatrix();
	glRotatef(angle, 0, 0, 1);
	drawsphere(1);
	glPopMatrix();*/
	
	
	
	glutSwapBuffers();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE| GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("YesYes");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(Keyboard);


	glClearColor(0, 0, 0, 1);

	 
	glutMainLoop();
	return 1;
}