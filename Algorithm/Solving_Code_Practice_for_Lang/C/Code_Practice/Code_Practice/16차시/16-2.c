#include<stdio.h>

int main() {
	char arr1[101] = { 0, };
	char arr2[101] = { 0, };
	int len1, len2, i;

	printf("비교할 두 숫자를 공백으로 구분하여 입력 \n");
	scanf("%s %s", arr1, arr2);


	len1 = strlen(arr1);
	len2 = strlen(arr2);

	if (len1 < len2) {
		printf("%s %s", arr1, arr2);
	}
	else if (len2 < len1) {
		printf("%s %s", arr2, arr1);
	}
	else {
		for (i = 0; i < len1; i++) {
			if(arr1[i] < arr2[i]) printf("%s \t %s", arr1, arr2);
			else if (arr1[i] > arr2[i]) printf("%s \t %s", arr2, arr1);
			printf("\n");
		}
	}
}