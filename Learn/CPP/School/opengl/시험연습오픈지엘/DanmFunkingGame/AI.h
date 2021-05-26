#pragma once
#ifndef _Cmj_ownmakeHeader20161213
#define _Cmj_ownmakeHeader20161213
#include"OpenGLHeaders.h"

struct EVector3f {
	float Ex;
	float Ey;
	float Ez;
};

EVector3f EnemyPos;
EVector3f EnemySpd;

void EnemySet(void) {
	EnemyPos.Ex = 0;
	EnemyPos.Ey = 0;
	EnemyPos.Ez = -0.5;
	EnemySpd.Ex = 0;
	EnemySpd.Ey = 0;
	EnemySpd.Ez = 0;
}
void EnemyDraw(void);
void EnemyAI(float x, float y, float z);

#endif

