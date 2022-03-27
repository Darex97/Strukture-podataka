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
		this->next=next;
		this->number=number;
	}
	/*friend ostream& operator<<(ostream& out,SLLNode& s)
	{

	}*/
	~SLLNode();
};

