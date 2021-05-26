#include "BasicHeader.h"
#include"Light.h"
#include"camera.h"


#define GRIDX 100
#define GRIDY 100
float heightMap[GRIDX][GRIDY];


void Cross(float *u, float *v, float *cross) {
	cross[0] = u[1] * v[2] - u[2] * v[1];
	cross[1] = u[2] * v[0] - u[0] * v[2];
	cross[2] = u[0] * v[1] - u[1] * v[0];
	float len = sqrt(cross[0] * cross[0] + cross[1] * cross[1] + cross[2] * cross[2]);
	if (len > 0) {
		cross[0] /= len;
		cross[1] /= len;
		cross[2] /= len;
	}
}//정규벡터 구하기



void GenerateHeightMap(int w, int h) {
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			heightMap[i][j] = (rand() % 10001) / 10000.0 - 0.5f;
		}
	}
}//지형생성

void ShowHeightMap(int w, int h) {
	float u[3], v[3], cross[3];

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < w - 1; i++) {
		for (int j = 0; j < h - 1; j++) {
			glPushMatrix();
			glTranslatef(-w/2, 0, -h/2);
			// FACE 1
			u[0] = 0; 
			u[1] = heightMap[i][j + 1] - heightMap[i][j]; 
			u[2] = 1;
			v[0] = 1;
			v[1] = heightMap[i+1][j + 1] - heightMap[i][j];
			v[2] = 0;
			Cross(u, v, cross);
			glNormal3fv(cross);
			glVertex3f(i, heightMap[i][j], j);
			glVertex3f(i, heightMap[i][j+1], j+1);
			glVertex3f(i+1, heightMap[i+1][j], j);
			// FACE 2
			u[0] = -1;
			u[1] = heightMap[i][j + 1] - heightMap[i+1][j];
			u[2] = 1;
			v[0] = 0;
			v[1] = heightMap[i+1][j + 1] - heightMap[i+1][j];
			v[2] = 1;
			Cross(u, v, cross);
			glVertex3f(i+1, heightMap[i + 1][j], j);
			glVertex3f(i, heightMap[i][j + 1], j + 1);
			glVertex3f(i+1, heightMap[i+1][j + 1], j + 1);
			glPopMatrix();
		}
	}
	glEnd();
	
}//지형그리기
bool bSpot = false;
bool bPers = true;
// parameters for camera lens
float aspRatio = 1.0;
GLfloat lightPos[] = { 0, 1, 0, 1 };
//light parameters
/*GLfloat lit_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat lit_specular[] = { 1.0, 0.0, 0.0, 1.0 };
GLfloat lit_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat lit_position0[] = { 5, 5, 0, 1 };
GLfloat lit_position1[] = { 5, 5, 0, 1 };


// material parameters
GLfloat mat_diffuse[] = { 0.0, 0.3, 0.3, 1.0 };
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_ambient[] = { 0.0, 0.03, 0.0, 1.0 };

void SetLighting(void) {
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glLightfv(GL_LIGHT0, GL_AMBIENT, lit_ambient);
	glLightfv(GL_LIGHT1, GL_AMBIENT, lit_ambient);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lit_diffuse);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lit_diffuse);


	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 90);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lit_specular);
	glLightfv(GL_LIGHT1, GL_SPECULAR, lit_specular);
}

void SetLightPosition(void) {
	glLightfv(GL_LIGHT0, GL_POSITION, lit_position0);
	glLightfv(GL_LIGHT1, GL_POSITION, lit_position1);
}*/


void SetCamera() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	bPers ? gluPerspective(60, aspRatio, 0.1, 1000) : glOrtho(-10, 10, -10, 10, -100, 100);
}

void reshape(int w, int h) {
	float asp = float(w) / h;
	setCameraLens(60, asp);
	glViewport(0, 0, w, h);
}

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


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	setCameraPosition(30, 30, 30);

	SetLightPosition(lightPos);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glLineWidth(1);
	//draw axes
	drawAxes(1.0);

	// draw plane
	//drawPlane(20, 0.5);

	glEnable(GL_LIGHTING);
	

	glPointSize(4);
	ShowHeightMap(GRIDX, GRIDY);

	glDisable(GL_LIGHTING);

	glutSwapBuffers();

}


void init(void) {
	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	SetMaterial(1.0, 1.0, 0.0);
	SetLight(1.0, 1.0, 1.0);

	GenerateHeightMap(GRIDX, GRIDY);
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