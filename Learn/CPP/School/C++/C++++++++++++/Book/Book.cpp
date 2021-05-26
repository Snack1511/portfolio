#include "Book.h"

Book::Book(char *title, int price) {
	int titlelength = strlen(title);
	
	//이 밑은 set으로 들어가면 좋을듯...
	this->title = new char[titlelength + 1];
	strcpy(this->title, title);
}
Book::~Book() {
	if(title)
	delete[] this->title;
}