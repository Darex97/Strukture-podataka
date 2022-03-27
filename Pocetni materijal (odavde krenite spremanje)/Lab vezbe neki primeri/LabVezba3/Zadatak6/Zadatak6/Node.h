#pragma once
#include<iostream>
using namespace std;

class Node
{
public:
	int number;
	Node *previous;
	Node *next;
public:
	Node(int number,Node *p,Node *n)
	{
		this->number=number;
		this->previous=p;
		this->next=n;
		
	}
	void print()
	{
		cout<<this->number<<endl;
	}
	~Node()
	{
	}

};
