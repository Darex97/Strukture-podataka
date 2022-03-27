#pragma once
#include "PNode.h"
#include <iostream>

using namespace std;


class CPolynomLL
{
public:
	PNode* head, *tail;
public:
	CPolynomLL(void){ head = tail = NULL; };
	void Coef(int exp, double koef);
	CPolynomLL* Add(CPolynomLL poly1, CPolynomLL poly2);
	bool isEmpty() { return head == NULL; }
	void printPolin();
	~CPolynomLL(void);
};
