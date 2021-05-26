#include<iostream>
#include<iomanip>
#include<string>

using namespace std;
/*
int main()
{
	string str;
	int len;
	cout << "문자열을 입력:";
	getline(cin, str, '\n'); // 문자열 입력

	len = str.size(); // 문자열의 길이
	for (int i = 0; i < len; i++)
	{
		string first = str.substr(0, 1); // 맨 앞의 문자 1개를 문자열로 분리
		string second = str.substr(1, len - 1); // 나머지 문자들을 문자열로 분리
		str = second + first; // 두 문자열을 연결하여 새로운 문자열로 만듦
		cout << str << endl;
	}
	return 0;
}*/
/*
int main() {
	string name[5];

	cout << "다섯개의 이름입력";
	for (int i = 0; i < 5; i++) {
		getline(cin, name[i], '\n');
	}
	string min = name[0];
	for (int i = 0; i < 5; i++) {
		if (min > name[i])
			min = name[i];
	}
	cout << "맨 앞에 나오는 이름 : " << min;

	return 0;
}*/

int main(void)
{
	cout << setprecision(3) << 123456 << endl;
	return 0;
}
