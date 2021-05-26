#include "OpenGLHeaders.h"
#include "CameraMgr.h"

// parameters for camera lens
float aspRatio = 1.0;

void SetCamera() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, aspRatio, 0.1, 1000);
}

void UpdateAspectRatio(float asp) {
	aspRatio = asp;
}