#pragma once
#include<iostream>

using namespace std;

struct Info
{
	int id;
	char* name;
	float percentage;
public:
	Info(){}
	Info(int _id, char* _name, float _percent) : id(_id), name(_name), percentage(_percent){}
};
class Student
{
private:
	int id;
	char* name;
	float percentage;
public:
	void show();
	void SetInfo(int _id, char* _name, float _percentage);
	static Info PassToStruct(Student a[], Info s[]);
	void SortDegree(Info a[]);
	void ShowAllStudent(Info a[]);
	
	Student();
	~Student();
};

