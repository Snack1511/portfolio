#include<iostream>

using namespace std;

//int Max(int a, int b)
//{
//	if (a > b)
//	{
//		return a;
//	}
//	else
//		return b;
//
//}

/*template <typename T>T Max(T a, T b)
{
	if (a > b)
	{
		return a;
	}
	else
		return b;
}*/
template <typename T1, typename T2>const T1& Max(const T1& a, const T2& b)
{
	cout << "템플릿 버젼" << endl;
	if (a > b)
	{
		return a;
	}
	else
		return b;
}
//※보통 쓸때 이렇게 쓴다 혹시나 매개변수의 데이터 변환을 없게 하기 때문에

template <> const double& Max(const double& a, const double& b)
{
	cout << "전문화 버젼" << endl;
	if (a > b)
	{
		return a;
	}
	else
		return b;
}//햇갈리는 템플릿 변수로 인한 실수를 방지하기 위해서

template <typename T1, typename T2> const double& Add(const T1& a, const T2& b)
{
	return a + b;
}



void main()
{
	int num1 = 200;
	double num2 = 200.2;

	float maxValue;
	maxValue = Max(num1, num2);
	cout << "큰것은 : " << maxValue << endl << endl;

	double num3 = 200;
	double num4 = 200.2;

	double maxValue2;
	maxValue2 = Max(num3, num4);
	cout << "큰것은 : " << maxValue2 << endl << endl;

	float num5 = 200;
	float num6 = 200.2;

	float maxValue3;
	maxValue3 = Max(num5, num6);
	cout << "큰것은 : " << maxValue3 << endl << endl;

	double n1 = 200;
	double n2 = 200.2;

	double AddValue;
	AddValue = Add(num1, num2);
	cout << "합계 : " << AddValue << endl << endl;
}