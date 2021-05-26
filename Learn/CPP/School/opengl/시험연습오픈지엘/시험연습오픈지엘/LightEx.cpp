#include "LightEx.h"

GLfloat Light_lightPos[] = { 1, 1, 1, 1 };

void SetMaterial(float r, float g, float b) {
	GLfloat diffuse[] = { r, g, b, 1.0 };
	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };

	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 100.0);
}

void SetLight(float r, float g, float b) {
	GLfloat diffuse[] = { r, g, b, 1.0 };
	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
}

void SetSpot(bool flag, float cutoff_angle) {
	if (!flag) glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 180);
	else {
		GLfloat direction[] = { -Light_lightPos[0], -Light_lightPos[1], -Light_lightPos[2] };
		glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, cutoff_angle);
		glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, direction);
	}

}

void SetLightPosition(float pos[]) {
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	for (int i = 0; i < 4; i++) Light_lightPos[i] = pos[i];
}