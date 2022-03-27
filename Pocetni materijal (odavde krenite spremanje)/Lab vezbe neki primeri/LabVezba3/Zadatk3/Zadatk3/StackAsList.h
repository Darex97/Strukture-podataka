#pragma once
#include"Node.h"

class StackAsList
{
private:
	Node *top;
public:
	StackAsList();
	void push(int number);//kao AddToHead();
	Node pop();
	Node getTop();
	bool isEmpty();
	int numberOfElements();
	void PRINT();
	~StackAsList(void);
};

