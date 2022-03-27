#pragma once

class Player
{
private:
	char* label;
	char* firstName;
	char* lastName;
	char* nationalTeam;
	unsigned int number;

public:
	Player();

private:
	void allocateMemory(char* label, char* firstName, char* lastName, char* nationalTeam);

public:
	Player(char* label, char* firstName, char* lastName, char* nationalTeam, 
		unsigned int number);

private:
	void deallocateMemory();

public:
	Player(const Player& player);

	Player& operator=(const Player& player);

	~Player();

	char* getLabel() const { return this->label; }

	friend ostream& operator<<(ostream& outputStream, const Player& player);
};