#include "MyPoint.h"

int main()
{
	MyPoint p1(3, 5), p2(5, 5), p3;
	cout << "p1:" << p1 << " p2:" << p2 << " p3:" << p3 << endl;
	p3 = p1 + p2;
	cout << "p1+p2 연산 후 결과 p3 :" << p3 << endl;
	p1 = p1 + 10;
	cout << "p1+10 연산 후 결과 p1:" << p1 << endl;
	p2 = 100 - p2;
	cout << "20-p2 연산 후 결과 p2:" << p2 << endl;
	MyPoint p4, p5;
	cout << "p1를 입력(x,y좌표순으로):";
	cin >> p4;
	p5 = p4++;
	cout << "p5 = p4++; 수행 후 p5:" << p5 << " p4:" << p4 << endl;
	if (p5 == p4) cout << "두 점 p5, p4의 좌표가 같습니다.\n";
	else cout << "두 점 p5, p4의 좌표가 다릅니다.\n";
	p3 = ++p1 + p2--;
	cout << "p3 = ++p1 + p2--; 수행 후 p1:" << p1 << " p2:" << p2 << " p3:" << p3 << endl;
	return 0;
}