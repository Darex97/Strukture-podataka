#pragma once
#include"Node.h"
class QueueAsList
{
private:
	Node *head;
	Node *tail;
public:
	QueueAsList();
	void enqueue(int number);//AddToTail()
	int dequeue();//deleteFromHead()
	Node getHead();
	bool isEmpty();
	~QueueAsList(void);
	void PRINT();
	int numberOfElements();
};

