#include<stdio.h>

int main() {
	char statement[1001];//문자 배열변수 선언
	fgets(statement, 1000, stdin);
	//공백문자가 포함된 문장을 입력받아 출력

	printf("%s", statement);
	return 0;
}
