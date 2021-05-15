#include<iostream>
#include<vector>
using namespace std;
vector<int> Tree[11];
bool check[10];

void DFS(int n) {
	if (check[n]) return;
	cout << n << " ";
	check[n] = true;
	for (int i = 0; i < Tree[n].size(); i++) {
		
		DFS(Tree[n][i]);
	}
	
}

int main() {
	Tree[1].push_back(2);
	Tree[1].push_back(3);

	Tree[2].push_back(1);
	Tree[2].push_back(3);
	Tree[2].push_back(4);
	Tree[2].push_back(5);

	Tree[3].push_back(1);
	Tree[3].push_back(2);
	Tree[3].push_back(6);
	Tree[3].push_back(7);

	Tree[4].push_back(2);
	Tree[4].push_back(5);
	Tree[4].push_back(8);
	Tree[4].push_back(9);

	Tree[5].push_back(2);
	Tree[5].push_back(4);
	Tree[5].push_back(10);

	Tree[6].push_back(3);
	Tree[6].push_back(7);

	Tree[7].push_back(3);
	Tree[7].push_back(6);

	Tree[8].push_back(4);
	Tree[8].push_back(9);

	Tree[9].push_back(4);
	Tree[9].push_back(8);

	Tree[10].push_back(5);


	DFS(1);
	return 0;
}