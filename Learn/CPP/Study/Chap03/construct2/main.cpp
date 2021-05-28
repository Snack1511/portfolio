#include<iostream>

using namespace std;

class MyClass 
{
private:
	int num1;
	char* name;
public :
	MyClass(int n1, char* _name);
	MyClass(const MyClass &copy);
	~MyClass();
	void show() 
	{
		cout << "num1 : " << num1 << " / " << "name : " << name << endl;
	}


};

MyClass::MyClass(int n1, char* _name) : num1(n1)
{
	int len = strlen(_name) + 1;
	name = new char[len];
	strcpy_s(name, len, _name);
	cout << "생성자입니다." << endl;
}

MyClass::MyClass(const MyClass & copy) : num1(copy.num1)
{
	int len = strlen(copy.name) + 1;
	name = new char[len];
	strcpy_s(name, len, copy.name);
	cout << "복사생성자입니다." << endl;
}

MyClass::~MyClass()
{
	delete[] name;
	cout << "소멸자입니다." << endl;
}

void main() 
{
	MyClass myclass1(10, "Test");
	MyClass myclass2(myclass1);
	MyClass myclass3 = myclass2;

	myclass1.show();
	myclass2.show();
	myclass3.show();
}
