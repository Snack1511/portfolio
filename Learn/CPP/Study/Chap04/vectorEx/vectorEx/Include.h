#pragma once
#include <iostream>
#include <vector>
#include<stdlib.h>

using namespace std;

typedef struct UserInfo
{
	char* userName;
	int level;
	int exp;
}USER;

// 방에는 최대 6명까지 들어 갈 수있음
// 방에 들어 오는 순서 중 가장 먼저 들어 온 사람이 방장이 된다.

