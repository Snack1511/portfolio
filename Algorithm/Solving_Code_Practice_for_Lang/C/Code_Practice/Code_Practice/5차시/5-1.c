#include<stdio.h>

int main() {
	int money, remain, book = 15000;

	printf("이 책의 가격은 %d 원 입니다.\n", book);
	printf("당신의 용돈을 입력하세요 : ");
	scanf("%d", &money);

	if (money >= book) {
		remain = money - book;
		printf("책을 구입하고 남은 용돈은 %d 원 입니다.\n", remain);
	}

	return 0;
}