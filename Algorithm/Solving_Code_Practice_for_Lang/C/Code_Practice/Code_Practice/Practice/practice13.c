#include<stdio.h>

int main() {
	char base[64];
	printf("원문 입력 : ");
	gets(base, '\0');
	for (int i = 0; base[i] != '\0'; i++) {
		if (base[i] != ' ') {
			base[i] += 3;
		}
	}
	printf("%s", base);

	return 0;
}