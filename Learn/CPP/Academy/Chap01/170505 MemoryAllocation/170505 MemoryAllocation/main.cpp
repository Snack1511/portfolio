#include<stdio.h>
#include<malloc.h>

typedef struct tagInfo{
	int iX;
	int iY;

}INFO;

int main(){

	INFO* pInfo;
	pInfo = (INFO*)malloc(sizeof(INFO));//메모리 할당 함수 malloc()
	pInfo -> iX = 10;//*에 접근하려면 화살표
	return 0;
}