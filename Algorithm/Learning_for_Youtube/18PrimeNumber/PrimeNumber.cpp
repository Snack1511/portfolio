/*
	소수판별
	PrimeNumber
	
	소수란 자기자신과 1만을 약수로 가지는 자연수를 의미한다. 
*/
#include<iostream> 
using namespace std;

bool IsPrimeNumber(int n){
	for(int i = 2; i < n; i++){
		if( n % i == 0) return false; 
		
	}// 2부터 n까지 비교하기 때문에 시간복잡도는 O(N)이다 
	 // 모든 경우의 수를 비교하기에 굉장히 비효율 적이다. 
	 // 8의 경우 2*4, 4*2와 같이 대칭을 이루기에
	 // 특정수의 제곱근 까지만 약수를 구하면 O(N^1/2)의 속도로 판별할 수 있다. 
	return true;
}

int main(){
	cout <<  IsPrimeNumber(100000) << endl;
	return 0;
}
