#include<stdio.h>

int main() {
	int y, m;
	int day;
	scanf("%d %d", &y, &m);

	if (m >= 8) m += 1;
	if (m % 2 == 1) day = 31;
	else day = 30;

	if (y % 4 == 0 && y % 100 != 0) {
		if (m == 2) day = 28;
	}
	printf("%d", day);
	
	return 0;
}