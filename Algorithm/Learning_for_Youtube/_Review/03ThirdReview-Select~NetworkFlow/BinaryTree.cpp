#include<iostream>
#include<vector>

using namespace std;

typedef struct Node* Npoint;
typedef struct Node{
public:
	int value;
	Npoint LeftC, RightC;
	Node() {}
	Node(int _value) {
		value = _value;
		LeftC = nullptr;
		RightC = nullptr;
	}
	void SetChildren(Node* lc, Node* rc) {
		LeftC = lc;
		RightC = rc;
	}
}N;

void preorderTravelsal(Npoint a) {
	if (a) {
		cout << a->value << " ";
		preorderTravelsal(a->LeftC);
		preorderTravelsal(a->RightC);
		
	}
}
void InorderTravelsal(Npoint a) {
	if (a) {
		InorderTravelsal(a->LeftC);
		cout << a->value << " ";
		InorderTravelsal(a->RightC);
	}
	
}
void postorTrabelsal(Npoint a) {
	if (a) {
		postorTrabelsal(a->LeftC);
		postorTrabelsal(a->RightC);
		cout << a->value << " ";
	}
}

int main() {
	N n[10];
	for (int i = 0; i < 10; i++) {
		n[i].value = i;
		n[i].LeftC = nullptr;
		n[i].RightC = nullptr;
	}
	for (int i = 1; i < 10; i++) {
		if (i % 2 == 1) {
			n[i / 2].LeftC = &n[i];
		}
		else {
			n[i / 2].RightC = &n[i];
		}
	}
	cout << endl << endl << "preorderTavelsal" << endl;
	preorderTravelsal(n);
	cout << endl << endl << "InorderTravelsal" << endl;
	InorderTravelsal(n);
	cout << endl << endl << "postorTrabelsal" << endl;
	postorTrabelsal(n);
	return 0;
}