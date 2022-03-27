#pragma once
#include<iostream>
using namespace std;

class Node
{
public:
	int number;
	Node *next;
public:
	Node(int number)
	{
		this->number=number;
		this->next=NULL;
	}
	void print()
	{
		cout<<this->number;
	}
	~Node()
	{
	}
};