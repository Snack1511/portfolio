#include<iostream>
#include<stack>
using namespace std;

/*
	≈• :  First in Fist out 
	Ω∫≈√ : Last in First out 
*/

int main(){
	stack<int> s;
	s.push(6);
	s.push(5);
	s.push(0);
	s.push(8);
	s.push(9);
	s.push(1);
	
	s.pop();
	
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}
