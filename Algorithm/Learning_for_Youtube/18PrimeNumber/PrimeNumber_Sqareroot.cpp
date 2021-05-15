#include<stdio.h>
#include<math.h>
/*
	제곱근을 이용한 소수판별법
	제곱근의 값이 소수가 아니면 판별하는 값은 소수가 아님을 이용 
*/
bool IsPrimeNumber(int n){
	 int end = (int) sqrt(n);
	 for(int i = 2; i < end; i++){
	 	if(end % 2 == 0) return false;
	 	
	 } 
	return true;
} 

int main(){
	printf("%d", IsPrimeNumber(594)); 
	return 0;
}
