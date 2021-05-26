#include <Windows.h>
#include <gl/GL.h>
#include <gl/glut.h>
#include <math.h>
#include "STBImage.h"

unsigned char *myTex;
int texWidth, texHeight, bitPerPixel;

void CreateTexture(void) {
	
	myTex = stbi_load("081115_2026_2.jpg", &texWidth, &texHeight, &bitPerPixel, 0);
	
}

void SetupTexture(void) {
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texWidth, texHeight, 0,
		GL_RGB, GL_UNSIGNED_BYTE, myTex);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glEnable(GL_TEXTURE_2D);
}

void myDisplay() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); 
	gluPerspective(60, 1.0, 0.1, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2, 2, 2, 0, 0, 0, 0, 1, 0);


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1, 1, 1);

	//glEnable(GL_TEXTURE_GEN_S);
	//glEnable(GL_TEXTURE_GEN_T);
	//glTexGenf(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);//GL_OBJECT_LINEAR, GL_SPHERE_MAP, GL_EYE_LINEAR
	//glTexGenf(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);//
	//
	//static float angle = 0.0;
	//glRotatef(angle, 0, 1, 1);
	//angle += 0.1;
	//glutSolidTeapot(1.0);

	//아래부터는 작년코드
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	static float angle = 0.0;
	glPushMatrix();
	glRotatef(angle, 1, 1, 1);
	glTexGenf(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glTexGenf(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glutSolidTeapot(0.5);
	glTranslatef(1.5, 0, 0);
	glTexGenf(GL_S, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glTexGenf(GL_T, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glutSolidTeapot(0.5);
	glTranslatef(-3, 0, 0);
	glTexGenf(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenf(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glutSolidTeapot(0.5);
	glPopMatrix();
	angle += 0.5;
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	//
	glutSwapBuffers();
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	CreateTexture();
	SetupTexture();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(512, 512);
	glutCreateWindow("My Texture");

	init();

	glutDisplayFunc(myDisplay);
	glutIdleFunc(myDisplay);

	glutMainLoop();

	return 0;
}