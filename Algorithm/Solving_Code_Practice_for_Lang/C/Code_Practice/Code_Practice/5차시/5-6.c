#include<stdio.h>

int main() {
	char ch;

	printf("영어 소문자를 입력하세요 : ");
	scanf("%c", &ch);
	switch (ch) {
	case 'a': case 'e': case 'i': case 'o': case 'u':
		printf("모음");
		break;
	default :
		printf("자음");
		break;
	}
	return 0;
}