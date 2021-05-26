#include <Windows.h>
#include <gl/glew.h>
#include <gl/GL.h>
#include <gl/glut.h>
#include <math.h>
#include <stdio.h>
#include "STBImage.h"
#include "mesh.h"


CMesh mesh1, mesh2;

GLuint tex[2];
unsigned char *myTex = NULL;
int texWidth, texHeight, bitPerPixel;


void PrepareTextures(void) {
	glGenTextures(2, tex);
	if (myTex) delete[] myTex;
	glBindTexture(GL_TEXTURE_2D, tex[0]);
	myTex = stbi_load("metal.jpg", &texWidth, &texHeight, &bitPerPixel, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texWidth, texHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, myTex);
	delete[] myTex;
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D, tex[1]);
	myTex = stbi_load("flower.jpg", &texWidth, &texHeight, &bitPerPixel, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texWidth, texHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, myTex);
	delete[] myTex;
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	myTex = NULL;
	glEnable(GL_TEXTURE_2D);
}


float aspRatio = 1.0;

//light parameters
GLfloat lit_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat lit_position[] = { 0, -1, 0, 1 };
// material parameters
GLfloat mat_diffuse[] = { 1.0, 1.0, 0.5, 1.0 };
float armY = 0, armZ = 0, handZ = 0;
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
	case 'y': armY += 1.0; break;
	case 'Y': armY -= 1.0; break;
	case 'z': armZ += 1.0; break;
	case 'Z': armZ -= 1.0; break;
	case 'h': handZ += 1.0; break;
	case 'H': handZ -= 1.0; break;
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

void DrawBox(float size, float cr, float cg, float cb) {

	glLineWidth(1);
	glColor3f(1, 1, 1);
	glutWireCube(size);
	glColor3f(cr, cg, cb);
	glutSolidCube(size - 0.2);

}//박스 그리기

void drawBox(float xsize, float ysize, float zsize) {
	glPushMatrix();
	glScalef(xsize, ysize, zsize);
	glutSolidCube(1.0);
	glPopMatrix();
	drawAxes(1.0);
}

void display() {
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	gluLookAt(30.0, 10, 30.0, 0, 10, 0, 0, 1, 0);

	static float angle = 0;
	lit_position[0] += cos(angle);
	lit_position[2] += sin(angle);
	angle += 0.01;

	SetLightPosition();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	
	
	glLineWidth(1);
	//draw axes
	drawAxes(1.0);

	glEnable(GL_LIGHTING);
	glPushMatrix();
	glColor3f(1, 0, 1);
	glTranslatef(0, 0.25, 0);
	drawBox(3, 0.5, 3);

	glColor3f(1, 1, 0);
	glTranslatef(0, 1.25, 0);
	glRotatef(armY, 0, 1, 0);
	drawBox(0.2, 2.0, 0.2);

	glColor3f(1, 1, 1);
	glTranslatef(0, 1.0, 0);
	glRotatef(armZ, 0, 0, 1);
	glTranslatef(0, 0.75, 0);
	drawBox(0.1, 1.5, 0.1);
	glPushMatrix();
	glScalef(5, 0.01, 5);
	DrawBox(1, 1, 1, 1);
	



	/*glPushMatrix();
	glTranslatef(0, 0.75, 0);
	glRotatef(handZ, 0, 0, 1);
	glTranslatef(0, 0.25, 0);
	glColor3f(0, 1, 1);
	drawBox(0.1, 0.5, 0.1);
	glPopMatrix();*/

	
	glPopMatrix();
	glScalef(0.2, 0.2, 0.2);
	glPushMatrix();
	// draw mesh
	glColor3f(1, 1, 0);  

	mesh1.show();//female

	

	
	
	glColor3f(1, 1, 1);  
	mesh2.show();//cloth
	glPopMatrix();



	glutSwapBuffers();

}


void init(void) {
	glClearColor(0, 0, 0, 1);
	PrepareTextures();
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