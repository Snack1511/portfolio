#include<stdio.h>

int main() {
	char base[50];
	int numc = 0, numcc = 0;
	printf("원문 입력 : ");
	gets(base, '\0');
	for (int i = 0; base[i] != '\0'; i++) {
		if (base[i] == 'c' || base[i] == 'C') {
			if (base[i + 1] == 'c' || base[i + 1] == 'C') {
				numcc++;
			}
			numc++;
		}
	}
	printf("문자 C : %d\n", numc);
	printf("문자 CC : %d", numcc);

	return 0;
}