#include<stdio.h>
#include<stdlib.h>
int main() {
	char n[8];
	char add[8];
	int idx = 0;
	printf("정수입력 : ");
	scanf("%s", &n);
	for (int i = 0; i < 8; i++) {
		if (n[i] == '\0') {
			idx = i;
		}
	}
	for (int i = 0; i < idx; i++) {
		add[i] = ((n[i] - '0') + (n[idx - (i + 1)] - '0')) + '0';
	}
	add[idx] = '\0';
	for (int i = 0; i < idx; i++) {
		if (add[i] == add[idx - (i + 1)]) {
			printf("OK\n");
			return 0;
		}
	}
	printf("Not Ok\n");
	return 0;
}