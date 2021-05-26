#pragma once
#ifndef _camera_ymkang_h_
#define _camera_ymkang_h_
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>

void setCameraLens(float angle, float asp);

void setCameraPosition(float x, float y, float z);

#endif