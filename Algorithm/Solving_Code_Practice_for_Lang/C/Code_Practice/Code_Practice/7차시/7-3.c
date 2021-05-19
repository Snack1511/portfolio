#include<stdio.h>

int main() {
	int num;
	

	do {
		printf("ÆÇº°ÇÒ ¼ö ÀÔ·Â : ");
		scanf("%d", &num);

		if (num > 0) {
			if (num % 2) printf("È¦¼ö\n");
			else printf("Â¦¼ö\n");
		}
	} while (num > 0);

	return 0;
}