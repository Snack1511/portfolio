#include"MyIntStack.h"

int main() {
	MyIntStack a(5);
	int value;
	for (int i = 0; i < 5; i++)
	{
		cout << "스택에 넣을 값 입력:";
		cin >> value;
		if (!a.push(value)) cout << "스택 full \n";
	}
	MyIntStack b = a;
	if (a.pop(value))
		cout << "스택 a에서 삭제: " << value << endl;
	for (int i = 0; i < 6.i++)
		if (b.pop(value))
			cout << "스택 b에서 삭제: " << value << endl;
	return 0;
}