#include "myPannel.h"

float pannelX = 0;
float pannelY = 0;

float GetPannelX(void) { return pannelX; }
float GetPannelY(void) { return pannelY; }

void PannelMove(float dx, float dy) {
	pannelX += dx;
	pannelY += dy;

}

void PannelDraw(void) {
	
	glPushMatrix();
	glTranslatef(pannelX, pannelY, 1.0);
	glScalef(0.5, 0.5, 0.01);
	glutSolidSphere(0.5, 20, 20);
	glPopMatrix();
}