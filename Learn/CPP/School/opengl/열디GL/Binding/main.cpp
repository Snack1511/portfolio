#include <Windows.h>
#include<gl/glew.h>
#include <gl/GL.h>
#include <gl/glut.h>
#include <math.h>
#include<String.h>
#include "STBImage.h"


// void glGenTextures(int n, GLuint *textures)
// void glBindTexture(GLenum target /*GL_TEXTURE_2D*/, GLuint texture);
GLuint tex[3];
unsigned char *myTex;
int texWidth, texHeight, bitPerPixel;



GLuint PrepareTextures(const char *filename) {
	unsigned char *image;

	int width, height, bPerPix;
	image = stbi_load(filename, &width, &height, &bPerPix, 0);

	GLuint tex;
	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
		GL_UNSIGNED_BYTE, image);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glEnable(GL_TEXTURE_2D);

	return tex;
}


void drawQuad(void) {
	glBegin(GL_QUADS);
	glTexCoord2f(0, 1);
	glVertex3f(-1, 1, 0);
	glTexCoord2f(0, 0);
	glVertex3f(-1, -1, 0);
	glTexCoord2f(1, 0);
	glVertex3f(1, -1, 0);
	glTexCoord2f(1, 1);
	glVertex3f(1, 1, 0);
	glEnd();
}

void myDisplay() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1.0, 0.1, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 20, 0, 0, 0, 0, 1, 0);


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1, 1, 1);

	/*glBindTexture(GL_TEXTURE_2D, tex[1]);
	glPushMatrix();
	glTranslatef(-1.0, 0, 0);
	drawQuad();
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, tex[0]);
	glPushMatrix();
	glTranslatef(1.0, 0, 0);
	drawQuad();
	glPopMatrix();*/

	/*for (int i = 0; i < 10; i++) {
		int a = i %2;
		glBindTexture(GL_TEXTURE_2D, tex[a]);
		glPushMatrix();
		glTranslatef(1.0+2*i, 0, 0);
		drawQuad();
		glPopMatrix();
	}*/
	for (int i = 0; i < 10; i++) {
		glTranslatef(1.0, 0, 0);
		glBindTexture(GL_TEXTURE_2D, tex[i]);
		glTranslatef(1.0, 0, 0);
		drawQuad();
	}
	glutSwapBuffers();
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	tex[0] = PrepareTextures("spheremap.jpg");
	tex[1] = PrepareTextures("metal.jpg");
	tex[2] = PrepareTextures("a.jpg");
	tex[3] = PrepareTextures("spheremap.jpg");
	tex[4] = PrepareTextures("spheremap.jpg");
	tex[5] = PrepareTextures("spheremap.jpg");
	tex[6] = PrepareTextures("spheremap.jpg");
	tex[7] = PrepareTextures("spheremap.jpg");
	tex[8] = PrepareTextures("spheremap.jpg");
	tex[9] = PrepareTextures("spheremap.jpg");
	//PrepareTextures("spheremap.jpg", 2);

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