#pragma once
#include "Node.h"

class StackAsLList
{
protected:
	Node* top;
	int noElem;
public:
	StackAsLList();
	void addToTop(int el);
	int deleteFromTop();
	int getElement();
	bool isEmpty()
	{
		return top == NULL;
	}
	void print();
	int numberOfElements();
};