#include<stdio.h>

int main() {
	char pw[21];
	int i;

	printf("패스워드 입력 : ");
	scanf("%s", pw);

	for (i = 0; pw[i] != '\0'; i++) {
		printf("%c", pw[i] + 2);
	}
	printf("\n");

	for (i = 0; i < pw[i] != '\0'; i++) {
		printf("%c", ((pw[i]*7)%80) + 48);
	}
	return 0;
}