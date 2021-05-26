#include "Student.h"



void Student::show()
{
	cout << "ID : " << id << endl;
	cout << "Name : " << name << endl;
	cout << "Percentage : " << percentage << endl;
	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
}

void Student::SetInfo(int _id, char * _name, float _percentage)
{
	id = _id;
	name = _name;
	percentage = _percentage;
}

Info Student::PassToStruct(Student a[], Info s[])
{

	
	for (int i = 0; i < 5; i++) 
	{
		s[i].id = a[i].id;
		s[i].name = a[i].name;
		s[i].percentage = a[i].percentage;
		return s[i];
	}
}



/*void Student::SortDegree(Info a[])
{
	
	Info tmp(0, " ", 0.0);
	for (int i = 0; i < 5; i++) 
	{
		
	}
	for (int i = 0; i < 5; i++) 
	{
		if (a[i].percentage < a[i + 1].percentage) 
		{
			tmp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = tmp;
		}
		if (a[i].percentage == a[i + 1].percentage) 
		{
			if (a[i].id < a[i + 1].id)
			{
				tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
			}
		}
	}
}

void Student::ShowAllStudent(Info a[])
{
	cout << "µî¼ö" << endl;
	for (int i = 0; i < 5; i++) 
	{
		cout << "ID : " << a[i].id << endl;
		cout << "Name : " << a[i].name << endl;
		cout << "Percentage : " << a[i].percentage << endl;
		cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	}
}*/

Student::Student()
{
}


Student::~Student()
{
}
