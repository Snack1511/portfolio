#include<stdio.h>

int main() {
	int xnum;
	printf("16진수 입력 : ");
	scanf("%x", &xnum);
	printf("16진수\t10진수\t8진수\n");
	printf("%x\t%d\t%o\n", xnum, xnum, xnum);
	return 0;
}