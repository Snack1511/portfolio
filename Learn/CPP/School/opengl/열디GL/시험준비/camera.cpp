#include "Camera.h"

void setCameraLens(float angle, float asp) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(angle, asp, 0.1, 100);
}

void setCameraPosition(float x, float y, float z) {
	gluLookAt(x, y, z, 0, 0, 0, 0, 1, 0);
}