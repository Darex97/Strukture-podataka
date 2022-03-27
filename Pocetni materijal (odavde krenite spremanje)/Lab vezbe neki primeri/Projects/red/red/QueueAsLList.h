#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

class QueueAsLList
{
public:
	Node *head, *tail;
	int noElem;

public:
	QueueAsLList();
	~QueueAsLList();
	int getHead();
	void enqueue(int el);
	int dequeue();
	int numberOfElements();
	bool isEmpty()
	{
		return (noElem == 0);
	}
	void print();
};