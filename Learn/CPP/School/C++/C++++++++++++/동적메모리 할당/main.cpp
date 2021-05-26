#include<iostream>

using namespace std;

void main() {
	int num, *pdata;
	double *p_data;

	cout << "데이터 개수 입력 : ";
	cin >> num;

	p_data = new double[num];


	for (int i = 0; i < num; i++){
		cin >> p_data[i];
	}

	cout << "입력된 데이터 확인\n";
	for (int i = 0; i < num; i++) {
		cout << *p_data << " ";
		p_data++;
	}


	delete[] p_data;


}