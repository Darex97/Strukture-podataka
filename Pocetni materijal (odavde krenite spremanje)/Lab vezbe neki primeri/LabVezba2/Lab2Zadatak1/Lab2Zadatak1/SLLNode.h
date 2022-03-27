#pragma once
#include<iostream>
using namespace std;


class SLLNode
{
public:
	int exp;
	double coef;
	SLLNode *next;
public:
	SLLNode();
	SLLNode(int e,double c);
	friend ostream& operator<<(ostream& out,SLLNode& s);
	~SLLNode();
};

