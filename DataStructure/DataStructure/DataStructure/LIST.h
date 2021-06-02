#pragma once
#include "BaseInclude.h"
#include <list>
class LIST : public iStudy {
private:
	virtual void Description() {
		cout << endl;
		cout << "-- 리스트 --" << endl;
		cout << "더블링크드 리스트로 구현" << endl;
		cout << "더블링크드 리스트의 장점을 그대로 가져오며 중간에 삽입/삭제가 빠르다." << endl;
		cout << "특정 원소에 접근하려면 선형탐색이 필요" << endl;
		cout << "상호 포인터 정보를 가지고 있기 때문에 메모리 사용 비율이 높다." << endl;
		cout << "list클래스를 참조" << endl << endl;
		cout << "반복자" << endl;
		cout << " - begin() : beginning iterator를 반환" << endl;
		cout << " - end() : end iterator를 반환" << endl;
		cout << "추가 및 삭제" << endl;
		cout << " - push_front(element) : 리스트 제일 앞에 원소 추가" << endl;
		cout << " - pop_front() : 리스트 제일 앞에 원소 삭제" << endl;
		cout << " - push_back(element) : 리스트 제일 뒤에 원소추가" << endl;
		cout << " - pop_back() : 리스트 제일 뒤에 원소 삭제" << endl;
		cout << " - insert(iterator, element) : iterator가 가리키는 부분 앞에 원소를 추가" << endl;
		cout << " - erase(iterator) : iterator가 가리키는 부분에 원소를 삭제" << endl;
		cout << "조회" << endl;
		cout << " - *iterator : iterator가 가리키는 원소에 접근" << endl;
		cout << " - front() : 첫번째 원소를 반환" << endl;
		cout << " - back() : 마지막 원소를 반환" << endl;
		cout << "기타" << endl;
		cout << " - empty() : 리스트가 비어있으면 true 아니면 false반환" << endl;
		cout << " - size() : 리스트 원소들의 수를 반환" << endl;
		cout << endl;
	}
public:

	virtual void Main() {
		Description();
		list<int> l;
		cout << "push_back(element)" << endl;
		for (int i = 0; i < 15; i++) {
			l.push_back(i);
		}
		for(int num : l)
		{
			cout << num << " ";
		}
		cout << endl;
		cout << "pop_back()" << endl;
		l.pop_back();
		for (int num : l)
		{
			cout << num << " ";
		}
		cout << endl;
		cout << "pop_front()" << endl;
		l.pop_front();
		for (int num : l)
		{
			cout << num << " ";
		}
		cout << endl;
		cout << "list front value : " << l.front() << endl;
		cout << "list back value : " << l.back() << endl;
		cout << "list size : " << l.size() << endl;
		cout << "list empty : " << (l.empty()? "True" : "False") << endl;
		cout << "iterator" << endl;
		list<int>::iterator it_begin = l.begin();
		auto it_begin_auto = l.begin();
		auto it_end_auto = l.end();
		cout << "erase(iterator)" << endl;
		--it_end_auto;
		--it_end_auto;
		cout << "before erase : "<< *(it_end_auto) << endl;
		l.erase(it_end_auto);
		it_end_auto = l.end();
		--it_end_auto;
		cout << "after erase : "<< *(--it_end_auto) << endl;
		cout << "*erase시 해당 이터레이터 사용불가 -> 새로운 이터레이터를 할당해줘야함" << endl;
		cout << "Insert(iterator, element)" << endl;
		it_begin++;
		l.insert(it_begin, 102);
		for (int num : l)
		{
			cout << num << " ";
		}
		cout << endl;
		cout << "*iterator : 원소 접근" << endl;
		cout << "List " << distance(l.begin(), it_begin_auto) + 1 << "element : " << *++it_begin_auto << endl;

		
	}
};