#pragma once
#include"BSTNode.h"
class QueueAsArray
{
private:
	BSTNode **_array;
	int size;
	int head;
	int tail;
	int numOfElements;
public:
	QueueAsArray(int size);
	bool isEmpty()
	{
		return this->numOfElements==0;
	}
	bool isFull()
	{
		return this->numOfElements==this->size;
	}
	void enqueue(BSTNode *el);
	BSTNode* dequeue();
	~QueueAsArray();
};

