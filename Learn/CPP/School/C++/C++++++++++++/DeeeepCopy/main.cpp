#include "Person.h"

int main() {
	Person prof(100, "조미경");
	Person student(prof);
	Person student1(200, "홍길동");

	prof.show();
	student.show();

	cout << "이름 수정후 : " << endl;
	student.changeName(student1);

	prof.show();
	student.show();


	return 0;
}