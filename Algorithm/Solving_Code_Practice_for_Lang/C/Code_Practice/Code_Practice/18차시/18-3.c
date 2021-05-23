#include <stdio.h>
int play_yut(int a, int b, int c, int d);

int main() {
	int yut1, yut2, yut3, yut4;

	printf("À·³îÀÌ¸¦ ½ÃÀÛÇÏ¼¼¿ä\n");
	scanf("%d %d %d %d", &yut1, &yut2, &yut3, &yut4);

	switch (play_yut(yut1, yut2, yut3, yut4))
	{
	case 1:
		printf("µµ");
		break;
	case 2:
		printf("°³");
		break;
	case 3:
		printf("°É");
		break;
	case 4:
		printf("À·");
		break;
	default:
		printf("¸ğ");
	}

	return 0;
}



int play_yut(int a, int b, int c, int d) {
	return a + b + c + d;
}