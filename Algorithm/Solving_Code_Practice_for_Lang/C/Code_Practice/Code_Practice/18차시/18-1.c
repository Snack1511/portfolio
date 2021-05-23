#include <stdio.h>
int zero(int x);
void non_zero(int x);

int main() {
	int num;

	printf("정수 1개 입력 : ");
	scanf("%d", &num);

	if(!zero(num))
		printf("\'zero\'");
	else
		printf("\'non zero\'");
	
	non_zero(num);

	return 0;
}

int zero(int x) {
	return x;
}

void non_zero(int x) {
	if (!x)
		printf("\'zero\'");
	else
		printf("\'non zero\'");
}