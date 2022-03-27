#pragma once
#include"Node.h"

class DequeueAsList
{
private:
	Node *head;
	Node *tail;
public:
	DequeueAsList();
	void enqueueHead(int number);//AddToHead
	int dequeueHead();//deleteFromHead
	void enqueueTail(int number);//AddToTail
	int dequeueTail();//deleteFromTail
	Node getHead();
	Node getTail();
	bool isEmpty();
	int numberOfelements();
	void PRINT();
	~DequeueAsList();
};

