#include "Degree.h"





int Degree::Menu()
{
	int choicenum = 0;
	cout << "1. Insert"<<endl;
	cout << "2. All_list" << endl;
	cout << "3. Search" << endl;
	cout << "4. Change" << endl;
	cout << "5. Delete" << endl;
	cout << "6. Exit" << endl;
	
	cin >> choicenum;
	
	return choicenum;

}
void Degree::Choice()
{
	int menunum = Menu();
	switch (menunum) 
	{
	case 1:
		Insert();
		break;
	case 2:
		All_list();
		break;
	case 3:
		char* searchingName;
		cout << "Type the searching name : ";
		cin >> searchingName;
		Search(searchingName);
		break;
	case 4:
		Change();
		break;
	case 5:
		Delete();
		break;
	case 6:
		Exit();
		break;
	}
	cout << endl;
	
}
void Degree::Insert()
{

}
void Degree::All_list()
{

}
void Degree::Search(char* searcingname)
{
	for (list<Student>::iterator iter = students.begin(); iter != students.end();) 
	{
		if (iter->userName == searcingname)
		{
			cout << "name   : " << iter->userName << endl;
			cout << "major  : " << iter->major << endl;
			cout << "number : " << iter->num << endl;
			cout << "grade  : " << iter->grade << endl;
		}
		else
			iter++;
		if (iter == students.end()) 
		{
			cout << "Not found name\n plz check this" << endl;
		}
	}
}
void Degree::Change()
{

}
void Degree::Delete()
{
	students.pop_back();
}
void Degree::Exit()
{
	students.clear();
	cout << "All clear" << endl;
	exit(0);
}



Degree::Degree()
{
}


Degree::~Degree()
{
}
