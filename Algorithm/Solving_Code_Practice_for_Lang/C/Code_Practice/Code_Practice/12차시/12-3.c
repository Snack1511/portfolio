#include<stdio.h>

int main() {
	char str[31];
	printf("단어(영어) 입력 : ");
	scanf("%s", &str);
	for (int i = 0; str[i] != NULL; i++) {
		printf("\'%c\'\n", str[i]);
	}
	return 0;
}