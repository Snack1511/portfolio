#pragma once
#include "Include.h"

const int WINCX = 170-1;
const int WINCY = 60-1;

extern bool EXIT;

const int BULLETSIZE = 3;
const int MONSTERSIZE_S = 5;
const int PLAYERSIZE = 8;
const int MONSTERMAX = 5;
const int MAX = 30;
const int BLOCKMAX = 4;
const int END = 5;
const int gravity = 2;
const int JumpPower = 4;

const DWORD		STATE_RSTAND = 0x00000001;
const DWORD		STATE_LSTAND = 0x00000020;
const DWORD		STATE_WALK	= 0x00000002;
const DWORD		STATE_RATT	= 0x00000004;
const DWORD		STATE_LATT	= 0x00000040;
const DWORD		STATE_ATT	= 0x00000080;
const DWORD		STATE_HIT	= 0x00000008;
const DWORD		STATE_DIE	= 0x00000010;
const DWORD		STATE_LEFT	= 0x00000100;
const DWORD		STATE_RIGHT	= 0x00000200;

const DWORD		KEY_UP		= 0x00000001;
const DWORD		KEY_DOWN	= 0x00000002;
const DWORD		KEY_LEFT	= 0x00000004;
const DWORD		KEY_RIGHT	= 0x00000008;
const DWORD		KEY_SPACE	= 0x00000010;
const DWORD		KEY_RETURN	= 0x00000020;
const DWORD		KEY_LBUTTON = 0x00000040;
const DWORD		KEY_RBUTTON	= 0x00000080;
const DWORD		KEY_ESCAPE	= 0x00000100;
const DWORD		KEY_Z		= 0x00000200;
const DWORD		KEY_X		= 0x00000400;
const DWORD		KEY_C		= 0x00000800;

const unsigned long COLOR_BLACK			= 0x00000000; // 검정색
const unsigned long COLOR_BLUE			= 0x00000001; // 파랑색
const unsigned long COLOR_GREEN			= 0x00000002; // 초록색
const unsigned long COLOR_JADE			= 0x00000003; // 옥색
const unsigned long COLOR_RED			= 0x00000004; // 빨간색
const unsigned long COLOR_PURPLE		= 0x00000005; // 자주색
const unsigned long COLOR_YELLOW		= 0x00000006; // 노랑색
const unsigned long COLOR_WHITE			= 0x00000007; // 흰색
const unsigned long COLOR_GRAY			= 0x00000008; // 회색

const unsigned long COLOR_PASTEL_BLUE	= 0x00000009; // 연한 파랑색
const unsigned long COLOR_PASTEL_GREEN	= 0x0000000A; // 연한 초록색
const unsigned long COLOR_PASTEL_JADE	= 0x0000000B; // 연한 옥색
const unsigned long COLOR_PASTEL_RED	= 0x0000000C; // 연한 빨간색
const unsigned long COLOR_PASTEL_PURPLE	= 0x0000000D; // 연한 자주색
const unsigned long COLOR_PASTEL_YELLOW	= 0x0000000E; // 연한 노랑색
const unsigned long COLOR_REALWHITE		= 0x0000000F; // 밝은 흰색