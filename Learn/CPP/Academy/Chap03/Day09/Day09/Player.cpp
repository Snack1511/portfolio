#include "Player.h"
#include "Include.h"

void Player::Initialize()
{
	cout << "Player::Initialize" << endl;
}

void Player::Progress()
{
	cout << "Player::Progress" << endl;
}

void Player::Render()
{
	cout << "Player::Render" << endl;
}

void Player::Release()
{
	cout << "Player::Release" << endl;
}

Player::Player(void)
{
}


Player::~Player(void)
{
	Release();
}
