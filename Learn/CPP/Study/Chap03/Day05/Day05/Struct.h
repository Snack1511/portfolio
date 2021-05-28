#pragma once
typedef struct tagInfo {

	char * Name;
	int iKor;
	int iEng;
	int iMath;

	tagInfo() {};
	tagInfo(char * _name, int _ikor, int _ieng, int _imath) 
		:Name(_name), iKor(_ikor), iEng(_ieng), iMath(_imath) {};

}INFO;