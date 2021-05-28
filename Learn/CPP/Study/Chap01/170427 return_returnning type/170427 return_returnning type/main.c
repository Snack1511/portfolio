#include<stdio.h>

//함수 전방 선언. => c언어는 멍청해서 언급하지 않으면 쓰질 않음
int Add(int _i, int _n);//선언

int main()
{

	int iNum1 = 10;//여기iNum과
	int iNum2 = 20;

	if(iNum1 <= 20)
	{

		int iNum = 20;//여기iNum은 다른 변수

		printf("%d\n", iNum);
	}
	printf("%d\n", iNum1);
	printf("%d\n", iNum2);
	printf("%d\n", Add(iNum1, iNum2));
	
	
	

	return 0;
}//main함수는 언제나 최 상단에 있는것이 약속ㅇㅇ

int Add(int _i, int _n)
{
	int iResult = _i + _n;

	return iResult;

}//정의