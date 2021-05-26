#include"Degree.h"

void main() 
{
	Degree degree;

	Student student[6];
	
	for (int i = 0; i < 6; i++) 
	{
		cout << "name : ";
		cin >> student[i].userName;
		cout << "major : ";
		cin >> student[i].major;
		cout << "number : ";
		cin >> student[i].num;
		cout << "grade : ";
		cin >> student[i].grade;
	}

	while (1) 
	{
		degree.Choice();
	}

}