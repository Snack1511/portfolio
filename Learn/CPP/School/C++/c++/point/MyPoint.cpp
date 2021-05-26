#include "MyPoint.h"

MyPoint MyPoint::operator+(const MyPoint& p) {
	return(this->x + p.x, this->y + p.y);
}
MyPoint MyPoint::operator+(const int v) {
	return(x+v, y+v);
}
MyPoint operator+(int val, const MyPoint& p) {
	return (p.x + val, p.y + val);
}

MyPoint MyPoint::operator-(const MyPoint& p) {
	return(x - p.x, y - p.y);
}
MyPoint MyPoint::operator-(const int v) {
	return(x - v, y - v);
}
MyPoint operator-(int val, const MyPoint& p) {
	return (p.x - val, p.y - val);
}

MyPoint MyPoint::operator++() {
	x++;
	y++;
	return *this; // 변경된 객체 자신(객체 a) 리턴
}
MyPoint MyPoint::operator++ (int x) {
	MyPoint tmp = *this; // 증가 이전 객체 상태를 저장
	x++;
	y++;
	return tmp; // 증가 이전 객체 상태 리턴
}
MyPoint MyPoint::operator--() {
	x++;
	y++;
	return *this; // 변경된 객체 자신(객체 a) 리턴
}
MyPoint MyPoint::operator-- (int x) {
	MyPoint tmp = *this; // 감소 이전 객체 상태를 저장
	x++;
	y++;
	return tmp; // 감소 이전 객체 상태 리턴
}

bool MyPoint::operator<(const MyPoint& p) {
	if (x < p.x && y < p.y) return true;
	else return false;
}
bool MyPoint::operator==(const MyPoint& p) {
	if (x == p.x && y == p.y) return true;
	else return false;
}
bool MyPoint::operator!=(const MyPoint& p) {
	if (x != p.x && y != p.y) return true;
	else return false;
}
ostream& operator<<(ostream& os, const MyPoint& p) {
	os << "[" << p.x << ", " << p.y << "]" << endl;
	return os;
}

istream& operator >> (istream& is, MyPoint& p) {
	is >> p.x >> p.y;
	return is;
}



