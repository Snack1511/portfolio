#pragma once
#ifndef _ball_mjchoiver20161103_asdf
#define _ball_mjchoiver20161103_asdf

struct Vector3f {
	float x;
	float y;
	float z;
};

void BallSet(float x, float y, float z, float vx, float vy, float vz);
void BallMove(void);
void BallDraw(void);

#endif _ball_mjchoiver20161103_asdf
