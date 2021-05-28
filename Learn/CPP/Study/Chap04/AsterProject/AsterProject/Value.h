#pragma once
#include<Windows.h>

const int TILEMAX = 3;

const int TileSizeX = 6;
const int TileSizeY = 3;

const int TileCntX = 5;
const int TileCntY = 5;

const int WINCX = 120;
const int WINCY = 80;

const DWORD		STATE_STAND = 0x00000001;
const DWORD		STATE_WALK = 0x00000002;
const DWORD		STATE_ATT = 0x00000004;
const DWORD		STATE_HIT = 0x00000008;
const DWORD		STATE_DIE = 0x00000010;

const DWORD		KEY_UP = 0x00000001;
const DWORD		KEY_DOWN = 0x00000002;
const DWORD		KEY_LEFT = 0x00000004;
const DWORD		KEY_RIGHT = 0x00000008;
const DWORD		KEY_SPACE = 0x00000010;
const DWORD		KEY_RETURN = 0x00000020;
const DWORD		KEY_ESCAPE = 0x00000040;
const DWORD		KEY_Z = 0x00000080;
