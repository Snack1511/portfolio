#pragma once
typedef struct tagInfo
{
	int iX;
	int iY;
	int iCX;
	int iCY;

	tagInfo() {};
	tagInfo(int _ix, int _iy) : iX(_ix), iY(_iy) {};
	tagInfo(int _ix, int _iy, int _icx, int _icy)
		: iX(_ix), iY(_iy), iCX(_icx), iCY(_icy) {};


}INFO;