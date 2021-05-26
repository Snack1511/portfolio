#include<iostream>

using namespace std;


//class Student
//{
//	private: int x;
//			 int y;
//
//	public :
//		Student();//생성자
//		int GetX();
//		int GetY();
//		void SetXY();
//		bool CompareXY();
//
//		
//
//		~Student();//소멸자
//};
//
//Student::Student()
//{
//	cout << "학생 객체 생성자"<<endl;
//	x = 0;
//	y = 0;
//}
//
//Student::~Student()
//{
//	cout << "학생 객체 소멸자" << endl;
//}
//void Student::SetXY()
//{
//	cout << "학생의 좌표값" <<endl;
//	cout << "x";
//	cin >> x;
//	cout << "y";
//	cin >> y;
//}
//
//bool Student::CompareXY()
//{
//	if(x < 0 || y < 0)
//	{
//		return false;
//	}
//	else
//	return true;
//}
//
//int Student::GetX()
//{
//	return x;
//}
//int Student::GetY()
//{
//	return y;
//}
//
//
//int main(){
//
//	Student S_1;
//	S_1.SetXY();
//	
//	if(S_1.CompareXY() == true){
//		cout << S_1.GetX() <<", "<< S_1.GetY() << endl;
//	}
//	if(S_1.CompareXY() == false){
//		cout << "음수ㄴㄴ"<<endl;
//	}
//	
//
//	return 0;
//	
//}
//생성자 활용






//class Student
//{
//private: int x;
//		 int y;
//
//public :
//	Student();//생성자
//	int GetX();
//	int GetY();
//	void SetXY();
//	bool CompareXY();
//	void Swap(int &ref1, int &ref2);
//
//
//
//	~Student();//소멸자
//};
//
//Student::Student()
//{
//	cout << "학생 객체 생성자"<<endl;
//	x = 0;
//	y = 0;
//}
//
//Student::~Student()
//{
//	cout << "학생 객체 소멸자" << endl;
//}
//void Student::SetXY()
//{
//	cout << "학생의 좌표값" <<endl;
//	cout << "x";
//	cin >> x;
//	cout << "y";
//	cin >> y;
//}
//
//bool Student::CompareXY()
//{
//	if(x < 0 || y < 0)
//	{
//		return false;
//	}
//	else
//		return true;
//}
//
//void Student::Swap(int &ref1, int &ref2)
//{
//	int temp = ref1;
//	ref1 = ref2;
//	ref2 = temp;
//}
//
//
//int Student::GetX()
//{
//	return x;
//}
//int Student::GetY()
//{
//	return y;
//}
//
//
//int main(){
//
//	Student S_1;
//	S_1.SetXY();
//	int xValue = S_1.GetX();
//	int yValue = S_1.GetY();
//	if(S_1.CompareXY() == true){
//		S_1.Swap(xValue, yValue);
//		cout << S_1.GetX() <<", "<< S_1.GetY() << endl;
//		cout << xValue <<", "<< yValue << endl;
//	}
//	if(S_1.CompareXY() == false){
//		cout << "음수ㄴㄴ"<<endl;
//	}
//
//
//	return 0;
//
//}

//레퍼런스(참조연산자..?)


class Vector2
{
private:
	int x;
	int y;

public:
	Vector2(const int &xNum, const int &yNum)
	{
		x = xNum;
		y = yNum;
	}
};

class SBSGameAcademy
{
private:
	Vector2 curretPosition;
	Vector2 targetPosition;
public:
	SBSGameAcademy(const int &x1, const int &y1, const int &x2, const int &y2) 
		: curretPosition(x1, y1), targetPosition(x2, y2)
	  {

	  
	  }
	
};