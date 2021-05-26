#include <Windows.h>
#include <gl/glew.h>

#include <gl/GL.h>
#include <gl/glut.h>

#include <math.h>
#include "STBImage.h"

#define NTEXTURES 2


GLuint tex[NTEXTURES];
unsigned char *myTex = NULL;
int texWidth, texHeight, bitPerPixel;


void PrepareTextures(int n, GLuint *textures) {
	glGenTextures(n, tex);
}


void SetTexture(int idx, char *fname) {

	if (myTex) delete[] myTex;
	glBindTexture(GL_TEXTURE_2D, tex[idx]);
	myTex = stbi_load(fname, &texWidth, &texHeight, &bitPerPixel, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texWidth, texHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, myTex);
	delete[] myTex; myTex = NULL;
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glEnable(GL_TEXTURE_2D);
}

void drawQuad(void) {
	glBegin(GL_QUADS);
	glMultiTexCoord2f(GL_TEXTURE0, 0, 0);
	glMultiTexCoord2f(GL_TEXTURE1, 0, 0);
	glVertex3f(-1, 1, 0);
	glMultiTexCoord2f(GL_TEXTURE0, 0, 1);
	glMultiTexCoord2f(GL_TEXTURE1, 0, 2);
	glVertex3f(-1, -1, 0);
	glMultiTexCoord2f(GL_TEXTURE0, 1, 1);
	glMultiTexCoord2f(GL_TEXTURE1, 2, 2);
	glVertex3f(1, -1, 0);
	glMultiTexCoord2f(GL_TEXTURE0, 1, 0);
	glMultiTexCoord2f(GL_TEXTURE1, 2, 0);
	glVertex3f(1, 1, 0);
	glEnd();
}

void myDisplay() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1.0, 0.1, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 4, 0, 0, 0, 0, 1, 0);


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1, 1, 1);


	glActiveTexture(GL_TEXTURE0);
	glEnable(GL_TEXTURE_GEN_S); glEnable(GL_TEXTURE_GEN_T);
	glTexGenf(GL_S, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glTexGenf(GL_T, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);

	glActiveTexture(GL_TEXTURE1);
	glEnable(GL_TEXTURE_GEN_S); glEnable(GL_TEXTURE_GEN_T);
	glTexGenf(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glTexGenf(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);


	static float angle = 0.0;
	glRotatef(angle, 1, 1, 1); angle += 0.5;
	glutSolidTeapot(1.0);

	glutSwapBuffers();
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);

	PrepareTextures(NTEXTURES, tex);
	// stage 0
	glActiveTexture(GL_TEXTURE0);
	SetTexture(0, "metal.jpg");

	// stage 1
	glActiveTexture(GL_TEXTURE1);
	SetTexture(1, "spheremap.jpg");


	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(512, 512);
	glutCreateWindow("My Texture");

	glewInit();
	init();

	glutDisplayFunc(myDisplay);
	glutIdleFunc(myDisplay);

	glutMainLoop();

	return 0;
}