#pragma once
#ifndef _BALL_YMKANG20161103_HH
#define _BALL_YMKANG20161103_HH

struct Vector3f {
	float x;
	float y;
	float z;
};

void BallSet(float x, float y, float z, float vx, float vy, float vz);
void BallMove(void);
void BallDraw(void);


#endif