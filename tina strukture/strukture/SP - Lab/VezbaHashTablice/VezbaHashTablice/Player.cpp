#include <iostream>
#include <string.h>

using namespace std;

#include "Player.h"

Player::Player()
{
	this->label = this->firstName = this->lastName = this->nationalTeam = nullptr;
	this->number = 0;
}

void Player::allocateMemory(char* label, char* firstName, char* lastName, char* nationalTeam)
{
	this->label = new char[strlen(label) + 1];
	this->firstName = new char[strlen(firstName) + 1];
	this->lastName = new char[strlen(lastName) + 1];
	this->nationalTeam = new char[strlen(nationalTeam) + 1];

	strcpy_s(this->label, strlen(label) + 1, label);
	strcpy_s(this->firstName, strlen(firstName) + 1, firstName);
	strcpy_s(this->lastName, strlen(lastName) + 1, lastName);
	strcpy_s(this->nationalTeam, strlen(nationalTeam) + 1, nationalTeam);
}

Player::Player(char* label, char* firstName, char* lastName, char* nationalTeam,
	unsigned int number)
{
	this->allocateMemory(label, firstName, lastName, nationalTeam);

	this->number = number;
}

void Player::deallocateMemory()
{
	if (this->label)
	{
		delete[] this->label;
	}

	if (this->firstName)
	{
		delete[] this->firstName;
	}

	if (this->lastName)
	{
		delete[] this->lastName;
	}

	if (this->nationalTeam)
	{
		delete[] this->nationalTeam;
	}
}

Player::Player(const Player& player)
{
	this->allocateMemory(player.label, player.firstName, player.lastName, player.nationalTeam);

	this->number = player.number;
}

Player& Player::operator=(const Player& player)
{
	if (this != &player)
	{
		this->deallocateMemory();

		this->allocateMemory(player.label, player.firstName, player.lastName, player.nationalTeam);

		this->number = player.number;
	}

	return *this;
}

Player::~Player() { this->deallocateMemory(); }

ostream& operator<<(ostream& outputStream, const Player& player)
{
	outputStream << player.label << " - " << player.firstName << " " << player.lastName <<
		" - " << player.nationalTeam << " - " << player.number;

	return outputStream;
}