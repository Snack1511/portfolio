#include<stdio.h>

int main() {
	//\0 : NULL문자 -> 문자열의 끝을 표시
	//30개의 문자열 -> NULL문자 포함 31개
	char c[31] = "";
	printf("단어입력 : ");
	scanf("%s", c);

	printf("%s", c);
	return 0;
}
