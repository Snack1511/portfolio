#include<stdio.h>

int main() {
	char str[128];
	printf("거꾸로 말할 문장 입력 : ");
	gets(str);

	for (int i = strlen(str); i >= 0; i--) {
		printf("%c", str[i]);
	}

	return 0;
}
