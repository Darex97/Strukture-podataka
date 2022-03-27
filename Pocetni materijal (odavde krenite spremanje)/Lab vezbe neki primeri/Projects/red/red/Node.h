#pragma once
#include <iostream>
using namespace std;

class Node
{
public:
	Node* next;
	int info;
public:
	Node()
	{
		next = NULL;
	}
	Node(int el)
	{
		info = el;
		next = NULL;
	}
	Node(int el, Node* sl)
	{
		info = el;
		next = sl;
	}
	int getInfo()
	{
		return info;
	}
	Node* getNext()
	{
		return next;
	}
};