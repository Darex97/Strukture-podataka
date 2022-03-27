#pragma once
#include<iostream>
using namespace std;

class Node
{
public:
	int number;
	Node *next;
public:
	Node(int number,Node *next)
	{
		this->number=number;
		this->next=next;
	}
	void print()
	{
		cout<<this->number<<endl;
	}
	~Node()
	{

	}
};