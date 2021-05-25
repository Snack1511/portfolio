#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;


int DoRandom(int n);
void PrintTrain();
void PrintDegree();
void PrintDegree(int n);
void GetBox();
void main() 
{
	//int n = 0;
	//cin >> n;
	//cout << dorandom(n) <<endl;
	//PrintDegree(n);
	while (true) {
		cout << "Do Open Box? if you want press a" << endl;
		char a = NULL;
		cin >> a;
		if (a == 'a')
		{
			GetBox();
		}
	}
	
}

int DoRandom(int n)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++) 
	{
		return rand() % 100;
	}
}

void GetBox() 
{
	srand((unsigned)time(NULL));
	int a;
	int Value = 0;
	int &RefVal = Value;
	a = rand() % 100;
	if (100 - a < 30) {Value = 0;}
	if (100 - a >= 30 && 100 - a < 60) { Value = 1; }
	if (100 - a >= 60 && 100 - a < 90) { Value = 2; }
	if (100 - a >= 90 && 100 - a < 100) { Value = 3; }

	switch (Value) 
	{
	case 0:
		cout << "WeaponBox" << endl;
		PrintDegree();
		break;
	case 1:
		cout << "ArmorBox" << endl;
		PrintDegree();
		break;
	case 2:
		cout << "TrainBox" << endl;
		PrintTrain();
		break;
	case 3:
		cout << "UsableBox" << endl;
		PrintDegree();
		break;

	}

	cout << endl;
	
}

void PrintTrain() 
{
	srand((unsigned)time(NULL));
	int a;
	a = rand() % 6;
	switch (a) 
	{
		case 0:
			cout << "A" << endl;
			break;
		case 1:
			cout << "B" << endl;
			break;
		case 2:
			cout << "C" << endl;
			break;
		case 3:
			cout << "D" << endl;
			break;
		case 4:
			cout << "E" << endl;
			break;
		case 5:
			cout << "F" << endl;
			break;
	}
}
void PrintDegree()
{
	srand((unsigned)time(NULL));
	int a;
	a = rand() % 100;
	if (100 - a <= 37) { cout << "F" << endl; }//37
	if (100 - a <= 67 && 100 - a > 37) { cout << "C" << endl; }//30
	if (100 - a <= 87 && 100 - a > 67) { cout << "B" << endl; }//20
	if (100 - a <= 97 && 100 - a > 87) { cout << "A" << endl; }//10
	if (100 - a <= 100 && 100 - a > 97) { cout << "S" << endl; }//3

}



void PrintDegree(int n) 
{
	int a;
	int S = 0, A = 0, B = 0, C = 0, F = 0;//D = 0, E = 0;
	int &RefS = S, &RefA = A, &RefB = B, &RefC = C, &RefF = F; //&RefD = D, &RefE = E;
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		 a = rand() % 100;
		 /*if (a < 100 && a >= 20) { E++; }
		 if (a < 100 && a >= 30) { D++; }
		 if (a < 100 && a >= 40) { C++; }
		 if (a < 100 && a >= 50) { B++; }
		 if (a < 100 && a >= 90) { A++; }
		 if (a < 100 && a >= 99) { S++; }*/

		 /*if (100-a <= 80) { E++; }
		 if (100-a <= 70) { D++; }
		 if (100-a <= 60) { C++; }
		 if (100-a <= 50) { B++; }
		 if (100-a <= 10) { A++; }
		 if (100-a <= 1) { S++; }*/

		 /*if (100 - a <= 20) { E++; }
		 if (100 - a <= 30 && 100 - a > 20) { D++; }
		 if (100 - a <= 40 && 100 - a > 30) { C++; }
		 if (100 - a <= 50 && 100 - a > 40) { B++; }
		 if (100 - a <= 90 && 100 - a > 50) { A++; }
		 if (100 - a <= 99 && 100 - a > 90) { S++; }*/

		 if (100 - a <= 37) { F++; }//37
		 if (100 - a <= 67 && 100 - a > 37) { C++; }//30
		 if (100 - a <= 87 && 100 - a > 67) { B++; }//20
		 if (100 - a <= 97 && 100 - a > 87) { A++; }//10
		 if (100 - a <= 100 && 100 - a > 97) { S++; }//3


		 
		 if (i % 25 == 0) 
		 {
			 cout <<endl;
		 }
		 cout << a << " ";
		 
	}
	cout << endl;
	cout << "S : " << (RefS*100 )/ n << "   "<< RefS<<"/"<<n << endl;
	cout << "A : " << (RefA*100 )/ n << "   "<< RefA<<"/"<<n << endl;
	cout << "B : " << (RefB*100 )/ n << "   "<< RefB<<"/"<<n << endl;
	cout << "C : " << (RefC*100 )/ n << "   "<< RefC<<"/"<<n << endl;
	cout << "F : " << (RefF * 100) / n << "   " << RefF << "/" << n << endl;
	//cout << "D : " << (RefD*100 )/ n << "   "<< RefD<<"/"<<n << endl;
	//cout << "E : " << (RefE*100 )/ n << "   "<< RefE<<"/"<<n << endl;
						   
}						   
						   