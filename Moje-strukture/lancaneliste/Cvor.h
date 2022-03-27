#pragma once
#include<iostream>
using namespace std;
class Cvor
{public:
	int info;
	Cvor* next;
	//------------------------------------------------------------
	Cvor() {
		info = 0000;
		next = NULL; }
	Cvor(int i) { info = i; next = NULL; }
	Cvor(int i, Cvor* n)
	{
		info = i;
		next = n;
	}
	~Cvor(){}
	int print() { return info; }
	bool jednak(int el) { return el == info; }


};