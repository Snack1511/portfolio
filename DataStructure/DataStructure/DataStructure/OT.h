#pragma once
#include "BaseInclude.h"

class OT : public iStudy {
private:
	virtual void Description() {
		cout << endl;
		cout << "자료구조의 필요성" << endl;
		cout << "1. 데이터를 효과적으로 저장하고, 처리하는 방법에 대해서 바르게 이해할 필요가 있다." << endl;
		cout << "2. 자료구조를 제대로 이해하지 못하면 불필요하게 메모리와 성능을 낭비할 여지가 있다." << endl;
		cout << "기본적인 자료구조들"<< endl;
		cout << "1. 선형구조" << endl << " - 배열\n - 연결리스트\n - 스택\n - 큐\n - 데크"<<endl;
		cout << "2. 비선형구조 \n - 트리(Tree)\n - 그래프(Graph)" << endl;
		cout << "언어마다 지원하는 자료구조가 다르기때문에 한 언어를 공부할때마다 맞는 자료구조를 파악해야 한다." << endl;
		cout << endl;
	}
public:
	
	virtual void Main() {
		Description();
	}
};