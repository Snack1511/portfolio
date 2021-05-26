#include"AI.h"
#include "Ball.h"




void EnemyDraw() {
	glPushMatrix();
	glTranslatef(EnemyPos.Ex, EnemyPos.Ey, EnemyPos.Ez);
	glScalef(0.1, 0.1, 0.01);
	glutSolidCube(1.0);
	glPopMatrix();
}
void EnemyAI(float x, float y, float z) {
	x = ;
	y = EnemySpd.Ey;
	z = EnemySpd.Ez;
	EnemyPos.Ex += x;
	EnemyPos.Ey += y;
	EnemyPos.Ez += z;
}