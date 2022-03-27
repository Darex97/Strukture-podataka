#pragma once
#include <iostream>
using namespace std;

class HashObject
{
public:
	char* ime;
	char* prezime;
	char* tel;
	bool free;
	int next;

	HashObject()
	{
		ime = NULL;
		prezime = NULL;
		tel = NULL;
		free = true;
		next = -1;
	}
	HashObject(char* i, char* p, char* t)
	{
		ime = i;
		prezime = p;
		tel = t;
		free = false;
		next = -1;
	}
	HashObject(char* i, char* p, char* t, int n)
	{
		ime = i;
		prezime = p;
		tel = t;
		free = false;
		next = n;
	}
	void deleteRecord()
	{
		if (!free)
			ime = NULL;
			prezime = NULL;
			tel = NULL;
			free = true;
	}
	void print()
	{
		cout << ime << " " << prezime << " " << tel << endl;
	}
	void setNext(int i)
	{
		next = i;
	}
};