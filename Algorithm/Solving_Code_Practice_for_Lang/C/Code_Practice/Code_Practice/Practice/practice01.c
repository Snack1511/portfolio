#include<stdio.h>

int main() {
	char name[8] = "신나라";
	int age = 20;
	char sex = 'F';
	float sleepTime = 6.25;
	char sentence[32] = "최고 보다는 최선을";
	printf("=*=*=*=*=*=*[ 학생정보 ]*=*=*=*=*=*=\n");
	printf("  이    름 :\t%s\n", name);
	printf("  나    이 :\t%d\n", age);
	printf("  성    별 :\t%c\n", sex);
	printf("  수면시간 :\t%.2f\n", sleepTime);
	printf("  마음가짐 :\t%s\n", sentence);

	return 0;
}