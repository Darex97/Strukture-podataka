#pragma once
#include <iostream>
using namespace std;

class Node
{
public:
	Node* next;
	Node* prev;
	int info;

	Node()
	{
		next = NULL;
		prev = NULL;
		info = 0;
	}
	Node(int el)
	{
		next = NULL;
		prev = NULL;
		info = el;
	}
	Node(int el, Node* pr, Node* sl)
	{
		next = sl;
		prev = pr;
		info = el;
	}
	int getInfo()
	{
		return info;
	}

};