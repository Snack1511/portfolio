#include<iostream>
#include<queue>
using namespace std;

/*
	≈• :  First in Fist out 
	Ω∫≈√ : Last in First out 
*/

int main(){
	queue<int> q;
	q.push(6);
	q.push(5);
	q.push(0);
	q.push(8);
	q.pop();
	q.push(1);
	q.pop();
	
	while(!q.empty()){
		cout << q.front() << " ";
		q.pop();
	}
	return 0;
}
