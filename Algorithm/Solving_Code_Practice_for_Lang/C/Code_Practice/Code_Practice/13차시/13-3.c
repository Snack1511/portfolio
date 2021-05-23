#include<stdio.h>

int main() {
	char code;
	printf("암호 : ");

	while (1) {
		scanf("%c", &code);
		if (code == '\n') {
			printf("로 복원했습니다.");
			break;
		}

		if (code >= 'a' && code <= 'z') {
			if (code - 3 < 'a') printf("%c", code + 23);
			else if (code - 3 > 'a') printf("%c", code - 3);
		}
		else if (code == ' ') printf(" ");
	}
	
	return 0;
}