#include<iostream>
#include<ctime> 
/*
	Dynamic Programming

하나의 문제는 단 한번만 풀도록 하는 알고리즘
	-> 상당수의 분할 정복 기법은 동일한 문제를 다시 푼다는 단점이 존재
	
	-> 대표적인 문제 ->  피보나치 수열 :  D[i] = D[i-1] + D[i-2]
		 -> 특정 수를 구하기 위해서는 그 앞에 있는 수와 두칸 앞에 있는 수의 합을 구해야 한다. 
		-> 이미 해결한 문제를 다시 반복적으로 해결 -> 비효율

다이나믹 프로그래밍은 다음의 가정 하에 사용가능 
	1. 큰 문제를 작은 문제로 나눌 수 있다.
	2. 작은 문제에서 구한 정답이 그것을 포함하는 큰 문제에도 동일하다.

		==> 크고 어려운 문제가 있을 시 잘게 나누어 해결한 뒤 처리
			이후 전체의 답 도출

	위 과정에서 메모이제이션(memoization)이 사용됨
		--> 이부분이 분할 정복과는 다름
		--> 계산한 결과는 배열에 저장해서 필요시 호출


*/

 
using namespace std;


int fibonacci(int x){
	if(x == 1) return 1;
	if(x == 2) return 1;
	
	return fibonacci(x - 1) + fibonacci(x - 2);
}

int d[100];

int fibonacci_DoMemoization(int x){
	if (x == 1) return 1;
	if (x == 2) return 1;
	
	if(d[x] != 0) return d[x];//메모이제이션을 활용한 스킵 
	
	return d[x] = fibonacci(x-1) + fibonacci(x-2);
} 

int main(){
	int n;
	//cin >> n;
	
	clock_t startTime = clock();
	clock_t endTime;
	clock_t elapsed;
	
	n = 45;
	
	cout << "fibo 10 : " << fibonacci(45) <<endl;// 수열이 1만 늘어나도 계산량 2배 증가 --> 2의 n승 
	
	endTime = clock();
	elapsed = endTime - startTime;
	cout << "  ---- Time : " << (double)(elapsed / CLOCKS_PER_SEC) << "   ms : " << elapsed << endl<< endl;
	startTime = clock();
	
	cout << "fibo_Memoization " << n/5 << " : "<< fibonacci_DoMemoization(n/5) << endl;
	
	endTime = clock();
	elapsed = endTime - startTime;
	cout << "  ---- Time : " << (double)(elapsed / CLOCKS_PER_SEC) << "   ms : " << elapsed << endl<< endl;
	startTime = clock();
	
	cout << "fibo_Memoization " << n/3 << " : "<< fibonacci_DoMemoization(n/3) << endl;
	
	endTime = clock();
	elapsed = endTime - startTime;
	cout << "  ---- Time : " << (double)(elapsed / CLOCKS_PER_SEC) << "   ms : " << elapsed << endl<< endl;
	startTime = clock();
	
	
	cout << "fibo_Memoization " << n/2 << " : "<< fibonacci_DoMemoization(n/2) << endl;
	
	endTime = clock();
	elapsed = endTime - startTime;
	cout << "  ---- Time : " << (double)(elapsed / CLOCKS_PER_SEC) << "   ms : " << elapsed  << endl<< endl;
	startTime = clock();
	
	
	cout << "fibo_Memoization " << n << " : "<< fibonacci_DoMemoization(n) << endl;
	
	endTime = clock();
	elapsed = endTime - startTime;
	cout << "  ---- Time : " << (double)(elapsed / CLOCKS_PER_SEC) << "   ms : " << elapsed << endl;
	return 0;
}
