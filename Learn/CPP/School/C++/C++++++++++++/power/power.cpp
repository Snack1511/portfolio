#include"power.h"

Power Power::operator+(Power a) {
	Power tmp;
	tmp.kick = this->kick + a.kick;
	tmp.punch = this->punch + a.punch;
	return tmp;

}

bool Power::operator==(Power a) {
	if (this->kick = a.kick && this->punch == a.punch)
		return true;
	else return false;
}

bool Power::operator<(Power a) {
	if (this->kick < a.kick && this->punch < a.punch)
		return true;
	else return false;
}

Power Power::operator++() {
	this->kick++;
	this->punch++;
	return *this;
}

Power Power::operator+=(Power a) {
	this->kick = this->kick + a.kick;
	this->punch = this->punch + a.punch;
	return *this;
}

int main() {
	Power lee(100, 200), park, kim(5, 5);

	park = kim + lee;//park = kim+(lee)
	park.show();
	kim.show();
	lee.show();
	if (lee == kim) cout << "규운형은 유지되어야 한다!" << endl;
	else cout << "널 박살내주마!" << endl;
	if (lee < kim) cout << "kim이 파워가 셉니다\n";
	else cout << "lee가 파워가 셉니다\n";

	park.operator++();
	park.show();

	lee += kim;
	lee.show();
	kim.show();
}