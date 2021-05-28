#include<iostream>

#include<cstring>

using namespace std;

//class SBSGameAcademy
//{
//private:
//	static int num;//메모리 공간 할당
//	int nonstatic = 0;//
//
//
//public:
//
//	SBSGameAcademy();
//	SBSGameAcademy(const SBSGameAcademy & copy);
//	
//	int GetInfo() { return nonstatic; };
//	
//	static int GetNum() { return num; };
//	void SetInfo(int n);
//	~SBSGameAcademy();
//};
//
//int SBSGameAcademy::num = 0;//static 변수 초기화
//
//
//void SBSGameAcademy::SetInfo(int n) 
//{
//	num = n;
//	nonstatic = n;
//}
//SBSGameAcademy::SBSGameAcademy()
//{
//	num++;
//	cout << "생성자 호출" << num<< endl;
//}
//SBSGameAcademy::SBSGameAcademy(const SBSGameAcademy & copy)
//{
//	
//	cout << "복사 생성자 호출" << endl;
//}
//
//
//
//
//SBSGameAcademy::~SBSGameAcademy()
//{
//	num++;
//	cout << "소멸자 호출" << num << endl;
//}
//
//SBSGameAcademy GetSBSFunc(SBSGameAcademy obj)
//{
//	cout << "GetSBSFunc" << endl;
//	return obj;// 리턴시 복사 생성자 호출
//}
//
//int main()
//{
//	SBSGameAcademy sga1;
//	SBSGameAcademy sga2;
//	SBSGameAcademy sga3;
//	sga1.SetInfo(2);
//	sga2.SetInfo(1);
//	sga3.SetInfo(0);
//
//	cout << "Static : " << sga1.GetNum() << " NonStatic : " << sga1.GetInfo() << endl;
//	cout << "Static : " << sga2.GetNum() << " NonStatic : " << sga2.GetInfo() << endl;
//	cout << "Static : " << sga3.GetNum() << " NonStatic : " << sga3.GetInfo() << endl;
//	return 0;
//}

const int Max = 50;

int num;
int Array[Max];

int main() {
	for (int i = 0; i < Max; i++) 
	{
		Array[i] = i;
		cout << Array[i]+1 << endl;
	}
	return 0;
}