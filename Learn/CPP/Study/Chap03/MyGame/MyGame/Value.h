#pragma once
#include"Include.h"

const int WINCX = 140;
const int WINCY = 54;


const int MAX = 50;
const int END = 10;

const DWORD		STATE_STAND				= 0x00000001;
const DWORD		STATE_WALK				= 0x00000002;
const DWORD		STATE_ATT				= 0x00000004;
const DWORD		STATE_HIT				= 0x00000008;
const DWORD		STATE_DIE				= 0x00000010;

const DWORD		KEY_UP					= 0x00000001;
const DWORD		KEY_DOWN				= 0x00000002;
const DWORD		KEY_LEFT				= 0x00000004;
const DWORD		KEY_RIGHT				= 0x00000008;
const DWORD		KEY_SPACE				= 0x00000010;
const DWORD		KEY_RETURN				= 0x00000020;
const DWORD		KEY_ESCAPE				= 0x00000040;
const DWORD		KEY_Z					= 0x00000080;