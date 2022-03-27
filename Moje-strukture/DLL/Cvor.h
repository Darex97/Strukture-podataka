#pragma once
#include<iostream>
using namespace std;
class Cvor
{
public:
	int info;
	Cvor* pr, * sl;

	Cvor()
	{
		info = 0000; pr = sl = NULL;
	}
	Cvor(int i) { info = i; pr = sl = NULL; }
	Cvor(int i, Cvor* p, Cvor* s) { info = i; pr = p; sl = s; }
	~Cvor(){}
	int print() { return info; }
	bool jednak(int e) { return e == info; }




};