#include <stdio.h>
int leap_year(int y);

int main() {
	int year;

	printf("연도 입력 : ");
	scanf("%d", &year);

	if (leap_year(year))
		printf("\'yes\'");
	else
		printf("\'no\'");

	return 0;
}

int leap_year(int y) {
	
	if ((y % 400 == 0 || y % 4 == 0) && (y % 100 != 0))
		return 1;
	else
		return 0;
}