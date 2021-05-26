#include "GameItem.h"

GameItem GameItem::operator+(GameItem& p) {
	GameItem tmp(this->weapon + " + " + p.weapon);
	tmp.power = this->power + p.power;
	tmp.duration = this->duration + p.duration;

	return tmp;
}

GameItem GameItem::operator+(int v) {
	GameItem tmp;
	tmp.power = this->power + v;
	tmp.duration = this->duration + v;

	return tmp;
}

GameItem GameItem::operator*(GameItem& p) {
	GameItem tmp(this->weapon + " * " + p.weapon);
	tmp.power = this->power * p.power;
	tmp.duration = this->duration * p.duration;

	return tmp;
}

GameItem GameItem::operator-(GameItem& p) {
	GameItem tmp(this->weapon + " - " + p.weapon);
	tmp.power = this->power - p.power;
	tmp.duration = this->duration - p.duration;

	return tmp;
}

GameItem GameItem::operator-(int v) {
	GameItem tmp;
	tmp.power = this->power - v;
	tmp.duration = this->duration - v;

	return tmp;
}

// 전위 연산자
GameItem GameItem::operator++() {
	this->power++;
	this->duration++;
	return *this;
}

GameItem GameItem::operator--() {
	this->power--;
	this->duration--;
	return *this;
}

// 후위 연산자
GameItem GameItem::operator++ (int power) {
	GameItem tmp = *this;
	this->power++;
	this->duration++;
	return tmp;
}

GameItem GameItem::operator-- (int power) {
	//GameItem tmp = *this;
	this->power--;
	this->duration--;
	//return tmp;
	return *this;
}


// 비교 연산자
bool GameItem::operator<(const GameItem& p) {
	if (this->power < p.power)
		return true;
	return false;
}

bool GameItem::operator>(const GameItem& p) {
	if (this->power > p.power)
		return true;
	return false;
}

bool GameItem::operator==(const GameItem& p) {
	if (this->power == p.power && this->duration == p.duration)
		return true;
	return false;
}

bool GameItem::operator!=(const GameItem& p) {
	if (this->power != p.power && this->duration != p.duration)
		return true;
	return false;
}