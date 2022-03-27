#pragma once
#include <iostream>

using namespace std;


class PNode
{
public:
	double koef;
	int exp;
	PNode* next;
public:
	PNode(void){ koef = 1; exp = 1; next = NULL; }
	PNode(int exp, double koef){ this->exp = exp, this->koef = koef; };
	void print() { cout << koef << "x^" << exp; }
	~PNode(void){};
};
