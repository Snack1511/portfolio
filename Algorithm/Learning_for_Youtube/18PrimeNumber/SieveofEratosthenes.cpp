
//#include<iostream>
/*
	Sieve of Eratosthenes
	
	대표적인 소수판별 알고리즘
	다랑의 소수를 판별하고 싶을 때 적절 
	
	1. 이차원 배열을 생성후 값 초기화 
	
	2. 2부터 시작해서 해당 수의 배수를 모두 지워준다.
			자기자신은 지우지 않는다. 
	
	3. 이미 지워진 값이면 넘어간다. 
	
	4. 남아있는 숫자 출력 
	 
*/
#include<stdio.h>

int num = 100000;
int a[100001];

void PrimeNumber_Sieve() {
	for(int i = 2; i <= num; i++){
		a[i] = i;
	}//값 초기화 
	
	for(int i = 2; i <= num; i++){
		if(a[i] == 0) continue; //이미 지워진 값은 건너 뜀 
		for(int j = i + i; j <= num; j += i){ // j의 초기값 -> i의 다음 배수; j에 i를 추가하며 증가 
			a[j] = 0;// num아래에 해당하는 수가 존재할 경우 0으로 초기화 
		}
	} 
	for(int i = 2; i <= num; i++){
		if(a[i] != 0){//0으로 초기화된 수를 제외한 나머지 수들 출력 
			printf("%d ", a[i]);
		}
		
	}
}


int main() { 
	PrimeNumber_Sieve();
	return 0;
}
