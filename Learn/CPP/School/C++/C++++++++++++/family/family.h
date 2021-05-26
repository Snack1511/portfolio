#pragma once
#include "person.h"
class family {
	string name;
	person* p; // Person 배열 포인터
	int size; // Person 배열의 크기. 가족 구성원 수
public:
	family(string name, int size); // size 개수만큼 Person 배열 동적 생성
	void setName(int index, string name);
	void show(); // 모든 가족 구성원 출력
	~family();
};