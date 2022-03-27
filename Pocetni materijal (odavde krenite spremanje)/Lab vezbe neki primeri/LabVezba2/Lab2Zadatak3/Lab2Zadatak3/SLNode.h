#pragma once
#include<iostream>
using namespace std;

class SLLNode
{
public:
	int number;
	SLLNode *next;
public:
	SLLNode();
	SLLNode(int number,SLLNode *next)
	{
		this->number=number;
		this->next=next;
	}
	~SLLNode();
};