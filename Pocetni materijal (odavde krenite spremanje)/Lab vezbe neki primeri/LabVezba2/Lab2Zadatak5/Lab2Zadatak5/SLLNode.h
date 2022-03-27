#pragma once
#include<iostream>
using namespace std;

class SLLNode
{
public:
	SLLNode *next;
	int number;
public:
	SLLNode()
	{
		this->next=NULL;
	}
	SLLNode(int number,SLLNode *next)
	{
		this->number=number;
		this->next=next;
	}
	~SLLNode(void);
};

