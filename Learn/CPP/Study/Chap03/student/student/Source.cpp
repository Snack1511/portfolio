#include <iostream>
#include"Student.h"
/*using namespace std;

struct student
{
private:
	int id;
	char* name;
	float percentage;
public:
	void show();
	void SetInfo(int _id, char* _name, float _percentage);
	
};

void student::show() 
{
	cout << "ID : " << id << endl;
	cout << "Name : " << name << endl;
	cout << "Percentage : " << percentage << endl;
}

void student::SetInfo(int _id, char * _name, float _percentage)
{
	id = _id;
	name = _name;
	percentage = _percentage;
}*/


int main()
{
	Info a[5];
	Student s[5];
	s[0].SetInfo(1, "½Ö½Ö¹Ù", 99.9);
	s[0].show();
	s[1].SetInfo(2, "ÁÒ½º¹Ù", 55.4);
	s[1].show();
	s[2].SetInfo(3, "¹Ù¹ã¹Ù", 33.5);
	s[2].show();
	s[3].SetInfo(4, "º¸¼®¹Ù", 22.9);
	s[3].show();
	s[4].SetInfo(5, "´©°¡¹Ù", 44.4);
	s[4].show();
	//SortRank(Student::PassToStruct(s, a));
	

	
	

	return 0;
}

Info SortRank(Info a[]) 
{
	Info tmp(0, "", 0.0);
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
	for (int i = 0; i < 5; i++) 
	{
		cout << "ID : " << a[i].id << endl;
		cout << "Name : " << a[i].name << endl;
		cout << "Percentage : " << a[i].percentage << endl;
		cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	}
}