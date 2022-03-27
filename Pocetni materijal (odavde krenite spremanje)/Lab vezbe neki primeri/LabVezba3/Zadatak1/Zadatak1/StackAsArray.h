#pragma once
#include"QueueAsArray.h"
class StackAsArray:public QueueAsArray 
{
public:
	StackAsArray();
	StackAsArray(int size);
	int NumberOfElements();
	bool isEmpty();
	void enqueue(int number);
	int dequeue();
	int getHead();
	~StackAsArray();
	void print();
};

