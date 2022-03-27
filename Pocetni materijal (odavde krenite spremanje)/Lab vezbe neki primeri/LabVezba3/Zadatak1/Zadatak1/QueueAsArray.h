#pragma once
#include<iostream>
using namespace std;

class QueueAsArray
{	
protected:
	int *array;
	int size;
	int head;
	int tail;
	int numofelements;
public:
	QueueAsArray();
	virtual int getHead();
	virtual int NumberOfElements();
	virtual bool isEmpty();
	virtual void enqueue(int number);
	virtual int dequeue();
	~QueueAsArray();
};

