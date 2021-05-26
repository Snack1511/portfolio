#include "LightMgr.h"

//light parameters
GLfloat lit_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat lit_specular[] = { 1.0, 0.0, 0.0, 1.0 };
GLfloat lit_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat lit_position[] = { 5, 5, 0, 1 };


// material parameters
GLfloat mat_diffuse[] = { 0.0, 0.3, 0.3, 1.0 };
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_ambient[] = { 0.0, 0.03, 0.0, 1.0 };


void SetLighting(void) {
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glLightfv(GL_LIGHT0, GL_AMBIENT, lit_ambient);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lit_diffuse);


	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 90);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lit_specular);
}

void SetLightPosition(void) {
	glLightfv(GL_LIGHT0, GL_POSITION, lit_position);
}