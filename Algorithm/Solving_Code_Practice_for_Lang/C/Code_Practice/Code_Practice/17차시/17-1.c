#include <stdio.h>
#include <string.h>
int main() {
	char w1[21], w2[21], w3[21];

	printf("한 줄에 하나씩 세 단어를 입력하세요\n");
	scanf("%s %s %s", w1, w2, w3);

	printf("순환 문자열 : ");
	if (w1[strlen(w1) - 1] == w2[0] &&
		w2[strlen(w2) - 1] == w3[strlen(w3) - 1] == w1[0])
		printf("Yes");
	else
		printf("No");

	return 0;
}