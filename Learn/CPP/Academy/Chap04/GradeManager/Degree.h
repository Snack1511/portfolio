#pragma once
#include"Include.h"
class Degree
{
private:
	list<Student> students;
	char* studentName;


public:
	int Menu();
	void Choice();
	void Insert();
	void All_list();
	void Search(char* searcingname);
	void Change();
	void Delete();
	void Exit();


public:
	Degree();
	~Degree();
};

