#include<iostream>
#include<vector>
#include<windows.h>
#include<time.h>
#include<conio.h>

using namespace std;
//열거형 정의
enum STATEID 
{
	FIRST,
	SECOND,
	THIRD,
};

//전역변수 선언
vector<int> m_veciNum(10); // vector의 공간을 10개 할당

DWORD m_dwKey;
STATEID SetStateID;

//함수 전방 선언부

void MainMenu(STATEID _stateID);
void Index();
void Function();
void CheckState();
void PUSH_BACK();

//main을 작성
void main() 
{
	time_t tCount = time(NULL);
	SetStateID = FIRST;

	while (true) 
	{
		if (tCount + 0.05 < time(NULL)) 
		{
			tCount = time(NULL);

			MainMenu(SetStateID);
			CheckState();
		}
	}
}

void MainMenu(STATEID _stateID) 
{
	switch (_stateID) 
	{
	case FIRST:
		Index();
		break;

	case SECOND:
		Function();
		break;

	case THIRD:
		PUSH_BACK();
		break;
	}
}

void Index() 
{
	system("cls");

	cout << "m_veciNum(10) = vector의 공간을 10개로 할당" << endl <<
		"vector에 새로운 공간을 미리 할당 할 수도 있고 그렇지 않을 수 도 있다." << endl << endl;

	//예약된 데이터 공간.
	cout << "[" << m_veciNum.capacity() << "]" << "capacity() = 예약된 데이터 공간" << endl;
	//현재 사용하고 있는 데이터 공간
	cout << "[" << m_veciNum.size() << "]" << "size() = 현재 사용하고 있는 데이터 공간" << endl;
	//현재 사용하고 있는 데이터 공간
	cout << "size()가 10인 이유는 vector를 생성할 때" << endl <<
		"미리 할당한 공간이 '0'으로 초기화 되었기 때문" << endl << endl;

	m_veciNum.clear();
	//vector에 있는 모든 원소를 지운다.
	cout << "m_veciNum.clear() = vector에 있는 모든 원소를 지운다" << endl << endl;

	m_veciNum.reserve(5);
	cout << "m_veciNum.reverse(5) = vector에 5개의 공간을 예약" << endl << endl;

	cout << "[" << m_veciNum.capacity() << "]" << "capacity() = 한번 늘어난 vector의 크기는 줄어 들지 않는다." << endl;
	cout << "[" << m_veciNum.size() << "]" << "size() = 하지만 원소의 갯수는 줄어들었다." << endl << endl;

	m_veciNum.push_back(10);
	cout << "Push_back(10)"<<" = 첫번째 원소 추가" << endl;
	m_veciNum.push_back(20);
	cout << "Push_back(20)" << " = 두번째 원소 추가" << endl;
	m_veciNum.push_back(30);
	cout << "Push_back(30)" << " = 세번째 원소 추가" << endl << endl;

	cout << "[" << m_veciNum.capacity() << "]" << "capacity() = 이미 늘어난 vector의 크기는 변함이 없으며, " << endl;
	cout << "[" << m_veciNum.size() << "]" << "size() = 원소의 갯수는 추가한 만큼 늘어났다." << endl;

	m_veciNum.clear();
	cout << "m_veciNum.clear() = vector에 있는 모든 원소를 지운다." << endl << endl;
}
void Function() 
{
	system("cls");

	cout << "m_veciNum.begin()	= 첫번째 원소를 가르키는 반복자 " << endl;
	cout << "m_veciNum.end()		= 마지막 (원소 아님) 을 가르키는 반복자 " << endl;
	cout << "m_veciNum.capacity()	= vector의 크기 (할당된 공간의 크기) " << endl;
	cout << "m_veciNum.size()	= vector의 원소 갯수 " << endl;
	cout << "m_veciNum.at( i )	= Index 로 접근 가능 [직접 접근가능] " << endl;
	cout << "m_veciNum.front()	= 첫번째 원소를 참조 " << endl;
	cout << "m_veciNum.back()	= 마지막 원소를 참조 " << endl;
	cout << "m_veciNum.clear()	= vector의 정보를 전체 삭제 " << endl;
	cout << "m_veciNum.insert(p,x)   = p가 가리키는 위치에 x 를 삽입 " << endl;
	cout << "m_veciNum.erase( p )	= p가 가리키는 원소를 삭제 " << endl;
	cout << "m_veciNum.max_size()	= vector의 최대 저장 가능한 원소의 갯수 " << endl;
	cout << "m_veciNum.rbegin()	= vector의 역순의 첫번째 원소를 가리키는 반복자" << endl;
	cout << "m_veciNum.rend()	= vector의 역순의 마지막을 가리키는 반복자" << endl;
	cout << "m_veciNum.pop_back()	= 마지막 원소를 삭제 " << endl;
	cout << "m_veciNum.push_back(x)	= 마지막에 x 를 추가한다. " << endl;
	cout << "m_veciNum.reserve( n )	= n 만큼의 크기를 재할당 한다. " << endl;
	cout << "m_veciNum.resize( n )	= n 만큼의 사이즈를 재할당 하고" <<
		"추가되는 공간에는 '0' 으로 초기화 됨. " << endl;
	cout << "m_veciNum.resize( n, x )= n 만큼의 사이즈를 재할당 하고" <<
		" 추가되는 공간에는 'x' 로 초기화 됨. " << endl;
	cout << "m_veciNum.swap()	= 2개의 vector 을  swap 함." << endl;


}
void CheckState() 
{
	int getKey = getch();

	switch (getKey) 
	{
	case 'a':
		SetStateID = FIRST;
		break;

	case 's':
		SetStateID = SECOND;
		break;

	case 'd':
		SetStateID = THIRD;
		break;

	}
}
void PUSH_BACK() 
{
	system("cls");

	m_veciNum.push_back(10);
	m_veciNum.push_back(20);
	m_veciNum.push_back(30);
	m_veciNum.push_back(40);
	m_veciNum.push_back(50);
	m_veciNum.push_back(60);
	m_veciNum.push_back(70);
	m_veciNum.push_back(80);
	m_veciNum.push_back(90);
	m_veciNum.push_back(100);
	cout <<
		"m_veciNum.push_back() = vector에 10 부터 100 까지 10개의원소를 추가"
		<< endl << endl;

	for (vector<int>::iterator iter = m_veciNum.begin(); iter != m_veciNum.end(); ++iter)
	{
		cout << (*iter) << endl;
	}
	cout << "vector<int>::iterator 를 사용한 출력." << endl << endl;
	cout << "begin() = 첫번째 원소를 가르키는 반복자." << endl;
	cout << "end() = 끝을 가르키는 반복자." << endl << endl;

	cout << "frot() = 첫번째 원소를 참조." << endl;
	cout << "back() = 마지막 원소를 참조." << endl << endl;

	cout << "[ frot() & back() ] 은 [ begin() & end() ] 와는 전혀 다르다."
		<< endl << endl;

	for (vector<int>::size_type i = 0; i < m_veciNum.size(); i++)
	{
		cout << m_veciNum[i] << endl;
	}
	cout << "vector<int>::size_type 을 이용한 출력." << endl <<
		"vector[Index] 로 바로 접근 가능." << endl << endl;

	m_veciNum.resize(20, 10);



}
