#include<iostream>
#include<math.h>
using namespace std;

bool IsPrimenumber(int n) {
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

bool IsPrimenumber_Sqr(int n) {
	int n_sqr = sqrt(n);
	for (int i = 2; i < n_sqr; i++) {
		if(n % i == 0) return false;
	}
	 return true;
}
int main() {
	cout << IsPrimenumber(19998523481)<<endl;
	cout << IsPrimenumber_Sqr(19998523481);
	return 0;
}