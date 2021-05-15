#include<stdio.h>

int main() {

	//소수점 이하 15자리 까지의 정밀도를 갖는 실수형 : double
	double dnum;
	printf("실수 입력 : ");
	scanf("%lf", &dnum);
	printf("%.10lf", dnum);
	return 0;
}