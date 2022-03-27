#pragma once
#include"SLLNode.h"
#include<iostream>
using namespace std;

class CPolynomLL
{
public:
	SLLNode *head;
public:
	CPolynomLL();
	void Coef(double c,int e);
	CPolynomLL* Add(const CPolynomLL& P1,const CPolynomLL& P2);
	void PRINT();
	~CPolynomLL();
};

