#include<iostream>
#include<math.h>
#include<windows.h>
using namespace std;

#define SQUARE(x) (x*x)//에러찾기 어려움, 가벼움
#define Add(x, y) (x+y)
#define Sub(x, y) (x+y)
#define Mult(x, y) (x+y)
#define Div(x, y) (x+y)
//namespace = 작업공간or작업환경

namespace A 
{
	void print()
	{
		cout << "네임 스페이스 A" << endl;
	}

}

namespace B
{
	void print()
	{
		cout << "네임 스페이스 B" << endl;
	}
	int i = 0;

}

void function(int a)
{
	cout << "function 은" << a << endl;
}
void function(int a, int b)
{
	cout << "function 은" << a << "와"<< b << endl;

}
void function(int a, int b, int defaultvalue = 5)
{
	cout << "function 은" << a << "와" << b << defaultvalue<< endl;
}




int main() 
{

	using namespace B;
	A::print();
	print();
	float in1, in2;
	char ccheck = NULL;
	/*while (true) 
	{
		switch (ccheck)
		{
		case NULL:
			cout << "1 = Add" << endl << "2 = Sub" << endl << "3 = Mult" << endl << "4 = Div" << endl << "5 = Square" << endl;
			cout << "input n1 :";
			cin >> in1;
			cout << "input opr :";
			cin >> ccheck;
			if (ccheck != '^'&& ccheck != 's' && ccheck != 'c' && ccheck != 't' )
			{
				cout << "input n2 :";
				cin >> in2;
			}
			break;
		case '+':
			cout << Add(in1, in2) << endl;
			ccheck = NULL;
			break;
		case '-':
			cout << Sub(in1, in2) << endl;
			ccheck = NULL;
			break;
		case '*':
			cout << Mult(in1, in2) << endl;
			ccheck = NULL;
			break;
		case '/':
			cout << Div(in1, in2) << endl;
			ccheck = NULL;
			break;
		case '^':
			cout << SQUARE(in1) << endl;
			ccheck = NULL;
			break;
		case 's':
			cout << sinf(in1*3.14 /180) << endl;
			ccheck = NULL;
			break;
		case 'c':
			cout << cosf(in1 * 3.14 /180) << endl;
			ccheck = NULL;
			break;
		case 't':
			cout << tanf(in1 * 3.14 /180) << endl;
			ccheck = NULL;
			break;
		default:
			cout << "nope" << endl;
			ccheck = NULL;
			break;

		}
	}*/

	function(1);
	function(1, 2);
	return 0;
}