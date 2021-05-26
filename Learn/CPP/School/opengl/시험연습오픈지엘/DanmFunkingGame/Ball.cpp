#include "Ball.h"
#include "OpenGLHeaders.h"


Vector3f ballPosition;
Vector3f ballVelocity;

void BallSet(float x, float y, float z, float vx, float vy, float vz) {
	ballPosition.x = x;
	ballPosition.y = y;
	ballPosition.z = z;
	ballVelocity.x = vx;
	ballVelocity.y = vy;
	ballVelocity.z = vz;
}

void BallMove(void) {
	// v = dx/dt;
	// dx = v*dt;
	// dx = ������ġ - ������ġ
	ballPosition.x = ballPosition.x + ballVelocity.x * 0.01;
	ballPosition.y = ballPosition.y + ballVelocity.y * 0.01;
	ballPosition.z = ballPosition.z + ballVelocity.z * 0.01;

}

void BallDraw(void) {
	glPushMatrix();
	glTranslatef(ballPosition.x, ballPosition.y, ballPosition.z);
	glutSolidSphere(0.1, 30, 30);
	glPopMatrix();

}