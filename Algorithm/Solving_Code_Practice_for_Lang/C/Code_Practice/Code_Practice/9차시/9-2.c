#include<stdio.h>

int main() {
	char input, start = 'a';

	printf("영문자 입력 : ");
	scanf("%c", &input);

	do {
		printf("%c\n", start);
		start++;
	} while (start <= input);



	return 0;
}