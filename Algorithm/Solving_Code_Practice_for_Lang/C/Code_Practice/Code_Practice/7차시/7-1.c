#include<stdio.h>

int main() {
	int month;
	printf("©Ы ют╥б : ");
	scanf("%d", & month);

	switch (month) {
	case 3: case 4: case 5:
		printf("spring");
		break;
	case 6: case 7: case 8:
		printf("summer");
		break;
	case 9: case 10: case 11:
		printf("fall");
		break;
	case 12: case 1: case 2:
		printf("winter");
		break;
	default:
		printf("Wrong number");
		break;
	}

	return 0;
}