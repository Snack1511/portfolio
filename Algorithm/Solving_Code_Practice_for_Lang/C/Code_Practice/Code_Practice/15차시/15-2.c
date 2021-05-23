#include<stdio.h>

int main() {
	char str[100001];
	int r = 0, l = 0;
	printf("괄호 문자열 입력 : ");
	gets(str);
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '(') l++;
		else r++;
	}
	printf("( : %d개", l);
	printf("\n");
	printf(") : %d개", r);


	return 0;
}