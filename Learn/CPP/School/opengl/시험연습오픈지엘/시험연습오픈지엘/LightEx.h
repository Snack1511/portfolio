#ifndef _lighttest_ymkang_20161104
#define _lighttest_ymkang_20161104

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>

void SetSpot(bool flag, float cutoff_angle);
void SetMaterial(float r, float g, float b);
void SetLight(float r, float g, float b);
void SetLightPosition(float pos[]);

#endif
