#include<iostream>
#include<windows.h>
#include"stack.h"
using namespace std;
int elementNum = 0;
stack<float> kStack;
void main() 
{
	
	cout << "123.4를 넣어주세요" << endl;

	int num = 123;

	kStack.Push(num);
	kStack.Push(567.8f);
	kStack.Push(910.11f);

	int count = kStack.Count();

	for (int i = 0; i < count; ++i) 
	{
		cout << "현재 들어가 있는 데이터는 : " << kStack.Pop() << endl;
	}

	while (true) 
	{
		
	}
}

void enterbullet(int index)
{
	switch (index) 
	{
	case 1:
		kStack.Push(1);
		break;
	case 2:
		kStack.Push(2);
		break;
	case 3:
		kStack.Push(3);
		break;
	case 4:
		kStack.Push(4);
		break;
	}
}

