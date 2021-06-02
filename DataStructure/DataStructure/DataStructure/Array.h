#pragma once
#include "BaseInclude.h"

class Array : public iStudy{
private :
	virtual void Description() {
		cout << endl;
		cout << "-- 배열 --" << endl;
		cout << "배열이란?\n여러 데이터를 하나의 이름으로 그룹핑해서 관리하기 위한 데이터 스트럭쳐\n";
		cout << "Array : value + index = element\n";
		cout << "배열의 장점 : 그룹핑된 데이터들을 한번에 관리하기 편하다"<<endl;
		cout << "배열의 단점 \n - 크기가 정해져있다\n - 기능이없다";
		cout << endl;
	}
public :
	
	virtual void Main() {
		Description();
		int iarr1[4] = {0, };
		int iarr2[4];
		int iarr3[4];
		cout << "iarr1[4] = {0, } -> iarr1[2] : " << iarr1[2]<<endl;
		iarr2[0] = 2;
		cout << "iarr2[0] = 2 -> iarr2[0] : " << iarr2[0] << endl;
		cout << "for문을 이용한 초기화"<<endl;
		for (int i = 0; i < 4; i++) {
			iarr3[i] = i;
			cout << "  iarr3[" << i << "] : " << iarr3[i] << endl;
		}
		cout << endl;
	}
};