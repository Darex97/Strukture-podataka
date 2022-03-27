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
	SLLNode(double coef,int exp)
	{
		this->coef=coef;
		this->exp=exp;
		this->next=NULL;
	}
	~SLLNode();
};