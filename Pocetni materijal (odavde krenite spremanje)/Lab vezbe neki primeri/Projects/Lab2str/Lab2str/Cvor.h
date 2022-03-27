#pragma once
#include <iostream>
using namespace std;

class Cvor {
public:
	double info;
	Cvor* next;
public:
	Cvor()
	{
		next = NULL;
	}
	Cvor(double el)
	{
		info = el;
		next = NULL;
	}
	Cvor(double el, Cvor* n)
	{
		info = el;
		next = n;
	}
	~Cvor()
	{

	}
	
	double print()
	{
		return info;
	}
};