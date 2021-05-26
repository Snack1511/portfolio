#include<iostream>
//#define SQUARE(x) (x*x)//간단한 함수의 경우 전처리기가 좀더 빠르다
//inline int SQUARE(int x){
//
//	return x*x;
//}//복잡하게 사용가능하지만 매개변수에 따라 제어가 힘들다
using namespace std;
//
//
////namespace workspace {
////
////	void Add(){
////
////		cout << "ADD"<<endl;
////	}
////	void Sub(){
////
////		cout << "Sub"<<endl;
////	}
////}
//
//
////using namespace workspace;
//
//int main()
//{
//	cout << SQUARE(3) << endl;
//	/*char name[10];
//	int age;
//	Add();
//	Sub();*/
//
//	/*cin >> name >> age;
//	cout << "제 이름은 " << name << "제 나이는" << age << endl;*/
//
//	return 0;
//
//}

//void GameClass(int a)
//{
//	cout << "GameClass : "<< a << endl;
//}
//
//void GameClass(int a, int b)
//{
//	cout << "GameClass : "<< a << "와 "<< b << "입니다"<<endl;
//}
//
//int main()
//{
//	GameClass(1);
//	GameClass(2, 3);
//	return 0;
//}//함수의 오버로딩



//void GameClass(int a = 5, int b = 6)
//{
//	cout << "GameClass : "<< a << "와 "<< b << "입니다"<<endl;
//}
//
//int main()
//{
//
//	GameClass();
//	return 0;
//}//Default 매개변수





/*struct GameClass
{

	int id;
	char *name;
	float point;
	void show();
	void SetInfo(int _id, char* _na, float _point);

	
};

void GameClass:: show(){

	cout << "id : " << id << endl 
		<< "name : " << name << endl 
		<< "point : " << point << endl;
}//struct ex1
void GameClass:: SetInfo(int _id, char* _name, float _point){

	id = _id;
	name = _name;
	point = _point;

}*/

//class GameClass
//{
//public : int id;
//		char *name;
//		float point;
//public :void show();
//		void SetInfo(int _id, char* _na, float _point);
//};
//
//void GameClass:: show(){
//
//	cout << "id : " << id << endl 
//		<< "name : " << name << endl 
//		<< "point : " << point << endl;
//}//struct ex1
//void GameClass:: SetInfo(int _id, char* _name, float _point){
//
//	id = _id;
//	name = _name;
//	point = _point;
//
//}
//
////struct GameClass
////{
////
////	int id;
////	char *name;
////	float point;
////	void show(){
////
////		cout << "id : " << id << endl 
////			<< "name : " << name << endl 
////			<< "point : " << point << endl;
////	}
////
////
////};//struct ex2
//
///*class GameClass
//{
//public : int id;
//		 char *name;
//		 float point;
//
//};*/
//
////struct와 class차이 : 기본 접근자 차이
//int main(){
//
//	GameClass gameClass;
//	gameClass.SetInfo(1, "머안리", 99.9);
//	/*cout << "id : " << gameClass.id << endl 
//		<< "name : " << gameClass.name << endl 
//		<< "point : " << gameClass.point << endl;*/
//
//	gameClass.show();
//	
//	cout << gameClass.id << endl;
//	return 0;
//}//class 

class GameProgramClass{

public : GameProgramClass();
		 GameProgramClass(int);
		 GameProgramClass(int, int);

		 ~GameProgramClass();

};
GameProgramClass::GameProgramClass()
{
	cout << "생성자 입니다" << endl;
}

GameProgramClass::GameProgramClass(int a)
{
	cout << a <<"생성자 입니다" << endl;
}

GameProgramClass::GameProgramClass(int a, int b)
{
	cout << a <<"와 "<< b <<"생성자 입니다" << endl;
}


GameProgramClass::~GameProgramClass()
{
	cout << "소멸자 입니다" << endl;
}

int main(){

	GameProgramClass gameClass1;
	cout<<"-----------------------------------------------"<<endl;
	GameProgramClass gameClass2(1);
	cout<<"-----------------------------------------------"<<endl;
	GameProgramClass gameClass3(2, 3);
	cout<<"-----------------------------------------------"<<endl;
	GameProgramClass *test = new GameProgramClass(11);
	delete test;
	return 0;
}//생성자 소멸자 오버로딩
